#include<iostream>
using namespace std;

int main()
{   int n,i,j,k=0;
    char *str;
    char *mgc={"fd","l4","d26"};
    char accept={' ','1','2','3','4','5','6','7','8','9','0',',','.','"','@','$','#'};
    char nouse{'@','#','$'};
    cout<<"请输入字符串最大长度:" ;
    cin>>n;
    str=new char[n+1];
    cout<<"请输入字符串： ";
    cin>>str;

    while(1){
        if (strlen(str)<=n){
            for (i=0;i<strlen(str);++i){
                for(j=0;j<17;++j){
                    if (str[i]==accept[j]) ++k;
              }

        }
        if (k<strlen(str)) {cout<<"输入字符串不符合要求请重新输入！ ";cin>>str;}
        else break;
        }
        else {cout<<"输入字符串超出长度请重新输入！ ";cin>>str;}
    }
    int filter();





}
