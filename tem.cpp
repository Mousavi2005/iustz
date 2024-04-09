#include <iostream>

using namespace std;

class a12
{
private:
    string name;
public:
    void SetName(string n){
        name = n;
    }
    a12() = default;
    friend class b;
};

class b
{
private:
    int age;
public:
    a12 objecta;

    b(/* args */);
    ~b();
};

b::b(/* args */)
{
}

b::~b()
{
}




int main(){

}