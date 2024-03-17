#include <iostream>

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

    void increaseHealth(int number)
    {
        health += number;
    }
    void decreaseHealth(int number)
    {
        health -= number;
    }

    void incraseStamina(int number)
    {
        stamina += number;
    }
    void decreaseStamina(int number)
    {
        stamina -= number;
    }

    string getName()
    {
        return name;
    }
    void setName(string name)
    {
        this->name = name;
    }

    int getAge()
    {
        return age;
    }
    void setAge(int age)
    {
        this->age = age;
    }

    string getGender()
    {
        return gender;
    }
    void setGender(string gender)
    {
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
    void attack()
    {
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
    void attack()
    {
    }
};
strongZombie::strongZombie(int health, int damagePower)
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
    bool Lock;
    firearm() = default;

public:
    firearm(string name, int damage, int price,bool Lock);

    void setName(string name)
    {
        this->name = name;
    }
    string getName()
    {
        return name;
    }

    void setDamage(int damage)
    {
        this->damage = damage;
    }
    int getDamage()
    {
        return damage;
    }

    void setPrice(int price)
    {
        this->price = price;
    }
    int getPrice()
    {
        return price;
    }
    void setLock(bool lock) {
        this->Lock = lock;
    }
    bool getLock() {
        return Lock;
    }
    friend class shop;
};
firearm::firearm(string name, int damage, int price,bool Lock)
{
    this->name = name;
    this->damage = damage;
    this->price = price;
    this->Lock = Lock;
}


class coldWeapon
{
private:
    string name;
    int damage;
    int price;
    bool Lock;
    coldWeapon() = default;

public:
    coldWeapon(string name, int damage, int price,bool Lock);

    void setName(string name)
    {
        this->name = name;
    }
    string getName()
    {
        return name;
    }

    void setDamage(int damage)
    {
        this->damage = damage;
    }
    int getDamage()
    {
        return damage;
    }

    void setPrice(int price)
    {
        this->price = price;
    }
    int getPrice()
    {
        return price;
    }
        void setLock(bool lock) {
        this->Lock = lock;
    }
    bool getLock() {
        return Lock;
    }
    friend class shop;
};
coldWeapon::coldWeapon(string name, int damage, int price,bool lock)
{
    this->name = name;
    this->damage = damage;
    this->price = price;
    this->Lock = lock;
}


class throwableWeapon
{
private:
    string name;
    int damage;
    int price;
    bool Lock;
    throwableWeapon() = default;

public:
    throwableWeapon(string name, int damage, int price,bool Lock);

    void setName(string name)
    {
        this->name = name;
    }
    string getName()
    {
        return name;
    }

    void setDamage(int damage)
    {
        this->damage = damage;
    }
    int getDamage()
    {
        return damage;
    }

    void setPrice(int price)
    {
        this->price = price;
    }
    int getPrice()
    {
        return price;
    }
        void setLock(bool lock) {
        this->Lock = lock;
    }
    bool getLock() {
        return Lock;
    }
    friend class shop;
};
throwableWeapon::throwableWeapon(string name, int damage, int price , bool lock)
{
    this->name = name;
    this->damage = damage;
    this->price = price;
    this->Lock = lock;
}


struct Backpack 
{
    firearm* gun1;
    firearm* gun2;
    firearm* gun3;
    firearm* grenade2;
    // Cold Weapons
    coldWeapon* knife;
    coldWeapon* sword;
    coldWeapon* bow;
    // Throwable
    throwableWeapon* stoneSling;
    throwableWeapon* ninjaStar;
    throwableWeapon* needle;
    
};
static Backpack bag;

class shop
{
private:
    // Firearms
    firearm gun1;
    firearm gun2;
    firearm gun3; 
    firearm grenade2;
    // Cold Weapons
    coldWeapon knife;
    coldWeapon sword;
    coldWeapon bow;
    // Throwable
    throwableWeapon stoneSlinges;
    throwableWeapon ninjaStar;
    throwableWeapon needle;

    int money;
    shop() = default;
public:
    shop(firearm gun1, firearm gun2, firearm gun3, firearm granade2, coldWeapon knife, coldWeapon sword, coldWeapon bow, throwableWeapon stoneSlings, throwableWeapon ninjastar, throwableWeapon needle ){

        this->gun1 = gun1;
        this->gun2 = gun2;
        this->gun3 = gun3;
        this->grenade2 = granade2;
        this->knife = knife;
        this->sword = sword;
        this->bow = bow;
        this->stoneSlinges = stoneSlings;
        this->ninjaStar = ninjastar;
        this->needle = needle;
    }

    void increaseMoney(int m){
        money += m;
    }
    void decreaseMoney(int m){
        money -= m;
    }
    void showShop(){
        cout << "[1]  " << gun1.getName() << "   " <<  gun1.getDamage() << "     " << gun1.getPrice() << "$" << endl;
        cout << "[2]  " << gun2.getName() << "   " <<  gun2.getDamage() << "     "  << gun2.getPrice() << "$" << endl;
        cout << "[3]  " << gun3.getName() << "   " <<  gun3.getDamage() << "     "  << gun3.getPrice() << "$" << endl;
        cout << "[4]  " << grenade2.getName() << "   " <<  grenade2.getDamage() << "     "  << grenade2.getPrice() << "$" << endl;
        cout << "[5]  " << knife.getName() << "   " <<  knife.getDamage() << "       " << knife.getPrice() << "$" << endl;
        cout << "[6]  " << sword.getName() << "   " <<  sword.getDamage() << "       " << sword.getPrice() << "$" << endl;
        cout << "[7]  " << bow.getName() << "   " <<   bow.getDamage() << "      "  << bow.getPrice() << "$" << endl;
        cout << "[8]  " << stoneSlinges.getName() << "   " <<  stoneSlinges.getDamage() << "     "  << stoneSlinges.getPrice() << "$" << endl;
        cout << "[9]  " << ninjaStar.getName() << "   " <<  ninjaStar.getDamage() << "       " << ninjaStar.getPrice() << "$" << endl;
        cout << "[10] " << needle.getName() << "   " <<   needle.getDamage() << "       "  << needle.getPrice() << "$" << endl;

    }

