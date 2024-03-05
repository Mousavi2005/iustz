#include<iostream>

using namespace std;

class humanCharacter
{
private:
    string name;
    int age;
    humanCharacter() = default;
public:
    void setName(string name){
        this->name = name;
    }
    humanCharacter(string name , int age);
    void setAge(int age){
        this->age = age;
    }
    string getName(){
        return name;
    }
    int getAge(){
        return age;
    }
};
humanCharacter::humanCharacter(string name , int age)
{
    this->age = age;
    this->name = name;
}



int main(){
    
}