#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "functions.h"
#include "data.h"
#define SIZE_OF_STRING 100

void switchMenu(int *_idxMenu, int *_idxFiltragem, int * _idxTemperaturas, int *_periodoAmostragem, char _nomePais[], char _nomeCidade[], int *_idxAnoAnalise, int *_periodo, int *_anoPretendido, int *_nCidades, int *_nPaises, int *_nMeses)
{
   
    char buff[SIZE_OF_STRING];
    printf("Escolha com o numero correspondente ao menu que pretende aceder:\n");
    printf("1.Filtragem de dados. \n2. Historico de temperaturas. \n3.Analise da temperatura por ano. \n4. Analise da temperatura global.\n");
    do{
        fgets(buff, SIZE_OF_STRING, stdin);
        sscanf(buff, "%d", _idxMenu);
        if (*_idxMenu<1 || *_idxMenu>4)
        printf(" Escolheu um numero nao valido. Por favor introduza um numero compreendido entre 1 e 4.\n");
          
    }while(*_idxMenu<1 || *_idxMenu>4);

    
    switch (*_idxMenu)
    {
        case 1:
        menuFiltragem(&_idxFiltragem);


        printf("Escolha agora que menu pretende analisar com os criterios predefinidos. \n2. Historico de temperaturas. \n3.Analise da temperatura por ano. \n4. Analise da temperatura global.\n ");

                switch (*_idxMenu)
                {
                    case 2:
                    menuTemperaturas(&_idxTemperaturas, &_periodoAmostragem, _nomePais, _nomeCidade );
                    break;
                    case 3:
                    menuAnoAnalise(&_idxAnoAnalise, &_anoPretendido, &_nCidades, &_nPaises);

                    break;
                    case 4:
                    menuGlobalAnalise(&_nMeses);

                    break;
                }
        break;

        case 2:
        menuTemperaturas(&_idxTemperaturas, &_periodoAmostragem, _nomePais, _nomeCidade);
        break;

        case 3:
        menuAnoAnalise(&_idxAnoAnalise, &_anoPretendido, &_nCidades, &_nPaises);
        break;

        case 4:
        menuGlobalAnalise(&_nMeses);
        break;
    }
}


void menuFiltragem(int  **_idxFiltragem)
{
    
    if(**_idxFiltragem == 1)
    {
        char buff[SIZE_OF_STRING];
        printf("Escolha com o numero correspondente o menu que pretende aceder. \n1.Limpar criterios. \n2.Escolhe um mes e um ano. todos os dados anteriores sao removidos. \n3. Escolhe 2 meses. todos os meses fora desse parametro serao removidos.\n");
        do{
          fgets(buff, SIZE_OF_STRING, stdin);
          sscanf(buff, "%d", _idxFiltragem);
          if (**_idxFiltragem<1 || **_idxFiltragem>3)
          printf("Escolheu um numero nao valido. Por favor introduza um numero compreendido entre 1 e 3.\n");
          
        }while(**_idxFiltragem<1 || **_idxFiltragem>3);
    }
}

void menuTemperaturas( int **_idxTemperaturas, int  **_periodoAmostragem, char *_nomePais[100], char *_nomeCidade[100] )
{
    char buff[SIZE_OF_STRING];
    Printf("Introduzida o periodo de amostragem que pretende. Escolha um valor entre 1 e 100.\n");
    do{
        fgets(buff, SIZE_OF_STRING, stdin);
        sscanf(buff, "%d", *_periodoAmostragem);
        if (**_periodoAmostragem<1 || **_periodoAmostragem>100)
            printf("Escolheu um numero nao valido. Por favor introduza um numero valido positivo menor que 100.\n");
          
    }while(**_periodoAmostragem<1 || **_periodoAmostragem>100);

    printf("Escolha agora o numero correspondente ao menu que pretende aceder.\n 1. Global: aplica-se a todos os paises. \n2.Por pais:aplica-se a um unico pais. \n3.Por cidade: aplica-se a uma unica cidade.");

    do{
          fgets(buff, SIZE_OF_STRING, stdin);
          sscanf(buff, "%d", _idxTemperaturas);
          if (**_idxTemperaturas<1 || **_idxTemperaturas>3)
          printf(" Escolheu um numero nao valido. Por favor introduza um numero entre 1 e 3.\n");
          
    }while(**_idxTemperaturas<1 || **_idxTemperaturas>3);

    if(**_idxTemperaturas==2)
    {
        printf("Que pais pretende analisar?\n");
        fgets(buff, SIZE_OF_STRING, stdin);
        sscanf(buff, "%s", _nomePais[SIZE_OF_STRING]);    // preciso fazer com q a funcao diga q foi escolhido pais e nao cidade
    }

    if(**_idxTemperaturas==3)
    {
        printf("Que pais pretende analisar?\n");
        fgets(buff, SIZE_OF_STRING, stdin);
        sscanf(buff, "%s", _nomeCidade[SIZE_OF_STRING]);   // rpeciso fazer com q a funcao diga q foi escolhido cidade e nao pais
    }
    
}

