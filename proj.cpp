
#include <iostream>
#include <vector>
#include <ctime>
#include <stdlib.h>
#include <string>
#include <iomanip>

// fire energy=0
//cold = 1
// ... = 3
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
    Shop(HumanCharacter* player) : Gun1 (0, 11, 100, "gun1"),Gun2(0, 13, 140, "gun2") , Gun3(0, 17, 130, "gun3"), Grenade1(3, 9, 20, 1, "grenade"), Grenade2(3, 21, 60, 1, "TNT"), Stone(3, 4, 5, 1, "stone"), NinjaStar(3, 14, 20, 1, "ninjaStar"), TRknife(3, 8, 20, 1, "TRknife"), knife1(1, 8, 20, "knife1"), knife2(1, 8, 20, "knife2"), knife3(1, 8, 20, "knife3"),Beverage(7,0,30,1,"drink"),Food(0,6,3,1,"apple")
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
        std::cout<<"7 ." << Grenade1.GetName() << "   " << Grenade1.GetPrice() << " $" << "\n";
        std::cout<<"8 ." << Grenade2.GetName() << "       " << Grenade2.GetPrice() << " $" << "\n";
        std::cout<<"9 ." << Stone.GetName() << "     " << Stone.GetPrice() << "  $" << "\n";
        std::cout<<"10." << NinjaStar.GetName() << " " << NinjaStar.GetPrice() << " $" << "\n";
        std::cout<<"11." << TRknife.GetName() << "   " << TRknife.GetPrice() << " $" << "\n";
        std::cout<<"12." << Beverage.GetName() << "     " << Beverage.GetPrice() << " $" << "\n";
        std::cout<<"13." << Food.GetName() << "     " << Food.GetPrice() << "  $" << "\n14. Exit\n";
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
    HumanCharacter *Player;
    State state;
