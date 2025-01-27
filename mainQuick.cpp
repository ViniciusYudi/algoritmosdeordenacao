#include <iostream>
#include <chrono>
#include "read_csv.h"
using namespace std;
using namespace chrono;

int particiona(int** vetor, int inicio, int fim) {
    int esq = inicio + 1;
    int dir = fim;
    int* pivo = vetor[inicio]; // o pivo aqui é escolhido como sendo o 1º elemento
    int* aux;

    while (esq <= dir) {
        while (esq <= fim) {
            if (vetor[esq][0] > pivo[0]) {
                esq++;
            }
            else if (vetor[esq][0] == pivo[0] && vetor[esq][1] > pivo[1]) {
                esq++;
            }
            else {
                break;
            }
        }
        while (dir >= inicio) {
            if (vetor[dir][0] < pivo[0]) {
                dir--;
            }
            else if (vetor[dir][0] == pivo[0] && vetor[dir][1] < pivo[1]) {
                dir--;
            }
            else {
                break;
            }
        }

        if (esq <= dir) {
            int* temp = vetor[esq];
            vetor[esq] = vetor[dir];
            vetor[dir] = temp;
            esq++;
            dir--;
        }
    }
    aux = vetor[inicio];
    vetor[inicio] = vetor[dir];
    vetor[dir] = aux;

    return dir;
}

void quickSort(int** vetor, int inicio, int fim) {
    if (inicio < fim) {
        int pivo = particiona(vetor, inicio, fim);
        quickSort(vetor, inicio, pivo - 1);
        quickSort(vetor, pivo + 1, fim);
    }
}

int main() {
    string nomeArquivo = "restaurante_pratos.csv";
    lerArquivo leitor(nomeArquivo);

    int linhas = leitor.getLinhas();
    int colunas = leitor.getColunas();

    int** intEndereco = leitor.enderecoIntArray();
    leitor.transformarStringEmInt();

    auto start = high_resolution_clock::now();

    quickSort(intEndereco, 0, leitor.getLinhas() - 1);

    auto end = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(end - start);

    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            cout << intEndereco[i][j] << " ";
        }
        cout << endl;
    }

    cout << "Tempo de ordenacao do QuickSort: " << duration.count() << " milissegundos" << endl;

    return 0;
}
