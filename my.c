#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define NONTEMP 9999999999999
#define NONST "EMPTY"


typedef struct node_
{   char * data;
    float avgtemp;
    float tempu;
    char * pais;
    char * city;
    char * lat;
    char * logi;
    struct node_ * next;
    struct node_ * prev;
}node;
void getfile(node **,FILE *,int);
char * strcom(char *);
void putcity(char *,node ***);
void putcoun(char *,node ***);
int checkchoi(char *);

int main()
{   FILE * fp;
    node * start=NULL;
    char nomef[100];
    int choice;
    printf("Introduza o nome do ficheiro\n----------> ");
    fgets(nomef,sizeof(nomef),stdin);
    nomef[strlen(nomef)-1]='\0';
    /*gets(nomef);*/
   /* printf("%ld, %ld",strlen(nomef),strlen("f"));*/
    choice=checkchoi(nomef);

    printf("choice %d\n",choice);
    fp = fopen(nomef,"r");
    /*printf("fp");*/
    getfile(&start,fp,choice);
    fclose(fp);
    return 0;
}

void getfile(node ** start_,FILE * file,int choi)
{   char buffer[500];
    
    fgets(buffer,500,file);  
     printf("getfile\n"); 
    while(fgets(buffer,500,file))
    {   
        switch (choi)
        {   case 1:
                printf("case1");
                putcity(buffer,&start_);
                break;
            case 2:
                printf("case2");
                putcoun(buffer,&start_);
                break;
        }
    }

}

void putcity(char * _buff,node *** _start)
{   node * auxi = (node*) malloc(sizeof(node));
    char * comma = _buff;
    char au[100]="";
    int tam = strcspn(comma,",\n");
    auxi->data = (char*) malloc(sizeof(9));
    auxi->pais = (char*) malloc(sizeof(50));
    auxi->city = (char*) malloc(sizeof(50));
    auxi->lat = (char*) malloc(sizeof(50));
    auxi->logi = (char*) malloc(sizeof(50));
    
    
    strncpy(auxi->data,comma,tam);
    comma+=tam+1;
    
    if ((*comma)==',')
    {
        auxi->avgtemp=NONTEMP;
        comma++;    
    }
    else 
    {   tam = strcspn(comma,",\n");
        strncpy(au,comma,tam);
        auxi->avgtemp = atof(au);
        comma+=tam+1;
    }
    if ((*comma)==',')
    {   auxi->tempu=NONTEMP;
        comma++;
    }
    else
    {
        tam = strcspn(comma,",\n");
        strncpy(au,comma,tam);
        auxi->tempu = atof(au);
        comma+=tam+1;
    }
    if ((*comma)==',')
    {   strcpy(auxi->pais,NONST);
        comma++;
    }
    else 
    {   
        tam = strcspn(comma,",\n");
        strncpy(auxi->pais,comma,tam);
        comma+=tam+1;
    }
    if ((*comma)==',')
    {   strcpy(auxi->city,NONST);
        comma++;
    }
    else
    {
        tam = strcspn(comma,",\n");
        strncpy(auxi->city,comma,tam);
        comma+=tam+1;
    }
        
    tam = strcspn(comma,",\n");
    strncpy(auxi->lat,comma,tam);
    comma+=tam+1;

    tam = strcspn(comma,",\n");
    strncpy(auxi->logi,comma,tam);
    comma+=tam+1;
   /* printf("----%s\n\n",auxi->data);
    
    
    printf("%.3f\n",auxi->avgtemp);
    printf("%.3f\n",auxi->tempu);
    
    printf("%s\n",auxi->pais);
    printf("%s\n",auxi->city);
    printf("%s\n",auxi->lat);
    printf("%s\n\n\n\n",auxi->logi);
    printf("-------------------\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");*/
    **_start=auxi;
}

void putcoun(char * _buff,node *** _start)
{   node * auxi = (node*) malloc(sizeof(node));
    char * comma = _buff;
    char au[100]="";
    int tam = strcspn(comma,",\n");
    auxi->data = (char*) malloc(sizeof(9));
    auxi->pais = (char*) malloc(sizeof(50));
    auxi->city = (char*) malloc(sizeof(50));
    auxi->lat = (char*) malloc(sizeof(50));
    auxi->logi = (char*) malloc(sizeof(50));
    
    strncpy(auxi->data,comma,tam);
    comma+=tam+1;
    
    if ((*comma)==',')
    {
        auxi->avgtemp=NONTEMP;
        comma++;    
    }
    else 
    {   tam = strcspn(comma,",\n");
        strncpy(au,comma,tam);
        auxi->avgtemp = atof(au);
        comma+=tam+1;
    }
    if ((*comma)==',')
    {   auxi->tempu=NONTEMP;
        comma++;
    }
    else
    {
        tam = strcspn(comma,",\n");
        strncpy(au,comma,tam);
        auxi->tempu = atof(au);
        comma+=tam+1;
    }
    if ((*comma)==',')
    {   strcpy(auxi->pais,NONST);
        comma++;
    }
    else 
    {   
        tam = strcspn(comma,",\n");
        strncpy(auxi->pais,comma,tam);
        /*comma+=tam+1;*/
    }
    /*printf("----%s\n\n",auxi->data);
    
    
    printf("%.3f\n",auxi->avgtemp);
    printf("%.3f\n",auxi->tempu);
    
    printf("%s\n",auxi->pais);
    
    printf("-------------------\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");*/
  
        

    
    **_start=auxi;

}

int checkchoi(char *chchoi)
{   if (strcmp(chchoi,"tempcities.csv")==0)
    {return 1;
    }
    else if(strcmp(chchoi,"tempcountries.csv")==0)
    {return 2;

    }
    else
    {return 0;

    }
}