# MinimumDeliveryPath
  Com a ideia de minimizar o tempo de entrega dos restaurantes Juquinha Lanches, desenvolvemos um código que calcula o menor tempo possível.
Para uma situação hipotética considerou-se que um dos restaurantes é localizado em Capoeiras (id = 2) e o outro na Trindade (id = 15).
A entrega contempla uma lista de 16 bairros e o tempo de entrega leva em consideração o tempo de locomoção e o preparo dos pedidos.

#### Participantes
>- Maitê Luisa da Silva
>- Rayan Martins Steinbach

#### Funcionamento do código
>- Pedidos
>> Gera um menu de opções para que o usuário possa realizar seu pedido e visualizar o mesmo. O cálculo do tempo é realizado da seguinte maneira, leva-se em média 10 minutos para preparo de cada item que precise disto, além de ser somado o tempo necessário para deslocamento do restaurante mais próximo até o destino.

>- Grafos
>> Gera o grafo onde se localizam os bairros e os restaurantes. Os vértices dos grafos contém o tempo de deslocamento, o identificador e o predecessor. A aresta contém o peso apenas. O grafo contém um vetor de vértices, a matriz de adjacência e o número de vértices.
>> O algoritmo de busca de caminho é o Bellman-Ford
>> A complexidade do algoritmo é O(|V| * |E|)

>- Lista_enc
>> Foi adicionado para que os pedidos pudessem ser armazenados. A lista encadeada tem uma estrutura com Cabeça, tamanho e Cauda.

>- No
>> Nó é um componente fundamental da lista encadeada. É nele que são armazenados os dados que são salvos na lista e o endereço do próximo nó.

