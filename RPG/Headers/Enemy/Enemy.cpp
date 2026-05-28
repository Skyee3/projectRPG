#include "Enemy.hpp"
#include "Player.hpp"

std::vector<question> initialize_questions(){
    std::vector<question> questions = {
        {"Který stát je největší na světě podle rozlohy?\n1) Kanada\n2) Čína\n3) USA\n4) Rusko\n", 4},
        {"Jaká je hlavní zkratka pro herní žánr, kde se střílí z pohledu první osoby (např. Doom, Counter-Strike)?\n1) RPG\n2) RTS\n3) FPS\n4) MOBA\n", 3},
        {"Které město je hlavním městem Spojených států amerických?\n1) New York\n2) Washington, D.C.\n3) Los Angeles\n4) Chicago\n", 2},
        {"Kolik minut má jeden hokejový zápas (čistého času bez prodloužení)?\n1) 45 minut\n2) 60 minut\n3) 80 minut\n4) 90 minut\n", 3},
        {"Která látka dává rostlinám jejich zelenou barvu a umožňuje fotosyntézu?\n1) Chlorofyl\n2) Karoten\n3) Hemoglobin\n4) Melanin\n", 1},
        {"Ve kterém městě byste našli slavnou Eiffelovu věž?\n1) Londýn\n2) Berlín\n3) Paříž\n4) Řím\n", 3},
        {"Který bájný pták podle pověstí vstal z vlastního popela?\n1) Pegas\n2) Fénix\n3) Gryf\n4) Sfinga\n", 2},
        {"Jak se jmenuje největší žijící savec na naší planetě?\n1) Slon africký\n2) Vorvaň obrovský\n3) Plejtvák obrovský\n4) Žralok velrybí\n", 3},
        {"Který mořeplavec v roce 1492 oficiálně objevil Ameriku pro evropský svět?\n1) Vasco da Gama\n2) Kryštof Kolumbus\n3) Fernando Magellan\n4) Marco Polo\n", 2},
        {"Jaká je nejvyšší hora světa?\n1) K2\n2) Kilimandžáro\n3) Mont Blanc\n4) Mount Everest\n", 4},
        {"Který nástroj se používá k měření atmosférického tlaku?\n1) Teploměr\n2) Barometr\n3) Vlhkoměr\n4) Seismograf\n", 2},
        {"Jaké je hlavní město Itálie?\n1) Milán\n2) Benátky\n3) Neapol\n4) Řím\n", 4},
        {"Která země je domovem divokých klokanů a koal?\n1) Jižní Afrika\n2) Austrálie\n3) Nový Zéland\n4) Madagaskar\n", 2},
        {"Kterou planetu v naší sluneční soustavě označujeme jako 'Rudou planetu'?\n1) Venuše\n2) Mars\n3) Jupiter\n4) Saturn\n", 2},
        {"Kdo napsal slavnou divadelní tragédii Romeo a Julie?\n1) William Shakespeare\n2) Charles Dickens\n3) Edgar Allan Poe\n4) Oscar Wilde\n", 1},
        {"Která tekutina koluje v lidském těle a rozvádí kyslík?\n1) Lymfa\n2) Voda\n3) Žluč\n4) Krev\n", 4},
        {"Kolik barev má základní duhové spektrum?\n1) 5\n2) 6\n3) 7\n4) 8\n", 3},
        {"Která slavná starověká památka se nachází v egyptské Gíze?\n1) Koloseum\n2) Velká čínská zeď\n3) Pyramidy\n4) Tádž Mahal\n", 3},
        {"Který evropský stát má tvar připomínající vysokou botu?\n1) Španělsko\n2) Řecko\n3) Itálie\n4) Portugalsko\n", 3},
        {"Jaká měna se oficiálně používá ve Velké Británii?\n1) Euro\n2) Libra šterlinků\n3) Dolar\n4) Frank\n", 2},
        {"Který hmyz je známý tím, že žije v úlech a vyrábí med?\n1) Čmelák\n2) Vosa\n3) Sršeň\n4) Včela\n", 4},
        {"Který oceán odděluje Ameriku od Evropy a Afriky?\n1) Tichý oceán\n2) Atlantský oceán\n3) Indický oceán\n4) Severní ledový oceán\n", 2},
        {"Které číslo následuje v řadě: 2, 4, 8, 16, ...?\n1) 20\n2) 24\n3) 32\n4) 64\n", 3},
        {"Jaké je hlavní město Velké Británie?\n1) Edinburgh\n2) Dublin\n3) Liverpool\n4) Londýn\n", 4},
        {"Který slavný fyzik objevil gravitační zákon, když mu (podle legendy) spadlo na hlavu jablko?\n1) Albert Einstein\n2) Isaac Newton\n3) Galileo Galilei\n4) Nikola Tesla\n", 2},
        {"Který orgán v lidském těle je zodpovědný za pumpování krve?\n1) Plíce\n2) Mozek\n3) Srdce\n4) Játra\n", 3},
        {"Která země je celosvětově nejznámější výrobou javorového sirupu (má javorový list i na vlajce)?\n1) USA\n2) Kanada\n3) Norsko\n4) Finsko\n", 2},
        {"Který herní hrdina nosí červenou čepici, montérky a zachraňuje princeznu Peach?\n1) Sonic\n2) Link\n3) Mario\n4) Crash\n", 3},
        {"Který kov je nejlepším vodičem elektrického proudu z těchto běžně používaných?\n1) Železo\n2) Měď\n3) Hliník\n4) Olovo\n", 2},
        {"Jak se nazývá proces, při kterém se voda mění v páru?\n1) Kondenzace\n2) Sublimace\n3) Vypařování\n4) Tání\n", 3},
        {"Ve které zemi vznikly první moderní olympijské hry?\n1) Itálie\n2) Řecko\n3) Francie\n4) Velká Británie\n", 2},
        {"Který kontinent je nejchladnější a trvale neobydlený lidmi (kromě vědců)?\n1) Arktida\n2) Grónsko\n3) Antarktida\n4) Sibiř\n", 3},
        {"Jak se nazývá největší poušť na africkém kontinentu?\n1) Kalahari\n2) Sahara\n3) Gobi\n4) Atacama\n", 2},
        {"Které chemické sloučenině odpovídá vzorec H2O?\n1) Oxid uhelnatý\n2) Kyselina sírová\n3) Voda\n4) Peroxid vodíku\n", 3},
        {"Který umělec namaloval světoznámý obraz Mony Lisy?\n1) Vincent van Gogh\n2) Pablo Picasso\n3) Michelangelo\n4) Leonardo da Vinci\n", 4},
        {"Ve kterém roce začala druhá světová válka?\n1) 1914\n2) 1918\n3) 1939\n4) 1945\n", 3},
        {"Které zvíře je symbolem moudrosti v mnoha světových kulturách?\n1) Liška\n2) Sova\n3) Lev\n4) Had\n", 2},
        {"Která řeka je považována za nejdelší v Evropě?\n1) Dunaj\n2) Rýn\n3) Volha\n4) Seina\n", 3},
        {"Jak se jmenuje hlavní město Německa?\n1) Mnichov\n2) Frankfurt\n3) Hamburk\n4) Berlín\n", 4},
        {"Kolik dní má běžný (nepřestupný) kalendářní rok?\n1) 360\n2) 364\n3) 365\n4) 366\n", 3},
        {"Který filmový režisér natočil Jurský park, Čelisti nebo E.T. - Mimozemšťan?\n1) Quentin Tarantino\n2) Steven Spielberg\n3) Christopher Nolan\n4) James Cameron\n", 2},
        {"Jaké je hlavní město Japonska?\n1) Kjóto\n2) Ósaka\n3) Tokio\n4) Hirošima\n", 3},
        {"Který zubní orgán/tkáň je nejtvrdší v lidském těle?\n1) Kost\n2) Zubní sklovina\n3) Chrupavka\n4) Nehet\n", 2},
        {"Která z těchto možností je hlavním zdrojem tepla a světla pro planetu Zemi?\n1) Měsíc\n2) Slunce\n3) Jádro Země\n4) Polární záře\n", 2},
        {"Která země je známá svými větrnými mlýny, tulipány a cyklistikou?\n1) Belgie\n2) Nizozemsko (Holandsko)\n3) Dánsko\n4) Švýcarsko\n", 2},
        {"Jak se jmenuje legendární britský tajný agent s kódovým označením 007?\n1) Sherlock Holmes\n2) Ethan Hunt\n3) Jason Bourne\n4) James Bond\n", 4},
        {"Které zvíře dokáže žít nejdéle bez vody v poušti díky svým hrbům?\n1) Velbloud\n2) Žirafa\n3) Surikata\n4) Pouštní liška\n", 1},
        {"Jaké je hlavní město Francie?\n1) Lyon\n2) Marseille\n3) Bordeaux\n4) Paříž\n", 4},
        {"Které herní studio vytvořilo celosvětový hit Minecraft?\n1) Rockstar Games\n2) Mojang\n3) Valve\n4) EA Sports\n", 2},
        {"Který plyn lidé vdechují, aby mohli žít?\n1) Dusík\n2) Kyslík\n3) Oxid uhličitý\n4) Vodík\n", 2}
    };
    return questions;
}

