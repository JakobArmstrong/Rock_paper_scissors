#include <iostream>
#include <random>

int user_wins = 0;
int computer_wins = 0;
int draws = 0;


std::vector<std::string> options{"rock", "paper", "scissors"};

std::string user_input;

/* generates random number for computer selection
    rock: 0, paper: 1, scissors: 2 */
int random() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> random_number(0, 2);
    return random_number(gen);
}

void win_condition() {
    user_wins++;
    std::cout << "User wins! :D" << "\n";
}

int main() {
    while(true) {
        std::cout << "\nEnter Rock/Paper/Scissors or Q to quit: ";
        std::getline (std::cin, user_input);

        for (int i=0; i<user_input.length(); i++) {
            user_input[i] = tolower(user_input[i]);
        }

        if (user_input == "q") {
            break;
        }
        
        std::string computer_choice = options[random()];
        std::cout << "Computer picked " << computer_choice << ".\n\n";

        if (user_input == "rock" && computer_choice == "scissors") {
            win_condition();
        }

        else if (user_input == "paper" && computer_choice == "rock") {
            win_condition();
        }

        else if (user_input == "scissors" && computer_choice == "paper") {
            win_condition();
        }

        else if (user_input == computer_choice) {
            std::cout << "Draw!\n";
            draws++;
        }

        else {
            std::cout << "You lost! :(\n";
            computer_wins++;
        }

        std::cout << "\nYou won " << user_wins << " times.";
        std::cout << "\nThe computer won " << computer_wins << " times.";
        std::cout << "\nYou and the computer drew " << draws << " times.\n";

    }
    
    std::cout << "\nProgram done, Goodbye!" << std::endl;
}