#include<bits/stdc++.h>
#include"Class1.h"
#include"Class2.h"
#include"Class3.h"
using namespace std;

string books::GetN()
{
    return Name;
}
int books::GetID()
{
    return ID;
}
int books::GetP()
{
    return Price;
}
bool books:: Sreach(string S)
{
    bool f=0;
    ifstream Library;
    Library.open("Library.txt",ios::in);
    bool z=1;
    string s;
    int i,m;
    while(!Library.eof())
    {
        Library>>s>>i>>m;
        if(S==s)
        {
            Name=s;
            ID=i;
            Price=m;
            z=0;
            break;
        }
    }
    Library.close();
    if(z)
    {
        cout<<"Not Found!!!!!\n";
        return f=0;
    }
    else
        return f=1;
}
void books:: deletedata(int I)
{
    string s;
    int i,m;
    fstream Library;
    fstream temp;
    Library.open("Library.txt",ios::in);
    temp.open("temp.txt",ios::out);
    while( Library>>s>>i>>m )
    {
        if (  i==I )
        {
            continue;
        }
        else
        {
            temp<< s<< "\t"<< i<<"\t"<< m<<endl;
        }
    }
    Library.close();
    temp.close();
    remove( "Library.txt" );
    rename( "temp.txt", "Library.txt" );
}


process::process() {}
process:: process(string Name1,int ID1,int Price1)
{
    this->Name1=Name1;
    this->ID1=ID1;
    this->Price1=Price1;
}
void process:: SetN(string s)
{
    Name1=s;
}
void process:: SetID(int I)
{
    ID1=I;
}
void process:: GetInB()
{
    cout<<"The Name of the book : "<<GetN();
    cout<<"\nThe ID of the book : "<<GetID();
    cout<<"\nThe Price of the book : "<<GetP();
}
void process::addtofile(string s,int I,int P)
{
    fstream Library;
    Library.open("Library.txt",ios::app);
    Library<<s<<"\t"<<I<<"\t"<<P<<endl;
    Library.close();
}



void Borrow::SetNA(string s)
{
    Name2=s;
}
void Borrow::  SetID(int I)
{
    ID2=I;
}
void  Borrow::addinfo(string s,int I,string D)
{
    fstream Customer;
    Customer.open("Customer.txt",ios::app);
    Customer<<s<<"\t"<<I<<"\t"<<D<<endl;
    Customer.close();
}
void  Borrow:: deleteinfo(string S,int I,string ss,int ii,int pp)
{
    string s,d;
    int i;
    fstream Customer;
    fstream temp;
    Customer.open("Customer.txt",ios::in);
    temp.open("temp.txt",ios::out);
    while( Customer>>s>>i>>d )
    {
        if (  s==S &&I==i)
        {
            continue;
        }
        else
        {
            temp<< s<< "\t"<< i<<"\t"<< d<<endl;
        }
    }
    Customer.close();
    temp.close();
    remove( "Customer.txt" );
    rename( "temp.txt", "Customer.txt" );
    bool f=0;
    ifstream Library;
    Library.open("Customer.txt",ios::in);
    bool z=1;
    string st;
    int iddd,da;
    while(!Customer.eof())
    {
        Customer>>st>>iddd>>da;
        if(iddd==ii)
        {
            f=1;

            break;
        }


    }
    if(f==1)
        addtofile(ss,ii,pp);
    else
    {
        cout<<"You have not borrow this book!!!\n";
    }
    Customer.close();


}

void fun()
{
    bool f=1;
    cout<<"Please enter the name of the book\n";
    string N;
    cin>>N;
    books ob;
    f=ob.Sreach(N);
    if(!f)
    {
        cout<<"\nIf you need to enter any books else press\"Y\" or \"y\" \nElse press\"n\" : ";
        char h;
        cin>>h;
        if(h=='Y'||h=='y')
        {
            fun();
        }
    }
    else
    {
        cout<<"We have this book\n";
        cout<<"***************************\n";
        cout<<"\nThe Name of the book is : "<<ob.GetN();
        cout<<"\nThe ID of the book is : "<<ob.GetID();
        cout<<"\nThe Price of the book is : "<<ob.GetP()<<"\n";
        cout<<"***************************\n";
        cout<<"\nIf you need to buy it press\"Y\" or \"y\"\nElse press\"n\" : ";
        char h;
        cin>>h;
        if(h=='Y'||h=='y')
        {
            int i=ob.GetID();
            ob.deletedata(i);
        }
    }
}
void fun1()
{
    bool f=1;
    cout<<"Please enter the name of the book\n";
    string N;
    cin>>N;
    books ob;
    f=ob.Sreach(N);
    // if(!f)
    //fun1();
    if(f)
    {

        cout<<"We have this book\n";
        cout<<"**************************\n";
        cout<<"The Name of the book is : "<<ob.GetN();
        cout<<"\nThe ID of the book is : "<<ob.GetID();
        cout<<"\nThe Price of the book is : "<<ob.GetP()<<"\n";
        cout<<"**************************\n";
        cout<<"\nIf you need to borrow it press\"Y\" or \"y\" \nElse press\"n\" : ";
        char h;
        cin>>h;
        if(h=='Y'||h=='y')
        {
            int i=ob.GetID();
            ob.deletedata(i);
            Borrow ob2;
            string s;
            int I;
            string D;
            cout<<"Please enter your name : ";
            cin>>s;
            cout<<"Please enter your ID : ";
            cin>>I;
            cout<<"Please enter the date that you need to return it : ";
            cin>>D;
            ob2.addinfo(s,I,D);
        }
    }
}
void fun2()
{
    bool f=1;
    cout<<"Please enter your name and your ID\n";
    string N;
    int I;
    cin>>N>>I;
    Borrow ob;
    cout<<"Please enter the name of the book ,its ID and the Price\n";
    string ss;
    int ii,pp;
    cin>>ss>>ii>>pp;
    ob.deleteinfo(N,I,ss,ii,pp);
}
int main()
{
    cout<<"********Welcome in our system********\n";
    bool flag=1;

    while(flag)
    {
        cout<<"1- To borrow any books or return the books\n";
        cout<<"2- To search about any books\n";
        cout<<"3- To add any books\n";
        cout<<"4- To buy any books\n";
        cout<<"5- To exit\n";
        int n;
        cin>>n;
        switch(n)
        {
        case 1:
        {
            cout<<"If you need to borrow books press\"y\" \nIf you need to return books press\"n\" : ";
            char a;
            cin>>a;
            if(a=='y')
                fun1();
            else
                fun2();
        }
        break;
        case 2:
        {
            fun();
        }
        break;
        case 3:
        {

            bool v=0;
            while(v==0)
            {

                string s;
                int I,p;
                cout<<"Please enter the name of the book : ";
                cin>>s;
                cout<<"Please enter the ID of the book : ";
                cin>>I;
                cout<<"Please enter the price of the book : ";
                cin>>p;

                // bool f=0;
                ifstream Library;
                Library.open("Library.txt",ios::in);
                bool z=1;
                string ss;
                int i,m;

                while(!Library.eof())
                {
                    Library>>ss>>i>>m;
                    if(I==i)
                    {
                        z=0;
                        cout<<"error Id!!!"<<endl;
                        break;
                    }

                }
                if(z==1)
                {
                    process b(s,I,p);
                    b.addtofile(s,I,p);
                    v=1;
                    cout<<"Done"<<endl;
                }

                Library.close();

            }

        }
        break;
        case 4:
        {
            fun();
        }
        break;
        default:
            flag=0;
        }

    }
    return 0;
}
