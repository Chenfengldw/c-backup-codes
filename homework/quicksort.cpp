#include <iostream>
using namespace std;

int divide(int a[],int low,int high);
void quicksort(int a[],int low,int high)
{  int mid;

    if (low>=high) return;
    mid = divide(a,low,high);
    quicksort(a,low,mid-1);
    quicksort(a,mid+1,high);
}
int divide( int a[],int low,int high)
{  int k =a [low];

    do{while (low<high && a[high]>=k) --high;;
       if (low<high) {a[low]=a[high];++low;}
       while (low<high &&a[low]<=k) ++low;
       if (low<high) {a[high]=a[low];--high;}
    }while(low != high);
    a[low]=k;

    return low;
}


int main()
{   int *p;
    p= new int[10];
    void quicksort(int a[],int low,int high);

    return 0;
}
