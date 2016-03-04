#include<iostream>
using namespace std;

int a[1000000];//fen zi
int b[1000000];//fen mu
double c[1000000];//magnitude


void quicksort(int a1[],int a2[],double arr[],int left,int right)
{
    int l=left;
    int r=right;
    double base=arr[(l+r)/2];
    while(l<=r)
    {
        while(arr[l]<base)l++;
        while(arr[r]>base)r--;
        if(l<=r)
        {
            double tmp;
            int tmp1,tmp2;
            tmp=arr[l];tmp1=a1[l];tmp2=a2[l];
            arr[l]=arr[r];
            a1[l]=a1[r];
            a2[l]=a2[r];
            arr[r]=tmp;
            a1[r]=tmp1;
            a2[r]=tmp2;

            l++;
            r--;
        }
    }

    if(l<right)quicksort(a1,a2,arr,l,right);
    if(left<r)quicksort(a1,a2,arr,left,r);
}

void print(int x,int y)
{
    int tmp1=x,tmp2=y;
    for(int i=x;i>=1;--i)
    {
        if(x%i==0&&y%i==0)
        {
            tmp1=x/i;
            tmp2=y/i;
            break;
        }
    }
    cout<<tmp1<<'/'<<tmp2<<endl;

}

int main()
{
    int n;
    cin>>n;

    int num=0;
    for(int i=1;i<=n;++i)
    {
        for(int j=0;j<=i;++j)
        {
            a[num]=j;
            b[num]=i;
            c[num]=double(j)/i;
            num++;
        }
    }

    quicksort(a,b,c,0,num-1);

    double before=0;
    cout<<0<<'/'<<1<<endl;
    for(int i=1;i<num;++i)
    {
        if(c[i]!=before) {print(a[i],b[i]);before=c[i];}
    }

}
