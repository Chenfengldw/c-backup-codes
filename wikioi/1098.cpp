#include<iostream>
using namespace  std;

int main()
{
    int n;
    cin>>n;
    int *p;
    p=new int[n];
    int sum=0,ave=0,result=0;
    for(int i=0;i<n;++i) {cin>>p[i];sum+=p[i];}
    ave=sum/n;
    for(int i=0;i<n-1;++i){
        if(p[i]!=ave){
                p[i+1]+=(p[i]-ave);
                p[i]=ave;
                result++;
        }
    }
    if(p[n]!=ave) result++;


    cout<<result-1;
    return 0;
}
