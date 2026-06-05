#include <iostream>
#include "Player.hpp"
#include "Enemy.hpp"

void Class_choose(Player &player){
    std::cout << "\n /===================\\\n";
    std::cout << " |  VYBER SI CLASSU  |\n";
    std::cout << " |===================|\n";
    std::cout << " |  [1] Warrior      |\n";
    std::cout << " |  [2] Ranger       |\n";
    std::cout << " |  [3] Gandalf      |\n";
    std::cout << " \\===================/\n";
    
    do{
        int choice;
        Input_checker("Vaše volba: ", choice, 1, 3);
        switch(choice){
            case 1:
                player.set_class_stats("Warrior", 1, 130, 40, 20, 0, 10); // class, ID, HP, mana, damage, dodge., defense
                player.set_mana_cost(0, 15, 30);
                break;
            case 2:
                player.set_class_stats("Ranger", 2, 100, 40, 25, 1, 5);
                player.set_mana_cost(0, 20, 30);
                break;
            case 3:
                player.set_class_stats("Gandalf", 3, 90, 60, 15, 1, 10);
                player.set_mana_cost(10, 20, 40);
                break;
            default:
                break;
        }
        Class_preview(player);
        if(Confirm_class_choice(player)){
            break;
        }
    }while(true);
    std::cout << "Zvolili jste classu: " << player.Class << "\n";
}

bool Confirm_class_choice(Player &player){
    int confirm_choice;
    Input_checker("Potvrďte výběr classy (1 - Ano, 0 - Ne): ", confirm_choice, 0, 1);
    if(confirm_choice == 1){
        return true;
    }
    else{
        std::cout << "Znovu zvolte classu\n";
        return false;
    }
}

void Class_preview(Player &player){
    std::cout << "Class: "<< player.Class << "\n\n";
    std::cout << "STATISTIKY: \n";
    std::cout << "  HP: " << player.HP << "/" << player.Max_HP << "\n";
    std::cout << "  MANA: " << player.Mana << "/" << player.Max_Mana << "\n";
    std::cout << "  Defense: " << player.Defense << "\n";
    std::cout << "  Poškození: " << player.Damage << "\n\n";
    Show_class_abilities(player);
}

void Show_class_abilities(Player &player){
    switch(player.Class_ID){
        case 1:
            std::cout << "Prostě boring warrior ale stane se z tebe dominantní jedinec\n";
            std::cout << "SCHOPNOSTI: \n";
            std::cout << " 1. Útok mečem\n";
            std::cout << "   V základu " << player.Damage << " poškození\n\n";
            std::cout << " 2. Silný úder (Mana: " << player.mana_cost[1] << ")\n";
            std::cout << "   V základu " << player.Damage + 5 << " poškození\n";
            std::cout << "   Omráčí nepřítele na 1 kolo\n\n";
            std::cout << " 3. Dominantní jedinec (Mana: " << player.mana_cost[2] << ")\n";
            std::cout << "   V základu " << player.Damage + 5 << " poškození\n";
            std::cout << "   Snižuje poškození nepřítele o 50% na 2 kola\n";
            std::cout << "   Zvýší poškození o 20% na 3 kola\n";
            std::cout << "   Lze použít jednou za 5 kol\n\n";
            break;
        case 2:
            std::cout << "Vysoký dodge a nízké HP\n";
            std::cout << "SCHOPNOSTI: \n";
            std::cout << " 1. Útok lukem\n";
            std::cout << "   V základu " << player.Damage << " poškození\n";
            std::cout << "   Při útoku vás nepřítel nemůže zasáhnout\n\n";
            std::cout << " 2. Jedovatý šíp (Mana: " << player.mana_cost[1] << ")\n";
            std::cout << "   V základu " << player.Damage << " poškození\n";
            std::cout << "   Nepřitel dostane jed, který způsobí 3 poškození za kolo, po dobu 3 kol\n\n";
            std::cout << " 3. Šípová sprcha (Mana: " << player.mana_cost[2] << ")\n";
            std::cout << "   Vystřelíš salvu šípů na všechny nepřítele\n";
            std::cout << "   Zasáhne více nepřátel najednou\n";
            std::cout << "   Každý zásah dává 75% poškození\n\n";
            break;
        case 3:
            std::cout << "Absolutní Gambler (nízké HP ale gamba)\n";
            std::cout << "SCHOPNOSTI: \n";
            std::cout << " 1. Flákanec (Mana: " << player.mana_cost[0] << ")\n";
            std::cout << "   Objeví se magicka pazoura pana Lubomíra Volného, a ten dá nepříteli flákanec, který způsobí " << player.Damage << " poškození\n\n";
            std::cout << " 2. Gamba (Mana: " << player.mana_cost[1] << ")\n";
            std::cout << "  Je to gamba, buď dáš vysoké nebo malé poškození (prostě gamba lol)\n\n";
            std::cout << " 3. Karma (Mana: " << player.mana_cost[2] << ")\n";
            std::cout << "   V příštím kole nepřítel zautočí sám na sebe\n\n";
            break;
        default:
            break;
    }
}
void Player_turn(Player &player, Enemy &enemy){
    int choice_ability;
    User_choice_ability(player, choice_ability);
    switch(player.Class_ID){
       case 1:
            Warrior_atack(player, enemy, choice_ability);
            break;
        case 2:
            Ranger_atack(player, enemy, choice_ability);
            break;
        case 3:
            Gandalf_atack(player, enemy, choice_ability);
            break;
        default:
            break;
    }
}

