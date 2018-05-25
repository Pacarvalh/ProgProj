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
    int i,a,b,c,d;
    int idxMenu=1, idxFiltragem, idxAnoAnalise, idxGlobalAnalise, idxTemperaturas, fmes=0, fano=0, primeiroMes=0, ultimoMes=0, periodoAmostragem,anoPretendido,nCidades,nPaises,nMeses;
    char buff[SIZE_OF_STRING];
    char nomeCidade[SIZE_OF_STRING], nomePais[SIZE_OF_STRING];
    FILE *Cidades=NULL, *Paises=NULL;
    node_t * startc=NULL;
    node_t * startp=NULL;
    int modoImpressao;
    for(i=0;i<argc; i++)
        {
            if(strcmp(argv[i], "-f1")==0)
                a=i+1;
                Paises=fopen(argv[i],"r");

            if(strcmp(argv[i], "-f2")==0)
                b=i+1;
                Cidades=fopen(argv[i],"r");
            if(strcmp(argv[i],"-t")==0)
                c=i;

            if (strcmp(argv[i], "-g")==0)
                d=1;

            if(c==1 && d==1)
            {
                printf("Não é possivel abrir o modo textual e gráfico ao mesmo tempo");
                exit(EXIT_FAILURE);
            }

        }

    /*Cidades=fopen("tempcities_short.csv","r");
    Paises=fopen("tempcountries_short.csv","r");*//*tempcountries.csv"*/
    getfile(&startc,Cidades,1);  /* falta preencher o primeiro parametro */
    getfile(&startp,Paises,2);
    startp=merge(startp);
               //     printlist(startp);
               // printlist(startc);


    while(1==1 )
    {
       
        menuPrincipal(&idxMenu);
        switch (idxMenu)
        {
            case 1:
            
            menuFiltragem(&idxFiltragem, &fmes, &fano, &primeiroMes, &ultimoMes);  
            
            if(idxFiltragem==1)
            {   clearList(&startp);
                clearList(&startc);


               // printlist(startc);
                getfile(&startp,Paises,2);
                                printf("badjoras2");
                fflush(stdout);
                
                startp=merge(startp);
                                printf("badjoras3");
                fflush(stdout);
                
                getfile(&startc,Cidades,1);
                printf("badjoras4");
                fflush(stdout);

                printlist(startp);
            
            }
      
            filtragem(&startp, fmes, fano, primeiroMes, ultimoMes,idxFiltragem,Paises,Cidades,2); 
            filtragem(&startc, fmes, fano, primeiroMes, ultimoMes,idxFiltragem,Paises,Cidades,1);                        
            //printlist(startc);
            break;

            case 2:
             
            menuTemperaturas(&idxTemperaturas,&periodoAmostragem, nomePais, nomeCidade);
            obterm(startp,"New York",10);
            break;

            case 3:
            menuAnoAnalise(&idxAnoAnalise,&anoPretendido,&nCidades,&nPaises);
            break;

            case 4:
            menuGlobalAnalise(&idxGlobalAnalise,&nMeses, nomePais, nomeCidade);

            break;

            case 5:

            printf("O programa irá fechar agora.\n");
            exit(EXIT_SUCCESS);
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

void menuFiltragem(int *_idxFiltragem, int *_fmes, int *_fano,int *_primeiroMes, int *_ultimoMes )
{
     
    
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
            sscanf(buff, "%d", _ultimoMes);
            if(*_primeiroMes <1 || *_primeiroMes>12 || *_ultimoMes<1 || *_ultimoMes>12 || *_primeiroMes>*_ultimoMes)
                printf("Introduza valores validos para o primeiro e último mês.\n");
        }while(*_primeiroMes <1 || *_primeiroMes>12 || *_ultimoMes<1 || *_ultimoMes>12 || *_primeiroMes>*_ultimoMes);

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

void menuAnoAnalise( int *_idxAnoAnalise,int *_anoPretendido,int *_nCidades, int *_nPaises)
{
    char buff[SIZE_OF_STRING];
    
    printf("Indique que ano pretende analisar. \n");

    do{
        fgets(buff, SIZE_OF_STRING, stdin);
        sscanf(buff, "%d", _anoPretendido);
        if(*_anoPretendido<1000 || *_anoPretendido>3000)
            printf("Escolheu um inválido. Por favor introduza um entre 1000 e 3000.\n");  /* ir ver qual o ano maixmo e o ano minimo*/
          
    }while(*_anoPretendido<1000 || *_anoPretendido>3000);
    
    printf("Escolha agora o correspondente ao menu que pretende aceder. \n1.Analise por pais. \n2.Analise por cidade");
    do{
        fgets(buff, SIZE_OF_STRING, stdin);
        sscanf(buff, "%d", _idxAnoAnalise);
         if (*_idxAnoAnalise<1 || *_idxAnoAnalise>2)
         printf("Escolheu um inválido. Por favor introduza um valido positivo menor que 2.\n");
          
    }while(*_idxAnoAnalise<1 || *_idxAnoAnalise>2);

    if(*_idxAnoAnalise==1)
    {
        printf("Quantas cidades pretende analisar? \n");
        do{
            fgets(buff, SIZE_OF_STRING, stdin);
            sscanf(buff, "%d", _nCidades);
            if(*_nCidades<1 || *_nCidades>20)
                 printf("Escolheu um inválido. Por favor introduza um número entre 1 e 20.\n");
          
         }while(*_nCidades<1 || *_nCidades>20);
    }

    if(*_idxAnoAnalise==2)
    {
        printf("Quantos paises pretende analisar? \n");
        do{
            fgets(buff, SIZE_OF_STRING, stdin);
            sscanf(buff, "%d", _nPaises);
            if(*_nPaises<1 || *_nPaises>20)
                 printf("Escolheu um inválido. Por favor introduza um número entre 1 e 20.\n");
          
         }while(*_nPaises<1 || *_nPaises>20);
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

 
void filtragem(node_t **_head, int _fmes, int _fano, int _primeiroMes, int _ultimoMes, int _idxFiltragem,FILE * _pais,FILE *_cidade,int choi) /* talvez usar lista newNodeliar*/
{   
    node_t *aux=NULL;
    node_t *temp=NULL;


    /*if(_idxFiltragem==1)
    {   
         switch(choi){
            case 2:
                getfile(&_head,_pais,2);
                *_head=merge(*_head);
                break;
            case 1:
                getfile(&_head,_cidade,1);
                break;
        
        }
    }  */  
    

    if(_idxFiltragem==2)
    {   static int i=0;
        aux = *_head;
        
       
        while(aux->next!=NULL)
        {
            printf("%d\n\n",i++);
            if((aux->payload.dt.ano)  <  _fano || (aux->payload.dt.ano) == _fano && aux->payload.dt.mes<_fmes)
            {  
                if (aux==*_head){
                   
                    aux->next->prev=NULL;
                    *_head=aux->next;
                    
                    free(aux);
                }
                else{
                  
                temp=aux->prev;
                
                aux->next->prev=temp;
               
                temp=aux->next;
              
                aux->prev->next=temp;

                
                                
                  
                free(aux);

                }
                
                
                
            }
            aux=aux->next;
         
        }/* aux encontra- se no ultimo elemento*/

        /*if((aux->payload.dt.ano)  <  _fano || (aux->payload.dt.ano) == _fano && aux->payload.dt.mes<_fmes)
          {  aux->prev->next=NULL;
            free(aux);
          }*/

        
    
    }

    if(_idxFiltragem ==3)
    {

             aux = *_head;
        
       
        while(aux->next!=NULL)
        {
            
            if((aux->payload.dt.mes)  <  (_primeiroMes) || (aux ->payload.dt.mes)  >  (_ultimoMes) )
            {  
                if (aux==*_head){
                    aux->next->prev=NULL;
                    *_head=aux->next;
                    
                    free(aux);
                }
                else{
                temp=aux->prev;
                aux->next->prev=temp;
                temp=aux->next;
                aux->prev->next=temp;
                free(aux);

                }
                
                
                
            }
            aux=aux->next;
            printf("\nfinal while\n");
        }/* aux encontra- se no ultimo elemento*/

        if((aux->payload.dt.mes)  <  (_primeiroMes) || (aux->payload.dt.mes)  >  (_ultimoMes) )
          {  aux->prev->next=NULL;
            free(aux);
          }
    }
}


void temperaturas(node_t **_head,int _periodoAmostragem,char _nomeCidade[], char _nomePais[],int _idxTemperaturas ) /* talvez usar lista */
{
    
    node_t *aux=(node_t*) malloc(sizeof(node_t));
    
    if (_idxTemperaturas==1)
    {

        /* funcao que faz o tabela cm medias etc etc para todos os paises*/
    }
    if (_idxTemperaturas==2)
    {
        aux = *_head;

        if(strcmp(_nomePais ,aux->payload.pais)!=0)
            free(aux);


        /* funcao que faz o tabela ja cm as medias etc etc para um pais especifico mas so e preciso invocar a funcao pq a lista ja foi reduzida para apenas esse pais especifico*/

    }

    if (_idxTemperaturas==3)
    {
        aux = *_head;

        if(strcmp(_nomePais,aux->payload.cidade)!=0)
            free(aux);    
        
        /*funcao que faz os graficos com as medias etc etc para uma cidade especifica*/
        

    }
}

void anoAnalise(node_t **_head, int _anoPretendido, int _nCidades, int _nPaises,int _idxAnoAnalise) /* talvez usar lista newNodeliar e e ficheiro dos paises*/
{
    node_t *aux=(node_t*) malloc(sizeof(node_t));
    aux = *_head;
    if(  (aux->payload.dt.ano) != _anoPretendido)
    {
        
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

void globalAnalise(node_t **_head,int _nMeses)
{
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
        
     
    if(newNode==NULL)
    {
        printf("memory allocation error \n");
        exit(EXIT_FAILURE);
    }
 
   
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
    {  
        switch (choi)
        {   case 1:
               
                putCity(buffer,&start_,choi);
                
                break;
                /* o q e q e suposto fazer?*/
            case 2:
               
                putCity(buffer,&start_,choi);/*Não te preocupes com o nome estar ser putCity, a funçao dá para os dois*/
                 
               
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
    
  if(choi!=0 && **_start != NULL) 
  {   
    auxi->next = **_start;
    
    auxi-> prev = NULL;
    auxi->next->prev=auxi;
    **_start = auxi;
      
      if(**_start ==NULL)
    {
        **_start = auxi;
        auxi->prev = NULL;
        auxi -> next = NULL;
        
    }
  
  }
  else
  {
      **_start=auxi;



  }
   /*if(!**_start)
    **_start=auxi;
    else
    {
        auxi->next=**_start;
        auxi->next->prev=auxi;
        **_start=auxi;


    }  */
 
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
    //static int i=0;
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
    static int i=0;
    if ((i++)==50 ||i==1000 ||i==5000|| i==10000 || i==40000)
        printf("%d\n",i);
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


void printlist(node_t *_start)
{   node_t * temp = (node_t *) malloc(sizeof(node_t));
    temp = _start;
    static int i=0;

    while( (temp->next!=NULL)/*&&(strcmp(temp->payload.pais,"Country")!=0)*/)
    {
        printf("ano--%d  mes--%d\n\n",temp->payload.dt.ano,temp->payload.dt.mes);
        printf("%d\n",i++);
        temp=temp->next;
     
       /* if(temp->next==NULL)
        {
            break;
        }*/
    }  
    
}





void clearList(node_t ** _head)
{
    node_t * aux=NULL;
    node_t * temp=NULL;
    aux=*_head;
    while(aux!=NULL)
    {
        temp=aux->next;
        free(aux);
        aux=temp;
    }
    *_head=NULL;
}

void obterm(node_t *_head,char *_pais,int _periodo)
{   FILE * temps;
    node_t * aux = _head;
    int i=0;
    
    int anoini=aux->payload.dt.ano;
    float contador=0,soma=0,media=0;
    while(aux!=NULL)
    {   //printf("dentro do");
        fflush(stdout);
        //printf("%d\n%d\n\n\n\n\n\n\n",strlen(aux->payload.pais),strlen(_pais));
        if(strcmp(aux->payload.pais,_pais)==0)
        {   
            soma += aux->payload.temperatura;
            contador++;

            if(aux->payload.dt.ano==(anoini+_periodo))
            {   //printf("dentro do\n\n\n\n");
                media=(soma/contador);
                if (i==0){
                    temps=fopen("aaa.txt","w");
                    fprintf(temps,"%s\n\n medias\n entre %d e %d---%.3f\n",_pais,anoini,(anoini+_periodo),media);
                    fclose(temps);
                    i++;
                }
                else 
                {   temps=fopen("aaa.txt","a");
                    fprintf(temps,"entre %d e %d---%.3f\n",anoini,(anoini+_periodo),media);
                    fclose(temps);
                    if(i++==19)
                        break;
                }
                anoini+=_periodo;    

            }
        }
        aux=aux->next;
    
    }
}