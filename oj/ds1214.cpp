#include<iostream>
using namespace std;


int n;

struct Node
{
    int data;
    Node *next;

    Node()
    {
        next=NULL;
    }
};


class Queue
{
public:
    Node *head;
    Node *rear;

    Queue()
    {
        head=new Node;
        rear=head;
    }

    void enQueue(int x)
    {
        Node *tmp;
        tmp=new Node;
        tmp->data=x;

        rear->next=tmp;
        rear=tmp;
    }

    int deQueue()
    {
        if(isEmpty())
        {
            return -1;
        }
        Node *tmp;
        tmp=head->next;
        int x=tmp->data;

        if(head->next==rear)rear=head;
        head->next=tmp->next;

        delete tmp;
        return x;

    }

    bool isEmpty()
    {
        return head==rear;
    }


};

struct treeNode
{
    treeNode *son;
    treeNode *brother;
    int ID;

    int weight;

    treeNode()
    {
        son=NULL;
        brother=NULL;
    }

};



class tree
{
public:
    treeNode *root;
    treeNode *treeArr;
    int rootID;

    tree();


    void preOrder()
    {
        preOrder(root);
    }
    void preOrder(treeNode *r)
    {
        if(r==NULL)return;//**********************************************
        cout<<r->weight<<' ';

        treeNode *tmp;
        tmp=r->son;
        while(tmp!=NULL)
        {
            preOrder(tmp);
            tmp=tmp->brother;
        }
    }

    void postOrder()
    {
        postOrder(root);
    }
    void postOrder(treeNode *r)
    {
        if(r==NULL) return;  //*************************************

        treeNode *tmp;
        tmp=r->son;
        while(tmp!=NULL)
        {
            postOrder(tmp);
            tmp=tmp->brother;
        }
        cout<<r->weight<<' ';
    }


    void depthOrder();



};


tree::tree()
{
    int n;
    cin>>n;

    bool *isRoot=new bool[n+1];
    for(int i=1;i<=n;++i) isRoot[i]=true;

    treeArr=new treeNode[n+1];
    for(int i=1;i<=n;++i)treeArr[i].ID=i;

    int p,q,v;
    for(int i=1;i<=n;++i)
    {
        cin>>p>>q>>v;

        if(p!=0)treeArr[i].son=&treeArr[p];
        else treeArr[i].son=NULL;

        if(q!=0)treeArr[i].brother=&treeArr[q];
        else treeArr[i].brother=NULL;

        treeArr[i].weight=v;
        isRoot[p]=false;
        isRoot[q]=false;

    }

    for(int i=1;i<=n;++i)
    {
        if(isRoot[i])
        {
            rootID=i;
            break;
        }
    }
    root=&treeArr[rootID];
}

void tree::depthOrder()
{
    Queue q;
    q.enQueue(rootID);
    if(root==NULL)return;
    int cnt;
    treeNode *tmp;
    while(!q.isEmpty())
    {
        cnt=q.deQueue();
        cout<<treeArr[cnt].weight<<' ';
        tmp=treeArr[cnt].son;
        while(tmp!=NULL)
        {
            q.enQueue(tmp->ID);
            tmp=tmp->brother;
        }

    }

}


int main()
{
    tree test;
    test.preOrder();
    cout<<endl;
    test.postOrder();
    cout<<endl;
    test.depthOrder();

    return 0;
}
