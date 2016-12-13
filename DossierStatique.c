#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <sys/types.h>
#include <string.h>
#include <dirent.h>
#include <unistd.h>

char *choixPBM(char *pbm_directory)
{
    DIR* rep = opendir(pbm_directory);

    if(rep != NULL)
    {
        struct dirent * ent;
        int nmb_images = 5;
        int n = 0;
        int nmb_random = rand_a_b(1, nmb_images);

        while(n != nmb_random && (ent = readdir(rep)) != NULL)
        {
            if(strcmp(ent->d_name, ".") != 0 && strcmp(ent->d_name, "..") != 0)
                n++;
        }
        closedir(rep);
        return ent->d_name;
    }
}

void OuvertureRepertoire()
{
    char fichier_pbm[1024];
    char* str = getenv("EXIASAVER1_PBM");

    if(str != NULL)
        strcpy(fichier_pbm, str);

    else
        getcwd(fichier_pbm, 1024);

    return 0;
}
