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



## Referência

Os algoritmos apresentados nesse repositório partem de estudos iniciados no curso de [ordenação](https://www.youtube.com/playlist?list=PL8iN9FQ7_jt6VF821P5sPbg4plqpWKn0x) do Dr. André Backes no canal [Programação Descomplicada Linguagem C](https://www.youtube.com/user/progdescomplicada) no YouTube.
