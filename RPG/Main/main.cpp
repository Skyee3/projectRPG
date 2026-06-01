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
    while(true){
        Choose_enemy(enemy);
        Battle(player, enemy, questions);
        if(player.HP <= 0){
            Dead_screen(player);
            return 0;
        }
        player.reset_stats();
        if(enemy.counter % 2 == 0){
            Village_choice(player);
        }
    }
    
    return 0;
}