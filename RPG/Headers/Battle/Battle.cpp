#include "Battle.hpp"

void Battle(Player &player, Enemy &enemy, std::vector<question> &questions){
    std::cout << "\n========================================\n";
    std::cout << "       Utkáváš se s " << enemy.name << "em\n";
    std::cout << "========================================\n\n";
    switch(enemy.Type){
        case 3:
            std::cout << "[INFO - BOHNIČAN]  Well well well, Pacient z bohnic tě portnul asi můžeš hádat kam (do bohnic) a ted užívej absolutní peak tohoto souboje\n";
            break;
        case 4:
            std::cout << "[INFO - QUIZLER]  No... tohle nebude basic battle. Teďka tě čeká kvíz.\n";
            std::cout << "[INFO - QUIZLER]  když odpovíš dobře tak quizler dostane poškození když ne tak asi můžeš hádat co se stane\n";
            std::cout << "[INFO - QUIZLER]  ten se objeví pouze jednou\n\n";
            break;
        default: break;
    }
    if(enemy.is_miniboss){
        std::cout << "[INFO - BATTLE]  No... tohle nebude easy battle. Narazil jsi na minibosse. Teď už nezačínáš první\n\n";
        player.skip_turn = true;
    }
    while(player.HP > 0 && enemy.HP > 0 && enemy.Type == 4){
        quizler_turn(player, enemy, questions);
        if(!enemy.is_alive() || !player.is_alive()) break;
        player.Show_Playerstats_short();
        enemy.show_all_enemy_stats_testing();
    }
    while(player.HP > 0 && enemy.HP > 0 && enemy.Type != 4){
        Before_player_turn(player);
        if(player.skip_turn || player.is_stunned()){
            if(player.is_stunned()){
                Before_enemy_turn(player, enemy);
            }
            Enemy_turn(player, enemy, questions);
            player.Show_Playerstats_short();
            player.skip_turn = false;
            continue;
        }
        Player_turn(player, enemy);
        if(player.is_sprcha_active && player.is_alive()){
            int random = rand() % 3 + 2;
            int single_arrow = (player.Damage * player.damage_multiplier * 0.5) - enemy.Defense;
            if(single_arrow < 1) single_arrow = 3;
            int dmg1 = single_arrow * random;
            std::cout << "Do " << enemy.name << "a jsi trefil " << random << " šípů takže dáváš " << dmg1 << " poškození\n";
            enemy.HP -= dmg1;
            player.is_sprcha_active = false;
        }
        std::cout << "\n========================================\n\n";
        if(enemy.HP <= 0 || player.HP <= 0){
            break;
        }
        enemy.show_all_enemy_stats_testing();
        if(Before_enemy_turn(player, enemy)){
            Enemy_turn(player, enemy, questions);
        }
        After_enemy_turn(player, enemy);
        std::cout << "\n========================================\n\n";
        player.Show_Playerstats_short();
    }
}

