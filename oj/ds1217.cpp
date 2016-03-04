#include<iostream>
using namespace std;

int main()
{
    int n,m;
    cin>>n;
    int *N;
    N=new int[n];
    for(int i=0;i<n;++i) cin>>N[i];
    cin>>m;
    for(int i=0;i<m;++i)
    {
        int tmp;
        bool flag=false;
        cin>>tmp;
        for(int i=0;i<n;++i)
        {
            if(N[i]==tmp)
            {
                cout<<'Y'<<endl;
                flag=true;
                break;
            }
        }
        if(!flag) cout<<'N'<<endl;

    }

}
