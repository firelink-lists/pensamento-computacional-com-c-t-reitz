/*
Enunciado:

Um sistema embarcado de controle de estoque precisa ordenar um array
de inteiros representando quantidades de produtos. Por restrições de
memória, a equipe optou pelo selection sort, que realiza a ordenação in-
place sem necessidade de espaço auxiliar proporcional a n. O código C++
a seguir apresenta a estrutura do algoritmo com o corpo da função
selection_sort a ser completado.

#include <iostream>
void troca(int v[], int i, int j) {
    int tmp = v[i];
    v[i] = v[j];
    v[j] = tmp;
}
void selection_sort(int v[], int n) {
    for (int i = 0; i < n - 1; i++) {
        // implementação
    }
}

Considerando que a função deve ordenar o array em ordem crescente,
assinale a alternativa que apresenta a implementação correta do corpo
do laço de selection_sort.

Alternativa correta:

int min_idx = i;
for (int j = i + 1; j < n; j++)
    if (v[j] < v[min_idx])
        min_idx = j;
troca(v, i, min_idx);
*/

#include <iostream>
using namespace std;

void imprimir_array(int v[], int n, const string& mensagem) {
    cout << mensagem;
    cout << "[ ";
    for (int i = 0; i < n; i++) {
        cout << v[i] << " ";
    }
    cout << "]" << endl;
}

void troca(int v[], int i, int j) {
    int tmp = v[i];
    v[i] = v[j];
    v[j] = tmp;
}

void selection_sort(int v[], int n) {
    cout << "===== INICIO DO SELECTION SORT =====" << endl;

    for (int i = 0; i < n - 1; i++) {
        cout << "\n-----------------------------------" << endl;
        cout << "Passo " << i + 1 << endl;
        cout << "Posicao atual i = " << i << endl;

        int min_idx = i;
        cout << "Assumindo inicialmente que o menor elemento esta em min_idx = "
             << min_idx << " (valor = " << v[min_idx] << ")" << endl;

        for (int j = i + 1; j < n; j++) {
            cout << "Comparando v[" << j << "] = " << v[j]
                 << " com v[" << min_idx << "] = " << v[min_idx] << endl;

            if (v[j] < v[min_idx]) {
                min_idx = j;
                cout << "-> Novo menor encontrado em min_idx = " << min_idx
                     << " (valor = " << v[min_idx] << ")" << endl;
            }
        }

        cout << "Menor elemento do trecho restante encontrado em indice "
             << min_idx << " com valor " << v[min_idx] << endl;

        if (min_idx != i) {
            cout << "Trocando v[" << i << "] = " << v[i]
                 << " com v[" << min_idx << "] = " << v[min_idx] << endl;
            troca(v, i, min_idx);
        } else {
            cout << "Nenhuma troca necessaria, pois o menor elemento ja esta na posicao correta." << endl;
        }

        imprimir_array(v, n, "Array apos este passo: ");
    }

    cout << "\n===== FIM DO SELECTION SORT =====" << endl;
}

int main() {
    int estoque[] = {42, 17, 8, 99, 23, 4, 50, 12};
    int n = sizeof(estoque) / sizeof(estoque[0]);

    cout << "Exemplo: controle de estoque com quantidades de produtos" << endl;
    imprimir_array(estoque, n, "Array original: ");

    selection_sort(estoque, n);

    imprimir_array(estoque, n, "\nArray ordenado em ordem crescente: ");

    return 0;
}