void User_choice_ability(Player &player, int &choice_ability){
    std::cout << "\n========================================\n";
    std::cout << "             TVŮJ TAH              \n";
    std::cout << "========================================\n";
    switch(player.Class_ID){
        case 1:
            std::cout << "1. Útok mečem\n";
            std::cout << "2. Silný úder (Mana: " << player.mana_cost[1] << ")\n";
            std::cout << "3. Dominantní jedinec (Mana: " << player.mana_cost[2] << ")\n";
            break;
        case 2:
            std::cout << "1. Útok lukem\n";
            std::cout << "2. Jedovatý šíp (Mana: " << player.mana_cost[1] << ")\n";
            std::cout << "3. Šípová sprcha (Mana: " << player.mana_cost[2] << ")\n";
            break;
        case 3:
            std::cout << "1. Flákanec (Mana: " << player.mana_cost[0] << ")\n";
            std::cout << "2. Gamba (Mana: " << player.mana_cost[1] << ")\n";
            std::cout << "3. Karma (Mana: " << player.mana_cost[2] << ")\n";
            break;
        default:
            break;
    }
    Input_ability(player, choice_ability);
    player.Mana -= player.mana_cost[choice_ability - 1];
}

void Warrior_atack(Player &player, Enemy &enemy, int choice_ability){
    int final_damage = 0;
    switch(choice_ability){
        case 1:
            final_damage = (player.Damage * player.damage_multiplier) - enemy.Defense;
            if(final_damage < 0) final_damage = 0;
            std::cout << "[ÚTOK]  Zvolili jste útok mečem\n";
            std::cout << "[POŠKOZENÍ]  Zasáhli jste nepřítele a způsobili mu " << final_damage << " poškození\n";
            enemy.HP -= final_damage;
            break;
        case 2:
            final_damage = (player.Damage + 5) * player.damage_multiplier - enemy.Defense;
            if(final_damage < 0) final_damage = 0;
            std::cout << "[ÚTOK]  Zvolili jste silný úder\n";
            std::cout << "[DEBUFF ENEMÁKÁ - OMRÁČENÍ]  Nepřítel je omráčen a nemůže útočit v příštím kole\n";
            std::cout << "[POŠKOZENÍ]  Zasáhli jste nepřítele a způsobili mu " << final_damage << " poškození\n";
            enemy.HP -= final_damage;
            enemy.stun_duration++;
            break;
        case 3:
            final_damage = (player.Damage + 5) * player.damage_multiplier - enemy.Defense;
            if(final_damage < 0) final_damage = 0;
            std::cout << "[DOMINANTNÍ JEDINEC :) ]  Zvolili jste dominantního jedince \n";
            std::cout << "[DEBUFF ENEMÁKA - DAMAGE]  Snižujete poškození nepřítele o 50% na 2 kola\n";
            std::cout << "[BUFF HRÁČ]  Zvýšíte poškození o 20% na 3 kola\n";
            std::cout << "[POŠKOZENÍ]  Zasáhli jste nepřítele a způsobili mu " << final_damage << " poškození\n";
            enemy.HP -= final_damage;
            player.jedinec_cooldown = 6;
            player.jedinec_buff_duration = 3;
            enemy.Damage_multiplier_duration = 2;
            break;
        default:
            break;
    }
    calculate_mana(player, 5);
    final_damage = 0;

}

