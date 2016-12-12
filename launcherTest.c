#include <stdlib.h> // pour les constantes EXIT_SUCCESS et EXIT_FAILURE
#include <stdio.h> // pour fprintf()
#include <unistd.h> // pour fork()
#include <errno.h> // pour perror() et errno
#include <sys/types.h> // pour le type pid_t
#include <sys/wait.h> // pour wait()

int main(int argc, char *argv[])
{
    char *arguments[] = {"statique", argv[1], NULL};

    if(execv("/home/mobeestone/Project-C/statique", arguments) == -1)
    {
        perror("execv");
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}

