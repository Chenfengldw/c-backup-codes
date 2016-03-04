# include <iostream>;
using namespace std;
int main()
{

    int score[50],max=0,min=100,sum=0,num,average,i;
    for (num=1;num<=50;++num){
        cout<<"请输入成绩（-1表示结束）:";
        cin>>score[num-1];
        if (score[num-1]==-1) break;
        sum += score[num-1];
        if (min>score[num-1]) min=score[num-1];
        if (max<score[num-1]) max=score[num-1];

    }
    average= sum/(num-1);
    cout<<"\n        成绩清单\n";
    cout<<"编号\t成绩"<<endl;
    for (i=0;i<num-1;++i){
        cout<<i+1<<'\t'<<score[i]<<endl;
    }
    cout<<"最高分"<<max<<"最低分"<<min<<"平均分"<<average;
    return 0;

}
