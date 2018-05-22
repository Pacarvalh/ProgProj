#ifndef DATA_H
#define DATA_H


typedef struct {
    int dia;
    int mes;
    int ano;
} data;

/*typedef struct {
    float angle;
    char cardeais;
} geo_coord;*/

typedef struct {
    data dt;
    float temperatura;
    float incerteza;
    char pais[100];
    char cidade[100];
    char lat[100];
    char longit[100];

} dados_temp;

typedef struct node {
    dados_temp payload;
    struct node *next;
    struct node *prev;
}node_t;

#endif