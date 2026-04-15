#include <iostream>
#include <ctime>
#include "Village.hpp"
#include "Player.hpp"

void Village_choice(Player &player){
    int choice;
    int Village_price[5] = {10, 25, 20, 50, 50};
    bool Village_loop = true;
    std::cout << R"(
    /-- SLUŽBY VE VESNICI --\
    | [1] Doplnit HP    10g |
    | [2] +Max HP       25g |
    | [3] +Max Mana     20g |
    | [4] Upgrade útok  50g |
    | [5] Upgrade Ability 50g  |
    | --------------------- |
    | [0] Odejít            |
    \-----------------------/)
    Máte )" << player.Gold << " zlata\n"; // upravit výstup
    do{
        std::cout << "Vaše volba: ";
        std::cin >> choice;
        if(std::cin.fail() || choice < 0 || choice > 5) {
            std::cin.clear();
            std::cin.ignore(1000, '\n');
            std::cout << "ERROR: Zadejte validní hodnotu (0-5)\n";
            continue;
        }
        if(choice == 0){
            Village_loop = false;
        }
        else if(player.Gold < Village_price[choice - 1]){
            std::cout << "Nemáte dostatek zlata!\n";
        }
        else {
            player.Gold -= Village_price[choice - 1];

            switch(choice) {
                case 1:{}
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
        }
    }while(choice < 0 || choice > 5 || Village_loop); // loop na kontrolu validnosti vstupu
    // dodělat vystup aby vědel sve nasledujici staty
}

void Village_Regen_HP(Player &player){
    int random = rand() % 8 + 1;
    player.HP += random;
    if(player.HP > player.Max_HP) player.HP = player.Max_HP;
}

void Village_upgrade_max_HP(Player &player){
    player.Max_HP+=5;
}

void Village_upgrade_max_MANA(Player &player){
    player.Max_Mana+=5;
}

void Village_upgrade_Atack(Player &player){
    //dodělat
}

void Village_upgrade_Ability(Player &player){
    //dodělat
}