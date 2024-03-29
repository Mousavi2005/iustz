#include "iust.cpp"
using namespace std;
int main (){
    Permanent Gun11(0,15,100,"gun1");
    Throwable knife(0, 8, 20, 6, "grenade1");
    ColdWeapon knife123(0,18,65,"asdfghjkl.lkjhgfdsaA");
    Consumables fod(0,12,34,3,"banana");
    std::vector <Item*>bag;
    bag.push_back(&fod);
    bag.push_back(&Gun11);
    bag.push_back(&knife);
    bag.push_back(&knife123);
    Character hesam("hesam",100,100,&knife123,bag,&knife,34,6);
    //std::cout<< hesam.GetHealth();
    
    HumanCharacter h("hesam",1000,1000,&Gun11,&knife,bag,37,10,18,"man",1,2,300);
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