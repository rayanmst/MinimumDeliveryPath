/*
 * grafo.c
 *
 *  Created on: Nov 18, 2016
 *      Author: Renan Augusto Starke
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <limits.h>

#include "grafo.h"

#define INFINITO (INT_MAX - 300)
#define MAX_VERTICES 20

struct vertices
{
    int id;         /*!< Identificação numérica do vértice  */
    int dist;
    int predecessor;
    };

struct arestas
{
    int adj;        /*!< Valor booleando. Verdadeiro representa uma adjacência entre dois vértices  */

    /* Mais informações, se necessário */
    int peso;
};

struct grafos
{
    int n_vertices;        /*!< Número de vértices do grafo  */
    vertice_t *vertices;   /*!< Vetor de ponteiros: conjunto V */
    aresta_t **matriz_adj;	/* Matriz de adjacência: conjunto E */
};

/**
  * @brief  Cria uma novo grafo estático
  * @param	vertices: quantidade de vértices
  *
  * @retval grafo_t: ponteiro para um novo grafo
  */
grafo_t *cria_grafo(int vertices)
{
    int i;
    aresta_t **matriz_adj;
    /* Aloca estrutura do grafo */
    grafo_t *g = malloc(sizeof(grafo_t));

    if (g == NULL)
    {
        perror("cria_grafo (g)");
        exit(EXIT_FAILURE);
    }

    /* Guarda número total de vértices */
    g->n_vertices = vertices;
    /* Aloca vértices */
    g->vertices = malloc(vertices * sizeof(vertice_t));

    if (g->vertices == NULL)
    {
        perror("cria_grafo (vertices)");
        exit(EXIT_FAILURE);
    }

    /* Zera vetor de vértices */
    memset(g->vertices, 0, vertices * sizeof(vertice_t));

    /* Aloca 1a dimensão da matriz de adjacência */
    matriz_adj = malloc(vertices * sizeof(aresta_t *));

    if (matriz_adj == NULL)
    {
        perror("cria_grafo (matriz_adj)");
        exit(EXIT_FAILURE);
    }

    /* Aloca 2a dimensão da matriz de adjacência */
    for ( i = 0; i < vertices; i++ )
    {
        matriz_adj[i] = calloc(vertices, sizeof(aresta_t)); //atribui zero quando cria

        if (matriz_adj[i] == NULL)
        {
            perror("cria_grafo (matriz_adj[i])");
            exit(EXIT_FAILURE);
        }
    }

    g->matriz_adj = matriz_adj;

    return g;
}

/**
  * @brief  Libera a memória utilizada pelo grafo
  * @param	Nenhum
  *
  * @retval Nenhum
  */
void libera_grafo (grafo_t *g)
{
    int i;

    if (g == NULL)
    {
        perror("libera_grafo");
        exit(EXIT_FAILURE);
    }

    for (i=0; i < g->n_vertices; i++)
        free(g->matriz_adj[i]);

    free(g->matriz_adj);
    free(g->vertices);
    free(g);
}

/**
  * @brief  Cria adjacência entre vértices u e v
  * @param	u: índice do vértice u
  * @param  v: índice do vértice v
  *
  * @retval int: verdadeiro se adjacência for criada
  */
int cria_adjacencia(grafo_t *g, int u, int v, int d)
{

    if (g == NULL)
    {
        return 0;
    }

    if (u > g->n_vertices || v > g->n_vertices )
        return 0;

    g->matriz_adj[u][v].adj = 1;
    g->matriz_adj[u][v].peso = d;
    g->matriz_adj[v][u].adj = 1;
    g->matriz_adj[v][u].peso = d;

    return 1;
}

/**
  * @brief  Remove adjacência entre vértices u e v
  * @param	u: índice do vértice u
  * @param  v: índice do vértice v
  *
  * @retval int: verdadeiro se adjacência for removida
  */
int rem_adjacencia(grafo_t *g, int u, int v)
{

    if (g == NULL)
    {
        return FALSE;
    }

    if (u > g->n_vertices || v > g->n_vertices)
        return FALSE;

    g->matriz_adj[u][v].adj = FALSE;

    return TRUE;
}

