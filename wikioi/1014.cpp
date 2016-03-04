#include<iostream>
using namespace std;
int max1(int x,int y){
 return (x>y)?x:y;
}
int v(int a,int b,int *p){//这是问题的关键，注意与找零问题的区别，找零问题硬币可以重复使用，而背包（装箱）问题则不可以，因此递归方式不同
    if (b==0 ||a==0) return 0;
    else{
    if(p[a-1]>b) return v(a-1,b,p);//a是指前a个物品。p[a-1]是a的体积！！！
    if (p[a-1]<=b) return max1(v(a-1,b,p),v(a-1,b-p[a-1],p)+p[a-1]);
    }
}
int main()
{
    int V,n,*p;
    cin>>V>>n;
    p=new int[n];
    for(int i=0;i<n;++i) cin>>p[i];
    cout<<V-v(n,V,p);
    return 0;

}
