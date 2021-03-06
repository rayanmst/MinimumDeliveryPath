/*
 * grafo.h
 *
 *  Created on: Nov 18, 2016
 *      Author: Renan Augusto Starke
 */

#ifndef GRAFO_H_
#define GRAFO_H_

#define TRUE 1
#define FALSE 0

typedef struct vertices vertice_t;
typedef struct arestas aresta_t;
typedef struct grafos grafo_t;

grafo_t *cria_grafo(int vertices);
void libera_grafo (grafo_t *g);
int cria_adjacencia(grafo_t *g, int u, int v, int d);
int rem_adjacencia(grafo_t *g, int u, int v);
int adjacente(grafo_t *g, int u, int v);
void exportar_grafo_dot(const char *filename, grafo_t *grafo);
void bellman_ford (grafo_t *grafo, int fonte);
void imprimir_caminho(grafo_t *grafo, int fonte, int destino);
int obter_distancia(grafo_t *g, int u);
int obter_peso(grafo_t *g, int u, int v);
void imprime_dados_vertice(grafo_t *g);

#endif /* GRAFO_H_ */
