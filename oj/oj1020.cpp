#include<iostream>
using namespace std;

int main()
{
    long int figure,figure1,result[500]={0},index[500]={0};
    cin>>figure;
    figure1=figure;
    long int num=0,tmp=2;
    for(long int i=2;i<=figure;++i){
        if (figure1==figure) tmp=i;
        if (figure%i==0){
            if(tmp!=i) {num++;index[num]++;}
            else index[num]++;
            result[num]=i;
            tmp=i;
            figure/=i;
            i=1;
        }
    }
    cout<<figure1<<'=';
    for(int i=0;i<500;++i){
        if (result[i]==0) break;
        cout<<result[i]<<'('<<index[i]<<')';
    }
    return 0;
}
