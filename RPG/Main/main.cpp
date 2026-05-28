#include <iostream>
#include <cmath>
#include <clocale>
#include "Player.hpp"
#include "Enemy.hpp"
#include "Village.hpp"
#include "Miscellaneous.hpp"
#include "Battle.hpp"

////////////////////////////////////////////////////////////////////////
// Přeji hodně štěstí při čtení tohoto absolutního bordel kódu (enjoy)//
/////////////////(ani já sám nevím co jsem to vytvořil)/////////////////
////////////////////////////////////////////////////////////////////////

int main(){
    std::setlocale(LC_ALL, "cs_CZ.UTF-8");
    srand(time(0));
    Player player;
    Enemy enemy;
    std::vector<question> questions = initialize_questions();

    player.Gold = 0;
    player.Level = 1;
    player.XP = 0;

    Show_start_menu();
    Class_choose(player);
    player.Show_playerstats();
    Choose_enemy(enemy);
    Battle(player, enemy, questions);
    
    return 0;
}