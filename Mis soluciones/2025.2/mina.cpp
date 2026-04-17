#include <iostream>
using namespace std;

#define N 6
#define M 11



bool valido(int i, int j,char mina[N][M],int res[N][M]) {
    return i >= 0 && i < N && j >= 0 && j < M &&
           mina[i][j] != '*' && res[i][j] == 0;//res[i][j] == 0 paraque cumpla la condicion de no sobreescriir en otra galeria
}

// prioridad: abajo → derecha → arriba
bool construirGaleria(int i, int j, int num,char mina[N][M],int res[N][M] ) {
    if (!valido(i, j,mina,res)) return false;

    res[i][j] = num;

    // si llegó al final devuelve true indicando que terminó de imprimir una galería
    if (j == M - 1) return true;

    // 1. abajo
    if (construirGaleria(i + 1, j, num,mina,res)) return true;

    // 2. derecha
    if (construirGaleria(i, j + 1, num,mina,res)) return true;

    // 3. arriba
    if (construirGaleria(i - 1, j, num,mina,res)) return true;

    // backtracking
    res[i][j] = 0;
    return false;
}

// generar varias galerías
void generarGalerias(int fila, int num,char mina[N][M],int res[N][M]) {
    if (fila < 0) return;

    if (valido(fila, 0,mina,res)) {//la primera celda a la izquiera (j==0)
        if (construirGaleria(fila, 0, num,mina,res)) {//si termina de imprimir la galería, genera otra galería
            generarGalerias(fila - 1, num + 1,mina,res);
            return;
        }
    }

    generarGalerias(fila - 1, num,mina,res);
}

void imprimir(char mina[N][M],int res[N][M]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (mina[i][j] == '*') cout << "* ";
            else cout << res[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    char mina[N][M];
    int res[N][M];
    // inicializar
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            mina[i][j] = '.';
            res[i][j] = 0;
        }
    }

    // rocas
    mina[3][5] = '*';
    mina[4][5] = '*';
    mina[5][5] = '*';

    generarGalerias(N - 1, 1,mina,res);//siendo 1 el numero q se imprimira en la mina. Empieza en la útima fila :V

    imprimir(mina,res);
}