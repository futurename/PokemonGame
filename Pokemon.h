
#ifndef POKEMONGAME_POKEMONBASE_H
#define POKEMONGAME_POKEMONBASE_H


#inlclude <iostream>

using namespace std;

class Pokemon {

  int lifePoints;
  int experiencePoints;
  
  ATTAK_TYPE attackType;
  int attackValue;
  int level;
  string symbol;
  string name;
  int id; // generated to be different for each Pokemon
  
  bool operator=(Pokemon){
    return true if same id
  }

  - levelUp()
  {
    //experienceLimit increase
    level +=1
    attackValue *= level //to define
  }

  + int getAttackValueFor(type){
    if(attackType == PHYSICAL){
      return attackValue* (level/ 1.5)
    }
  }
  + reduceLifePoints(int points)
  - gainExperince(int points)

  + recover(){
    // recover from a percentage each round
  }

  





};


#endif //POKEMONGAME_POKEMONBASE_H
