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
        Before_player_turn(player, enemy);
        Player_turn(player, enemy);
        enemy.show_all_enemy_stats_testing();
        if(enemy.HP <= 0 || player.HP <= 0){
            break;
        }
        if(Before_enemy_turn(player, enemy)){
            Enemy_turn(player, enemy, questions);
        }
        After_enemy_turn(player, enemy);
        player.Show_Playerstats_short();
    }
    enemy.counter++;
}

void Before_player_turn(Player &player, Enemy &enemy){
    player.damage_multiplier = 1.0;

    if(player.jedinec_buff_duration > 0) {
        player.damage_multiplier *= 1.2;
        player.jedinec_buff_duration--;
        if(player.jedinec_buff_duration == 0) {
            std::cout << "Buff z Dominantního jedince právě vyprchal.\n";
        }
        else{
            std::cout << "Buff z Dominantního jedince potrvá ještě " << player.jedinec_buff_duration << " kol.\n";
        }
    }
    if(player.jedinec_cooldown > 0 && player.Class_ID == 1) {
        player.jedinec_cooldown--;
        if(player.jedinec_cooldown == 0){
            std::cout << "Schopnost Dominantní jedinec je teďka dostupná.\n";
        }
        else{
            std::cout << "Schopnost Dominantní jedinec můžeš použít za " << player.jedinec_cooldown << " kol\n";
        }
    }
    if(player.buldozer_debuff_duration > 0) {
        player.buldozer_debuff_duration--;
        player.damage_multiplier *= 0.85; 
        std::cout << "Debuff od Buldozera ti snižuje poškození o 15% na toto kolo\n";
    }
    if(player.Burn_duration > 0){
        player.HP -= 5;
        player.Burn_duration--;
        std::cout << "Poškození z ohně způsobilo 5 poškození\n";
        if(player.Burn_duration == 0){
            std::cout << "Už nehoříš (Big thumbs up :P)\n";
        }
        else{
            std::cout << "Oheň bude působit ještě " << player.Burn_duration << " kol :(\n";
        }
    }
}

bool Before_enemy_turn(Player &player, Enemy &enemy) {
    enemy.Damage_multiplier = 1.0;
    if(enemy.stun_duration > 0) {
        std::cout << "Nepřítel je omráčen a nemůže v tomto kole útočit!\n";
        enemy.stun_duration--;
        return false;
    }

    if(check_dodge_player(player)) {
        std::cout << "Skvěle! Vyhnul jsi se útoku nepřítele.\n";
        return false; 
    }

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
    return true; 
}

void After_enemy_turn(Player &player, Enemy &enemy){
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
}

void Dead_screen(Player &player){
    int choice;
    std::cout << "Prohrál jsi\n";
    std::cout << "Ale nezoufej vykoupit se můžeš když mi zadáš číslo platební karty, včetně expirace a hlavně nezapomenň na to schované číslíčko vzadu\n";
    Input_checker("Chceš se vykoupit ? (1 - ano, 0 - ne): ", choice, 0, 1);
    if(choice == 1){
        Input_checker("číslo Karty: ", player.number_of_cart, 1000000000000000, 9999999999999999);
        Input_checker("CVV: ", player.cvv, 100, 999);
        std::cout << "Zadejte expiraci karty (MM/YY): ";
        std::cin >> player.expiration_date;
        std::cout << "Teď počkejte než to zpracujeme...\n";
        std::cout << "Chyba program se zničil\n";
    }
    else{
        std::cout << "Bohužel můžeš to zkusit znovu restartováním hry\n";
    }
}