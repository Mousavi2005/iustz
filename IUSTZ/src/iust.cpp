#include "../include/iust.hpp"
    Item::Item(int energy,int damage,int price,std::string name,int number) {
        Energy = energy;
        Damage = damage;
        Price = price;
        Name = name;
        Number = number;
    }
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
    Temporary::Temporary(int energy,int damage,int price,int number,std::string name) :Item( energy, damage , price , name,number){}
    void Temporary:: ReduceNumber(){
        int a = GetNumber();
        SetNumber((a--));
    }
    void Temporary:: AddNumber(){
        int a = GetNumber();
        SetNumber((a++));
    }
    Throwable::Throwable(int energy,int damage,int price,int number, std::string name):Temporary( energy, damage, price,number,name){}
    Consumables::Consumables(int energy,int damage,int price,int number, std::string name):Temporary( energy, damage, price,number,name){}
    Permanent::Permanent(int energy,int damage,int price,std::string name) :Item( energy, damage,price, name,1000000) {}
    Firearm::Firearm(int energy,int damage,int price,std::string name) : Permanent( energy, damage,price, name) {}
    int Firearm:: GetType()
    {
        return 0;
    }
    ColdWeapon::ColdWeapon(int energy,int damage,int price,std::string name) : Permanent( energy, damage,price, name) {}
    int ColdWeapon:: GetType()
    {
        return 1;
    }
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
    void Character::SetSkillFire(int fire) {
        SkillFire = fire;
    }
    void Character::SetSkillCold(int Cold) {
        SkillCold = Cold;
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
    void Character::Injury(int a) {
        Health -= a;
    }
    void Character::Activity(int a) {
        Stamina -= a;
    }
    HumanCharacter::HumanCharacter(std::string name,int health,int stamina , Item* currentWeapon,Item * consumerItem,std::vector<Item*> bagpack , int skilfire , int skillcold, int age,std::string gender,int level,int point, int money) : Character( name, health, stamina, currentWeapon, bagpack,consumerItem,skilfire, skillcold) {
        Age = age;
        Gender = gender;
        Level = level;
        Point = point;
        Money = money;
    }
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
    Shop::Shop(HumanCharacter* player) : Gun1 (0, 11, 100, "gun1"),Gun2(0, 13, 140, "gun2") , Gun3(0, 17, 130, "gun3"), Grenade1(0, 9, 20, 1, "grenade1"), Grenade2(0, 21, 60, 1, "grenade2"), Stone(0, 4, 5, 1, "stone"), NinjaStar(0, 14, 20, 1, "ninjaStar"), TRknife(0, 8, 20, 1, "TRknife"), knife1(0, 8, 20, "knife1"), knife2(0, 8, 20, "knife2"), knife3(0, 8, 20, "knife3"),Beverage(7,0,30,1,"drink"),Food(0,6,3,1,"apple")
        {
            Player = player;
        }
    int Shop::GetMoney(){
        return Player->GetMoney();   
    }
    void Shop::ShowShop()
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
    void Shop::BuyItem(int Option)
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
    Fight::Fight(Model*enemy,HumanCharacter* player)
    {
        Player = player;
        Enemy = enemy;
    }
    void Fight::ChoiceOfAction(int choice) {
        if (choice==1)
        {
            // upgrading character
            Shop::ShowShop;
            int ItemNum;
            std::cin >> ItemNum;
            // Shop::BuyItem(ItemNum);
        }
        else if (choice ==2) 
        {
            // using backpack items
           for (Item* item :Player->GetBagpack()) 
           {
            if (!(item->GetName() ==Player->GetCurrentWeapon()->GetName()))
            {
                std::cout<<item->GetName();
                if (item->GetNumber()==1000000)
                {
                    std::cout <<"\n";
                }
                else
                {
                    std::cout <<"    Number: "<<item->GetNumber()<<"\n";
                }
            }
            int Weapon , ConsumerItem;
            std::cout << " Select your weapon \n";
            std::cin >> Weapon;
            std::cout << " Select your consumer item \n";
            std::cin >>ConsumerItem;
            if(item->GetNumber() == Weapon)
            {
                Player->SetCurrentWeapon(item);
            }
            if(item->GetNumber() == ConsumerItem)
            {
                Player->SetConsumerItem(item);
            }
          }  
        }
        else if (choice == 3) 
        {
            // fighting

        }
    }
    Factory::Factory(HumanCharacter * player,std::string kind) {
        Kind = kind;
        Player = player;
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
            return new Model(name,(Player->GetHealth()+100),Player->GetStamina(),Player->GetCurrentWeapon(), Player->GetConsumerItem(),Player->GetBagpack(),(Player->GetSkillFire()+10),Player->GetSkillCold(),Player->GetMoney(),gender,"zombie");
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
            return new Model(name,(Player->GetHealth()+1000),Player->GetStamina(),Player->GetCurrentWeapon(), Player->GetCurrentWeapon(),Player->GetBagpack(),(Player->GetSkillFire()+100),(Player->GetSkillCold()+100),Player->GetMoney(),gender,"strongZombie");

        }
        else if (Kind == "humanEnemy") {
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
            return new Model(name,(Player->GetHealth()+rand()%1000+10) , (Player->GetStamina()+(Player->GetLevel()*10)),Player->GetCurrentWeapon(), Player->GetConsumerItem(),bag ,(Player->GetSkillFire()+(Player->GetLevel()*10)),(Player->GetSkillCold()+(Player->GetLevel()*10)),Player->GetMoney(),gender,"humanEnemy");

        }
    return 0;
    }
 







    

