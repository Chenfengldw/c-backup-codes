#include<iostream>
#include<cstring>
using namespace std;

template <class T>
class LinearList
{
    public:
        T *DataArray;
        int length;
        int maxSize;
        LinearList();
        void ReadAll();
        LinearList<T>& operator=(LinearList<T> a);
        LinearList<T> operator+(LinearList<T> &a);

};

template <class T>
LinearList<T>::LinearList()
{
    length=0;
    maxSize=100;
    DataArray=new T[maxSize];
}


template <class T>
LinearList<T>& LinearList<T>::operator=(LinearList<T> a)
{
 length=a.length;
 maxSize=a.maxSize;
 for(int i=0;i<length;++i) DataArray[i]=a.DataArray[i];
 return *this;
}

template <class T>
LinearList<T> LinearList<T>::operator+(LinearList<T> &a)
{
    int tmp;
    tmp=length;
    length+=a.length;
    maxSize+=a.maxSize;
    for(int i=0;i<a.length;++i) DataArray[i+tmp]=a.DataArray[i];
    return *this;
}


template <class T>
void LinearList<T>::ReadAll()
{
    for(int i=0;i<length;++i) cout<<DataArray[i]<<' ';
}




int main()
{
    char p[5];
    cin>>p;
    int n1,n2;
    cin>>n1>>n2;
    if(strcmp(p,"int")==0)
    {
        LinearList<int> L1,L2;
        L1.DataArray=new int[n1];
        L2.DataArray=new int[n2];
        L1.length=n1;
        L2.length=n2;
        for(int i=0;i<n1;++i) cin>>L1.DataArray[i];
        for(int i=0;i<n2;++i) cin>>L2.DataArray[i];

        (L1+L2).ReadAll();
    }
    if(strcmp(p,"char")==0)
    {
        LinearList<char> L1,L2;
        L1.DataArray=new char[n1];
        L2.DataArray=new char[n2];
        L1.length=n1;
        L2.length=n2;
        for(int i=0;i<n1;++i) cin>>L1.DataArray[i];
        for(int i=0;i<n2;++i) cin>>L2.DataArray[i];
        (L1+L2).ReadAll();
    }
    if(strcmp(p,"double")==0)
    {
        LinearList<double> L1,L2;
        L1.DataArray=new double[n1];
        L2.DataArray=new double[n2];
        L1.length=n1;
        L2.length=n2;
        for(int i=0;i<n1;++i) cin>>L1.DataArray[i];
        for(int i=0;i<n2;++i) cin>>L2.DataArray[i];
        (L1+L2).ReadAll();
    }




}
