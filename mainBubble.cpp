#include <iostream>
#include <chrono>
#include "read_csv.h"
using namespace std;
using namespace chrono;


void bubbleSort(int** vetor, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (vetor[j][0] < vetor[j + 1][0]) {
                int* temp = vetor[j];
                vetor[j] = vetor[j + 1];
                vetor[j + 1] = temp;
            }

            else if (vetor[j][0] == vetor[j + 1][0]) {
                if (vetor[j][1] < vetor[j + 1][1]) {
                    int* temp = vetor[j];
                    vetor[j] = vetor[j + 1];
                    vetor[j + 1] = temp;
                }
            }
        }
    }
}


int main(){
    string nomeArquivo = "restaurante_pratos.csv";
    lerArquivo leitor(nomeArquivo);

    int linhas = leitor.getLinhas();
    int colunas = leitor.getColunas();

    int** intEndereco = leitor.enderecoIntArray();
    leitor.transformarStringEmInt();

    auto start = high_resolution_clock::now(); // inicio do tempo c/ o chrono

    bubbleSort(intEndereco, linhas);

    auto end = high_resolution_clock::now(); // fim do tempo
    auto duration = duration_cast<milliseconds>(end - start); // calcula a duracao

    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            cout << intEndereco[i][j] << " ";
        }
        cout << endl;
    }

    cout << "Tempo de ordenacao do BubbleSort: " << duration.count() << " milissegundos" << endl;

    return 0;
}
