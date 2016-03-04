#include<iostream>
using namespace std;

long long int func(int i,int j)
{

    long long int  tmpsum;
    tmpsum=(i+1)*i/2;
    if (j==0||j==1||j==2) return 1;
    if(j<0) return 0;
    if(tmpsum<j) return 0;
    if(tmpsum==j) return 1;
    return func(i-1,j)+func(i-1,j-i);//O(2^n)!!!
}

int  main()
{
    long long int  n;
    cin>>n;
    long long int  sum;
    sum=(n+1)*n/2;
    if(sum%2!=0)cout<<0;
    else cout<<func(n,sum/2)/2;

}
