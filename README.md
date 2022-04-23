# Algoritmos de Ordenação 

Repositório contendo estudos de algoritmos de ordenação desenvolvidos na linguagem C++.



## Tipo de Dado

Os algoritmos de ordenação presentes nesse repositório são aplicados sobre um vetor contendo elementos de uma classe denominada `Individuo`, contendo as variáveis `int`: id e idade; `float`: peso e altura; e `string`: nome.

```cpp
class Individuo
{
private:
    int id, idade;
    float peso, altura;
    string nome;
```

Para mais informações sobre a classe e a estrutura dos dados verifique a pasta sobre [Lista Sequencial Estática](https://github.com/NetoStAna/estruturas-de-dados/tree/main/01_lista_sequencial_estatica) em meu repositório sobre [Estruturas de Dados](https://github.com/NetoStAna/estruturas-de-dados).



## Tipos de Ordenação

Todos os algoritmos ordenam o `vetor` com objetos do tipo `Individuo`, através do `id` de cada um em ordem crescente.



### Bubble Sort

O método utiliza uma variável `int`: continuar, para verificar a necessidade de continuar a ordenação, uma variável `int`: fim, inicializada com a quantidade de itens no `vetor`, um `Individuo`: auxiliar, para auxiliar nas trocas necessárias pela ordenação, assim como um loop `do, while`, que segue enquanto o valor da variável `continuar` for diferente de `0`.

```cpp
void Lista::bubble_sort()
{
    int continuar, fim = this->quantidade_max;
    Individuo auxiliar;

    do
    {
```

A cada etapa do loop a variável `continuar` recebe o valor `0` e é utilizado um laço `for` que percorre a quantidade de itens correspondente ao valor da variável `fim`.

```cpp
        continuar = 0;
        
        for (int i = 0; i < fim - 1; i++)
        {
```

A cada etapa do laço é verificado se o `id` do `Individuo` na posição `i` do `vetor` é maior que o `id` do `Individuo` da posição seguinte. Em caso afirmativo, a variável `auxiliar` recebe o `Individuo` da posição `i`, a posição `i` recebe o `Individuo` da posição seguinte, a posição seguinte recebe o `Individuo` da variável `auxiliar` e a variável `continuar` recebe o valor de `i`.

```cpp
            if (this->lista[i].get_id() > this->lista[i + 1].get_id())
            {
                auxiliar = this->lista[i];
                this->lista[i] = this->lista[i + 1];
                this->lista[i + 1] = auxiliar;
                continuar = i;
            }
```

Desta forma, ao fim do laço, o `Individuo` com maior `id` será posto no final do `vetor`. Por fim, a variável `fim` é decrementada em uma unidade para evitar trabalhar com o elemento já ordenado e o loop `do, while` continua até que todos os elementos estejam ordenados.

```cpp
        }
        fim--;
    } while (continuar != 0);
}
```

> Melhor Caso: O<sub>(n)</sub>
>
> Pior Caso: O<sub>(n²)</sub>



### Insertion Sort

O método utiliza uma variável `int`: j, para controlar um laço aninhado e a posição de inserção do elemento analisado, e uma variável `Individuo`: auxiliar, para auxiliar nas trocas necessárias pela ordenação, assim como um laço `for` que percorre o `vetor` a partir do segundo elemento até o fim.

```cpp
void Lista::insertion_sort()
{
    int j;
    Individuo auxiliar;

    for (int i = 1; i < this->quantidade_max; i++)
    {
```

A cada etapa do laço, a variável `auxiliar` recebe o `Individuo` da posição `i` e utiliza-se outro laço `for` aninhado, iniciando na posição `i` e percorrendo o `vetor` até o início ou até que seja encontrado um `Individuo` com `id` menor que o `id` do `Individuo` armazenado na variável `auxiliar`.

```cpp
        auxiliar = this->lista[i];

        for (j = i; j > 0 && auxiliar.get_id() < this->lista[j - 1].get_id(); j--)
        {
```

A cada etapa do laço aninhado, o elemento da posição `j` do `vetor` recebe o elemento anterior. Por fim, a última posição `j` recebe o `Individuo` armazenado na variável `auxiliar`, desta forma, o `Individuo` que originalmente estava na posição `i` estará na posição correta em relação aos elementos anteriores.

```cpp
            this->lista[j] = this->lista[j - 1];
        }
        this->lista[j] = auxiliar;
    }
}
```

> Melhor Caso: O<sub>(n)</sub>
>
> Pior Caso: O<sub>(n²)</sub>



### Selection Sort

O método utiliza uma variável `int`: menor_id, para verificar a posição do `Individuo` com menor `id` no vetor, uma variável `Individuo`: auxiliar, para auxiliar nas trocas necessárias da ordenação, assim como um laço `for` que percorre o `vetor` do início até a última posição.

```cpp
void Lista::selection_sort()
{
    int menor_id;
    Individuo auxiliar;

    for (int i = 0; i < this->quantidade_max - 1; i++)
    {
```

A cada etapa do laço, a variável `menor_id` recebe o valor de `i`, em seguida é utilizado outro laço `for` aninhado que percorre o `vetor` da posição seguinte de `i` até o final.

```cpp
        menor_id = i;

        for (int j = i + 1; j < this->quantidade_max; j++)
        {
```

A cada etapa do laço aninhado o valor do `id` do `Individuo` na posição `j` é comparado ao valor do `id` do `Individuo` na posição `menor_id`. Caso o primeiro seja menor que o segundo, a variável `menor_id` recebe o valor de `j`, desta forma ao fim do laço aninhado a variável `menor_id` terá a posição do `Individuo` com o menor `id` no `vetor`.

```cpp
            if (this->lista[j].get_id() < this->lista[menor_id].get_id())
            {
                menor_id = j;
            }
```

Por fim, é verificada a diferença entre o valor da variável `i` e o valor da variável `menor_id`, caso estes sejam diferentes, a variável `auxiliar` recebe o `Individuo` da posição `i` do `vetor`, a posição `i` do `vetor` recebe o `Individuo` da posição `menor_id` e a posição `menor_id` recebe o `Individuo` da variável `auxiliar`. Caso contrário, o primeiro laço `for` continua normalmente.

```cpp
        }
        if (i != menor_id)
        {
            auxiliar = this->lista[i];
            this->lista[i] = this->lista[menor_id];
            this->lista[menor_id] = auxiliar;
        }
    }
}
```

> Melhor Caso: O<sub>(n²)</sub>
>
> Pior Caso: O<sub>(n²)</sub>



### Merge Sort

O método utiliza a função `merge_recursion` aplicada sobre a variável `lista`, iniciando em `0` e finalizando em `quantidade_max - 1`.

```cpp
void Lista::merge_sort()
{
    this->merge_recursion(this->lista, 0, this->quantidade_max - 1);
}
```



#### Merge Recursion

A função recebe uma variável `Individuo *`: lista, uma variável `int`: inicio e uma variável `int`: fim como parâmetros e utiliza uma variável `int`: meio, para dividir o `vetor`.

```cpp
void Lista::merge_recursion(Individuo *lista, int inicio, int fim)
{
    int meio;
```

Em seguida, são comparados os valores das variável `inicio` e `fim`, caso o primeiro seja menor que o segundo, a variável `meio` recebe o valor da média entre as duas variáveis, a função `merge_recursion` é usada na primeira e na segunda metade do `vetor` e a função `merge` é aplicada sobre as variáveis `lista`, `inicio`, `meio` e `fim`.

```cpp

    if (inicio < fim)
    {
        meio = floor((inicio + fim) / 2);

        this->merge_recursion(lista, inicio, meio);
        this->merge_recursion(lista, meio + 1, fim);

        this->merge(lista, inicio, meio, fim);
    }
}
```



#### Merge

A função recebe uma variável `Individuo *:` lista e as variáveis `int`: inicio, meio e fim, como parâmetros e utiliza as variáveis `int`: primeira_metade, inicializada com o valor da variável `inicio`, `int`: segunda_metade, inicializada com o valor da variável `meio` mais `1`, `int`: quantidade, inicializada com o valor da variável `fim` menos o valor da variável `inicio` mais `1`, `bool`: fim_primeira_metade e fim_segunda_metade, inicializadas em `false` e aloca-se um `vetor` de objetos do tipo `Individuo`: temporario, com a quantidade definida na variável `quantidade`, para auxiliar na transferência dos elementos durante a ordenação.

```cpp
void Lista::merge(Individuo *lista, int inicio, int meio, int fim)
{
    int primeira_metade = inicio;
    int segunda_metade = meio + 1;
    int quantidade = fim - inicio + 1;
    bool fim_primeira_metade = false, fim_segunda_metade = false;
    Individuo *temporario = new Individuo[quantidade];
```

Em seguida, verifica-se se o a variável `temporario` está vazia, caso contrário, inicia-se um laço `for` que percorre todo o `vetor`.

```cpp

    if (temporario != NULL)
    {
        for (int i = 0; i < quantidade; i++)
        {
```

A cada etapa do laço, é verificado se uma das variáveis `fim_primeira_metade` e `fim_segunda_metade` se tornaram verdadeiras, em caso negativo, o `id` do `Individuo` da posição da `primeira_metade` é comparado ao `id` do `Individuo` da posição da `segunda_metade`, o menor destes dois é colocado na posição `i` do `vetor` e sua variável correspondente é incrementada em uma unidade.

```cpp
            if (!fim_primeira_metade && !fim_segunda_metade)
            {
                if (lista[primeira_metade].get_id() < lista[segunda_metade].get_id())
                {
                    temporario[i] = lista[primeira_metade++];
                }
                else
                {
                    temporario[i] = lista[segunda_metade++];
                }
```

Em seguida, verifica-se se a primeira ou a segunda metade chegaram ao fim e atualiza-se a variável correspondente.

```cpp
                
                if (primeira_metade > meio)
                {
                    fim_primeira_metade = true;
                }

                if (segunda_metade > fim)
                {
                    fim_segunda_metade = true;
                }
```

Caso uma das duas metades já tenha chegado ao fim, verifica-se qual destas está finalizada e insere-se o restante dos demais elementos no `vetor`.

```cpp
            }
            else
            {
                if (!fim_primeira_metade)
                {
                    temporario[i] = lista[primeira_metade++];
                }
                else
                {
                    temporario[i] = lista[segunda_metade++];
                }
```

Por fim, o a variável `temporario` contará com um `vetor` ordenado e será transferida para a variável `lista` recebida como parâmetro, através de um laço `for` que percorre ambos os `vetores`. Em seguida, a variável `temporario` é liberada da memória, finalizando a função.

```cpp
            }
        }
        
        for (int j = 0, k = inicio; j < quantidade; j++, k++)
        {
            lista[k] = temporario[j];
        }
    }
    delete [] temporario;
}
```

> Melhor Caso: O<sub>(n * log<sub>n</sub>)</sub>
>
> Pior Caso: O<sub>(n * log<sub>n</sub>)</sub>



### Quick Sort

O método utiliza a função `quick_recursion` aplicada sobre a variável `lista`, iniciando em `0` e finalizando em `quantidade_max - 1`.

```cpp
void Lista::quick_sort()
{
    this->quick_recursion(this->lista, 0, this->quantidade_max - 1);
}
```



#### Quick Recursion

A função recebe uma variável `Individuo *`: lista, uma variável `int`: inicio e uma variável `int`: fim como parâmetros e utiliza uma variável `int`: pivo, para definir o ponto de início da ordenação.

```cpp
void Lista::quick_recursion(Individuo *lista, int inicio, int fim)
{
    int pivo;
```

Em seguida, são comparados os valores das variável `fim` e `inicio`, caso o primeiro seja maior que o segundo, a variável `pivo` recebe o valor retornado da função `particionar` aplicada às variáveis recebidas como parâmetro e a função `quick_recursion` é aplicada sobre as duas partes do `vetor` que são divididas pelo valor da variável `pivo`.

```cpp

    if (fim > inicio)
    {
        pivo = this->particionar(lista, inicio, fim);

        this->quick_recursion(lista, inicio, pivo - 1);
        this->quick_recursion(lista, pivo + 1, fim);
    }
}
```



#### Particionar

A função recebe uma variável `Individuo *`: lista, uma variável `int`: inicio e uma variável `int`: fim como parâmetros e utiliza as variáveis `int`: esquerda, inicializada com o valor da variável `inicio`, `int`: direita, inicializada com o valor da variável `fim`, `Individuo`: auxiliar, utilizado para auxiliar nas trocas necessárias para a ordenação e `Individuo`: pivo, inicializada com o `Individuo` armazenado na posição correspondente à variável `inicio` do `vetor` da variável `lista`. Em seguido é utilizado um loop `while`, que segue enquanto o valor da variável `esquerda` for menor que o valor da variável `direita`.

```cpp
int Lista::particionar(Individuo *lista, int inicio, int fim)
{
    int esquerda = inicio;
    int direita = fim;
    Individuo auxiliar, pivo = lista[inicio];

    while (esquerda < direita)
    {
```

A cada etapa do loop a variável `esquerda` é incrementada em uma unidade, enquanto esta for menor ou igual ao fim e o `id` do `Individuo` na posição correspondente for menor ou igual que o `id` do `pivo`.

```cpp
        while (esquerda <= fim && lista[esquerda].get_id() <= pivo.get_id())
        {
            esquerda++;
        }
```

Da mesma forma, a variável `direita` é decrementada em uma unidade, enquanto esta for maior ou igual a `0` e o `id` do `Individuo` da posição correspondente for maior que o `id` do `pivo`.

```cpp
        
        while (direita >= 0 && lista[direita].get_id() > pivo.get_id())
        {
            direita--;
        }
```

Após encerrados os dois loops das variável `esquerda` e `direita`, os valores destas são comparados, se a primeira for maior que a segunda, a variável `auxiliar` recebe o `Individuo` armazenado na posição `esquerda`, a posição correspondente à variável `esquerda` recebe o `Individuo` armazenado na posição `direita` e a posição correspondente à variável `direita` recebe a variável `auxiliar`.

```cpp
        
        if (esquerda < direita)
        {
            auxiliar = lista[esquerda];
            lista[esquerda] = lista[direita];
            lista[direita] = auxiliar;
        }
```

Ao final do loop principal, a posição correspondente à variável `inicio` recebe o `Individuo` armazenado na posição `direita` e a posição correspondente à variável `direita` recebe o `Individuo` armazenado no `pivo`. O método então é encerrado, retornando o valor da variável `direita`.

```cpp
    }
    lista[inicio] = lista[direita];
    lista[direita] = pivo;

    return direita;
}
```

> Melhor Caso: O<sub>(n * log<sub>n</sub>)</sub>
>
> Pior Caso: O<sub>(n²)</sub>



## Referência

Os algoritmos apresentados nesse repositório partem de estudos iniciados no curso de [ordenação](https://www.youtube.com/playlist?list=PL8iN9FQ7_jt6VF821P5sPbg4plqpWKn0x) do Dr. André Backes no canal [Programação Descomplicada Linguagem C](https://www.youtube.com/user/progdescomplicada) no YouTube.
