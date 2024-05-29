#include "./gameEngine.cpp"

void startingGUI() {

 std::cout << R"(
       __  ____                                                   
      /  |/  (_)___  ___  _____                                  
     / /|_/ / / __ \/ _ \/ ___/      _____  ___  ____  ___  _____
    / /  / / / / / /  __/\__ \ | /| / / _ \/ _ \/ __ \/ _ \/ ___/ 
    _/  /_/_/_/ /_/\___/ __/ / |/ |/ /  __/  __/ /_/ /  __/ /  
  /___________________ /____/|__/|__/\___/\___/ .___/\___/_/   
                      |_____________________ /_/_____________/ 
                      
                                         ¿CAN YOU FIND 'EM ALL?   
    )" << '\n';

    std::cout << WHITE << "              |A| " <<  MAGENTA << "Beginner " << WHITE << "[8 x 8 - 16 BOMBS]" << std::endl;
    std::cout << WHITE << "      " << std::endl;
    std::cout << WHITE << "              |B| " << MAGENTA << "Intermediate " << WHITE << "[16 x 16 - 40 BOMBS]" << std::endl;
    std::cout << WHITE << "          " << std::endl;
    std::cout << WHITE << "              |C| " << MAGENTA << "Advanced " << WHITE << "[16 x 30 - 99 BOMBS]" << std::endl;
    std::cout << WHITE << "      " << std::endl;
    std::cout << MAGENTA << "  ___________________________________________________________" << std::endl;
    std::cout << MAGENTA << "  -Miney: "<< WHITE <<"Welcome! Please SELECT a DIFFICULT to start playing: ";
};

void rules(int bombs) {

    std::cout << WHITE << "  ____________________________________________________________" << std::endl;
    std::cout << WHITE << "      " << std::endl;
    std::cout << MAGENTA <<"                            RULES" << std::endl;
    std::cout << WHITE << "      " << std::endl;
    std::cout << MAGENTA << "       // " << WHITE  << "Only up to " << 16 << " cells can be FLAGGED" << std::endl;
    std::cout << WHITE << "      " << std::endl;
    std::cout << MAGENTA << "       // " << WHITE  << "You can't EXPLORE a cell that is already FLAGGED" << std::endl;
    
    std::cout << WHITE << "      " << std::endl;
    std::cout << MAGENTA << "       // " << WHITE  << "Neither, FLAG or EXPLORE a explored one." << std::endl;
    std::cout << WHITE << "      " << std::endl;
    std::cout << MAGENTA << "       // " << WHITE  << "FLAG or EXPLORE outside the board is ilegall" << std::endl;
    std::cout << WHITE << "      " << std::endl;
    std::cout << MAGENTA << "       // " << WHITE  << "Using an incorrect move format." << std::endl;
    std::cout << WHITE << "      " << std::endl;
    std::cout << WHITE << "  ____________________________________________________________" << std::endl;
};

