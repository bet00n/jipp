#include <iostream>
using namespace std;

int main()
{
    int a[10][10], b[10][10], wynik[10][10], r1, c1, r2, c2, i, j, k;
start:
    cout << "Ilosc rzedow i kolumn w pierwszej macierzy: ";
    cin >> r1 >> c1;
    cout << "Ilosc rzedow i kolumn w drugiej macierzy: ";
    cin >> r2 >> c2;

    while (c1!=r2)
    {
        cout << "Kolumny pierwszej macierzy nie zgadzaja sie z rzedami drugiej!";
        goto start;
    }

    cout << endl << "Podaj elementy pierwszej macierzy:" << endl;
    for(i = 0; i < r1; ++i)
        for(j = 0; j < c1; ++j)
        {
            cout << "Podaj element a" << i + 1 << j + 1 << " : ";
            cin >> a[i][j];
        }

    cout << endl << "Podaj elementy drugiej amcierzy :" << endl;
    for(i = 0; i < r2; ++i)
        for(j = 0; j < c2; ++j)
        {
            cout << "Podaj element b" << i + 1 << j + 1 << " : ";
            cin >> b[i][j];
        }

    for(i = 0; i < r1; ++i)
        for(j = 0; j < c2; ++j)
        {
            wynik[i][j]=0;
        }

    for(i = 0; i < r1; ++i)
        for(j = 0; j < c2; ++j)
            for(k = 0; k < c1; ++k)
            {
                wynik[i][j] += a[i][k] * b[k][j];
            }

    cout << endl << "Wynik: " << endl;
    for(i = 0; i < r1; ++i)
    for(j = 0; j < c2; ++j)
    {
        cout << " " << wynik[i][j];
        if(j == c2-1)
            cout << endl;
    }

    return 0;
}