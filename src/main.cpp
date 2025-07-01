#include "Game.hpp"

inline void printUsage() {
    std::cout << "Usage: ./unoInTerminal -d <delayTime> -p <playerCnt>"
              << std::endl;
}

int main(int argc, char** argv) {
    size_t delaySeconds = 2;
    size_t playersCnt = 3;

    if (argc == 1) {
        std::cout << "By default there are 3 players in the game and delay "
                  << "between info messages is set to 2 seconds. You can "
                  << "change amount of players and delay time using command "
                  << "line arguments:"
                  << std::endl
                  << "./unoInTernimal -d <delayTime> -p <playerCnt>"
                  << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(4));
    }
    
    else if (argc == 5) {
        bool changedDelaySeconds = false;
        bool changedPlayersCnt = false;
        for (int i = 0; i < argc; ++i) {
            if (std::string(argv[i]) == "-d" && i + 1 < argc) {
                changedDelaySeconds = true;
                delaySeconds = atoi(argv[i + 1]);
            }
            if (std::string(argv[i]) == "-p" && i + 1 < argc) {
                changedPlayersCnt= true;
                playersCnt = atoi(argv[i + 1]);
            }
        }
        if (!changedDelaySeconds || !changedPlayersCnt) {
            printUsage();
            return 0;
        }
        if (delaySeconds < 0) {
            std::cout << "Bad delay time." << std::endl;
            return 0;
        }
        if (!(2 <= playersCnt && playersCnt <= 10)) {
            std::cout << "Bad players count." << std::endl;
            return 0;
        }
    }
    
    else {
        printUsage();
        return 0;
    }

    Game game(playersCnt, delaySeconds);
}