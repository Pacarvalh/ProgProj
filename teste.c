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
   
Cidades=fopen("tempcities_short.csv","r");
Paises=fopen("tempcountries_short.csv","r");/*tempcountries.csv"*/

  /* receberDados(argc , argv, &Cidades, &Paises, modoImpressao); */  /* os files que ela muda sao os files a ser usados posteriormente*/
 //getfile(&startc,Cidades,1);  /* falta preencher o primeiro parametro */
  getfile(&startp,Paises,2);
 startp=merge(startp);

  
// merge(startp);
 
 if(0==1)
    {
     getfile(&startc,Cidades,1);  /* falta preencher o primeiro parametro */
   getfile(&startp,Paises,2);
    }
      printf("efwg");
  fflush(stdout);
//filtragem(&startc, 9, 2012,3, 5, 2);
  printf("1234");
  fflush(stdout);
   
printlist(startp);
  printf("1234");
  fflush(stdout);

    
}







 




node_t *getNewNode(char *data,float Temperatura,float incerto,char *pais,char *city, char *lati, char *longi,int choi) /* novos valores preciso colocar nas estruturas*/
{
    node_t * newNode = (node_t*) malloc(sizeof(node_t));
    char s[SIZE_OF_STRING]="-";
    //char a[SIZE_OF_STRING]="",b[SIZE_OF_STRING]="",c[SIZE_OF_STRING]="";
    int a,b,c;
    a=atoi(strtok(data,s));
    b=atoi(strtok(NULL,s));
    c=atoi(strtok(NULL,s));
            

    //printf("data----%d---%d---%d\n",a,b,c);
     
    if(newNode==NULL)
    {
        printf("memory allocation error \n");
        exit(EXIT_FAILURE);
    }
   /* printf("52\n");*/
   
    newNode->payload.dt.ano=a;
    newNode->payload.dt.mes=b;
    newNode->payload.dt.dia=c;
    newNode->payload.temperatura=Temperatura;
    newNode->payload.incerteza=incerto;
    strcpy(newNode->payload.pais,pais);
   // printf("")
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
     //fgets(buffer,SIZE_OF_STRING,file); 
    while(fgets(buffer,SIZE_OF_STRING,file))
    {   if ((i++)>49800)
        {break;}
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
    static int i=0;
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
    /*printf("%d\n\n",i++);*/
    if(strcmp(pais,"country")==0)
        return 0;

   //printf("177\n");
    
    auxi=getNewNode(data,Temperatura,incerto,pais,city,latitude,longitude,choi);
    /*printf("%d\n",auxi->payload.dt.ano);
    printf("%d\n",auxi->payload.dt.mes);
    printf("%d\n",auxi->payload.dt.dia);
    printf("%f\n",auxi->payload.temperatura);
    printf("%f\n",auxi->payload.incerteza);
    printf("%s\n",auxi->payload.pais);
   printf("%s\n",auxi->payload.cidade);
    printf("%s\n",auxi->payload.lat);
    printf("%s\n",auxi->payload.longit);
*/  //printf("%d\n\n\n\n\n",i++);
  if(choi!=0) /*o erro é aqui*/
  {   auxi->next = **_start;
    auxi-> prev = NULL;
    **_start = auxi;
      
      if(**_start ==NULL)
    {
        **_start = auxi;
        auxi->prev = NULL;
        auxi -> next = NULL;
        
    }
  
  }
   /*if(!**_start)
    **_start=auxi;
    else
    {
        auxi->next=**_start;
        auxi->next->prev=auxi;
        **_start=auxi;


    }  */
  /* if (choi==2)
    ordenarLista(auxi, &_start);*/
   
    
    return  **_start;        /*verificar numero de  ** */
}







void ordenarLista(node_t *newElem, node_t ****_start)
{   static int i=0;
    node_t * current;
    //printf("safef");
    //printf("%d",i++);*/
    if ((i++)==50 ||i==1000 ||i==5000|| i==10000 || i==40000)
        printf("%d\n",i);
   if(***_start==NULL)
        ***_start=newElem;
    else if((***_start)->payload.dt.ano>newElem->payload.dt.ano || ((***_start)->payload.dt.ano==newElem->payload.dt.ano && (***_start)->payload.dt.mes>newElem->payload.dt.mes))
    {
        newElem->next = ***_start;
        newElem->next->prev=newElem;
        ***_start=newElem;
    }

    else{
        current = ***_start;
        while (current->next !=NULL && (current->next->payload.dt.ano<newElem->payload.dt.ano|| (current->next->payload.dt.ano==newElem->payload.dt.ano && current->next->payload.dt.mes<newElem->payload.dt.mes)))
            current = current->next;

        newElem->next = current->next;

        if (current->next!=NULL)
            newElem->next->prev = newElem;
        
        current->next = newElem;
        newElem->prev = current;
    }
}


node_t * junta(node_t * a,node_t * b)
{
    node_t * jajuntas = NULL;
    static int i=0;
    //printf("\n%d\n",i++);
    if(a==NULL)
        return b;
    if (b==NULL)
        return a;
    if((a)->payload.dt.ano<b->payload.dt.ano || (a->payload.dt.ano==b->payload.dt.ano && a->payload.dt.mes<b->payload.dt.mes))
    {
        a->next=junta(a->next,b);
        a->next->prev=a;
        a->prev=NULL;
        return a;
    }
    else
    {    b->next=junta(a,b->next);
        b->next->prev=b;
        b->prev=NULL;
        return b;
       
    }
    

}

node_t * merge(node_t * _start)
{
    if(!_start||!_start->next)
        return _start;

    node_t * second = separa(_start);
    _start=merge(_start);
    second=merge(second);
    return junta(_start,second);
}

node_t * separa(node_t * _head)
{
   node_t * rapido=_head,*lento=_head;
  
    while(rapido->next && rapido->next->next)
    {
        rapido = rapido->next->next;
        lento=lento->next;
    }
    node_t * temp = lento->next;
    lento->next=NULL;
    return temp;
   
}

void filtragem(node_t **_head, int _fmes, int _fano, int _primeiroMes, int _ultimoMes, int _idxFiltragem) /* talvez usar lista newNodeliar*/
{ 
    node_t *aux=NULL;
    node_t *temp=NULL;

    
    

    if(_idxFiltragem==2)
    {
        aux = *_head;
        
        while((aux->next->payload.dt.ano)  <  _fano || (aux->next->payload.dt.ano) == _fano && aux->next->payload.dt.mes<_fmes)
        {
            temp=aux->next;
            free(aux);
            aux = temp;
            
        }

        *_head= aux; 

        
    
    }
/*
    if(_idxFiltragem ==3)
    {

        aux = *_head;
        temp=aux;
        printf("386");
        fflush(stdout);

        while(temp -> next != NULL)
        {
            if(  (temp->payload.dt.mes)  <  (_primeiroMes) || (temp ->payload.dt.mes)  >  (_ultimoMes)  )
            {
                printf("loop\n");
                fflush(stdout);
                
                temp=aux;
                temp->prev->next=temp->next;
                temp->next->prev=temp->prev;
                free(aux);
                printf("after loop\n");
                fflush(stdout);

            }                
               

            temp = temp-> next;

        } printf("out of loop\n\n\n\n\n\n\n\n\n");
                fflush(stdout);
        while(temp->prev!=NULL)
            temp=temp->prev;

        
        *_head= temp; 
       printf("%s\n",temp->payload.pais);
       printf("%f\n\n\n\n",temp->payload.temperatura);
      
    }*/
}


void printlist(node_t *_start)
{   node_t * temp = (node_t *) malloc(sizeof(node_t));
    temp = _start;
static int i=0;/*
if ((i++)==50 ||i==1000 ||i==5000|| i==10000 || i==40000)
        printf("%d\n",i);*/
    while( (temp->next!=NULL || temp->next->next!=NULL )/*&&(strcmp(temp->payload.pais,"Country")!=0)*/)
    {
        printf("ano--%d  mes--%d\n\n",temp->payload.dt.ano,temp->payload.dt.mes);
        temp=temp->next;
        //printf("\n%d",i++);
        fflush(stdout);
        if(temp->next==NULL)
        {
            break;
        }
    }  
    
}