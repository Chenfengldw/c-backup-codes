#include<iostream>
using namespace std;
int max1(int x,int y){
 return (x>y)?x:y;
}
int v(int a,int b,int *p){//��������Ĺؼ���ע�������������������������Ӳ�ҿ����ظ�ʹ�ã���������װ�䣩�����򲻿��ԣ���˵ݹ鷽ʽ��ͬ
    if (b==0 ||a==0) return 0;
    else{
    if(p[a-1]>b) return v(a-1,b,p);//a��ָǰa����Ʒ��p[a-1]��a�����������
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
