#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include <stdlib.h>
#include <stdio.h>
#include "functions.h"
#include "data.h"

void switchMenu (int argc, char *argv[]);
int menuPrincipal(int *_idxMenu);
void menuFiltragem(int *,int*,int *,int *, int *);
void menuTemperaturas(int *,int *,  char _nomePais[], char _nomeCidade[]);
void menuAnoAnalise(int *,int *,int*,int *);
void menuGlobalAnalise(int *,int *,char _nomePais[], char _nomeCidade[]);
void receberDados(int argc , char * argv[], FILE **Cidade, FILE **Paises, int *modoImpressao);
void filtragem(node_t **_filtrar, int _fmes, int _fano, int _primeiroMes, int _ultimoMes, int _idxFiltragem,FILE * _pais,FILE *_cidade,int);
void temperaturas(node_t **_temperaturas,int _periodoAmostragem, char _nomeCidade[], char _nomePais[],int _idxTemperaturas );
void anoAnalise(node_t **analise, int _idxAnoAnalise, int _anoPretendido, int _nCidades, int _nPaises);
void globalAnalise(node_t **,int _nMeses);
void getfile(node_t **,FILE *,int);
node_t *putCity(char *,node_t ***,int);
node_t *getNewNode(char *,float,float,char *,char *,char *,char*,int);
void ordenarLista(node_t *, node_t ****);
node_t * separa(node_t *);
node_t * merge(node_t *);
node_t *junta(node_t *,node_t *);
void printlist(node_t *);



#endif