public:
    Controller(Model* enemy,HumanCharacter *player) 
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
                                Player->Injury(1,Enemy->GetConsumerItem()->GetDamage());
                                Enemy->GetConsumerItem()->ReduceNumber(1);
                                //Player->Activity(1,10);
                            }
                            
                        }
                   }
                   if (Enemy->GetStamina()>=20)
                    {
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
                                Player->Injury(1,Enemy->GetConsumerItem()->GetDamage());
                                Enemy->GetConsumerItem()->ReduceNumber(1);
                                //Player->Activity(1,10);
                            }
                            
                        }
                   }
                   if (Enemy->GetStamina()>=10)
                    {
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
HumanCharacter* Player;
public:
    Fight(Model*enemy,HumanCharacter* player)
    {
        Player = player;
        Enemy = enemy;
    }
    void ChoiceOfAction(int choice) {
        while (true)
        {
        
            if (choice==1)
            {
                std::cout<<"Money:"<<Player->GetMoney()<<"$\n";
                std::cout<<"1.Increase Fire Skill By 5 Units  30$ ("<<Player->GetSkillFire() <<")"<<"\n2.Increase Cold Skill By 5 Units  20$ ("<<Player->GetSkillCold() <<")"<<"\n3. \n4.Exit\n";
                int Option;
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
                    
                    break;
                
                default:
                    std::cout <<"Invalid Command\n";
                    break;
                }
                
            }
            else if (choice ==2) 
            {
                int num = 1;
            for (Item* i :Player->GetBagpack()) 
            {
                
                    std::cout<<num<<"."<<i->GetName();
                    if (i->GetNumber()==1000000)
                    {
                        std::cout <<"\n";
                    }
                    else
                    {
                        std::cout <<"    ("<<i->GetNumber()<<")\n";
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
        return new Model(name,(Player->GetHealth()-50),Player->GetStamina(),Player->GetCurrentWeapon(), Player->GetConsumerItem(),Player->GetBagpack(),(Player->GetSkillFire()+1),Player->GetSkillCold(),Player->GetMoney(),gender,"zombie");
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
        return new Model(name,(Player->GetHealth()+1000),Player->GetStamina(),Player->GetCurrentWeapon(), Player->GetCurrentWeapon(),Player->GetBagpack(),(Player->GetSkillFire()+7),(Player->GetSkillCold()+7),Player->GetMoney(),gender,"strongZombie");

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
        return new Model(name,(Player->GetHealth()+rand()%1000+10) , (Player->GetStamina()+(Player->GetLevel()*10)),Player->GetCurrentWeapon(), &Food,bag ,(Player->GetSkillFire()+(Player->GetLevel()*3)),(Player->GetSkillCold()+(Player->GetLevel()*3)),Player->GetMoney(),gender,"HumanEnemy");

    }
return 0;
}
 
};
int main(){
    
    
    ColdWeapon knife123(1,18,65,"asdfghjkl.lkjhgfdsaA");
    Consumables fod(0,12,34,3,"apple");

    std::cout <<"Choose Character:\nPlease Enter Your :\nName: ";
    std ::string name,gender;
    int health,stamina, skilfire, skillcold, age, level, point, money;
    Item *currentWeapon;
    Item * consumerItem;
    std::vector<Item *> bagpack;
    std ::cin>>name;
    std::cout<<"Gender: ";
    std::cin>>gender;
    std::cout<<"Age: ";
    std::cin>>age;
    
    std::vector<Item*>bag23;
    bag23.push_back(&Gun1);
    bag23.push_back(&fod);
    bag23.push_back(&knife123);
    HumanCharacter Player (name,1000,1000,&Gun1,&fod,bag23,8,10,age,gender,1,0,60);
    HumanCharacter CopyPl =Player;
 
    
    while (true)
    {   
        int t = rand()%100;
        
        if (t > 80)
        {
            std::cout<<"Select Enemy:\n1.Zombie\n2.Strong Zombie\n3.Human\n";
            int Enemy;
            std::cin>>Enemy;
            
            if (Enemy ==1)
            {
                Factory zombie(&Player,"zombie");
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
                        Fight displayFight(EnemyZombie,&Player);
                        std::cout <<"\n1.Upgrade\n2.Items\n3.Fight\n";
                        int t;
                        std::cin >>t;
                        displayFight.ChoiceOfAction(t);
                        if (EnemyZombie->GetHealth() <= 0)
                        {
                            std::cout<<"you are win.\n";
                            Player.ManageMoney(0,20);
                            Player.IncreasePoint(50);
                            Player.Injury(0,200);
                            Player.Activity(0,100);
                            if (Player.GetPoint()%100==0)
                            Player.IncreaseLevel(1);
                            std::cout<<"\nHealth: "<<Player.GetHealth()<<"\nStamina: "<<Player.GetStamina()<<"\nLevel: "<<Player.GetLevel()<<"\nPoint: "<<Player.GetPoint()<<"\nMoney: "<<Player.GetMoney()<<" $\n";
                            break;
                        }
                        std::cout<<"Enemy Health:"<<EnemyZombie->GetHealth();

                        random++;
                    }
                    
                    if (random == 1)
                    {
                        Controller display(EnemyZombie,&Player);
                        display.ZombieFight();
                        if (Player.GetHealth() <= 0)
                        {
                            std::cout<<"\nYou Lost!\n";
                            Player.SetHealth(500);
                            Player.IncreasePoint(10);
                            std::cout<<"\nHealth: "<<Player.GetHealth()<<"\nStamina: "<<Player.GetStamina()<<"\nLevel: "<<Player.GetLevel()<<"\nPoint: "<<Player.GetPoint()<<"\nMoney: "<<Player.GetMoney()<<" $\n";
                            break;
                        }
                        std::cout<<"\nYuor Health :"<<Player.GetHealth();
                        random--;
                    }
                }
                
                
            }
            else if(Enemy == 2)
            {
                Factory zombie(&Player,"strongZombie");
                Model* EnemyZombie = zombie.CreateModel();
                Model* CopyEnemy = EnemyZombie;
                View*view= (View*)CopyEnemy;
                view->Display();
                int random = rand()%2;
                while (true)
                {
                    if(random == 0)
                    {
                        Fight displayFight(EnemyZombie,&Player);
                        std::cout <<"\n1.Upgrade\n2.Items\n3.Fight\n";
                        int t;
                        std::cin >>t;
                        displayFight.ChoiceOfAction(t);
                        if (EnemyZombie->GetHealth() <= 0)
                        {
                            std::cout<<"you are win.\n";
                            Player.ManageMoney(0,20);
                            Player.IncreasePoint(50);
                            Player.Injury(0,200);
                            Player.Activity(0,100);
                            if (Player.GetPoint()%100==0)
                            Player.IncreaseLevel(1);
                            std::cout<<"\nHealth: "<<Player.GetHealth()<<"\nStamina: "<<Player.GetStamina()<<"\nLevel: "<<Player.GetLevel()<<"\nPoint: "<<Player.GetPoint()<<"\nMoney: "<<Player.GetMoney()<<" $\n";
                            break;
                        }
                        std::cout<<"Enemy Health:"<<EnemyZombie->GetHealth();

                        random++;
                    }
                    
                    if (random == 1)
                    {
                        Controller display(EnemyZombie,&Player);
                        display.ZombieFight();
                        if (Player.GetHealth() <= 0)
                        {
                            std::cout<<"\nYou Lost!\n";
                            Player.SetHealth(500);
                            Player.IncreasePoint(10);
                            std::cout<<"\nHealth: "<<Player.GetHealth()<<"\nStamina: "<<Player.GetStamina()<<"\nLevel: "<<Player.GetLevel()<<"\nPoint: "<<Player.GetPoint()<<"\nMoney: "<<Player.GetMoney()<<" $\n";
                            break;
                        }
                        std::cout<<"\nYou`re Health :"<<Player.GetHealth();
                        random--;
                    }
                }
            }
            else if(Enemy == 3)
            {
                Factory HumanEnemy(&Player,"HumanEnemy");
                Model* EnemyHuman = HumanEnemy.CreateModel();
                //std::cout<<EnemyZombie->GetCurrentWeapon()->GetDamage();
                Model* CopyHumanEnemy = EnemyHuman;
                View*view= (View*)CopyHumanEnemy;
                view->Display();
                int random = rand()%2;
                while (true)
                {
                    if(random == 0)
                    {
                        Fight displayFight(EnemyHuman,&Player);
                        std::cout <<"\n1.Upgrade\n2.Items\n3.Fight\n";
                        int t;
                        std::cin >>t;
                        displayFight.ChoiceOfAction(t);
                        if (EnemyHuman->GetHealth() <= 0)
                        {
                            std::cout<<"you are win.\n";
                            Player.ManageMoney(0,20);
                            Player.IncreasePoint(50);
                            Player.Injury(0,200);
                            Player.Activity(0,100);
                            if (Player.GetPoint()%100==0)
                            Player.IncreaseLevel(1);
                            std::cout<<"\nHealth: "<<Player.GetHealth()<<"\nStamina: "<<Player.GetStamina()<<"\nLevel: "<<Player.GetLevel()<<"\nPoint: "<<Player.GetPoint()<<"\nMoney: "<<Player.GetMoney()<<" $\n";
                            break;
                        }
                        std::cout<<"Enemy Health:"<<EnemyHuman->GetHealth();

                        random++;
                    }
                    if(random == 1)
                    {
                        Controller display(EnemyHuman,&Player);
                        int temp = 0;
                        State s1 =  ManageState(&Player,EnemyHuman,State::Attack);
                        display.StateFight(s1);
                        if (s1 == State::Attack)
                        {
                            temp = 1;
                        }
                        if (temp == 0)
                        {
                            State s2 = ManageState(&Player,EnemyHuman,s1);
                            display.StateFight(s2);
                            if (s2 == State::Attack)
                            {
                                temp = 1;
                            }
                            if (temp == 0 )
                            {
                                State s3 = ManageState(&Player,EnemyHuman,s2);
                                display.StateFight(s3);
                            }
                            
                        }
                        if (Player.GetHealth() <= 0)
                        {
                            std::cout<<"\nYou Lost!\n";
                            Player.SetHealth(500);
                            Player.IncreasePoint(10);
                            std::cout<<"\nHealth: "<<Player.GetHealth()<<"\nStamina: "<<Player.GetStamina()<<"\nLevel: "<<Player.GetLevel()<<"\nPoint: "<<Player.GetPoint()<<"\nMoney: "<<Player.GetMoney()<<" $\n";
                            break;
                        }
                        
                        std::cout<<"\nYou`re Health :"<<Player.GetHealth();
                        random--;
                    }

                }
                
            }

        }
        else
        {
            while (true)
            {
            int Option= 0;
                Shop shop(&Player);
                std::cout<<"Money :"<<Player.GetMoney()<<"$\n";
                shop.ShowShop();
                
                std::cin >>Option;
                if(Option >=14)
                {
                    break;
                }
                shop.BuyItem(Option);
            }
            
        }
    }

    // std::vector <HumanCharacter*> characters;
    // while(true){
    //     int option1;
    //     std::cout << "Chose an option :" << std :: endl;
    //     std::cout << "1. Create Character " << std :: endl;
    //     std::cout << "2. Exit " << std :: endl;
    //     std::cin >> option1;
    //     if(option1 == 1){
    //         //Create character
    //         std::cout << "Enter your name: " << std::endl;
    //         std ::string name,gender;
    //         int health,stamina, skilfire, skillcold, age, level, point, money;
    //         Item *currentWeapon;
    //         Item * consumerItem;
    //         std::vector<Item *> bagpack;
    //         std::cin>>name;
    //         std::cout<<"Gender: ";
    //         std::cin>>gender;
    //         std::cout<<"Age: ";
    //         std::cin>>age;
            
    //         std::vector<Item*>bag23;
    //         bag23.push_back(&Gun1);
    //         bag23.push_back(&fod);
    //         bag23.push_back(&knife123);
    //         HumanCharacter* Player = new HumanCharacter(name,1000,1000,&Gun1,&fod,bag23,8,10,age,gender,1,0,60);
    //         // HumanCharacter CopyPl = Player;
    //         characters.push_back(Player);
    //     }
    //     else if(option1 == 2){
    //         break;
    //     }
    //     else{
    //         std::cout << "Invalid Number!" << std::endl;
            
    //     }

    // }
    // for(HumanCharacter* i: characters){
    //     std::cout << i->GetName()<< "\n";
    // }
    
  
    
    
return 0;
}
    
