#pragma once

#include <map>
#include <string>
using std::string;
using std::map;
#include <vector>
using std::vector;

class GamePiece;
class GameState {
 private:
  int num_of_pieces = 0;  // total number of pieces
  map<string, vector<string>> account_of_playerName_pieceName_;  // map that
                                                                 // holds the
                                                                 // name of the
                                                                 // player and a
                                                                 // vector
                                                                 // containging
                                                                 // the strings
                                                                 // of the types
                                                                 // that he/she
                                                                 // has

 public:
  int enemy_wizard_count(
      const string &name);  // amount of wizards the opposing player has
  int get_user_wizard_count(const string &name);  // amount of wizards you have
  GameState() = default;  // default constructor
  void addPlayer(GamePiece &player);  // adds a player to the map and the types
                                      // that they have
  void deletePlayer(
      GamePiece &player);  // removes a player and the types they have
  int NumPieces();                    // returns total pieces in play
  int NumPieces(const string &name);  // returns total pieces for a player
  int NumPieces(const string &name, const string &type);  // returns total
                                                          // pieces of a
                                                          // specific type for a
                                                          // specific person
};
