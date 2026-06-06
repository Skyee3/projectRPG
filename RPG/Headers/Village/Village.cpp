#include <iostream>
#include <ctime>
#include "Village.hpp"
#include "Player.hpp"

void Village_choice(Player &player){
    int choice;
    int Village_price[5] = {10, 25, 20, 50, 50}; 
    bool Village_loop = true;
    std::cout << R"(
    /---------------------------------------------\
    |                   VESNICE                   |
    |---------------------------------------------|
    |                                             |
    |   [1] Doplnit HP ................... 10 ks  |
    |   [2] Vylepšit maximální HP ........ 25 ks  |
    |   [3] Vylepšit maximalní manu ...... 20 ks  |
    |   [4] Vylepšit poškození útoku ..... 50 ks  |
    |   [5] Vylepšit schopnost ........... 50 ks  |
    |                                             |
    |---------------------------------------------|
    |   [0] Pokračovat v cestě (Odejít)           |
    \---------------------------------------------/
    Máte )" << player.Gold << " zlata\n"; 
    do{
        std::cout << "Vaše volba: ";
        std::cin >> choice;
        if(std::cin.fail() || choice < 0 || choice > 5) {
            std::cin.clear();
            std::cin.ignore(1000, '\n');
            std::cout << "[ERROR]  Zadejte validní hodnotu (0-5)\n";
            continue;
        }
        if(choice == 0){
            Village_loop = false;
        }
        else if(player.Gold < Village_price[choice - 1]){
            std::cout << "[INFO]  Nemáte dostatek zlata! Zadejte jinou volbu.\n";
            continue;
        }
        player.Gold -= Village_price[choice - 1];

        switch(choice) {
            case 1:
                Village_Regen_HP(player);
                break;
            case 2:
                Village_upgrade_max_HP(player);
                break;
            case 3:
                Village_upgrade_max_MANA(player);
                break;
            case 4:
                Village_upgrade_Atack(player);
                break;
            case 5:
                Village_upgrade_Ability(player);
                break;
        }
        Village_loop = false;

    }while(choice < 0 || choice > 5 || Village_loop);
}

void Village_Regen_HP(Player &player){
    int random = rand() % 8 + 1;
    player.HP += random;
    if(player.HP > player.Max_HP) player.HP = player.Max_HP;
}

void Village_upgrade_max_HP(Player &player){
    player.Max_HP+=10;
    player.HP+=10;
    std::cout << "[VESNICE]  Nyní máte " << player.HP << "/" << player.Max_HP << " HP\n";
}

void Village_upgrade_max_MANA(Player &player){
    player.Max_Mana+=10;
    player.Mana+=10;
    std::cout << "[VESNICE]  Nyní máte " << player.Mana << "/" << player.Max_Mana << " MANY\n";
}

void Village_upgrade_Atack(Player &player){
    std::cout << "[VESNICE]  Nyní dáváte " << player.Damage << " Poškození\n";
}

void Village_upgrade_Ability(Player &player){
    //dodělat
}