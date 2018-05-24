#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "functions.h"
#include "data.h"
#define SIZE_OF_STRING 100
#define NONTEMP 9999999999
#define NONST "EMPTY"

void switchMenu(int argc, char *argv[])
{
   
    int idxMenu=1, idxFiltragem, idxAnoAnalise, idxGlobalAnalise, idxTemperaturas, fmes=0, fano=0, primeiroMes=0, ultimoMes=0, periodoAmostragem;
    char buff[SIZE_OF_STRING];
    char nomeCidade[SIZE_OF_STRING], nomePais[SIZE_OF_STRING];
    FILE *Cidades=NULL, *Paises=NULL;
    node_t * startc=NULL;
    node_t * startp=NULL;
    int modoImpressao;
    Cidades=fopen("tempcities.csv","r");
Paises=fopen("tempcountries_short.csv","r");
   // receberDados(argc , argv, &Cidades, &Paises, modoImpressao);   /* os files que ela muda sao os files a ser usados posteriormente*/
    getfile(&startc,Cidades,1);   /* falta preencher o primeiro parametro */
   // getfile(&startp,Paises,2);

    while(1==1 )
    {
       
        menuPrincipal(&idxMenu);
        switch (idxMenu)
        {
            case 1:
            menuFiltragem(&idxFiltragem, &fmes, &fano, &primeiroMes, &ultimoMes);                      
                   
            break;

            case 2:
            menuTemperaturas(&idxTemperaturas,&periodoAmostragem, nomePais, nomeCidade);

            break;

            case 3:
            menuAnoAnalise(&idxAnoAnalise);
            break;

            case 4:
            menuGlobalAnalise(&idxGlobalAnalise,&_nMeses, nomePais, nomeCidade);

            break;

            case 5;

            printf("O programa irá fechar agora.\n");
            exit(EXIT_SUCESS);
            break;
        }
    }
}

int menuPrincipal(int *_idxMenu)
{
    char buff[SIZE_OF_STRING];
    printf("Escolha com o correspondente ao menu que pretende aceder:\n");
    printf("1.Filtragem de dados. \n2.Historico de temperaturas. \n3.Analise da temperatura por ano. \n4.Analise da temperatura global.\n5. Fechar o programa.\n");
    do{
        fgets(buff, SIZE_OF_STRING, stdin);
        sscanf(buff, "%d", _idxMenu);
        if (*_idxMenu<1 ||*_idxMenu>5)
        printf(" Escolheu um número nao válido. Por favor introduza um compreendido entre 1 e 4.\n");
          
    }while(*_idxMenu<1 ||*_idxMenu>5);

    return *_idxMenu;
}

