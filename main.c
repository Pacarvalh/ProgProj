#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "functions.h"
#include "data.h"
#define SIZE_OF_STRING 100


int main (int argc, char *argv[])
{
    FILE *Cidades=NULL, *Paises=NULL;
    
    /* Apresenta os menus e pede todos os valores necessarios ao utilizador.*/
    switchMenu(argc,argv);  
    return EXIT_SUCCESS;
}

