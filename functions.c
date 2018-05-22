#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "functions.h"
#include "data.h"
#define SIZE_OF_STRING 100
#define NONTEMP 9999999999
#define NONST "EMPTY"

void switchMenu(void)
{
   
    int idxMenu=1 ;
    char buff[SIZE_OF_STRING];
    char nomeCidade[SIZE_OF_STRING], nomePais[SIZE_OF_STRING];
 
    while(idxMenu==1)
    {
       
        menuPrincipal(&idxMenu);
        switch (idxMenu)
        {
            case 1:
            menuFiltragem();
                   
            break;

            case 2:
            menuTemperaturas( nomePais, nomeCidade);
            break;

            case 3:
            menuAnoAnalise();
            break;

            case 4:
            menuGlobalAnalise(nomePais, nomeCidade);
            break;
        }
    }
}

int menuPrincipal(int *_idxMenu)
{
    char buff[SIZE_OF_STRING];
    printf("Escolha com o correspondente ao menu que pretende aceder:\n");
    printf("1.Filtragem de dados. \n2.Historico de temperaturas. \n3.Analise da temperatura por ano. \n4.Analise da temperatura global.\n");
    do{
        fgets(buff, SIZE_OF_STRING, stdin);
        sscanf(buff, "%d", _idxMenu);
        if (*_idxMenu<1 ||*_idxMenu>4)
        printf(" Escolheu um número nao válido. Por favor introduza um compreendido entre 1 e 4.\n");
          
    }while(*_idxMenu<1 ||*_idxMenu>4);

    return *_idxMenu;
}

void menuFiltragem(void)
{
     int fmes=0, fano=0, primeiroMes=0, ultimoMes=0, idxFiltragem=0;
    
    char buff[SIZE_OF_STRING];
    printf("Escolha com o correspondente o menu que pretende aceder. \n1.Limpar criterios. \n2.Escolhe um mes e um ano. todos os dados anteriores sao removidos. \n3. Escolhe 2 meses. todos os meses fora desse parametro serao removidos.\n");
    do{
      fgets(buff, SIZE_OF_STRING, stdin);
      sscanf(buff, "%d", &idxFiltragem);
      if (idxFiltragem<1 || idxFiltragem>3)
          printf("Escolheu um nao valido. Por favor introduza um compreendido entre 1 e 3.\n");
          
    }while(idxFiltragem<1 || idxFiltragem>3);



    if(idxFiltragem == 1)
    {
             /* funcao que enche a lista outra vez sem criterios*/
    }


    if(idxFiltragem==2)
    {
        char buff[SIZE_OF_STRING];
        printf("\nIrá escolher um para o ano e outro para o mês. Todas as datas anteriores a isso vão ser eliminadas.\n\n\n");
        printf("Agora vai escolher um ano.\n");
        do{
            fgets(buff, SIZE_OF_STRING, stdin);
            sscanf(buff, "%d", &fano);
            if (fano<1950 || fano>2013)
            {

                printf("Escolheu um número não válido. Por favor introduza um número para o ano entre x e y..\n"); /* definir ainda ano minimo e ano maximo*/
            }
        }while(fano<1950 || fano>2013);

        printf("Agora vai escolher um mês. Escolha um número compreendido entre 1 e 12. \n");
        do{
            fgets(buff, SIZE_OF_STRING, stdin);
            sscanf(buff, "%d", &fmes );
            if (fmes<1 || fmes>12 )
            {

                printf("Escolheu um não válido. Por favor introduza um número para o mês entre 1 e 12.\n"); /* definir ainda ano minimo e ano maximo*/
            }
        }while(fmes<1 || fmes>12 );
    }

    if(idxFiltragem == 3)
    {
        
        char buff[SIZE_OF_STRING];
        printf("Escolha agora o intervalo de meses que pretende analisar. Todos os meses que estiverem fora desse intervalo serão eliminados.\n");
        printf("Introduza agora o mês de valor inferior.\n");
        do{
            fgets(buff, SIZE_OF_STRING, stdin);
            sscanf(buff, "%d", &primeiroMes);
            if(primeiroMes <1 || primeiroMes>12)
                printf("Introduza valores validos para o primeiro e último mês.\n");
        }while(primeiroMes <1 || primeiroMes>12 );

        printf("Introduza agora o mês de valor superior\n");
         do{
            fgets(buff, SIZE_OF_STRING, stdin);
            sscanf(buff, "%d", &ultimoMes);
            if(primeiroMes <1 || primeiroMes>12 || ultimoMes<1 || ultimoMes>12 || primeiroMes>ultimoMes)
                printf("Introduza valores validos para o primeiro e último mês.\n");
        }while(primeiroMes <1 || primeiroMes>12 || ultimoMes<1 || ultimoMes>12 || primeiroMes>ultimoMes);

    }
}

