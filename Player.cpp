
#include "Player.h"
#include <iostream>
#include <vector>

using namespace std;


Player::Player(string name) : name(name) {}

string Player::getName() const {
    return name;
}

vector<Pokemon> Player::getPokemons(){
    return playerPokemons;
}
void Player::addPokenmon(Pokemon pokemon){
    playerPokemons.push_back(pokemon);
}
bool Player::removePokemon(Pokemon pokemon){
    for(auto it = playerPokemons.begin(); it != playerPokemons.end(); it++){
        if( it->getId() == pokemon.getId() ) {
            playerPokemons.erase(it);
            return true;
        }
    }
    return false;
}

void Player::recoverBloodPoints(double ratio) {
    for (int i = 0; i < playerPokemons.size(); i++) {
        int blood = playerPokemons.at(i).getBloodPoints();
        playerPokemons.at(i).setBloodPoints( blood +ratio);
    }
}

void Player::setPokenmons(vector<Pokemon> pokemons) {
    playerPokemons = pokemons;
}
