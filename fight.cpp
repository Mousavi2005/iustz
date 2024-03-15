#include <iostream>
#include <vector>
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
public:
    Character(std::string name,int health,int stamina,Item* currentWeapon,std::vector<Item*> bagpack) {
        Name = name;
        Health = health;
        Stamina = stamina;
        CurrentWeapon = currentWeapon;
        Bagpack = bagpack;
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
    HumanCharacter(std::string name,int health,int stamina,Item* currentWeapon,std::vector<Item*> bagpack,int age,std::string gender,int level,int point, int money) : Character( name, health, stamina, currentWeapon, bagpack) {
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
    Shop(HumanCharacter* player) : Gun1 (0, -10, 100, "gun1"),Gun2(0, -12, 140, "gun2") , Gun3(0, -17, 130, "gun3"), Grenade1(0, -8, 20, 1, "grenade1"), Grenade2(0, -20, 60, 1, "grenade2"), Stone(0, -3, 5, 1, "stone"), NinjaStar(0, -13, 20, 1, "ninjaStar"), TRknife(0, -8, 20, 1, "TRknife"), knife1(0, -8, 20, "knife1"), knife2(0, -8, 20, "knife2"), knife3(0, -8, 20, "knife3"),Beverage(+7,0,30,1,"drink"),Food(0,+6,3,1,"apple")
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
class Model :public Character{};
class Controller :public Model{};
class View :public Controller{};
class Fight 
{
    
};
class CreateCharacter{};
class Factory{};
int main(){
    Permanent Gun11(0,-10,100,"Colt");
    Throwable knife(0, -8, 20, 6, "grenade1");
    std::vector <Item*>bag;
    bag.push_back(&Gun11);
    bag.push_back(&knife);
    Character hesam("hesam",100,100,&knife,bag);
    //std::cout<< hesam.GetHealth();
    Permanent Gun2();
    HumanCharacter h("hesam",100,100,&Gun11,bag,18,"man",1,2,300);
    
    Shop s(& h);
    s.ShowShop();
    
    int q;
    std::cin >>q;
    s.BuyItem(q);
    
    std::cout<<h.GetBagpack().size();
    std::cout<<h.GetBagpack()[1]->GetNumber();
    return 0;
}