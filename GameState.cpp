#include "GameState.hpp"
#include "GamePiece.hpp"

#include <map>
using std::map;
#include <vector>
using std::vector;

#include <string>
using std::string;

// This function allows for adding a new player to the map containing the
// strings for the player name and the type name
void GameState::addPlayer(GamePiece &player) {
  account_of_playerName_pieceName_[player.GetPlayer()].push_back(
      player.GetType());
  num_of_pieces = num_of_pieces + 1;
}

// This function allows for deleating a new player to the map containing the
// strings for the player name and the type name
void GameState::deletePlayer(GamePiece &player) {
  if (account_of_playerName_pieceName_.count(player.GetPlayer()) == 1) {
    auto &ptrVec = account_of_playerName_pieceName_[player.GetPlayer()];
    for (auto its = ptrVec.begin(); its != ptrVec.end(); its++) {
      if ((*its) == player.GetType()) {
        ptrVec.erase(its);
        num_of_pieces--;
        break;
      }
    }
  }
}

// The first NumPieces function, takez in no parameters and returns the count of
// the total game poieces in play regardless of which team they are on.
int GameState::NumPieces() { return num_of_pieces; }

// The second NumPieces function, which takes in the parameter of a name, and
// returns the number of pieces that a specific player has.
int GameState::NumPieces(const string &name) {
  int count_of_pieces = 0;
  for (auto itr = account_of_playerName_pieceName_.begin();
       itr != account_of_playerName_pieceName_.end(); itr++) {
    if (itr->first == name) {
      count_of_pieces += itr->second.size();
    }
  }
  return count_of_pieces;
}

// The last NumPieces function, which takes a player name and a type name, and
// returns the numer of pieces that the player has of that type
int GameState::NumPieces(const string &name, const string &type) {
  vector<string> piece;
  int count_of_pieces = 0;
  piece = account_of_playerName_pieceName_[name];
  for (auto itr = piece.begin(); itr != piece.end(); itr++) {
    if ((*itr) == type) {
      count_of_pieces = count_of_pieces + 1;
    }
  }

  return count_of_pieces;
}

// A helper function which takes in the name of the opposing player and returns
// the number of wizards that he/she has in play
int GameState::enemy_wizard_count(const string &name) {
  int wizard_count = 0;
  for (auto const &piece : account_of_playerName_pieceName_) {
    if (piece.first != name) {
      for (auto type_of_piece : piece.second) {
        if (type_of_piece == "Wizard") {
          wizard_count = wizard_count + 1;
        }
      }
    }
  }
  return wizard_count;
}

// A helper function which takes in the name of theplayer and returns the number
// of wizards that he/she has in play
int GameState::get_user_wizard_count(const string &name) {
  int wizard_count = 0;
  for (auto const &piece : account_of_playerName_pieceName_) {
    if (piece.first == name) {
      for (auto type_of_piece : piece.second) {
        if (type_of_piece == "Wizard") {
          wizard_count = wizard_count + 1;
        }
      }
    }
  }
  return wizard_count;
}