void menuTemperaturas( char _nomePais[], char _nomeCidade[] )
{
    int idxTemperaturas, periodoAmostragem;
    char buff[SIZE_OF_STRING];
    printf("Introduzida o periodo de amostragem que pretende. Escolha um valor entre 1 e 100.\n");
    do{
        fgets(buff, SIZE_OF_STRING, stdin);
        sscanf(buff, "%d",&periodoAmostragem);
        if (periodoAmostragem<1 || periodoAmostragem>100)
            printf("Escolheu um número não válido. Por favor introduza um número valido positivo menor que 100.\n");
          
    }while(periodoAmostragem<1 || periodoAmostragem>100);

    printf("Escolha agora o correspondente ao menu que pretende aceder.\n 1. Global: aplica-se a todos os paises. \n2.Por pais:aplica-se a um unico pais. \n3.Por cidade: aplica-se a uma unica cidade.");

    do{
          fgets(buff, SIZE_OF_STRING, stdin);
          sscanf(buff, "%d", &idxTemperaturas);
          if (idxTemperaturas<1 || idxTemperaturas>3)
          printf(" Escolheu um não valido. Por favor introduza um entre 1 e 3.\n");
          
    }while(idxTemperaturas<1 ||idxTemperaturas>3);

    if(idxTemperaturas==2)
    {
        printf("Que pais pretende analisar?\n");
        fgets(buff, SIZE_OF_STRING, stdin);
        sscanf(buff, "%s", _nomePais);    /* preciso fazer com q a funcao diga q foi escolhido pais e nao cidade*/
    }

    if(idxTemperaturas==3)
    {
        printf("Que pais pretende analisar?\n");
        fgets(buff, SIZE_OF_STRING, stdin);
        sscanf(buff, "%s", _nomeCidade);   /* rpeciso fazer com q a funcao diga q foi escolhido cidade e nao pais*/
    }
    
}

void menuAnoAnalise(void)
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

