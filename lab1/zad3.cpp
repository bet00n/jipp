#include<iostream>
using namespace std;
double bmiWzor (double masa_ciala, double wzrost)
{
    return(masa_ciala/(wzrost * wzrost)*10000);
}
int main(int argc, char *argv[])
{
    int masa_ciala, wzrost;
    cout << "Twoja masa ciala:";
    cin >> masa_ciala;
    cout <<"Twoj wzrost:";
    cin >> wzrost;
    double bmi = bmiWzor(masa_ciala, wzrost);
    cout << "Twoje bmi wynosi:" << bmi << endl;
    if (bmi<16) 
        cout << "wyglodzenie";
    else if (bmi>=16 && bmi<17)
        cout << "wychudzenie";
    else if (bmi>=17 && bmi<18.5)
        cout << "niedowaga";
    else if (bmi>=18.5 && bmi<25)
        cout << "wartosc prawidlowa";
    else if (bmi>=25 && bmi<30)
        cout << "nadwaga";
    else if (bmi>=30 && bmi<35)
        cout << "I stopien otylosci";
    else if (bmi>=35 && bmi<40)
        cout << "II stopien otylosci";
    else if (bmi>=40)
        cout << "skrajna otylosc";
                        
    return 0;
}