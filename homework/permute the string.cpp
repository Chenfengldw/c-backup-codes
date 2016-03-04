#include <iostream>
#include <cstring>
using namespace std;
void swap(char str[],int k,int i);
void PermuteWithFixedPrefix(char str[],int k)
{
    int i;
    if (k == strlen(str)) cout << str <<endl;
    else for (i=k;i<strlen(str);++i){
        swap(str,k,i);
        PermuteWithFixedPrefix(str,k+1);
        swap(str,k,i);
    }
}
void swap(char str[],int k,int i)
{
    int tmp;
    tmp =str[k];
    str[k]=str[i];
    str[i]=tmp;
}

int main()
{
    char str[50];
    PermuteWithFixedPrefix(str,0);
    return 0;
}
