# include <iostream>;
using namespace std;
int main()
{

    int score[50],max=0,min=100,sum=0,num,average,i;
    for (num=1;num<=50;++num){
        cout<<"������ɼ���-1��ʾ������:";
        cin>>score[num-1];
        if (score[num-1]==-1) break;
        sum += score[num-1];
        if (min>score[num-1]) min=score[num-1];
        if (max<score[num-1]) max=score[num-1];

    }
    average= sum/(num-1);
    cout<<"\n        �ɼ��嵥\n";
    cout<<"���\t�ɼ�"<<endl;
    for (i=0;i<num-1;++i){
        cout<<i+1<<'\t'<<score[i]<<endl;
    }
    cout<<"��߷�"<<max<<"��ͷ�"<<min<<"ƽ����"<<average;
    return 0;

}
