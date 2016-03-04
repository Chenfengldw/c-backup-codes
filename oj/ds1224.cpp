#include<iostream>
using namespace std;

class hashTable
{
private:
    struct Node
    {
        int data;
        int state;
    };
    Node *arr;

public:
    hashTable()
    {
        arr=new Node[500001];
        for(int i=0;i<500001;++i) arr[i].state=0;
    }
    ~hashTable()
    {
        delete [] arr;
    };
    int find(int x)
    {
        int index=(x+1000000)/4;
        for(int i=0;arr[(i+index)%500001].state!=0;++i)
        {
            if(arr[(i+index)%500001].data==x) return arr[(i+index)%500001].state;
        }
        return 0;
    }
    void insert(int x)
    {
        int index;
        for(index=(x+1000000)/4;arr[index%500001].state!=0&&arr[index%500001].data!=x;++index){}
        if(arr[index%500001].state==0)
        {
            arr[index%500001].data=x;
            arr[index%500001].state++;
        }
        else arr[index%500001].state++;


    }
    int getData(int index)
    {
        return arr[index].data;
    }
    int getState(int index)
    {
        return arr[index].state;
    }

};

int main()
{
    hashTable T1,T2;
    int A[500],B[500],C[500],D[500];
    int n;
    cin>>n;
    for(int i=0;i<n;++i)
    {
        cin>>A[i]>>B[i]>>C[i]>>D[i];
    }
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<n;++j)
        {
            T1.insert(A[i]+B[j]);
            T2.insert(-C[i]-D[j]);
        }
    }
    int counter=0;
    for(int i=0;i<500001;++i)
    {
        //if(T2.getData(i)!=0)cout<<T2.getData(i);
        counter+=(T1.find(T2.getData(i)))*T2.getState(i);
    }
    cout<<counter;
}