void menuFiltragem(int *_idxFiltragem, int *_fmes, int *_fano,int *primeiroMes, int *ultimoMes )
{
     int fmes=0, fano=0, primeiroMes=0, ultimoMes=0,
    
    char buff[SIZE_OF_STRING];
    printf("Escolha com o correspondente o menu que pretende aceder. \n1.Limpar criterios. \n2.Escolhe um mes e um ano. todos os dados anteriores sao removidos. \n3. Escolhe 2 meses. todos os meses fora desse parametro serao removidos.\n");
    do{
      fgets(buff, SIZE_OF_STRING, stdin);
      sscanf(buff, "%d", _idxFiltragem);
      if (*_idxFiltragem<1 || *_idxFiltragem>3)
          printf("Escolheu um nao valido. Por favor introduza um compreendido entre 1 e 3.\n");
          
    }while(*_idxFiltragem<1 || *_idxFiltragem>3);



    if(*_idxFiltragem == 1)
    {
             /* funcao que enche a lista outra vez sem criterios*/
    }


    if(*_idxFiltragem==2)
    {
        char buff[SIZE_OF_STRING];
        printf("\nIrá escolher um para o ano e outro para o mês. Todas as datas anteriores a isso vão ser eliminadas.\n\n\n");
        printf("Agora vai escolher um ano.\n");
        do{
            fgets(buff, SIZE_OF_STRING, stdin);
            sscanf(buff, "%d", _fano);
            if (*_fano<1950 || *_fano>2013)
            {

                printf("Escolheu um número não válido. Por favor introduza um número para o ano entre x e y..\n"); /* definir ainda ano minimo e ano maximo*/
            }
        }while(*_fano<1950 || *_fano>2013);

        printf("Agora vai escolher um mês. Escolha um número compreendido entre 1 e 12. \n");
        do{
            fgets(buff, SIZE_OF_STRING, stdin);
            sscanf(buff, "%d", _fmes );
            if (*_fmes<1 || *_fmes>12 )
            {

                printf("Escolheu um não válido. Por favor introduza um número para o mês entre 1 e 12.\n"); /* definir ainda ano minimo e ano maximo*/
            }
        }while(*_fmes<1 || *_fmes>12 );
    }

    if(*_idxFiltragem == 3)
    {
        
        char buff[SIZE_OF_STRING];
        printf("Escolha agora o intervalo de meses que pretende analisar. Todos os meses que estiverem fora desse intervalo serão eliminados.\n");
        printf("Introduza agora o mês de valor inferior.\n");
        do{
            fgets(buff, SIZE_OF_STRING, stdin);
            sscanf(buff, "%d", _primeiroMes);
            if(*_primeiroMes <1 || *_primeiroMes>12)
                printf("Introduza valores validos para o primeiro e último mês.\n");
        }while(*_primeiroMes <1 || *_primeiroMes>12 );

        printf("Introduza agora o mês de valor superior\n");
         do{
            fgets(buff, SIZE_OF_STRING, stdin);
            sscanf(buff, "%d", ultimoMes);
            if(*_primeiroMes <1 || *_primeiroMes>12 || *_ultimoMes<1 || *_ultimoMes>12 || *_primeiroMes>ultimoMes)
                printf("Introduza valores validos para o primeiro e último mês.\n");
        }while(*_primeiroMes <1 || *_primeiroMes>12 || *_ultimoMes<1 || *_ultimoMes>12 || *_primeiroMes>ultimoMes);

    }
}

void menuTemperaturas( int *_idxTemperaturas, int *_periodoAmostragem,char _nomePais[], char _nomeCidade[])
{
    char buff[SIZE_OF_STRING];
    printf("Introduzida o periodo de amostragem que pretende. Escolha um valor entre 1 e 100.\n");
    do{
        fgets(buff, SIZE_OF_STRING, stdin);
        sscanf(buff, "%d",_periodoAmostragem);
        if (*_periodoAmostragem<1 || *_periodoAmostragem>100)
            printf("Escolheu um número não válido. Por favor introduza um número valido positivo menor que 100.\n");
          
    }while(*_periodoAmostragem<1 || *_periodoAmostragem>100);

    printf("Escolha agora o correspondente ao menu que pretende aceder.\n 1. Global: aplica-se a todos os paises. \n2.Por pais:aplica-se a um unico pais. \n3.Por cidade: aplica-se a uma unica cidade.");

    do{
          fgets(buff, SIZE_OF_STRING, stdin);
          sscanf(buff, "%d", _idxTemperaturas);
          if (*_idxTemperaturas<1 || *_idxTemperaturas>3)
          printf(" Escolheu um não valido. Por favor introduza um entre 1 e 3.\n");
          
    }while(*_idxTemperaturas<1 ||*_idxTemperaturas>3);

    if(*_idxTemperaturas==2)
    {
        printf("Que pais pretende analisar?\n");
        fgets(buff, SIZE_OF_STRING, stdin);
        sscanf(buff, "%s", _nomePais);    /* preciso fazer com q a funcao diga q foi escolhido pais e nao cidade*/
    }

    if(*_idxTemperaturas==3)
    {
        printf("Que pais pretende analisar?\n");
        fgets(buff, SIZE_OF_STRING, stdin);
        sscanf(buff, "%s", _nomeCidade);   /* rpeciso fazer com q a funcao diga q foi escolhido cidade e nao pais*/
    }
    
}

