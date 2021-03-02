#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    char *ptr;

    if(argc < 3)
    {
        printf("Usage: ./getenv <environment variable> <target name program>\n");
        exit(EXIT_FAILURE);
    }

    ptr = getenv(argv[1]);
    /*
    Le calcul qui suit est nécessaire car le contexte d'exécution peut être différent selon
    l'endroit où l'on se trouve.
    En effet, la variable d'environnement PWD indique le chemin absolu du dossier dans lequel
    on se trouve : la longueur de ce chemin aura un impact sur l'emplacement des variables suivantes
    */
    ptr += strlen(argv[0]) - strlen(argv[2]);

    printf("%s found at %p\n", argv[1], ptr);

    return EXIT_SUCCESS;
}
