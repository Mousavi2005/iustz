#include "iust.cpp"
using namespace std;

int main(){
    srand(time(0));

    std::string u = Clock();
    bool t = IS_Day(u);

    
    ColdWeapon knife123(1,18,65,"The Combat Knife");
    Consumables fod(0,12,34,3,"apple");

    std::cout << "\n\n\n\n\n\n\n\n\n\n";
    std::cout <<RED<<"                                                                             _     _\n";
    std::cout <<RED<<"                                                          _______  _ __ ___ | |__ (_)\n";
    std::cout <<RED<<"                                                         |_  / _  | '_ ` _  | '_  | |\n";
    std::cout <<RED<<"                                                          / / (_) | | | | | | |_) | |\n";
    std::cout <<RED<<"                                                         /_______/|_| |_| |_|_.__/|_|\n";
    std::cout <<RED<<"\n";
    std::cout <<GREEN<<"********************************************************************************************************************************************"<<"\n";
    //delay(3);

    std::cout << "\n\n\n";
    // // Story
    std::cout << WHITE << "In a not-so-distant future, a mysterious virus outbreak has ravaged the world,"<< std::endl;
    std::cout << "turning the majority of the population into mindless zombies."<< std::endl;
    std::cout << "The few remaining humans struggle to survive in a post-apocalyptic landscape filled with danger and despair.\n\n" << std::endl;
    //delay(5);

    std::cout << "You, the player, wake up in an abandoned building, your memory hazy from the chaos that ensued."<< std::endl;
    std::cout << "As you step outside, you're greeted by the sight of crumbling buildings, overgrown vegetation,"<< std::endl;
    std::cout << "and the distant groans of the undead.\n" << std::endl;
    std::cout << std::endl;
    //delay(5);

    std::cout << "You soon learn that survivors have grouped together in makeshift settlements, trying to rebuild "<< std::endl;
    std::cout << "some semblance of society amidst the chaos. But tensions rise as resources become scarce, and "<< std::endl;
    std::cout << "conflicts erupt between rival factions vying for control.\n" << std::endl;
    std::cout << std::endl;
    //delay(5);

    std::cout << "Meanwhile, rumors spread of a powerful leader known as 'The Colonel,' who promises safety and "<< std::endl;
    std::cout << "salvation in exchange for absolute loyalty. Some survivors swear allegiance to him, while others "<< std::endl;
    std::cout << "see him as a tyrant exploiting the desperate for his own gain.\n" << std::endl;
    std::cout << std::endl;
    //delay(5);

    std::cout << "As you navigate this dangerous world, you'll encounter various characters with their own agendas "<< std::endl;
    std::cout << "and stories. You'll have to make tough decisions: Who can you trust? Will you join a faction, or "<< std::endl;
    std::cout << "remain independent? And ultimately, will you survive the looming human-zombie war that "<< std::endl;
    std::cout << "threatens to consume what's left of humanity?\n" << std::endl;
    std::cout << std::endl;
    //delay(6);

    std::cout << "Prepare yourself, for in this world, every choice matters, and only the strong will survive." << std::endl;
    std::cout << "Good luck with your journey!\n" << std::endl;
    std::cout << std::endl;
    //delay(4);



    // Create players
    std::vector <HumanCharacter*> players;
    int Number_of_players = 0;

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
                    if (currentOption == 1)
                    {
                        currentOption = 2;
                        break;
                    }
                    else
                        currentOption -= 1;

                    break;
                case 's': // Move down
                case 'S':
                    if (currentOption == 2)
                    {
                        currentOption = 1;
                        break;
                    }
                    else
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

        } while (option1 != 1 and option1 != 2); 


        if(option1 == 1){
            //Create character
            Number_of_players ++;
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
        else if(option1 == 2 and Number_of_players > 0){
            break;
        }
        else if (option1 == 2 and Number_of_players == 0)
        {
            std::cout << "Create a Character First!\n";
        }

    }

    
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
                    int exit1 = 0;
                    if(random == 0)
                    {
                        int t;
                        for(HumanCharacter*i:players)
                        {
                            if(i->GetHealth()> 1)
                            {

                                int t = 0;
                                // int temp;
                                int currentoption = 1;
                                char choice;
                                Fight displayFight(EnemyZombie,players);
                                // 88888888**********************222222222222222
                                // std::cout <<"\n1.Upgrade\n2.Items\n3.Fight\n";
                                do
                                {
                                    ShowMenu(currentoption);
                                    choice = getch();

                                    switch (choice)
                                    {
                                        case 'w': 
                                        case 'W':
                                            if (currentoption == 1)
                                            {
                                                currentoption = 3;
                                                break;
                                            }
                                            else
                                                currentoption -= 1;
                                        break;

                                        case 's': 
                                        case 'S':
                                            if (currentoption == 3)
                                            {
                                                currentoption = 1;
                                                break;
                                            }
                                            else
                                                currentoption += 1;
                                        break;

                                        case '\r': 
                                            if (currentoption == 1)
                                            {
                                                t = 1;
                                                break;
                                            }
                                            else if (currentoption == 2)
                                            {
                                                t = 2;
                                            }
                                            else if (currentoption == 3)
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
                                            t = 4;
                                            exit1 =1;
                                            break;
                                        }
                                        std::cout<<"Enemy Health:"<<EnemyZombie->GetHealth()<<"\n";
                            }

                        }
                        
                        if (t==4)
                        {
                            break;
                        }
                        if (exit1 == 1)
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
                                std::string temp_losing = Losing_Sentence();
                                std::cout << temp_losing;
                                //delay(5);
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
                            std::string temp_losing = Losing_Sentence();
                            std::cout <<temp_losing << std::endl;
                            //delay(5);
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
                    int exit1 = 0;
                    if(random == 0)
                    {
                        int t;
                        
                        for(HumanCharacter*i:players)
                        {
                            if (i->GetHealth()>1)
                            {

                                int t = 0;
                                // int temp;
                                int currentoption = 1;
                                char choice;
                                Fight displayFight(EnemyZombie,players);
                                // // 88888888**********************222222222222222
                                // // std::cout <<"\n1.Upgrade\n2.Items\n3.Fight\n";

                                do
                                {
                                    ShowMenu(currentoption);
                                    choice = getch();

                                    switch (choice)
                                    {
                                        case 'w': 
                                        case 'W':
                                            if (currentoption == 1)
                                            {
                                                currentoption = 3;
                                                break;
                                            }
                                            else
                                                currentoption -= 1;
                                        break;

                                        case 's': 
                                        case 'S':
                                            if (currentoption == 3)
                                            {
                                                currentoption = 1;
                                                break;
                                            }
                                            else
                                                currentoption += 1;
                                        break;

                                        case '\r': 
                                            if (currentoption == 1)
                                            {
                                                t = 1;
                                                break;
                                            }
                                            else if (currentoption == 2)
                                            {
                                                t = 2;
                                            }
                                            else if (currentoption == 3)
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
                                            exit1 = 1;
                                            break;
                                        }
                                        std::cout<<"Enemy Health:"<<EnemyZombie->GetHealth()<<"\n";
                                // ---------------------------------------------------------------------------------------------------------------

                                // Fight displayFight(EnemyZombie,players);
                                // std::cout <<"\n"<<i->GetName() << " :"<<"\n1.Upgrade\n2.Items\n3.Fight\n";
                                
                                // std::cin >>t;
                                // displayFight.ChoiceOfAction(t,i);

                                // if (EnemyZombie->GetHealth() <= 0)
                                // {
                                //     std::cout<< "You Are Win!\n";
                                //     for (HumanCharacter*Player:players)
                                //     {
                                        
                                //         Player->ManageMoney(0,20);
                                //         Player->IncreasePoint(50);
                                //         Player->Injury(0,200);
                                //         Player->Activity(0,100);
                                //         if (Player->GetPoint()%100==0)
                                //         Player->IncreaseLevel(1);
                                //         std::cout<<"\nname: "<<Player->GetName()<<"\nHealth: "<<Player->GetHealth()<<"\nStamina: "<<Player->GetStamina()<<"\nLevel: "<<Player->GetLevel()<<"\nPoint: "<<Player->GetPoint()<<"\nMoney: "<<Player->GetMoney()<<" $\n";
                                        

                                //     }
                                //     t =4;
                                //     break;
                                // }
                                // std::cout<<"Enemy Health:"<<EnemyZombie->GetHealth()<<"\n";
                            }
                        }
                        
                        if (t==4)
                        {
                            break;
                        }
                        if (exit1 == 1)
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
                                std::string temp_losing = Losing_Sentence();
                                std::cout<< Losing_Sentence << std::endl;
                                //delay(5);
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
                            std::string temp_losing = Losing_Sentence();
                            std::cout <<temp_losing << std::endl;
                            //delay(5);
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
                    int exit1 = 0;

                    if(random == 0)
                    {
                        for(HumanCharacter* i:players)
                        {
                            if (i->GetHealth()>1)
                            {

                                int t = 0;
                                // int temp;
                                int currentoption = 1;
                                char choice;
                                Fight displayFight(EnemyHuman,players);
                                // // // 88888888**********************222222222222222
                                // // // std::cout <<"\n1.Upgrade\n2.Items\n3.Fight\n";

                                do
                                {
                                    ShowMenu(currentoption);
                                    choice = getch();

                                    switch (choice)
                                    {
                                        case 'w': 
                                        case 'W':
                                            if (currentoption == 1)
                                            {
                                                currentoption = 3;
                                                break;
                                            }
                                            else
                                                currentoption -= 1;
                                        break;

                                        case 's': 
                                        case 'S':
                                            if (currentoption == 3)
                                            {
                                                currentoption = 1;
                                                break;
                                            }
                                            else
                                                currentoption += 1;
                                        break;

                                        case '\r': 
                                            if (currentoption == 1)
                                            {
                                                t = 1;
                                                break;
                                            }
                                            else if (currentoption == 2)
                                            {
                                                t = 2;
                                            }
                                            else if (currentoption == 3)
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
                                                

                                //             }
                                //             t =4;
                                //             break;
                                //         }
                                //         std::cout<<"Enemy Health:"<<EnemyZombie->GetHealth()<<"\n";

                                // Fight displayFight(EnemyHuman,players);
                                // std::cout <<"\n"<<i->GetName() << " :"<<"\n1.Upgrade\n2.Items\n3.Fight\n";
                                
                                // std::cin >>t;
                                // displayFight.ChoiceOfAction(t,i);

                                // if (EnemyHuman->GetHealth() <= 0)
                                // {
                                    // std::cout<< "You Are Win!\n";
                                    // for (HumanCharacter*Player:players)
                                    // {
                                        
                                    //     Player->ManageMoney(0,20);
                                    //     Player->IncreasePoint(50);
                                    //     Player->Injury(0,200);
                                    //     Player->Activity(0,100);
                                        // if (Player->GetPoint()%100==0)
                                        // Player->IncreaseLevel(1);
                                        // std::cout<<"\nname: "<<Player->GetName()<<"\nHealth: "<<Player->GetHealth()<<"\nStamina: "<<Player->GetStamina()<<"\nLevel: "<<Player->GetLevel()<<"\nPoint: "<<Player->GetPoint()<<"\nMoney: "<<Player->GetMoney()<<" $\n";
                                        

                                    }
                                            t = 4;
                                            exit1 = 1;
                                            break;
                                        }
                                std::cout<<"Enemy Health:"<<EnemyHuman->GetHealth()<<"\n";
                            }
                        }
                        
                        if (t==4)
                        {
                            break;
                        }
                        if (exit1 == 1)
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
                                std::string temp_losing = Losing_Sentence();
                                std::cout<< temp_losing << std::endl;
                                //delay(5);
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
                            std::string temp_losing = Losing_Sentence();
                            std::cout <<temp_losing << std::endl;
                            //delay(5);
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

    
return 0;
}


