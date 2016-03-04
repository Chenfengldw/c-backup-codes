#include<iostream>
#include<cstring>
#include <queue>
#include<cmath>
using namespace std;

int nodeNum=1;

template<class T>
class Node
{
        public:
            T data;
            int id;
            Node *son,*brother;

            Node(T tmpdata,Node *ls=NULL,Node *rb=NULL)
            {
                id=num;
                num++;
                data=tmpdata;
                son=ls;
                brother=rb;
            }

            Node(){son=NULL;brother=NULL;}
};


template<class T>
class Binomial
{

private:
    Node<T> ** forest;
    int scale;

    Node<T> * merge(Node<T> * t1,Node<T> * t2);
    int findMin();
    void deleteTree(Node<T> *rt)
    {
        Node<T> *son,*t;
        son=rt->son;
        while(son!=NULL)
        {
            t=son;son=son->brother;
            deleteTree(t);
        }
        delete rt;
    }

public:
    Binomial(int n=100)
             {
                 scale=int(log(n)/log(2))+1;
                 forest=new Node<T> *[scale];  //创建一个Binomial后其实forest里边只有scale个指针，并没有实际节点
                 for(int i=0;i<scale;++i) forest[i]=NULL;
             }

    ~Binomial()
    {
        for(int i=0;i<scale;++i)
        {
            if(forest[i]!=NULL) deleteTree(forest[i]);
        }
        delete [] forest;
    }

    void merge(Binomial &other);
    Node<T> *enQueue(T x);
    T deQueue();
    bool isEmpty();
    T getHead();
    void printMin(){cout<<forest[findMin()]->data<<endl;}
    int printMinId();
};

template<class T>
void Binomial<T>::merge(Binomial &other)
{
    Node<T> **tmp=forest,*carry;
    int tmpSize=scale;
    int min=scale<other.scale?scale:other.scale;
    int i;

    if (scale<other.scale)
    {
        scale=other.scale;
        if(other.forest[scale-1]!=NULL)++scale;
    }
    else if(forest[scale-1]!=NULL) ++scale;

    forest=new Node<T> *[scale];
    for(i=0;i<scale;++i)forest[i]=NULL;

    carry=NULL;

    for(i=0;i<min;++i)
    {
        if(carry==NULL)
        {
            if(tmp[i]==NULL) forest[i]=other.forest[i];
            else
            {
               if(other.forest[i]==NULL) forest[i]=tmp[i];
               else carry=merge(tmp[i],other.forest[i]);
            }

        }
        else
        {
            if (tmp[i]==NULL&&other.forest[i]==NULL) forest[i]=carry;
            else
            {
                if(tmp[i]!=NULL&&other.forest[i]!=NULL)
                {
                    forest[i]=carry;
                    carry=merge(tmp[i],other.forest[i]);

                }
                else
                {
                    if(tmp[i]==NULL) carry=merge(other.forest[i],carry);
                    else carry=merge(tmp[i],carry);
                }
            }
        }
    }



    if (other.scale==min)
    {
        for(;i<tmpSize;++i)
        {
            if(carry==NULL)forest[i]=tmp[i];
            else
            {
                if(tmp[i]==NULL){forest[i]=carry;carry=NULL;}
                else carry=merge(tmp[i],carry);

            }
        }
    }
    else
    {
       for(;i<other.scale;++i)
        {
            if(carry==NULL)forest[i]=other.forest[i];
            else
            {
                if(other.forest[i]==NULL){forest[i]=carry;carry=NULL;}
                else carry=merge(other.forest[i],carry);

            }
        }
    }
    if(carry!=NULL)forest[i]=carry;

    for(i=0;i<other.scale;++i)other.forest[i]=NULL;
    delete [] tmp;
}

template<class T>
Node<T> * Binomial<T>::merge(Node<T> * t1,Node<T> * t2)
{
    Node<T> * big,*small;
    if(t1->data<t2->data) {small=t1;big=t2;}
    else{small=t2;big=t1;}

    if(small->son==NULL) small->son=big;
    else{
        Node<T> *tmp=small->son;
        while(tmp->brother!=NULL)tmp=tmp->brother;
        tmp->brother=big;
    }
    return small;
}

template<class T>
Node<T>* Binomial<T>::enQueue(T x)
{
    Binomial tmp(1);
    tmp.forest[0]=new Node<T>(x);
    merge(tmp);
    return tmp.forest[0];
}

template<class T>
T Binomial<T>::deQueue()
{
    T minValue;
    int min=findMin();

    if(min==0)
    {
        minValue=forest[0]->data;
        delete forest[0];
        forest[0]=NULL; //do not forget to reset this to NULL
        return minValue;
    }
    else
    {
        Node<T> *t=forest[min],*son,*brother;
        int subTreeNode=pow(double(2),double(min))-1;
        Binomial tmp=(subTreeNode);
        minValue=t->data;
        forest[min]=NULL;

        son=t->son;
        delete t;
        int i=0;

        do{
            tmp.forest[i++]=son;
            brother=son->brother;
            son->brother=NULL;
        }while((son=brother)!=NULL);

        merge(tmp);
        return minValue;
    }
}

template<class T>
int Binomial<T>::findMin()
{
    int min;
    int i;
    for(i=0;i<scale&&forest[i]==NULL;++i);
    min=i;
    for(;i<scale;++i)
    {
        if (forest[i]!=NULL&&forest[i]->data<forest[min]->data) min=i;
    }


    return min;
}

template<class T>
int Binomial<T>::printMinId()
{
    cout<<forest[findMin()]->id;
}





int main()
{
    Node<int> **allNodes;
    int M;
    Binomial<int> test(1);
    char op[10];
    cin>>M;
    allNodes=new Node<int> *[M];
    int nodeCounter=0;
    for(int i=0;i<M;++i)
    {
        cin>>op;
        if(strcmp(op,"insert")==0){
            int x;
            cin>>x;
            nodeCounter++;
            allNodes[nodeCounter]=test.enQueue(x);

        }
        if(strcmp(op,"find")==0){

        }
        if(strcmp(op,"decrease")==0)
        {
            int a,b;
            cin>>a>>b;
            allNodes[a]->data-=b;
        }
    }
}
