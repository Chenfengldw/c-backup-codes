#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    char p[100][2000];
    char tmp[2000];
    cin.getline(tmp,2000);
    int num=0;
    while(tmp[0]!='*')
       {
        for(int x=0;x<strlen(tmp);++x)p[num][x]=tmp[x];
        cin.getline(tmp,2000);
        num++;
       }
    char op[120];
    cin>>op;
    while(strcmp(op,"quit")!=0)
    {
        if(strcmp(op,"list")==0)
        {
            int n1,n2;
            cin>>n1>>n2;
            if (n1<=0||n2<=0||n1>num||n2>num||n1>n2) cout<<"Error!"<<endl;
            else {for(int k=n1-1;k<n2;++k) cout<<p[k]<<endl;}
        }
         if(strcmp(op,"ins")==0)
        {
            int i,j;
            char str[100];
            cin>>i>>j;
            cin.get();
            cin.getline(str,100);
            int len;
            len=strlen(str);
            if (i<=0||j<=0||i>num||j>strlen(p[i-1])+1||strlen(str)>=100) cout<<"Error!"<<endl;
            else{

                if (j==strlen(p[i-1])+1)
                    {
                        for(int x=j-1;x<j-1+len;++x) p[i-1][x]=str[x-j+1];
                        p[i-1][j-1+len]='\0';
                    }
                else{
                    for(int x=strlen(p[i-1]);x>=j-1;--x) p[i-1][x+len]=p[i-1][x];
                    for(int x=j-1;x<j-1+len;++x) p[i-1][x]=str[x-j+1];
                    }

            }
        }
         if(strcmp(op,"del")==0)
        {
            int i,j,number;
            cin>>i>>j>>number;
            if (i<=0||j<=0||i>num||j+number-1>strlen(p[i-1])) cout<<"Error!"<<endl;
            else{
            for(int m=j+number-1;m<strlen(p[i-1]);m++) p[i-1][m-number]=p[i-1][m];
            p[i-1][strlen(p[i-1])-number]='\0';
            }
        }
        cin>>op;
    }
    for(int i=0;i<num;++i) cout<<p[i]<<endl;

}
