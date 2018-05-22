#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include <stdlib.h>
#include <stdio.h>
#include "functions.h"
#include "data.h"

void switchMenu (void);
int menuPrincipal(int *_idxMenu);
void menuFiltragem(void);
void menuTemperaturas(  char _nomePais[], char _nomeCidade[]);
void menuAnoAnalise(void);
void menuGlobalAnalise(char _nomePais[], char _nomeCidade[]);
void receberDados(int argc , char * argv[], FILE **Cidade, FILE **Paises, int *modoImpressao);
void filtragem(node_t *_filtrar, int _fmes, int _fano, int _primeiroMes, int _ultimoMes, int _idxFiltragem);
void temperaturas(node_t *_temperaturas, int _idxTemperaturas,int _periodoAmostragem, char _nomeCidade[], char _nomePais[] );
void anoAnalise(node_t *analise, int _idxAnoAnalise, int _anoPretendido, int _nCidades, int _nPaises);
void globalAnalise(int _nMeses);
void getfile(node_t **,FILE *,int);
node_t *putCity(char *,node_t ***,int);
node_t *getNewNode(char *,float,float,char *,char *,char *,char*,int);


#endif