void Battle_two_enemies(Player &player, Enemy &enemy1, Enemy &enemy2, std::vector<question> &questions){
    while(player.HP > 0 && (enemy1.HP > 0 || enemy2.HP > 0)){
        Before_player_turn(player);
        if(player.is_stunned()){
            if (!player.is_alive()) break;
            if(enemy1.HP > 0){
                if(Before_enemy_turn(player, enemy1)) Enemy_turn(player, enemy1, questions);
                After_enemy_turn(player, enemy1);
                enemy1.check_is_death();
            }
            if(enemy1.HP <= 0 && enemy2.HP <= 0) break;
            if(!player.is_alive()) break;
            if(enemy2.HP > 0){
                if(Before_enemy_turn(player, enemy2)) Enemy_turn(player, enemy2, questions);
                After_enemy_turn(player, enemy2);
                enemy2.check_is_death();
            }
            if(enemy1.HP <= 0 && enemy2.HP <= 0) break;
            continue;
        }
        if(!player.is_alive()) break;
        std::cout << "Vyberte proti kterému enemy chcete teď bojovat (1 - " << enemy1.name << ", 2 - " << enemy2.name << ")\n";
        int choice;
        do{
            Input_checker("Váš výběr: ", choice, 1, 2);
            if(choice == 1 && enemy1.HP <= 0){
                std::cout << "Tenhle už je mrtvej bro... vyber č.2\n";
            }
            else if(choice == 2 && enemy2.HP <= 0){
                std::cout << "Tenhle už je mrtvej bro... vyber č.1\n";
            }
            else break;
        }while(true);
        if(choice == 1){
            Player_turn(player, enemy1);
            enemy1.check_is_death();
        }
        else{
            Player_turn(player, enemy2);
            enemy2.check_is_death();
        }
        if(player.is_sprcha_active){
            if(enemy1.HP > 0){
                int random = rand() % 3 + 2;
                int single_arrow = (player.Damage * player.damage_multiplier * 0.5) - enemy1.Defense;
                if(single_arrow < 1) single_arrow = 5;
                int dmg1 = single_arrow * random;
                std::cout << "Do " << enemy1.name << "a jsi trefil " << random << " šípů takže dáváš " << dmg1 << " poškození\n";
                enemy1.HP -= dmg1;
                enemy1.check_is_death();
            }
            if(enemy2.HP > 0){
                int random = rand() % 3 + 2;
                int single_arrow = (player.Damage * player.damage_multiplier * 0.5) - enemy2.Defense;
                if(single_arrow < 1) single_arrow = 5;
                int dmg1 = single_arrow * random;
                std::cout << "Do " << enemy2.name << "a jsi trefil " << random << " šípů takže dáváš " << dmg1 << " poškození\n";
                enemy2.HP -= dmg1;
                enemy2.check_is_death();
            }
            player.is_sprcha_active = false;
        }
        if(enemy1.HP <= 0 && enemy2.HP <= 0) {
            break; 
        }
        std::cout << "\n========================================\n\n";
        if(enemy1.HP > 0){
            enemy1.show_all_enemy_stats_testing();
        }
        if(enemy2.HP > 0){
            enemy2.show_all_enemy_stats_testing();
        }
        if(enemy1.HP <= 0 && enemy2.HP <= 0) break;
        if(enemy1.HP > 0){
            if(Before_enemy_turn(player, enemy1)) Enemy_turn(player, enemy1, questions);
            After_enemy_turn(player, enemy1);
            enemy1.check_is_death();
        }
        if(enemy1.HP <= 0 && enemy2.HP <= 0) break;
        if(!player.is_alive()) break;
        if(enemy2.HP > 0){
            if(Before_enemy_turn(player, enemy2)) Enemy_turn(player, enemy2, questions);
            After_enemy_turn(player, enemy2);
            enemy2.check_is_death();
        }
        std::cout << "\n========================================\n\n";
        if(enemy1.HP <= 0 && enemy2.HP <= 0) break;
        if(!player.is_alive()) break;
        player.Show_Playerstats_short();
    }
}

