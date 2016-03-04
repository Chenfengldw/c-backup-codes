
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
        int toBeReturned;
        tmp=head->next;
        toBeReturned=tmp->data;
        if(head->next==rear)rear=head;
        head->next=tmp->next;

        delete tmp;
        return toBeReturned;
    }
    bool isEmpty()
    {
        return head==rear;
    }
};



