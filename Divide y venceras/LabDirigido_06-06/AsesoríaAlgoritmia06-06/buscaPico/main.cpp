#include <iostream>
#include <iomanip>
#include <cstring>
#include <fstream>

using namespace std;

int buscarMax(int*arr,int ini,int fin){
    if(ini==fin)return arr[ini];

    int med=(ini+fin)/2;
    if(arr[med]>arr[med+1])return buscarMax(arr,ini,med);
    else return buscarMax(arr,med+1,fin);

}

int main(int argc, char** argv) {
    int arr[]={2,4,5,6,8,12,3,1};
    int n=sizeof(arr)/sizeof(arr[0]);

    cout<<buscarMax(arr,0,n-1);
    return 0;
}

