/*
 * SPDX-FileCopyrightText: 2021 John Samuel
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 *
 */

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

#include "client.h"
#include "bmp.h"

/*
 * Fonction d'envoi et de réception de messages
 * Il faut un argument : l'identifiant de la socket
 */

// data = "{ "code" : "message", "valeurs" : ["Bonjour", "comment" "tu", "vas"] }
void format_message(char *data, char *code, char *valeurs)
{
  memset(data, 0, sizeof(data));
  sprintf(data, "{ \"code\" : \" %s \", \"valeurs\" : [\" %s \"] } ", code, valeurs);
}

int envoie_recois_message(int socketfd) {

  char data[1024];
  // la réinitialisation de l'ensemble des données
  memset(data, 0, sizeof(data));


  // Demandez à l'utilisateur d'entrer un message
  char message[100];
  char code[] = "message";
  printf("Votre message (max 1000 caracteres): ");
  fgets(message, 1024, stdin);
  // strcpy(data, "message: ");
  // strcat(data, message);
  format_message(data, code, message);

  int write_status = write(socketfd, data, strlen(data));
  if ( write_status < 0 ) {
    perror("erreur ecriture");
    exit(EXIT_FAILURE);
  }

  // la réinitialisation de l'ensemble des données
  memset(data, 0, sizeof(data));


  // lire les données de la socket
  int read_status = read(socketfd, data, sizeof(data));
  if ( read_status < 0 ) {
    perror("erreur lecture");
    return -1;
  }

  printf("Message recu: %s\n", data);

  return 0;
}

void analyse(char *pathname, char *data, char *num) {
  //compte de couleurs
  couleur_compteur *cc = analyse_bmp_image(pathname);

  int count;
  char temp_string[100];
  char code[] = "couleurs";
  int numero = atoi(num);
  // strcpy(data, "couleurs: ");
  strcpy(temp_string, num);
  strcat(temp_string, ", ");


  if (cc->size < numero) {
    sprintf(temp_string, "%d,", cc->size);
  }
  // strcat(data, temp_string);

  //choisir 10 couleurs
  char temp[10];
  for (count = 1; count < numero + 1 && cc->size - count >0; count++) {
    if(cc->compte_bit ==  BITS32) {
      sprintf(temp, "#%02x%02x%02x,", cc->cc.cc24[cc->size-count].c.rouge,cc->cc.cc32[cc->size-count].c.vert,cc->cc.cc32[cc->size-count].c.bleu);
    }
    if(cc->compte_bit ==  BITS24) {
      sprintf(temp, "#%02x%02x%02x,", cc->cc.cc32[cc->size-count].c.rouge,cc->cc.cc32[cc->size-count].c.vert,cc->cc.cc32[cc->size-count].c.bleu);
    }
    strcat(temp_string, temp);
  }

  //enlever la derniere virgule
  temp_string[strlen(temp_string)-1] = '\0';
  format_message(data, code, temp_string);
}

int envoie_couleurs(int socketfd, char *pathname, char *num) {
  char data[1024];
  memset(data, 0, sizeof(data));
  analyse(pathname, data, num);

  int write_status = write(socketfd, data, strlen(data));
  if ( write_status < 0 ) {
    perror("erreur ecriture");
    exit(EXIT_FAILURE);
  }

  return 0;
}


int main(int argc, char **argv) {
  int socketfd;
  int bind_status;

  struct sockaddr_in server_addr, client_addr;

  /*
   * Creation d'une socket
   */
  socketfd = socket(AF_INET, SOCK_STREAM, 0);
  if ( socketfd < 0 ) {
    perror("socket");
    exit(EXIT_FAILURE);
  }

  //détails du serveur (adresse et port)
  memset(&server_addr, 0, sizeof(server_addr));
  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(PORT);
  server_addr.sin_addr.s_addr = INADDR_ANY;

  //demande de connection au serveur
  int connect_status = connect(socketfd, (struct sockaddr *) &server_addr, sizeof(server_addr));
  if ( connect_status < 0 ) {
    perror("connection serveur");
    exit(EXIT_FAILURE);
  }

  // envoie_recois_message(socketfd);
  if (argc < 3)
  {
    // valeur par defaut = 10
    char val[] = "10";
    envoie_couleurs(socketfd, argv[1], val);
  }
  //envoie_recois_message(socketfd);
  envoie_couleurs(socketfd, argv[1], argv[2]);

  close(socketfd);
}


