#include <iostream>
#include <ctime>
#include "Village.hpp"
#include "Player.hpp"

void Village_choice(Player &player){
    int choice;
    static int Village_price[5] = {10, 25, 20, 50, 50}; 
    const int MAX_HP_UPGRADES = 9;
    const int MAX_MANA_UPGRADES = 5;
    const int MAX_ATK_UPGRADES = 8;
    do{
        std::cout << "\n/-------------------------------------------------------------\\" << std::endl;
        std::cout << "|                          VESNICE                            |" << std::endl;
        std::cout << "|-------------------------------------------------------------|" << std::endl;
        std::cout << "|                                                             |" << std::endl;

        std::cout << "|  [1] Plné doplnění HP ................ " << Village_price[0] << " ks                |" << std::endl;

        std::cout << "|  [2] Vylepšit max HP (+10) ........... " << Village_price[1] << " ks  ";
        if (player.hp_upgrades_bought < MAX_HP_UPGRADES) std::cout << "(" << player.hp_upgrades_bought << "/" << MAX_HP_UPGRADES << ")         |" << std::endl;
        else std::cout << "[VYPRODÁNO]   |" << std::endl;

        std::cout << "|  [3] Vylepšit max Manu (+10) ......... " << Village_price[2] << " ks  ";
        if (player.mana_upgrades_bought < MAX_MANA_UPGRADES) std::cout << "(" << player.mana_upgrades_bought << "/" << MAX_MANA_UPGRADES << ")         |" << std::endl;
        else std::cout << "[VYPRODÁNO]   |" << std::endl;

        std::cout << "|  [4] Vylepšit poškození (+5) ......... " << Village_price[3] << " ks  ";
        if (player.atk_upgrades_bought < MAX_ATK_UPGRADES) std::cout << "(" << player.atk_upgrades_bought << "/" << MAX_ATK_UPGRADES << ")         |" << std::endl;
        else std::cout << "[VYPRODÁNO]   |" << std::endl;

        std::cout << "|  [5] Vylepšit Dodge (Úhyb +1) ........ " << Village_price[4] << " ks  ";
        if (player.Dodge < 3) std::cout << "(" << player.Dodge << "/3)         |" << std::endl;
        else std::cout << "[VYPRODÁNO] |" << std::endl;

        std::cout << "|                                                             |" << std::endl;
        std::cout << "|-------------------------------------------------------------|" << std::endl;
        std::cout << "|  [0] Pokračovat v cestě (Odejít)                            |" << std::endl;
        std::cout << "\\-------------------------------------------------------------/" << std::endl;
        std::cout << "Vaše volba: ";
        std::cin >> choice;

        if(std::cin.fail() || choice < 0 || choice > 5) {
            std::cin.clear();
            std::cin.ignore(1000, '\n');
            std::cout << "[ERROR]  Zadej prosím číslo od 0 do 5.\n";
            continue;
        }
        if(choice == 0){
            break;
        }
        if(choice == 2 && player.hp_upgrades_bought >= MAX_HP_UPGRADES){
            std::cout << "[INFO]  Vyprodáno!\n";
            continue;
        }
        if(choice == 3 && player.mana_upgrades_bought >= MAX_MANA_UPGRADES){
            std::cout << "[INFO]  Vyprodáno!\n";
            continue;
        }
        if(choice == 4 && player.atk_upgrades_bought >= MAX_ATK_UPGRADES){
            std::cout << "[INFO]  Vyprodáno!\n";
            continue;
        }
        if(choice == 5 && player.Dodge >= 3){ 
            std::cout << "[INFO]  Vyprodáno! maximální úroveň dodge je 3\n";
            continue;
        }
        if(player.Gold < Village_price[choice - 1]){
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
                player.hp_upgrades_bought++;
                Village_price[1] += 15;
                break;
            case 3:
                Village_upgrade_max_MANA(player);
                player.mana_upgrades_bought++; 
                Village_price[2] += 10;
                break;
            case 4:
                Village_upgrade_Atack(player);
                player.atk_upgrades_bought++;
                Village_price[3] += 20;
                break;
            case 5:
                Village_upgrade_dodge(player);
                Village_price[4] += 25;
                break;
        }
    }while(true);
}

void Village_Regen_HP(Player &player){
    player.HP = player.Max_HP;
    std::cout << "[VESNICE]  doplnil sis maximální HP\n";
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
    player.Damage += 5;
    std::cout << "[VESNICE]  Nyní dáváte " << player.Damage << " Poškození\n";
}

void Village_upgrade_dodge(Player &player){ //funkce vytvořena: 
    player.Dodge++;
    std::cout << "[Vesnice]  Nyní máte dodge na úrovni: " << player.Dodge << "\n";
}