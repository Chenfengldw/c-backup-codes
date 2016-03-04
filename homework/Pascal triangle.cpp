#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
   int n,i,j,k,m,p;
   cout<<"please enter the scale"<<endl;
   cin>>n;
   const int scale=n;
   int a[scale][2*scale-1];
   for (j=0;j<2*scale-1;++j){
           if (j!=scale-1) a[0][j]=0;
           else a[0][j]=1;

       }

   for (i=1;i<scale;++i){

       if (i!=scale-1){
            a[i][0]=a[i][2*scale-1]=0;
            for (k=1;k<2*scale-1;++k){
                 a[i][k]=a[i-1][k-1]+a[i-1][k+1];
            }
       }

       else{
           a[scale-1][0]=a[scale-1][2*scale-2]=1;
           for (k=1;k<2*scale-2;++k){
                a[i][k]=a[i-1][k-1]+a[i-1][k+1];
           }
       }
   }

   for (m=0;m<scale;++m){
       for(p=0;p<2*scale-1;++p){
           if (a[m][p]==0) cout<<"   ";
           else cout<<setw(3)<<a[m][p];
       }
           cout<<endl;
   }

 return 0;






}
