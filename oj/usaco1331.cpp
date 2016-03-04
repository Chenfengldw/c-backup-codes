#include<iostream>
#include<cstring>
using namespace std;


bool isPalindromes(const char *p)
{
    int length=strlen(p);
    int head=0,rear=length-1;
    while(p[head]==p[rear]&&rear-head>=1)
    {
        head++;
        rear--;
    }
    if(rear-head<=0)return true;
    else return false;
}



char *decimal_to_base(int x,int base)
{
    char bit;
    char *tmp,*result;
    result=new char[50];
    tmp=new char[50];
    for(int i=0;i<50;++i)tmp[i]='\0';
    int i=0;
    while(x!=0)
    {
        if(x%base==0)bit='0';
        if(x%base==1)bit='1';
        if(x%base==2)bit='2';
        if(x%base==3)bit='3';
        if(x%base==4)bit='4';
        if(x%base==5)bit='5';
        if(x%base==6)bit='6';
        if(x%base==7)bit='7';
        if(x%base==8)bit='8';
        if(x%base==9)bit='9';
        if(x%base==10)bit='A';
        if(x%base==11)bit='B';
        if(x%base==12)bit='C';
        if(x%base==13)bit='D';
        if(x%base==14)bit='E';
        if(x%base==15)bit='F';
        if(x%base==16)bit='G';
        if(x%base==17)bit='H';
        if(x%base==18)bit='I';
        if(x%base==19)bit='J';
       tmp[i]=bit;
       x/=base;
       i++;
    }

    int m=49;
    while(tmp[m]=='\0')m--;
    int j=0;
    for(;j<=m;++j)result[j]=tmp[m-j];
    result[j]='\0';
    return result;
}

int main()
{
    int B;
    cin>>B;

    for(int i=1;i<=300;++i)
    {
        char *tmp;
        tmp=decimal_to_base(i*i,B);
        if(isPalindromes(tmp))
           {
               cout<<decimal_to_base(i,B)<<' '<<tmp<<endl;
           }
    }


}
