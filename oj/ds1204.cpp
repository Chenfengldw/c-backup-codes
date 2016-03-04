#include <iostream>
#include <cstring>
#include <stdlib.h>
using namespace std;

int main()
{
    char p[100][2000];
    char tmp[2000];
    int i=0;
    cin.getline(tmp,2000);
    int num=0;
    while(tmp[0]!='*')
       {
        for(int ii=0;ii<strlen(tmp);++ii)p[i][ii]=tmp[ii];
        ++i;
        cin.getline(tmp,2000);
        num++;
       }
    char op[120];
    cin.getline(op,120,'\n');
    while(op[0]!='q')
    {
        if(op[0]=='l')
        {
            int n1,n2,i=0;
            char n11[4],n22[4];
            char bit=op[5];
            if (bit=='-') {cout<<"Error!"<<endl;goto endline;}
            while(bit!=' ')
            {
                n11[i]=bit;
                i++;
                bit=op[5+i];
            }
            n11[i]='\0';
            bit=op[6+i];
            if (bit=='-') {cout<<"Error!"<<endl;goto endline;}
            int j=0;
            while(bit!='\0')
            {
                n22[j]=bit;
                j++;
                i++;
                bit=op[6+i];
            }
            n22[j]='\0';
            n1=atoi(n11);
            n2=atoi(n22);
            if (n1>num||n2>num||n1>n2||n1<=0||n2<=0) cout<<"Error!"<<endl;
            else {for(int k=n1-1;k<n2;++k) cout<<p[k]<<endl;}
        }
         if(op[0]=='i')
        {
            int i,j;
            int m=0,n=0;
            char i1[5],j1[5];
            char bit=op[4];
            if (bit=='-') {cout<<"Error!"<<endl;goto endline;}
            while(bit!=' ')
            {
                i1[m]=bit;
                m++;
                bit=op[4+m];
            }

            i1[m]='\0';
            bit=op[5+m];
            if (bit=='-') {cout<<"Error!"<<endl;goto endline;}
            while(bit!=' ')
            {
                j1[n]=bit;
                m++;
                n++;
                bit=op[5+m];
            }

            j1[n]='\0';
            i=atoi(i1);
            j=atoi(j1);

            char str[101];
            int s=0;
            bit=op[6+m];
            if (bit=='-') {cout<<"Error!"<<endl;goto endline;}
            while(bit!='\0')
            {
                str[s]=bit;
                m++;
                s++;
                bit=op[6+m];
            }
            str[s]='\0';
            int len;
            len=strlen(str);
            if (i>num||j>strlen(p[num-1])||i<0||j<0) cout<<"Error!"<<endl;
            else{
            for(int mm=0;mm<len;++mm){
            for(int ii=1998;ii>=j-1+mm;--ii) p[i-1][ii+1]=p[i-1][ii];
            }
            for(int ii=j-1;ii<j-1+len;++ii) p[i-1][ii]=str[ii-j+1];
            }
        }
         if(op[0]=='d')
        {
            int i,j,number;
            int m=0,n=0;
            char i1[5],j1[5],num1[4];
            char bit=op[4];
            if (bit=='-') {cout<<"Error!"<<endl;goto endline;}

            while(bit!=' ')
            {
                i1[m]=bit;
                m++;
                bit=op[4+m];
            }

            i1[m]='\0';
            bit=op[5+m];
            if (bit=='-') {cout<<"Error!"<<endl;goto endline;}

            while(bit!=' ')
            {
                j1[n]=bit;
                m++;
                n++;
                bit=op[5+m];
            }
            j1[n]='\0';
            bit=op[6+m];
            int s=0;
            if (bit=='-') {cout<<"Error!"<<endl;goto endline;}

            while(bit!='\0')
            {
                num1[s]=bit;
                m++;
                s++;
                bit=op[6+m];
            }
            num1[s]='\0';
            i=atoi(i1);
            j=atoi(j1);
            number=atoi(num1);
            if (i>num||j>strlen(p[num-1])||i<0||j<0) cout<<"Error!"<<endl;
            else{
            for(int ss=0;ss<number;++ss){
            for(int m=j;m<strlen(p[i-1]);m++) p[i-1][m-1]=p[i-1][m];
            p[i-1][strlen(p[i-1])-1]='\0';
            }
            }
        }
        endline:cin.getline(op,120,'\n');

    }
    for(int i=0;i<num;++i) cout<<p[i]<<endl;

}
