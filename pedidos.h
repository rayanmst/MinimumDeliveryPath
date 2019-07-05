#ifndef PEDIDOS_H_INCLUDED
#define PEDIDOS_H_INCLUDED

#include "../grafos/grafo.h"

typedef struct pedidos pedido_t;

void menu(grafo_t* grafo);
void cabecalho();
void cardapio();
void bairros();
void verPedido(pedido_t* pedido);
void valorTotal(pedido_t* pedido);
void calculaTempo(pedido_t* pedido);
float valorItem(int item);
pedido_t* fazPedido();
void libera_pedidos(lista_enc_t* lista);




#endif // PEDIDOS_H_INCLUDED
