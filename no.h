#ifndef NO_H_INCLUDED
#define NO_H_INCLUDED

typedef struct nos no_t;

/**
  * @brief  Cria um novo n� de lista encadeada.
  * @param	dado: ponteiro gen�rico para qualquer tipo de dado.
  *
  * @retval no_t: ponteiro do tipo n� contendo a refer�ncia do dado.
  */
no_t *criar_no(void *dado);


/**
  * @brief  Faz o encadeamento entre dois n�s de encadeados.
  * @param	fonte: ponteiro da fonte entre a liga��o.
  *         destino: ponteiro do destino entre a liga��o.
  *
  * @retval Nenhum.
  */
void ligar_nos (no_t *fonte, no_t *destino);


/**
  * @brief  Remove encadeamento um n� encadeado.
  * @param	no: n� de lista que se deseja remover liga��o.
  *
  * @retval Nenhum.
  */
void desligar_no (no_t *no);

/**
  * @brief  Obt�m a refer�ncia do dado pertencente ao n� de lista encadeada.
  * @param	no: n� de lista que se deseja obter o dado.
  *
  * @retval void *: dado referenciado pelo n� encadeado.
  */
no_t *obter_proximo (no_t *no);

/**
  * @brief  Obt�m a pr�xima refer�ncia encadeada.
  * @param	no: n� de lista que se deseja obter o pr�ximo elemento.
  *
  * @retval no_t *: onteiro do pr�ximo elemento da lista. NULL se final de lista.
  */
void *obter_dado (no_t *no);


#endif // NO_H_INCLUDED