void Choose_enemy(Enemy &enemy){
    int random = rand() % 10;
    if(random < 1 && !enemy.was_quizler){
        enemy.set_enemy("Quizler", 4, 100, 10, 1);
        enemy.was_quizler = true;
    }
    else if(random < 4) enemy.set_enemy("Buldozer", 1, 50, 10, 5);
    else if(random < 7) enemy.set_enemy("Kostík", 2, 80, 15, 8);
    else enemy.set_enemy("Bohničan", 3, 120, 20, 10);

}

void Enemy_turn(Player &player, Enemy &enemy, std::vector<question> &questions){
    std::cout << "\n========================================\n";
    std::cout << "             TAH " << enemy.name << "a\n";
    std::cout << "========================================\n";
    switch(enemy.Type){
        case 1:
            Buldozer_turn(player, enemy);
            break;
        case 2:
            kostik_turn(player, enemy);
            break;
        case 3:
            bohnican_turn(player, enemy);
            break;
        case 4:
            quizler_turn(player, enemy, questions);
            break;
        default:
            break;
    }
}

void Buldozer_turn(Player &player, Enemy &enemy){
    int final_damage;
    int ability = rand() % 4;
    switch(ability){
        case 0:
            final_damage = (enemy.Damage - 2) - player.Defense;
            std::cout << "Buldozer ti napálil a dal ti " << final_damage << " poškození a oslabil tě na další kolo o 15%\n";
            player.HP -= final_damage; 
            enemy.player_debuff_by_buldozer = 1;
            break;
        case 1:
            final_damage = enemy.Damage + 5 - player.Defense;
            std::cout << "Buldozer zvolil útok ohňem a dal ti " << final_damage << " poškození.\n";
            std::cout << "Po dobu 2 kol budeš hořet a dostavat 5 poškození navíc.\n";
            player.HP -= final_damage;
            break;
        default:
            final_damage = enemy.Damage - player.Defense;
            std::cout << "Buldozer zvolil basic útok a kopl tě za" << final_damage << " poškození.\n";
            player.HP -= final_damage;
            break;
    }
    final_damage = 0;
}

