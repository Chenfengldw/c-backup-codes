//本程序会自动生成三个不同的数供用户猜
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{   int i,y1,y2,y3,A(0),B(0),a[3];//数组a用于记录所生成的三个数
    srand(time(NULL));
    a[0]=rand()%10;
    a[1]=rand()%10;
    while(a[1]==a[0]){//保证生成的第一和第二个数不等
        a[1]=rand()%10;
    }
    a[2]=rand()%10;
    while(a[ 2]==a[0] || a[2]==a[1] ){//保证生成的第三个数和第一第二均不等
        a[2]=rand()%10;
    }
    cout<<a[0]<<a[1]<<a[2]<<endl;
    for (i=0;i<7;++i){//一共循环七次，用户有七次猜测机会
           cout<<"请输入你猜测的数字"<<endl;
           cin>>y1>>y2>>y3;
           while(y1==y2||y1==y3||y2==y3){//提示用户猜测三个不同的数
               cout<<"请输入三个不同的数！！"<<endl;
               cin>>y1>>y2>>y3;
           }
           A=B=0;
           if (y1==a[0]) ++A ;
           if (y2==a[1]) ++A ;
           if (y3==a[2]) ++A ;
           if (y1!=a[0] && (y1==a[0]||y1==a[1]||y1==a[2])) ++B ;
           if (y2!=a[1] && (y2==a[0]||y2==a[1]||y2==a[2])) ++B ;
           if (y3!=a[2] && (y3==a[0]||y3==a[1]||y3==a[2])) ++B ;
           if (A==3 && B==0){
               cout<<"恭喜,你猜对了！"<<endl;
               break;
           }
           else cout<<A<<"A"<<B<<"B"<<endl;//A代表位置正确数字也正确B代表位置不正确数字正确
    }
    if (i==7) cout<<"很遗憾，你没有在规定次数内答对，答案是"<<a[0]<<a[1]<<a[2]<<endl;
    return 0;
}


