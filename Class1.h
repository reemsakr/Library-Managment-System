#include <iostream>

using namespace std;

class books
{
private:
    string Name;
    int ID,Price;
public:
    string GetN();

    int GetID();

    int GetP();

    bool Sreach(string S);
    void deletedata(int I);
};
