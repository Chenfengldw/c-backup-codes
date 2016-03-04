#include<iostream>
using namespace std;

struct tNode
{
    int left;
    int right;
};

struct Node
{
    int data;
    Node *next;

    Node(){next=NULL;}
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
        if(isEmpty())return -1;
        Node *tmp;
        tmp=head->next;
        int x;
        x=tmp->data;
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




int main()
{
    int n;
    cin>>n;
    tNode *tree;
    tree=new tNode[n+1];
    bool *isRoot = new bool[n+1];
    for(int i=1;i<=n;++i)
    {
        isRoot[i]=true;
    }
    for(int i=1;i<=n;++i)
    {
        int l,r;
        cin>>l>>r;
        tree[i].left=l;
        tree[i].right=r;
        isRoot[l]=false;
        isRoot[r]=false;

    }

    int root;
    for(int i=1;i<=n;++i)
    {
        if(isRoot[i])
        {
            root=i;
            break;
        }
    }

    Queue q;
    q.enQueue(root);
    int last=1,counter=0,child=root;
    while(!q.isEmpty())
    {
        int cnt;
        cnt=q.deQueue();
        counter++;
        if(tree[cnt].left!=0)
        {
            last=2*counter;

            child=tree[cnt].left;
            q.enQueue(child);

        }
        if(tree[cnt].right!=0)
        {
            last=2*counter+1;

            child=tree[cnt].right;
            q.enQueue(child);
        }
    }

    if(last==n)cout<<"Y";
    else cout<<"N";

    return 0;
}
