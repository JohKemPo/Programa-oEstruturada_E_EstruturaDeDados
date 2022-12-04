# **ARVORE B**
<br>
<br>

## **CARACTERÍSTICAS**

<br>

- Cada nó tem N - 1 chaves. 
- Cada nó contem N filhos.
- As chaves do nó estão ordenadas.
- As chaves são separadores para ponteiros para os filhos do nó.

<br>

### **EXEMPLO**


<!--![image](https://user-images.githubusercontent.com/74382074/205516362-275e4d2b-c9c3-4058-855a-35c327c3e8a3.png)-->
<image src="https://user-images.githubusercontent.com/74382074/205516362-275e4d2b-c9c3-4058-855a-35c327c3e8a3.png" width=50% ></image>


<br>
<br>
<br>

- Ordem D
- A raiz é uma folha com ao menos 2 filhos.
- Cada nó, nao folha  e nem raiz, tem no mínimo D + 1 filhos.
- Cada nó tem no max 2d + 1 filhos.
- Todas as folhas, apontando para null, estao no mesmo nível.
- Seja M o número de chaves em uma página P, temos P com M + 1 filhos, P tem entre D e 2D chaves.
- P contém m+1 ponteiros para filhos.


<br>

### **EXEMPLO**
<!--![image](https://user-images.githubusercontent.com/74382074/205517070-624514b0-fcf5-4def-b71e-a91bf81a67f2.png)-->
<image src="https://user-images.githubusercontent.com/74382074/205517070-624514b0-fcf5-4def-b71e-a91bf81a67f2.png" width=50% ></image>


