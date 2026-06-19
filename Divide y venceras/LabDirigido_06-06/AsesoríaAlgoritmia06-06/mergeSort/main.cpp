
#include <iostream>
using namespace std;

void merge(int*arr,int ini,int mid,int fin) {
    int n1=mid-ini+1;
    int n2=fin-mid;

    int temp[50];
    int i=ini, j=mid+1, k=ini; //i reccore la mitad izquierda,j recorre la mitad derecha, k recorre temp

    while(i<=mid && j<=fin) { //mientras ambas mitades tengan elementos por fusionar, fusiono
        //ordenamiento fusion entre arreglos
        // sobreecribe esto: temp
        if (arr[i]<=arr[j]) {
            //cogemos el dato i
            temp[k++]=arr[i++];
        }else {
            //cogemos el dato j
            temp[k++]=arr[j++];
        }
    }

    while (i<=mid) temp[k++]=arr[i++];//si es que el i todavia falta avanzar, entonces seguimos
    while (j<=fin) temp[k++]=arr[j++];//si es que el j todavia falta avanzar, entonces seguimos

    for (int x=ini;x<=fin;x++) arr[x]=temp[x]; //copiamos del temp al arr
}

void mergeSort(int*arr,int ini,int fin) {
    if (ini>=fin)return;
    int mid=(ini+fin)/2;
    mergeSort(arr,ini,mid); //partimos x la izquierda
    mergeSort(arr,mid+1,fin); //partimos x derecha
    merge(arr,ini,mid,fin);
}

int main() {
    int arr[]={5,3,1,9,2,7,4,6};
    int n = sizeof(arr)/sizeof(arr[0]);

    mergeSort(arr,0,n-1);

    for(int i=0;i<n;i++) {
        cout<<arr[i]<<" ";
    }
    return 0;
}