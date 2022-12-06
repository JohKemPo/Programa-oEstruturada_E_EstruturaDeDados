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
        
        Grafos orientados possuem arestas unidirecionais, também são chamados de DIGRAFOS. 
        Grafos não orientados possuem arestas bidirecionais ( Se exite uma conexão a --> b então também existe uma conexão b --> a ).

        Forma de representar um grafo:

        G = ( V, E )
        V = { 1, 2, 3, 4, 5 }
        E = {(1, 5), (2, 3), (2, 4), (3, 2), (4, 3), (5,2), (5, 4)}

        Representando a direção da aresta ( edge ). Ex.: 2 <--> 3.

        No exemplo de representação de relação em redes sociais, temos que o usuário A segue um usuário B, não é garantido que o contrário seja verdadeiro também.

        Um grafo pode ser VALORADO se possuir valores ( pesos ) associados as arestas e/ou aos vértices.
        
 <!--![image](https://user-images.githubusercontent.com/74382074/206010917-e5d9a5a7-a4ed-4799-b031-85e4cbe8fbce.png)-->
 <image src="https://user-images.githubusercontent.com/74382074/206010917-e5d9a5a7-a4ed-4799-b031-85e4cbe8fbce.png" width=50% alt="EXEMPLO DE GRAFO COM PESOS"></image>

## **Algoritmos**

<br>
