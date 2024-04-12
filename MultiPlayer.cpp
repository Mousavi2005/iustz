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
// #define TEMPC

std::string tempc = "   -> ";

std::vector<std::string> Male_Zombie_name = {"Gravus","Mortimer","Vlad","Rott","Lurch","Brainsworth","Decayne","Ghoulio","Zandar","Asher"};
std::vector<std::string> Feale_Zombie_name = {"Lorna","Zombella","Ravenna","Morgana","Celia","Zara","Svetlana","Evangeline","Zephyra","Azura"};

std::string Random_MaleZombie_Name(std::vector<std::string> names){
    srand(time(0));
    int temp = rand() % 10;
    if (temp == 0)
    {
        return names[0];
    }
    else if (temp == 1)
    {
        return names[1];
    }
    else if (temp == 2)
    {
        return names[21];
    }
    else if (temp == 3)
    {
        return names[3];
    }
    else if (temp == 4)
    {
        return names[4];
    }
    else if (temp == 5)
    {
        return names[5];
    }
    else if (temp == 6)
    {
        return names[6];
    }
    else if (temp == 7)
    {
        return names[7];
    }
    else if (temp == 8)
    {
        return names[8];
    }
    else 
        return names[9];
    
}

std::string Random_FemaleZombie_Name(std::vector<std::string> names){
    srand(time(0));
    int temp = rand() % 10;
    if (temp == 0)
    {
        return names[0];
    }
    else if (temp == 1)
    {
        return names[1];
    }
    else if (temp == 2)
    {
        return names[21];
    }
    else if (temp == 3)
    {
        return names[3];
    }
    else if (temp == 4)
    {
        return names[4];
    }
    else if (temp == 5)
    {
        return names[5];
    }
    else if (temp == 6)
    {
        return names[6];
    }
    else if (temp == 7)
    {
        return names[7];
    }
    else if (temp == 8)
    {
        return names[8];
    }
    else 
        return names[9];
    
}

// fire energy=0
//cold = 1
// ... = 3

std::string Wining_Sentence(){
    srand(time(0));
    int temporary = rand() % 5;
    if (temporary == 0)
    {
        return "congratulations! You've emerged vitorious!";
    }
    else if (temporary == 1)
    {
        return "victory is yours! well done.";
    }
    else if (temporary == 2)
    {
        return "you've triumphed over all chalenges. You win!";
    }
    else if (temporary == 3)
    {
        return "success! You've achieved the ultimate goal.";
    }
    else
    {
        return "you've proven your prowess and emerged victorious.";
    }
     
}

std::string Losing_Sentence(){
    srand(time(0));
    int temp = rand() % 5;
    if (temp == 0)
    {
        return "Alas, you have been defeated";
    }
    else if (temp == 1)
    {
        return "it's game over for you this time";

    }
    else if (temp == 2)
    {
        return "Better luck next time! You've been vanquished";
    }
    else if (temp == 3)
    {
        return "Defeat is bitter,but there is always another chance.";

    }
    else
    {
        return "Unfortunetly victory eludes you this time";
    }
    
}

bool Check_Gender(std::string name){
    if (name == "female" or name == "Female" or name == "woman" or name == "Woman")
    {
        return true;
    }
    else if (name == "male" or name == "Male" or name == "man" or name == "Man")
    {
        return true;
    }
    else
        return false;
}

bool Check_Age(int age){
    if (age <= 0 or age >= 100)
    {
        return false;
    }
    else
        return true;
    
}

std::string Clock(){

    auto currentTime = std::chrono::system_clock::now();

    std::time_t time = std::chrono::system_clock::to_time_t(currentTime);
    std::string currentTimeStr = std::ctime(&time);
    std::string clock = currentTimeStr.substr(11,2);
    return clock;
}

bool IS_Day(std::string clock){
    int x = std::stoi(clock);
    if (18 <= x or x <= 5)
    {
        return false;
    }
    else{
        return true;
    }

}

// void delay(int seconds) {
    
//     std::this_thread::sleep_for(std::chrono::seconds(seconds));

// }

void ShowOptions(int a){
    if (a ==1 )
    {
        std::cout << "Chose an option :" << std :: endl;
        std::cout << tempc << "1. Create Character " << std :: endl;
        std::cout << "2. Start The Game " << std :: endl;
    }
    else
    {
        std::cout << "Chose an option :" << std :: endl;
        std::cout << "1. Create Character " << std :: endl;
        std::cout << tempc << "2. Start The Game " << std :: endl;
    }

}

