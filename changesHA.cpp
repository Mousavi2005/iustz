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
    firearm* grenade;
    firearm* grenade2;
    // Cold Weapons
    coldWeapon* knife;
    coldWeapon* knife2;
    coldWeapon* knife3;
    // Throwable
    throwableWeapon* stone;
    throwableWeapon* ninjaStar;
    throwableWeapon* TRknife;
    
};
static Backpack bag;
class shop
{
private:
    // Firearms
    firearm gun1;
    firearm gun2;
    firearm grenade; 
    firearm grenade2;
    // Cold Weapons
    coldWeapon knife;
    coldWeapon knife2;
    coldWeapon knife3;
    // Throwable
    throwableWeapon stone;
    throwableWeapon ninjaStar;
    throwableWeapon TRknife;

    int money;
public:
    void increaseMoney(int m){
        money += m;
    }
    void decreaseMoney(int m){
        money -= m;
    }
    void showShop(){
        cout << "[1] " << gun1.getName() << "   " << gun1.getPrice() << " $" << endl;
        cout << "[2] " << gun2.getName() << "   " << gun2.getPrice() << " $" << endl;
        cout << "[3] " << grenade.getName() << "   " << grenade.getPrice() << " $" << endl;
        cout << "[4] " << grenade2.getName() << "   " << grenade2.getPrice() << " $" << endl;
        cout << "[5] " << knife.getName() << "   " << knife.getPrice() << " $" << endl;
        cout << "[6] " << knife2.getName() << "   " << knife2.getPrice() << " $" << endl;
        cout << "[7] " << knife3.getName() << "   " << knife3.getPrice() << " $" << endl;
        cout << "[8] " << stone.getName() << "   " << stone.getPrice() << " $" << endl;
        cout << "[9] " << ninjaStar.getName() << "   " << ninjaStar.getPrice() << " $" << endl;
        cout << "[10] " << TRknife.getName() << "   " << TRknife.getPrice() << " $" << endl;


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
            if (money >= grenade.getPrice())
            {
                /* code */
                if(bag.grenade->getLock()==true) {
                money -= grenade.getPrice();  
                bag.grenade->setLock(false);  
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
            if (money >= knife2.getPrice())
            {
                /* code */
                if(bag.knife2->getLock()==true) {
                money -= knife2.getPrice();  
                bag.knife2->setLock(false);  
                }
            }
            else
            {
                cout << "You don't have enough money!" << endl;
            }
            
        }
        else if (option == 7)
        {
            if (money >= knife3.getPrice())
            {
                /* code */
                if(bag.knife3->getLock()==true) {
                money -= knife3.getPrice();  
                bag.knife3->setLock(false);  
                }
               
            }
            else
            {
                cout << "You don't have enough money!" << endl;
            }
            
        }
        else if (option == 8)
        {
            if (money >= stone.getPrice())
            {
                /* code */
                if(bag.stone->getLock()==true) {
                money -= stone.getPrice();  
                bag.stone->setLock(false);  
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
            if (money >= TRknife.getPrice())
            {
                /* code */
                if(bag.TRknife->getLock()==true) {
                money -= TRknife.getPrice();  
                bag.TRknife->setLock(false);  
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
    
    return 0;
}