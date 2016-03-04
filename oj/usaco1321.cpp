#include<iostream>
using namespace std;

class dyArray
{

public:
    int *storage;
    int currentSize;
    int maxSize;


    dyArray(){maxSize=100;currentSize=0;storage=new int[maxSize];}
    ~dyArray(){delete [] storage;}
    void doublespace()
    {
        int *tmp,*tmp2;
        tmp=new int[maxSize*2];
        for(int i=0;i<currentSize;++i)tmp[i]=storage[i];
        tmp2=storage;
        delete tmp2;
        storage=tmp;
    }

    void push(int x)
    {
        storage[currentSize++]=x;
    }
};


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


bool isPrime(int x)
{
    if(x%2==0) return false;
    for(int i=3;i<x;i+=2)
    {
        if (x%i==0) return false;
    }
    return true;

}



int main()
{
    int n;
    cin>>n;
    dyArray *p;
    p=new dyArray[n];
    p[0].push(2);
    p[0].push(3);
    p[0].push(5);
    p[0].push(7);
    if(n==1)
    {
        cout<<2<<endl<<3<<endl<<5<<endl<<7<<endl;
    }
    else
    {
        for(int i=1;i<n;++i)
        {
            for(int j=0;j<p[i-1].currentSize;j++)
            {
                if(isPrime(p[i-1].storage[j]*10+1)) p[i].push(p[i-1].storage[j]*10+1);
                if(isPrime(p[i-1].storage[j]*10+3)) p[i].push(p[i-1].storage[j]*10+3);
                if(isPrime(p[i-1].storage[j]*10+7)) p[i].push(p[i-1].storage[j]*10+7);
                if(isPrime(p[i-1].storage[j]*10+9)) p[i].push(p[i-1].storage[j]*10+9);
            }
        }
    }
   quicksort(p[n-1].storage,0,p[n-1].currentSize-1);
   for(int k=0;k<p[n-1].currentSize;++k)
   {
       cout<<p[n-1].storage[k]<<endl;
   }

}