class Item
{
private:
    std::string Name;
    int Energy;
    int Damage;
    int Price;
    int Number;
 public:
    Item(int energy,int damage,int price,std::string name,int number) {
        Energy = energy;
        Damage = damage;
        Price = price;
        Name = name;
        Number = number;
    }
    void SetEnergy(int energy){
        Energy = energy;
    }
    void SetDamage(int damage){
        Damage = damage;
    }
    void SetPrice(int price){
        Price = price;
    }
    void SetName(std::string name){
        Name = name;
    }
    void SetNumber(int number){
        Number = number;
    }
    void IncreaseNumber(int a) {
        Number+=a;
    }
    void ReduceNumber(int a) {
        Number-=a;
    }
    int GetEnergy(){
        return Energy;
    }
    int GetDamage(){
        return Damage;
    }
    int GetPrice(){
        return Price;
    }
    std::string GetName(){
        return Name;
    }
    int GetNumber(){
        return Number;
    }
    
};
class Temporary :public Item
{
private:
    
public:
    Temporary(int energy,int damage,int price,int number,std::string name) :Item( energy, damage , price , name,number){}
    void ReduceNumber(){
        int a = GetNumber();
        SetNumber((a--));
    }
    void AddNumber(){
        int a = GetNumber();
        SetNumber((a++));
    }

};
class Throwable :public Temporary
{
public:
    Throwable(int energy,int damage,int price,int number, std::string name):Temporary( energy, damage, price,number,name){}
};
class Consumables :public Temporary
{
public:
    Consumables(int energy,int damage,int price,int number, std::string name):Temporary( energy, damage, price,number,name){}

};
class Permanent :public Item
{
public:
    Permanent(int energy,int damage,int price,std::string name) :Item( energy, damage,price, name,1000000) {}
};
class Firearm :public Permanent
{
public:
   Firearm (int energy,int damage,int price,std::string name) : Permanent( energy, damage,price, name) {}
    
};
class ColdWeapon : public Permanent
{
public:
   ColdWeapon (int energy,int damage,int price,std::string name) : Permanent( energy, damage,price, name) {}
    
};
class Character
{
private:
    std::string Name;
    int Health = 100;
    int Stamina = 100;
    Item* CurrentWeapon;
    Item* ConsumerItem;
    std::vector<Item*> Bagpack;
    int SkillFire;
    int SkillCold;
public:
    Character(std::string name,int health,int stamina,Item* currentWeapon,std::vector<Item*> bagpack, Item* consumerItem ,int skillfire,int skillcold)
     {
        Name = name;
        Health = health;
        Stamina = stamina;
        CurrentWeapon = currentWeapon;
        Bagpack = bagpack;
        SkillCold = skillcold;
        SkillFire = skillfire;
        ConsumerItem = consumerItem;
    }
    int GetSkillFire(){
        return SkillFire;
    }
    int GetSkillCold(){
        return SkillCold;
    }
    std::string GetName(){
        return Name;
    }
    int GetHealth(){
        return Health;
    }
    int GetStamina(){
        return Stamina;
    }
    Item* GetCurrentWeapon() {
        return CurrentWeapon;
    }
    Item* GetConsumerItem() {
        return ConsumerItem;
    }
    std::vector<Item*> GetBagpack(){
        return Bagpack;
    }
    void IncreaseSkillFire(int fire) {
        SkillFire += fire;
    }
    void IncreaseSkillCold(int Cold) {
        SkillCold += Cold;
    }
    void SetName(std::string name) {
        Name =name;
    }
    void SetHealth(int health) {
        Health = health;
    }
    void SetStamina(int stamina) {
        Stamina = stamina;
    }
    void SetCurrentWeapon(Item* currentWeapon) {
        this->CurrentWeapon = currentWeapon;
    }
    void SetConsumerItem(Item* consumerItem) {
        ConsumerItem = consumerItem;
    }
    void AddBagpack(Item* member) {
        Bagpack.push_back(member);
    }
    void Injury(int b,int a) {
        if (b == 1)
        {
            Health -= a;
        }
        else if (b == 0)
        {
            Health += a;
        }
    }
    void Activity(int b ,int a) {
        if (b == 1)
        {
            Stamina -= a;
        }
        else if (b == 0)
        {
            Stamina += a;
        }
        
    }
    
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
    HumanCharacter(std::string name,int health,int stamina , Item* currentWeapon,Item * consumerItem,std::vector<Item*> bagpack , int skilfire , int skillcold, int age,std::string gender,int level,int point, int money) : Character( name, health, stamina, currentWeapon, bagpack,consumerItem,skilfire, skillcold) {
        Age = age;
        Gender = gender;
        Level = level;
        Point = point;
        Money = money;
    }
    int GetAge() {
        return Age;
    }
    std::string GetGender() {
        return Gender;
    }
    int GetLevel() {
        return Level;
    }
    int GetPoint() {
        return Point;
    }
    int GetMoney() {
        return Money;
    }
    float GetMoneyRatio(){
        return Money_Ratio;
    }
    void SetAge(int age) {
        Age = age;
    }
    void SetGender(std::string gender) {
        Gender = gender;
    }
    void IncreaseLevel(int a) {
        Level += a;
    }
    void IncreasePoint(int a) {
        Point += a;
    }
    void ManageMoney(int b,int a) {
        if (b == 0) {
            a *= GetMoneyRatio();
            Money += a;
        }
        if (b == 1) {
            Money -= a;
        }
    }
    void Increase_MoneyRatio(int a){
        Money_Ratio += a;
    }
    
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
    Shop(std::vector<HumanCharacter*> players) : Gun1 (0, 11, 100, "gun1"),Gun2(0, 13, 140, "gun2") , Gun3(0, 17, 130, "gun3"), Grenade1(3, 9, 20, 1, "grenade"), Grenade2(3, 21, 60, 1, "TNT"), Stone(3, 4, 5, 1, "stone"), NinjaStar(3, 14, 20, 1, "ninjaStar"), TRknife(3, 8, 20, 1, "TRknife"), knife1(1, 8, 20, "knife1"), knife2(1, 8, 20, "knife2"), knife3(1, 8, 20, "knife3"),Beverage(7,0,30,1,"drink"),Food(0,6,3,1,"apple")
        {
            Players = players;
        }
    int GetMoney(){
        return Players[0]->GetMoney();
        // Gun1.GetPrice();
        // Item q(100,100,12,"sdfg",2);
        // Player->GetBagpack().push_back(&q);
        
        
    }
    void ShowShop(int a)
    {   
        if (a == 1)
        {
            std::cout<< "Welcome to shop \n";
            std::cout<<"----------------------------------- \n";
            std::cout<< tempc << "1 ." << RED << Gun1.GetName() << "      " << WHITE << Gun1.GetPrice() << "$" << "\n" ;
            std::cout<<"2 ." << RED << Gun2.GetName() << "      " << WHITE << Gun2.GetPrice() << "$" << "\n" << WHITE;
            std::cout<<"3 ." << RED << Gun3.GetName() << "      " << WHITE << Gun3.GetPrice() << "$" << "\n" << WHITE;
            std::cout<<"4 ." << BLUE << knife1.GetName() << "    " << WHITE << knife1.GetPrice() << " $" << "\n" << WHITE;
            std::cout<<"5 ." << BLUE << knife2.GetName() << "    " << WHITE << knife2.GetPrice() << " $" << "\n" << WHITE;
            std::cout<<"6 ." << BLUE << knife3.GetName() << "    " << WHITE << knife3.GetPrice() << " $" << "\n"<< WHITE;
            std::cout<<"7 ." << YELLOW << Grenade1.GetName() << "   " << WHITE << Grenade1.GetPrice() << " $" << "\n"<< WHITE;
            std::cout<<"8 ." << YELLOW << Grenade2.GetName() << "       " << WHITE << Grenade2.GetPrice() << " $" << "\n"<< WHITE;
            std::cout<<"9 ." << YELLOW << Stone.GetName() << "     " << WHITE << Stone.GetPrice() << "  $" << "\n";
            std::cout<<"10." << RED << NinjaStar.GetName() << " " << WHITE << NinjaStar.GetPrice() << " $" << "\n"<< WHITE;
            std::cout<<"11." << RED << TRknife.GetName() << "   " << WHITE << TRknife.GetPrice() << " $" << "\n"<< WHITE;
            std::cout<<"12." << CYAN << Beverage.GetName() << "     " << WHITE << Beverage.GetPrice() << " $" << "\n"<< WHITE;
            std::cout<<"13." << GREEN << Food.GetName() << "     " << WHITE << Food.GetPrice() << "  $\n";
            std::cout << "14." << RED << "Exit\n" << WHITE;
        }
        else if (a == 2)
        {
            std::cout<< "Welcome to shop \n";
            std::cout<<"----------------------------------- \n";
            std::cout<< "1 ." << RED << Gun1.GetName() << "      " << WHITE << Gun1.GetPrice() << "$" << "\n" ;
            std::cout<< tempc <<"2 ." << RED << Gun2.GetName() << "      " << WHITE << Gun2.GetPrice() << "$" << "\n" << WHITE;
            std::cout<<"3 ." << RED << Gun3.GetName() << "      " << WHITE << Gun3.GetPrice() << "$" << "\n" << WHITE;
            std::cout<<"4 ." << BLUE << knife1.GetName() << "    " << WHITE << knife1.GetPrice() << " $" << "\n" << WHITE;
            std::cout<<"5 ." << BLUE << knife2.GetName() << "    " << WHITE << knife2.GetPrice() << " $" << "\n" << WHITE;
            std::cout<<"6 ." << BLUE << knife3.GetName() << "    " << WHITE << knife3.GetPrice() << " $" << "\n"<< WHITE;
            std::cout<<"7 ." << YELLOW << Grenade1.GetName() << "   " << WHITE << Grenade1.GetPrice() << " $" << "\n"<< WHITE;
            std::cout<<"8 ." << YELLOW << Grenade2.GetName() << "       " << WHITE << Grenade2.GetPrice() << " $" << "\n"<< WHITE;
            std::cout<<"9 ." << YELLOW << Stone.GetName() << "     " << WHITE << Stone.GetPrice() << "  $" << "\n";
            std::cout<<"10." << RED << NinjaStar.GetName() << " " << WHITE << NinjaStar.GetPrice() << " $" << "\n"<< WHITE;
            std::cout<<"11." << RED << TRknife.GetName() << "   " << WHITE << TRknife.GetPrice() << " $" << "\n"<< WHITE;
            std::cout<<"12." << CYAN << Beverage.GetName() << "     " << WHITE << Beverage.GetPrice() << " $" << "\n"<< WHITE;
            std::cout<<"13." << GREEN << Food.GetName() << "     " << WHITE << Food.GetPrice() << "  $\n";
            std::cout << "14." << RED << "Exit\n" << WHITE;
        }
        else if (a == 3)
        {
            std::cout<< "Welcome to shop \n";
            std::cout<<"----------------------------------- \n";
            std::cout<< "1 ." << RED << Gun1.GetName() << "      " << WHITE << Gun1.GetPrice() << "$" << "\n" ;
            std::cout<<"2 ." << RED << Gun2.GetName() << "      " << WHITE << Gun2.GetPrice() << "$" << "\n" << WHITE;
            std::cout<< tempc <<"3 ." << RED << Gun3.GetName() << "      " << WHITE << Gun3.GetPrice() << "$" << "\n" << WHITE;
            std::cout<<"4 ." << BLUE << knife1.GetName() << "    " << WHITE << knife1.GetPrice() << " $" << "\n" << WHITE;
            std::cout<<"5 ." << BLUE << knife2.GetName() << "    " << WHITE << knife2.GetPrice() << " $" << "\n" << WHITE;
            std::cout<<"6 ." << BLUE << knife3.GetName() << "    " << WHITE << knife3.GetPrice() << " $" << "\n"<< WHITE;
            std::cout<<"7 ." << YELLOW << Grenade1.GetName() << "   " << WHITE << Grenade1.GetPrice() << " $" << "\n"<< WHITE;
            std::cout<<"8 ." << YELLOW << Grenade2.GetName() << "       " << WHITE << Grenade2.GetPrice() << " $" << "\n"<< WHITE;
            std::cout<<"9 ." << YELLOW << Stone.GetName() << "     " << WHITE << Stone.GetPrice() << "  $" << "\n";
            std::cout<<"10." << RED << NinjaStar.GetName() << " " << WHITE << NinjaStar.GetPrice() << " $" << "\n"<< WHITE;
            std::cout<<"11." << RED << TRknife.GetName() << "   " << WHITE << TRknife.GetPrice() << " $" << "\n"<< WHITE;
            std::cout<<"12." << CYAN << Beverage.GetName() << "     " << WHITE << Beverage.GetPrice() << " $" << "\n"<< WHITE;
            std::cout<<"13." << GREEN << Food.GetName() << "     " << WHITE << Food.GetPrice() << "  $\n";
            std::cout << "14." << RED << "Exit\n" << WHITE;
        }
        else if (a == 4)
        {
            std::cout<< "Welcome to shop \n";
            std::cout<<"----------------------------------- \n";
            std::cout<<"1 ." << RED << Gun1.GetName() << "      " << WHITE << Gun1.GetPrice() << "$" << "\n" ;
            std::cout<<"2 ." << RED << Gun2.GetName() << "      " << WHITE << Gun2.GetPrice() << "$" << "\n" << WHITE;
            std::cout<<"3 ." << RED << Gun3.GetName() << "      " << WHITE << Gun3.GetPrice() << "$" << "\n" << WHITE;
            std::cout<< tempc <<"4 ." << BLUE << knife1.GetName() << "    " << WHITE << knife1.GetPrice() << " $" << "\n" << WHITE;
            std::cout<<"5 ." << BLUE << knife2.GetName() << "    " << WHITE << knife2.GetPrice() << " $" << "\n" << WHITE;
            std::cout<<"6 ." << BLUE << knife3.GetName() << "    " << WHITE << knife3.GetPrice() << " $" << "\n"<< WHITE;
            std::cout<<"7 ." << YELLOW << Grenade1.GetName() << "   " << WHITE << Grenade1.GetPrice() << " $" << "\n"<< WHITE;
            std::cout<<"8 ." << YELLOW << Grenade2.GetName() << "       " << WHITE << Grenade2.GetPrice() << " $" << "\n"<< WHITE;
            std::cout<<"9 ." << YELLOW << Stone.GetName() << "     " << WHITE << Stone.GetPrice() << "  $" << "\n";
            std::cout<<"10." << RED << NinjaStar.GetName() << " " << WHITE << NinjaStar.GetPrice() << " $" << "\n"<< WHITE;
            std::cout<<"11." << RED << TRknife.GetName() << "   " << WHITE << TRknife.GetPrice() << " $" << "\n"<< WHITE;
            std::cout<<"12." << CYAN << Beverage.GetName() << "     " << WHITE << Beverage.GetPrice() << " $" << "\n"<< WHITE;
            std::cout<<"13." << GREEN << Food.GetName() << "     " << WHITE << Food.GetPrice() << "  $\n";
            std::cout << "14." << RED << "Exit\n" << WHITE;
        }        
        else if (a == 5)
        {
            std::cout<< "Welcome to shop \n";
            std::cout<<"----------------------------------- \n";
            std::cout<< "1 ." << RED << Gun1.GetName() << "      " << WHITE << Gun1.GetPrice() << "$" << "\n" ;
            std::cout<<"2 ." << RED << Gun2.GetName() << "      " << WHITE << Gun2.GetPrice() << "$" << "\n" << WHITE;
            std::cout<<"3 ." << RED << Gun3.GetName() << "      " << WHITE << Gun3.GetPrice() << "$" << "\n" << WHITE;
            std::cout<<"4 ." << BLUE << knife1.GetName() << "    " << WHITE << knife1.GetPrice() << " $" << "\n" << WHITE;
            std::cout<< tempc <<"5 ." << BLUE << knife2.GetName() << "    " << WHITE << knife2.GetPrice() << " $" << "\n" << WHITE;
            std::cout<<"6 ." << BLUE << knife3.GetName() << "    " << WHITE << knife3.GetPrice() << " $" << "\n"<< WHITE;
            std::cout<<"7 ." << YELLOW << Grenade1.GetName() << "   " << WHITE << Grenade1.GetPrice() << " $" << "\n"<< WHITE;
            std::cout<<"8 ." << YELLOW << Grenade2.GetName() << "       " << WHITE << Grenade2.GetPrice() << " $" << "\n"<< WHITE;
            std::cout<<"9 ." << YELLOW << Stone.GetName() << "     " << WHITE << Stone.GetPrice() << "  $" << "\n";
            std::cout<<"10." << RED << NinjaStar.GetName() << " " << WHITE << NinjaStar.GetPrice() << " $" << "\n"<< WHITE;
            std::cout<<"11." << RED << TRknife.GetName() << "   " << WHITE << TRknife.GetPrice() << " $" << "\n"<< WHITE;
            std::cout<<"12." << CYAN << Beverage.GetName() << "     " << WHITE << Beverage.GetPrice() << " $" << "\n"<< WHITE;
            std::cout<<"13." << GREEN << Food.GetName() << "     " << WHITE << Food.GetPrice() << "  $\n";
            std::cout << "14." << RED << "Exit\n" << WHITE;
        }        
        else if (a == 6)
        {
            std::cout<< "Welcome to shop \n";
            std::cout<<"----------------------------------- \n";
            std::cout<< "1 ." << RED << Gun1.GetName() << "      " << WHITE << Gun1.GetPrice() << "$" << "\n" ;
            std::cout<<"2 ." << RED << Gun2.GetName() << "      " << WHITE << Gun2.GetPrice() << "$" << "\n" << WHITE;
            std::cout<<"3 ." << RED << Gun3.GetName() << "      " << WHITE << Gun3.GetPrice() << "$" << "\n" << WHITE;
            std::cout<<"4 ." << BLUE << knife1.GetName() << "    " << WHITE << knife1.GetPrice() << " $" << "\n" << WHITE;
            std::cout<<"5 ." << BLUE << knife2.GetName() << "    " << WHITE << knife2.GetPrice() << " $" << "\n" << WHITE;
            std::cout<< tempc <<"6 ." << BLUE << knife3.GetName() << "    " << WHITE << knife3.GetPrice() << " $" << "\n"<< WHITE;
            std::cout<<"7 ." << YELLOW << Grenade1.GetName() << "   " << WHITE << Grenade1.GetPrice() << " $" << "\n"<< WHITE;
            std::cout<<"8 ." << YELLOW << Grenade2.GetName() << "       " << WHITE << Grenade2.GetPrice() << " $" << "\n"<< WHITE;
            std::cout<<"9 ." << YELLOW << Stone.GetName() << "     " << WHITE << Stone.GetPrice() << "  $" << "\n";
            std::cout<<"10." << RED << NinjaStar.GetName() << " " << WHITE << NinjaStar.GetPrice() << " $" << "\n"<< WHITE;
            std::cout<<"11." << RED << TRknife.GetName() << "   " << WHITE << TRknife.GetPrice() << " $" << "\n"<< WHITE;
            std::cout<<"12." << CYAN << Beverage.GetName() << "     " << WHITE << Beverage.GetPrice() << " $" << "\n"<< WHITE;
            std::cout<<"13." << GREEN << Food.GetName() << "     " << WHITE << Food.GetPrice() << "  $\n";
            std::cout << "14." << RED << "Exit\n" << WHITE;
        }        
        else if (a == 7)
        {
            std::cout<< "Welcome to shop \n";
            std::cout<<"----------------------------------- \n";
            std::cout<< "1 ." << RED << Gun1.GetName() << "      " << WHITE << Gun1.GetPrice() << "$" << "\n" ;
            std::cout<<"2 ." << RED << Gun2.GetName() << "      " << WHITE << Gun2.GetPrice() << "$" << "\n" << WHITE;
            std::cout<<"3 ." << RED << Gun3.GetName() << "      " << WHITE << Gun3.GetPrice() << "$" << "\n" << WHITE;
            std::cout<<"4 ." << BLUE << knife1.GetName() << "    " << WHITE << knife1.GetPrice() << " $" << "\n" << WHITE;
            std::cout<<"5 ." << BLUE << knife2.GetName() << "    " << WHITE << knife2.GetPrice() << " $" << "\n" << WHITE;
            std::cout<<"6 ." << BLUE << knife3.GetName() << "    " << WHITE << knife3.GetPrice() << " $" << "\n"<< WHITE;
            std::cout<< tempc << "7 ." << YELLOW << Grenade1.GetName() << "   " << WHITE << Grenade1.GetPrice() << " $" << "\n"<< WHITE;
            std::cout<<"8 ." << YELLOW << Grenade2.GetName() << "       " << WHITE << Grenade2.GetPrice() << " $" << "\n"<< WHITE;
            std::cout<<"9 ." << YELLOW << Stone.GetName() << "     " << WHITE << Stone.GetPrice() << "  $" << "\n";
            std::cout<<"10." << RED << NinjaStar.GetName() << " " << WHITE << NinjaStar.GetPrice() << " $" << "\n"<< WHITE;
            std::cout<<"11." << RED << TRknife.GetName() << "   " << WHITE << TRknife.GetPrice() << " $" << "\n"<< WHITE;
            std::cout<<"12." << CYAN << Beverage.GetName() << "     " << WHITE << Beverage.GetPrice() << " $" << "\n"<< WHITE;
            std::cout<<"13." << GREEN << Food.GetName() << "     " << WHITE << Food.GetPrice() << "  $\n";
            std::cout << "14." << RED << "Exit\n" << WHITE;
        }        
        else if (a == 8)
        {
            std::cout<< "Welcome to shop \n";
            std::cout<<"----------------------------------- \n";
            std::cout<< "1 ." << RED << Gun1.GetName() << "      " << WHITE << Gun1.GetPrice() << "$" << "\n" ;
            std::cout<<"2 ." << RED << Gun2.GetName() << "      " << WHITE << Gun2.GetPrice() << "$" << "\n" << WHITE;
            std::cout<<"3 ." << RED << Gun3.GetName() << "      " << WHITE << Gun3.GetPrice() << "$" << "\n" << WHITE;
            std::cout<<"4 ." << BLUE << knife1.GetName() << "    " << WHITE << knife1.GetPrice() << " $" << "\n" << WHITE;
            std::cout<<"5 ." << BLUE << knife2.GetName() << "    " << WHITE << knife2.GetPrice() << " $" << "\n" << WHITE;
            std::cout<<"6 ." << BLUE << knife3.GetName() << "    " << WHITE << knife3.GetPrice() << " $" << "\n"<< WHITE;
            std::cout<<"7 ." << YELLOW << Grenade1.GetName() << "   " << WHITE << Grenade1.GetPrice() << " $" << "\n"<< WHITE;
            std::cout<< tempc << "8 ." << YELLOW << Grenade2.GetName() << "       " << WHITE << Grenade2.GetPrice() << " $" << "\n"<< WHITE;
            std::cout<<"9 ." << YELLOW << Stone.GetName() << "     " << WHITE << Stone.GetPrice() << "  $" << "\n";
            std::cout<<"10." << RED << NinjaStar.GetName() << " " << WHITE << NinjaStar.GetPrice() << " $" << "\n"<< WHITE;
            std::cout<<"11." << RED << TRknife.GetName() << "   " << WHITE << TRknife.GetPrice() << " $" << "\n"<< WHITE;
            std::cout<<"12." << CYAN << Beverage.GetName() << "     " << WHITE << Beverage.GetPrice() << " $" << "\n"<< WHITE;
            std::cout<<"13." << GREEN << Food.GetName() << "     " << WHITE << Food.GetPrice() << "  $\n";
            std::cout << "14." << RED << "Exit\n" << WHITE;
        }
        else if (a == 9)
        {
            std::cout<< "Welcome to shop \n";
            std::cout<<"----------------------------------- \n";
            std::cout<< "1 ." << RED << Gun1.GetName() << "      " << WHITE << Gun1.GetPrice() << "$" << "\n" ;
            std::cout<<"2 ." << RED << Gun2.GetName() << "      " << WHITE << Gun2.GetPrice() << "$" << "\n" << WHITE;
            std::cout<<"3 ." << RED << Gun3.GetName() << "      " << WHITE << Gun3.GetPrice() << "$" << "\n" << WHITE;
            std::cout<<"4 ." << BLUE << knife1.GetName() << "    " << WHITE << knife1.GetPrice() << " $" << "\n" << WHITE;
            std::cout<<"5 ." << BLUE << knife2.GetName() << "    " << WHITE << knife2.GetPrice() << " $" << "\n" << WHITE;
            std::cout<<"6 ." << BLUE << knife3.GetName() << "    " << WHITE << knife3.GetPrice() << " $" << "\n"<< WHITE;
            std::cout<<"7 ." << YELLOW << Grenade1.GetName() << "   " << WHITE << Grenade1.GetPrice() << " $" << "\n"<< WHITE;
            std::cout<< "8 ." << YELLOW << Grenade2.GetName() << "       " << WHITE << Grenade2.GetPrice() << " $" << "\n"<< WHITE;
            std::cout<< tempc <<"9 ." << YELLOW << Stone.GetName() << "     " << WHITE << Stone.GetPrice() << "  $" << "\n";
            std::cout<<"10." << RED << NinjaStar.GetName() << " " << WHITE << NinjaStar.GetPrice() << " $" << "\n"<< WHITE;
            std::cout<<"11." << RED << TRknife.GetName() << "   " << WHITE << TRknife.GetPrice() << " $" << "\n"<< WHITE;
            std::cout<<"12." << CYAN << Beverage.GetName() << "     " << WHITE << Beverage.GetPrice() << " $" << "\n"<< WHITE;
            std::cout<<"13." << GREEN << Food.GetName() << "     " << WHITE << Food.GetPrice() << "  $\n";
            std::cout << "14." << RED << "Exit\n" << WHITE;
        }
        else if (a == 10)
        {
            std::cout<< "Welcome to shop \n";
            std::cout<<"----------------------------------- \n";
            std::cout<< "1 ." << RED << Gun1.GetName() << "      " << WHITE << Gun1.GetPrice() << "$" << "\n" ;
            std::cout<<"2 ." << RED << Gun2.GetName() << "      " << WHITE << Gun2.GetPrice() << "$" << "\n" << WHITE;
            std::cout<<"3 ." << RED << Gun3.GetName() << "      " << WHITE << Gun3.GetPrice() << "$" << "\n" << WHITE;
            std::cout<<"4 ." << BLUE << knife1.GetName() << "    " << WHITE << knife1.GetPrice() << " $" << "\n" << WHITE;
            std::cout<<"5 ." << BLUE << knife2.GetName() << "    " << WHITE << knife2.GetPrice() << " $" << "\n" << WHITE;
            std::cout<<"6 ." << BLUE << knife3.GetName() << "    " << WHITE << knife3.GetPrice() << " $" << "\n"<< WHITE;
            std::cout<<"7 ." << YELLOW << Grenade1.GetName() << "   " << WHITE << Grenade1.GetPrice() << " $" << "\n"<< WHITE;
            std::cout<< "8 ." << YELLOW << Grenade2.GetName() << "       " << WHITE << Grenade2.GetPrice() << " $" << "\n"<< WHITE;
            std::cout<<"9 ." << YELLOW << Stone.GetName() << "     " << WHITE << Stone.GetPrice() << "  $" << "\n";
            std::cout<< tempc << "10." << RED << NinjaStar.GetName() << " " << WHITE << NinjaStar.GetPrice() << " $" << "\n"<< WHITE;
            std::cout<<"11." << RED << TRknife.GetName() << "   " << WHITE << TRknife.GetPrice() << " $" << "\n"<< WHITE;
            std::cout<<"12." << CYAN << Beverage.GetName() << "     " << WHITE << Beverage.GetPrice() << " $" << "\n"<< WHITE;
            std::cout<<"13." << GREEN << Food.GetName() << "     " << WHITE << Food.GetPrice() << "  $\n";
            std::cout << "14." << RED << "Exit\n" << WHITE;
        }
        else if (a == 11)
        {
            std::cout<< "Welcome to shop \n";
            std::cout<<"----------------------------------- \n";
            std::cout<< "1 ." << RED << Gun1.GetName() << "      " << WHITE << Gun1.GetPrice() << "$" << "\n" ;
            std::cout<<"2 ." << RED << Gun2.GetName() << "      " << WHITE << Gun2.GetPrice() << "$" << "\n" << WHITE;
            std::cout<<"3 ." << RED << Gun3.GetName() << "      " << WHITE << Gun3.GetPrice() << "$" << "\n" << WHITE;
            std::cout<<"4 ." << BLUE << knife1.GetName() << "    " << WHITE << knife1.GetPrice() << " $" << "\n" << WHITE;
            std::cout<<"5 ." << BLUE << knife2.GetName() << "    " << WHITE << knife2.GetPrice() << " $" << "\n" << WHITE;
            std::cout<<"6 ." << BLUE << knife3.GetName() << "    " << WHITE << knife3.GetPrice() << " $" << "\n"<< WHITE;
            std::cout<<"7 ." << YELLOW << Grenade1.GetName() << "   " << WHITE << Grenade1.GetPrice() << " $" << "\n"<< WHITE;
            std::cout<< "8 ." << YELLOW << Grenade2.GetName() << "       " << WHITE << Grenade2.GetPrice() << " $" << "\n"<< WHITE;
            std::cout<<"9 ." << YELLOW << Stone.GetName() << "     " << WHITE << Stone.GetPrice() << "  $" << "\n";
            std::cout<<"10." << RED << NinjaStar.GetName() << " " << WHITE << NinjaStar.GetPrice() << " $" << "\n"<< WHITE;
            std::cout<< tempc << "11." << RED << TRknife.GetName() << "   " << WHITE << TRknife.GetPrice() << " $" << "\n"<< WHITE;
            std::cout<<"12." << CYAN << Beverage.GetName() << "     " << WHITE << Beverage.GetPrice() << " $" << "\n"<< WHITE;
            std::cout<<"13." << GREEN << Food.GetName() << "     " << WHITE << Food.GetPrice() << "  $\n";
            std::cout << "14." << RED << "Exit\n" << WHITE;
        }
        else if (a == 12)
        {
            std::cout<< "Welcome to shop \n";
            std::cout<<"----------------------------------- \n";
            std::cout<< "1 ." << RED << Gun1.GetName() << "      " << WHITE << Gun1.GetPrice() << "$" << "\n" ;
            std::cout<<"2 ." << RED << Gun2.GetName() << "      " << WHITE << Gun2.GetPrice() << "$" << "\n" << WHITE;
            std::cout<<"3 ." << RED << Gun3.GetName() << "      " << WHITE << Gun3.GetPrice() << "$" << "\n" << WHITE;
            std::cout<<"4 ." << BLUE << knife1.GetName() << "    " << WHITE << knife1.GetPrice() << " $" << "\n" << WHITE;
            std::cout<<"5 ." << BLUE << knife2.GetName() << "    " << WHITE << knife2.GetPrice() << " $" << "\n" << WHITE;
            std::cout<<"6 ." << BLUE << knife3.GetName() << "    " << WHITE << knife3.GetPrice() << " $" << "\n"<< WHITE;
            std::cout<<"7 ." << YELLOW << Grenade1.GetName() << "   " << WHITE << Grenade1.GetPrice() << " $" << "\n"<< WHITE;
            std::cout<< "8 ." << YELLOW << Grenade2.GetName() << "       " << WHITE << Grenade2.GetPrice() << " $" << "\n"<< WHITE;
            std::cout<<"9 ." << YELLOW << Stone.GetName() << "     " << WHITE << Stone.GetPrice() << "  $" << "\n";
            std::cout<<"10." << RED << NinjaStar.GetName() << " " << WHITE << NinjaStar.GetPrice() << " $" << "\n"<< WHITE;
            std::cout<<"11." << RED << TRknife.GetName() << "   " << WHITE << TRknife.GetPrice() << " $" << "\n"<< WHITE;
            std::cout<< tempc << "12." << CYAN << Beverage.GetName() << "     " << WHITE << Beverage.GetPrice() << " $" << "\n"<< WHITE;
            std::cout<<"13." << GREEN << Food.GetName() << "     " << WHITE << Food.GetPrice() << "  $\n";
            std::cout << "14." << RED << "Exit\n" << WHITE;
        }
        else if (a == 13)
        {
            std::cout<< "Welcome to shop \n";
            std::cout<<"----------------------------------- \n";
            std::cout<< "1 ." << RED << Gun1.GetName() << "      " << WHITE << Gun1.GetPrice() << "$" << "\n" ;
            std::cout<<"2 ." << RED << Gun2.GetName() << "      " << WHITE << Gun2.GetPrice() << "$" << "\n" << WHITE;
            std::cout<<"3 ." << RED << Gun3.GetName() << "      " << WHITE << Gun3.GetPrice() << "$" << "\n" << WHITE;
            std::cout<<"4 ." << BLUE << knife1.GetName() << "    " << WHITE << knife1.GetPrice() << " $" << "\n" << WHITE;
            std::cout<<"5 ." << BLUE << knife2.GetName() << "    " << WHITE << knife2.GetPrice() << " $" << "\n" << WHITE;
            std::cout<<"6 ." << BLUE << knife3.GetName() << "    " << WHITE << knife3.GetPrice() << " $" << "\n"<< WHITE;
            std::cout<<"7 ." << YELLOW << Grenade1.GetName() << "   " << WHITE << Grenade1.GetPrice() << " $" << "\n"<< WHITE;
            std::cout<< "8 ." << YELLOW << Grenade2.GetName() << "       " << WHITE << Grenade2.GetPrice() << " $" << "\n"<< WHITE;
            std::cout<<"9 ." << YELLOW << Stone.GetName() << "     " << WHITE << Stone.GetPrice() << "  $" << "\n";
            std::cout<<"10." << RED << NinjaStar.GetName() << " " << WHITE << NinjaStar.GetPrice() << " $" << "\n"<< WHITE;
            std::cout<<"11." << RED << TRknife.GetName() << "   " << WHITE << TRknife.GetPrice() << " $" << "\n"<< WHITE;
            std::cout<<"12." << CYAN << Beverage.GetName() << "     " << WHITE << Beverage.GetPrice() << " $" << "\n"<< WHITE;
            std::cout<< tempc << "13." << GREEN << Food.GetName() << "     " << WHITE << Food.GetPrice() << "  $\n";
            std::cout << "14." << RED << "Exit\n" << WHITE;
        }
        else if (a == 14)
        {
            std::cout<< "Welcome to shop \n";
            std::cout<<"----------------------------------- \n";
            std::cout<< "1 ." << RED << Gun1.GetName() << "      " << WHITE << Gun1.GetPrice() << "$" << "\n" ;
            std::cout<<"2 ." << RED << Gun2.GetName() << "      " << WHITE << Gun2.GetPrice() << "$" << "\n" << WHITE;
            std::cout<<"3 ." << RED << Gun3.GetName() << "      " << WHITE << Gun3.GetPrice() << "$" << "\n" << WHITE;
            std::cout<<"4 ." << BLUE << knife1.GetName() << "    " << WHITE << knife1.GetPrice() << " $" << "\n" << WHITE;
            std::cout<<"5 ." << BLUE << knife2.GetName() << "    " << WHITE << knife2.GetPrice() << " $" << "\n" << WHITE;
            std::cout<<"6 ." << BLUE << knife3.GetName() << "    " << WHITE << knife3.GetPrice() << " $" << "\n"<< WHITE;
            std::cout<<"7 ." << YELLOW << Grenade1.GetName() << "   " << WHITE << Grenade1.GetPrice() << " $" << "\n"<< WHITE;
            std::cout<< "8 ." << YELLOW << Grenade2.GetName() << "       " << WHITE << Grenade2.GetPrice() << " $" << "\n"<< WHITE;
            std::cout<<"9 ." << YELLOW << Stone.GetName() << "     " << WHITE << Stone.GetPrice() << "  $" << "\n";
            std::cout<<"10." << RED << NinjaStar.GetName() << " " << WHITE << NinjaStar.GetPrice() << " $" << "\n"<< WHITE;
            std::cout<<"11." << RED << TRknife.GetName() << "   " << WHITE << TRknife.GetPrice() << " $" << "\n"<< WHITE;
            std::cout<<"12." << CYAN << Beverage.GetName() << "     " << WHITE << Beverage.GetPrice() << " $" << "\n"<< WHITE;
            std::cout<<"13." << GREEN << Food.GetName() << "     " << WHITE << Food.GetPrice() << "  $\n";
            std::cout<< tempc << "14." << RED << "Exit\n" << WHITE;
        }
        
        
        // std::cout<< "Welcome to shop \n";
        // std::cout<<"----------------------------------- \n";
        // std::cout<<"1 ." << RED << Gun1.GetName() << "      " << WHITE << Gun1.GetPrice() << "$" << "\n" ;
        // std::cout<<"2 ." << RED << Gun2.GetName() << "      " << WHITE << Gun2.GetPrice() << "$" << "\n" << WHITE;
        // std::cout<<"3 ." << RED << Gun3.GetName() << "      " << WHITE << Gun3.GetPrice() << "$" << "\n" << WHITE;
        // std::cout<<"4 ." << BLUE << knife1.GetName() << "    " << WHITE << knife1.GetPrice() << " $" << "\n" << WHITE;
        // std::cout<<"5 ." << BLUE << knife2.GetName() << "    " << WHITE << knife2.GetPrice() << " $" << "\n" << WHITE;
        // std::cout<<"6 ." << BLUE << knife3.GetName() << "    " << WHITE << knife3.GetPrice() << " $" << "\n"<< WHITE;
        // std::cout<<"7 ." << YELLOW << Grenade1.GetName() << "   " << WHITE << Grenade1.GetPrice() << " $" << "\n"<< WHITE;
        // std::cout<<"8 ." << YELLOW << Grenade2.GetName() << "       " << WHITE << Grenade2.GetPrice() << " $" << "\n"<< WHITE;
        // std::cout<<"9 ." << YELLOW << Stone.GetName() << "     " << WHITE << Stone.GetPrice() << "  $" << "\n";
        // std::cout<<"10." << RED << NinjaStar.GetName() << " " << WHITE << NinjaStar.GetPrice() << " $" << "\n"<< WHITE;
        // std::cout<<"11." << RED << TRknife.GetName() << "   " << WHITE << TRknife.GetPrice() << " $" << "\n"<< WHITE;
        // std::cout<<"12." << CYAN << Beverage.GetName() << "     " << WHITE << Beverage.GetPrice() << " $" << "\n"<< WHITE;
        // std::cout<<"13." << GREEN << Food.GetName() << "     " << WHITE << Food.GetPrice() << "  $\n";
        // std::cout << "14." << RED << "Exit\n" << WHITE;

    }
    void BuyItem(int Option,HumanCharacter* Player)
    {
        int temp = 0;
        switch (Option)
        {
        case 1:
             for (Item*i:Player->GetBagpack()) {
                 if (i->GetName() == Gun1.GetName()) 
                 {
                     temp = 1;
                 }
             }
             if (temp == 1)
             std::cout <<"You have this weapon.\n";
             else
             {
                if (Player->GetMoney() >= Gun1.GetPrice()) 
                {
                    Player->ManageMoney(1,Gun1.GetPrice());
                    Player->AddBagpack(&Gun1);
                }
                else
                {
                    std::cout << "You don't have enough money!\n" ;
                }
            }
            break;
        case 2:
            //int temp = 0;
            
            for (Item*i:Player->GetBagpack()) {
                if (i->GetName() == Gun2.GetName()) 
                {
                    temp = 1;
                }
            }
            if (temp == 1)
            std::cout <<"You have this weapon.\n";
            else
            {
                if (Player->GetMoney() >= Gun2.GetPrice()) 
                {
                    Player->ManageMoney(1,Gun2.GetPrice());
                    Player->AddBagpack(&Gun2);
                }
                else
                {
                    std::cout << "You don't have enough money!\n" ;
                }
            }
            break;
        case 3:
            //int temp = 0;
            
            for (Item*i:Player->GetBagpack()) {
                if (i->GetName() == Gun3.GetName()) 
                {
                    temp = 1;
                }
            }
            if (temp == 1)
            std::cout <<"You have this weapon.\n";
            else
            {
                if (Player->GetMoney() >= Gun3.GetPrice()) 
                {
                    Player->ManageMoney(1,Gun3.GetPrice());
                    Player->AddBagpack(&Gun3);
                }
                else
                {
                    std::cout << "You don't have enough money!\n" ;
                }
            }
            break;
        case 4:
            //int temp = 0;
            
            for (Item*i:Player->GetBagpack()) {
                if (i->GetName() == knife1.GetName()) 
                {
                    temp = 1;
                }
            }
            if (temp == 1)
            std::cout <<"You have this weapon.\n";
            else
            {
                if (Player->GetMoney() >= knife1.GetPrice()) 
                {
                    Player->ManageMoney(1,knife1.GetPrice());
                    Player->AddBagpack(&knife1);
                }
                else
                {
                    std::cout << "You don't have enough money!\n" ;
                }
            }
            break;
        case 5:
            //int temp = 0;
            
            for (Item*i:Player->GetBagpack()) {
                if (i->GetName() == knife2.GetName()) 
                {
                    temp = 1;
                }
            }
            if (temp == 1)
            std::cout <<"You have this weapon.\n";
            else
            {
                if (Player->GetMoney() >= knife2.GetPrice()) 
                {
                    Player->ManageMoney(1,knife2.GetPrice());
                    Player->AddBagpack(&knife2);
                }
                else
                {
                    std::cout << "You don't have enough money!\n" ;
                }
            }
            break;
        case 6:
            //int temp = 0;
            
            for (Item*i:Player->GetBagpack()) {
                if (i->GetName() == knife3.GetName()) 
                {
                    temp = 1;
                }
            }
            if (temp == 1)
            std::cout <<"You have this weapon.\n";
            else
            {
                if (Player->GetMoney() >= knife3.GetPrice()) 
                {
                    Player->ManageMoney(1,knife3.GetPrice());
                    Player->AddBagpack(&knife3);
                }
                else
                {
                    std::cout << "You don't have enough money!\n" ;
                }
            }
            break;
        case 7:
            //int temp = 0;
            
            for (Item*i:Player->GetBagpack()) {
                if (i->GetName() == Grenade1.GetName()) 
                {
                    temp = 1;
                    i->IncreaseNumber(Grenade1.GetNumber());
                    Player->ManageMoney(1,Grenade1.GetPrice());
                }
            }
            if (temp == 1){}

            else
            {
                if (Player->GetMoney() >= Grenade1.GetPrice()) 
                {
                    Player->ManageMoney(1,Grenade1.GetPrice());
                    Player->AddBagpack(&Grenade1);
                }
                else
                {
                    std::cout << "You don't have enough money!\n" ;
                }
            }
            break;
        case 8:
            //int temp = 0;
            
            for (Item*i:Player->GetBagpack()) {
                if (i->GetName() == Grenade2.GetName()) 
                {
                    temp = 1;
                    i->IncreaseNumber(Grenade2.GetNumber());
                    Player->ManageMoney(1,Grenade2.GetPrice());
                }
            }
            if (temp == 1){}
            else
            {
                if (Player->GetMoney() >= Grenade2.GetPrice()) 
                {
                    Player->ManageMoney(1,Grenade2.GetPrice());
                    Player->AddBagpack(&Grenade2);
                }
                else
                {
                    std::cout << "You don't have enough money!\n" ;
                }
            }
            break;
        case 9:
            //int temp = 0;
            
            for (Item*i:Player->GetBagpack()) {
                if (i->GetName() == Stone.GetName()) 
                {
                    temp = 1;
                    i->IncreaseNumber(Stone.GetNumber());
                    Player->ManageMoney(1,Stone.GetPrice());
                }
            }
            if (temp == 1){}
            else
            {
                if (Player->GetMoney() >= Stone.GetPrice()) 
                {
                    Player->ManageMoney(1,Stone.GetPrice());
                    Player->AddBagpack(&Stone);
                }
                else
                {
                    std::cout << "You don't have enough money!\n" ;
                }
            }
            break;
        case 10:
            //int temp = 0;
            
            for (Item*i:Player->GetBagpack()) {
                if (i->GetName() == NinjaStar.GetName()) 
                {
                    temp = 1;
                    i->IncreaseNumber(NinjaStar.GetNumber());
                    Player->ManageMoney(1,NinjaStar.GetPrice());
                }
            }
            if (temp == 1){}
            else
            {
                if (Player->GetMoney() >= NinjaStar.GetPrice()) 
                {
                    Player->ManageMoney(1,NinjaStar.GetPrice());
                    Player->AddBagpack(&NinjaStar);
                }
                else
                {
                    std::cout << "You don't have enough money!\n" ;
                }
            }
            break;
        case 11:
            //int temp = 0;
            
            for (Item*i:Player->GetBagpack()) {
                if (i->GetName() == TRknife.GetName()) 
                {
                    temp = 1;
                    i->IncreaseNumber(TRknife.GetNumber());
                    Player->ManageMoney(1,TRknife.GetPrice());
                }
            }
            if (temp == 1){}
            else
            {
                if (Player->GetMoney() >= TRknife.GetPrice()) 
                {
                    Player->ManageMoney(1,TRknife.GetPrice());
                    Player->AddBagpack(&TRknife);
                }
                else
                {
                    std::cout << "You don't have enough money!\n" ;
                }
            }
            break;
        case 12:
            //int temp = 0;
            
            for (Item*i:Player->GetBagpack()) {
                if (i->GetName() == Beverage.GetName()) 
                {
                    temp = 1;
                    i->IncreaseNumber(Beverage.GetNumber());
                    Player->ManageMoney(1,Beverage.GetPrice());
                }
            }
            if (temp == 1){}
            else
            {
                if (Player->GetMoney() >= Beverage.GetPrice()) 
                {
                    Player->ManageMoney(1,Beverage.GetPrice());
                    Player->AddBagpack(&Beverage);
                }
                else
                {
                    std::cout << "You don't have enough money!\n" ;
                }
            }
            break;
        case 13:
            //int temp = 0;
            
            for (Item*i:Player->GetBagpack()) {
                if (i->GetName() == Food.GetName()) 
                {
                    temp = 1;
                    i->IncreaseNumber(Food.GetNumber());
                    Player->ManageMoney(1,Food.GetPrice());
                }
            }
            if (temp == 1){}
            else
            {
                if (Player->GetMoney() >= Food.GetPrice()) 
                {
                    Player->ManageMoney(1,Food.GetPrice());
                    Player->AddBagpack(&Food);
                }
                else
                {
                    std::cout << "You don't have enough money!\n" ;
                }
            }
            break;
        }
    } 
    
    
};
class Model :public Character
{
private:
    std::string Type;
    HumanCharacter* Player;
    int MoneyEnemy;
    std::string Gender;
public:
    Model(std::string name,int health,int stamina,Item* currentWeapon,Item*consumerItem,std::vector<Item*> bagpack, int skillfire,int skillcold, int moneyenemy ,std::string gender, std::string type ) :Character( name, health, stamina, currentWeapon, bagpack,consumerItem,skillfire, skillcold)
    {
        MoneyEnemy = moneyenemy;
        Type = type;
        Gender = gender;

    }
    HumanCharacter* GetPlyer()
    {
        return Player;
    }
    std::string GetType() 
    {
        return Type;
    }
    int GetMoney()
    {
        return MoneyEnemy;
    }
    std::string GetGender()
    {
        return Gender;
    }


};
enum class State
{
Upgrade,
Item,
Attack
};
Firearm Gun1 (0, 11, 100, "gun1");
Firearm Gun2(0, 13, 140, "gun2");
Firearm Gun3(0, 17, 130, "gun3");
Throwable Grenade1(3, 9, 20, rand()%10 , "grenade1");
Throwable Grenade2(3, 21, 60, rand()%10 , "grenade2");
Throwable Stone(3, 4, 5, rand()%10 , "stone");
Throwable NinjaStar(3, 14, 20, rand()%10 , "ninjaStar");
Throwable TRknife(3, 8, 20, rand()%10 , "TRknife");
ColdWeapon knife1(1, 8, 20, "knife1");
ColdWeapon knife2(1, 8, 20, "knife2");
ColdWeapon knife3(1, 8, 20, "knife3");
Consumables Bevrage(7,0,30,rand()%10,"drink");
Consumables Food(0,6,3,rand()%10,"apple");
State ManageState(HumanCharacter* Player,Model* Enemy,State LastState)
{
    if (LastState == State::Attack)
    {
        if(Enemy->GetCurrentWeapon()->GetDamage()>Player->GetHealth())
        {
            return State::Attack;
        }
        else
        {
            return State::Item;
        }

    }
    else if (LastState == State::Item)
    {
        if (Enemy->GetSkillFire()>(Player->GetSkillFire()+10))
        {
            if(Enemy->GetSkillCold()>(Player->GetSkillCold()+10))
            {
                return State::Attack;
            }
            return State::Upgrade;
        }
        return State::Upgrade;
    }
    return State::Attack;
}
class Controller 
{
private:
    Model* Enemy;
    std::vector<HumanCharacter*> Players;
    HumanCharacter* Player;
    State state;
public:
    Controller(Model* enemy,std::vector<HumanCharacter*> players) 
    {
    Enemy = enemy;
    Players = players;
    
    }
    Controller(Model* enemy,HumanCharacter* player)
    {
        Enemy = enemy;
        Player = player;
    }
    void StateFight(State action)
    {
        Item* BestFire;
        Item* BestCold;
        Item* BestConsumer;
        int BigFire = 0;
        int BigCold = 0;
        int BigConsumer = 0;
       switch (action)
       {
        case State::Attack:
            if (Enemy->GetCurrentWeapon()->GetEnergy() == 0 ) 
            {
                if (Enemy->GetConsumerItem()->GetNumber() == 0)
                {
                    if (Enemy->GetStamina()>=20)
                    {
                        // for (int i = 0; i < Players.size(); i++)
                        // {
                        //     Players[i]->Injury(1,(Enemy->GetCurrentWeapon()->GetDamage()*Enemy->GetSkillFire()));
                        // }
                        
                        Player->Injury(1,(Enemy->GetCurrentWeapon()->GetDamage()*Enemy->GetSkillFire()));
                        Enemy->Activity(1,20);
                    }
                    else
                    {
                        std::cout <<"The Enemy does not have Stamina\n";
                    }
                }
                else
                {
                   int temp = Enemy->GetConsumerItem()->GetNumber();
                   for(;temp>0;temp--)
                   {
                        if (Enemy->GetConsumerItem()->GetEnergy() == 0)
                        {
                            if (Enemy->GetConsumerItem()->GetNumber()>=1)
                            {
                                Enemy->Injury(0,Enemy->GetConsumerItem()->GetDamage());
                                Enemy->GetConsumerItem()->ReduceNumber(1);
                                //Player->Activity(1,5);
                            }
                            
                        }
                        else if (Enemy->GetConsumerItem()->GetDamage() == 0)
                        {
                            if (Enemy->GetConsumerItem()->GetNumber()>=1)
                            {
                                Enemy->Activity(0,Enemy->GetConsumerItem()->GetEnergy());
                                Enemy->GetConsumerItem()->ReduceNumber(1);
                                //Player->Activity(1,1);
                            }
                           
                        }
                        else 
                        {
                            if (Enemy->GetConsumerItem()->GetNumber()>=1)
                            {
                                // for (int i = 0; i < Players.size(); i++)
                                // {
                                //     Players[i]->Injury(1,Enemy->GetConsumerItem()->GetDamage());
                                // }
                                
                                Player->Injury(1,Enemy->GetConsumerItem()->GetDamage());
                                Enemy->GetConsumerItem()->ReduceNumber(1);
                                //Player->Activity(1,10);
                            }
                            
                        }
                   }
                   if (Enemy->GetStamina()>=20)
                    {
                        // for (int i = 0; i < Players.size(); i++)
                        // {
                        //     Players[i]->Injury(1,(Enemy->GetCurrentWeapon()->GetDamage()*Enemy->GetSkillFire()));
                        // }
                        Player->Injury(1,(Enemy->GetCurrentWeapon()->GetDamage()*Enemy->GetSkillFire()));
                        Enemy->Activity(1,20);
                    }
                    else
                    {
                        std::cout <<"The Enemy does not have Stamina\n";
                    }

                }
                
            }
            else 
            {

                    if (Enemy->GetConsumerItem()->GetNumber() == 0)
                {
                    if (Enemy->GetStamina()>=10)
                    {  
                        // for (int i = 0; i < Players.size(); i++)
                        // {
                        //     Players[i]->Injury(1,(Enemy->GetCurrentWeapon()->GetDamage()*Enemy->GetSkillCold()));
                        // }
                        
                        Player->Injury(1,(Enemy->GetCurrentWeapon()->GetDamage()*Enemy->GetSkillCold()));
                        Enemy->Activity(1,10);
                    }
                    else
                    {
                        std::cout <<"The Enemy does not have Stamina\n";
                    }
                }
                else
                {
                   int temp = Enemy->GetConsumerItem()->GetNumber();
                   for(;temp>0;temp--)
                   {
                        if (Enemy->GetConsumerItem()->GetEnergy() == 0)
                        {
                            if (Enemy->GetConsumerItem()->GetNumber()>=1)
                            {
                                Enemy->Injury(0,Enemy->GetConsumerItem()->GetDamage());
                                Enemy->GetConsumerItem()->ReduceNumber(1);
                                //Player->Activity(1,5);
                            }
                            
                        }
                        else if (Enemy->GetConsumerItem()->GetDamage() == 0)
                        {
                            if (Enemy->GetConsumerItem()->GetNumber()>=1)
                            {
                                Enemy->Activity(0,Enemy->GetConsumerItem()->GetEnergy());
                                Enemy->GetConsumerItem()->ReduceNumber(1);
                                //Player->Activity(1,1);
                            }
                           
                        }
                        else 
                        {
                            if (Enemy->GetConsumerItem()->GetNumber()>=1)
                            {
                                // for (int i = 0; i < Players.size(); i++)
                                // {
                                //     Players[i]->Injury(1,Enemy->GetConsumerItem()->GetDamage());
                                // }
                                
                                Player->Injury(1,Enemy->GetConsumerItem()->GetDamage());
                                Enemy->GetConsumerItem()->ReduceNumber(1);
                                //Player->Activity(1,10);
                            }
                            
                        }
                   }
                   if (Enemy->GetStamina()>=10)
                    {
                        // for (int i = 0; i < Players.size(); i++)
                        // {
                        //     Players[i]->Injury(1,(Enemy->GetCurrentWeapon()->GetDamage()*Enemy->GetSkillCold()));
                        // }
                        
                        Player->Injury(1,(Enemy->GetCurrentWeapon()->GetDamage()*Enemy->GetSkillCold()));
                        Enemy->Activity(1,10);
                    }
                    else
                    {
                        std::cout <<"The Enemy does not have Stamina\n";
                    }

                }

                    
            }

            break;
        case State::Item :
            
                if (Player->GetLevel()>10)
                {
                    for(Item* i:Enemy->GetBagpack())
                    {
                        if (i->GetEnergy() == 0)
                        {
                            if (i->GetDamage()*Enemy->GetSkillFire() > BigFire)
                            {
                                BigFire = i->GetDamage()*Enemy->GetSkillFire();
                                BestFire = i;
                            }
                        }
                        else if (i->GetEnergy() == 1)
                        {
                            if (i->GetDamage()*Enemy->GetSkillCold() > BigCold)
                            {
                                BigCold = i->GetDamage()*Enemy->GetSkillCold();
                                BestCold = i;
                            }
                        }

                    }
                    if (BigCold > BigFire)
                    {
                        Enemy->SetCurrentWeapon(BestCold);
                    }
                    else
                    {
                        Enemy->SetCurrentWeapon(BestFire);
                    }
                    if ((Enemy->GetHealth() < 50) && !(Enemy->GetBagpack()[12] == 0))
                    {
                      Enemy->SetConsumerItem(Enemy->GetBagpack()[12]);   
                    }
                    else
                    {
                        for(Item* i :Enemy->GetBagpack())
                        {
                            if (i->GetEnergy() == 3)
                            {
                                if ((i->GetDamage()> BigConsumer) && !(i->GetNumber() == 0))
                                {
                                    BigConsumer = i->GetDamage();
                                    Enemy->SetConsumerItem(i);
                                }
                            }
                        }
                    }
                }
                else if (Player->GetLevel()>5)
                {
                    for(Item* i:Enemy->GetBagpack())
                    {
                        if (i->GetEnergy() == 0)
                        {
                            if (i->GetDamage()+Enemy->GetSkillFire() > BigFire)
                            {
                                BigFire = i->GetDamage()+Enemy->GetSkillFire();
                                BestFire = i;
                            }
                        }
                        else if (i->GetEnergy() == 1)
                        {
                            if (i->GetDamage()+Enemy->GetSkillCold() > BigCold)
                            {
                                BigCold = i->GetDamage()+Enemy->GetSkillCold();
                                BestCold = i;
                            }
                        }

                    }
                    if (BigCold > BigFire)
                    {
                        Enemy->SetCurrentWeapon(BestCold);
                    }
                    else
                    {
                        Enemy->SetCurrentWeapon(BestFire);
                    }

                }
                else if (Player->GetLevel()<5)
                {
                    for(Item* i:Enemy->GetBagpack())
                    {
                        if (i->GetEnergy() == 0)
                        {
                            if (i->GetDamage() > BigFire)
                            {
                                BigFire = i->GetDamage();
                                BestFire = i;
                            }
                        }
                        else if (i->GetEnergy() == 1)
                        {
                            if (i->GetDamage() > BigCold)
                            {
                                BigCold = i->GetDamage();
                                BestCold = i;
                            }
                        }

                    }
                    if (BigCold > BigFire)
                    {
                        Enemy->SetCurrentWeapon(BestCold);
                    }
                    else
                    {
                        Enemy->SetCurrentWeapon(BestFire);
                    }

                }
            break;
            
        case State::Upgrade :
            if (Player->GetLevel()>10)
            {
                if (Enemy->GetCurrentWeapon()->GetEnergy() == 0)
                {
                    Enemy->IncreaseSkillFire(10);
                }
                else 
                {
                    Enemy->IncreaseSkillCold(10);
                }
            }
            else
            {
                if (Enemy->GetCurrentWeapon()->GetEnergy() == 0)
                {
                    Enemy->IncreaseSkillFire(5);
                }
                else 
                {
                    Enemy->IncreaseSkillCold(5);
                }
            }
            break;
       
        
       } 
    }
    void ZombieFight()
    {
        if (Enemy->GetCurrentWeapon()->GetEnergy() == 0 ) 
            {
                if (Enemy->GetStamina()>=20)
                {
                
                    Player->Injury(1,(Enemy->GetCurrentWeapon()->GetDamage()*Enemy->GetSkillFire()));
                
                
                // Player->Injury(1,(Enemy->GetCurrentWeapon()->GetDamage()*Enemy->GetSkillFire()));
                Enemy->Activity(1,20);
                }
                else
                {
                    std::cout <<"The Enemy does not have Stamina\n";
                }
            }
        else 
        {
                if (Enemy->GetStamina()>=10)
                {
                
                    Player->Injury(1,(Enemy->GetCurrentWeapon()->GetDamage()*Enemy->GetSkillCold()));
                
                
                // Player->Injury(1,(Enemy->GetCurrentWeapon()->GetDamage()*Enemy->GetSkillCold()));
                Enemy->Activity(1,10);
                }
                else
                {
                    std::cout <<"The Enemy does not have Stamina\n";
                }
        }
    }
};
class View:public Model 
{
private:
    //Model*Enemy;
public:
    // View(Model*enemy)
    // {
    //     Enemy = enemy;
    // }
    // Model* GetEnemy()
    // {
    //     return Enemy;
    // }
    void Display()
    {
        std::cout<<"name: "<<GetName()<<"\nGender: "<<GetGender() <<"\nType: "<<GetType()<<"\nHealth: "<<GetHealth()<<"\nStamina: "<<GetStamina()<<"\nWeapon: "<<GetCurrentWeapon()->GetName();
    }
};
class Fight 
{
private:
Model*Enemy;
std::vector<HumanCharacter*> Players;
public:
    Fight(Model*enemy,std::vector<HumanCharacter*> players)
    {
        Players = players;
        
        
        Enemy = enemy;
    }
    void ChoiceOfAction(int choice,HumanCharacter*Player) {
        while (true)
        {
            
            
        
            if (choice==1)
            {
                std::cout <<"Money:"<<Player->GetMoney()<<"$\n";
                std::cout <<"1.Increase Fire Skill By 5 Units  30$ ("<<Player->GetSkillFire() <<")"<<"\n2.Increase Cold Skill By 5 Units  20$ ";
                std::cout << "("<<Player->GetSkillCold() <<")\n";
                std::cout << "3.Increase Earning Money Ratio By 100%  60$ (" << Player->GetMoneyRatio() << ")\n";
                std::cout << "4.Exit\n";
                int Option = 0;
                
                for(;Option<4;)
                {
                    std::cin>>Option;
                    switch (Option)
                    {
                    case 1:
                        if (Player->GetMoney()>=30)
                        {
                            Player->IncreaseSkillFire(5);
                            Player->ManageMoney(1,30);
                        }
                        else {std::cout <<"You don`t have enough money!\n";}
                        
                        break;
                    case 2:
                        if (Player->GetMoney()>=20)
                        {
                            
                            Player->IncreaseSkillCold(5);
                            Player->ManageMoney(1,20);
                        }
                        else {std::cout <<"You don`t have enough money!\n";}
                        break;
                    case 3:
                        if (Player->GetMoney() >= 60)
                        {
                            
                            Player->Increase_MoneyRatio(1);
                            Player->ManageMoney(1,60);
                        }
                        else {std::cout <<"You don`t have enough money!\n";}
                        break;
                    case 4:
                        
                        break;
                    
                    default:
                        std::cout <<"Invalid Command\n";
                        break;
                    }
                
                std::cout <<"Money:"<<Player->GetMoney()<<"$\n";
                std::cout <<"1.Increase Fire Skill By 5 Units  30$ ("<<Player->GetSkillFire() <<")"<<"\n2.Increase Cold Skill By 5 Units  20$ ";
                std::cout << "("<<Player->GetSkillCold() <<")\n";
                std::cout << "3.Increase Earning Money Ratio By 100%  60$ (" << Player->GetMoneyRatio() << ")\n";
                std::cout << "4.Exit\n";    
                }
            
            }
            else if (choice ==2) 
            {
                int num = 1;
            for (Item* i :Player->GetBagpack()) 
            {
                
                    std::cout<<num<<"."<<i->GetName();
                    if (i->GetName() == Player->GetCurrentWeapon()->GetName())
                    {
                        std::cout<<"    *";
                    }
                    if (i->GetNumber()==1000000)
                    {
                        std::cout <<"\n";
                    }
                    else
                    {
                        std::cout <<"    ("<<i->GetNumber()<<")";
                        if (i->GetName() == Player->GetConsumerItem()->GetName())
                        {
                            std::cout<<"   *\n";
                        }
                    }
                    num++;
                
            } 
            int select;
            std::cin>>select;
            
            if (Player->GetBagpack()[select-1]->GetNumber()==1000000)
                    {
                        Player->SetCurrentWeapon(Player->GetBagpack()[select-1]);
                    }
                    else
                    {
                        Player->SetConsumerItem(Player->GetBagpack()[select-1]);
                    }
            
            }
            else if (choice == 3) 
            {
                std::cout<<"1.Temporary Item :"<<Player->GetConsumerItem()->GetName() <<"(" <<Player->GetConsumerItem()->GetNumber() <<")"<<"\n2.Permanent Item :"<< Player->GetCurrentWeapon()->GetName()<<"--->";
                if (Player->GetCurrentWeapon()->GetEnergy() == 0)
                {
                    std::cout<<Player->GetCurrentWeapon()->GetDamage()*Player->GetSkillFire() <<"\n";
                }
                else
                {
                    std::cout<<Player->GetCurrentWeapon()->GetDamage()*Player->GetSkillCold() <<"\n";
                }
                
                int temp = 0;
                if (Player->GetStamina()<20) 
                {
                    temp = 2;
                }
                while (temp<2)
                {
                    std::cin>>temp;
                    if (temp == 1)
                    {
                        if (Player->GetConsumerItem()->GetEnergy() == 0)
                        {
                            if (Player->GetConsumerItem()->GetNumber()>=1)
                            {
                                Player->Injury(0,Player->GetConsumerItem()->GetDamage());
                                Player->GetConsumerItem()->ReduceNumber(1);
                                Player->Activity(1,5);
                            }
                            else 
                            {
                                std::cout<<"Invalid command!\n";
                            }
                        }
                        else if (Player->GetConsumerItem()->GetDamage() == 0)
                        {
                            if (Player->GetConsumerItem()->GetNumber()>=1)
                            {
                                Player->Activity(0,Player->GetConsumerItem()->GetEnergy());
                                Player->GetConsumerItem()->ReduceNumber(1);
                                Player->Activity(1,1);
                            }
                            else 
                            {
                                std::cout<<"Invalid command!\n";
                            }
                        }
                        else 
                        {
                            if (Player->GetConsumerItem()->GetNumber()>=1)
                            {
                                Enemy->Injury(1,Player->GetConsumerItem()->GetDamage());
                                Player->GetConsumerItem()->ReduceNumber(1);
                                Player->Activity(1,10);
                            }
                            else 
                            {
                                std::cout<<"Invalid command!\n";
                            }
                        }
                        
                    }
                    else if(temp == 2) 
                    {
                        //fire
                        if (Player->GetCurrentWeapon()->GetEnergy() == 0)
                        {
                            Enemy->Injury(1,(Player->GetCurrentWeapon()->GetDamage()*Player->GetSkillFire()));
                            Player->Activity(1,20);
                        }
                        //cold
                        else 
                        {
                            Enemy->Injury(1,(Player->GetCurrentWeapon()->GetDamage()*Player->GetSkillCold()));
                            Player->Activity(1,15);
                        }
                    }
                
                    if (temp==1)
                    {
                        std::cout<<"1.Temporary Item :"<<Player->GetConsumerItem()->GetName() <<"(" <<Player->GetConsumerItem()->GetNumber() <<")"<<"\n2.Permanent Item :"<< Player->GetCurrentWeapon()->GetName()<<"--->";
                        if (Player->GetCurrentWeapon()->GetEnergy() == 0)
                        {
                            std::cout<<Player->GetCurrentWeapon()->GetDamage()*Player->GetSkillFire() <<"\n";
                        }
                        else
                        {
                            std::cout<<Player->GetCurrentWeapon()->GetDamage()*Player->GetSkillCold() <<"\n";
                        }
                    }
                }
                
                choice++;
            }
            
            if (choice == 4)
            {
                break;
            }
            std::cout <<"1.Upgrade\n2.Items\n3.Fight\n";
            std::cin>>choice;
        }
        
    }

};

