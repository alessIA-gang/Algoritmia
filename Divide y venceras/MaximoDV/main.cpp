#include <iostream>
using namespace std;
int MaximoDV(int A[], int inicial, int final) {
    //CASO BASE
    if (inicial==final)
        return A[inicial];
    //PARTE RECURSIVA
    int medio=(inicial+final)/2;
    if (A[medio]<A[medio+1])
        return MaximoDV(A, medio+1,final);
    else
        return MaximoDV(A,inicial,medio);
}
int main() {
    int A[]={8,10,20,80,100,200,400,399,3,2,1};
    int n=11;
    cout<<MaximoDV(A, 0, n-1)<<endl;
    return 0;
}