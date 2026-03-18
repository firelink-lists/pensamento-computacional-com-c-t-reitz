/*
Contexto do problema:

Um sistema embarcado de controle de estoque precisa ordenar um array
de inteiros que representam quantidades de produtos. Como o ambiente
possui restrição de memória, foi escolhido o algoritmo selection sort,
pois ele organiza os elementos diretamente no próprio array, sem usar
estrutura auxiliar proporcional ao tamanho da entrada.

A função selection_sort deve ordenar os valores em ordem crescente.

Trecho correto da lógica dentro do laço principal:

int min_idx = i;
for (int j = i + 1; j < n; j++)
    if (v[j] < v[min_idx])
        min_idx = j;
troca(v, i, min_idx);
*/

#include <iostream>
using namespace std;

void exibirArray(int v[], int n, const string& texto) {
    cout << texto << "[ ";
    for (int i = 0; i < n; i++) {
        cout << v[i] << " ";
    }
    cout << "]" << endl;
}

void troca(int v[], int i, int j) {
    int aux = v[i];
    v[i] = v[j];
    v[j] = aux;
}

void selection_sort(int v[], int n) {
    cout << "\n=== Iniciando ordenacao por Selection Sort ===" << endl;

    for (int i = 0; i < n - 1; i++) {
        cout << "\nEtapa " << i + 1 << ":" << endl;
        cout << "Vamos definir qual valor deve ficar na posicao " << i << "." << endl;

        int min_idx = i;
        cout << "Por enquanto, o menor valor considerado esta no indice "
             << min_idx << ", com valor " << v[min_idx] << "." << endl;

        for (int j = i + 1; j < n; j++) {
            cout << "Analisando indice " << j << " (valor " << v[j] << ")"
                 << " em comparacao com o menor atual (valor " << v[min_idx] << ")." << endl;

            if (v[j] < v[min_idx]) {
                min_idx = j;
                cout << "Novo menor valor encontrado: " << v[min_idx]
                     << " no indice " << min_idx << "." << endl;
            }
        }

        if (min_idx != i) {
            cout << "Troca necessaria: colocando " << v[min_idx]
                 << " na posicao " << i << "." << endl;
            troca(v, i, min_idx);
        } else {
            cout << "A posicao " << i << " ja contem o menor elemento restante. Nenhuma troca feita." << endl;
        }

        exibirArray(v, n, "Estado atual do array: ");
    }

    cout << "\n=== Ordenacao concluida ===" << endl;
}

int main() {
    int estoque[] = {37, 12, 25, 9, 58, 3, 41, 18};
    int n = sizeof(estoque) / sizeof(estoque[0]);

    cout << "Sistema de estoque - demonstracao de ordenacao" << endl;
    exibirArray(estoque, n, "Valores antes da ordenacao: ");

    selection_sort(estoque, n);

    exibirArray(estoque, n, "\nValores depois da ordenacao: ");

    return 0;
}