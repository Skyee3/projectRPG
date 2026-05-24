#include "Battle.hpp"

void Battle(Player &player, Enemy &enemy, std::vector<question> &questions){
    std::cout << "Utkáváš se s " << enemy.name << "em\n";
    switch(enemy.Type){
        case 3:
            std::cout << "Well well well, Pacient z bohnic tě portnul asi můžeš hádat kam (do bohnic) a ted užívej absolutní peak tohoto souboje\n";
            break;
        case 4:
            std::cout << "No... tohle nebude basic battle. Teďka tě čeká kvíz.\n";
            std::cout << "když odpovíš dobře tak quizler dostane poškození když ne tak asi můžeš hádat co se stane\n";
            break;
        default: break;
    }
    while(player.HP > 0 && enemy.HP > 0 && enemy.Type == 4){
        quizler_turn(player, enemy, questions);
    }
    while(player.HP > 0 && enemy.HP > 0 && enemy.Type != 4){
        Player_turn(player, enemy);
        enemy.show_all_enemy_stats_testing();
        Enemy_turn(player, enemy, questions);
        player.Show_Playerstats_short();
    }

}
