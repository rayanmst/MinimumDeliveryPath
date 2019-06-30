#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#include "pedidos.h"
#include "../grafos/grafo.h"

struct pedidos {
    char* cliente;
    int* itens;
    int bairro;
    int numeroItens;
    float valor;
    int tempoEntrega;

};

void menu(grafo_t* grafo) {
    int choice;
    pedido_t* pedido = malloc(sizeof(pedido_t));
    setlocale(LC_CTYPE, "portuguese");
    pedido->valor = -1;
    while(1) {
            system("cls");
            fflush(stdin);
            cabecalho();
            puts("01 - Mostrar cardápio ");
            puts("02 - Realizar pedido  ");
            puts("03 - Visualizar pedido");
            puts("04 - Finalizar pedido ");

            scanf("%d", &choice);
            switch(choice) {
            case 1: // cardápio
                system("cls");
                fflush(stdin);
                cabecalho();
                cardapio();
                puts("Pressione enter para retornar ao menu");
                getchar();
                continue;

            case 2: // fazer pedido
                system("cls");
                fflush(stdin);
                cabecalho();
                pedido = fazPedido(grafo);
                puts("Pressione enter para retornar ao menu");
                fflush(stdin);
                getchar();
                continue;

            case 3: // ver pedido
                system("cls");
                fflush(stdin);
                if(pedido-> valor != -1 ) verPedido(pedido);
                else puts("Faça um pedido primeiro!");
                getchar();
                continue;

            case 4: // fim
                free(pedido);
                break;
            default:
            fflush(stdin);
            puts("Insira apenas itens do menu!");
            puts("Pressione enter para tentar novamente.");
            getchar();
            system("cls");
            continue;
            }
        break;
    }
}

void cabecalho() {
    puts("*********************************************");
    puts("*              Juquinha Lanches             *");
    puts("*********************************************");
}

void cardapio() {
    puts("-------------------Lanches-------------------");
    puts("<01> - Cachorro Quente Tradicional  - R$10.00");
    puts("<02> - Cachorro Quente Prensado     - R$11.00");
    puts("<03> - X-Salada                     - R$12.00");
    puts("<04> - X-Calabresa                  - R$15.00");
    puts("<05> - X-Bacon                      - R$16.00");
    puts("<06> - X-Burger                     - R$10.00");
    puts("<07> - X-Galinha                    - R$13.00");
    puts("<08> - X-Egg                        - R$13.00");
    puts("<09> - X-Juquinha                   - R$20.00");
    puts("-------------------Bebidas-------------------");
    puts("<10> - Refrigerante lata            - R$ 3.50");
    puts("<11> - Refrigerante 600ml           - R$ 5.00");
    puts("<12> - Refrigerante 1 litro         - R$ 7.50");
    puts("<13> - Refrigerante 2 litros        - R$10.00");
    puts("<14> - Suco lata                    - R$ 3.50");
    puts("<15> - Cerveja 600ml                - R$10.00");
    puts("-----------Taxa de entrega: R$ 3.50----------");
}

void bairros() {
    setlocale(LC_CTYPE, "portuguese");
    puts("        Bairros       ");
    puts("<00> - Agronômica     ");
    puts("<01> - Campinas       ");
    puts("<02> - Capoeiras      ");
    puts("<03> - Carvoeira      ");
    puts("<04> - Centro         ");
    puts("<05> - Córrego Grande ");
    puts("<06> - Coqueiros      ");
    puts("<07> - Estreito       ");
    puts("<08> - Itacorubi      ");
    puts("<09> - João Paulo     ");
    puts("<10> - Kobrasol       ");
    puts("<11> - Monte Verde    ");
    puts("<12> - Pantanal       ");
    puts("<13> - Saco dos Limões");
    puts("<14> - Saco Grande    ");
    puts("<15> - Trindade       ");
}

pedido_t* fazPedido(grafo_t* grafo) {
    int  i, tempoMin;
    int* itens;

    pedido_t* pedido = malloc(sizeof(pedido_t));
    pedido->cliente = malloc(sizeof(char*));
    setlocale(LC_CTYPE, "portuguese");
    system("cls");
    cabecalho();
    printf("Insira seu nome: ");
    fflush(stdin);
    gets(pedido->cliente);
    printf("Quantos itens serão pedidos?");
    scanf("%d", &pedido->numeroItens);
    itens = malloc(sizeof(int) * (pedido->numeroItens));
    cardapio();
    for(i = 0; i< pedido->numeroItens; i++) {
        printf("Insira o número do item desejado de acordo com o cardápio:");
        scanf("%d", &itens[i]);
    }
    pedido->itens = itens;
    valorTotal(pedido);

    bairros();
    while(1) {
        printf("Digite o número do seu bairro: ");
        scanf("%d", &(pedido->bairro));
        if(pedido->bairro > 0 || pedido->bairro < 15) break;
        else continue;
    }
    if(pedido->bairro != 2 && pedido->bairro !=15) {
        bellman_ford(grafo, 15);
        tempoMin = obter_distancia(grafo, pedido->bairro);
        bellman_ford(grafo, 2);
        if(tempoMin > obter_distancia(grafo, pedido->bairro)) {
            tempoMin = obter_distancia(grafo, pedido->bairro);
        }
        pedido->tempoEntrega = tempoMin;
    }
    else {
        pedido->tempoEntrega = 3;
    }

    calculaTempo(pedido);

    verPedido(pedido);

    return pedido;
}

void verPedido(pedido_t* pedido) {
    setlocale(LC_CTYPE, "portuguese");
    puts(" Pedido ");
    printf("Cliente: %s\n", pedido->cliente);
    printf("Número de Itens: %d\n", pedido->numeroItens);
    printf("Valor Total: R$%.2f\n", pedido->valor);
    printf("Tempo de Espera: %d minutos\n", pedido->tempoEntrega);

}

void valorTotal(pedido_t* pedido) {
    int i;
    pedido->valor = 3.50;
    for(i = 0; i < pedido->numeroItens; i++) {
        pedido->valor += valorItem(pedido->itens[i]);
    }
}

void calculaTempo(pedido_t* pedido) {
    int i;
    for(i = 0; i < pedido->numeroItens; i++) {
        if(pedido->itens[i] < 10) {
            pedido->tempoEntrega += 10;
        }
    }
}

float valorItem(int item) {

    switch(item) {
        case 1:
            return 10.00;
        case 2:
            return 11.00;
        case 3:
            return 12.00;
        case 4:
            return 15.00;
        case 5:
            return 16.00;
        case 6:
            return 10.00;
        case 7:
        case 8:
            return 13.00;
        case 9:
            return 20.00;
        case 10:
            return 3.50;
        case 11:
            return 5.00;
        case 12:
            return 7.50;
        case 13:
            return 10.00;
        case 14:
            return 3.50;
        case 15:
            return 10.00;
    }
    return 0.00;
}
