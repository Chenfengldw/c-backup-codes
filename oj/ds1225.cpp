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
        if(left<=right){//此处必须有=否则会无穷递归！！！！！！！！！！！！！11
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
    int n;
    cin>>n;
    int *arr;
    arr=new int[n];
    for(int i=0;i<n;++i)cin>>arr[i];
    quicksort(arr,0,n-1);
    int counter=1;
    int tmp=arr[0];
    for(int i=1;i<n;++i)
    {
        if(arr[i]!=tmp)
        {
            tmp=arr[i];
            counter++;
        }
    }
    cout<<counter;
}
