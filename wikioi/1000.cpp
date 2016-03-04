#include <iostream>
using namespace std;
int main()
{
    double s=0,k,i=1;
    cin>>k;
    while(s<=k){
        s+=1/i;
        i++;
    }
    cout<<i-1;
    return 0;
}
