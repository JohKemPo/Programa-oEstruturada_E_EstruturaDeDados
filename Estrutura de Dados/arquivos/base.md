# **ARQUIVOS EM C**

    MODO DE ABERTURA
    

    Significado

    "r"	Abre um arquivo texto para leitura. O arquivo deve existir antes de ser aberto.
    "w"	Abrir um arquivo texto para grava��o. Se o arquivo n�o existir, ele ser� criado. Se j� existir, o conte�do anterior ser� destru�do.
    "a"	Abrir um arquivo texto para grava��o. Os dados ser�o adicionados no fim do arquivo ("append"), se ele j� existir, ou um novo arquivo ser� criado, no caso de arquivo n�o existente anteriormente.
    "rb"	Abre um arquivo bin�rio para leitura. Igual ao modo "r" anterior, s� que o arquivo � bin�rio.
    "wb"	Cria um arquivo bin�rio para escrita, como no modo "w" anterior, s� que o arquivo � bin�rio.
    "ab"	Acrescenta dados bin�rios no fim do arquivo, como no modo "a" anterior, s� que o arquivo � bin�rio.
    "r+"	Abre um arquivo texto para leitura e grava��o. O arquivo deve existir e pode ser modificado.
    "w+"	Cria um arquivo texto para leitura e grava��o. Se o arquivo existir, o conte�do anterior ser� destru�do. Se n�o existir, ser� criado.
    "a+"	Abre um arquivo texto para grava��o e leitura. Os dados ser�o adicionados no fim do arquivo se ele j� existir, ou um novo arquivo ser� criado, no caso de arquivo n�o existente anteriormente.
    "r+b"	Abre um arquivo bin�rio para leitura e escrita. O mesmo que "r+" acima, s� que o arquivo � bin�rio.
    "w+b"	Cria um arquivo bin�rio para leitura e escrita. O mesmo que "w+" acima, s� que o arquivo � bin�rio.
    "a+b"	Acrescenta dados ou cria uma arquivo bin�rio para leitura e escrita. O mesmo que "a+" acima, s� que o arquivo � bin�rio

<br>
<br>

## **FUNÇÕES**
<br>
<br>

- fopen() - abre o rquivo
- fclose() - fecha arquivo e descarrega o buffer automatic.
- feof() - retorna TRUE se fim do arquivo
- ferror() - retorna TRUE se houve erro
- remove() - deleta arquivo
- fflsuh() - descarrega buffer no arquivo

<br>

### **LEITURA E ESCRITA**
<br>


- fputc() - escreve caractere 
- fgetc() - lê caractere
- fprintf()
- fscanf()

        