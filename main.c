#include <stdio.h>
#include <stdlib.h>

#include "grafo.h"
#include "pedidos.h"

int main()
{
	grafo_t *g;

	g = cria_grafo(16);

	  cria_adjacencia(g, 1, 2, 6);
		cria_adjacencia(g, 2, 6, 5);
		cria_adjacencia(g, 2, 7, 6);
		cria_adjacencia(g, 7, 6, 8);
		cria_adjacencia(g, 0, 4, 10);
		cria_adjacencia(g, 15, 4, 13);
		cria_adjacencia(g, 15, 0, 10);
		cria_adjacencia(g, 15, 3, 4);
		cria_adjacencia(g, 5, 0, 12);
		cria_adjacencia(g, 13, 3, 4);
		cria_adjacencia(g, 15, 13, 5);
		cria_adjacencia(g, 12, 13, 8);
		cria_adjacencia(g, 12, 15, 10);
		cria_adjacencia(g, 12, 5, 12);
		cria_adjacencia(g, 15, 5, 9);
		cria_adjacencia(g, 5, 8, 6);
		cria_adjacencia(g, 9, 12, 12);
		cria_adjacencia(g, 15, 8, 10);
		cria_adjacencia(g, 9, 15, 13);
		cria_adjacencia(g, 9, 11, 6);
		cria_adjacencia(g, 9, 14, 8);
		cria_adjacencia(g, 14, 11, 6);
		cria_adjacencia(g, 15, 11, 12);
		cria_adjacencia(g, 15, 14, 16);
		cria_adjacencia(g, 1, 10, 4);
		cria_adjacencia(g, 10, 2, 8);
		cria_adjacencia(g, 4, 7, 11);

    menu(g);
    libera_grafo(g);

    return 0;

}
