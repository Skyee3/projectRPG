#include "Battle.hpp"

void Battle(Player &player, Enemy &enemy){
    std::cout << "Dnes se utkáš s " << enemy.name << "em\n";
    while(player.HP > 0 && enemy.HP > 0){
        Player_turn(player, enemy);
        enemy.show_all_enemy_stats_testing();
        Enemy_turn(player, enemy);
        player.Show_Playerstats_short();
    }
}