void menuGlobalAnalise(char _nomePais[], char _nomeCidade[])
{  
    char buff[SIZE_OF_STRING];

    int nMeses, idxGlobalAnalise;
    printf("Indique quantas mediçoes pretende para fazer os cálculos. \n");
    do{
        fgets(buff, SIZE_OF_STRING, stdin);
        sscanf(buff, "%d", &nMeses);
        if (nMeses<1 || nMeses>2)
        printf("Escolheu um inválido. Por favor introduza um válido positivo menor que 3.\n");   
    }while(nMeses<1 || nMeses>2);
    printf("Escolha com o número correspondente o menu que pretende aceder.\n");
    printf("1. Aumento da temperatura global do planeta: Calculado como o aumento da temperatura em 1860, 1910, 1960, 1990, 2013. \n  O aumento da temperatura é calculado como a diferença entre o ano com menor temperatura média e o ano com a maior temperatura  média incluindo todos os anos anteriores. \n  Realize a média da temperatura de todos os países presentes nos dados. ");
    printf("2. Aumento da temperatura global de um país: O mesmo que o ponto 1, mas apenas incluindo os dados de um só país\n");
    printf("3. Aumento da temperatura global de uma cidade: O mesmo que o ponto 1, mas apenas inclindo os dados de uma só cidade");
     
    do{
        fgets(buff, SIZE_OF_STRING, stdin);
        sscanf(buff, "%d", &idxGlobalAnalise);
        if (idxGlobalAnalise<1 || idxGlobalAnalise>2)
        printf("Escolheu um inválido. Por favor introduza um número entre 1 e 3.\n");   
    }while(idxGlobalAnalise<1 || idxGlobalAnalise>2);

    if(idxGlobalAnalise==1)
    {
        /* funcao que faz a media a todos os paises*/

    }

    if(idxGlobalAnalise==2)
    {
        printf("iIntroduza o nome do país que pretende analisar.\n");
       /* do{*/
            fgets(buff,SIZE_OF_STRING, stdin);
            sscanf(buff, "%s", _nomePais);
            /* if string n for valida ent qq coia*/
     /*  }while(if string n for valida ent qq coisa ) */

    }

    if(idxGlobalAnalise==3)
    {
        printf("iIntroduza o nome do cidade que pretende analisar.\n");
       /* do{*/
            fgets(buff,SIZE_OF_STRING, stdin);
            sscanf(buff, "%s", _nomeCidade);
            /* if string n for valida ent qq coia*/
     /*  }while(if string n for valida ent qq coisa ) */

    }
}



 
void filtragem(node_t *_filtrar, int _fmes, int _fano, int _primeiroMes, int _ultimoMes, int _idxFiltragem) /* talvez usar lista newNodeliar*/
{ 
    node_t *aux=NULL;
    
    if(_idxFiltragem==1)
    {
            /*voltar a encher lista funcao q faz isso*/
    }
    if(_idxFiltragem==2)
    {
        if(  (_filtrar->payload.dt.ano)  <  _fano)
        {
            aux = _filtrar;
            free(aux);
        }

        if( (_filtrar->payload.dt.ano)  ==_fano && (_filtrar->payload.dt.mes)<_fmes)
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

void temperaturas(node_t *_temperaturas, int idxTemperaturas,int periodoAmostragem,char _nomeCidade[], char _nomePais[] ) /* talvez usar lista */
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

void anoAnalise(node_t *_analise, int _idxAnoAnalise, int _anoPretendido, int _nCidades, int _nPaises) /* talvez usar lista newNodeliar e e ficheiro dos paises*/
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

void globalAnalise(int _nMeses)
{


}
 



node_t *getNewNode(char *data,float Temperatura,float incerto,char *pais,char *city) /* novos valores preciso colocar nas estruturas*/
{
    node_t * newNode = (node_t*) malloc(sizeof(node_t));
    char s[SIZE_OF_STRING]="-";
    if(newNode==NULL)
    {
        printf("memory allocation error \n");
        exit(EXIT_FAILURE);
    }

    newNode->payload.dt.ano=atoi(strtok(data,s));
    newNode->payload.dt.mes=atoi(strtok(NULL,s));
    newNode->payload.dt.dia=atoi(strtok(NULL,s));
    newNode->payload.temperatura=Temperatura;
    newNode->payload.incerteza=incerto;
    strcpy(newNode->payload.pais,pais);
    strcpy(newNode->payload.cidade,city);

    newNode->next = NULL;
    newNode->prev = NULL;

    return newNode;
}

void getfile(node_t ** start_,FILE * file,int choi)
{   char buffer[SIZE_OF_STRING];
    int i=0;
    fgets(buffer,SIZE_OF_STRING,file);  
    while(fgets(buffer,SIZE_OF_STRING,file))
    {   if (i++>10)
        {break;}
        switch (choi)
        {   case 1:
                printf("case1");
                putCity(buffer,&start_);
                break;
                /* o q e q e suposto fazer?*/
            case 2:
                printf("case2");
                putCountry(buffer,&start_);
                break;
        }
    }

}

int putCity(char * _buff,node_t *** _start)  /* se der return a 1, entra na lista, se der return a 0 nao entra na lista */
{   
    char * comma = _buff;
    float Temperatura,incerto;
    char pais[SIZE_OF_STRING]="",city[SIZE_OF_STRING]="";
    char au[SIZE_OF_STRING]="";
    
    char data[SIZE_OF_STRING]="";
    int tam = strcspn(comma,",\n");
    
    
    
    
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
        return 0
    }
    else
    {
        tam = strcspn(comma,",\n");
        strncpy(city,comma,tam);
        comma+=tam+1;
        if(city ==NULL)
    }


    **_start=getNewNode(data,Temperatura,incerto,pais,city);

    return 1;
        
    /*
    tam = strcspn(comma,",\n");
    strncpy(newNode->lat,comma,tam);
    comma+=tam+1;

    tam = strcspn(comma,",\n");
    strncpy(newNode->logi,comma,tam);
    comma+=tam+1;
   */
}

void putCountry(char * _buff,node_t *** _start)
{  
    char * comma = _buff;
    char au[SIZE_OF_STRING]="";
    char data[SIZE_OF_STRING]="";
    float Temperatura,incerto;
    char pais[SIZE_OF_STRING]="",city[SIZE_OF_STRING]="";
    int tam = strcspn(comma,",\n");
  
    
   
    strncpy(data,comma,tam);
    comma+=tam+1;
    

    if ((*comma)==',')
    {
        Temperatura=NONTEMP;
        comma++;    
    }
    else 
    {   tam = strcspn(comma,",\n");
        strncpy(au,comma,tam);
        Temperatura = atof(au);
        comma+=tam+1;
    }
    if ((*comma)==',')
    {   incerto=NONTEMP;
        comma++;
    }
    else
    {
        tam = strcspn(comma,",\n");
        strncpy(au,comma,tam);
        incerto = atof(au);
        comma+=tam+1;
    }
    if ((*comma)==',')
    {   strcpy(pais,NONST);
        comma++;
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
    }
    else
    {
        tam = strcspn(comma,",\n");
        strncpy(city,comma,tam);
        comma+=tam+1;
    }
    **_start=getNewNode(data,Temperatura,incerto,pais,city);
}

int checkChoice(char *chchoi)
{  /* if (strcmp(chchoi,"tempcities.csv")==0)
    {
        return 1;
    }
    else if(strcmp(chchoi,"tempcountries.csv")==0)
    {
        return 2;

    }
    else
    {
        return 0;
    }*/
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



node_t *insertHead(node_t *_head)  /* novos valores e preciso colocalos nas estruturas*/
{
    node_t *newValues=NULL;

   /* newValues=getNewNode();*/   /* colocar argumentos*/

    if(_head ==NULL)
    {
        _head = newValues;
        newValues->prev = NULL;
        newValues -> next = NULL;
        return newValues;
    }
    newValues->next = _head;
    newValues -> prev = NULL;
    _head = newValues;

    return newValues;
}


node_t insertTail(node_t **_head)  
{
    node_t *newValues= NULL;
    node_t *aux= NULL;
    newValues =getNewNode();  /* colocar argumentos*/

    if(*_head == NULL)
    {
        *_head == newValues;
        return;
    }

    aux = *_head;
    while( (aux->next) !=NULL)
    {
        aux=(aux->next);
    }

    (aux->next)=newValues; /* sera q fica na lista o proximo elemento?*/

    return *newValues;

}




