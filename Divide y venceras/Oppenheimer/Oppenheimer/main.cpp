#include <iostream>
using namespace std;
int PotenciaMaxima(int A[], int inicial, int final) {
    //es como un busca mayor
    //CASO BASE
    if (inicial==final)
        return A[inicial];
    //PARTE RECURSIVA
    int medio=(inicial+final)/2;
    if (A[medio]<=A[medio+1])//El cambio aquí es en "<=" ya que hay duplas, pero igual quiero encontrar el mayor de todos ellos.
        return PotenciaMaxima(A,medio+1,final);
    else
        return PotenciaMaxima(A,inicial,medio);
}
int Radiacion(int A[], int inicial, int final, int contador_no_positivos) {
    //CASO BASE
    if (inicial>final)
        return contador_no_positivos;//PARA REVISAR
    //PARTE RECURSIVA
    int medio=(inicial+final)/2;
    if (A[medio]>0)//A[medio] es positivo, entonces no lo considero en el análisis
        return Radiacion (A, inicial, medio-1, contador_no_positivos);
    else//A[medio] es no-positivo, lo cuento y no lo considero en el análisis
        return Radiacion (A, medio+1, final, contador_no_positivos+(medio-inicial)+1);//cuento los no-positivos
}
int main() {
    //int A[]={0,-1,0,-1,0,1,1,2,2,3,2,2,1,1};
    int A[]={-1,0,-1,0,1,1,2,2,3,3,4,3,3,2,2,1,1};
    int n= sizeof(A)/sizeof(int);
    int distancia=Radiacion(A, 0, n-1, 0); //O(logN)
    cout<<"La radiacion empieza en : "<<distancia<<endl;
    cout<<"Potencia maxima: "<< PotenciaMaxima(A, distancia, n-1)<<" megatones."<<endl; //O(logN)
    return 0;
}