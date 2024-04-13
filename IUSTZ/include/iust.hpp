#include <iostream>
#include <vector>
#include <ctime>
#include <stdlib.h>
#include <string>
#include <iomanip>
#include <windows.h>
#include <chrono>
#include <ctime>
#include <string>
#include <thread>
#include <conio.h>

#define RESEt "\033[0m"
#define RED "\033[31m"
#define BRIGHTRED "\033[91m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define WHITE "\033[37m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"


std::vector<std::string> Male_Zombie_name;
std::vector<std::string> Female_Zombie_name;
std::string Random_MaleZombie_Name(std::vector<std::string> names);
std::string Random_FemaleZombie_Name(std::vector<std::string> names);
std::string Wining_Sentence();
std::string Losing_Sentence();
bool Check_Gender(std::string name);
bool Check_Age(int age);
std::string Clock();
bool IS_Day(std::string clock);
void ShowOptions(int a);
void ShowMenu(int a);

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
    void IncreaseSkillFire(int fire) ;
    void IncreaseSkillCold(int Cold);
    void SetName(std::string name);
    void SetHealth(int health);
    void SetStamina(int stamina);
    void SetCurrentWeapon(Item* currentWeapon);
    void SetConsumerItem(Item* consumerItem) ;
    void AddBagpack(Item* member) ;
    void Injury(int b,int a) ;
    void Activity(int b ,int a) ;
};
class HumanCharacter :public Character
{
private:
    int Age;
    std::string Gender;
    int Level;
    int Point;
    int Money;
    int Money_Ratio = 1;
public:
    HumanCharacter(std::string name,int health,int stamina , Item* currentWeapon,Item * consumerItem,std::vector<Item*> bagpack , int skilfire , int skillcold, int age,std::string gender,int level,int point, int money) ;

    int GetAge();
    std::string GetGender();
    int GetLevel();
    int GetPoint();
    int GetMoney();
    float GetMoneyRatio();
    void SetAge(int age);
    void SetGender(std::string gender);
    void IncreaseLevel(int a);
    void IncreasePoint(int a);
    void ManageMoney(int b,int a);
    void Increase_MoneyRatio(int a);
    
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
    std::vector<HumanCharacter*> Players;
public:
    Shop(std::vector<HumanCharacter*> players) ;
    int GetMoney();
    void ShowShop(int a);
    void BuyItem(int Option,HumanCharacter* Player);
};
class Model :public Character
{
private:
    std::string Type;
    HumanCharacter* Player;
    int MoneyEnemy;
    std::string Gender;
public:
    Model(std::string name,int health,int stamina,Item* currentWeapon,Item*consumerItem,std::vector<Item*> bagpack, int skillfire,int skillcold, int moneyenemy ,std::string gender, std::string type ) ;
    HumanCharacter* GetPlyer();
    std::string GetType() ;
    int GetMoney();
    std::string GetGender();    
};
enum class State
{
Upgrade,
Item,
Attack
};
Firearm Gun1 (0, 11, 100, "Desert Eagle");
Firearm Gun2(0, 13, 140, "M4");
Firearm Gun3(0, 17, 130, "HK-416");
Throwable Grenade1(3, 9, 20, rand()%10 , "grenade1");
Throwable Grenade2(3, 21, 60, rand()%10 , "grenade2");
Throwable Stone(3, 4, 5, rand()%10 , "stone");
Throwable NinjaStar(3, 14, 20, rand()%10 , "ninjaStar");
Throwable TRknife(3, 8, 20, rand()%10 , "TRknife");
ColdWeapon knife1(1, 8, 20, "KA-BAR");
ColdWeapon knife2(1, 8, 20, "Fairbain-Sykes");
ColdWeapon knife3(1, 8, 20, "Sword");
Consumables Bevrage(7,0,30,rand()%10,"drink");
Consumables Food(0,6,3,rand()%10,"apple");
State ManageState(HumanCharacter* Player,Model* Enemy,State LastState);
class Controller 
{
private:
    Model* Enemy;
    std::vector<HumanCharacter*> Players;
    HumanCharacter* Player;
    State state;
public:
    Controller(Model* enemy,std::vector<HumanCharacter*> players) ;
    Controller(Model* enemy,HumanCharacter* player);
    void StateFight(State action);
    void ZombieFight();
    };
class View:public Model 
{
private:
    
public:
    
    void Display();
};
void ShowMenu2(int a, HumanCharacter*Player);
void ShowMenu3(int a, HumanCharacter* player);
class Fight 
{
private:
Model*Enemy;
std::vector<HumanCharacter*> Players;
public:
    Fight(Model*enemy,std::vector<HumanCharacter*> players);
    void ChoiceOfAction(int choice,HumanCharacter*Player);
};
class Factory
{
private:
    std::vector<HumanCharacter *> Players;
    std::string Kind;
public:
    Factory(std::vector<HumanCharacter *> players,std::string kind);
    Model* CreateModel(); 
};