    void buyItem(int option){
        if (option == 1)
        {
            if (money >= gun1.getPrice())
            {
                /* code */
                if (bag.gun1->getLock()==true) {
                money -= gun1.getPrice();
                bag.gun1->setLock(false);    
                }
                
               
            }
            else
            {
                cout << "You don't have enough money!" << endl;
            }
            
        }
        else if (option == 2)
        {
            if (money >= gun2.getPrice())
            {
                /* code */
                if(bag.gun2->getLock()==true) {
                money -= gun2.getPrice();  
                bag.gun2->setLock(false);  
                }
                
            }
            else
            {
                cout << "You don't have enough money!" << endl;
            }
            
        }
        else if (option == 3)
        {
            if (money >= gun3.getPrice())
            {
                /* code */
                if(bag.gun3->getLock()==true) {
                money -= gun3.getPrice();  
                bag.gun3->setLock(false);  
                }
                
            }
            else
            {
                cout << "You don't have enough money!" << endl;
            }
            
        }
        else if (option == 4)
        {
            if (money >= grenade2.getPrice())
            {
                /* code */
                if(bag.grenade2->getLock()==true) {
                money -= grenade2.getPrice();  
                bag.grenade2->setLock(false);  
                }
            }
            else
            {
                cout << "You don't have enough money!" << endl;
            }
            
        }
        else if (option == 5)
        {
            if (money >= knife.getPrice())
            {
                /* code */
                if(bag.knife->getLock()==true) {
                money -= knife.getPrice();  
                bag.knife->setLock(false);  
                }
            }
            else
            {
                cout << "You don't have enough money!" << endl;
            }
            
        }
        else if (option == 6)
        {
            if (money >= sword.getPrice())
            {
                /* code */
                if(bag.sword->getLock()==true) {
                money -= sword.getPrice();  
                bag.sword->setLock(false);  
                }
            }
            else
            {
                cout << "You don't have enough money!" << endl;
            }
            
        }
        else if (option == 7)
        {
            if (money >= bow.getPrice())
            {
                /* code */
                if(bag.bow->getLock()==true) {
                money -= bow.getPrice();  
                bag.bow->setLock(false);  
                }
               
            }
            else
            {
                cout << "You don't have enough money!" << endl;
            }
            
        }
        else if (option == 8)
        {
            if (money >= stoneSlinges.getPrice())
            {
                /* code */
                if(bag.stoneSling->getLock()==true) {
                money -= stoneSlinges.getPrice();  
                bag.stoneSling->setLock(false);  
                }
                
            }
            else
            {
                cout << "You don't have enough money!" << endl;
            }
            
        }
        else if (option == 9)
        {
            if (money >= ninjaStar.getPrice())
            {
                /* code */
                if(bag.ninjaStar->getLock()==true) {
                money -= ninjaStar.getPrice();  
                bag.ninjaStar->setLock(false);  
                }
            }
            else
            {
                cout << "You don't have enough money!" << endl;
            }
            
        }
        else if (option == 10)
        {
            if (money >= needle.getPrice())
            {
                /* code */
                if(bag.needle->getLock()==true) {
                money -= needle.getPrice();  
                bag.needle->setLock(false);  
                }
            }
            else
            {
                cout << "You don't have enough money!" << endl;
            }
            
        }
        

    }
    friend class Fight;
};


class skills
{
private:
    int luck;
    int aditionalPower;
    int aditionalHealth;

public:
    skills() = default;
    skills(int luck, int aditionalPower, int aditionalHealth);
    
    int getLuck(){
        return luck;
    }
    int getAditionalHealth(){
        return aditionalHealth;
    }
    int getAditionalPower(){
        return aditionalPower;
    }

    void increaseLuck(int luck){
        this->luck += luck;
    }
    void increasePower(int additionalPower){
        this->aditionalHealth += additionalPower;
    }
    void increaseHealth(int additionalHealth){
        this->aditionalHealth += additionalHealth;
    }

};

skills::skills(int luck, int aditionalPower, int aditionalHealth)
{
    this->luck = luck;
    this->aditionalPower = aditionalPower;
    this->aditionalHealth = aditionalHealth;
}

class Fight 
{
public:
    //int InitiatorOfTheFight;
    
    void ChoiceOfAction(string choice) {
        if (choice=="Upgread"){

        }
        else if (choice =="Items") {

        }
        else if (choice == "Fight") {

        }
    }

};




int main()
{
    firearm shotgun = firearm("Shotgun",60,1200,false);
    firearm sniper = firearm("Sniper",80,1500,false);
    firearm rifle = firearm("Rifle",40,800,false);
    firearm granade = firearm("Granade",120,100,false);

    coldWeapon knife = coldWeapon("Knife",10,50,false);
    coldWeapon sword = coldWeapon("Sword",20,150,false);
    coldWeapon bow = coldWeapon("Bow",30,250,false);

    throwableWeapon ninjaStar = throwableWeapon("Ninja Star",15,100,false);
    throwableWeapon needle = throwableWeapon("Neeedle",5,30,false);
    throwableWeapon stoneSlinge = throwableWeapon("Stone Sling",8,40,false);

    shop Shop = shop(shotgun,sniper,rifle,granade,knife,sword,bow,stoneSlinge,ninjaStar,needle);

    skills Skills;
    
    return 0;
}