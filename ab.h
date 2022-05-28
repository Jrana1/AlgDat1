#ifndef _A_
#define _A_
#include <iostream>
using namespace std;
#include <stdlib.h>
#include <time.h>
#include <vector>
#include <string>
class A
{
private:
    int a;
    string name;

public:
    A() { a = 3; }
    A(int x, string name)
    {
        a = x;
        this->name = name;
    }
    void display()
    {
        cout << a << " " << this->name << endl;
    }
};
#endif