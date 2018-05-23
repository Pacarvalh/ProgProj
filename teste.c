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
Paises=fopen("tempcountries_short.csv","r");/*tempcountries.csv"*/

  /* receberDados(argc , argv, &Cidades, &Paises, modoImpressao); */  /* os files que ela muda sao os files a ser usados posteriormente*/
 getfile(&startc,Cidades,1);  /* falta preencher o primeiro parametro */
   //getfile(&startp,Paises,2);
   printf("entra merge");
// merge(startp);
printlist(startc);

    
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
            

    /*printf("data----%d---%d---%d\n",a,b,c);*/
     
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
   /* newNode->next = NULL;
    newNode->prev = NULL;*/

    
    return newNode;
}


void getfile(node_t ** start_,FILE * file,int choi)
{   char buffer[SIZE_OF_STRING];
    int i=0;
    if(choi==1)
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
  if(choi==1)
  { if(**_start ==NULL)
    {
        **_start = auxi;
        auxi->prev = NULL;
        auxi -> next = NULL;
        
    }
    auxi->next = **_start;
    auxi-> prev = NULL;
    **_start = auxi;
  }
   /*if(!**_start)
    **_start=auxi;
    else
    {
        auxi->next=**_start;
        auxi->next->prev=auxi;
        **_start=auxi;


    }  */
   if (choi==2)
    ordenarLista(auxi, &_start);
   
    
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

/*
node_t * junta(node_t * a,node_t * b)
{
    node_t * jajuntas = NULL;
    static int i=0;
    printf("\n%d\n",i++);
    if(a==NULL)
        return b;
    if (b==NULL)
        return a;
    if((a)->payload.dt.ano<b->payload.dt.ano || (a->payload.dt.ano==b->payload.dt.ano && a->payload.dt.mes<b->payload.dt.mes))
    {
        jajuntas = a;
        jajuntas->next=junta(a->next,b);
    }
    else
    {
       jajuntas = b;
        jajuntas->next=junta(a,b->next);
    }
    return jajuntas;

}

void merge(node_t * _start)
{
    node_t * head = _start;
    node_t * a = NULL;
    node_t * b = NULL;
    static int i=0;
    printf("\n%d\n",i++);

    if(head==NULL || head->next==NULL)
        return;
    
    separa(head,a,b);
    merge(a);
    merge(b);
    _start = junta(a,b);
}

void separa(node_t * _head,node_t * a,node_t * b)
{
   node_t * rapido,*lento;
   node_t *aux;
    
   if(_head==NULL || _head->next == NULL)
   {
       a = _head;
       b = NULL;
       
   }
   else{
       lento=_head;
       rapido = _head->next;
       while(rapido!=NULL)
       {
           rapido = rapido->next;
           if(rapido!=NULL)
           {
               lento=lento->next;
               rapido=rapido->next;
           }

       }
       a = _head;
       b=lento->next;


   }
}
*/
void printlist(node_t *_start)
{   node_t * temp = _start;
static int i;
if ((i++)==50 ||i==1000 ||i==5000|| i==10000 || i==40000)
        printf("%d\n",i);
    while(_start || _start->next)
    {
        printf("ano--%d  mes--%d\n\n",temp->payload.dt.ano,temp->payload.dt.mes);
        temp=temp->next;
        
    }
}