void kostik_turn(Player &player, Enemy &enemy){
    int final_damage;
    int ability = rand() % 10;
    if(ability >= 8){
        int arrow_count = check_dodge_kostik(player);
        std::cout << "Kostík do svého luku dal 10 šípů a vystřelil do vzduchu, každopádně každý dává jen 50% poškození\n";
        final_damage = (enemy.Damage * arrow_count) * 0.50 - player.Defense;

        std::cout << "Celkem si dostal " << final_damage << " poškození\n";
        player.HP -= final_damage;
    }
    else if(ability == 7 && !enemy.is_upgraded){
        std::cout << "Kostík vylepšil svůj luk a jeho útoky teď dávají o 5 poškození navíc.\n";
        std::cout << "Toto kolo si nedostal žádné poškození.\n";
        enemy.Damage += 5;
        enemy.is_upgraded = true;
    }
    else{
        final_damage = enemy.Damage - player.Defense;
        std::cout << "Kostík vytasil svůj luk a trefil ti za " << final_damage << " poškození.\n";
        player.HP -= final_damage;
    }
    final_damage = 0;
}

int check_dodge_kostik(Player &player){
    int Arrow_hitted = 0;
    switch(player.Dodge){
        case 0:
            Arrow_hitted = rand() % 2 + 7;
            std::cout << "Jelikož ještě nemáš vylepšený dodge tak tě trefil " << Arrow_hitted << " šípama\n";
            break;
        case 1:
            Arrow_hitted = rand() % 2 + 6;
            std::cout << "Vzhledem k tomu že máš alespoň trošičku vylepšnený dodge tak tě trefil " << Arrow_hitted << " šípama\n";
            break;
        case 2:
            Arrow_hitted = rand() % 2 + 4;
            std::cout << "Vzhledem k tomu že máš vylepšený dodge tak tě trefil  " << Arrow_hitted << " šípama\n";
            break;
        case 3:
            Arrow_hitted = rand() % 2 + 3;
            std::cout << "Vzhledem k tomu že máš velmi dobře vylepšený dodge tak tě trefil jenom " << Arrow_hitted << " šíppama\n";
            break;
    }
    return Arrow_hitted;
}

