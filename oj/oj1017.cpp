#include<iostream>
using namespace std;
int a,b,c,N;
int rabbit(int N)
{
    int* num;
    num=new int[N+1];
    num[0]=1;
    num[1]=a;
    num[2]=a*a+b;
    num[3]=a*a*a+2*a*b+c;
    for(int i=4;i<=N;++i){
        for(int j=0;j<i-2;++j){
            num[i]+=c*num[j];
        }
        num[i]+=b*num[i-2];
        num[i]+=a*num[i-1];
    }
   int amount=0;
   for(int i=0;i<=N;++i) amount+=num[i];
   return amount;
}

int main()
{
    cin>>a;
    cin>>b;
    cin>>c;
    cin>>N;
    while (!(0<=a&&a<=b&&b<=c&&c<=100)||!(N>0&&N<=1000)){
        cin>>a;
        cin>>b;
        cin>>c;
        cin>>N;
    }

    if (N==1) cout<<a+1;
    if (N==2) cout<<a*a+a+b+1;
    if (N==3) cout<<a*a*a+a*a+2*b*a+a+b+c+1;
    if (N>3) cout<<rabbit(N);
    return 0;
}

