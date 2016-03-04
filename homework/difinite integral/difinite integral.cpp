#include<iostream>
#include<cmath>
using namespace std;
double integral(double (*p)(double x),double x1,double x2){
    int n=(x2-x1)/0.01,i;double s=0,x;
    //cout<<n<<endl<<p(x2)<<endl;

    for (i=0;i<n;++i){
        x=x1+0.01*i;
        s+=p(x)*0.01;

    }
    return s;
}

int main()
{
    double x1,x2;
    cin>>x1>>x2;
    cout<<integral(sin,x1,x2);

    return 0;
}

