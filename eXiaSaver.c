#include <stdio.h> // pour l'affichage sur l'écran avec printf()
#include <stdlib.h> // pour les constantes EXIT_SUCCESS et EXIT_FAILURE
#include <unistd.h> // pour fork()
#include <time.h>    //permet d'utiliser srand() et rand()
#include <string.h> // pour la gestion des chaîne de caractères
#include <sys/wait.h> // pour wait()
#include <sys/types.h> // pour le type pid_t
#include <errno.h> // pour perror() et errno

typedef struct Aleatoire Aleatoire;
struct Aleatoire
{
    int nombreRand;
    int nombreAleatoire;
};

/*typedef struct Temps Temps; A REGARDER
struct Temps
{
    time_t t;
    struct tm;
};*/

int main (int argc, char *argv[])
{

    time_t t;
    struct tm ;

    Aleatoire tirage;

    FILE* fichierHistorique = NULL;
    fichierHistorique = fopen("historique.txt", "a+");

    t = time(NULL);

    if (argc == 2 && strcmp(argv[1], "-stats") == 0)
    {
        system ("clear");
        ouvrirProgrammeHistorique(argv[0]);
    }

    else if (argc == 1 && strcmp(argv[0], "./eXiaSaver") == 0)
    {
        pid_t pid = fork();

        if (pid < 0)
        {
            perror("Forked failed");
        }
        if (pid == 0)
        {
            fonctionAleatoire(&tirage, fichierHistorique);
            system ("clear");

            switch (tirage.nombreAleatoire) //Vide la console avant de lancer les autres programmes
            {
                case 0:
                    fprintf(fichierHistorique, "Statique %s", ctime(&t));
                    fclose(fichierHistorique);
                    //sauvegarderAction(&tps); A REGARDER
                    executerEcranStatique (argv[0]);
                    break;
                case 1:
                    fprintf(fichierHistorique, "Dynamique %s", ctime(&t));
                    fclose(fichierHistorique);
                    //sauvegarderAction(&tps); A REGARDER
                    executerEcranDynamique(argv[0]);
                    break;
                case 2:
                    fprintf(fichierHistorique, "Interactif %s", ctime(&t));
                    fclose(fichierHistorique);
                    //sauvegarderAction(&tps); A REGARDER
                    executerEcranInteractif();
                    break;
                default:
                    printf("Le tirage de nombre aléatoire n'a pas fonctionne\n");
                    break;
            };
            exit(0);
        }
    }

    else
    {
        printf("La commande n'existe pas\n");
    }
    wait(NULL);

    return 0;
}

void fonctionAleatoire(Aleatoire* p)
{
    srand(time(NULL));      //initialisation de rand
    p->nombreRand = rand();    //nombre_aleatoire prend la valeur d'un nombre aleatoire grace a la fonction rand()
    p->nombreAleatoire = p->nombreRand %3;    //on souhaite un nombre aleatoire de 5 valeurs possible, on utilise donc modulo 5
}

void ouvrirProgrammeHistorique(char* nomArgv)
{
    char historique[1024];
    char* str = getenv("EXIASAVER_HIS");

    if(str != NULL)
    {
        strcpy(historique, str);
    }

    else
    {
        getcwd(historique, 1024);
    }

    char *argumentsHistorique[] = {"historique", nomArgv, NULL};

    if (execv(historique, argumentsHistorique) == -1)
        {
            perror("execv");
            return EXIT_FAILURE;
        }
        return EXIT_SUCCESS;
}

/*void sauvegarderAction(Temps *p, char *fichierHistorique)
{
    fprintf(fichierHistorique, "%sEcran Statique\n", ctime(&t));
    fclose(fichierHistorique);
}*/

void executerEcranStatique(char* nomArgv)
{
    char executable1[1024];
    char* str = getenv("EXIASAVER1");

    if(str != NULL)
    {
        strcpy(executable1, str);
    }

    else
    {
        getcwd(executable1, 1024);
    }

    char *argumentsStatique[] = {"statique", nomArgv, NULL};

    if (execv(executable1, argumentsStatique) == -1)
    {
        perror("execv");
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}

void executerEcranDynamique(char* nomArgv)
{
    char executable2[1024];
    char* str = getenv("EXIASAVER2");

    if(str != NULL)
    {
        strcpy(executable2, str);
    }

    else
    {
        getcwd(executable2, 1024);
    }

    char *argumentsDynamique[] = {"dynamique", nomArgv, NULL};

    if (execv(executable2, argumentsDynamique) == -1)
    {
        perror("execv");
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}

void executerEcranInteractif(char* nomArgv)
{
    char executable3[1024];
    char* str = getenv("EXIASAVER3");

    if(str != NULL)
    {
        strcpy(executable3, str);
    }

    else
    {
        getcwd(executable3, 1024);
    }

    char *argumentsInteractif[] = {"interactif", nomArgv, NULL};

    if (execv(executable3, argumentsInteractif) == -1)
    {
        perror("execv");
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
