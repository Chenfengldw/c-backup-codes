#include<iostream>
using namespace std;

void quicksort(int arr[],int l,int r)
{
    int right,left,base;
    left=l;
    right=r;
    base=arr[(l+r)/2];
    while(left<right)
    {
        while(arr[left]<base) left++;
        while(arr[right]>base) right--;
        if(left<=right){//此处必须有=否则会无穷递归！！！！！！！！！！！！！
            int tmp;
            tmp=arr[left];
            arr[left]=arr[right];
            arr[right]=tmp;
            left++;
            right--;
        }
    }
    if(r>left) quicksort(arr,left,r);
    if(l<right) quicksort(arr,l,right);


}



int main()
{
    int M,S,C;
    cin>>M>>S>>C;
    int *stall_has_cow;
    stall_has_cow=new int[C];
    for(int i=0;i<C;++i) cin>>stall_has_cow[i];
    quicksort(stall_has_cow,0,C-1);
    int *gap;
    if(C>1)
    {
    gap=new int[C-1];
    for(int i=0;i<C-1;++i)
    {
        gap[i]=stall_has_cow[i+1]-stall_has_cow[i]-1;
    }
    quicksort(gap,0,C-2);
    }
    int totalLength=stall_has_cow[C-1]-stall_has_cow[0]+1;
    for(int i=0;i<M-1&&i<C-1;++i)
    {
        totalLength-=gap[C-2-i];
    }
    cout<<totalLength;
}
