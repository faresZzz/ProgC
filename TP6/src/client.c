/*
Auteurs : Farès ZAGHOUANE, Maxime CURRAL
Rendu le 09/11/2021 dans le cadre du module "Programmation en C"
CPE LYON
*/

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
envoi des couleurs
{
  'code': couleur,
  'message:X, 0xXX, ...
}

envoi d'une phrases
{
  'code' : message,
  'message' XXXXXX
}

*/
void format_data(char* data, char *code, char *message)
// fonction de formatage du message avant de l'envoyer
{
  memset(data, 0, sizeof(data));
  sprintf(data, "{ \n \t 'code': %s , \n\t 'message': %s \n} ", code, message);

}
int envoie_recois_message(int socketfd) {

  char data[1024];
  // la réinitialisation de l'ensemble des données
  memset(data, 0, sizeof(data));


  // Demandez à l'utilisateur d'entrer un message
  char message[100];
  printf("Votre message (max 1000 caracteres): ");
  fgets(message, 1024, stdin);

  // formatage du message
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
  //  chaine des couleurs temporaire avant de formater le message finale dans data
  char temp_string[1024];
  char temp_couleur[10];
  memset(temp_string, 0, sizeof(temp_string));

  if (cc->size < 10) {
    sprintf(num, "%d,", cc->size);
  }

  // ajout du nombre de couleurs traitées dans le messages
  strcat(temp_string, num);
  strcat(temp_string, ",");


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

  //enlever la derniere virgule
  temp_string[strlen(temp_string)-1] = '\0';

  // formattage de la data dans le format type Json
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

  // switch case permetant de savoir si l'on enoi un message ou des couleurs a plot
  char default_val[] = "10";
  switch(argc)
  {
    // case envoi d'un message
    case 1: envoie_recois_message(socketfd);
    break;

    // case envoi des couleurs avec le nombre de tranches par defaut
    case 2: envoie_couleurs(socketfd, argv[1], default_val);
    break;

    // case envoi des couleurs avec le nombre de tranches saisi par l'utilisateur
    case 3: envoie_couleurs(socketfd, argv[1], argv[2]);
    break;

    default: printf("Erreur arguments passées au programme\n");
  }




  close(socketfd);
}
