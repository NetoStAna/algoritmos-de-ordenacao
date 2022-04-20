#include "03_lista_estatica.h"

#include <iostream>

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
    Individuo aux;

    do
    {
        continuar = 0;
        
        for (int i = 0; i < fim - 1; i++)
        {
            if (this->lista[i].get_id() > this->lista[i + 1].get_id())
            {
                aux = this->lista[i];
                this->lista[i] = this->lista[i + 1];
                this->lista[i + 1] = aux;
                continuar = i;
            }
        }
        fim--;
    } while (continuar != 0);
}
