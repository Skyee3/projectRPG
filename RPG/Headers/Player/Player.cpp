#include <iostream>
#include "Player.hpp"

void Class_choose(Player &player){
    int choice;
    bool Class_loop = true;
    int confirm_choice;
    std::cout << "\n /===================\\\n";
    std::cout << " |  VYBER SI CLASSU  |\n";
    std::cout << " |===================|\n";
    std::cout << " |  [1] Warrior      |\n";
    std::cout << " |  [2] Ranger       |\n";
    std::cout << " |  [3] Mage         |\n";
    std::cout << " \\===================/\n";
    do{
        std::cout << "Vaše volba: ";
        std::cin >> choice;
        if(std::cin.fail() || choice < 1 || choice > 3) {
            std::cin.clear();
            std::cin.ignore(1000, '\n');
            std::cout << "ERROR: Zadejte validní hodnotu (1-3)\n";
            continue;
        }
        do{
            std::cout << "Jste si jistý, že chcete zvolit tuto classu? (1 - Ano, 0 - Ne): ";
            std::cin >> confirm_choice;
            if(std::cin.fail() || confirm_choice < 0 || confirm_choice > 1) {
                std::cin.clear();
                std::cin.ignore(1000, '\n');
                std::cout << "ERROR: Zadejte validní hodnotu (0-1)\n";
                continue;
            }
            else{
                break;
            }
        }while(true);
        if(confirm_choice == 1){
            Class_loop = false;
        }
        else{
            std::cout << "Znovu zvolte classu\n";
        }
    }while(Class_loop);
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
    std::cout << "Zvolili jste classu: " << player.Class << "\n";
}
void Class_warrior(Player &player){
    player.Class = "Warrior";
    player.Max_HP = 10;
    player.Mana;
    player.Max_Mana;
}

void Class_ranger(Player &player){
    player.Class = "Ranger";
    player.Max_HP = 5;
    player.Mana;
    player.Max_Mana;
}

void Class_mage(Player &player){
    player.Class = "Mage";
    player.Max_HP = 5;
    player.Mana;
    player.Max_Mana;
}

void Show_playerstats(Player &player){
    std::cout << "\n========================================\n";
    std::cout << "             STATUS POSTAVY             \n";
    std::cout << "========================================\n";
    
    std::cout << "  Jméno:      " << player.name << "\n";
    std::cout << "  Class:      " << player.Class << "\n";
    std::cout << "\n";
    std::cout << "  HP:         " << player.HP << " / " << player.Max_HP << "\n";
    std::cout << "  MANA:       " << player.Mana << " / " << player.Max_Mana << "\n";
    std::cout << "  Poškození:  " << player.Damage << "\n";
    std::cout << "  ZLATO:      " << player.Gold << " ks\n";
    
    std::cout << "========================================\n";
}