void Battle_three_enemies(Player &player, Enemy &enemy1, Enemy &enemy2, Enemy &enemy3, std::vector<question> &questions){
    while(player.HP > 0 && (enemy1.HP > 0 || enemy2.HP > 0 || enemy3.HP > 0)){
        Before_player_turn(player);
        if (!player.is_alive()) break;  
        if(player.is_stunned()){
            if(enemy1.HP > 0){
                if(Before_enemy_turn(player, enemy1)) Enemy_turn(player, enemy1, questions);
                After_enemy_turn(player, enemy1);
                enemy1.check_is_death();
            }
            if(enemy1.HP <= 0 && enemy2.HP <= 0 && enemy3.HP <= 0) break;
            if(!player.is_alive()) break;
            if(enemy2.HP > 0){
                if(Before_enemy_turn(player, enemy2)) Enemy_turn(player, enemy2, questions);
                After_enemy_turn(player, enemy2);
                enemy2.check_is_death();
            }
            if(enemy1.HP <= 0 && enemy2.HP <= 0 && enemy3.HP <= 0) break;
            if(!player.is_alive()) break;
            if(enemy3.HP > 0){
                if(Before_enemy_turn(player, enemy3)) Enemy_turn(player, enemy3, questions);
                After_enemy_turn(player, enemy3);
                enemy3.check_is_death();
            }
            if(enemy1.HP <= 0 && enemy2.HP <= 0 && enemy3.HP <= 0) break;
            if(!player.is_alive()) break;
            continue;
        }
        if(!player.is_alive()) break;
        std::cout << "\nVyberte proti kterému enemy chcete teď bojovat (1 - " << enemy1.name << ", 2 - " << enemy2.name << ", 3 - " << enemy3.name << ")\n";
        int choice;
        do{
            Input_checker("Váš výběr: ", choice, 1, 3);
            if(choice == 1 && enemy1.HP <= 0){
                std::cout << "Tenhle už je mrtvej bro... Vyber jiného\n";
            }
            else if(choice == 2 && enemy2.HP <= 0){
                std::cout << "Tenhle už je mrtvej bro... Vyber jiného\n";
            }
            else if(choice == 3 && enemy3.HP <= 0){
                std::cout << "Tenhle už je mrtvej bro... Vyber jiného\n";
            }
            else break;
        }while(true);
        if(choice == 1){
            Player_turn(player, enemy1);
            enemy1.check_is_death();
        }
        else if(choice == 2){
            Player_turn(player, enemy2);
            enemy2.check_is_death();
        }
        else{
            Player_turn(player, enemy3);
            enemy3.check_is_death();
        }
        if(player.is_sprcha_active){
            if(enemy1.HP > 0){
                int random = rand() % 3 + 2;
                int single_arrow = (player.Damage * player.damage_multiplier * 0.5) - enemy1.Defense;
                if(single_arrow < 1) single_arrow = 5;
                int dmg1 = single_arrow * random;
                std::cout << "Do " << enemy1.name << "a jsi trefil " << random << " šípů takže dáváš " << dmg1 << " poškození\n";
                enemy1.HP -= dmg1;
                enemy1.check_is_death();
            }
            if(enemy2.HP > 0){
                int random = rand() % 3 + 2;
                int single_arrow = (player.Damage * player.damage_multiplier * 0.5) - enemy2.Defense;
                if(single_arrow < 1) single_arrow = 5;
                int dmg1 = single_arrow * random;
                std::cout << "Do " << enemy2.name << "a jsi trefil " << random << " šípů takže dáváš " << dmg1 << " poškození\n";
                enemy2.HP -= dmg1;
                enemy2.check_is_death();
            }
            if(enemy3.HP > 0){
                int random = rand() % 3 + 2;
                int single_arrow = (player.Damage * player.damage_multiplier * 0.5) - enemy3.Defense;
                if(single_arrow < 1) single_arrow = 5;
                int dmg1 = single_arrow * random;
                std::cout << "Do " << enemy3.name << "a jsi trefil " << random << " šípů takže dáváš " << dmg1 << " poškození\n";
                enemy3.HP -= dmg1;
                enemy3.check_is_death();
            }
            player.is_sprcha_active = false;
        }
        if(enemy1.HP <= 0 && enemy2.HP <= 0 && enemy3.HP <= 0){
            break; 
        }
        std::cout << "\n========================================\n\n";
        if(enemy1.HP > 0){
            enemy1.show_all_enemy_stats_testing();
        }
        if(enemy2.HP > 0){
            enemy2.show_all_enemy_stats_testing();
        }
        if(enemy3.HP > 0){
            enemy3.show_all_enemy_stats_testing();
        }
        if(enemy1.HP <= 0 && enemy2.HP <= 0 && enemy3.HP <= 0) break;
        if(enemy1.HP > 0){
            if(Before_enemy_turn(player, enemy1)) Enemy_turn(player, enemy1, questions);
            After_enemy_turn(player, enemy1);
            enemy1.check_is_death();
        }
        if(!player.is_alive()) break;
        if(enemy1.HP <= 0 && enemy2.HP <= 0 && enemy3.HP <= 0) break;
        if(enemy2.HP > 0){
            if(Before_enemy_turn(player, enemy2)) Enemy_turn(player, enemy2, questions);
            After_enemy_turn(player, enemy2);
            enemy2.check_is_death();
        }
        if(!player.is_alive()) break;
        if(enemy1.HP <= 0 && enemy2.HP <= 0 && enemy3.HP <= 0) break;
        if(enemy3.HP > 0){
            if(Before_enemy_turn(player, enemy3)) Enemy_turn(player, enemy3, questions);
            After_enemy_turn(player, enemy3);
            enemy3.check_is_death();
        }
        std::cout << "\n========================================\n\n";
        if(enemy1.HP <= 0 && enemy2.HP <= 0 && enemy3.HP <= 0) break;
        if(!player.is_alive()) break;
        player.Show_Playerstats_short();
    }
}

