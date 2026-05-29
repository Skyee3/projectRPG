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
            std::cout << "ten se objeví pouze jednou\n";
            break;
        default: break;
    }
    if(enemy.is_miniboss){
        std::cout << "No... tohle nebude easy battle. Narazil jsi na minibosse. Teď už nezačínáš první\n";
        player.skip_turn = true;
    }
    while(player.HP > 0 && enemy.HP > 0 && enemy.Type == 4){
        quizler_turn(player, enemy, questions);
    }
    while(player.HP > 0 && enemy.HP > 0 && enemy.Type == 4){
        quizler_turn(player, enemy, questions);
    }
    while(player.HP > 0 && enemy.HP > 0 && enemy.Type != 4){
        if(player.skip_turn){
            Enemy_turn(player, enemy, questions);
            player.skip_turn = false;
            continue;
        }
        Player_turn(player, enemy);
        enemy.show_all_enemy_stats_testing();
        check_after_player_turn(player, enemy);
        if(enemy.stun_duration > 0){
            std::cout << "Nepřítel je omráčen a nemůže útočit v tomto kole\n";
            enemy.stun_duration--;
            continue;
        }
        if(check_dodge_player(player)){
            std::cout << "vyhnul si se útoku\n";
            continue;
        }
        Enemy_turn(player, enemy, questions);
        player.Show_Playerstats_short();
    }
    enemy.counter++;
}