void menuAnoAnalise( int *_idxAnoAnalise,int *_anoPretendido,int *_nCidades, int *_nPaises;)
{
    char buff[SIZE_OF_STRING];
    int idxAnoAnalise,anoPretendido, nCidades, nPaises;
    printf("Indique que ano pretende analisar. \n");

    do{
        fgets(buff, SIZE_OF_STRING, stdin);
        sscanf(buff, "%d", &anoPretendido);
        if(anoPretendido<1000 || anoPretendido>3000)
            printf("Escolheu um inválido. Por favor introduza um entre 1000 e 3000.\n");  /* ir ver qual o ano maixmo e o ano minimo*/
          
    }while(anoPretendido<1000 || anoPretendido>3000);
    
    printf("Escolha agora o correspondente ao menu que pretende aceder. \n1.Analise por pais. \n2.Analise por cidade");
    do{
        fgets(buff, SIZE_OF_STRING, stdin);
        sscanf(buff, "%d", &idxAnoAnalise);
         if (idxAnoAnalise<1 || idxAnoAnalise>2)
         printf("Escolheu um inválido. Por favor introduza um valido positivo menor que 2.\n");
          
    }while(idxAnoAnalise<1 || idxAnoAnalise>2);

    if(idxAnoAnalise==1)
    {
        printf("Quantas cidades pretende analisar? \n");
        do{
            fgets(buff, SIZE_OF_STRING, stdin);
            sscanf(buff, "%d", &nCidades);
            if(nCidades<1 || nCidades>20)
                 printf("Escolheu um inválido. Por favor introduza um número entre 1 e 20.\n");
          
         }while(nCidades<1 || nCidades>20);
    }

    if(idxAnoAnalise==2)
    {
        printf("Quantos paises pretende analisar? \n");
        do{
            fgets(buff, SIZE_OF_STRING, stdin);
            sscanf(buff, "%d", &nPaises);
            if(nPaises<1 || nPaises>20)
                 printf("Escolheu um inválido. Por favor introduza um número entre 1 e 20.\n");
          
         }while(nPaises<1 || nPaises>20);
    }
}