/**
  * @brief  Retorna adjacência entre vértices u e v
  * @param	u: índice do vértice u
  * @param  v: índice do vértice v
  *
  * @retval int: verdadeiro se u for adjacente a v
  */
int adjacente(grafo_t *g, int u, int v)
{

    if (u > MAX_VERTICES || v > MAX_VERTICES)
        return FALSE;

    return ((g->matriz_adj[u][v].adj));
}

/**
  * @brief  Implementação de Bellman-Ford para um grafo representado por matriz de adjacência
  * @param	grafo: um grafo
  * @param  fonte: vértice fonte utilizando em Bellman-Ford
  *
  * @retval Nenhum. Predecessor e distância são adicionados em cada vértice
  */

void bellman_ford (grafo_t *grafo, int fonte)
{
    if (grafo == NULL)
    {
        fprintf(stderr, "bellman_ford: grafo invalido\n");
        exit(EXIT_FAILURE);
    }

    int i;
    int z;
    int j;
    vertice_t* w;
    vertice_t* vertice = &(grafo->vertices[fonte]);
    vertice_t* v;
    int nova_dist;

    for(i = 0; i< grafo->n_vertices; i++)
    {
        v = &(grafo->vertices[i]);
        v->id = i;
        v->dist = INFINITO;
        v->predecessor=-1;
    }

    vertice->dist=0;

    for(i = 0; i< (grafo->n_vertices) -1; i++)
    {
        for(z=0; z< grafo->n_vertices; z++)
        {
            for(j=0; j < grafo->n_vertices; j++)
            {
                v = &(grafo->vertices[z]);
                w = &(grafo->vertices[j]);
                if(grafo->matriz_adj[z][j].adj)
                {
                    nova_dist = w->dist + obter_peso(grafo,z,j);

                    if( v->dist > nova_dist )
                    {
                        v->dist = nova_dist;
                        v->predecessor = j;
                    }
                }
            }
        }
    }
}

/**
  * @brief  Imprime o caminho de menor distância. Execute Bellman-Ford previamente.
  * @param	grafo: um grafo
  * @param  fonte: vértice fonte utilizando em Bellman-Ford
  * @param  destino: vértice destino. Deve haver pelo menos um caminho entre fonte e destino
  *
  * @retval Nenhum
  */
void imprimir_caminho(grafo_t *grafo, int fonte, int destino){

    if (grafo == NULL)
    {
        fprintf(stderr, "imprimir_caminho: grafo invalido\n");
        exit(EXIT_FAILURE);
    }
   int pre;
   bellman_ford (grafo, fonte);
   vertice_t* vertice = &grafo->vertices[destino];
   printf("\ncaminho entre %d e %d\n", fonte, destino);
   printf("%d\n", vertice->id);

   while (vertice->predecessor != -1)
    {
        pre = vertice->predecessor;
        vertice = &(grafo->vertices[pre]);
        printf("%d\n", vertice->id);
    }

}

void imprime_dados_vertice(grafo_t *g){
    int i;

    for (i=0; i < g->n_vertices; i++){
		printf("g->vertices[%d].distancia = %d  |  pred: %d \n", i, g->vertices[i].dist,g->vertices[i].predecessor);
	}
}


void exportar_grafo_dot(const char *filename, grafo_t *grafo)
{

    FILE* fp = fopen (filename, "w");
    if (fp == NULL)
    {
        printf ("Erro ao abrir o arquivo.\n");
        exit(1);
    }

    fprintf(fp, "graph G {\n");
    int i, j;
    for (i=0; i < grafo->n_vertices; i++)
    {
        for (j=0; j < grafo->n_vertices && j<=i; j++)
        {
            if (adjacente(grafo,i,j))
            {
                fprintf(fp, "%d -- %d\n", j, i);
            }
        }
    }
    fprintf(fp, "}");
    fclose (fp);
}


int obter_peso(grafo_t *g, int u, int v){

	if (u > g->n_vertices || v > g->n_vertices )
		return -1;

	return g->matriz_adj[v][u].peso;
}

int obter_distancia(grafo_t *g, int u){

	if (u > g->n_vertices)
		return -1;

	return g->vertices[u].dist;
}
