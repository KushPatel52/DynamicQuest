#pragma once
#include "GameState.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <ostream>

using std::string;
using std::vector;
using std::ostream;

// class GameState;

class GamePiece {
 private:
  string name_;  // string for the player name
  string type_;  // string for the type of piece
  GameState* state_;  // gamestate class

 public:
  int GetPower() const;  // gets the power
  int GetSpeed() const;  // gets the speed
  ~GamePiece();  // deconstructor
  GamePiece(string names, string types,
            GameState* games);  // a constructor to initialize values
  GamePiece(const GamePiece&);  // a constructor to initalize variables
  string GetPlayer() const { return name_; }  // returns the name of the player
  string GetType() const { return type_; }  // returns the type of piece

  GamePiece& operator=(const GamePiece&);  // the assignment operator

  // different required operators for the function

  friend bool operator==(const GamePiece&, const GamePiece&);
  friend bool operator!=(const GamePiece&, const GamePiece&);
  friend bool operator<(const GamePiece&, const GamePiece&);
  friend bool operator>(const GamePiece&, const GamePiece&);
  friend bool operator<=(const GamePiece&, const GamePiece&);
  friend bool operator>=(const GamePiece&, const GamePiece&);

  friend ostream& operator<<(ostream& os,
                             const GamePiece&);  // print ostream operator
};
