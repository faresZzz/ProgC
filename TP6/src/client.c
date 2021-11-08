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

/*
format message:
{
  'code': couleur,
  'message:[X, 0xXX, ...]
}
*/
void format_data(char* data, char *code, char *message)
{
  memset(data, 0, sizeof(data));
  sprintf(data,"{ \n \t 'code': %s , \n\t 'message': %s\n} ", code, message);

}
int envoie_recois_message(int socketfd) {

  char data[1024];
  // la réinitialisation de l'ensemble des données
  memset(data, 0, sizeof(data));


  // Demandez à l'utilisateur d'entrer un message
  char message[100];
  printf("Votre message (max 1000 caracteres): ");
  fgets(message, 1024, stdin);
  strcpy(data, "message: ");
  //strcat(data, message);
  format_data(data, "message", message);
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
  // strcpy(data, "couleurs: ");
  char temp_string[1024];
  char temp_couleur[10];
  memset(temp_string, 0, sizeof(temp_string));
  if (cc->size < 10) {
    sprintf(num, "%d,", cc->size);
  }
  // strcat(data, num);
  // strcat(data, ",");
  strcat(temp_string, num);
  strcat(temp_string, ",");

  // //choisir 10 couleurs
  // for (count = 1; count < (atoi(num)+1) && cc->size - count >0; count++) {
  //   if(cc->compte_bit ==  BITS32) {
  //     sprintf(temp_string, "#%02x%02x%02x,", cc->cc.cc24[cc->size-count].c.rouge,cc->cc.cc32[cc->size-count].c.vert,cc->cc.cc32[cc->size-count].c.bleu);
  //   }
  //   if(cc->compte_bit ==  BITS24) {
  //     sprintf(temp_string, "#%02x%02x%02x,", cc->cc.cc32[cc->size-count].c.rouge,cc->cc.cc32[cc->size-count].c.vert,cc->cc.cc32[cc->size-count].c.bleu);
  //   }
  //   strcat(data, temp_string);
  // }

  // //enlever le dernier virgule
  // data[strlen(data)-1] = '\0';

  //choisir 10 couleurs
  for (count = 1; count < (atoi(num)+1) && cc->size - count >0; count++) {
    if(cc->compte_bit ==  BITS32) {
      sprintf(temp_couleur, "#%02x%02x%02x,", cc->cc.cc24[cc->size-count].c.rouge,cc->cc.cc32[cc->size-count].c.vert,cc->cc.cc32[cc->size-count].c.bleu);
    }
    if(cc->compte_bit ==  BITS24) {
      sprintf(temp_couleur, "#%02x%02x%02x,", cc->cc.cc32[cc->size-count].c.rouge,cc->cc.cc32[cc->size-count].c.vert,cc->cc.cc32[cc->size-count].c.bleu);
    }
    strcat(temp_string, temp_couleur);
  }

  //enlever le dernier virgule
  temp_string[strlen(temp_string)-1] = '\0';
  format_data(data, "couleurs", temp_string);
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
  //envoie_recois_message(socketfd);
  if (argc<3)
  {
    char default_val[] = "10";
    //envoie_recois_message(socketfd);
    envoie_couleurs(socketfd, argv[1], default_val);
  }
  else
  {
    envoie_couleurs(socketfd, argv[1], argv[2]);
  }


  close(socketfd);
}
