#include <iostream>
#include <vector>
#include <ctime>
#include <stdlib.h>
#include <string>
#include <iomanip>
class Item
{
private:
    std::string Name;
    int Energy;
    int Damage;
    int Price;
    int Number;
 public:
    Item(int energy,int damage,int price,std::string name,int number);
    void SetEnergy(int energy);
    void SetDamage(int damage);
    void SetPrice(int price);
    void SetName(std::string name);
    void SetNumber(int number);
    void IncreaseNumber(int a);
    void ReduceNumber(int a);
    int GetEnergy();
    int GetDamage();
    int GetPrice();
    std::string GetName();
    int GetNumber();
    
};
class Temporary :public Item
{
private:
    
public:
    Temporary(int energy,int damage,int price,int number,std::string name) ;
    void ReduceNumber();
    void AddNumber();
};
class Throwable :public Temporary
{
public:
    Throwable(int energy,int damage,int price,int number, std::string name);
};
class Consumables :public Temporary
{
public:
    Consumables(int energy,int damage,int price,int number, std::string name);

};
class Permanent :public Item
{
public:
    Permanent(int energy,int damage,int price,std::string name) ;
};
class Firearm :public Permanent
{
public:
   Firearm (int energy,int damage,int price,std::string name) ;
    int GetType();

};
class ColdWeapon : public Permanent
{
public:
   ColdWeapon (int energy,int damage,int price,std::string name) ;
    int GetType();
};
class Character
{
private:
    std::string Name;
    int Health ;
    int Stamina ;
    Item* CurrentWeapon;
    Item* ConsumerItem;
    std::vector<Item*> Bagpack;
    int SkillFire;
    int SkillCold;
public:
    Character(std::string name,int health,int stamina,Item* currentWeapon,std::vector<Item*> bagpack, Item* consumerItem ,int skillfire,int skillcold);
    int GetSkillFire();
    int GetSkillCold();
    std::string GetName();
    int GetHealth();
    int GetStamina();
    Item* GetCurrentWeapon();
    Item* GetConsumerItem();
    std::vector<Item*> GetBagpack();
    void SetSkillFire(int fire);
    void SetSkillCold(int Cold);
    void SetName(std::string name);
    void SetHealth(int health);
    void SetStamina(int stamina);
    void SetCurrentWeapon(Item* currentWeapon);
    void SetConsumerItem(Item* consumerItem);
    void AddBagpack(Item* member);
    void Injury(int a);
    void Activity(int a);
};
class HumanCharacter :public Character
{
private:
    int Age;
    std::string Gender;
    int Level;
    int Point;
    int Money;
public:
    HumanCharacter(std::string name,int health,int stamina , Item* currentWeapon,Item * consumerItem,std::vector<Item*> bagpack , int skilfire , int skillcold, int age,std::string gender,int level,int point, int money) ;
    int GetAge();
    std::string GetGender();
    int GetLevel();
    int GetPoint();
    int GetMoney();
    void SetAge(int age);
    void SetGender(std::string gender);
    void IncreaseLevel(int a);
    void IncreasePoint(int a);
    void ManageMoney(int b,int a);
};
class Shop
{
private:
    Firearm Gun1;
    Firearm Gun2;
    Firearm Gun3;
    ColdWeapon knife1;
    ColdWeapon knife2;
    ColdWeapon knife3;
    Throwable Grenade1; 
    Throwable Grenade2;
    Throwable Stone;
    Throwable NinjaStar;
    Throwable TRknife;
    Consumables Beverage;
    Consumables Food;
    HumanCharacter* Player;
public:
    Shop(HumanCharacter* player);
    int GetMoney();
    void ShowShop();
    void BuyItem(int Option);
};
class Model :public Character
{
private:
    std::string Type;
    HumanCharacter* Player;
    int MoneyEnemy;
    std::string Gender;
public:
    Model(std::string name,int health,int stamina,Item* currentWeapon,Item*consumerItem,std::vector<Item*> bagpack, int skillfire,int skillcold, int moneyenemy ,std::string gender, std::string type );
    HumanCharacter* GetPlyer();
    std::string GetType();
    int GetMoney();


};
enum class State
{
Upgrade,
Item,
Fight
};
class Controller 
{
private:
    Model* Enemy;
    HumanCharacter *Player;
    State state;
public:
    Controller(Model* enemy,HumanCharacter *player);
    void StateFight();
    void ZombieFight();
};
class View :public Controller{};
class Fight 
{
private:
Model*Enemy;
HumanCharacter* Player;
public:
    Fight(Model*enemy,HumanCharacter* player);
    void ChoiceOfAction(int choice);
};
class CreateCharacter{};
class Factory
{
private:
    HumanCharacter * Player;
    std::string Kind;
public:
    Factory(HumanCharacter * player,std::string kind);
Model* CreateModel(); 
};
