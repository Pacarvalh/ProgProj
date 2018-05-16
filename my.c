#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define NONTEMP 9999999999999


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
void getfile(node **,FILE *);
char * strcom(char *);
void putcity(char *,node ***);
int main()
{   FILE * fp;
    node * start=NULL;
     printf("add\n");
    fp = fopen("tempcities.csv","r");
    printf("a\n");
    getfile(&start,fp);
    printf("saiu");
    fclose(fp);
    return 0;
}

void getfile(node ** start_,FILE * file)
{   char buffer[500];
    int i;
    fgets(buffer,500,file);  
     printf("getfile\n");
    while(fgets(buffer,500,file))
    {   if (i++>55) 
        {
            break;
        }
        putcity(buffer,&start_);
    }

}

/*int parse(char * buff)
{   int ind[20],j=0,i;
    char * find;
    for (i=0;i<=strlen(buff);i++)
    {   if (buff[i]==',')
        {   ind[j++]=i;
        }
    }
    return ind;
}
*/

char * strcom(char * aux)
{   static char * temp = NULL;
    char * ch , * tok=0;
    /*
    if (aux!=NULL)
    {   temp = aux;

    }
    if (aux == NULL)
    {   return NULL;

    }
    if ((ch=strpbrk(temp,","))!=NULL)
    {   *ch = 0;
        tok = temp;
        temp = ++ch;
    }
    else if (*temp)
    {   tok = temp;
        temp = NULL;

    }*/
    return tok;


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
    printf("meio\n");
    strncpy(auxi->data,comma,tam);
    comma+=tam+1;
    if ((*comma)==',')
    {
        auxi->avgtemp=NONTEMP;
        comma++;

        
    }
    else 
    {
        
        tam = strcspn(comma,",\n");
        strncpy(au,comma,tam);
        auxi->avgtemp = atof(au);
        comma+=tam+1;
    }
    
    
    if ((*comma)==',')
    {   auxi->tempu=NONTEMP;
        printf("merda");
    }
    else
    {
        tam = strcspn(comma,",\n");
        strncpy(au,comma,tam);
        auxi->tempu = atof(au);
    }

    comma+=tam+1;
    tam = strcspn(comma,",\n");
    strncpy(auxi->pais,comma,tam);

    comma+=tam+1;
    tam = strcspn(comma,",\n");
    strncpy(auxi->city,comma,tam);

    comma+=tam+1;
    tam = strcspn(comma,",\n");
    strncpy(auxi->lat,comma,tam);

    comma+=tam+1;
    tam = strcspn(comma,",\n");
    strncpy(auxi->logi,comma,tam);
   


    
    
    /*strcpy(auxi->data,strcom(_buff));
    auxi->avgtemp = atof(strcom(NULL));
    auxi->tempu = atof(strcom(NULL));
    strcpy(auxi->pais,strcom(NULL));
    strcpy(auxi->city,strcom(NULL));
    strcpy(auxi->lat,strcom(NULL));
    strcpy(auxi->logi,strcom(NULL));
    auxi->next=**_start;
    */
    printf("----%s\n\n",auxi->data);
    /*printf("----%s\n\n",au);*/
    
    printf("%.3f\n",auxi->avgtemp);
    printf("%.3f\n",auxi->tempu);
    
    printf("%s\n",auxi->pais);
    printf("%s\n",auxi->city);
    printf("%s\n",auxi->lat);
    printf("%s\n\n\n\n",auxi->logi);
    printf("-------------------\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
    **_start=auxi;




}