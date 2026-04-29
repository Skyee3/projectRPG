#include <iostream>
#include "Miscellaneous.hpp"

void Show_start_menu(){
    std::cout << "\n========================================" << std::endl;
    std::cout << "                RPG                      " << std::endl;
    std::cout << "========================================" << std::endl;
    std::cout << "  [1] Nová hra\n";
    std::cout << "  [2] O hře\n";
    std::cout << "  [3] Ukoncit\n";
    std::cout << "----------------------------------------" << std::endl;
    int choice;
    Input_checker("Vaše volba: ", choice, 1, 3);
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

void Input_checker(std::string Input_message, int &input, int min, int max){
    do{
        std::cout << Input_message;
        std::cin >> input;
        if(std::cin.fail() || input < min || input > max) {
            std::cin.clear();
            std::cin.ignore(1000, '\n');
            std::cout << "ERROR: Zadejte validní hodnotu (" << min << "-" << max << ")\n";
            continue;
        }
        break;
    }while(true);
}