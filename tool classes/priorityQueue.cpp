#include <iostream>
using namespace std;

class priorityQueue//minimum
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
                if(arr[hole*2+1]>arr[hole*2])child++;
            }
            if(arr[child]>tmp)
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
        for(;hole>1&&x>arr[hole/2];hole/=2)
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

        cout<<minData;
        return minData;
    }
};



int main()
{
    priorityQueue pQ;
    pQ.enQueue(3);
    pQ.enQueue(1);
    pQ.enQueue(2);
    pQ.deQueue();
    pQ.deQueue();
    pQ.deQueue();


}
