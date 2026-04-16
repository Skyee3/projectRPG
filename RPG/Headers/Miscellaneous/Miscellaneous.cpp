#include <iostream>
#include "Miscellaneous.hpp"

void Show_start_menu(){
    int choice;
    std::cout << "\n========================================" << std::endl;
    std::cout << "                RPG                      " << std::endl;
    std::cout << "========================================" << std::endl;
    std::cout << "  [1] Nová hra\n";
    std::cout << "  [2] O hře\n";
    std::cout << "  [3] Ukoncit\n";
    std::cout << "----------------------------------------" << std::endl;
    do{
        std::cout << "Vaše volba: ";
        std::cin >> choice;
        if(std::cin.fail() || choice < 1 || choice > 3) {
            std::cin.clear();
            std::cin.ignore(1000, '\n');
            std::cout << "ERROR: Zadejte validní hodnotu (1-3)\n";
            continue;
        }
        else{
            break;
        }
    }while(true);
    
    switch (choice){
        case 1:
            break;
        case 2:
            break;
        case 3:
            break;
        default:
            break;
    }
    
}
