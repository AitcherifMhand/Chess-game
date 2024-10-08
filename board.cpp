#include "board.hpp"
#include "view.hpp"
#include <iostream>
#include <string>
using namespace std;

// les fonctions get square recupere le contenu des cases en les sauvegardant
// dans cases memoires temporaires

string get_square1(string board[][Colon], int lig, int col) {
  string tmp;
  tmp = board[lig][col];
  return tmp;
}

// les fonctions set square permettent de changer le contenu de la case dans les
// differents possibilites
void set_square1(string board[][Colon], int ligD, int colD, int ligA,int colA) {
  if (board[ligA][colA] == " ") { // si la case est vide
    string tmp;
    tmp = get_square1(board, ligD, colD);
    board[ligA][colA] = tmp;
    board[ligD][colD] = "-";
  }
  if (board[ligA][colA] != " ") { // si la case n'est pas vide(prise de piece)
    string tmp1, tmp2;
    tmp1 = get_square1(board, ligA, colA);
    tmp2 = get_square1(board, ligD, colD);
    board[ligA][colA] = tmp2;
    board[ligD][colD] = "-";
  }
}
// la fonction move piece est une fonction qui recupere une piece puis changerle contenu de la case selectionne
void move_piece(string board[][Colon], int ligD, int colD, int ligA, int colA) {
  get_square1(board, ligD, colD);
  get_square1(board, ligA, colA);
  set_square1(board, ligD, colD, ligA, colA);
}

void start1(string board[][Colon]) {
  Empty1(board);
  // Initialise les pièces noires
  board[0][0] = "r";
  board[0][1] = "n";
  board[0][2] = "b";
  board[0][3] = "q";
  board[0][4] = "k";
  board[0][5] = "b";
  board[0][6] = "n";
  board[0][7] = "r";
  board[1][0] = "p";
  board[1][1] = "p";
  board[1][2] = "p";
  board[1][3] = "p";
  board[1][4] = "p";
  board[1][5] = "p";
  board[1][6] = "p";
  board[1][7] = "p";

  // Initialise les cases vides
  for (int i = 2; i < 6; i++) {
    for (int j = 0; j < Colon; j++) {
      board[i][j] = "-";
    }
  }

  // Initialise les pièces blanches
  board[7][0] = "R";
  board[7][1] = "N";
  board[7][2] = "B";
  board[7][3] = "Q";
  board[7][4] = "K";
  board[7][5] = "B";
  board[7][6] = "N";
  board[7][7] = "R";
  board[6][0] = "P";
  board[6][1] = "P";
  board[6][2] = "P";
  board[6][3] = "P";
  board[6][4] = "P";
  board[6][5] = "P";
  board[6][6] = "P";
  board[6][7] = "P";
}