#include <iostream>
#include <vector>
#include <ctime>
#include <stdlib.h>
#include <string>
#include <iomanip>
//aghar selah garm bod damage fard ast va dar gheir in sorat zoj
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
    std::vector<Item*> Bagpack;
    int SkillFire;
    int SkillCold;
public:
    Character(std::string name,int health,int stamina,Item* currentWeapon,std::vector<Item*> bagpack, int skillfire,int skillcold) {
        Name = name;
        Health = health;
        Stamina = stamina;
        CurrentWeapon = currentWeapon;
        Bagpack = bagpack;
        SkillCold = skillcold;
        SkillFire = skillfire;
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
    std::vector<Item*> GetBagpack(){
        return Bagpack;
    }
    void SetSkillFire(int fire) {
        SkillFire = fire;
    }
    void SetSkillCold(int Cold) {
        SkillCold = Cold;
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
    // void CurrentWeapon(Item* currentWeapon) {
    //     this->CurrentWeapon = currentWeapon;
    // }
    void AddBagpack(Item* member) {
        Bagpack.push_back(member);
    }
    void Injury(int a) {
        Health -= a;
    }
    void Activity(int a) {
        Stamina -= a;
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
public:
    HumanCharacter(std::string name,int health,int stamina , Item* currentWeapon,std::vector<Item*> bagpack , int skilfire , int skillcold, int age,std::string gender,int level,int point, int money) : Character( name, health, stamina, currentWeapon, bagpack,skilfire, skillcold) {
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
            Money += a;
        }
        if (b == 1) {
            Money -= a;
        }
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
    HumanCharacter* Player;
public:
    Shop(HumanCharacter* player) : Gun1 (0, 11, 100, "gun1"),Gun2(0, 13, 140, "gun2") , Gun3(0, 17, 130, "gun3"), Grenade1(0, 9, 20, 1, "grenade1"), Grenade2(0, 21, 60, 1, "grenade2"), Stone(0, 4, 5, 1, "stone"), NinjaStar(0, 14, 20, 1, "ninjaStar"), TRknife(0, 8, 20, 1, "TRknife"), knife1(0, 8, 20, "knife1"), knife2(0, 8, 20, "knife2"), knife3(0, 8, 20, "knife3"),Beverage(7,0,30,1,"drink"),Food(0,6,3,1,"apple")
        {
            Player = player;
        }
    int GetMoney(){
        return Player->GetMoney();
        // Gun1.GetPrice();
        // Item q(100,100,12,"sdfg",2);
        // Player->GetBagpack().push_back(&q);
        
        
    }
    void ShowShop()
    {   
        std::cout<<"1 ." << Gun1.GetName() << "      " << Gun1.GetPrice() << "$" << "\n";
        std::cout<<"2 ." << Gun2.GetName() << "      " << Gun2.GetPrice() << "$" << "\n";
        std::cout<<"3 ." << Gun3.GetName() << "      " << Gun3.GetPrice() << "$" << "\n";
        std::cout<<"4 ." << knife1.GetName() << "    " << knife1.GetPrice() << " $" << "\n";
        std::cout<<"5 ." << knife2.GetName() << "    " << knife2.GetPrice() << " $" << "\n";
        std::cout<<"6 ." << knife3.GetName() << "    " << knife3.GetPrice() << " $" << "\n";
        std::cout<<"7 ." << Grenade1.GetName() << "  " << Grenade1.GetPrice() << " $" << "\n";
        std::cout<<"8 ." << Grenade2.GetName() << "  " << Grenade2.GetPrice() << " $" << "\n";
        std::cout<<"9 ." << Stone.GetName() << "     " << Stone.GetPrice() << "  $" << "\n";
        std::cout<<"10." << NinjaStar.GetName() << " " << NinjaStar.GetPrice() << " $" << "\n";
        std::cout<<"11." << TRknife.GetName() << "   " << TRknife.GetPrice() << " $" << "\n";
        std::cout<<"12." << Beverage.GetName() << "     " << Beverage.GetPrice() << " $" << "\n";
        std::cout<<"13." << Food.GetName() << "     " << Food.GetPrice() << "  $" << "\n";
    }
    void BuyItem(int Option)
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
public:
    Model(std::string name,int health,int stamina,Item* currentWeapon,std::vector<Item*> bagpack, int skillfire,int skillcold, int moneyenemy , std::string type ) :Character( name, health, stamina, currentWeapon, bagpack,skillfire, skillcold)
    {
        MoneyEnemy = moneyenemy;
        Type = type;

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
    Controller(Model* enemy,HumanCharacter *player) 
    {
    Enemy = enemy;
    Player = player;
    }
    void StateFight()
    {
        if (Enemy->GetType()=="humanEnemy")
        {

        }
        else
        {
            if ((Enemy->GetCurrentWeapon()->GetDamage()%2)==1) 
            {
                if (Enemy->GetStamina()>=2)
                {
                Player->Injury((Enemy->GetCurrentWeapon()->GetDamage()+Enemy->GetSkillFire()));
                Enemy->Activity(2);
                }
                else
                {
                    std::cout <<"The Enemy does not have Stamina";
                }
            }
            else 
            {
                if (Enemy->GetStamina()>=1)
                {
                Player->Injury((Enemy->GetCurrentWeapon()->GetDamage()+Enemy->GetSkillCold()));
                Enemy->Activity(1);
                }
                else
                {
                    std::cout <<"The Enemy does not have Stamina";
                }
            }
        }
    }
};
class View :public Controller{};
class Fight 
{
private:
Model*Enemy;
HumanCharacter* Player;
public:
    Fight(Model*enemy,HumanCharacter* player)
    {
        Player = player;
        Enemy = enemy;
    }
    void ChoiceOfAction(int choice) {
        if (choice==1)
        {
            
        }
        else if (choice ==2) 
        {
          for (Item* i :Player->GetBagpack()) 
          {
            if (!(i->GetName() ==Player->GetCurrentWeapon()->GetName()))
            {
                std::cout<<i->GetName();
                if (i->GetNumber()==1000000)
                {
                    std::cout <<"\n";
                }
                else
                {
                    std::cout <<"    Number: "<<i->GetNumber()<<"\n";
                }
            }
          }  
        }
        else if (choice == 3) 
        {

        }
    }

};
class CreateCharacter{};
class Factory
{
private:
    HumanCharacter * Player;
    std::string Kind;
public:
    Factory(HumanCharacter * player,std::string kind) {
        Kind = kind;
        Player = player;
    }
Model* CreateModel() {
    if (Kind =="zombie"){
        srand(time(0));
        std::string name;
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
        return new Model(name,(Player->GetHealth()+100),Player->GetStamina(),Player->GetCurrentWeapon(),Player->GetBagpack(),(Player->GetSkillFire()+10),Player->GetSkillCold(),Player->GetMoney(),"zombie");
    }
    else if (Kind == "strongZombie"){
        srand(time(0));
        std::string name;
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
        return new Model(name,(Player->GetHealth()+1000),Player->GetStamina(),Player->GetCurrentWeapon(),Player->GetBagpack(),(Player->GetSkillFire()+100),(Player->GetSkillCold()+100),Player->GetMoney(),"strongZombie");

    }
    else if (Kind == "humanEnemy") {
        srand(time(0));
        std::string name;
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
        std::vector <Item*>bag;
        Firearm Gun1 (0, 11, 100, "gun1");
        bag.push_back(&Gun1);
        Firearm Gun2(0, 13, 140, "gun2");
        bag.push_back(&Gun2);
        Firearm Gun3(0, 17, 130, "gun3");
        bag.push_back(&Gun3);
        Throwable Grenade1(0, 9, 20, rand()%10 , "grenade1");
        bag.push_back(&Grenade1);
        Throwable Grenade2(0, 21, 60, rand()%10 , "grenade2");
        bag.push_back(&Grenade2);
        Throwable Stone(0, 4, 5, rand()%10 , "stone");
        bag.push_back(&Stone);
        Throwable NinjaStar(0, 14, 20, rand()%10 , "ninjaStar");
        bag.push_back(&NinjaStar);
        Throwable TRknife(0, 8, 20, rand()%10 , "TRknife");
        bag.push_back(&TRknife);
        ColdWeapon knife1(0, 8, 20, "knife1");
        bag.push_back(&knife1);
        ColdWeapon knife2(0, 8, 20, "knife2");
        bag.push_back(&knife2);
        ColdWeapon knife3(0, 8, 20, "knife3");
        bag.push_back(&knife3);
        Consumables Bevrage(7,0,30,rand()%10,"drink");
        bag.push_back(&Bevrage);
        Consumables Food(0,6,3,rand()%10,"apple");
        bag.push_back(&Food);
        return new Model(name,(Player->GetHealth()+rand()%1000+10) , (Player->GetStamina()+(Player->GetLevel()*10)),Player->GetCurrentWeapon(),bag ,(Player->GetSkillFire()+(Player->GetLevel()*10)),(Player->GetSkillCold()+(Player->GetLevel()*10)),Player->GetMoney(),"humanEnemy");

    }
return 0;
}

};
int main(){
    Permanent Gun11(0,15,100,"gun1");
    Throwable knife(0, 8, 20, 6, "grenade1");
    ColdWeapon knife123(0,18,65,"asdfghjkl.lkjhgfdsaA");
    Consumables fod(0,12,34,3,"banana");
    std::vector <Item*>bag;
    bag.push_back(&fod);
    bag.push_back(&Gun11);
    bag.push_back(&knife);
    bag.push_back(&knife123);
    Character hesam("hesam",100,100,&knife,bag,34,6);
    //std::cout<< hesam.GetHealth();
    
    HumanCharacter h("hesam",1000,1000,&Gun11,bag,37,10,18,"man",1,2,300);
    Factory f(&h,"humanEnemy");
    Fight sos(f.CreateModel(),&h);
    sos.ChoiceOfAction(2);
    //Shop s(& h);
    //s.ShowShop();
    //int q;
    //std::cin >>q;
    //s.BuyItem(q);
    //std::cout<<h.GetBagpack().size();
    //std::cout<<h.GetBagpack()[0]->GetNumber();
        
    
    return 0;
}