void Final_battle(Player &player, Enemy &boss){
    int hit_chance = 50;
    int random_hit = 0;
    int critical_chance = 20;
    int heal_chance = 1;
    bool boss_under_5 = false;
    while(true){
        if(Before_enemy_turn(player, boss)){
            if(boss.HP < boss.Max_HP / 20){
                heal_chance = 50;
                if(!boss_under_5){
                    std::cout << "\n[INFO]  boss má od teď vyší šanci na heal, takže bacha\n\n";
                    boss_under_5 = true;
                }
            }
            else{
                heal_chance = 1;
                if(boss_under_5){
                    std::cout << "\n[INFO]  boss má nyní zase malou čanci na heal\n";
                    boss_under_5 = false;
                }
            }
    
            Boss_turn(player, boss, critical_chance, heal_chance);
            After_enemy_turn(player, boss);
        }
        std::cout << "\n========================================\n\n";
        if(boss.HP <= 0){
            boss.check_is_death();
            break;
        }
        if(!player.is_alive()) break;
        player.Show_Playerstats_short();
        Before_player_turn(player);
        if(!player.is_alive()) break;

        random_hit = rand() % 100;
        if(random_hit < hit_chance){
            std::cout << "[ÚTOK INFO]  Gamba vítězí a máš možnost útočit!\n";
            std::cout << "[ŠANCE]  Šance na hit se ti zmenšila\n";
            Player_turn(player, boss);
            hit_chance -= 10;
            if(hit_chance < 0) hit_chance = 0;
        }
        else{
            std::cout << "[ÚTOK INFO]  Bohužel enemáka jsi minul, takže toto kolo skipuješ\n";
            std::cout << "[ŠANCE]  Příští kolo budeš ale mít větší šanci na zásah\n";
            hit_chance += 10;
            if(hit_chance > 100) hit_chance = 100;
        }
        if(player.is_sprcha_active && player.is_alive() && boss.HP > 0){
                int random = rand() % 3 + 2;
                int single_arrow = (player.Damage * player.damage_multiplier * 0.5) - boss.Defense;
                if(single_arrow < 1) single_arrow = 5;
                int dmg1 = single_arrow * random;
                std::cout << "Do " << boss.name << "a jsi trefil " << random << " šípů takže dáváš " << dmg1 << "Poškození\n";
                boss.HP -= dmg1;
            player.is_sprcha_active = false;
        }
        if(boss.HP <= 0){
            boss.check_is_death();
            break;
        }
        boss.show_all_enemy_stats_testing();
    }
}

void Before_player_turn(Player &player){
    player.damage_multiplier = 1.0;
    if(player.jedinec_buff_duration > 0){
        std::cout << "\n============EFEKT DOMINANTNÍ JEDINEC============\n\n";
        player.damage_multiplier *= 1.2;
        player.jedinec_buff_duration--;
        if(player.jedinec_buff_duration == 0){
            std::cout << "[STAV]  BUFF už vyprchal\n";
        }
        else if(player.jedinec_buff_duration == 1){
            std::cout << "[AKTIVNÍ BUFF] - DOMINANTNÍ JEDINEC\n";
            std::cout << "[EFEKT]  Zvýšené poškození o 20%\n";
            std::cout << "[STAV]  BUFF bude trvat ještě 1 kolo\n";
        }
        else{
            std::cout << "[AKTIVNÍ BUFF] - DOMINANTNÍ JEDINEC\n";
            std::cout << "[EFEKT]  Zvýšené poškození o 20%\n";
            std::cout << "[STAV]  BUFF bude trvat ještě " << player.jedinec_buff_duration << " kola\n";
        }
        std::cout << "\n==================================================\n\n";
    }
    if(player.jedinec_cooldown > 0 && player.Class_ID == 1){
        std::cout << "===========COOLDOWN DOMINANTNÍ JEDINEC===========\n\n";
        player.jedinec_cooldown--;
        if(player.jedinec_cooldown == 0){
            std::cout << "[STAV]  Schopnost Dominantní jedinec je nyní dostupná.\n";
        }
        else if(player.jedinec_cooldown == 1){
            std::cout << "[STAV]  Schopnost Dominantní jedin můžeš použít za 1 kolo\n";
        }
        else if (player.jedinec_cooldown < 5){
            std::cout << "[STAV]  Schopnost Dominantní jedinec můžeš použít za " << player.jedinec_cooldown << " kola\n";

        }
        else{
            std::cout << "[STAV]  Schopnost Dominantní jedinec můžeš použít za " << player.jedinec_cooldown << " kol\n";
        }
        std::cout << "\n=================================================\n\n";
    }
    if(player.buldozer_debuff_duration > 0){
        std::cout << "===============DEBUFF OD BULDOZERA===============\n\n";
        player.buldozer_debuff_duration--;
        player.damage_multiplier *= 0.85; 
        std::cout << "[DEBUFF]  máš o 15% nižší poškození\n";
        std::cout << "\n==================================================\n\n";
    }
    if(player.Burn_duration > 0){
        std::cout << "======================FIRE=======================\n\n";
        player.HP -= 5;
        player.Burn_duration--;
        std::cout << "[POŠKOZENÍ]  Poškození z ohně ti způsobilo 5 poškození\n";
        std::cout << "[HP]  aktuálně máš " << player.HP << "/" << player.Max_HP << " HP\n";
        if(player.Burn_duration == 0){
            std::cout << "[STAV]  Oheň debuff už končí, takže příší kolo už nebudeš hořet\n";
        }
        else if(player.Burn_duration == 1){
            std::cout << "[STAV]  Oheň bude působit poslední kolo\n";
        }
        else{
            std::cout << "[STAV]  Oheň bude působit ještě " << player.Burn_duration << " kola :(\n";
        }
        std::cout << "\n==================================================\n\n";
    }
}