void Ranger_atack(Player &player, Enemy &enemy, int choice_ability){
    int final_damage = 0;
    switch(choice_ability){
        case 1:
            final_damage = (player.Damage * player.damage_multiplier) - enemy.Defense;
            if(final_damage < 0) final_damage = 0;
            std::cout << "[ÚTOK]  Zvolili jste útok lukem\n";
            std::cout << "[POŠKOZENÍ]  Zasáhli jste nepřítele a způsobili mu " << final_damage << " poškození\n";
            enemy.HP -= final_damage ;
            break;
        case 2:
            final_damage = (player.Damage * player.damage_multiplier) - enemy.Defense;
            if(final_damage < 0) final_damage = 0;
            std::cout << "[ÚTOK]  Zvolili jste jedovatý šíp\n";
            std::cout << "[POŠKOZENÍ]  Zasáhli jste nepřítele a způsobili mu " << final_damage << " poškození\n";
            std::cout << "[DEBUFF ENEMÁKA - POISON]  Nepřitel dostal jed, který způsobí 3 poškození za kolo, po dobu 3 kol\n";
            if(enemy.poison_duration > 0) std::cout << "[DEBUFF POISON INFO]  Vzhledem k tomu že enemy už má poison tak ho bude mít o 3 kola déle\n";
            enemy.HP -= final_damage;
            enemy.poison_duration += 3;
            break;
        case 3:{
            std::cout << "[ÚTOK]  Zvolili jste šípovou sprchu\n";
            std::cout << "[INFO - ÚTOK]  Vystřelili jste salvu šípů na všechny nepřítele\n";
            std::cout << "[INFO - ÚTOK]  Každý zásah dává 75% poškození\n";
            player.is_sprcha_active = true;
            break;
        }
        default:
            break;
    }
    calculate_mana(player, 5);
    final_damage = 0;
}

void Gandalf_atack(Player &player, Enemy &enemy, int choice_ability){
    int final_damage = 0;
    switch(choice_ability){
        case 1:
            final_damage = (player.Damage * player.damage_multiplier) - enemy.Defense;
            if(final_damage < 0) final_damage = 0;
            std::cout << "[ÚTOK]  Zvolili jste flákanec\n";
            std::cout << "[POŠKOZENÍ]  Objevil se pan Lubimírek a plesknul mu za " << final_damage << " poškození\n";
            enemy.HP -= final_damage;
            break;
        case 2:
            std::cout << "[ÚTOK]  GAMBAAAAAAAAAAAAA (absolutní gigachad si po dnešku za zvolení tohoto útoku :D)\n";
            final_damage = gamba_Gandalf(player, enemy, final_damage);
            final_damage = final_damage * player.damage_multiplier - enemy.Defense;
            if(final_damage < 0) final_damage = 0;
            enemy.HP -= final_damage;
            break;
        case 3:
            std::cout << "[ÚTOK]  Karma\n";
            std::cout << "[KARMA]  V příštím kole se nepřítel zautočí sám na sebe\n";
            enemy.karma_active = true;
            break;
        default:
            break;
    }
    calculate_mana(player, 5);
    final_damage = 0;
}

void Input_ability(Player &player, int &choice_ability){
    do{
        Input_checker("Zadejte číslo schopnosti, kterou chcete použít: ", choice_ability, 1, 3);
        if(player.Mana < player.mana_cost[choice_ability - 1]){
            std::cout << "[CHYBA]  Nemáte dostatek many pro tuto schopnost. Zvolte jinou schopnost.\n";
            continue;
        }
        else if(player.jedinec_cooldown > 0 && player.Class_ID == 1 && choice_ability == 3){
            std::cout << "[CHYBA]  Schopnost Dominantní jedinec je momentálně v cooldownu. Zvolte jinou schopnost.\n";
            continue;
        }
        break;
    }while(true);
}
int gamba_Gandalf(Player &player, Enemy &enemy, int final_damage){
    int random = rand() % 2;
    int random2;
    switch(random){
        case 0:
            random2 = rand() % 3 + 1;
            final_damage = random2;
            std::cout << "[INFO - GAMBA]  No níc gamba nevyšla a dal si mu jenom " << final_damage << " poškození (tomu říkam skill issue ale určitě to zkus zas :D)\n";
            player.Gamba_counter--;
            if(player.Gamba_counter < -3){
                std::cout << "[INFO - GAMBA]  Teď si říkáš, že to je riggnutý. Je to možný, ale určitě nepřestávej gamblit\n";
            }
            break;
        case 1:
            random2 = rand() % 3 + 5;
            final_damage = random2;
            std::cout << "[INFO - GAMBA]  Ty si rozený gambler normálně. Vyhrál si gambu a dal si mu za " << final_damage << " poškození\n";
            player.Gamba_counter++;
            if(player.Gamba_counter > 4){
                std::cout << "[INFO - GAMBA]  vypni ty cheaty bro je to jenom hra (možná luck ?)\n";
            }
            std::cout << "[GAMBA - SCORE]  Tvoje gamba skóre je: " << player.Gamba_counter << "\n";
            break;
        default:
            break;
    }
    return final_damage;
}

