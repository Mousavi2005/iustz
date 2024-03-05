#include<iostream>

using namespace std;

class humanCharacter
{
private:
    string name;
    string gender;
    int health = 100;
    int stamina = 100;
    int level;
    int age;

    humanCharacter() = default;
public:
    humanCharacter(string name, string gender, int age);

    void increaseHealth(int number){
        health += number;
    }
    void decreaseHealth(int number){
        health -= number;
    }

    void incraseStamina(int number){
        stamina += number;
    }
    void decreaseStamina(int number){
        stamina -= number;
    }

    string getName(){
        return name;
    }
    void setName(string name){
        this->name = name;
    }

    int getAge(){
        return age;
    }
    void setAge(int age){
        this->age = age;
    }

    string getGender(){
        this->gender = gender;
    }
    void setGender(string gender){
        this->gender = gender;
    }



};
humanCharacter::humanCharacter(string name, string gender, int age)
{
    this->name = name;
    this->gender = gender;
    this->age = age;
}


class zombie
{
private:
    int health;
    int damagePower;

    zombie() = default;
public:
    zombie(int health, int damagePower);
    void attack(){

    }
};
zombie::zombie(int health, int damagePower)
{
    this->health = health;
    this->damagePower = damagePower;
}


class strongZombie
{
private:
    int health;
    int damagePower;

    strongZombie() = default;
public:
    strongZombie(int health, int damagePower);
    void attack(){

    }
};
strongZombie::strongZombie(int health , int damagePower)
{
    this->health = health;
    this->damagePower = damagePower;
}


class firearm
{
private:
    string name;
    int damage;
    int price;

    firearm() = default;
public:
    firearm(string name, int damage, int price);

    void setName(string name){
        this->name = name;
    }
    string getName(){
        return name;
    }

    void setDamage(int damage){
        this->damage = damage;
    }
    int getDamage(){
        return damage;
    }

    void setPrice(int price){
        this->price = price;
    }
    int getPrice(){
        return price;
    }

};
firearm::firearm(string name, int damage, int price)
{
    this->name = name;
    this->damage = damage;
    this->price = price;
}


class coldWeapon
{
private:
    string name;
    int damage;
    int price;

    coldWeapon() = default;
public:
    coldWeapon(string name, int damage, int price);

    void setName(string name){
        this->name = name;
    }
    string getName(){
        return name;
    }

    void setDamage(int damage){
        this->damage = damage;
    }
    int getDamage(){
        return damage;
    }

    void setPrice(int price){
        this->price = price;
    }
    int getPrice(){
        return price;
    }

};
coldWeapon::coldWeapon(string name, int damage, int price)
{
    this->name = name;
    this->damage = damage;
    this->price = price;
}


class throwableWeapon
{
private:
    string name;
    int damage;
    int price;

    throwableWeapon() = default;
public:
    throwableWeapon(string name, int damage, int price);

    void setName(string name){
        this->name = name;
    }
    string getName(){
        return name;
    }

    void setDamage(int damage){
        this->damage = damage;
    }
    int getDamage(){
        return damage;
    }

    void setPrice(int price){
        this->price = price;
    }
    int getPrice(){
        return price;
    }

};
throwableWeapon::throwableWeapon(string name, int damage, int price)
{
    this->name = name;
    this->damage = damage;
    this->price = price;
}


class shop
{
private:
    //Firearms
    firearm gun1;
    firearm gun2;
    firearm granade;
    firearm granade2;
    //Cold Weapons
    coldWeapon knife;
    coldWeapon knife2;
    //Throwable

    shop(/* args */);

};

// shop::shop(/* args */)
// {
// }







int main(){
    
}