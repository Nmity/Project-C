#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *tableau;
    int tailleDuTableau = 0;
    tailleDuTableau = malloc(tailleDuTableau * sizeof(int));

    FILE* fichier = NULL;

    int caractereActuel =0;

    fichier = fopen("ex2.pbm", "r");

    if (fichier != NULL)
    {
        do
        {
            caractereActuel = fgetc(fichier);
            int i;
            int y;
            for (i = 0 ; i < 2 ; i++)
            {
                printf("\n");
                for (y = 0; y<4; y++)
                {
                    printf("%d", tableau);
                }
                tableau = fgetc(fichier);
            }
        }
        while (caractereActuel != EOF);
        {
            fclose(fichier);
        }
    }
    return 0;
}