bool check_dodge_player(Player &player){
    int random;
    switch(player.Dodge){
        case 0:
            random = rand() % 18;
            break;
        case 1:
            random = rand() % 12;
            break;
        case 2:
            random = rand() % 8;
            break;
        default:
            random = rand() % 4;
            break;        
    }
    if(random == 0){
        return true;
    }
    else{
        return false;
    }
}

void count_level(Player &player, int min, int max){
    std::cout << "\n========================================\n";
    std::cout << "            XP REWARDING SYSTEM.        \n";
    std::cout << "========================================\n";
    int random = rand () % (max - min + 1) + min;
    player.XP += random;
    std::cout << "[XP]  Získal jsi " << random << " XP\n[XP]  Celkem máš " << player.XP << "XP\n";
    while(player.XP >= 15){
        std::cout << "[LEVELUP]\n";
        player.Level++;
        std::cout << "[INFO - LEVEL]  Tvůj nový level je: " << player.Level << '\n';
        std::cout << "[INFO - LEVEL]  level tě stál 15XP\n";
        player.XP -=15;
        Choose_stat_upgrade(player);
    }
}
void Choose_stat_upgrade(Player &player){
    int choice;
    bool valid_choice = false;
    do{
        std::cout << "Vyber si z následujících možností co bys chtěl upgradnout:\n";
        std::cout << "1. upgrade max many o 5 (Aktuálně: " << player.upgrade_mana_counter << "/4)\n";
        std::cout << "2. upgrade max HP o 10 (Aktuálně: " << player.upgrade_hp_counter << "/4)\n";
        std::cout << "3. Zvýšit poškození o 5 (Aktuálně: " << player.upgrade_dmg_counter << "/4)\n";
        std::cout << "4. Zvýšit defense o 2 (Aktuálně: " << player.upgrade_dfns_counter << "/4)\n";
        
        Input_checker("Váš výběr: ", choice, 1, 4);

        if(choice == 1){
            if(player.upgrade_mana_counter < 4){
                player.Max_Mana += 5;
                player.Mana = player.Max_Mana;
                player.upgrade_mana_counter++;
                std::cout << "Výborně, maximální mana navýšena na: " << player.Max_Mana << '\n';
                valid_choice = true;
            }
            else{
                std::cout << "Mana upgrade je už na maximu!\n\n";
            }
        }
        else if(choice == 2){
            if(player.upgrade_hp_counter < 4){
                player.Max_HP += 10;
                player.HP = player.Max_HP;
                player.upgrade_hp_counter++;
                std::cout << "Výborně, maximální HP navýšeno na: " << player.Max_HP << '\n';
                valid_choice = true;
            }
            else{
                std::cout << "HP upgrade je už na maximu!\n\n";
            }
        }
        else if(choice == 3){
            if(player.upgrade_dmg_counter < 4){
                player.Damage += 5;
                player.upgrade_dmg_counter++;
                std::cout << "Výborně, tvůj Damage je nyní: " << player.Damage << '\n';
                valid_choice = true;
            }
            else{
                std::cout << "Damage upgrade je už na maximu!\n\n";
            }
        }
        else if(choice == 4){
            if(player.upgrade_dfns_counter < 4){
                player.Defense += 2;
                player.upgrade_dfns_counter++;
                std::cout << "Nyní máš " << player.Defense << " defense\n";
                valid_choice = true;
            }
            else{
                std::cout << "Defense upgrade je už na maximu!\n\n";
            }
        }
    }while(!valid_choice);
}

void calculate_mana(Player &player, int m){
    if(player.Mana == player.Max_Mana){
        std::cout << "[MANA]  už máš maximum many takže žádnou nedostaneš lol\n";
        player.Mana = player.Max_Mana;
        return;
    }
    player.Mana += m;
    if(player.Mana > player.Max_Mana){
        std::cout << "[MANA]  Doplnila se ti maximální mana\n";
        player.Mana = player.Max_Mana;
    }
    else{
        std::cout << "[MANA]  Za konec kola získáváš " << m << " many\n";
    }
    std::cout << "[MANA]  Aktuální mana: " << player.Mana << "/" << player.Max_Mana << "\n";
}