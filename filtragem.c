#include <stdlib.h>
#include <stdio.h>

void filtragem(node_t *_filtrar, int _fmes, int _fano, int _primeiroMes, int _ultimoMes, int _idxFiltragem) // talvez usar lista auxiliar
{ 
    if(_idxFiltragem==1)
    {
            //voltar a encher lista funcao q faz isso


    }
    
    
    if(_idxFiltragem==2)
    {
        if(node_t->data.ano<_fano)
        {
            aux= *_filtrar;
            free(aux);
        }

        if(node_t->data.ano==_fano || node_t->data.mes<_fmes)
        {
            aux= *_filtrar;
            free(aux);
        }
    }

    if(_idxFiltragem ==3)
    {
    
        if(node_t ->data.mes<_primeiroMes)
            {
                aux= *_filtrar;
                free(aux);
            }                
        if(node_t ->data.mes>_ultimoMes)
            {
                aux= *_filtrar;
                free(aux);
            }
    }
}

void temperaturas(node_t *_temperaturas, int _idxTemperaturas,int _periodoAmostragem,char nomeCidade[], char nomePais[] ) // talvez usar lista auxiliar
{
    if(_idxTemperaturas==1)
    {

        // funcao que faz o tabela cm medias etc etc para todos os paises
    }
    if(_idxTemperaturas==2)
    {
        aux = *_temperaturas;

        if((strcmp(nomePais[],node_t->data.pais)!=0)
            free(aux);


        // funcao que faz o tabela ja cm as medias etc etc para um pais especifico mas so e preciso invocar a funcao pq a lista ja foi reduzida para apenas esse pais especifico

    }

    if(_idxTemperaturas==3)
    {
        aux = *_temperaturas;

        if((strcmp(nomePais[],node_t->data.cidade)!=0)
            free(aux);    
        
        //funcao que faz os graficos com as medias etc etc para uma cidade especifica
        

    }
}

void anoAnalise(node_t *analise, int _idxAnoAnalise, int _anoPretendido, int _nCidades, int _nPaises) // talvez usar lista auxiliar e e ficheiro dos paises
{
    if(node_t->data.ano!=_anoPretendido)
    {
        aux = *_temperaturas;
        free(aux); 

    }


    if(_idxAnoAnalise==1)
    {
        //funcao que procura os N paises nas varias condicoes pedidas para paises

    }

    if(_idxAnoAnalise ==2)
    {

        //funcao que procura os N paises nas varias condicoes pedidas para cidades
    }

}

void globalAnalise(int _nMeses)
{


}

