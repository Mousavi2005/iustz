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
        this->gender = gender;
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

    firearm() = default;

public:
    firearm(string name, int damage, int price);

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
    // Firearms
    firearm gun1;
    firearm gun2;
    firearm granade;
    firearm granade2;
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
        cout << "[3] " << granade.getName() << "   " << granade.getPrice() << " $" << endl;
        cout << "[4] " << granade2.getName() << "   " << granade2.getPrice() << " $" << endl;
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
                money -= gun1.getPrice();
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
                money -= gun2.getPrice();
            }
            else
            {
                cout << "You don't have enough money!" << endl;
            }
            
        }
        else if (option == 3)
        {
            if (money >= granade.getPrice())
            {
                /* code */
                money -= granade.getPrice();
            }
            else
            {
                cout << "You don't have enough money!" << endl;
            }
            
        }
        else if (option == 4)
        {
            if (money >= granade2.getPrice())
            {
                /* code */
                money -= granade2.getPrice();
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
                money -= knife.getPrice();
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
                money -= knife2.getPrice();
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
                money -= knife3.getPrice();
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
                money -= stone.getPrice();
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
                money -= ninjaStar.getPrice();
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
                money -= TRknife.getPrice();
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
    zombie ZombieOrHuman;
    void ChoiceOfAction(string choice) {
        if (choice=="Upgread"){

        }
        else if (choice =="Items") {

        }
        else if (choice == "Fight") {

        }
    }

};
int main() {

    return 0;
}


int main()
{
}