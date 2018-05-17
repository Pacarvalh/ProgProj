#ifndef DATA_H
#define DATA_H


typedef struct {
    int dia;
    int mes;
    int ano;
} data;

typedef struct {
    float angle;
    int hemisferio;
} geo_coord;

typedef struct {
    data dt;
    float temperatura;
    float incerteza;
    char pais[100];
    char cidade[100];
    geo_coord lat;
    geo_coord longit;

} dados_temp;

typedef struct node {
    dados_temp payload;
    struct node *next;
    struct node *prev;
}node_t;

#endif