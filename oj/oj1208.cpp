#include<iostream>
#include<math.h>
#define pi 3.1415926
using namespace std;

double area(double r,double a);
int main()
{
    double arr[1000]={0};
    int i=0;
    double a,b;
    while(cin>>a>>b){
        arr[i]=a;
        arr[i+1]=b;
        i+=2;
    }
    double tmp=0;
    for(int j=0;j<i;j+=2){
        double a,r;
        r=arr[j];
        a=arr[j+1];
        if ((((2*acos(a/r))/(2*pi))*pi*r*r)-a*sin(acos(a/r))*r>=tmp) tmp=(((2*acos(a/r))/(2*pi))*pi*r*r)-a*sin(acos(a/r))*r;
    }
    if(tmp*100-int(tmp*100)>=0.5) cout<<(int(tmp*100)+1)/100.0;
    else cout<<int(tmp*100)/100.0;
    return 0;
    }