bool Before_enemy_turn(Player &player, Enemy &enemy){
    enemy.Damage_multiplier = 1.0;
    if(enemy.stun_duration > 0){
        std::cout << "======================STUN=======================\n\n";
        std::cout << "[STAV]  Nepřítel je omráčen a nemůže v tomto kole útočit!\n";
        std::cout << "\n==================================================\n\n";
        enemy.stun_duration--;
        return false;
    }

    if(check_dodge_player(player)){
        std::cout << "=====================DODGE======================\n\n";
        std::cout << "[DODGE]  Skvěle! Vyhnul jsi se útoku nepřítele.\n";
        std::cout << "\n================================================\n\n";
        return false; 
    }

    if(enemy.Damage_multiplier_duration > 0){
        std::cout << "=====================DEBUFF======================\n\n";
        std::cout << "[DEBUFF]  " << enemy.name << " dává pouze 50% svého poškození\n";
        enemy.Damage_multiplier *= 0.5;
        enemy.Damage_multiplier_duration--;
        if(enemy.Damage_multiplier_duration == 0){
            std::cout << "[STAV]  " << enemy.name << " příští kolo už nebude debuffnutý.\n";
        }
        else if(enemy.Damage_multiplier_duration == 1){
            std::cout << "[STAV]  " << enemy.name << " bude debuffnutý ještě 1 kolo.\n";
        }
        else{
            std::cout << "[STAV]  " << enemy.name << " bude debuffnutý ještě " << enemy.Damage_multiplier_duration << " kola\n";
        }
        std::cout << "\n==================================================\n\n";
    }
    return true; 
}

void After_enemy_turn(Player &player, Enemy &enemy){
    if(enemy.poison_duration > 0){
        enemy.HP -= 5;
        enemy.poison_duration--;
        std::cout << "\n=====================POISON======================\n\n";
        std::cout << "[INFO]  Poškození z jedu způsobilo 5 poškození nepříteli\n";
        if(enemy.poison_duration == 0){
            std::cout << "[STAV]  Jed přestal působit\n";
        }
        else if(enemy.poison_duration == 1){
            std::cout << "[STAV]  Jed bude působit ještě 1 kolo\n";
        }
        else{
            std::cout << "[STAV]  Jed bude působit ještě " << enemy.poison_duration << " kola\n";
        }
        std::cout << "[HP]  " << enemy.name << " aktuálně má " << enemy.HP << "/" << enemy.Max_HP << " HP\n";
        std::cout << "\n==================================================\n\n";

    }
}

void Dead_screen(Player &player){
    int choice;
    std::cout << "\n========================================\n";
    std::cout << "             PROHRA!!!!!             \n";
    std::cout << "========================================\n\n";
    std::cout << "Ale nezoufej vykoupit se můžeš když mi zadáš číslo platební karty, včetně expirace a hlavně nezapomenň na to schované číslíčko vzadu\n";
    Input_checker("Chceš se vykoupit ? (1 - ano, 0 - ne): ", choice, 0, 1);
    if(choice == 1){
        std::cout << "Číslo Karty: ";
        std::cin >> player.number_of_cart;
        Input_checker("CVV: ", player.cvv, 100, 999);
        std::cout << "Zadejte expiraci karty (MM/YY): ";
        std::cin >> player.expiration_date;
        std::cout << "Teď počkejte než to zpracujeme...\n";
        std::cout << "Chyba program se zničil\n";
    }
    else{
        std::cout << "Bohužel můžeš to zkusit znovu restartováním hry\n";
    }
    exit(0);
}