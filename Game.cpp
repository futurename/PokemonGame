
#include "Game.h"

#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

const string Game::FILE_NAME = "../pokemons.txt";

void Game::readPokenmonModelsFromFile(string &filename) {
    ifstream inFile(filename);
    if (inFile.is_open()) {
        string line;
        while (getline(inFile, line)) {
            if (!inFile.bad()) {
                string name, typeStr;
                int lifePoints, attackValue;
                stringstream ss(line);
                if (!(ss >> name >> lifePoints >> attackValue >> typeStr)) {
                    cout << "Reading pokemon info error: " + ss.str();
                }
                string symbol;
                while (getline(inFile, line) && !line.empty()) {
                    symbol += line + "\n";
                }

                Type type = getTypeFromNumber(stoi(typeStr));

                Pokemon pokemon(name, lifePoints, attackValue, type, symbol);
                pokenmonModels.push_back(pokemon);
            }
        }
        inFile.close();
    } else {
        cout << "Cannot open the configuration file: pokemons.txt" << endl;
    }
}

Game::Game() {
    readPokenmonModelsFromFile();
}

vector<Player> Game::getPlayers() {
    return players;
}

vector<Pokemon> Game::getPokenmonType() {
    return pokenmonModels;
}

Game::~Game() = default;

void Game::play(int roundLimit) {
    static int roundIndex = 1;
    const int roundTitleWidth = 15;

    cout << "How many players: " << endl;
    int numOfPlayers = getValidInputNumber();
    if (numOfPlayers <= 1) {
        cout << "Minimum 2 players" << endl;
        numOfPlayers = DEFAULT_PLAYER_NUM;
    }

    initPlayer(numOfPlayers);
    initActivePokemons();

    while (roundLimit-- > 0) {
        cout << setfill('*') << setw(roundTitleWidth) << " Round : "
             << to_string(roundIndex++) << " " << setw(roundTitleWidth) << "" << endl;

        cout << setfill(' ');

        for (int i = 0; i < players.size(); i++) {
            cout << "player sequence: " + to_string(i + 1) << endl;
            playByPlayer(players.at(i));
        }
    }
}

void Game::initPlayer(int numOfPlayers) {
    for (int i = 1; i <= numOfPlayers; i++) {
        string name = "Player_" + to_string(i);
        Player player(name);
        player.setPokenmons(createPokenmonVector(INIT_PLAYER_POKEMONS));
        players.push_back(player);
    }
    for (Player p: players) {
        cout << p.getName() << endl;
        for (Pokemon pm: p.getPokemons()) {
            pm.printPokemon();
        }
    }
}

int Game::getValidInputNumber() {
    int result;
    string input;
    while (true) {
        bool success = true;
        getline(cin, input);
        for (char c: input) {
            if (!isdigit(c)) {
                cout << "Not a number, try again: " << endl;
                success = false;
                break;
            }
        }
        if (success) {
            result = stoi(input);
            break;
        }
    }
    return result;
}

void Game::playByPlayer(Player &player) {
    cout << "Attack a pokemon <1> or other players <2> (1 or 2)" << endl;
    int input;
    while (true) {
        input = getValidInputNumber();
        if (input == 1 || input == 2) {
            break;
        } else {
            cout << "Please select 1 for attacking a pokemon or 2 for attacking a player: " << endl;
        }
    }
    if(input == 1){
        int randomIndex = getRandomNum(0, activePokenmons.size());
        Pokemon defender = activePokenmons.at(randomIndex);
        cout << endl << "DEFENDER: " << endl;
        defender.printPokemon();

        cout << endl;
        cout << "which pokemon will you choose for this combat? " << endl;
        for(int i = 0; i < player.getPokemons().size();i++){
            cout << "ID: <" << i << ">" << endl;
            player.getPokemons().at(i).printPokemon();
        }

        input = getValidInputNumber();
        Pokemon attacker = player.getPokemons().at(input);

        cout << "ATTACKER: "<< endl;
        attacker.printPokemon();
    }

}

void Game::initActivePokemons() {
    cout << ">>>>> Initializing active pokemon size : " << INIT_ACTIVE_POKEMONS << " <<<<<" << endl << endl;
    activePokenmons = createPokenmonVector(INIT_ACTIVE_POKEMONS);
}

int Game::getRandomNum(int low, int high) {
    return rand() % (high - low) + low;
}

vector<Pokemon> Game::createPokenmonVector(const int num) {
    vector<Pokemon> result;
    for (int i = 0; i < num; i++) {
        int ranIndex = getRandomNum(0, pokenmonModels.size());
        Pokemon onePokenmon(pokenmonModels.at(ranIndex));
        result.push_back(onePokenmon);
    }
    return result;
}
