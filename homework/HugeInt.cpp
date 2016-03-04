#include <iostream>
#include <cstring>
using namespace std;

class HugeInt{
    friend ostream & operator<<(ostream & os,const HugeInt &obj);
private:
    int storage[30];
public:
    HugeInt(const char *str);
    HugeInt operator+(const HugeInt &a) const;

}
HugeInt::HugeInt(const char *str)
{
    int i=0;
    for (i=0;i<30;++i) storage[i]=0;
    for (i=strlen(str)-1;i>=0;--i){
             if (str[i]!=0) storage[29-(strlen(str)-1-i)]=str[i];
                else break;
    }
}

HugeInt HugeInt::operator+(const HugeInt &a) const
{
    int i=0;int jinwei=0; HugeInt tmp;
    for(i=29;i>=0;--i){
        tmp.storage[i]=(storage[i]+a.storage[i])%10+jinwei;
        if(storage[i]+a.storage[i]+jinwei>=10) jinwei=(storage[i]+a.storage[i]+jinwei)/10;
            else jinwei=0;
        if (i==0 && jinwei!=0) {cout<<"³¬³ö·¶Î§£¡"<<endl;return HugeInt("0");}
            else return tmp;
    }
}

ostream & operator<<(ostream & os,const HugeInt &obj)
{
    int i=0;
    while(obj.storage[i]==0){
        ++i;
    }
    for(;i<30;++i) os<<obj.storage[i];
    return os;
}


