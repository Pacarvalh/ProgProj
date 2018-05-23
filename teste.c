#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "functions.h"
#include "data.h"
#define SIZE_OF_STRING 1000
#define NONTEMP 9999999999
#define NONST "EMPTY"

void switchMenu(int argc, char *argv[])
{
   
    int idxMenu=1 ;
    char buff[SIZE_OF_STRING];
    char nomeCidade[SIZE_OF_STRING], nomePais[SIZE_OF_STRING];
    FILE *Cidades=NULL, *Paises=NULL;
    node_t * startc=NULL;
    node_t * startp=NULL;

    int modoImpressao;
Cidades=fopen("tempcities.csv","r");
Paises=fopen("tempcountries.csv","r");

  /* receberDados(argc , argv, &Cidades, &Paises, modoImpressao); */  /* os files que ela muda sao os files a ser usados posteriormente*/
  getfile(&startc,Cidades,1);  /* falta preencher o primeiro parametro */
  // getfile(&startp,Paises,2);

    
}







 




node_t *getNewNode(char *data,float Temperatura,float incerto,char *pais,char *city, char *lati, char *longi,int choi) /* novos valores preciso colocar nas estruturas*/
{
    node_t * newNode = (node_t*) malloc(sizeof(node_t));
    char s[SIZE_OF_STRING]="-";
   
    
    if(newNode==NULL)
    {
        printf("memory allocation error \n");
        exit(EXIT_FAILURE);
    }
   /* printf("52\n");*/

    newNode->payload.dt.ano=atoi(strtok(data,s));
    newNode->payload.dt.mes=atoi(strtok(NULL,s));
    newNode->payload.dt.dia=atoi(strtok(NULL,s));
    newNode->payload.temperatura=Temperatura;
    newNode->payload.incerteza=incerto;
    strcpy(newNode->payload.pais,pais);
    
    if (choi==1){ /*só entra se estiver na cidade,fica definido que a escolha 1 é cidade*/
        strcpy(newNode->payload.cidade,city);
        strcpy(newNode->payload.lat,lati);
        strcpy(newNode->payload.longit,longi);
    }
    newNode->next = NULL;
    newNode->prev = NULL;

    
    return newNode;
}


void getfile(node_t ** start_,FILE * file,int choi)
{   char buffer[SIZE_OF_STRING];
    int i=0;
    fgets(buffer,SIZE_OF_STRING,file);  
    while(fgets(buffer,SIZE_OF_STRING,file))
    {  /* if (i++>10)
        {break;}*/
        switch (choi)
        {   case 1:
                /*printf("case1\n");*/
                putCity(buffer,&start_,choi);
                
                break;
                /* o q e q e suposto fazer?*/
            case 2:
                /*printf("case2\n");*/
                putCity(buffer,&start_,choi);/*Não te preocupes com o nome estar ser putCity, a funçao dá para os dois*/
                 
                /*ordenarLista(node_t *_newElem, node_t *_head);*/
                break;
        }
    }
    


}


node_t *putCity(char * _buff,node_t *** _start,int choi)  /* se der return a 1, entra na lista, se der return a 0 nao entra na lista */
{   node_t *auxi =(node_t *) malloc(sizeof(node_t));
    char * comma = _buff;
    float Temperatura,incerto;
    char pais[SIZE_OF_STRING]="",city[SIZE_OF_STRING]="", latitude[ SIZE_OF_STRING] = "", longitude [SIZE_OF_STRING] = "";
    char au[SIZE_OF_STRING]="";
    char data[SIZE_OF_STRING]="";
   
    long int tam = strcspn(comma,",\n");
    strncpy(data,comma,tam);
    comma+=tam+1;
    

    if ((*comma)==',')
    {
        Temperatura=NONTEMP;
        return 0;   
    }
    else 
    {   tam = strcspn(comma,",\n");
        strncpy(au,comma,tam);
        Temperatura = atof(au);
        comma+=tam+1;
        if(Temperatura > 70 || Temperatura < -70 )
            return 0;

    }
    if ((*comma)==',')
    {   incerto=NONTEMP;
        comma++; 
            return 0;  
    }
    else
    {
        tam = strcspn(comma,",\n");
        strncpy(au,comma,tam);
        incerto = atof(au);
        comma+=tam+1;
        /* verificar valor aceitavel */
        if(incerto > 3)
        return 0;
    }
    if ((*comma)==',')
    {   strcpy(pais,NONST);
        comma++;
        return 0;
    }
    else 
    {   
        tam = strcspn(comma,",\n");
        strncpy(pais,comma,tam);
        comma+=tam+1;

    }
    if ((*comma)==',')
    {   strcpy(city,NONST);
        comma++;
        return 0;
    }
    else
    {
        tam = strcspn(comma,",\n");
        strncpy(city,comma,tam);
        comma+=tam+1;
        
    }

        
    
    tam = strcspn(comma,",\n");
    strncpy(latitude,comma,tam);
    comma+=tam+1;

    tam = strcspn(comma,",\n");
    strncpy(longitude,comma,tam);
    comma+=tam+1;

   /* printf("177\n");*/
    auxi=getNewNode(data,Temperatura,incerto,pais,city,latitude,longitude,choi);
    /*printf("%s\n\n\n\n\n\n\n\n\n\n\n",auxi->payload.pais);*/
    if(**_start ==NULL)
    {
        **_start = auxi;
        auxi->prev = NULL;
        auxi -> next = NULL;
        
    }
    auxi->next = **_start;
    auxi -> prev = NULL;
    **_start = auxi;

    
    return  **_start;        /*verificar numero de  ** */
}





 

void receberDados(int argc , char * argv[], FILE **Cidade, FILE **Paises, int *modoImpressao)
{
    int aux1=0, aux2=0;
    int i;
    for( i=0 ; i<= argc; i++)
    {
        if(strcmp(argv[i],"-t"== 0))
        {
            *modoImpressao=2;
            aux1=1;

        }

        else if(strcmp(argv[i],"-g"== 0))
        {
            *modoImpressao=1;
            aux2=1;

        }

        else if(strcmp(argv[i],"-f1"== 0))
        {
            *Cidade = fopen(argv[(i++)+1], "r");
        }

        else if(strcmp(argv[i],"-f2"== 0))
        {
            *Paises = fopen(argv[(i++)+1], "r");
        }
    }
    if (aux1=1 && aux2 ==1)
    {
        printf("Erro. O ficheiro nao pode ser do tipo grafico e textual ao mesmo tempo");
        exit(EXIT_FAILURE);
    }

}


