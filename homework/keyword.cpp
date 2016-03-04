#include <iostream>
#include <cstring>
using namespace std;
int search(char *chararray,char *keyword);
int main()
{  int n=0,i,j,count=0;char **p,**q;
   cout<<"请输入关键词个数，不超过10个: ";
   cin>>n;
   p=new char*[n];
   q=new char*[25];
   for (i=0;i<n;++i) {p[i]=new char[41];cin.getline(p[i],41,'\n');}
   for (i=0;i<25;++i) {
       q[i]=new char[81];
       for(j=0;j<80;++j) q[i][j]=' ';
    }
   for (i=0;i<25;++i) {
       cin.getline(q[i],81,'\n');
       if (q[i][0]=='\0') break;
       }
   for (i=0;i<25;++i) {
       for (j=0;j<n;++j) count+=search(q[i],p[j]);
   }
   cout<<count;
   return 0;

}

int search(char *chararray,char *keyword){
    int i=0,j=0,count=0;
    for (i=0;i<80;++i){
        if (chararray[i]>=65&&chararray[i]<=90 ||chararray[i]>=97&&chararray[i]<=122||chararray[i]=='\0') continue;
         else chararray[i]=' ';
    }
    for (i=0;i<80;++i){
        if(j==strlen(keyword))  {count++;j=0;}
        if (chararray[i]=='\0') return count;
        if (chararray[i]!=keyword[j]&&chararray[i]!=' ') {j=0;continue;}
        if (chararray[i]==' ') continue;
        if ((chararray[i]==keyword[j])||(chararray[i]-keyword[j]==32)||(keyword[j]-chararray[i]==32)) j++;

    }
    return count;
}




