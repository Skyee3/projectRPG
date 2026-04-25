#include <iostream>
#include <cmath>
#include <windows.h>
#include "Player.hpp"
#include "Village.hpp"
#include "Miscellaneous.hpp"
#include "Enemy.hpp"

int main(){
    SetConsoleOutputCP(CP_UTF8);
    srand(time(0));
    Player player;
    Enemy enemy;

    player.Gold = 0;
    player.Level = 1;
    player.XP = 0;
    
    Show_start_menu();
    Class_choose(player);
    Show_playerstats(player);
    Choose_enemy(enemy);
    
    return 0;
}