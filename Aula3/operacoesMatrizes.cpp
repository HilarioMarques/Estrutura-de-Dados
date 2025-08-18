#include <iostream>
using namespace std;

//função para imprimir a matriz
void imprimirMatriz(int M[][10], int linhas, int colunas){
    for(int i = 0; i < linhas; i++){
        for(int j = 0; j < colunas; j++){
            cout << M[i][j] << " ";
        }
        cout << endl;
    }
}

//somar duas matrizes
void somaMatriz(int A[][10], int B[][10], int C[][10], int linhas, int colunas){
    for(int i = 0; i < linhas; i++){
        for(int j = 0; j < colunas; j++){
            C[i][j] = A[i][j] + B[i][j];
        }
    }
}

//Multiplicar matrizes
void multiplicaMatriz(int A[][10], int B[][10], int C[][10], int l1, int c1, int c2){
    for(int i = 0; i < l1; i++){
        for(int j = 0; j < c2; j++){
            C[i][j] = 0;

            for(int k = 0; k < c1; k++){
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

int main(){
    int A[10][10], B[10][10], C[10][10];
    int l1, c1, l2, c2;

    cout << "Digite o número de linhas e colunas da primeira matriz: ";
    cin >> l1 >> c1;
    cout << "Digites os elementos da primeira matriz: ";
    for(int i = 0; i < l1; i++){
        for(int j = 0; j < c1; j++){
            cin >> A[i][j];
        }
    }

    cout << "Digite o número de linhas e colunas da segunda matriz: ";
    cin >> l2 >> c2;
    cout << "Digites os elementos da segunda matriz: ";
    for(int i = 0; i < l2; i++){
        for(int j = 0; j < c2; j++){
            cin >> B[i][j];
        }
    }

    if(l1 == l2 && c1 == c2){
        somaMatriz(A, B, C, l1, c1);
        cout << "\nResultado soma das matrizes:\n";
        imprimirMatriz(C, l1, c1);
    } else {
        cout << "\nNao é possível fazer a soma pois as matrizes tem dimensões diferentes.\n";
    }

    if(c1 == l2){
        multiplicaMatriz(A, B, C, l1, c1, c2);
        cout << "\nResultado multiplicação das matrizes:\n";
        imprimirMatriz(C, l1, c2);
    } else {
        cout << "\nNao é possível fazer a soma pois as matrizes tem dimensões imcompatíveis.\n";
    }

    return 0;

}