#include<fstream>
using namespace std;

int main()
{
    ifstream infile("file1");
    ofstream outfile("file2");
    int n;
    infile>>n;
    int *heapSize;
    heapSize=new int[n];
    for(int i=0;i<n;++i)
    {
        infile>>heapSize[i];
    }

    int *result;
    result=new int[n];
    result[0]=heapSize[0];
    result[1]=heapSize[0]+heapSize[1];
    for(int i=2;i<n;++i){
        result[i]=result[i-1]+heapSize[i];
    }


    outfile<<n;



    return 0;


}
