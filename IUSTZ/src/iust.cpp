#include "../include/iust.hpp"

std::string tempc = "   -> ";

// Generate Zombie Name
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

// Generate Zombie Name
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

// Generate Win Sentance
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

// Generate Lose Sentance
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

// Gender Handling
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

// Age Handling
bool Check_Age(int age){
    if (age <= 7 or age >= 100)
    {
        return false;
    }
    else
        return true;
    
}

// Get Clock
std::string Clock(){

    auto currentTime = std::chrono::system_clock::now();

    std::time_t time = std::chrono::system_clock::to_time_t(currentTime);
    std::string currentTimeStr = std::ctime(&time);
    std::string clock = currentTimeStr.substr(11,2);
    return clock;
}

// Check Day
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

// Stop Program
void delay(int seconds) {
    
    std::this_thread::sleep_for(std::chrono::seconds(seconds));

}

// Show First Menu
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

// Show Second Menu
void ShowMenu(int a){
    if (a == 1)
    {
        std::cout << "\n" << tempc <<"1.Upgrade\n";
        std::cout <<"2.Items\n";
        std::cout <<"3.Fight\n";
    }
    else if (a == 2)
    {
        std::cout << "\n" <<"1.Upgrade\n";
        std::cout << tempc <<"2.Items\n";
        std::cout <<"3.Fight\n";
    }
    else
    {
        std::cout << "\n" <<"1.Upgrade\n";
        std::cout <<"2.Items\n";
        std::cout << tempc <<"3.Fight\n";
    }
    
}

// Item Constructer
    Item::Item(int energy,int damage,int price,std::string name,int number) {
        Energy = energy;
        Damage = damage;
        Price = price;
        Name = name;
        Number = number;
    }