void bohnican_turn(Player &player, Enemy &enemy){
    int ability = rand() % 10;
    int final_damage;
    if(ability >= 8 && !enemy.is_upgraded){
        std::cout << "Bro si našel pytlík s kouzelným bílým práškem (cukr samozřejmě) a pocháloval si\n";
        std::cout << "odteď bude dávát větší poškození (seš cooked)\n";
        enemy.is_upgraded = true;
        enemy.Damage += 10;
    }
    else if(ability >=5 && ability < 8){
        int count_enemies = rand() % 3 + 2;
        if(count_enemies == 3) count_enemies = 4;
        final_damage = (enemy.Damage * count_enemies) / 2;
        std::cout << "Pacient z bohnic si povolal armádu jeho kamarádů a všichni se na tebe vrhli a dostal si absolutní bídu\n";
        std::cout << "Vzhledem k tomu že na tebe naběhlo " << count_enemies << " nepřátel tak si dostal " << final_damage << " poškození\n";
        std::cout << "Pro tvoje štěstí jsi je vypnul na jeden hit takže už nejsou (dont worry, be happy)\n";
        player.HP -= final_damage;
    }
    else{
        final_damage = enemy.Damage - player.Defense;
        std::cout << "Dostal si flákanec lol\n";
        std::cout << "Prostě basic útok co čekáš. Dostáváš " << final_damage << " poškození.\n";
        player.HP -= final_damage;
    }
    final_damage = 0;
}

void quizler_turn(Player &player, Enemy &enemy, std::vector<question> &questions){
    int random = rand() % questions.size();
    question current_question = questions[random];
    std::cout << current_question.question_text;
    int answer;
    Input_checker("Odpověď (1-4): ", answer, 1, 4);
    if(answer == current_question.correct_option){
        std::cout << "Správně! Způsobil jsi " << player.Damage << '\n';
        enemy.HP -= player.Damage;
    }
    else{
        std::cout << "Špatně! správná odpověď byla " << current_question.correct_option << '\n';
        std::cout << "dostal si " << enemy.Damage << " poškození\n";
        player.HP -= enemy.Damage;
    }
    questions.erase(questions.begin() + random);
}