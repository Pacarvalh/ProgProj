# ProgProj
Projecto final programação

Já recebe e guarda com o nome do ficheiro escolhido




Vai à linha de comandos e faz: 
```
git clone https://github.com/Pacarvalh/ProgProj.git
```  
adicionado

O ficheiro ta funcionar, e a ordenação também
Tem de se utilizar o ficheiro mais pequeno porque o sort demora imenso, agora a demorar 1min

Não percebo o porque de haver duas filtragens(menufiltragem e filtragem) (são os dois menus)

 gcc *.c -g -I/usr/local/include -Wall -pedantic -std=c99 -L/usr/local/lib -lm -lSDL2 -lSDL2_ttf -lSDL2_image -o WarmingUp

 gcc functions.c -g -I/usr/local/include -Wall -pedantic -std=c99 -L/usr/local/lib -lm -lSDL2 -lSDL2_ttf -lSDL2_image -o WarmingUp

gcc functions.c main.c -g -I/usr/local/include -Wall -pedantic -std=c99 -L/usr/local/lib -lm -lSDL2 -lSDL2_ttf -lSDL2_image -o WarmingUp

void Nelementos(node_t *head,int _anoPretendido,int N)
{
    node_t *aux =NULL;
    int max, min, tmax, tmin,i;
    char * maximo;
    char * minimo;
    for(i=0;i<=N;i++)
    {
        while(aux!=NULL)
        {
            if(aux->payload.dt.ano==_anoPretendido)
            {
                if(aux->payload.temperatura>max && aux->payload.temperatura<tmax)
                {
                    max=aux->payload.temperatura;
                    strcpy( maximo, aux->payload.pais);

                }

                if(aux->payload.temperatura<min && aux->payload.temperatura>tmin)
                {
                    min=aux->payload.temperatura;
                    strcpy( maximo, aux->payload.pais);


                }


            }

        }
        tmax=max;
        tmin=min;
        printf("min-->  %d --> %s  max--> %d  pais--> %s",min, minimo,max, maximo);

    }

}
