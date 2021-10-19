#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

char lire_fichier(char *nom_fichier)
{
    char content;
    int fd, size;
    fd = open(
        nom_fichier, O_RDONLY);

    while (1)
    {
        size = read(fd, &content, 1);
        if(size < 1)
        {
            break;
        }
        printf("%c", content);
    }
    close(fd);


}

char ecrire_dans_fichier(char *nom_fichier, char *message)
{

    int fd, count, size;
    fd = open (nom_fichier, O_CREAT|O_WRONLY, S_IRUSR|S_IWUSR);
    size = write(fd, message, strlen(message));
    close(fd);
}

int main()
{
    char *fichier = "fichier.txt";
    lire_fichier(fichier);
    return 0;

}