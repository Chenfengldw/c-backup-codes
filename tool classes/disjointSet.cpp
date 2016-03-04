class disjointSet
{
private:
    int Size;
    int *parent;

public:
    disjointSet(int n)
    {
        Size=n;
        parent=new int[n];//if ver 0 shows up,then write like this,if not ,for example,from ver 1 to ver n,then parent=new int[n+1],and for(int i=1;i<=n;++i)parent[i]=-1;
        for(int i=0;i<n;++i)parent[i]=-1;//parent[i] means that ver i's parent ver parent[i];If parent[i] is minus,that indecates ver i doesn't have parent and that is to say it is a root;
    }

    int Find(int x)
    {
       if(parent[x]<0)return x;
       return parent[x]=Find(parent[x]);
    }

    void Union(int a,int b)
    {
        if(a==b)return;
        if(parent[a]>parent[b])
        {
            parent[b]+=parent[a];
            parent[a]=b;
        }
        else
        {
            parent[a]+=parent[b];
            parent[b]=a;
        }
    }
};
