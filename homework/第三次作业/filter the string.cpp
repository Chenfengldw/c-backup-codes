#include<iostream>
#include<cstring>
using namespace std;
const int maxlen=100;//�ַ����洢�������ֵ
int filter(char input[],const char (*mg)[maxlen],int n,char *nu,int n1);//��input���й���
int check(char *in,char *nouse,int n,char *pn,int n1);//�������in�Ƿ�Ϸ�
char *get();//��ȡ���룬����һ���ַ������м�ո��û������ַ��ͱ���������
char (*getmg(int &n))[maxlen];//��ȡ���룬����һ����̬�����ά����,�û���ȡ�û���������дʻ�
int YesOrNo(const char warning[]);
int equal(char *in,const char *forb,char *nu,int n);//�ж�ָ�뵱ǰλ���Ƿ�������дʻ�
int equal(char a,const char b);//�ж������ַ����Ƿ����
void cut(char *in,const char *forb);//ɾ����Ӧλ�õ��ַ���
void cut(char *p,int n);




int main()
{
    char mg_default[3][maxlen]={"L4","FD","D26"};//���дʻ��Ĭ��ֵ
    char (*mg)[maxlen];
    int mg_n=3;//���дʻ�Ĭ�ϸ���
    char useless_default[]="#@$";
    char *useless;
    char punctuation_default[]=",.\"";
    char *punctuation;
    int unsigned length=20;//Ĭ�ϳ������ֵ
    if (YesOrNo("�Ƿ�涨������?(y/n):")){
        cout<<"ʾ��: , . !"<<endl;
        cout<<"������ :";
        punctuation=get();
       }
    else punctuation=punctuation_default;
    cout<<"������Ϊ:"<<punctuation<<'\n'<<endl;
    if (YesOrNo("�Ƿ�涨�����ַ�?(y/n):")){
        cout<<"ʾ��: @ # &"<<endl;
        cout<<"������ :";
        useless=get();
       }
    else useless=useless_default;
    cout<<"�����ַ�Ϊ:"<<useless<<'\n'<<endl;
    if (YesOrNo("�Ƿ�涨���дʻ�?(y/n):")){
        cout<<"ʾ��: fd,d26,l4"<<endl;
        cout<<"������ :";
        mg=getmg(mg_n);
        }
    else mg=mg_default;
    cout<<"���дʻ�Ϊ:";
    int i=0;
    while(i<mg_n) cout<<*(mg+i++)<<' ';
    cout<<'\n'<<endl;
    if (YesOrNo("�Ƿ�涨�ַ�������?(y/n):")){
        cout<<"������";
        cin>>length;cin.get();
        }
    cout<<"���ȹ涨Ϊ:"<<length<<'\n'<<endl;
    char input[maxlen];//�洢�û�������
    do{
        while (1){    //��ȡ����Ĵ������ַ�����ֱ�����������׼.
        cout<<"������������ַ���:";
        cin.getline(input,maxlen);
        if (check(input,useless,strlen(useless),punctuation,strlen(punctuation)) && strlen(input)<=length){//�ж������Ƿ���ϱ�׼
            while(0!=filter(input,mg,mg_n,useless,strlen(useless)));//ѭ�����ˣ�֪�����������дʻ�
            cout<<"���˺�Ϊ:"<<input<<endl;
            break;
        }
        else cout<<"���벻����Ҫ������������."<<endl<<endl;
    }
        }while(YesOrNo("�Ƿ����?(y/n):"));


    return 0;

}

char *get(){//��ȡ���룬����һ���ַ�����ȥ���м�ո��û������ַ��ͱ���������
    char *temp=new char [maxlen];
    cin.getline(temp,maxlen);
    int i=0;
    while(temp[i]!='\0') if (temp[i++]==' ') cut(temp+i-1,1);
    return temp;
}

char (*getmg(int &n))[maxlen]{//��ȡ���롣
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
int YesOrNo(const char warning[]){//��ȡ�����һ��(y/n),ѭ����ȡ���룬ֱ������Ϊy �� n.
    char go_on[maxlen];
    while (1){
        cout<<warning;
        cin>>go_on;
        if ((go_on[0]!='y' && go_on[0]!='n') || strlen(go_on)!=1) cout<<"\n�������������y��n."<<endl;//��ֹ��������
        else break;
    }
    cin.get();//ɾ������Ļ��з�
    if (go_on[0]=='n') return 0;
    else return 1;
}

int check(char *in,char *nouse,int n,char *pn,int n1){//�������in�Ƿ�Ϸ���nuΪ�����ַ���pnΪΪ������
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
int filter(char input[],const char (*mg)[maxlen],int n,char *nouse,int n1){//��input���й���
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
int equal(char *in,const char *forb,char *nouse,int n){//�ж�ָ�뵱ǰλ���Ƿ�������дʻ㣬���ж�forb ����������ַ�,�Թ�nu��������������ַ�
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
void cut(char *in,const char *forb){//��in��ǰλ��ɾ���ַ�ָ�� *forb����ַ�����
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

