#include<iostream>
using namespace std;

void zamien(int *a,int *b)
{
    if(*b > *a)
        swap(*a,*b);  
}

int main()
{
    int A,B;
    cout<<"Podaj dwie liczby:";
    cin>>A>>B;
    zamien(&A,&B);
    cout<<A<<" "<<B<<endl;
    return 0;
}