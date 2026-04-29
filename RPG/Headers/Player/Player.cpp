#include <iostream>
#include "Player.hpp"

void Class_choose(Player &player){
    std::cout << "\n /===================\\\n";
    std::cout << " |  VYBER SI CLASSU  |\n";
    std::cout << " |===================|\n";
    std::cout << " |  [1] Warrior      |\n";
    std::cout << " |  [2] Ranger       |\n";
    std::cout << " |  [3] Mage         |\n";
    std::cout << " \\===================/\n";
    
    bool Class_loop = true;
    do{
        int choice;
        std::cout << "Vaše volba: ";
        std::cin >> choice;
        if(std::cin.fail() || choice < 1 || choice > 3) {
            std::cin.clear();
            std::cin.ignore(1000, '\n');
            std::cout << "ERROR: Zadejte validní hodnotu (1-3)\n";
            continue;
        }
        switch(choice){
            case 1:
            Class_warrior(player);
            break;
            case 2:
            Class_ranger(player);
            break;
            case 3:
            Class_mage(player);
            break;
            default:
            break;
        }
        int confirm_choice;
        Input_checker("Potvrďte výběr classy (1 - Ano, 0 - Ne): ", confirm_choice, 0, 1);
        if(confirm_choice == 1){
            Class_loop = false;
        }
        else{
            std::cout << "Znovu zvolte classu\n";
        }
    }while(Class_loop);
    std::cout << "Zvolili jste classu: " << player.Class << "\n";
}
void Class_warrior(Player &player){
    player.Class = "Warrior";
    player.Class_ID = 1;
    player.Max_HP = 130;
    player.HP = player.Max_HP;
    player.Max_Mana = 40;
    player.Mana = player.Max_Mana;
    player.Damage = 15;
    Class_preview(player);
    std::cout << "SCHOPNOSTI: \n";
    std::cout << " 1. Útok mečem\n";
    std::cout << "   V základu " << player.Damage << " poškození\n";
    std::cout << " 2. Silný úder (Mana: 20)\n";
    std::cout << "   V základu " << player.Damage - 2 << " poškození\n";
    std::cout << "   Omráčí nepřítele na 1 kolo\n\n";
    std::cout << " 3. Dominantní jedinec (Mana: 35)\n";
    std::cout << "   V základu " << player.Damage - 1 << " poškození\n";
    std::cout << "   Snižuje poškození nepřítele o 50% na 2 kola\n";
    std::cout << "   Zvýší poškození o 20% na 3 kola\n\n";
}

void Class_ranger(Player &player){
    player.Class = "Ranger";
    player.Class_ID = 2;
    player.Max_HP = 80;
    player.HP = player.Max_HP;
    player.Max_Mana = 40;
    player.Mana = player.Max_Mana;
    player.Damage = 3;
    Class_preview(player);
    std::cout << "SCHOPNOSTI: \n";
    std::cout << " 1. Útok lukem\n";
    std::cout << "   V základu " << player.Damage << " poškození\n";
    std::cout << "   Při útoku vás nepřítel nemůže zasáhnout\n\n";
    std::cout << " 2. Jedovatý šíp (Mana: 20)\n";
    std::cout << "   V základu " << player.Damage << " poškození\n";
    std::cout << "   Nepřitel dostane jed, který způsobí 3 poškození za kolo, po dobu 3 kol\n\n";
    std::cout << " 3. Šípová sprcha (Mana: 30)\n";
    std::cout << "   Vystřelíš salvu šípů na všechny nepřítele\n";
    std::cout << "   Zasáhne více nepřátel najednou\n";
    std::cout << "   Každý zásah dává 75% poškození\n\n";
    std::cout << " 4. Legolas (Mana: 5)\n";
    std::cout << "   "; //dodělat
}

void Class_mage(Player &player){ 
    player.Class = "Mage";
    player.Class_ID = 3;
    player.Max_HP = 50;
    player.HP = player.Max_HP;
    player.Max_Mana = 60;
    player.Mana = player.Max_Mana;
    player.Damage = 10;
    Class_preview(player);
    std::cout << "SCHOPNOSTI: \n";
    std::cout << " 1. Flákanec (Mana: 1)\n";
    std::cout << "   Objeví se magicka pazoura pana Lubomíra Volného, a ten dá nepříteli flákanec, který způsobí " << player.Damage << " poškození\n\n";
    std::cout << " 2. Gamba (Mana: 20)\n";
    std::cout << "  Je to gamba, buď dáš vysoké nebo malé poškození (prostě gamba lol)\n\n";
    std::cout << " 3. Karma (Mana: 40)\n";
    std::cout << "   V příštím kole nepřítel zautočí sám na sebe\n\n";
}

void Show_playerstats(Player &player){
    std::cout << "\n========================================\n";
    std::cout << "             STATUS POSTAVY             \n";
    std::cout << "========================================\n";
    
    std::cout << "  Jméno:      " << player.name << "\n";
    std::cout << "  Class:      " << player.Class << "\n";
    std::cout << "\n";
    std::cout << "  Level:     " << player.Level << "\n";
    std::cout << "  XP:        " << player.XP << "\n";
    std::cout << "\n";
    std::cout << "  HP:         " << player.HP << " / " << player.Max_HP << "\n";
    std::cout << "  MANA:       " << player.Mana << " / " << player.Max_Mana << "\n";
    std::cout << "  Poškození:  " << player.Damage << "\n";
    std::cout << "  ZLATO:      " << player.Gold << " ks\n";
    
    std::cout << "========================================\n";
}

void Class_preview(Player &player){
    std::cout << "Class: "<< player.Class << "\n\n";
    std::cout << "STATISTIKY: \n";
    std::cout << "  HP: " << player.HP << "/" << player.Max_HP << "\n";
    std::cout << "  MANA: " << player.Mana << "/" << player.Max_Mana << "\n";
    std::cout << "  Poškození: " << player.Damage << "\n\n";
}