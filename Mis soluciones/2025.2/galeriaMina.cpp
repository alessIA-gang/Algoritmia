//
// Created by isabe on 17/04/2026.
//

#include <iostream>
#define N 6
#define M 11
using namespace std;

bool celdaValida(int resultado[N][M], char mina[N][M], int xIni, int yIni) {
    return (xIni >= 0 && xIni < N && yIni >= 0 && yIni < M && mina[xIni][yIni] != '*' && resultado[xIni][yIni] == 0);
}

bool minaTerminada(int resultado[N][M], char mina[N][M], int x, int y, int num) {
    if (not celdaValida(resultado, mina, x, y)) return false;

    resultado[x][y] = num;
    if (y==M-1) return true; //terminó
    //abajo
    if (minaTerminada(resultado, mina, x + 1, y,num)) return true;
    //derecha
    if (minaTerminada(resultado, mina, x, y + 1,num)) return true;
    //arriba
    if (minaTerminada(resultado, mina, x - 1, y,num)) return true;
    //si ningun camio sirve, se deshace lo hecho
    resultado[x][y] = 0;
    return false;
}

void iniciarMina(int resultado[N][M], char mina[N][M], int xIni, int yIni, int numGaleria) {
if (xIni<0)return;
    if (celdaValida(resultado, mina, xIni, yIni)) {
        if (minaTerminada(resultado,mina,xIni,yIni,numGaleria)) {
            iniciarMina(resultado, mina, xIni - 1, 0, numGaleria + 1);
        }
    }
    iniciarMina(resultado, mina, xIni-1, yIni, numGaleria);
}
void imprimirMina(int resultado[N][M],char mina[N][M], int fila, int colum ) {
    for (int i = 0; i < fila; i++) {
        for (int j = 0; j < colum; j++) {
            if (mina[i][j] == '*') {
                cout << mina[i][j] << " ";
            }else {
                cout << resultado[i][j] << " ";
            }
        }
        cout << endl;
    }
}
int main() {
    //crear minas para rellenar
    int resultado[N][M];
    char mina[N][M];
    //inicializar
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            mina[i][j] = '.';
            resultado[i][j] = 0;
        }
    }
    //cargando minas
    mina[3][5]='*';
    mina[4][5]='*';
    // mina[5][5]='*';
    mina[5][0]='*';

    iniciarMina(resultado, mina,N - 1, 0, 1);
    imprimirMina(resultado,mina,N,M) ;
}
