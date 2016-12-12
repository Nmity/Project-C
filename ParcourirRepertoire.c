#include <stdlib.h>
#include <stdio.h>

int main(void)
{
    DIR* rep = opendir("EXIASAVER1_PBM");

    if(rep != NULL)
    {
        struct dirent *ent;

        while ((ent = readdir (rep)) != NULL)
        {
            printf("%s\n", ent->d_name);
        }
        closedir(rep);
    }
    return 0;
}
