#include<iostream>
#include<cstring>
using namespace std;
const int maxlen=100;//字符串存储长度最大值
int filter(char input[],const char (*mg)[maxlen],int n,char *nu,int n1);//对input进行过滤
int check(char *in,char *nouse,int n,char *pn,int n1);//检查输入in是否合法
char *get();//获取输入，返回一个字符串，中间空格，用户无用字符和标点符号输入
char (*getmg(int &n))[maxlen];//获取输入，返回一个动态分配二维数组,用户获取用户输入的敏感词汇
int YesOrNo(const char warning[]);
int equal(char *in,const char *forb,char *nu,int n);//判断指针当前位置是否包含敏感词汇
int equal(char a,const char b);//判断两个字符串是否相等
void cut(char *in,const char *forb);//删除对应位置的字符串
void cut(char *p,int n);




int main()
{
    char mg_default[3][maxlen]={"L4","FD","D26"};//敏感词汇的默认值
    char (*mg)[maxlen];
    int mg_n=3;//敏感词汇默认个数
    char useless_default[]="#@$";
    char *useless;
    char punctuation_default[]=",.\"";
    char *punctuation;
    int unsigned length=20;//默认长度最大值
    if (YesOrNo("是否规定标点符号?(y/n):")){
        cout<<"示例: , . !"<<endl;
        cout<<"请输入 :";
        punctuation=get();
       }
    else punctuation=punctuation_default;
    cout<<"标点符号为:"<<punctuation<<'\n'<<endl;
    if (YesOrNo("是否规定无用字符?(y/n):")){
        cout<<"示例: @ # &"<<endl;
        cout<<"请输入 :";
        useless=get();
       }
    else useless=useless_default;
    cout<<"无用字符为:"<<useless<<'\n'<<endl;
    if (YesOrNo("是否规定敏感词汇?(y/n):")){
        cout<<"示例: fd,d26,l4"<<endl;
        cout<<"请输入 :";
        mg=getmg(mg_n);
        }
    else mg=mg_default;
    cout<<"敏感词汇为:";
    int i=0;
    while(i<mg_n) cout<<*(mg+i++)<<' ';
    cout<<'\n'<<endl;
    if (YesOrNo("是否规定字符串长度?(y/n):")){
        cout<<"请输入";
        cin>>length;cin.get();
        }
    cout<<"长度规定为:"<<length<<'\n'<<endl;
    char input[maxlen];//存储用户的输入
    do{
        while (1){    //获取输入的待过滤字符串，直到符合输入标准.
        cout<<"请输入待过滤字符串:";
        cin.getline(input,maxlen);
        if (check(input,useless,strlen(useless),punctuation,strlen(punctuation)) && strlen(input)<=length){//判断输入是否符合标准
            while(0!=filter(input,mg,mg_n,useless,strlen(useless)));//循环过滤，知道不含有敏感词汇
            cout<<"过滤后为:"<<input<<endl;
            break;
        }
        else cout<<"输入不符合要求，请重新输入."<<endl<<endl;
    }
        }while(YesOrNo("是否继续?(y/n):"));


    return 0;

}

char *get(){//获取输入，返回一个字符串，去除中间空格，用户无用字符和标点符号输入
    char *temp=new char [maxlen];
    cin.getline(temp,maxlen);
    int i=0;
    while(temp[i]!='\0') if (temp[i++]==' ') cut(temp+i-1,1);
    return temp;
}

char (*getmg(int &n))[maxlen]{//获取输入。
    static char tem[maxlen];
    cin.getline(tem,maxlen);
    int i=0;n=0;
    while(tem[i]!='\0') if (tem[i++]==' ') n++;
    n++;
    char (*a)[maxlen]=new char [n][maxlen];
    i=0;int j=0;int last=0;
    while(tem[i]!='\0'){
        if (tem[i]==' ') {
            tem[i]='\0';
            strcpy(*(a+j),tem+last);
            j++;
            last=i+1;
        }
        i++;
        }
    strcpy(*(a+j),tem+last);
    return a;
}
int YesOrNo(const char warning[]){//获取输入的一个(y/n),循环获取输入，直到输入为y 或 n.
    char go_on[maxlen];
    while (1){
        cout<<warning;
        cin>>go_on;
        if ((go_on[0]!='y' && go_on[0]!='n') || strlen(go_on)!=1) cout<<"\n输入错误，请输入y或n."<<endl;//防止错误输入
        else break;
    }
    cin.get();//删除输入的换行符
    if (go_on[0]=='n') return 0;
    else return 1;
}

int check(char *in,char *nouse,int n,char *pn,int n1){//检查输入in是否合法，nu为无用字符，pn为为标点符号
    int i=0;
    while(*in!='\0'){
        if ((*in<91 && *in>64)||(*in<123 && *in>96)|| (*in<58 && *in>47) || *in==' ') {in++;continue;}
        for (i=0;i<n;i++,nouse++) if (*in==*nouse) break;
        nouse-=i;
        if (i<n) {in++;continue;}
        for (i=0;i<n1;i++,pn++) if (*in==*pn) break;
        pn-=i;
        if (i<n1) {in++;continue;}
        return 0;
    }
    return 1;
}
int filter(char input[],const char (*mg)[maxlen],int n,char *nouse,int n1){//对input进行过滤
    char *p=input;
    int i=0,cut_times=0;
    while(*p!='\0'){
    for (i=0;i<n;i++){
        if (equal(*p,**mg)){
            if (equal(p,*mg,nouse,n1)) {
                cut(p,*mg);
                cut_times++;
                break;
        }
    }
        mg++;
}
    p++;mg-=i;
}
    return cut_times;
}
int equal(char *in,const char *forb,char *nouse,int n){//判断指针当前位置是否包含敏感词汇，将判断forb 里面的所有字符,略过nu里面包含的无用字符
int i=0;
while (*forb!='\0'){
    if (*in==*forb) {in++;forb++;continue;}
    if (*in==' ') {in++;continue;}
    if (*in>64 && *in<91 && *in+32==*forb) {in++;forb++;continue;}
    if (*in>96 && *in<123 && *in-32==*forb) {in++;forb++;continue;}
    for (i=0;i<n;i++,nouse++) if (*in==*nouse) break;
    nouse-=i;
    if (i<n) {in++;continue;}
    return 0;
    }
    return 1;
}
void cut(char *in,const char *forb){//在in当前位置删除字符指针 *forb里的字符串。
    while (*forb!='\0'){
        if (*in==' ') {in++;continue;}
        if ((*in==*forb) || (*in>64 && *in<91 && *in+32==*forb) || (*in>96 && *in<123 && *in-32==*forb)) {cut(in,1);forb++;continue;}
        cut(in,1);
    }
}
int equal(char a,const char b){
    if (a==b) return 1;
    else if ((a>64 && a<91 && a+32==b) || (a>96 && a<123 && a-32==b)) return 1;
    return 0;
}
void cut(char *p,int n){
    char *tmp=p+n;
    while(*tmp!='\0') *(p++)=*(tmp++);
    *p='\0';
    }

