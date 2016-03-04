#include<iostream>
using namespace std;
double max1(double x,double y){
 return (x>y)?x:y;
}

double v(int a,double x,double *p,double *q){//这是问题的关键，注意与找零问题的区别，找零问题硬币可以重复使用，而背包（装箱）问题则不可以，因此递归方式不同
    if (x==0 ||a==0) return 0;
    else{
    if(p[a-1]>x) return v(a-1,x,p,q);//a是指前a个物品。p[a-1]是a的体积！！！
    if (p[a-1]<=x) return max1(v(a-1,x,p,q),v(a-1,x-p[a-1],p,q)+q[a-1]);
    }
}
int main()
{
    int n,k,*r,*s;
    double x;
    double *p,*q;
    cin>>n>>k>>x;
    p=new double[n];
    q=new double[n];
    r=new int[n];
    s=new int[k];
    for (int i=0;i<n;++i) cin>>p[i];
    for (int i=0;i<n;++i) cin>>q[i];
    for (int i=0;i<n;++i) cin>>r[i];
    for (int i=0;i<k;++i) cin>>s[i];
     double mustmoney=0,yummy=0;
    for (int i=0;i<k;++i){
      for (int j=0;j<n;++j){
            if (r[j]==s[i]){
                mustmoney+=p[j];
                yummy+=q[j];
                break;
            }
    }
    }
    int num=0;
    for (int i=0;i<k;++i){
        for (int j=0;j<n;++j){
            if (r[j]==s[i]){
                p[j]=-1;
                q[j]=-1;
                num++;
            }
        }

    }
    double *p1,*q1;
    p1=new double[n-num];
    q1=new double[n-num];
    int aaa=0,*alreadyin;
    alreadyin=new int[n];
    for (int i=0;i<n;++i) alreadyin[i]=0;
    for (int i=0;i<n;++i){
        bool in;
        in=false;
        for(int j=0;j<n;++j) {if (r[i]==alreadyin[j]) in=true;}
        if (p[i]!=-1&&in==false) {p1[aaa]=p[i];q1[aaa]=q[i] ;alreadyin[aaa]=r[i];++aaa;}
    }
    int code;
    bool flag=true;

    cout<<v(aaa,x-mustmoney,p1,q1)+yummy;











}
