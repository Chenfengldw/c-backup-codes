#include <iostream>
using namespace std;

class priorityQueue
{
public:
    int currentSize;
    int *arr;

    priorityQueue()
    {
        arr=new int[10000];
        currentSize=0;
    }

    bool isEmpty()
    {
        return currentSize==0;
    }

    void percolateDown(int hole)
    {
        int child;
        int tmp=arr[hole];
        for(;hole*2<=currentSize;hole=child)
        {
            child=hole*2;
            if(hole*2+1<=currentSize)
            {
                if(arr[hole*2+1]<arr[hole*2])child++;
            }
            if(arr[child]<tmp)
            {
                arr[hole]=arr[child];
            }
            else break;
        }
        arr[hole]=tmp;

    }

    void enQueue(int x)
    {
        currentSize++;
        int hole=currentSize;
        for(;hole>1&&x<arr[hole/2];hole/=2)
        {
            arr[hole]=arr[hole/2];
        }
        arr[hole]=x;
    }

    int deQueue()
    {
        int minData=arr[1];
        arr[1]=arr[currentSize--];
        percolateDown(1);
        return minData;
    }
};




int main()
{
    int n;
    cin>>n;

    priorityQueue pQ;
    for(int i=0;i<n;++i)
    {
        int tmp;
        cin>>tmp;
        pQ.enQueue(tmp);
    }

    int total=0;
    int counter=0;
    while(counter<n-1)
    {
        int tmp1,tmp2;
        tmp1=pQ.deQueue();
        tmp2=pQ.deQueue();
        total=tmp1+tmp2+total;
        pQ.enQueue(tmp1+tmp2);
        counter++;
    }
    cout<<total;
}

