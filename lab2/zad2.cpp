#include<iostream>
using namespace std;

void zamien(int &a,int &b)
{
    int t;
    t = a;
    a=b;
    b=t;

}

int main()
{
    int A,B;
    cout<<"Podaj dwie liczby:";
    cin>>A>>B;
    zamien(A,B);
    cout<<A<<" "<<B<<endl;
    return 0;
}