#include<iostream>
#include<string.h>

using namespace std;

int main()
{
    char str1[10],str2[10];
    int i,j,d;
    cout << "Podaj slowo:"<<endl;
    gets(str1);
    d = strlen(str1)-1;
    for(i=d,j=0;i>=0;i--, j++)
        str2[j]=str1[i];
    if(strcmp(str1,str2)==0)
        cout << "Slowo jest palindromem!";
    else
        cout << "Slowo nie jest palindromem!";
    
    
    return 0;
}