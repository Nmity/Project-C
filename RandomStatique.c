#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <unistd.h>
#include <sys/types.h>
#include <time.h>

int main(int argc, char *argv[])
{
    char rep_pbm[1024];
    char* str = getenv("EXIASAVER1_PBM");

    if(str != NULL)
    {
        strcpy(rep_pbm, str);
    }

    else
    {
        getcwd(rep_pbm, 1024);
    }

    DIR* rep = opendir(rep_pbm);

    if (rep != NULL)
    {
        struct dirent * ent;

        while ((ent = readdir(rep)) != NULL)
        {
            if(strcmp(ent->d_name, ".") != 0 && strcmp(ent->d_name, "..") != 0)
            printf("%s\n", ent->d_name);
        }

        rewinddir(rep);
        srand(time(NULL));
        int n = 0;
        int nbr = rand() % 6;

        while (n != nbr && (ent = readdir(rep)) != NULL)
        {
            if(strcmp(ent->d_name, ".") != 0 && strcmp(ent->d_name, "..") != 0)
            {
                n++;
            }
        }

        char chemin[255];
        strcpy(chemin, rep_pbm);
        strcat(chemin, ent->d_name);
        FILE* fichier = fopen(chemin, "r");

        if(fichier != NULL)
        {
            printf("\n%s", &chemin);
        }
    }

    else
    {
        perror("");
    }

    return 0;
}
