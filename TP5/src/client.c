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
#include <fcntl.h>
#include <dirent.h>

#include "client.h"

/*
 * Fonction d'envoi et de réception de messages
 * Il faut un argument : l'identifiant de la socket
 */

int lire_fichier(char *fichier)
{
  char content[2];
    int fd, size;

    fd = open(fichier, O_RDONLY);

    if (fd < 0)
    {
        printf("Erreur impossible d'acceder au fichier \"%s\"\n", argv[1]);
        exit(0);
    }
    size = read(fd, content, 1);
    if (size < 1 )
    {
      return -1;
    }
    return atoi(content);

    close(fd);
}
void lire_dossier_recursif(char *nom_dossier)
{
  DIR *dirp = opendir(nom_dossier);

  if(dirp == NULL)
  {
      perror("opendir");
      exit(0);
  }

  struct dirent * element;

  for (int i = 0; i < 5; i++)
  {
    element = readdir(dirp);
    if(element == NULL)
    {
        break;
    }
  }
  while(1)
  {
      element = readdir(dirp);
      if(element == NULL)
      {
          break;
      }
      if ((strcmp(element->d_name, ".") != 0) && (strcmp(element->d_name, "..") != 0))
      {
          if (element->d_type == DT_DIR)
          {
              printf("%s\n", element->d_name);
              char nouv_dossier[100];
              strcpy(nouv_dossier, nom_dossier);
              strcat(nouv_dossier, "/");
              strcat(nouv_dossier, element->d_name);
              lire_dossier_recursif(nouv_dossier, level+1);
          }
          else
          {
              printf("%s\n", element->d_name);
          }
      }

  }
  closedir(dirp);
}

int envoie_recois_message(int socketfd) {

  char data[1024];
  // la réinitialisation de l'ensemble des données
  memset(data, 0, sizeof(data));


  // Demandez à l'utilisateur d'entrer un message
  char message[100];
  printf("Votre message (max 100 caracteres): ");
  fgets(message, 100, stdin);
  strcpy(data, "message: ");
  strcat(data, message);

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


int envoie_operateur_numeros(int socketfd)
{
  char data[1024];
  // la réinitialisation de l'ensemble des données
  memset(data, 0, sizeof(data));


  // Demandez à l'utilisateur d'entrer un message
  char message[100];
  printf("Votre calcul 'operateur' num1 num 2: ");
  fgets(message, 100, stdin);
  strcpy(data, "calcul: ");
  strcat(data, message);

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

  char reponse[100];
  sscanf(data, "calcul: %s", reponse );
  printf("calcule: %s\n", reponse);

  return 0;
}


int main() {
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
  char commande;

  printf("Voulez vous envoyer un message ou un calcul:[m/c] ");
  scanf("%c", &commande);

  //  clear buffer scanf
  int c;
  while((c = getchar()) != '\n' && c !=EOF){ }

  switch(commande)
  {
    case 'm':
      // appeler la fonction pour envoyer un message au serveur
      envoie_recois_message(socketfd);
      break;

    case 'c':
      // appeler la fonction pour envoyer un calcul
      envoie_operateur_numeros(socketfd);
      break;

    default:
      printf("Erreur veuiller saisir [m/c] afin d'executer une operation\n");
  }


  close(socketfd);
}
