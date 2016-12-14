#include <stdio.h> // pour l'affichage sur l'écran avec printf()
#include <stdlib.h> // pour les constantes EXIT_SUCCESS et EXIT_FAILURE
#include <unistd.h> // pour fork()
#include <time.h>    //permet d'utiliser srand() et rand()
#include <string.h> // pour la gestion des chaîne de caractères
#include <sys/wait.h> // pour wait()
#include <sys/types.h> // pour le type pid_t
#include <errno.h> // pour perror() et errno


int main (int argc, char *argv[])
{
    int nombre_aleatoire;
    int nombreAleatoire;
    char *arguments[] = {"statique", argv[0], NULL};
    char *arg[] = {"testStat", argv[1], NULL};
    char lecture[200] = "";

    FILE* fichierDeHistorique = NULL; //pointeur sur le fichier .txt de l'historique

    if(argc == 2 && strcmp(argv[1], "-stats") == 0)
    {
        fichierDeHistorique = fopen("historique.txt", "a+"); //permet d'ouvir un fichier .txt, le "a+" permet de lie, écrire et ajouter à la fin du fichier ainsi que de le créer s'il n'existe pas

        if(fichierDeHistorique != NULL) //si on a réussi à ouvrir le fichier
        {
            do //faire
            {
                fgets(lecture, 200, fichierDeHistorique);//permet de lire la chaine de caractères écrite sur le fichier .txt
                printf("%s", lecture);// On affiche la chaine de caractères
            }
            while(fgets(lecture, 200, fichierDeHistorique) != NULL);//si la lecture du fichier a été réussi

            fclose(fichierDeHistorique);//permet de libérer la mémoire du fichier ouvert
        }
    }

    else if(argc == 1 && strcmp(argv[0], "./eXiaSaver") == 0)
    {
        pid_t pid = fork();

        if(pid < 0)
        {
            perror("Forked failed");
        }

        if(pid == 0)
        {
            srand(time(NULL));      //initialisation de rand
            nombre_aleatoire = rand();    //nombre_aleatoire prend la valeur d'un nombre aleatoire grace a la fonction rand()
            nombreAleatoire = nombre_aleatoire %3;    //on souhaite un nombre aleatoire de 5 valeurs possible, on utilise donc modulo 5

            system("clear");

            switch(nombreAleatoire) //Vide la console avant de lancer les autres programmes
            {
            case 0:
                if(execv("/home/Bureau/Project-C/statique", arguments) == -1)
                {
                    perror("execv");
                    return EXIT_FAILURE;
                    int ecrireDateDansFichierTXT()
                        {
                            FILE* fichierDeHistorique = NULL;
                            fichierDeHistorique = fopen("historique.txt", "a+");
                            time_t t;
                            struct tm ;
                            t = time(NULL);

                            if (fichierDeHistorique != NULL)
                            {
                                fprintf(fichierDeHistorique, "Date et heure : %s", ctime(&t));
                                fprintf(fichierDeHistorique, "Ecran statique");

                            }
                        }
                    return EXIT_SUCCESS;
                    break;
                case 1:
                    //execv("./dynamique", programme);
                    printf("Le dynamique va etre lance\n");
                    break;
                case 2:
                    //execv("./interactif", programme);
                    printf("L'interactif va etre lance\n");
                    break;
                default:
                    printf("Le tirage de nombre aléatoire n'a pas fonctionne\n");
                    break;
                };

                exit(0);
            }
        }
        }

        else
        {
            printf("La commande n'existe pas\n");
        }

        wait(NULL);

        return 0;

    }
