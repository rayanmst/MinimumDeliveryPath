#include <stdio.h>
#include <stdlib.h>
#include "no.h"

struct nos
{
    void* dados;    /*!< Refer�ncia do dado respectiva ao n� da lista encadeada. */
    no_t *proximo;  /*!< Refer�ncia do pr�ximo elemento da lista encadeada. */
};

/**
  * @brief  Cria um novo n� de lista encadeada.
  * @param	dado: ponteiro gen�rico para qualquer tipo de dado.
  *
  * @retval no_t: ponteiro do tipo n� contendo a refer�ncia do dado.
  */
no_t *criar_no(void *dado)
{
    no_t *p = malloc(sizeof(no_t));

    if (p == NULL)
    {
        perror("cria_no:");
        exit(EXIT_FAILURE);
    }

    p->dados = dado;
    p->proximo = NULL;

    return p;
}

/**
  * @brief  Faz o encadeamento entre dois n�s de encadeados.
  * @param	fonte: ponteiro da fonte entre a liga��o.
  *         destino: ponteiro do destino entre a liga��o.
  *
  * @retval Nenhum.
  */
void ligar_nos (no_t *fonte, no_t *destino)
{
    if (fonte == NULL || destino == NULL)
    {
        fprintf(stderr,"liga_nos: ponteiros invalidos");
        exit(EXIT_FAILURE);
    }

    fonte->proximo = destino;
}

/**
  * @brief  Remove encadeamento um n� encadeado.
  * @param	no: n� de lista que se deseja remover liga��o.
  *
  * @retval Nenhum.
  */
void desligar_no (no_t *no)
{
    if (no == NULL)
    {
        fprintf(stderr,"liga_nos: ponteiros invalidos");
        exit(EXIT_FAILURE);
    }

    no->proximo = NULL;
}

/**
  * @brief  Obt�m a refer�ncia do dado pertencente ao n� de lista encadeada.
  * @param	no: n� de lista que se deseja obter o dado.
  *
  * @retval void *: dado referenciado pelo n� encadeado.
  */
void *obter_dado (no_t *no)
{
    if (no == NULL)
    {
        fprintf(stderr,"liga_nos: ponteiros invalidos");
        exit(EXIT_FAILURE);
    }

    return no->dados;
}

/**
  * @brief  Obt�m a pr�xima refer�ncia encadeada.
  * @param	no: n� de lista que se deseja obter o pr�ximo elemento.
  *
  * @retval no_t *: ponteiro do pr�ximo elemento da lista. NULL se final de lista.
  */
no_t *obter_proximo (no_t *no)
{
    if (no == NULL)
    {
        fprintf(stderr,"liga_nos: ponteiros invalidos");
        exit(EXIT_FAILURE);
    }

    return no->proximo;
}
