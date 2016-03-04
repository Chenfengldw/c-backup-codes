#include<iostream>
#include<cstring>
using namespace std;
bool CanBeAdded(char *a,char *b,int start);
void addstr(char *a,char *b,int start);
int main()
{
    int n;
    cin>>n;
    char **p;
    p=new char*[n];
    for (int i=0;i<n;++i) {p[i]=new char[100];cin>>p[i];}
    char head;
    cin>>head;
    char *q;
    int before,*usetime;
    usetime=new int[n];
    for(int i=0;i<n;++i) usetime[i]=0;
    q=new char[999];
    for(int i=0;i<n;++i){
        if (p[i][0]==head) {
            before=i;
            usetime[i]++;
            int j;
            for(j=0;p[i][j]!='\0';++j) q[j]=p[i][j];
            q[j]='\0';
            break;
        }
    }
    bool stop=false;
    cout<<q;
    while(stop==false)
    {
      stop=true;
      for(int i=0;i<n;++i){
            cout<<(CanBeAdded(q,p[i],strlen(q)-strlen(p[before]))==true&&i!=before&&usetime[i]<2)<<endl;
        if (CanBeAdded(q,p[i],strlen(q)-strlen(p[before]))==true&&usetime[i]<2) {
            stop=false;
            addstr(q,p[i],strlen(q)-strlen(p[before]));
            before=i;
            usetime[i]++;
        }
    }

    }
  cout<<q;
  cout<<strlen(q);

}

bool CanBeAdded(char *a,char *b,int start)
{
    int alen,blen;
    bool flag;
    alen=strlen(a);
    blen=strlen(b);
    for(int i=1;i<alen;++i)
    {
        flag=true;
        for(int j=0;j<min(alen-i,blen)-1;++j){
            if (a[i+j+start]!=b[j]) {flag=false; break;}
        }
        if (flag==true) return true;
    }
    if (flag==false) return false;

}


void addstr(char *a,char *b,int start)
{
    int alen,blen;
    bool flag;
    alen=strlen(a);
    blen=strlen(b);
    for(int i=1;i<alen;++i)
    {
        flag=true;
        for(int j=0;j<min(alen-i,blen)-1;++j){
            if (a[i+j+start]!=b[j]) {flag=false; break;}
        }
        if (flag==true) {
             for(int j=0;j<blen;++j){
                 a[i+j+start]=b[j];
            }
            a[i+blen+start]='\0';
            break;
        }
    }
}

