
#include "Game.h"

#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

const string Game::FILE_NAME = "../pokemons.txt";

void Game::readPokenmonModelsFromFile(string& filename) {
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
                pokenmonModels.insert({pokemon.getId(), pokemon});
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

map<int, Pokemon> Game::getPokenmonType() {
    return pokenmonModels;
}

Game::~Game() = default;

void Game::play(int roundLimit) {
    static int roundIndex = 1;
    const int roundTitleWidth = 15;

    cout << "How many players: " << endl;
    int numOfPlayers = getValidInputNumber();

    initPlayer(numOfPlayers);
    initActivePokemons();

    while (roundLimit-- > 0) {
        cout << setfill('*') << setw(roundTitleWidth) << " Round : "
             << to_string(roundIndex) << " " << setw(roundTitleWidth) << "" << endl;

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
        players.push_back(player);
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

}

void Game::initActivePokemons() {
    for(int i = 0; i < INIT_ACTIVE_POKEMONS; i++){
        int ranIndex = getRandomNum(0, INIT_ACTIVE_POKEMONS);

        cout << "random num: " << ranIndex << endl;


    }
}

int Game::getRandomNum(int low, int high) {
    return rand() % (high - low) + low;
}
