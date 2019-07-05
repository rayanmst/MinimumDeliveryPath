#include <stdio.h>
#include <stdlib.h>
#include "lista_enc.h"
#include "no.h"
//#define DEBUG

struct listas_enc
{
    no_t *cabeca;   /*!< Refer�ncia da cabe�a da lista encadeada: primeiro elemento. */
    no_t *cauda;    /*!< Refer�ncia da cauda da lista encadeada: �ltimo elemento. */
    int tamanho;    /*!< Tamanho atual da lista. */
};

/**
  * @brief  Cria uma nova lista encadeada vazia.
  * @param	Nenhum
  *
  * @retval lista_enc_t *: ponteiro (refer�ncia) da nova lista encadeada.
  */
lista_enc_t *criar_lista_enc (void)
{
    lista_enc_t *p = malloc(sizeof(lista_enc_t));

    if (p == NULL)
    {
        perror("cria_lista_enc:");
        exit(EXIT_FAILURE);
    }

    p->cabeca = NULL;
    p->cauda = NULL;
    p->tamanho = 0;

    return p;
}


/**
  * @brief  Obt�m a refer�ncia do in�cio (cabe�a) da lista encadeada.
  * @param	lista: lista que se deseja obter o in�cio.
  *
  * @retval no_t *: n� inicial (cabe�a) da lista.
  */
no_t *obter_cabeca(lista_enc_t *lista)
{
    return lista->cabeca;
}

/**
  * @brief  Adiciona um n� de lista no final.
  * @param	lista: lista encadeada que se deseja adicionar.
  * @param  elemento: n� que ser� adicionado na cauda.
  *
  * @retval Nenhum
  */
void add_cauda(lista_enc_t *lista, no_t* elemento)
{
    if (lista == NULL || elemento == NULL)
    {
        fprintf(stderr,"add_cauda: ponteiros invalidos");
        exit(EXIT_FAILURE);
    }

#ifdef DEBUG
    printf("Adicionando %p --- tamanho: %d\n", elemento, lista->tamanho);
#endif // DEBUG

    //lista vazia
    if (lista->tamanho == 0)
    {
#ifdef DEBUG
        printf("add_cauda: add primeiro elemento: %p\n", elemento);
#endif // DEBUG

        lista->cauda = elemento;
        lista->cabeca = elemento;
        lista->tamanho++;

        desligar_no(elemento);
    }
    else
    {
        // Remove qualquer ligacao antiga
        desligar_no(elemento);
        // Liga cauda da lista com novo elemento
        ligar_nos(lista->cauda, elemento);

        lista->cauda = elemento;
        lista->tamanho++;
    }
}

int tamanho_lista(lista_enc_t* lista)
{
    int tam = lista->tamanho;
    return tam;
}

/**
  * @brief  libera os n�s e a lista encadeada
  * @param  lista: lista que se deseja liberar.
  *
  * @retval Nenhum.
  */
void libera_lista(lista_enc_t* lista)
{
    no_t* no_ant;
    no_t* no = obter_cabeca(lista);
    while(no)
    {
        no_ant = no;
        no = obter_proximo(no);
        free(no_ant);
    }
    free(lista);
   
}

/**
  * @brief  Informa se tem elementos na lista.
  * @param	lista: lista encadeada que deseja saber se está vazia.
  *
  * @retval inteiro, 1 para lista vazia.
  */

int lista_vazia(lista_enc_t* lista){
    if(lista->tamanho == 0)
        return 1;
        else return 0;
}