class Factory
{
private:
    std::vector<HumanCharacter *> Players;
    std::string Kind;
public:
    Factory(std::vector<HumanCharacter *> players,std::string kind) {
        Kind = kind;
        for (int i = 0; i < players.size(); i++)
        {
            // --------------------------------------------------------------------
            Players.push_back(players[i]);
            // Players[i] = players[i];
        }
        
    }

Model* CreateModel() {
    if (Kind =="zombie"){
        srand(time(0));
        std::string name;
        std::string gender;
        char temp;
        for (int i = 0 ; i < 6 ;i++) {
            if (i == 0){
                temp = (char)(rand()%26+65);
                name+=temp; 
            }
            else {
            temp=char(rand()%26+97);
            name+=temp;  
            }
            
        }
        if ((rand()%2)== 0) 
        {
            gender = "Man";
        }
        else { gender = "Woman";}
        int number_5;
        int number_4;
        int number_3;
        int number_2;
        int number_1;
        int health_sum = 0;
        int stamina_sum = 0;
        number_5 = rand()%(Players.size());
        number_4 = rand()%(Players.size());
        number_3 = rand()%(Players.size());
        number_2 = rand()%(Players.size());
        number_1 = rand()%(Players.size());
        for (HumanCharacter* i:Players)
        {
            health_sum += i->GetHealth();
            stamina_sum += i->GetStamina();
        }
        
        return new Model(name,(health_sum ),(stamina_sum ),Players[number_5]->GetCurrentWeapon(), Players[number_4]->GetConsumerItem(),Players[number_3]->GetBagpack(),(Players[number_2]->GetSkillFire()+1),Players[number_1]->GetSkillCold(),0,gender,"zombie");
    }
    else if (Kind == "strongZombie"){
        srand(time(0));
        std::string name;
        std::string gender;
        char temp;
        for (int i = 0 ; i < 6 ;i++) {
            if (i == 0){
                temp = (char)(rand()%26+65);
                name+=temp; 
            }
            else {
            temp=char(rand()%26+97);
            name+=temp;  
            }
            
        }
        if ((rand()%2)== 0) 
        {
            gender = "Man";
        }
        else { gender = "Woman";}
        int number_5;
        int number_4;
        int number_3;
        int number_2;
        int number_1;
        int health_sum = 0;
        int stamina_sum = 0;
        number_5 = rand()%(Players.size());
        number_4 = rand()%(Players.size());
        number_3 = rand()%(Players.size());
        number_2 = rand()%(Players.size());
        number_1 = rand()%(Players.size());
        for (int i = 0; i < Players.size(); i++)
        {
            health_sum += Players[i]->GetHealth();
            stamina_sum += Players[i]->GetStamina();
        }
        
        return new Model(name,(health_sum * 0.95),(stamina_sum * 0.95),Players[number_5]->GetCurrentWeapon(), Players[number_4]->GetConsumerItem(),Players[number_3]->GetBagpack(),((Players[number_2]->GetSkillFire())*3),(Players[number_1]->GetSkillCold())*3,0,gender,"strongZombie");

    }
    else if (Kind == "HumanEnemy") {
        srand(time(0));
        std::string name;
        std::string gender;
        char temp;
        for (int i = 0 ; i < 6 ;i++) {
            if (i == 0){
                temp = (char)(rand()%26+65);
                name+=temp; 
            }
            else {
            temp=char(rand()%26+97);
            name+=temp;  
            }
            
        }
        if ((rand()%2)== 0) 
        {
            gender = "Man";
        }
        else { gender = "Woman";}
        std::vector <Item*>bag;
        
        bag.push_back(&Gun1);
        
        bag.push_back(&Gun2);
        
        bag.push_back(&Gun3);
        
        bag.push_back(&Grenade1);
        
        bag.push_back(&Grenade2);
        
        bag.push_back(&Stone);
        
        bag.push_back(&NinjaStar);
        
        bag.push_back(&TRknife);
        
        bag.push_back(&knife1);
        
        bag.push_back(&knife2);
        
        bag.push_back(&knife3);
        
        bag.push_back(&Bevrage);
        
        bag.push_back(&Food);

        int health_sum = 0;
        int stamina_sum = 0;
        int number_1;
        int number_2;
        int number_3;
        int number_4;
        number_1 = rand()%(Players.size());
        number_2 = rand()%(Players.size());
        number_3 = rand()%(Players.size());
        number_4 = rand()%(Players.size());
        for (int i = 0; i < Players.size(); i++)
        {
            health_sum += Players[i]->GetHealth();
            stamina_sum += Players[i]->GetStamina();
        }

        return new Model(name,(health_sum+rand()%1000+10) , (stamina_sum+(Players[number_1]->GetLevel()*10)),Players[number_2]->GetCurrentWeapon(), &Food,bag ,(Players[number_3]->GetSkillFire()+(Players[number_3]->GetLevel()*3)),(Players[number_4]->GetSkillCold()+(Players[number_4]->GetLevel()*3)),Players[number_4]->GetMoney(),gender,"HumanEnemy");

    }
return 0;
}
 
};
int main(){
    srand(time(0));

    std::string u = Clock();
    bool t = IS_Day(u);

    
    ColdWeapon knife123(1,18,65,"asdfghjkl.lkjhgfdsaA");
    Consumables fod(0,12,34,3,"apple");

    // std::cout << "\n\n\n\n\n\n\n\n\n\n";
    // std::cout <<RED<<"                                                                             _     _\n";
    // std::cout <<RED<<"                                                          _______  _ __ ___ | |__ (_)\n";
    // std::cout <<RED<<"                                                         |_  / _  | '_ ` _  | '_  | |\n";
    // std::cout <<RED<<"                                                          / / (_) | | | | | | |_) | |\n";
    // std::cout <<RED<<"                                                         /_______/|_| |_| |_|_.__/|_|\n";
    // std::cout <<RED<<"\n";
    // std::cout <<GREEN<<"********************************************************************************************************************************************"<<"\n";
    // delay(3);

    // std::cout << "\n\n\n";
    // // // Story
    // std::cout << WHITE << "In a not-so-distant future, a mysterious virus outbreak has ravaged the world,"<< std::endl;
    // std::cout << "turning the majority of the population into mindless zombies."<< std::endl;
    // std::cout << "The few remaining humans struggle to survive in a post-apocalyptic landscape filled with danger and despair.\n\n" << std::endl;
    // delay(5);

    // std::cout << "You, the player, wake up in an abandoned building, your memory hazy from the chaos that ensued."<< std::endl;
    // std::cout << "As you step outside, you're greeted by the sight of crumbling buildings, overgrown vegetation,"<< std::endl;
    // std::cout << "and the distant groans of the undead.\n" << std::endl;
    // std::cout << std::endl;
    // delay(5);

    // std::cout << "You soon learn that survivors have grouped together in makeshift settlements, trying to rebuild "<< std::endl;
    // std::cout << "some semblance of society amidst the chaos. But tensions rise as resources become scarce, and "<< std::endl;
    // std::cout << "conflicts erupt between rival factions vying for control.\n" << std::endl;
    // std::cout << std::endl;
    // delay(5);

    // std::cout << "Meanwhile, rumors spread of a powerful leader known as 'The Colonel,' who promises safety and "<< std::endl;
    // std::cout << "salvation in exchange for absolute loyalty. Some survivors swear allegiance to him, while others "<< std::endl;
    // std::cout << "see him as a tyrant exploiting the desperate for his own gain.\n" << std::endl;
    // std::cout << std::endl;
    // delay(5);

    // std::cout << "As you navigate this dangerous world, you'll encounter various characters with their own agendas "<< std::endl;
    // std::cout << "and stories. You'll have to make tough decisions: Who can you trust? Will you join a faction, or "<< std::endl;
    // std::cout << "remain independent? And ultimately, will you survive the looming human-zombie war that "<< std::endl;
    // std::cout << "threatens to consume what's left of humanity?\n" << std::endl;
    // std::cout << std::endl;
    // delay(6);

    // std::cout << "Prepare yourself, for in this world, every choice matters, and only the strong will survive." << std::endl;
    // std::cout << "Good luck with your journey!\n" << std::endl;
    // std::cout << std::endl;
    // delay(4);



    // Create players
    std::vector <HumanCharacter*> players;

    while(true){
        input:
        int option1 = 0;
        char choice;
        int currentOption = 1;
    
        do {

            ShowOptions(currentOption); 
            
            // Get user choice
            choice = getch();
            
            switch (choice) 
            {
                case 'w': // Move up
                case 'W':
                    currentOption -= 1;
                    break;
                case 's': // Move down
                case 'S':
                    currentOption += 1;
                    break;
                case '\r': // Enter key
                    if (currentOption == 1)
                    {
                        option1 = 1;
                    }
                    else
                    {
                        option1 = 2;
                    }
                    
                default:
                    break;
            }
            
            // Clear screen
            std::cout << "\033[2J\033[1;1H";

        } while (option1 != 1 and option1 != 2); // Exit when 'q' is pressed


        if(option1 == 1){
            //Create character

            std::cout << "Enter your name: " << std::endl;
            std ::string name,gender;
            int health,stamina, skilfire, skillcold, age, level, point, money;
            Item *currentWeapon;
            Item * consumerItem;
            std::vector<Item *> bagpack;
            std::cin>>name;
            std::cout << "\033[2J\033[1;1H";

            while (!Check_Gender(gender))
            {
                std::cout<<"Enter your Gender: " << std::endl;
                std::cin>>gender;
                std::cout << "\033[2J\033[1;1H";
                if (Check_Gender(gender) == false)
                {
                    std::cout << "Invalid Gender!\n";
                }
                
            }

            std::cout << "\033[2J\033[1;1H";

            while (!Check_Age(age))
            {
                std::cout<<"Age: " << std::endl;
                std::cin>>age;
                std::cout << "\033[2J\033[1;1H";
                if (Check_Age(age) == false)
                {
                    std::cout << "Invalid Age\n";
                }

            }
            
            std::cout << "\033[2J\033[1;1H";


            std::vector<Item*>bag23;
            bag23.push_back(&Gun1);
            bag23.push_back(&fod);
            bag23.push_back(&knife123);
            HumanCharacter* Player = new HumanCharacter(name,1000,1000,&Gun1,&fod,bag23,8,10,age,gender,1,0,60);
            // HumanCharacter CopyPl = Player;
            players.push_back(Player);
        }
        else if(option1 == 2){
            break;
        }
        else{
            std::cout << "Invalid Option!" << std::endl;
            goto input;
        }

    }

    // for(HumanCharacter* i: players){
    //     std::cout << i->GetName()<< "\n";
    // }

    // std::cout <<"Please Enter Your :";
    // std ::string name,gender;
    // int health,stamina, skilfire, skillcold, age, level, point, money;
    // Item *currentWeapon;
    // Item * consumerItem;
    // std::vector<Item *> bagpack;
    // std ::cin>>name;
    // std::cout<<"Gender: ";
    // std::cin>>gender;
    // std::cout<<"Age: ";
    // std::cin>>age;
    
    // std::vector<Item*>bag23;
    // bag23.push_back(&Gun1);
    // bag23.push_back(&fod);
    // bag23.push_back(&knife123);
    // HumanCharacter Player (name,1000,1000,&Gun1,&fod,bag23,8,10,age,gender,1,0,60);
    // HumanCharacter CopyPl =Player;
 
    
    // ---------------------------------------------------
    while (true)
    {   
        int t = rand()%100;
        
        if (t < 50)
        {
            std::cout<<"Select Enemy:\n1.Zombie\n2.Strong Zombie\n3.Human\n";
            int Enemy;
            std::cin>>Enemy;


            if (Enemy ==1)
            {
                Factory zombie(players,"zombie");
                Model* EnemyZombie = zombie.CreateModel();
                //std::cout<<EnemyZombie->GetCurrentWeapon()->GetDamage();
                Model* CopyEnemy = EnemyZombie;
                View*view= (View*)CopyEnemy;
                view->Display();
                int random = rand()%2;
                while (true)
                {
                    if(random == 0)
                    {
                        int t;
                        for(HumanCharacter*i:players)
                        {
                            if(i->GetHealth()> 1)
                            {


                                Fight displayFight(EnemyZombie,players);
                                std::cout <<"\n"<<i->GetName() << " :"<<"\n1.Upgrade\n2.Items\n3.Fight\n";
                                
                                std::cin >>t;
                                displayFight.ChoiceOfAction(t,i);

                                if (EnemyZombie->GetHealth() <= 0)
                                {
                                    std::cout<< "You Are Win!\n";
                                    for (HumanCharacter*Player:players)
                                    {
                                        
                                        Player->ManageMoney(0,20);
                                        Player->IncreasePoint(50);
                                        Player->Injury(0,200);
                                        Player->Activity(0,100);
                                        if (Player->GetPoint()%100==0)
                                        Player->IncreaseLevel(1);
                                        std::cout<<"\nname: "<<Player->GetName()<<"\nHealth: "<<Player->GetHealth()<<"\nStamina: "<<Player->GetStamina()<<"\nLevel: "<<Player->GetLevel()<<"\nPoint: "<<Player->GetPoint()<<"\nMoney: "<<Player->GetMoney()<<" $\n";
                                        

                                    }
                                    t =4;
                                    break;
                                }
                                std::cout<<"Enemy Health:"<<EnemyZombie->GetHealth()<<"\n";
                            }

                        }
                        
                        if (t==4)
                        {
                            break;
                        }
                        random++;
                
                }
                    
                    
                    if (random == 1)
                    {
                        int Exit1 = 0;
                        for(HumanCharacter* Player:players)
                        {
                            Controller display(EnemyZombie,Player);
                            if (Player->GetHealth() > 1)
                            {
                            display.ZombieFight();
                            if (Player->GetHealth()<=0)
                            {
                                std::cout<<Player->GetName()<<" lost\n";
                                if (Player->GetHealth()<0)
                                {
                                    Player->SetHealth(0);
                                }
                            }
                            else
                            {
                            std::cout <<"\n"<<Player->GetName()<<" Health :"<<Player->GetHealth();

                            }

                            }
                            int SumHealth  = 0;
                            for(HumanCharacter*i:players)
                            {
                                SumHealth +=i->GetHealth();
                            }
                            if (SumHealth == 0)
                            {
                                Exit1 = 1;
                            }
                        }
                        if (Exit1 == 1)
                        {
                            std::cout <<"Lost\n";
                            for(HumanCharacter*Player:players)
                            {
                            
                            Player->SetHealth(500);
                            Player->IncreasePoint(10);
                            std::cout<<"\nname: "<<Player->GetName() <<"\nHealth: "<<Player->GetHealth()<<"\nStamina: "<<Player->GetStamina()<<"\nLevel: "<<Player->GetLevel()<<"\nPoint: "<<Player->GetPoint()<<"\nMoney: "<<Player->GetMoney()<<" $\n";

                            }
                            break;


                        }
                        random--;
                    }
                    }
                    
                
                
                
            }
            else if(Enemy == 2)
            {
                Factory zombie(players,"strongZombie");
                Model* EnemyZombie = zombie.CreateModel();
                //std::cout<<EnemyZombie->GetCurrentWeapon()->GetDamage();
                Model* CopyEnemy = EnemyZombie;
                View*view= (View*)CopyEnemy;
                view->Display();
                int random = rand()%2;
                while (true)
                {
                    if(random == 0)
                    {
                        int t;
                        for(HumanCharacter*i:players)
                        {
                            if (i->GetHealth()>1)
                            {

                                Fight displayFight(EnemyZombie,players);
                                std::cout <<"\n"<<i->GetName() << " :"<<"\n1.Upgrade\n2.Items\n3.Fight\n";
                                
                                std::cin >>t;
                                displayFight.ChoiceOfAction(t,i);

                                if (EnemyZombie->GetHealth() <= 0)
                                {
                                    std::cout<< "You Are Win!\n";
                                    for (HumanCharacter*Player:players)
                                    {
                                        
                                        Player->ManageMoney(0,20);
                                        Player->IncreasePoint(50);
                                        Player->Injury(0,200);
                                        Player->Activity(0,100);
                                        if (Player->GetPoint()%100==0)
                                        Player->IncreaseLevel(1);
                                        std::cout<<"\nname: "<<Player->GetName()<<"\nHealth: "<<Player->GetHealth()<<"\nStamina: "<<Player->GetStamina()<<"\nLevel: "<<Player->GetLevel()<<"\nPoint: "<<Player->GetPoint()<<"\nMoney: "<<Player->GetMoney()<<" $\n";
                                        

                                    }
                                    t =4;
                                    break;
                                }
                                std::cout<<"Enemy Health:"<<EnemyZombie->GetHealth()<<"\n";
                            }
                        }
                        
                        if (t==4)
                        {
                            break;
                        }
                        random++;
                
                }
                    
                    
                    if (random == 1)
                    {
                        int Exit1 = 0;
                        for(HumanCharacter* Player:players)
                        {
                            Controller display(EnemyZombie,Player);
                            if (Player->GetHealth() > 0)
                            {
                            display.ZombieFight();
                            if (Player->GetHealth()<=0)
                            {
                                std::cout<<Player->GetName()<<" lost\n";
                                if (Player->GetHealth()<0)
                                {
                                    Player->SetHealth(0);
                                }
                            }
                            else
                            {
                            std::cout <<"\n"<<Player->GetName()<<" Health :"<<Player->GetHealth();

                            }

                            }
                            int SumHealth  = 0;
                            for(HumanCharacter*i:players)
                            {
                                SumHealth +=i->GetHealth();
                            }
                            if (SumHealth == 0)
                            {
                                Exit1 = 1;
                            }
                        }
                        if (Exit1 == 1)
                        {
                            std::cout <<"Lost\n";
                            for(HumanCharacter*Player:players)
                            {
                            
                            Player->SetHealth(500);
                            Player->IncreasePoint(10);
                            std::cout<<"\nname: "<<Player->GetName() <<"\nHealth: "<<Player->GetHealth()<<"\nStamina: "<<Player->GetStamina()<<"\nLevel: "<<Player->GetLevel()<<"\nPoint: "<<Player->GetPoint()<<"\nMoney: "<<Player->GetMoney()<<" $\n";

                            }
                            break;


                        }
                        random--;
                    }
                    }
                    
                
                
            }
            else if(Enemy == 3)
            {
                Factory HumanEnemy(players,"HumanEnemy");
                Model* EnemyHuman = HumanEnemy.CreateModel();
                Model* CopyHumanEnemy = EnemyHuman;
                View*view= (View*)CopyHumanEnemy;
                view->Display();
                int random = rand()%2;
                while (true)
                {

                    if(random == 0)
                    {
                        for(HumanCharacter* i:players)
                        {
                            if (i->GetHealth()>1)
                            {

                                Fight displayFight(EnemyHuman,players);
                                std::cout <<"\n"<<i->GetName() << " :"<<"\n1.Upgrade\n2.Items\n3.Fight\n";
                                
                                std::cin >>t;
                                displayFight.ChoiceOfAction(t,i);

                                if (EnemyHuman->GetHealth() <= 0)
                                {
                                    std::cout<< "You Are Win!\n";
                                    for (HumanCharacter*Player:players)
                                    {
                                        
                                        Player->ManageMoney(0,20);
                                        Player->IncreasePoint(50);
                                        Player->Injury(0,200);
                                        Player->Activity(0,100);
                                        if (Player->GetPoint()%100==0)
                                        Player->IncreaseLevel(1);
                                        std::cout<<"\nname: "<<Player->GetName()<<"\nHealth: "<<Player->GetHealth()<<"\nStamina: "<<Player->GetStamina()<<"\nLevel: "<<Player->GetLevel()<<"\nPoint: "<<Player->GetPoint()<<"\nMoney: "<<Player->GetMoney()<<" $\n";
                                        

                                    }
                                    t =4;
                                    break;
                                }
                                std::cout<<"Enemy Health:"<<EnemyHuman->GetHealth()<<"\n";
                            }
                        }
                        
                        if (t==4)
                        {
                            break;
                        }
                        random++;
                    }
                    if(random == 1)
                    {
                        int Exit1 = 0;
                        int temp = 0;
                        for(HumanCharacter*Player:players)
                        {
                                // need to correct ManageState

                            Controller display(EnemyHuman,Player);

                            

                            State s1 =  ManageState(Player,EnemyHuman,State::Attack);
                            display.StateFight(s1);
                            if (s1 == State::Attack)
                            {
                                temp = 1;
                            }
                            if (temp == 0)
                            {
                                State s2 = ManageState(Player,EnemyHuman,s1);
                                display.StateFight(s2);
                                if (s2 == State::Attack)
                                {
                                    temp = 1;
                                }
                                if (temp == 0 )
                                {
                                    State s3 = ManageState(Player,EnemyHuman,s2);
                                    display.StateFight(s3);
                                }
                                
                            }
                            if (Player->GetHealth() <= 0)
                            {
                                std::cout<<Player->GetName()<<" lost\n";
                                if (Player->GetHealth()<0)
                                {
                                    Player->SetHealth(0);
                                }
                            }
                            
                            else
                            {
                            std::cout <<"\n"<<Player->GetName()<<" Health :"<<Player->GetHealth();

                            }                       
                            int SumHealth  = 0;
                            for(HumanCharacter*i:players)
                            {
                                SumHealth +=i->GetHealth();
                            }
                            if (SumHealth == 0)
                            {
                                Exit1 = 1;
                            }

                        }
                        if (Exit1 == 1)
                        {
                            std::cout <<"Lost\n";
                            for(HumanCharacter*Player:players)
                            {
                            
                            Player->SetHealth(500);
                            Player->IncreasePoint(10);
                            std::cout<<"\nname: "<<Player->GetName() <<"\nHealth: "<<Player->GetHealth()<<"\nStamina: "<<Player->GetStamina()<<"\nLevel: "<<Player->GetLevel()<<"\nPoint: "<<Player->GetPoint()<<"\nMoney: "<<Player->GetMoney()<<" $\n";

                            }
                            break;


                        }
                        random--;
                    }

                }
                
            }

        }
        else
        {
            char choice;
            
            while (true)
            {
                // int temp = 0;
                int currentoption = 1;
                //HumanCharacter Player = *players[0];
                Shop shop(players);
                for(HumanCharacter* i:players)
                    {  
                    int temp = 0;
                while(temp != 15) 
                {
                    std::cout<<i->GetName()<<"\nMoney :"<<i->GetMoney()<<"$\n";
                    shop.ShowShop(currentoption);

                    choice = getch();

                    switch (choice) {
                        case 'w': 
                        case 'W':
                            // currentoption = (currentoption == 1) ? 3 : currentoption - 1;
                            currentoption -= 1;
                            break;
                        case 's': 
                        case 'S':
                            currentoption += 1;
                            // currentoption = (currentoption == 3) ? 1 : currentoption + 1;
                            break;
                        case '\r': 
                            if (currentoption == 14)
                            {
                                temp = 15;
                                break;
                            }
                            else
                            {
                                shop.BuyItem(currentoption,i);
                            }
                            
                            break;
                    }
                    
                    std::cout << "\033[2J\033[1;1H";

                } 
                
                    
                }   
                break;
            }


            
        }
    }

    // Create players
    // std::vector <HumanCharacter*> players;
    // while(true){
    //     input:
    //     int option1;
    //     std::cout << "Chose an option :" << std :: endl;
    //     std::cout << "1. Create Character " << std :: endl;
    //     std::cout << "2. Exit " << std :: endl;
    //     std::cin >> option1;
    //     std::cout << "\033[2J\033[1;1H";

    //     if(option1 == 1){
    //         //Create character
    //         std::cout << "Enter your name: " << std::endl;
    //         std ::string name,gender;
    //         int health,stamina, skilfire, skillcold, age, level, point, money;
    //         Item *currentWeapon;
    //         Item * consumerItem;
    //         std::vector<Item *> bagpack;
    //         std::cin>>name;
    //         std::cout << "\033[2J\033[1;1H";
    //         std::cout<<"Gender: " << std::endl;
    //         std::cin>>gender;
    //         std::cout << "\033[2J\033[1;1H";

    //         std::cout<<"Age: " << std::endl;
    //         std::cin>>age;
    //         std::cout << "\033[2J\033[1;1H";

            
    //         std::vector<Item*>bag23;
    //         bag23.push_back(&Gun1);
    //         bag23.push_back(&fod);
    //         bag23.push_back(&knife123);
    //         HumanCharacter* Player = new HumanCharacter(name,1000,1000,&Gun1,&fod,bag23,8,10,age,gender,1,0,60);
    //         // HumanCharacter CopyPl = Player;
    //         players.push_back(Player);
    //     }
    //     else if(option1 == 2){
    //         break;
    //     }
    //     else{
    //         std::cout << "Invalid Number!" << std::endl;
    //         goto input;
    //     }

    // }

    // for(HumanCharacter* i: players){
    //     std::cout << i->GetName()<< "\n";
    // }

  
    
    
return 0;
}