void menuAnoAnalise(int **_idxAnoAnalise, int **_anoPretendido, int **_nCidades, int **_nPaises)
{
    char buff[SIZE_OF_STRING];
    
    printf("Indique que ano pretende analisar. \n");

    do{
        fgets(buff, SIZE_OF_STRING, stdin);
        sscanf(buff, "%d", _anoPretendido);
        if(**_anoPretendido<1000 || **_anoPretendido>3000)
            printf("Escolheu um numero invalido. Por favor introduza um numero entre 1000 e 3000.\n");  // ir ver qual o ano maixmo e o ano minimo
          
    }while(**_anoPretendido<1000 || **_anoPretendido>3000);
    
    printf("Escolha agora o numero correspondente ao menu que pretende aceder. \n1.Analise por pais. \n2.Analise por cidade");
    do{
        fgets(buff, SIZE_OF_STRING, stdin);
        sscanf(buff, "%d", _idxAnoAnalise);
         if (**_idxAnoAnalise<1 || **_idxAnoAnalise>2)
         printf("Escolheu um numero invalido. Por favor introduza um numero valido positivo menor que 2.\n");
          
    }while(**_idxAnoAnalise<1 || **_idxAnoAnalise>2);

    if(**_idxAnoAnalise==1)
    {
        printf("Quantas cidades pretende analisar? \n");
        do{
            fgets(buff, SIZE_OF_STRING, stdin);
            sscanf(buff, "%d", _nCidades);
            if(**_nCidades<1 || **_nCidades>20)
                 printf("Escolheu um numero invalido. Por favor introduza um numeroentre 1 e 20.\n");
          
         }while(**_nCidades<1 || **_nCidades>20);
    }

    if(**_idxAnoAnalise==2)
    {
        printf("Quantos paises pretende analisar? \n");
        do{
            fgets(buff, SIZE_OF_STRING, stdin);
            sscanf(buff, "%d", _nPaises);
            if(**_nPaises<1 || **_nPaises>20)
                 printf("Escolheu um numero invalido. Por favor introduza um numeroentre 1 e 20.\n");
          
         }while(**_nPaises<1 || **_nPaises>20);
    }
}

void menuGlobalAnalise(int **_nMeses)
{  
    char buff[SIZE_OF_STRING];
    printf("Indique quantas mediçoes pretende para fazer os calculos. \n");
    do{
        fgets(buff, SIZE_OF_STRING, stdin);
        sscanf(buff, "%d", _nMeses);
        if (**_nMeses<1 || **_nMeses>2)
        printf("Escolheu um numero invalido. Por favor introduza um numero valido positivo menor que 3.\n");   
    }while(**_nMeses<1 || **_nMeses>2);
}


void receberDados(int argc , char * argv[], FILE **Cidade, FILE **Paises, int *modoImpressao)
{
    int aux1=0, aux2=0 , i=0;
    for( i=0 ; i<= argc;  i++)
    {
        if(strcmp(argv[i],"-t"== 0))
        {
            *modoImpressao=1;
            aux1=1;

        }

        else if(strcmp(argv[i],"-g"== 0))
        {
            *modoImpressao=2;
            aux2=1;

        }

        else if(strcmp(argv[i],"-f1"== 0))
        {
            *Cidade = fopen(argv[i+1], "r");
            
        }

        else if(strcmp(argv[i],"-f2"== 0))
        {
            *Paises = fopen(argv[i+1], "r");

        }
    }
    if (aux1=1 && aux2 ==1)
    {
        printf("Erro. O ficheiro nao pode ser do tipo grafico e textual ao mesmo tempo");
        exit(EXIT_FAILURE);
    }
} 

/*void lerFicheiros(FILE *Cidades, FILE *Paises)
{
    char buff[SIZE_OF_STRING];
    char data [SIZE_OF_STRING]
    const char virgula [SIZE_OF_STRING]= ",";

    while(fgets(buff, SIZE_OF_STRING,(FILE*)Cidades)!=NULL )
    {
        node_t *newElem =NULL;

        newElem = getNewNode();


        
        

            
    }
            
}
 */

node_t *getNewNode(void) // novos valores preciso colocar nas estruturas
{
    node_t *newNode;
 
    newNode=(node_t *)malloc(sizeof(node_t));
    if(newNode==NULL)
    {
        printf("memory allocation error \n");
        exit(EXIT_FAILURE);
    }
    //newNode -> dia = constante;
    //newNode -> mes = _mes;
    //newNode -> ano = constate;

    newNode->next = NULL;
    newNode->prev = NULL;

    return newNode;
}




/*node_t *insertHead(node_t *_head)  // novos valores e preciso colocalos nas estruturas
{
    node_t *newValues=NULL;

    newValues=getNewNode();   // colocar argumentos

    if(_head ==NULL)
    {
        _head = newNode;
        newValues->prev = NULL;
        newValues -> next = NULL;
        return newValues;
    }
    newValues->next = _head;
    newValues -> prev = NULL;
    _head = newValues;

    return newValues;
}
*/

/*node_t insertTail(node_t **_head)  
{
    node_t *newValues= NULL;
    node_t *aux= NULL;
    newValues =getNewNode()  // colocar argumentos

    if(*_head == NULL)
    {
        *_head ==newValues;
        return;
    }

    aux = *_head;
    while(aux->next !=NULL)
    {
        aux=aux->next;
    }

    aux->next=newValues; // sera q fica na lista o proximo elemento?

}
*/

