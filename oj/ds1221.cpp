#include<iostream>
#include<cstring>
using namespace std;
int number[5005];

class binary_search_tree
{
private:
    struct binary_node
    {
        int data;
        binary_node *left;
        binary_node *right;
        binary_node(const int &the_data,binary_node *lt,binary_node *rt)
        {
            data=the_data;
            left=lt;
            right=rt;
        }
    };

public:
    binary_search_tree(binary_node *t=NULL){root=t;}
    ~binary_search_tree(){make_empty(root);}
    bool find(const int &x)const {return find(x,root);}
    void insert(const int &x){insert(x,root);}
    void remove(const int &x){remove(x,root);}
    void del_less(const int x){del_less(x,root);}
    void del_great(const int x){del_great(x,root);}
    void del_range(int x,int y){del_range(x,y,root);}
    void mid_order(){for(int i=0;i<5000;i++) number[i]=100000000;int j=0;mid_order(j,root);}
    int find_ith(int x)
    {
        if (x<=0||x>5000) return 100000000;
        int j=0;
        mid_order();
        return number[x-1];
    }

private:
    binary_node *root;
    void insert(const int &x,binary_node *&t)
    {
        if(t==NULL){t=new binary_node(x,NULL,NULL);}
        else if(x<t->data){insert(x,t->left);}
             else if(t->data<=x){insert(x,t->right);}//
    }

    void remove(const int &x,binary_node *&t)
    {
        if(t==NULL){return;}//return 0;
        if(x<t->data){remove(x,t->left);}
        else if(t->data<x)remove(x,t->right);
             else if(t->left!=NULL&&t->right!=NULL)
                 {
                     binary_node *tmp=t->right;
                     while(tmp->left!=NULL)tmp=tmp->left;
                     t->data=tmp->data;
                     remove(t->data,t->right);
                 }
                 else
                 {
                     binary_node *old_node=t;
                     t=(t->left!=NULL)?t->left:t->right;
                     delete old_node;
                 }
    }

    bool find(const int &x,binary_node *t)const
    {
        if(t==NULL){return false;}
        else if(x<t->data){return find(x,t->left);}
             else if(t->data<x){return find(x,t->right);}
                  else {return true;}
    }


    void make_empty(binary_node *&t)
    {
        if(t!=NULL)
        {
            make_empty(t->left);
            make_empty(t->right);
        }
        delete t;
    }

    void del_less(const int x,binary_node *&t)
    {
        if(t==NULL)return;
        if(t->data<x)
        {
            binary_node *tmp=t;
            t=t->right;
            make_empty(tmp->left);
            delete tmp;
            del_less(x,t);
        }
        else del_less(x,t->left);
    }

    void del_great(const int x,binary_node *&t)
    {
        if(t==NULL)return;
        if(t->data>x)
        {
            binary_node *tmp=t;
            t=t->left;
            make_empty(tmp->right);
            delete tmp;
            del_great(x,t);
        }
        else del_great(x,t->right);
    }

    void del_range(int x,int y,binary_node *&t)
    {
        if(t==NULL)return;
        if(t->data<=x)del_range(x,y,t->right);//
        else if(t->data>=y)del_range(x,y,t->left);
             else
             {
                 remove(t->data,t);
                 del_range(x,y,t);
             }
    }

    void mid_order(int &j,binary_node *&t)
   {
       if(t==NULL)return;
       mid_order(j,t->left);
       number[j]=t->data;j++;
       mid_order(j,t->right);
   }

};

binary_search_tree test;
int main()
{
    int n,tmp,tmp2,val;
    char order[25];
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>order;

        if(strcmp(order,"insert")==0)
        {
            cin>>tmp;
            test.insert(tmp);
        }

        if(strcmp(order,"delete")==0)
        {
            cin>>tmp;
            test.remove(tmp);
            //cout<<test.dequeue()<<endl;
        }
        if(strcmp(order,"find")==0)
        {
            cin>>tmp;
            if(test.find(tmp)){cout<<"Y"<<endl;}
            else{cout<<"N"<<endl;}
        }
        //cout<<"233"<<endl;
        if(strcmp(order,"delete_less_than")==0)
        {
            cin>>tmp;
            test.del_less(tmp);
        }
        if(strcmp(order,"delete_greater_than")==0)
        {
            cin>>tmp;
            test.del_great(tmp);
        }

        if(strcmp(order,"delete_interval")==0)
        {
            cin>>tmp>>tmp2;
            test.del_range(tmp,tmp2);
        }

        if(strcmp(order,"find_ith")==0)
        {
            cin>>tmp;
            if(test.find_ith(tmp)>=10000000){cout<<"N"<<endl;}
            else{cout<<test.find_ith(tmp)<<endl;}
        }

    }
    return 0;
}
