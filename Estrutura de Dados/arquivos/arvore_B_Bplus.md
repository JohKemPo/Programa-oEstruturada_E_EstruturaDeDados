# **ARVORE B e B+**
<br>
<br>

## **CARACTERÍSTICAS**

<br>

- Cada nó tem N - 1 chaves. 
- Cada nó contem N filhos.
- As chaves do nó estão ordenadas.
- As chaves são separadores para ponteiros para os filhos do nó.

<br>

### *EXEMPLO*


<!--![image](https://user-images.githubusercontent.com/74382074/205516362-275e4d2b-c9c3-4058-855a-35c327c3e8a3.png)-->
<image src="https://user-images.githubusercontent.com/74382074/205516362-275e4d2b-c9c3-4058-855a-35c327c3e8a3.png" width=80% ></image>



<br>

- Ordem D
- A raiz é uma folha com ao menos 2 filhos.
- Cada nó, nao folha  e nem raiz, tem no mínimo D + 1 filhos.
- Cada nó tem no max 2d + 1 filhos.
- Todas as folhas, apontando para null, estao no mesmo nível.
- Seja M o número de chaves em uma página P, temos P com M + 1 filhos, P tem entre D e 2D chaves.
- P contém m+1 ponteiros para filhos.


<br>

### *EXEMPLO*
<!--![image](https://user-images.githubusercontent.com/74382074/205517070-624514b0-fcf5-4def-b71e-a91bf81a67f2.png)-->
<image src="https://user-images.githubusercontent.com/74382074/205517070-624514b0-fcf5-4def-b71e-a91bf81a67f2.png" width=80% ></image>

<br>
<br>

## **BUSCA EM ARVORE B**
<br>

- pt é o ponteiro para raiz da arvore.
- Percorre as chaves do nó apontado até encontra ELEMENTO, ou até encontra uma chave > ELEMENTO, ou até percorrer todas as chaves do nó.
    - Se encontrou E encerra a busca.
    - Se não, se encontrou a chave > E, ptNovo = ponteiro da esquerda dessa chave.
    - Se não, se percorreu todas as chaves do nó atual, ptNovo = ponteiro a direita da última chave do nó.
    - Se ptNovo = NULL, encerra a busca, retornando pt ( chave não encontrada , mas, se existisse estaria nessa posição pt ).
    - Se nãao, pt = ptNovo, volte ao passo 2.


<br>
<br>

## **INSERÇÃO EM ARVORE B**
<br>

- Executa o algorítmo de busca.
- Se a chave está no nó, inserção inválida.
- Se chave não está no nó, inserção inválida.

<br>

## **INSERÇÃO EM ARVORE B, QUANDO NÓ CHEIO**
<br>

- Particionar a página, nó, em dois.
- Na página P permanece os D primeiros elementos.
- A entrada D + 1 sobre para o pai.
- Alocar outra página Q, e nelaalocas as outras D chaves.
- Repetir isso se necessário até a raiz, gerando uma nova raiz.


<br>

## **EXCLUSÃO EM ARVORE B**
<br>

- Caso E esteja em um nó folha fazer apenas a liberação dessa chave.
- Se não, substituir chave pela chave apontada a direita maior.
- Reorganizar o nó de onde foi retirado o elemento.


<br>

## **CONCATENAÇÃO EM ARVORE B, QUANDO A SOMA DAS QTD DE CHAVES  <= 2D**
<br>

- TODO NÓ DEVE TER AO MENOS **D** CHAVES, EXCETO O NÓ RAIZ QUE PODE TER 1 CHAVE.
- Duas páginas D e Q são adjacentes se têm o mesmo pai W e são apontadas por dois ponteiros adjacentes em W.
- P e Q podem ser concatenados se são irmãs adjacentes e juntas possuem 2D chaves.
- A concatenação é uma forma de diminuir a arvore.

<br>

## **REDITTRIBUIÇÃO EM ARVORE B, QUANDO A SOMA DAS QTD DE CHAVES  >= 2D**
<br>

- TODO NÓ DEVE TER AO MENOS **D** CHAVES, EXCETO O NÓ RAIZ QUE PODE TER 1 CHAVE.
- Concatenar P e Q.
- Isso resulta em um nó com mais de 2D chaves, nao permitido.
- Particionar nó P usando Q como novo nó.
- Essa operação não é propagável. o nó pai W é alterado mais seu número de chaves não é alterado.

<br>
<br>

# **ARVORE B+**
<br>


Semelhante a arvore B, porém com 2 diferenças:

 **RELEMBRANDO**
- A raiz é folha ou tem ao menos 2 filhos.
- Cada nó interno ( nao folha e nao raiz ) possui ao menos  D + 1 filhos.
- Cada nó tem no maximo 2D + 1 filhos.
- Todas as folhas estao no mesmo nível e apontam para NULL.

<br>

**ARVORE B+**
- Armazena dados somente nas folhas - os nós internos só servem apenas de ponteiros.
- As folhas são encadeadas, ou seja não apontam para NULL>
- Índices e chaves se repetem.


<br>

### *EXEMPLO*
<!--![image](https://user-images.githubusercontent.com/74382074/205699868-f5b3d3ff-49b3-4698-807c-c97265fab5a0.png)-->
<image src="https://user-images.githubusercontent.com/74382074/205699868-f5b3d3ff-49b3-4698-807c-c97265fab5a0.png" width=80% ></image>



### *ÍNDICES REPETEM VALORES DE CHAVE QUE APARECE NAS FOLHAS*

<br>

**ARVORE B+ BUSCA**
- Achou chave maior que a chave de busca, desce pelo ponteiro da esquerda.
- Achou chave igual a chave de busca, desce pelo ponteiro da direita.

<br>

## **INSERÇÃO EM ARVORE B+**
<br>

- Lógica similar a de arvore B.
- Diferenciando em:
     - Para a página Pai sobe somente o valor da chave. O registro fica na folha, juntamente com sua chave.
    - Isso só vale se o nó  que está sendo particionado for uma folha.
    - Se não, seguir o mesmo procedimento da arvore B.

<br>

## **EXCLUSÃO EM ARVORE B+**
<br>

- Exclusão ocorre apenas no nó folha.
- Chaves excluidas continuam nos nós intermediários.