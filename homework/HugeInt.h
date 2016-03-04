#ifndef HUGEINT_H_INCLUDED
#define HUGEINT_H_INCLUDED
#include <iostream>
#include <cstring>
using namespace std;

class HugeInt{
    friend ostream & operator<<(ostream & os,const HugeInt &obj)
private:
    int storage[30]={0};
public:
    HugeInt(const char *str);
    HugeInt operator+(const HugeInt &a) const;




#endif // HUGEINT_H_INCLUDED
