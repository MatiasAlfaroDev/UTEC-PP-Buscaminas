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

    std::cout << WHITE << "              |A| " << GREEN << "Beginner " << WHITE << "[8 x 8 - 16 BOMBS]" << std::endl;
    std::cout << WHITE << "      " << std::endl;
    std::cout << WHITE << "              |B| " << YELLOW << "Intermediate " << WHITE << "[16 x 16 - 40 BOMBS]" << std::endl;
    std::cout << WHITE << "          " << std::endl;
    std::cout << WHITE << "              |C| " << RED<< "Advanced " << WHITE << "[16 x 30 - 99 BOMBS]" << std::endl;
    std::cout << WHITE << "      " << std::endl;
    std::cout << CYAN  << "  ___________________________________________________________" << std::endl;
    std::cout << CYAN  << "  -Miney: "<< WHITE <<"Welcome! Please SELECT a DIFFICULT to start playing: ";
};