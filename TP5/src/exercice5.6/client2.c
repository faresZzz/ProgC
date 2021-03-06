/*
Auteurs : Farès ZAGHOUANE, Maxime CURRAL
Rendu le 09/11/2021 dans le cadre du module "Programmation en C"
CPE LYON

Programme permetant de venir lire les notes de chaque etudiant contenu dans le dossier etudiants
Et d'en faire la moyenne
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
#include <fcntl.h>
#include <dirent.h>

#include "client2.h"
#include "repertoire.h"

/*
 * Fonction d'envoi et de réception de messages
 * Il faut un argument : l'identifiant de la socket
 */

// creation de la structure etudiant
typedef struct Eleve{
  char path[100];             // chemin vers son dossier ./etudiant/X
  int notes[5];
  int moyenne;
}Eleve;



int envoie_recois_message(int socketfd, char message[100]) {

  char data[1024];
  // la réinitialisation de l'ensemble des données
  memset(data, 0, sizeof(data));

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


int envoie_operateur_numeros(int socketfd, char op, int num1, int num2)
/*
Fonction qui vas venir envoyer le calcul a efecturer au serveur2
*/
{
  char data[1024];
  // la réinitialisation de l'ensemble des données
  memset(data, 0, sizeof(data));


  // Demandez à l'utilisateur d'entrer un message
  char message[100];
  sprintf(message, "%c %d %d", op, num1, num2);
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

  int reponse;
  sscanf(data, "calcul: %d", &reponse );
  printf("resultat: %d\n", reponse);

  return reponse;
}

void notes_Eleves(int socketfd)
{
  Eleve liste_eleve[5];
  // liste des moyennes de la classe par matiere
  int liste_moyennes_matieres[] = {0, 0, 0, 0, 0};

  for (int i = 0; i < 5 ; i++)
  // on vient recupere tous les notes de chaque etudiant
  {
    // on assigne un Path a chaque eleve
    sprintf(liste_eleve[i].path,"./etudiant/%d", i+1);
    for (int j = 0; j < 5; j++)
    {
      // boucle pour donner a chque chaque eleve ces notes
      char fichier[120];
      sprintf(fichier, "%s/note%d.txt", liste_eleve[i].path, j+1);
      liste_eleve[i].notes[j] = lire_fichier(fichier);
    }
    liste_eleve[i].moyenne = 0;

  }

  for(int eleve = 0; eleve < 5; eleve++) // on boucle sur chque eleve pour calculer sa moyenne. on fait en meme temps la moyenne par matiere
  // boucle sur les eleve
  {
      for (int note = 0; note < 5; note++)
      // boucle sur les notes de chaque etudiant
      {
        // calcul de la somme de l'eleve
        liste_eleve[eleve].moyenne = envoie_operateur_numeros(socketfd, '+',liste_eleve[eleve].moyenne, liste_eleve[eleve].notes[note] ); // moyenne de l'eleve

        // calcul de la somme des notes par matiere
        liste_moyennes_matieres[note] = envoie_operateur_numeros(socketfd, '+',liste_moyennes_matieres[note], liste_eleve[eleve].notes[note] ); // moyenne dans la matiere
      }
      // obtention de la moyenne de l'eleve
      liste_eleve[eleve].moyenne = envoie_operateur_numeros(socketfd, '/',liste_eleve[eleve].moyenne, 5 );
  }

  for (int matiere = 0; matiere < 5; matiere++)
  {
    // obtention de la moyenne par matiere
    liste_moyennes_matieres[matiere] = envoie_operateur_numeros(socketfd, '/',liste_moyennes_matieres[matiere], 5 );
  }


  // envoi d'un signal de fin au serveur
  envoie_recois_message(socketfd, "FIN!!");

  for (int k = 0; k < 5; k++)
  // affichage
    {
      printf("eleve n°%d: path: %s, notes(%d, %d, %d, %d, %d) moyenne: %d\n",
                                                                            k,
                                                                            liste_eleve[k].path,
                                                                            liste_eleve[k].notes[0],
                                                                            liste_eleve[k].notes[1],
                                                                            liste_eleve[k].notes[2],
                                                                            liste_eleve[k].notes[3],
                                                                            liste_eleve[k].notes[4],
                                                                            liste_eleve[k].moyenne);

      printf("Moyenne dans la matiere %d: %d\n\n", k, liste_moyennes_matieres[k]);
    }



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

  notes_Eleves(socketfd);

  close(socketfd);
}
