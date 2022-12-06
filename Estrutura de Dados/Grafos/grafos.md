<br>

# **GRAFOS**

<br>



## **Definição**

<br>

Estrutura de dados que é formado por um conjunto de vértices e um conjunto de arestas.

As relações de uma redes sociais pode ser representada por um grafo, onde Os vértices são os usuários e as arestas são a relação de seguir/amizade.

Um grafo G é representado por um conjunto, não vazio, V de vértices e um conjunto de arestas, possivelmente vazio, E ( edges ).

    G = ( V, E )    

Arestas podem ser unidirecionais ou bidirecionais. 

***Grafos orientados*** possuem arestas unidirecionais, também são chamados de DIGRAFOS. 
***Grafos não orientados*** possuem arestas bidirecionais ( Se exite uma conexão a --> b então também existe uma conexão b --> a ).

Forma de representar um grafo:

    G = ( V, E )
    V = { 1, 2, 3, 4, 5 }
    E = {(1, 5), (2, 3), (2, 4), (3, 2), (4, 3), (5,2), (5, 4)}

Representando a direção da aresta ( edge ). Ex.: 2 <--> 3.

No exemplo de representação de relação em redes sociais, temos que o usuário A segue um usuário B, não é garantido que o contrário seja verdadeiro também.

Um grafo pode ser VALORADO se possuir valores ( pesos ) associados as arestas e/ou aos vértices.
<br>
<br>

        
 <!--![image](https://user-images.githubusercontent.com/74382074/206010917-e5d9a5a7-a4ed-4799-b031-85e4cbe8fbce.png)-->
### *EXEMPLO DE GRAFO VALORADO*
 <image src="https://user-images.githubusercontent.com/74382074/206010917-e5d9a5a7-a4ed-4799-b031-85e4cbe8fbce.png" width=50% alt="EXEMPLO DE GRAFO COM PESOS"></image>
 <br>


### **DEFINIÇÕES E TERMINOLOGIAS**

<br>

Um vértice V1 é adjacente a um V2 em G, se exite uma aresta conectando V1 a V2 em G.

<br>

- Em grafo não orientado: V1 é adjacente a V2 se existe { V1, V2 }, nesse caso V2 também é adjacente a V1. 
- Em grafos orientados: V1 é adjacente a V2 se existe aresta ( V1, V2 ).
- Já para as arestas, em um grafo orientado uma aresta ( V1, V2 ) e incidente de  "sai de" V1 e é incidente "entra em" V2.
- Em grafos não orientados, uma aresta { V1, V2 } é incidente em V1 e V2.
- Grau de um vértice é o número de aresta desse vértice de um grafo, a quantos outros vértices ele está ligado.
- Vértices de grau 0 são ditos vértices isolados.
- A ordem de um grafo é o número de vértices do grafo.



<br>
<!--![image](https://user-images.githubusercontent.com/74382074/206012260-23551925-12eb-4e2a-8262-04af6cb927bb.png)-->
<image src="https://user-images.githubusercontent.com/74382074/206012260-23551925-12eb-4e2a-8262-04af6cb927bb.png" width=80%></image><br>
<image src="https://user-images.githubusercontent.com/74382074/206016566-1da2c4c4-d400-4e79-98b9-2fbdb86f9824.png" width=80%></image><br>


 <br><br>



 <br><br>



## **Algoritmos**

<br>