// Item Class Functions 
    void Item:: SetEnergy(int energy){
        Energy = energy;
    }
    void Item:: SetDamage(int damage){
        Damage = damage;
    }
    void Item:: SetPrice(int price){
        Price = price;
    }
    void Item:: SetName(std::string name){
        Name = name;
    }
    void Item:: SetNumber(int number){
        Number = number;
    }
    void Item:: IncreaseNumber(int a) {
        Number+=a;
    }
    void Item:: ReduceNumber(int a) {
        Number-=a;
    }
    int Item:: GetEnergy(){
        return Energy;
    }
    int Item:: GetDamage(){
        return Damage;
    }
    int Item:: GetPrice(){
        return Price;
    }
    std::string Item:: GetName(){
        return Name;
    }
    int Item:: GetNumber(){
        return Number;
    }

    // Temporary Constructer
    Temporary::Temporary(int energy,int damage,int price,int number,std::string name) :Item( energy, damage , price , name,number){}
    
    // Temporary Class Functions
    void Temporary:: ReduceNumber(){
        int a = GetNumber();
        SetNumber((a--));
    }
    void Temporary:: AddNumber(){
        int a = GetNumber();
        SetNumber((a++));
    }
    
    // Throwable Constructer
    Throwable::Throwable(int energy,int damage,int price,int number, std::string name):Temporary( energy, damage, price,number,name){}
    
    // Consumables Constructer
    Consumables::Consumables(int energy,int damage,int price,int number, std::string name):Temporary( energy, damage, price,number,name){}
    
    // Permanent Constructer
    Permanent::Permanent(int energy,int damage,int price,std::string name) :Item( energy, damage,price, name,1000000) {}
    
    // Firearm Constructer
    Firearm::Firearm(int energy,int damage,int price,std::string name) : Permanent( energy, damage,price, name) {}

    int Firearm:: GetType()
    {
        return 0;
    }
    
    // ColdWeapon Constructer
    ColdWeapon::ColdWeapon(int energy,int damage,int price,std::string name) : Permanent( energy, damage,price, name) {}
    int ColdWeapon:: GetType()
    {
        return 1;
    }

    // Character Constructer
    Character::Character(std::string name,int health,int stamina,Item* currentWeapon,std::vector<Item*> bagpack, Item* consumerItem ,int skillfire,int skillcold)
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
    
    // Character Class Functions
    int Character::GetSkillFire(){
        return SkillFire;
    }
    int Character::GetSkillCold(){
        return SkillCold;
    }
    std::string Character::GetName(){
        return Name;
    }
    int Character::GetHealth(){
        return Health;
    }
    int Character::GetStamina(){
        return Stamina;
    }
    Item* Character::GetCurrentWeapon() {
        return CurrentWeapon;
    }
    Item* Character::GetConsumerItem() {
        return ConsumerItem;
    }
    std::vector<Item*> Character::GetBagpack(){
        return Bagpack;
    }
    void Character::IncreaseSkillFire(int fire) {
        SkillFire += fire;
    }
    void Character::IncreaseSkillCold(int Cold) {
        SkillCold += Cold;
    }
    void Character::SetName(std::string name) {
        Name =name;
    }
    void Character::SetHealth(int health) {
        Health = health;
    }
    void Character::SetStamina(int stamina) {
        Stamina = stamina;
    }
    void Character::SetCurrentWeapon(Item* currentWeapon) {
        this->CurrentWeapon = currentWeapon;
    }
    void Character::SetConsumerItem(Item* consumerItem) {
        ConsumerItem = consumerItem;
    }
    void Character::AddBagpack(Item* member) {
        Bagpack.push_back(member);
    }
    void Character::Injury(int b,int a) {
        if (b == 1)
        {
            Health -= a;
        }
        else if (b == 0)
        {
            Health += a;
        }
    }
    void Character::Activity(int b,int a) {
        if (b == 1)
        {
            Stamina -= a;
        }
        else if (b == 0)
        {
            Stamina += a;
        }
    }
    
    // HumanCharacter Constructer
    HumanCharacter::HumanCharacter(std::string name,int health,int stamina , Item* currentWeapon,Item * consumerItem,std::vector<Item*> bagpack , int skilfire , int skillcold, int age,std::string gender,int level,int point, int money) : Character( name, health, stamina, currentWeapon, bagpack,consumerItem,skilfire, skillcold) {
        Age = age;
        Gender = gender;
        Level = level;
        Point = point;
        Money = money;
    }
    
    // HumanCharacter Class Function
    int HumanCharacter::GetAge() {
        return Age;
    }
    std::string HumanCharacter::GetGender() {
        return Gender;
    }
    int HumanCharacter::GetLevel() {
        return Level;
    }
    int HumanCharacter::GetPoint() {
        return Point;
    }
    int HumanCharacter::GetMoney() {
        return Money;
    }
    float HumanCharacter::GetMoneyRatio(){
        return Money_Ratio;
    }
    void HumanCharacter::SetAge(int age) {
        Age = age;
    }
    void HumanCharacter::SetGender(std::string gender) {
        Gender = gender;
    }
    void HumanCharacter::IncreaseLevel(int a) {
        Level += a;
    }
    void HumanCharacter::IncreasePoint(int a) {
        Point += a;
    }
    void HumanCharacter::ManageMoney(int b,int a) {
        if (b == 0) {
            Money += a;
        }
        if (b == 1) {
            Money -= a;
        }
    }
    void HumanCharacter::Increase_MoneyRatio(int a){
        Money_Ratio += a;
    }
    
    // Shop Constructer
    Shop::Shop(std::vector<HumanCharacter*> players) : Gun1 (0, 11, 100, "gun1"),Gun2(0, 13, 140, "gun2") , Gun3(0, 17, 130, "gun3"), Grenade1(0, 9, 20, 1, "grenade1"), Grenade2(0, 21, 60, 1, "grenade2"), Stone(0, 4, 5, 1, "stone"), NinjaStar(0, 14, 20, 1, "ninjaStar"), TRknife(0, 8, 20, 1, "TRknife"), knife1(0, 8, 20, "knife1"), knife2(0, 8, 20, "knife2"), knife3(0, 8, 20, "knife3"),Beverage(7,0,30,1,"drink"),Food(0,6,3,1,"apple")
        {
            Players = players;
        }
    
    // Shop Class Functions
    int Shop::GetMoney(){
       return Players[0]->GetMoney();   
    }
    void Shop::ShowShop(int a)
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
        

    }
    void Shop::BuyItem(int Option,HumanCharacter* Player)
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
    
    // Model Constructer
    Model::Model(std::string name,int health,int stamina,Item* currentWeapon,Item*consumerItem,std::vector<Item*> bagpack, int skillfire,int skillcold, int moneyenemy ,std::string gender, std::string type ) :Character( name, health, stamina, currentWeapon, bagpack,consumerItem,skillfire, skillcold)
    {
        MoneyEnemy = moneyenemy;
        Type = type;
        Gender = gender;

    }
    HumanCharacter* Model::GetPlyer()
    {
        return Player;
    }
    std::string Model::GetType() 
    {
        return Type;
    }
    int Model::GetMoney()
    {
        return MoneyEnemy;
    }
    std::string Model::GetGender()
    {
        return Gender;
    }
    
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
    
    Controller::Controller(Model* enemy,std::vector<HumanCharacter*> players) 
        {
        Enemy = enemy;
        Players = players;
        
        }
    Controller::Controller(Model* enemy,HumanCharacter* player)
        {
            Enemy = enemy;
            Player = player;
        }
    
    // Controller Functions
    void Controller::StateFight(State action)
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
    void Controller::ZombieFight()
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
    void View::Display()
        {
            std::cout<<"name: "<<GetName()<<"\nGender: "<<GetGender() <<"\nType: "<<GetType()<<"\nHealth: "<<GetHealth()<<"\nStamina: "<<GetStamina()<<"\nWeapon: "<<GetCurrentWeapon()->GetName();
        }
    
    void ShowMenu2(int a, HumanCharacter*Player){
    if (a == 1)
    {
        std::cout <<"Money:"<<Player->GetMoney()<<"$\n";
        std::cout << tempc << "1.Increase Fire Skill By 5 Units  30$ ("<<Player->GetSkillFire() <<")"<<"\n2.Increase Cold Skill By 5 Units  20$ ";
        std::cout << "("<<Player->GetSkillCold() <<")\n";
        std::cout << "3.Increase Earning Money Ratio By 100%  60$ (" << Player->GetMoneyRatio() << ")\n";
        std::cout << "4.Exit\n";
    }
    else if (a == 2)
    {
        std::cout <<"Money:"<<Player->GetMoney()<<"$\n";
        std::cout <<"1.Increase Fire Skill By 5 Units  30$ ("<<Player->GetSkillFire() <<")"<<"\n" << tempc << "2.Increase Cold Skill By 5 Units  20$ ";
        std::cout << "("<<Player->GetSkillCold() <<")\n";
        std::cout << "3.Increase Earning Money Ratio By 100%  60$ (" << Player->GetMoneyRatio() << ")\n";
        std::cout << "4.Exit\n";
    }
    else if (a == 3)
    {
        std::cout <<"Money:"<<Player->GetMoney()<<"$\n";
        std::cout <<"1.Increase Fire Skill By 5 Units  30$ ("<<Player->GetSkillFire() <<")"<<"\n" << "2.Increase Cold Skill By 5 Units  20$ ";
        std::cout << "("<<Player->GetSkillCold() <<")\n";
        std::cout << tempc << "3.Increase Earning Money Ratio By 100%  60$ (" << Player->GetMoneyRatio() << ")\n";
        std::cout << "4.Exit\n";
    }
    else
    {
        std::cout <<"Money:"<<Player->GetMoney()<<"$\n";
        std::cout <<"1.Increase Fire Skill By 5 Units  30$ ("<<Player->GetSkillFire() <<")"<<"\n2.Increase Cold Skill By 5 Units  20$ ";
        std::cout << "("<<Player->GetSkillCold() <<")\n";
        std::cout << "3.Increase Earning Money Ratio By 100%  60$ (" << Player->GetMoneyRatio() << ")\n";
        std::cout << tempc <<"4.Exit\n";

    }
    
}

    void ShowMenu3(int a, HumanCharacter* player){

    int num = 1;
    std::string temp = "";
    for (Item* i :player->GetBagpack()) 
    {
        if (num == a)
        {
            temp = tempc;
        }
                  
        std::cout << temp << num << "." <<i->GetName();
         if (i->GetName() == player->GetCurrentWeapon()->GetName())
          {
               std::cout<<"    *";
           }
        if (i->GetNumber()==1000000)
        {
            std::cout <<"\n";
        }
        else
        {
            std::cout <<"    ("<<i->GetNumber()<<")\n";
            if (i->GetName() == player->GetConsumerItem()->GetName())
            {
                std::cout<<"   *\n";
            }
        }
        num++;
        temp = "";
                    
    }
    

}

     
    Fight::Fight(Model*enemy,std::vector<HumanCharacter*> players)
    {
        Players = players;
        Enemy = enemy;
    }
    void Fight::ChoiceOfAction(int choice,HumanCharacter*Player) {
        while (true)
        {
            
            // input:
        
            if (choice==1)
            {
                int Option = 0;
                char choice1;
                int currentoption = 1;

                do
                {
                    ShowMenu2(currentoption, Player);

                    choice1 = getch();

                    switch (choice1)
                    {
                    case 'w':
                    case 'W':
                        if (currentoption == 1)
                        {
                            currentoption = 4;
                        }
                        else
                            currentoption -= 1;
                        
                        break;
                    
                    case 's' :
                    case 'S' :
                        if (currentoption == 4)
                        {
                            currentoption == 1;
                        }
                        else
                            currentoption += 1;
                        break;

                    case '\r' :
                        if (currentoption == 1)
                        {
                            Option = 1;
                        }
                        else if (currentoption == 2)
                        {
                            Option = 2;
                        }
                        else if (currentoption == 3)
                        {
                            Option = 3;
                        }
                        else
                        {
                            Option = 4;
                        }
                        break;
                                    
                    default:
                        break;
                    }

                    std::cout << "\033[2J\033[1;1H";


                } while (Option == 0);
                
                
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
                        break;

                    }
                
            
            }
            
            else if (choice ==2) 
            {
                int num = 1;
                int select = 0;

                char choice3;
                int currentoption = 1;

                do
                {
                    ShowMenu3(currentoption, Player);
                    
                    choice3 = getch();

                    switch (choice3)
                    {
                    case 'w':
                    case 'W':
                        if (currentoption == 1)
                        {
                            currentoption = Player->GetBagpack().size();
                        }
                        else
                        {
                            currentoption -= 1;
                        }
                        break;

                    case 's':
                    case 'S' :
                    if (currentoption == Player->GetBagpack().size())
                    {
                        currentoption = 1;
                    }
                    else
                    {
                        currentoption += 1;
                    }
                    break;

                    case '\r':
                        select = currentoption;

                    // break;
                        goto qrc;
                        // yt = 10;
                    default:
                        break;
                    }

                std::cout << "\033[2J\033[1;1H";

                } while (select == 0);
                qrc:

                
                        if (Player->GetBagpack()[select-1]->GetNumber()==1000000)
                        {
                            Player->SetCurrentWeapon(Player->GetBagpack()[select-1]);
                        }
                        else
                        {
                            Player->SetConsumerItem(Player->GetBagpack()[select-1]);
                        }
                        // goto input;
                        // break;
            
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
            // ShowMenu(1);
            int yt = choice;
            char chk;
            int t = 0;

            do
                            {
                                ShowMenu(yt);
                                chk = getch();

                                switch (chk)
                                {
                                    case 'w': 
                                    case 'W':
                                        if (yt == 1)
                                        {
                                            yt = 3;
                                            break;
                                        }
                                        else
                                            yt -= 1;
                                    break;

                                    case 's': 
                                    case 'S':
                                        if (yt == 3)
                                        {
                                            yt = 1;
                                            break;
                                        }
                                        else
                                            yt += 1;
                                    break;

                                    case '\r': 
                                        if (yt == 1)
                                        {
                                            t = 1;
                                            break;
                                        }
                                        else if (yt == 2)
                                        {
                                            t = 2;
                                        }
                                        else if (yt == 3)
                                        {
                                            t = 3;
                                        }
                                        
                                        else
                                        {
                                            t = 4;
                                        }
                                        break;

                                    default:
                                        break;
                                }
                                std::cout << "\033[2J\033[1;1H";


                            } while (t == 0);
                            choice = t;




        }
            std::cout << "\033[2J\033[1;1H";

        
    }

    Factory::Factory(std::vector<HumanCharacter *> players,std::string kind) {
        Kind = kind;
        Players = players;
        
        }
    Model* Factory::CreateModel() {
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
 







    







    