void menuGlobalAnalise( int *_idxGlobalAnalise, int *_nMeses,char _nomePais[], char _nomeCidade[])
{  
    char buff[SIZE_OF_STRING];
    printf("Indique quantas mediçoes pretende para fazer os cálculos. \n");
    do{
        fgets(buff, SIZE_OF_STRING, stdin);
        sscanf(buff, "%d", _nMeses);
        if (*_nMeses<1 || *_nMeses>2)
        printf("Escolheu um inválido. Por favor introduza um válido positivo menor que 3.\n");   
    }while(*_nMeses<1 || *_nMeses>2);
    printf("Escolha com o número correspondente o menu que pretende aceder.\n");
    printf("1. Aumento da temperatura global do planeta: Calculado como o aumento da temperatura em 1860, 1910, 1960, 1990, 2013. \n  O aumento da temperatura é calculado como a diferença entre o ano com menor temperatura média e o ano com a maior temperatura  média incluindo todos os anos anteriores. \n  Realize a média da temperatura de todos os países presentes nos dados. ");
    printf("2. Aumento da temperatura global de um país: O mesmo que o ponto 1, mas apenas incluindo os dados de um só país\n");
    printf("3. Aumento da temperatura global de uma cidade: O mesmo que o ponto 1, mas apenas inclindo os dados de uma só cidade");
     
    do{
        fgets(buff, SIZE_OF_STRING, stdin);
        sscanf(buff, "%d", _idxGlobalAnalise);
        if (*_idxGlobalAnalise<1 || *_idxGlobalAnalise>2)
        printf("Escolheu um inválido. Por favor introduza um número entre 1 e 3.\n");   
    }while(*_idxGlobalAnalise<1 || *_idxGlobalAnalise>2);


    if(*_idxGlobalAnalise==2)
    {
        printf("Introduza o nome do país que pretende analisar.\n");
       /* do{*/
            fgets(buff,SIZE_OF_STRING, stdin);
            sscanf(buff, "%s", _nomePais);
            /* if string n for valida ent qq coia*/
     /*  }while(if string n for valida ent qq coisa ) */

    }

    if(*_idxGlobalAnalise==3)
    {
        printf("iIntroduza o nome do cidade que pretende analisar.\n");
       /* do{*/
            fgets(buff,SIZE_OF_STRING, stdin);
            sscanf(buff, "%s", _nomeCidade);
            /* if string n for valida ent qq coia*/
     /*  }while(if string n for valida ent qq coisa ) */

    }
}

 
void filtragem(node_t **headpaises, node_t **headcities, int _fmes, int _fano, int _primeiroMes, int _ultimoMes, int _idxFiltragem) /* talvez usar lista newNodeliar*/
{ 
    node_t *aux=NULL;

    
    
    if(_idxFiltragem==1)
    {
       /* getfile(node_t ** start_,FILE * file,1);*/  /* falta preencher o primeiro parametro */
        /*getfile(node_t ** start_,FILE * file,2);*/
    }
    if(_idxFiltragem==2)
    {
        if(  (_filtrar->payload.dt.ano)  <  _fano)
        {
            aux = _filtrar;
            free(aux);
        }

        if( (_filtrar->payload.dt.ano) == _fano && _filtrar->payload.dt.mes<_fmes)
        {
            aux = _filtrar;
            free(aux);
        }
    }

    if(_idxFiltragem ==3)
    {

        if(  (_filtrar ->payload.dt.mes)  <  (_primeiroMes) || (_filtrar ->payload.dt.mes)  >  (_ultimoMes)  )
            {
                aux = _filtrar;
                free(aux);
            }                

    }
}

void temperaturas(node_t **headpaises, node_t **headcities, int idxTemperaturas,int periodoAmostragem,char _nomeCidade[], char _nomePais[] ) /* talvez usar lista */
{
    
    node_t *aux=(node_t*) malloc(sizeof(node_t));
    
    if (idxTemperaturas==1)
    {

        /* funcao que faz o tabela cm medias etc etc para todos os paises*/
    }
    if (idxTemperaturas==2)
    {
        aux = _temperaturas;

        if(strcmp(_nomePais ,_temperaturas->payload.pais)!=0)
            free(aux);


        /* funcao que faz o tabela ja cm as medias etc etc para um pais especifico mas so e preciso invocar a funcao pq a lista ja foi reduzida para apenas esse pais especifico*/

    }

    if (idxTemperaturas==3)
    {
        aux = _temperaturas;

        if(strcmp(_nomePais,_temperaturas->payload.cidade)!=0)
            free(aux);    
        
        /*funcao que faz os graficos com as medias etc etc para uma cidade especifica*/
        

    }
}

void anoAnalise(node_t **headpaises, node_t **headcities, int _idxAnoAnalise, int _anoPretendido, int _nCidades, int _nPaises) /* talvez usar lista newNodeliar e e ficheiro dos paises*/
{
    node_t *aux=(node_t*) malloc(sizeof(node_t));
    if(  (_analise->payload.dt.ano) != _anoPretendido)
    {
        aux = _analise;
        free(aux); 

    }


    if(_idxAnoAnalise==1)
    {
        /*funcao que procura os N paises nas varias condicoes pedidas para paises*/

    }

    if(_idxAnoAnalise ==2)
    {

        /*funcao que procura os N paises nas varias condicoes pedidas para cidades*/
    }

}

void globalAnalise(node_t **headpaises, node_t **headcities,int _nMeses)
{


}


