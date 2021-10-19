#include<bits/stdc++.h>


using namespace std;
class process:public books
{
    string Name1;
    int ID1,Price1;
public:
    process();
    process(string Name1,int ID1,int Price1);

    void SetN(string s);

    void SetID(int I);

    void GetInB();

    void addtofile(string s,int I,int P);

};
