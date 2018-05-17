#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include <stdlib.h>
#include <stdio.h>
#include "functions.h"
#include "data.h"

void switchMenu ( int *_idxMenu,int *_idxFiltragem, int * _idxTemperaturas,int *_periodoAmostragem, char _nomePais[], char _nomeCidade[], int *_idxAnoAnalise, int *_periodo, int *_anoPretendido, int *_nCidades, int *_nPaises, int *_nMeses);
void menuFiltragem(int  **_idxFiltragem);
void menuTemperaturas( int **_idxTemperaturas, int  **_periodoAmostragem, char *_nomePais[100], char *_nomeCidade[100]);
void menuAnoAnalise(int **_idxAnoAnalise , int **_anoPretendido, int **_nCidades, int **_nPaises);
void menuGlobalAnalise(int **_nMeses);
void receberDados(int argc , char * argv[], FILE **Cidade, FILE **Paises, int *modoImpressao);
node_t *getNewNode(void);


#endif
