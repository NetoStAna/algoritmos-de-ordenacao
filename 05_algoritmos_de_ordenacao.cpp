#include "03_lista_estatica.h"

#include <iostream>

using namespace std;

int main()
{
    int menu, ord, id, idade, quantidade_max;
    float peso, altura;
    string nome;

    cout << "Algoritmo de ordenação bubble sort!\n";

    cout << "Digite a quantidade máxima de indivíduos a serem inseridos na lista!\n";
    cin >> quantidade_max;

    Lista lista_individuos(quantidade_max);

    do
    {
        cout << "Digite 1 para inserir um indivíduo na lista!\n";
        cout << "Digite qualquer outro número inteiro para encerrar a inserção e ordenar a lista!\n";
        cin >> menu;

        if (menu == 1)
        {
            cout << "Digite o id do indivíduo: ";
            cin >> id;

            cout << "Digite o nome do individuo: ";
            cin >> nome;

            cout << "Digite a idade do indivíduo: ";
            cin >> idade;

            cout << "Digite o peso do indivíduo: ";
            cin >> peso;

            cout << "Digite a altura do indivíduo: ";
            cin >> altura;

            Individuo inserido(id, idade, peso, altura, nome);
            bool resultado = lista_individuos.inserir(inserido);

            if (resultado)
            {
                cout << "Indivíduo id: " << id << " inserido com sucesso!\n";
            }
            else
            {
                cout << "Indivíduo id: " << id << " não inserido, pois a lista está cheia!\n";
            }
        }
    } while (menu == 1);

    cout << "Digite 1 para fazer a ordenação bubble sort!\n";
    cout << "Digite 2 para fazer a ordenação insertion sort!\n";
    cout << "Digite 3 para fazer a ordenação selection sort!\n";
    cout << "Digite qualquer outro número inteiro para fazer a ordenação merge sort!\n";
    cin >> ord;

    cout << "Lista antes da ordenação:\n";
    lista_individuos.imprimir();

    if (ord == 1)
    {
        lista_individuos.bubble_sort();
    }
    else if (ord == 2)
    {
        lista_individuos.insertion_sort();
    }
    else if (ord == 3)
    {
        lista_individuos.selection_sort();
    }
    else
    {
        lista_individuos.merge_sort();
    }

    cout << "Lista após ordenação:\n";
    lista_individuos.imprimir();

    cout << "Fim do algoritmo!\n";

    return 0;
}
