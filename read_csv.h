// C++ Program to illustrate how we can read data from a
// CSV file into a 2D array
#include <fstream>
#include <iostream>
#include <sstream>
#include <stdlib.h>
using namespace std;

class lerArquivo{
    private:
        string ** data;
        int** intData;
        float** floatData;
        int col = 0;
        int row = 0;
        int maxrows = 0, maxcols = 0;
        int * colunasporlinha;
    public:
        // construtor
        lerArquivo(string &file){
            ifstream files(file);
            if(!files.is_open()) {
                cerr << "Error opening file!" << endl;
                return; 
            }

            string line;
            row = 0;
            col = 0;

            // implementei inicializando com 1 e contando a qtd de virgulas (eh um csv, então vai ser separado por virgula)

            while(getline(files, line)) {
                row++;
                stringstream ss(line);
                string cell;
                int tempCol = 0;

                while (getline(ss, cell, ',')){
                    tempCol++;
                }

                if (tempCol > maxcols){
                    maxcols = tempCol;
                }
            }
            maxrows = row;
            files.close();

            // abrir o arquivo dnv, não achei outra alternativa (peço perdão se ficar muito poluído, mas é o que funcionou)

            ifstream files2(file);
            if(!files2.is_open()){
                cerr << "Error opening file!" << endl;
                return;
            }

            // alocacao dinamica, funciona pensando em alocar memoria p cada linha considerando a qtd de colunas (maxcols)

            data = new string*[maxrows];
            intData = new int* [maxrows];
            floatData = new float* [maxrows];
            colunasporlinha = new int[maxrows];
            for (int i = 0; i < maxrows; i++) {
                data[i] = new string[maxcols];
                intData[i] = new int[maxcols];
                floatData[i] = new float[maxcols];
            }
        
            row = 0;
            while (getline(files2, line) && row < maxrows) {
                stringstream ss(line);
                string cell;
                col = 0;
                while (getline(ss, cell, ',') && col < maxcols) {
                    data[row][col] = cell;
                    col++;
                }   
                colunasporlinha[row] = col;
                row++;
            }

            files2.close();
        }

        int getLinhas(){
            return row;
        }

        int getColunas(){
            return col;
        }

        int** enderecoIntArray() {
            return intData;
        }

        float** enderecoFloatArray(){
            return floatData;
        }

        void transformarStringEmInt(){
            for (int i = 0; i < maxrows; i++) {
                for (int j = 0; j < maxcols; j++){
                    intData[i][j] = atoi(data[i][j].c_str()); // atoi significa ascii to integer.
                }
            }
            cout << "Array bidimensional de string convertido para inteiro" << endl;
        }

        void transformarStringEmFloat(){
            for(int i = 0; i < maxrows; i++){
                for(int j = 0; j < maxcols; j++){
                    floatData[i][j] = atof(data[i][j].c_str()); // atof significa ascii to float.
                }
            }
            cout << "Array bidimensional de string convertido para flutuante" << endl;
        }

        // destrutor pra nao explodir a memoria
        ~lerArquivo() {
            for (int i = 0; i < maxrows; i++) {
                delete[] data[i];
                delete[] intData[i];
                delete[] floatData[i];
            }
            delete[] data;
            delete[] intData;
            delete[] floatData;
            delete[] colunasporlinha;
        }
};   
