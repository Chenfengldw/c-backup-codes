#include<iostream>
using namespace std;

int main()
{   int n,i,j,k=0;
    char *str;
    char *mgc={"fd","l4","d26"};
    char accept={' ','1','2','3','4','5','6','7','8','9','0',',','.','"','@','$','#'};
    char nouse{'@','#','$'};
    cout<<"�������ַ�����󳤶�:" ;
    cin>>n;
    str=new char[n+1];
    cout<<"�������ַ����� ";
    cin>>str;

    while(1){
        if (strlen(str)<=n){
            for (i=0;i<strlen(str);++i){
                for(j=0;j<17;++j){
                    if (str[i]==accept[j]) ++k;
              }

        }
        if (k<strlen(str)) {cout<<"�����ַ���������Ҫ�����������룡 ";cin>>str;}
        else break;
        }
        else {cout<<"�����ַ��������������������룡 ";cin>>str;}
    }
    int filter();





}
