#include "GamePiece.hpp"
#include "GameState.hpp"
#include <iostream>
#include <string>
#include <vector>

using std::string;
using std::vector;

// a constructor to initialize values
GamePiece::GamePiece(string names, string types, GameState* state) {
  name_ = names;
  type_ = types;
  state_ = state;
  (*state).addPlayer(*this);
}

// a copy constructor
GamePiece::GamePiece(const GamePiece& game_piece_copy) {
  name_ = game_piece_copy.name_;
  type_ = game_piece_copy.type_;
  state_ = game_piece_copy.state_;
  state_->addPlayer(*this);
}

// deconstructor using the delete player method from GameState
GamePiece::~GamePiece() { state_->deletePlayer(*this); }

// This function returns the power of the player pieces
int GamePiece::GetPower() const {
  if (type_ == "Warrior") {
    return 5;
  } else if (type_ == "Scout") {
    return 1;
  } else {
    return state_->get_user_wizard_count(name_);
  }
}

// This function returns the speed of the player pieces
int GamePiece::GetSpeed() const {
  int speed = 1;
  if (type_ == "Warrior") {
    speed = 2;
  } else if (type_ == "Scout") {
    speed = 8;
  } else {
    speed = 12;
    int wizard_num = state_->enemy_wizard_count(name_);
    speed = speed - wizard_num;

    if (speed < 1) {
      speed = 1;
    }
  }
  return speed;
}

// the assignment operator
GamePiece& GamePiece::operator=(const GamePiece& one) {
  state_->deletePlayer(*this);
  name_ = one.name_;
  type_ = one.type_;
  state_ = one.state_;
  (*state_).addPlayer(*this);
  return *this;
}

// the == operator for the function
bool operator==(const GamePiece& one, const GamePiece& two) {
  if (one.GetPower() == two.GetPower()) {
    if (one.GetSpeed() == two.GetSpeed()) {
      return true;
    }
  }
  return false;
}

// the != operator for the function
bool operator!=(const GamePiece& one, const GamePiece& two) {
  if (one.GetPower() == two.GetPower()) {
    if (one.GetSpeed() == two.GetSpeed()) {
      return false;
    }
  }
  return true;
}

// the < operator for the function
bool operator<(const GamePiece& one, const GamePiece& two) {
  if (one.GetPower() < two.GetPower()) {
    return true;
  } else if (one.GetPower() == two.GetPower()) {
    if (one.GetSpeed() < two.GetSpeed()) {
      return true;
    }
  }
  return false;
}

// the > operator for the function
bool operator>(const GamePiece& one, const GamePiece& two) {
  if (one.GetPower() > two.GetPower()) {
    return true;
  } else if (one.GetPower() == two.GetPower()) {
    if (one.GetSpeed() > two.GetSpeed()) {
      return true;
    }
  }
  return false;
}

// the <= operator for the function
bool operator<=(const GamePiece& one, const GamePiece& two) {
  if (one.GetPower() < two.GetPower()) {
    return true;
  } else if (one.GetPower() == two.GetPower()) {
    if (one.GetSpeed() <= two.GetSpeed()) {
      return true;
    }
  }
  return false;
}

// the >= operator for the function
bool operator>=(const GamePiece& one, const GamePiece& two) {
  if (one.GetPower() > two.GetPower()) {
    return true;
  } else if (one.GetPower() == two.GetPower()) {
    if (one.GetSpeed() >= two.GetSpeed()) {
      return true;
    }
  }
  return false;
}

// ostream operator to print the final result containing the name, type, power,
// and speed
ostream& operator<<(ostream& os, const GamePiece& result) {
  os << "(" << result.GetPlayer() << "," << result.GetType() << ","
     << result.GetPower() << "," << result.GetSpeed() << ")";
  return os;
}

