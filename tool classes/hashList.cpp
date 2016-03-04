#define INF 20000000
class hashList
{
public:
    struct hashNode
    {
        int data;
        int state;

        hashNode()
        {
            state=0;
            data=INF;
        }
    };

    hashNode *arr;

    hashList()
    {
        arr=new Node[500009];
    }

    void insertData(int x)//arr's index must be periodic!!
    {
        int index=(x+1000000)%500009;
        int i;
        for(i=index;arr[(i+1000000)%500009].state!=0&&arr[(i+1000000)%500009].data!=x;++i){}
        if(arr[(i+1000000)%500009].state==0){arr[(i+1000000)%500009].state++;arr[(i+1000000)%500009].data=x;}
        else arr[(i+1000000)%500009].state++;
    }

    int Find(int x)
    {
        int index=(x+1000000)%500009;
        for(int i=index;arr[(i+1000000)%500009].state!=0;++i)
        {
            if(arr[(i+1000000)%500009].data==x)return arr[(i+1000000)%500009].state;
        }
        return 0;

    }


};
