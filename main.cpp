#include "board.hpp"
#include "game.hpp"
#include "mask.hpp"
#include "types.hpp"
#include "view.hpp"
#include <fstream>
#include <iostream>
#include <string>
int main() {
  string chessBoard[Colon][Colon];
  int M[Colon][Colon];
  bool check = true;
  int colD, ligD, colA, ligA;
  clear_mask(M);
  start1(chessBoard);
  int menu;
  cout << "1-voulez vous jouer avec un human?\n";
  cout << "2-voulez vous jouer contre L'ordinateur?\n";
  cin >> menu;
  switch (menu) {
  case 1:
    joue_human(chessBoard, M, check);
    break;
  case 2:
    jouer_Ordi(chessBoard, M, check);
    break;
  }

  return 0;
}
