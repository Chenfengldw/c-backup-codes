#include <iostream>
using namespace std;

int main()
{
    long int N,M,*n,*m,cnt=0;
    bool flag=false;
    cin>>N>>M;
    n=new long int[N];
    m=new long int[M];
    for(int i=0;i<N;++i) cin>>n[i];
    for(int i=0;i<M;++i) cin>>m[i];
    for(int i=0;i<N;++i){
        long int tmp=0,index;
        flag=false;
        for(int j=0;j<M;++j){

            if (m[j]<n[i]) {
                    flag=true;
                    if(m[j]>tmp) {tmp=m[j];index=j;}
            }
        }

        if (flag) {cnt++;m[index]=10000000;}
    }
    cout<<cnt+N;


return 0;
}
