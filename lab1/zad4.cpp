#include<iostream>
using namespace std;
int sumaDzielnikow( int n)
{
    int suma=0, i;
    for(i=1;i<n;i++)
    {
        if(n % i ==0)
        {
            suma+=i;
        }
    }
    return suma;
}   
int main()
{
    int a,b;
    cout << "Podaj liczbe a oraz b:";
    cin >> a >> b;
    if ((sumaDzielnikow(a)==b+1) && (sumaDzielnikow(b)==a+1))
    {
        cout << a << " i " << b << " sa liczbami skojarzonymi";
    }
    else
    {
        cout << a << " i " << b << " nie sa liczbami skojarzonymi";
    }
    return 0;
}