#include "03_lista_estatica.h"

#include <iostream>
#include <math.h>

using namespace std;

Lista::Lista(int quantidade_max)
{
    this->quantidade_max = quantidade_max;
    this->lista = new Individuo[this->quantidade_max];
}
Lista::~Lista()
{
    delete [] this->lista;
}

bool Lista::esta_vazia()
{
    for (int i = 0; i < this->quantidade_max; i++)
    {
        if (this->lista[i].get_id() != -1)
        {
            return false;
        }
    }
    return true;
}
bool Lista::esta_cheia()
{
    for (int i = 0; i < this->quantidade_max; i++)
    {
        if (this->lista[i].get_id() == -1)
        {
            return false;
        }
    }
    return true;
}
int Lista::quantidade_itens()
{
    int count = 0;

    for (int i = 0; i < this->quantidade_max; i++)
    {
        if (this->lista[i].get_id() != -1)
        {
            count++;
        }
    }
    return count;
}

bool Lista::inserir(Individuo individuo)
{
    for (int i = 0; i < this->quantidade_max; i++)
    {
        if (this->lista[i].get_id() == -1)
        {
            this->lista[i] = individuo;

            return true;
        }
    }
    return false;
}
Individuo Lista::remover(int id)
{
    Individuo generico;

    for (int i = 0; i < this->quantidade_max; i++)
    {
        if (this->lista[i].get_id() == id)
        {
            Individuo removido;

            removido = this->lista[i];
            this->lista[i] = generico;

            return removido;
        }
    }
    return generico;
}
Individuo Lista::buscar(int id)
{
    for (int i = 0; i < this->quantidade_max; i++)
    {
        if (this->lista[i].get_id() == id)
        {
            return this->lista[i];
        }
    }
    Individuo generico;

    return generico;
}

void Lista::imprimir()
{
    for (int i = 0; i < this->quantidade_max; i++)
    {
        if (this->lista[i].get_id() != -1)
        {
            cout << "\tIndivíduo id: " << this->lista[i].get_id() << ", ";
            cout << "Nome: " << this->lista[i].get_nome() << endl;
        }
    }
}

void Lista::bubble_sort()
{
    int continuar, fim = this->quantidade_max;
    Individuo auxiliar;

    do
    {
        continuar = 0;
        
        for (int i = 0; i < fim - 1; i++)
        {
            if (this->lista[i].get_id() > this->lista[i + 1].get_id())
            {
                auxiliar = this->lista[i];
                this->lista[i] = this->lista[i + 1];
                this->lista[i + 1] = auxiliar;
                continuar = i;
            }
        }
        fim--;
    } while (continuar != 0);
}
void Lista::insertion_sort()
{
    int j;
    Individuo auxiliar;

    for (int i = 1; i < this->quantidade_max; i++)
    {
        auxiliar = this->lista[i];

        for (j = i; j > 0 && auxiliar.get_id() < this->lista[j - 1].get_id(); j--)
        {
            this->lista[j] = this->lista[j - 1];
        }
        this->lista[j] = auxiliar;
    }
}
void Lista::selection_sort()
{
    int menor_id;
    Individuo auxiliar;

    for (int i = 0; i < this->quantidade_max - 1; i++)
    {
        menor_id = i;

        for (int j = i + 1; j < this->quantidade_max; j++)
        {
            if (this->lista[j].get_id() < this->lista[menor_id].get_id())
            {
                menor_id = j;
            }
        }
        if (i != menor_id)
        {
            auxiliar = this->lista[i];
            this->lista[i] = this->lista[menor_id];
            this->lista[menor_id] = auxiliar;
        }
    }
}
void Lista::merge_sort()
{
    this->merge_recursion(this->lista, 0, this->quantidade_max - 1);
}

void Lista::merge_recursion(Individuo *lista, int inicio, int fim)
{
    int meio;

    if (inicio < fim)
    {
        meio = floor((inicio + fim) / 2);

        this->merge_recursion(lista, inicio, meio);
        this->merge_recursion(lista, meio + 1, fim);

        this->merge(lista, inicio, meio, fim);
    }
}
void Lista::merge(Individuo *lista, int inicio, int meio, int fim)
{
    int primeira_metade = inicio;
    int segunda_metade = meio + 1;
    int quantidade = fim - inicio + 1;
    bool fim_primeira_metade = false, fim_segunda_metade = false;
    Individuo *temporario = new Individuo[quantidade];

    if (temporario != NULL)
    {
        for (int i = 0; i < quantidade; i++)
        {
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
                
                if (primeira_metade > meio)
                {
                    fim_primeira_metade = true;
                }

                if (segunda_metade > fim)
                {
                    fim_segunda_metade = true;
                }
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
            }
        }
        
        for (int j = 0, k = inicio; j < quantidade; j++, k++)
        {
            lista[k] = temporario[j];
        }
    }
    delete [] temporario;
}
