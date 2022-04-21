#include "01_individuo.h"

using namespace std;

class Lista
{
private:
    int quantidade_max;
    Individuo *lista;
    
    void merge_recursion(Individuo *lista, int inicio, int fim);
    void merge(Individuo *lista, int inicio, int meio, int fim);
public:
    Lista(int quantidade_max);
    ~Lista();

    bool esta_vazia();
    bool esta_cheia();
    int quantidade_itens();

    bool inserir(Individuo individuo);
    Individuo remover(int id);
    Individuo buscar(int id);

    void imprimir();

    void bubble_sort();
    void insertion_sort();
    void selection_sort();
    void merge_sort();
};
