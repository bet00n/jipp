#include<iostream>
using namespace std;
int f(int a, int b,int &suma)
{
    suma=a+b;
    return a*b;
}

int main()
{
    int A,B,suma;
    cout<<"Podaj dwie liczby:";
    cin>>A>>B;
    cout<<"Iloczyn wynosi:"<<f(A,B,suma)<<endl;
    cout<<"Suma wynosi:"<<suma;
    return 0;
}