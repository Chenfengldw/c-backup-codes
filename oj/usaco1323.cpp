#include<iostream>
#include<cstring>
using namespace std;

char *int_to_string(unsigned int x)
{
    unsigned int tmp1=x;
    char *tmp2;
    int bit=0;
    while((tmp1=tmp1/10)!=0) bit++;
    bit++;
    tmp2=new char[bit+1];
    tmp2[bit]='\0';
    for(int i=0;i<bit;++i)
    {
        tmp2[bit-1-i]=x%10+'0';
        x/=10;
    }
    return tmp2;
}
bool isRunRound(unsigned int x)
{
    int bit[10];
    for(int i=0;i<10;++i)bit[i]=0;
    char *number=int_to_string(x);
    bool *state;
    int numLen=strlen(number);
    for(int i=0;i<numLen;++i)
    {
        bit[number[i]-'0']++;
    }
    if(bit[0]!=0)return false;
    for(int i=0;i<10;++i)
    {
        if(bit[i]>1)return false;
    }
    state=new bool[numLen];
    for(int i=0;i<numLen;i++) state[i]=false;
    bool currentState=false;
    int currentPosition=0;
    while(currentState==false)
    {
     state[currentPosition]=true;
     currentPosition=(currentPosition+number[currentPosition]-'0')%numLen;
     currentState=state[currentPosition];

    }
    bool meetEach=true;
    for(int i=0;i<numLen;++i)
    {
        if(state[i]==false) meetEach=false;
    }
    if(currentPosition==0&&meetEach) return true;
    else return false;
}



int main()
{
    unsigned int M;
    cin>>M;
    M++;
    while(isRunRound(M)==false)M++;
    cout<<M<<endl;

}
