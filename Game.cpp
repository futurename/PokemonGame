
#include "Game.h"

#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

void Game::readPokenmonsFromFile(string filename) {
    ifstream inFile(filename);
    if (inFile.is_open()) {
        string line;
        while (getline(inFile, line)) {
            if (!inFile.bad()) {
                string name, type;
                int lifePoints, attackValue;
                stringstream ss(line);
                if (!(ss >> name >> lifePoints >> attackValue >> type)) {
                    cout << "Reading pokemon info error: " + ss.str();
                }
                string symbol;
                while (getline(inFile, line) && !line.empty()) {
                    symbol += line + "\n";
                }
                Pokemon pokemon(name, lifePoints, attackValue, type, symbol);
                pokenmonModels.insert({name, pokemon});
            }
        }
        inFile.close();
    } else {
        cout << "Cannot open the configuration file: pokemons.txt" << endl;
    }
}

Game::Game(int numOfPlayers) {
    for (int i = 1; i <= numOfPlayers; i++) {
        string name = "Player_" + to_string(i);
        Player player(name);
        players.push_back(player);
    }

    readPokenmonsFromFile();
}

vector<Player> Game::getPlayers() {
    return players;
}

map<string, Pokemon> Game::getPokenmonType() {
    return pokenmonModels;
}

Game::~Game() {

}
