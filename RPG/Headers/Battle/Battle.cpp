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
    while(player.HP > 0 && enemy.HP > 0 && enemy.Type != 4){
        if(player.skip_turn){
            Enemy_turn(player, enemy, questions);
            player.skip_turn = false;
            continue;
        }

        Player_turn(player, enemy);
        enemy.show_all_enemy_stats_testing();
        check_after_player_turn(player, enemy);
        if(enemy.HP <= 0 || player.HP <= 0){
            break;
        }
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
        check_after_enemy_turn(player, enemy);
    }
    enemy.counter++;
}


void check_after_player_turn(Player &player, Enemy &enemy){
    player.damage_multiplier = 1.0;

    if(player.jedinec_buff_duration > 0) {
        player.damage_multiplier *= 1.2;
    }
    if(player.buldozer_debuff_duration > 0) {
        player.damage_multiplier *= 0.85; 
    }
    if(player.jedinec_buff_duration > 0) {
        player.jedinec_buff_duration--;
        if(player.jedinec_buff_duration == 0) {
            std::cout << "Buff z Dominantního jedince právě vyprchal.\n";
        }
        else{
            std::cout << "Buff z Dominantního jedince potrvá ještě " << player.jedinec_buff_duration << " kol.\n";
        }
    }
    
    if(player.buldozer_debuff_duration > 0) {
        player.buldozer_debuff_duration--;
        if(player.buldozer_debuff_duration == 0) {
            std::cout << "Debuff od Buldozera právě vyprchal.\n";
        }
    }
    if(player.Class_ID == 1 && player.jedinec_cooldown > 0){
            player.jedinec_cooldown--;
            std::cout << "Schopnost Dominantní jedinec můžete použít za " << player.jedinec_cooldown << " kol\n";
    }
}

void check_after_enemy_turn(Player &player, Enemy &enemy){
    if(enemy.poison_duration > 0){
        enemy.HP -= 5;
        enemy.poison_duration--;

        std::cout << "Poškození z jedu způsobilo " << 5 << " poškození nepříteli\n";
        if(enemy.poison_duration == 0){
            std::cout << "Jed přestal působit\n";
        }
        else{
            std::cout << "Jed bude působit ještě " << enemy.poison_duration << " kol\n";
        }
    }
    enemy.Damage_multiplier = 1.0;
    if(enemy.Damage_multiplier_duration > 0){
        enemy.Damage_multiplier *= 0.5;
        enemy.Damage_multiplier_duration--;
        if(enemy.Damage_multiplier_duration == 0){
            std::cout << "Enemy už není debuffnutý.\n";
        }
        else{
            std::cout << "Enemy bude debuffnutý ještě " << enemy.Damage_multiplier_duration << " kol.\n";
        }
    }
}