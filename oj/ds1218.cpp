#include<iostream>
#include<cstring>
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


class set
{
private:
    int *data;
    int maxSize;
    int currentSize;
    void doublespace()
    {
        int *tmp;
        tmp=new int[maxSize*2];
        for(int i=0;i<maxSize;i++) tmp[i]=data[i];
        delete [] data;
        data=tmp;
        maxSize*=2;
    }
public:
    set(int init=100){
        maxSize=init;
        data=new int[maxSize];
        currentSize=0;
    }
    ~set(){delete [] data;}

    void add(int x);
    void sub(int x);
    void merge(set &A);
    void subSet(set &A);
    void intersect(set &A);
    void out();
    void sort();
};

void set::sort()
{
    quicksort(data,0,currentSize-1);
}

void set::add(int x)
{

    data[currentSize]=x;
    currentSize++;

}

void set::sub(int x)
{
    for(int i=0;i<currentSize;++i)
    {
        if(data[i]==x)
        {
            for(int j=i;j<currentSize;++j) data[j]=data[j+1];
            currentSize--;
            break;
        }
    }
}


void set::merge(set &A)
{
     for(int i=0;i<A.currentSize;++i)
    {
        bool flag=false;
        for(int j=0;j<currentSize;++j)
        {
            if(A.data[i]==data[j])
            {
                flag=true;
            }
        }
        if(!flag)
        {
            add(A.data[i]);
        }
    }

}


void set::subSet(set &A)
{
    for(int i=0;i<currentSize;++i)
    {
        bool flag=false;
        for(int j=0;j<A.currentSize;++j)
        {
            if(data[i]==A.data[j])
            {
                flag=true;
            }
        }
        if(flag)
        {
            sub(data[i]);
            i--;
        }
    }

}

void set::intersect(set &A)
{

    for(int i=0;i<currentSize;++i)
    {
        bool flag=false;
        for(int j=0;j<A.currentSize;++j)
        {
            if(data[i]==A.data[j])
            {
                flag=true;
                break;
            }
        }
        if(!flag)
        {
            for(int k=i;k<currentSize;++k) data[k]=data[k+1];
            currentSize--;
            i--;
        }
    }


}

void set::out()
{
    if(currentSize==0) cout<<endl;
    else
    {
        for(int i=0;i<currentSize;i++)cout<<data[i]<<' ';
    }
}

int main()
{
    int n;
    char op[2];
    set test(100);
    cin>>n;
    for(int i=0;i<n;++i)
    {
        cin>>op;
        if(strcmp(op,"+")==0)
        {
            int m;
            cin>>m;
            set tmpSet;
            for(int j=0;j<m;++j)
            {
                int tmp;
                cin>>tmp;
                tmpSet.add(tmp);
            }
            test.merge(tmpSet);
            test.sort();
            test.out();

        }
        if(strcmp(op,"-")==0)
        {
            int m;
            cin>>m;
            for(int j=0;j<m;++j)
            {
                int tmp;
                cin>>tmp;
                test.sub(tmp);
            }
            test.sort();
            test.out();

        }
        if(strcmp(op,"*")==0)
        {
            int m;
            cin>>m;
            set tmpSet;
            for(int j=0;j<m;++j)
            {
                int tmp;
                cin>>tmp;
                tmpSet.add(tmp);
            }
            test.intersect(tmpSet);
            test.sort();
            test.out();
        }
    }
}


