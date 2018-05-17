#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "functions.h"
#include "data.h"
#define SIZE_OF_STRING 100


int main (int argc, char *argv[])
{
    int idxMenu, idxFiltragem, idxTemperaturas, idxAnoAnalise,  periodoAmostragem, anoPretendido, nCidades, nPaises, nMeses, periodo;
    FILE *Cidades=NULL, *Paises=NULL;
    char nomeCidade[SIZE_OF_STRING], nomePais[SIZE_OF_STRING];
    // Apresenta os menus e pede todos os valores necessarios ao utilizador.
    switchMenu(&idxMenu, &idxFiltragem, &idxTemperaturas, &periodoAmostragem,nomePais, nomeCidade, &idxAnoAnalise, &periodo, &anoPretendido, &nCidades, &nPaises, &nMeses);  

    return EXIT_SUCCESS;
}

