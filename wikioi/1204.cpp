#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    char a[200],b[200];
    cin>>a;
    cin>>b;
    int alen,blen,start=0;
    alen=strlen(a);
    blen=strlen(b);
    for(int i=0;i<alen-blen+1;++i)
    {   bool flag=true;
        for(int j=0;j<blen;++j)
        {
            if (b[j]!=a[i+j]) {flag=false;break;}
        }
        if (flag==true) {start=i+1;break;}
    }
    cout<<start;
    return 0;
}
