#include<iostream>
#include <queue>
using namespace std;


template <class T>
class BinaryTree
{
private:
    struct Node
    {
        Node *left,*right;
        T data;
        int judge_root;
        Node():left(NULL),right(NULL),judge_root(0){}
        Node(T value,Node *L=NULL,Node *R=NULL):left(L),right(R),data(value){}


    };
    Node *root;

public:
    BinaryTree(){root=NULL;}
    BinaryTree(T value){root=new Node(value);}



    T getroot(){return root->data;}
    T getleft(){return root->left->data;}
    T getright(){return root->right->data;}

    struct elem
    {
        Node *p;
        int num;
    };

    void createTree();


    void makeTree(T x,BinaryTree &lt,BinaryTree &rt)
    {
        root=new Node(x,lt.root,rt.root);
        lt.root=NULL;
        rt.root=NULL;
    }

    void delLeft()
    {
        BinaryTree tmp=root->left;
        root->left=NULL;
        tmp.clear();
    }

    void delRight()
    {
        BinaryTree tmp=root->right;
        root->right=NULL;
        tmp.clear();
    }

    bool isEmpty()
    {
        return root==NULL;
    }

   /*void clear()
    {
        if (root!=NULL)
        {
            clear(root->left);
            clear(root->right);
            delete *root;
        }
        else return;
    }

    void clear(Node *tmp)
    {
        if (tmp!=NULL)
        {
            clear(tmp->left);
            clear(tmp->right);
            delete *tmp;
        }
        else return;
    }
*/


    int height(Node *t)
    {
        if(t==NULL) return 0;
        else{
            int lt=height(t->left);
            int rt=height(t->right);
            return 1+((lt>rt)?lt:rt);
        }
    }

    void preOrder()
    {
         if (root!=NULL)
         {
             cout<<root->data<<' ';
             preOrder(root->left);
             preOrder(root->right);
         }
    }

    void preOrder(Node *t)
    {
         if (t!=NULL)
         {
             cout<<t->data<<' ';
             preOrder(t->left);
             preOrder(t->right);
         }
    }

    void midOrder()
    {
         if (root!=NULL)
         {
             midOrder(root->left);
             cout<<root->data<<' ';
             midOrder(root->right);
         }
    }

    void midOrder(Node *t)
    {
         if (t!=NULL)
         {
             midOrder(t->left);
             cout<<t->data<<' ';
             midOrder(t->right);
         }
    }

    void postOrder()
    {
         if (root!=NULL)
         {
             postOrder(root->left);
             postOrder(root->right);
             cout<<root->data<<' ';

         }
    }

    void postOrder(Node *t)
    {
         if (t!=NULL)
         {
             postOrder(t->left);
             postOrder(t->right);
             cout<<t->data<<' ';

         }
    }

    void depthTraverse();

    bool isCBT();




};


template <class T>
void BinaryTree<T>::createTree()
{
    int num_of_node;
        cin>>num_of_node;
        Node* tree;
        tree=new Node[num_of_node+1];
        for(int i=1;i<=num_of_node;++i)
        {
            tree[i].judge_root=1;
        }
        for(int i1=1;i1<=num_of_node;++i1)
        {
            int inleft,inright,selfData;
            cin>>inleft>>inright>>selfData;
            tree[i1].data=selfData;
            if(inleft!=0){tree[i1].left=&tree[inleft];tree[inleft].judge_root=0;}
            if(inright!=0){tree[i1].right=&tree[inright];tree[inright].judge_root=0;}
        }
        for(int i2=1;i2<=num_of_node;++i2)
        {
            if(tree[i2].judge_root==1){root=&tree[i2];break;}
        }
}

template <class T>
void BinaryTree<T>::depthTraverse()
    {
        queue<Node *> que;
        Node *current;

        if (root==NULL) return;

        que.push(root);

        while(!que.empty())
        {
            current=que.front();
            que.pop();
            if(current->left!=NULL) que.push(current->left);
            if(current->right!=NULL) que.push(current->right);
            cout<<current->data<<' ';
        }
    }

template <class T>
bool BinaryTree<T>::isCBT()
{
    queue<elem> que;
    elem current,child;
    int count=1;
    int last=1;

    if (root==NULL) return true;
    current.p=root;
    current.num=1;
    que.push(current);
    while(!que.empty())
    {
        current=que.front();
        que.pop();
        if(current.p->left!=NULL)
        {
            ++count;
            child.p=current.p->left;
            last=child.num=current.num*2;
            que.push(child);
        }
        if(current.p->right!=NULL)
        {
            ++count;
            child.p=current.p->right;
            last=child.num=current.num*2+1;
            que.push(child);
        }
    }

    return count==last;
}



int main()
{
    BinaryTree<int> test;
    test.createTree();
    test.depthTraverse();

}

