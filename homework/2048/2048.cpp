#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
void movew();void moves();void movea();void moved();
int a[4][4]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
int main()
{   char tow;int tem[4][4],i,j,k,m,over=0;
    srand(time(NULL));
    i=rand()%4;j=rand()%4;
    a[i][j]=2;
    //cout<<"11111111111111111111111111111111111111111111111111";
    k=rand()%4;m=rand()%4;
    while((i==k)&&(j==m)) {k=rand()%4;m=rand()%4;} ;
    a[k][m]=2;
    for (i=0;i<4;++i){
            for (j=0;j<4;++j){
                if (a[i][j]!=0) cout<<a[i][j]<<' ';
                    else cout<<"__";
            }
            cout<<endl;
        }
    //cout<<"11111111111111111111111111111111111111111111111111";
    while(over==0){
        //cout<<"11111111111111111111111111111111111111111111111111";
        for (i=0;i<4;++i){
            for (j=0;j<4;++j){
                tem[i][j]=a[i][j];
      //          cout<<"11111111111111111111111111111111111111111111111111";
            }
        }
        //cout<<"11111111111111111111111111111111111111111111111111";
        cout<<"请选择移动方向(w,s,a,d): ";
        cin>>tow;
        if (tow=='w') movew();
        if (tow=='s') moves();
        if (tow=='a') movea();
        if (tow=='d') moved();
        i=rand()%4;j=rand()%4;
        while(a[i][j]!=0){
            i=rand()%4;j=rand()%4;
        }
        a[i][j]=2;
        over=1;
        for (i=0;i<4;++i){
            for (j=0;j<4;++j){
                if (a[i][j]!=0) cout<<a[i][j]<<' ';
                    else cout<<"__";
                 if (tem[i][j]!=a[i][j]) over=0;


            }
            cout<<endl;
        }



}
//cout<<"11111111111111111111111111111111111111111111111111";
return 0;
}
 void moved()
{    int i,j,move=0;
     for (i=0;i<4;++i){
         if (a[i][3]==0 && (a[i][0]!=0||a[i][1]!=0||a[i][2]!=0 )) move=1;
     }
     while(move){
     for (i=0;i<4;++i){
            for (j=2;j>=0;--j){
                if (a[i][j+1]==0) {a[i][j+1]=a[i][j];a[i][j]=0;};
            }
     }
     move=0;
     for (i=0;i<4;++i){
         if (a[i][3]==0 && (a[i][0]!=0||a[i][2]!=0||a[i][1]!=0 )) move=1;
     }
     }
     for (i=0;i<4;++i){
            for (j=0;j<3;++j){
                if (a[i][j]==a[i][j+1]) {
                    a[i][j+1]*=2;
                    a[i][j]=0;
            }
     }
    }
}
void movew()
 {
     int i,j,move=0;
     for (j=0;j<4;++j){
         if (a[0][j]==0 && (a[1][j]!=0||a[2][j]!=0||a[3][j]!=0 )) move=1;
     }
     while(move){
     for (j=0;j<4;++j){
            for (i=1;i<=3;++i){
                if (a[i-1][j]==0) {a[i-1][j]=a[i][j];a[i][j]=0;};
            }
     }
     move=0;
     for (j=0;j<4;++j){
         if (a[0][j]==0 && (a[1][j]!=0||a[2][j]!=0||a[3][j]!=0 )) move=1;
     }
     }
    for (j=0;j<4;++j){
            for (i=3;i>=1;--i){
                if (a[i][j]==a[i-1][j]) {
                    a[i-1][j]*=2;
                    a[i][j]=0;
            }
     }
    }
 }
void movea()
 {   int i,j,move=0;
     for (i=0;i<4;++i){
         if (a[i][0]==0 && (a[i][1]!=0||a[i][2]!=0||a[i][3]!=0 )) move=1;
     }
     while(move){
     for (i=0;i<4;++i){
            for (j=1;j<=3;++j){
                if (a[i][j-1]==0) {a[i][j-1]=a[i][j];a[i][j]=0;};
            }
     }
     move=0;
     for (i=0;i<4;++i){
         if (a[i][0]==0 && (a[i][1]!=0||a[i][2]!=0||a[i][3]!=0 )) move=1;
     }
     }
     for (i=0;i<4;++i){
            for (j=3;j>=1;--j){
                if (a[i][j]==a[i][j-1]) {
                    a[i][j-1]*=2;
                    a[i][j]=0;
            }
     }
    }
 }
void moves()
 {  int i,j,move=0;
     for (j=0;j<4;++j){
         if (a[3][j]==0 && (a[2][j]!=0||a[1][j]!=0||a[0][j]!=0 )) move=1;
     }
     //cout<<"2222222222222222222222";
     while(move){
     for (j=0;j<4;++j){
            for (i=2;i>=0;--i){
                if (a[i+1][j]==0) {a[i+1][j]=a[i][j];a[i][j]=0;};
                //cout<<"2222222222222222222222";
            }
            //cout<<"4444444444444444444444444444";
     }
     //cout<<"3333333333333333333333333333333";
     move=0;
     for (j=0;j<4;++j){
         //cout<<"666666666666666666666666666666666666666";
         if (a[3][j]==0 && (a[2][j]!=0||a[1][j]!=0||a[0][j]!=0 )) move=1;
     }
     }
     for (j=0;j<4;++j){
            for (i=0;i<3;++i){
                if (a[i][j]==a[i+1][j]) {
                    a[i+1][j]*=2;
                    a[i][j]=0;
            }
     }
    }
 }
