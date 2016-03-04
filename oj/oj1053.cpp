#include<iostream>
using namespace std;


int main()
{ int n,**getValue;
  cin>>n;
  getValue=new int*[n];
  for(int i=0;i<n;++i) getValue[i]=new int[3];
  for(int i=0;i<n;++i){
    for(int j=0;j<3;++j){
        cin>>getValue[i][j];
    }
  }
  int maxrow=0,maxcol=0;
  for(int i=0;i<n;++i){
        if (getValue[i][0]>=maxrow) maxrow=getValue[i][0];
        if (getValue[i][1]>=maxcol) maxcol=getValue[i][1];
  }


cout<<"1111111111111111";
  int **storage;
  storage=new int*[maxrow];
  for(int i=0;i<maxrow;++i) storage[i]=new int[maxcol];
  cout<<"2222222222222222"<<endl;
  for(int i=0;i<maxrow;++i){
    for(int j=0;j<maxcol;++j){
        storage[i][j]=0;
    }
  }
  cout<<"33333333333333333";
  for(int i=0;i<n;++i) {cout<<"              "<<getValue[i][0]<<"           "<<getValue[i][1]<<"         ";storage[getValue[i][0]][getValue[i][1]]=getValue[i][2];}
  cout<<"44444444444444";


  int m,**operate;
  cin>>m;
  operate=new int*[m];
  for(int i=0;i<m;++i) operate[i]=new int[3];
  for(int i=0;i<m;++i){
    for(int j=0;j<3;++j) cin>>operate[i][j];
  }

  for(int i=0;i<m;++i){
    if (operate[i][0]==0){
        if(operate[i][1]>maxrow||operate[i][2]>maxrow) continue;
        else{
            int *tmp;
            tmp=new int[maxcol];
            for(int j=0;j<maxcol;++j) tmp[j]=storage[operate[i][1]][j];
            for(int j=0;j<maxcol;++j) storage[operate[i][1]][j]=storage[operate[i][2]][j];
            for(int j=0;j<maxcol;++j) storage[operate[i][2]][j]=tmp[j];
        }
    }
    if (operate[i][0]==1){
        if(operate[i][1]>maxcol||operate[i][2]>maxcol) continue;
        else{
            int *tmp;
            tmp=new int[maxrow];
            for(int j=0;j<maxrow;++j) tmp[j]=storage[j][operate[i][1]];
            for(int j=0;j<maxrow;++j) storage[j][operate[i][1]]=storage[j][operate[i][2]];
            for(int j=0;j<maxrow;++j) storage[j][operate[i][2]]=tmp[j];

        }
    }


  if (operate[i][0]==2){
        if(operate[i][1]>maxrow||operate[i][2]>maxcol) cout<<0;
        else cout<<storage[operate[i][1]][operate[i][2]];
  }



  }
  return 0;

}
