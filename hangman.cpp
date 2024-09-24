#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <limits>


struct GameResources{

std::vector<std::string> players{};
std::string words[5] =
{
    "Manguangua",
    "Gafito",
    "Arepa",
    "America",
    "Prime",
};
short limbs = 5;
};


void confirming_players(){

    GameResources resource;

    std::vector<std::string> *pPlayers = &resource.players;
    std::string player;
    int amount_of_players;
    std::cout << "How many players are there?";
    std::cin >> amount_of_players;
    while (true){
        std::cout << "Introduce their names (for every name, push ENTER):" << std::endl
                  << "--> ";
        std::cin >> player;
        if (player == "stop"){
            break;
        }
        for (int i = 0; i < amount_of_players; i++){
            (*pPlayers).push_back(player);
        }
    }
    
}

void rules(){
    std::cout << " |          The rules are pretty simple:";

}


void winner(){
    GameResources resources;
    std::cout << "AND THE WINNER IS " << resources.players[0] << std::endl;
}
void loser(){
    GameResources resources;
    std::cout << "YOU SUCK, " << resources.players[0] << std::endl;
}


bool player_letter(std::string letter, std::string word, std::vector<std::string>& letters){
     if (word.find(letter) != 0){
        return false;
    } else if (word.find(letter) == 0){
        int index = std::stoi((letters).at(word.find_first_of(letter)));
        (letters).at(index) = letter;
        return true;
    }
    return false;
}

bool counting_victories(short& correct, short& incorrect, std::string letter, std::string word, std::vector<std::string> array_letters){
    if (player_letter(letter, word, array_letters) == true){
        std::cout << "You got it!" << std::endl;
        return true;
    } else {
        std::cout << "NOPE!" << std::endl;
        return false;
    }
}



void game(std::string word){

    GameResources resources;
    std::string letter;
    short correct = 0;
    short incorrect = 0; 
    std::vector<std::string> array_letters(word.length()); 
    short winning = 0;
    short losing = 0;
    short final_countdown;
    for (int i = 0; i <= word.length(); i++){
        (array_letters).push_back("_");
    }
    std::cout << "LET'S START!" 
              << std::endl
              << std::endl;
    while (true){
        if ((winning == word.length()) || (losing == resources.limbs)){
            break;
        } 
        std::cout << "--> ";
        for (const auto& blank: array_letters){
            std::cout << blank << " ";
        }
        std::cout << std::endl;
        std::cout << "Can you guess the word...?: "; 
        std::getline(std::cin, letter);
        if (std::cin.fail()){
            std::cout << "Come on! Give me a letter!" << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max());
            break;
        }
        if (counting_victories(correct, incorrect, letter, word, array_letters) == true) {
            winning += correct;
        } else {
            losing += incorrect;
        }
        
    }
        if (winning == word.length()){
            final_countdown = 0;
        } else {
            final_countdown = 1;
        }
    switch (final_countdown){
    case 0:
        winner();
    case 1:
        loser();
    default:
        break;
    }
}


std::string initiating_game(){    
    GameResources resource;
    std::string word_in_game;
    srand(time(0));
    const short min_value = 0;
    const short max_value = 5;
    const short index = (rand() % (max_value - min_value + 1)) + min_value;
    std::cout << index << std::endl;
    return word_in_game = resource.words[index];
}

void introduction(){

    std::cout << "Welcome to the Ultimate Hangman Game!" << std::endl;




}


int main(){
    introduction();
    confirming_players();
    std::string word = initiating_game();
    game(word);
    
    return 0;
}