#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int n,*p;
    cin>>n;
    p=new int[n];
    for(int i=0;i<n;++i) cin>>p[i];
    sort(p,p+n);
    for(int i=0;i<n;++i) cout<<p[i]<<' ';
    return 0;
}
