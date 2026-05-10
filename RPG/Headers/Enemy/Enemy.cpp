#include <iostream>
#include "Enemy.hpp"


void Choose_enemy(Enemy &enemy){
    int random = rand() % 4;
    switch(random){
        case 0:
            enemy.set_enemy("Buldozer", 1, 50, 10, 5);
            break;
        case 1:
            enemy.set_enemy("e2", 2, 80, 15, 8);
            break;
        case 2:
            enemy.set_enemy("e3", 3, 120, 20, 10);
            break;
        case 3:
            enemy.set_enemy("e4", 4, 200, 30, 15);
            break;
        default:
            break;
    }
}

void Enemy_turn(Player &player, Enemy &enemy){
    std::cout << "\n========================================\n";
    std::cout << "             TAH NEPŘÍTELE              \n";
    std::cout << "========================================\n";
}

void Buldozer_turn(Player &player, Enemy &enemy){ //debuffer
    int ability = rand() % 4;
    switch(ability){
        case 0:
            std::cout << "Nepřítel tě shodil a dal ti " << enemy.Damage - 2 << " poškození a oslabil tě na další kolo o 15%\n";
            player.HP -= enemy.Damage - 2;
            break;
        case 1:
            std::cout << "Nepřítel zvolil útok ohňem a dal ti " << enemy.Damage + 5 << " poškození.\n";
            std::cout << "Po dobu 2 kol budeš hořet a dostavat 5 poškození navíc.\n";
            player.HP -= enemy.Damage + 5;
            break;
        default:
            std::cout << "Nepřítel zvolil basic útok a kopl tě za" << enemy.Damage << " poškození.\n";
            player.HP -= enemy.Damage;
            break;
    }
}