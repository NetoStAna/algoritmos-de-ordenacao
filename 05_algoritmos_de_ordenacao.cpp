#include "03_lista_estatica.h"

#include <iostream>

using namespace std;

int main()
{
    int menu, id, idade, quantidade_max;
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

    cout << "Lista antes da ordenação:\n";
    lista_individuos.imprimir();

    lista_individuos.bubble_sort();

    cout << "Lista após ordenação:\n";
    lista_individuos.imprimir();
}
