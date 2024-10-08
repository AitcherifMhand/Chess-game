#include "view.hpp"
#include "historique.hpp"
#include "mask.hpp"
#include "types.hpp"
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

// cette fonction initialise l'echiquier a vide
void Empty1(string board[][Colon]) {
  for (int i = 0; i < Colon; i++) {
    for (int j = 0; j < Colon; j++) {
      board[i][j] = "-";
    }
  }
}
// cette fonction definit la couleur du fond de la case selon le masque appliquer
void set_background(string t[][Colon], int i, int j, int M[][Colon]) {
  int m = M[i][j];
  if (m == 0) {//si la case de masque est 0,l'echiquier garde ces coleurs
    if ((i % 2 == 0 && j % 2 == 0) || (i % 2 != 0 && j % 2 != 0)) {
      cout << "\033[48;2;245;222;179m";

    } else {
      cout << "\033[48;2;139;69;19m";
    }
  } else if (m == 1) {//si une case est vide et la piece peut se deplacer elle sera de coleur d'oree
    cout << "\x1b[43m";
  } else if (m == -1) {//si une piece est selectionne 
    cout << "\x1b[42m";
  } else if (m == 2) {//si il y a prise la case sera bleu
    cout << "\x1b[44m";
  } else if (m == 3) {
    cout << "\x1b[45m";
  } else if (m == 4) {
    cout << "\x1b[46m";
  }
}
// cette fonction definit la couleur de la piece
void set_foreground(string board[][Colon], int i, int j) {
  if (isupper(board[i][j][0])) { //
    cout << "\x1b[30m";
  }
  if (board[i][j] == "p" || board[i][j] == "P") {
    cout << "\u2659"<< "  ";
  }
  if (board[i][j] == "R" || board[i][j] == "r") {
    cout << "\u2656"<< "  ";
  }
  if (board[i][j] == "B" || board[i][j] == "b") {
    cout << "\u2657"<< "  ";
  }
  if (board[i][j] == "N" || board[i][j] == "n") {
    cout << "\u2658"<< "  ";
  }
  if (board[i][j] == "q" || board[i][j] == "Q") {

    cout << "\u2655"<< "  ";
  }
  if (board[i][j] == "k" || board[i][j] == "K") {
    cout << "\u2654"<< "  ";
  }
  if (board[i][j] == "-") {
    cout << board[i][j] << "  ";
  }
}
// cette fonction affiche une case avec sa couleur de fond et la representation unicode de sa piece
void print_square_color(string board[][Colon], int i, int j, int M[][Colon]) {
  set_background(board, i, j, M);
  set_foreground(board, i, j);
}
// cette fonction permet d'afficher l'echiquier sur le terminal et en bas sa notation FEN
void print_board(string board[][Colon], int M[][Colon]) {
  for (int i = 97; i <= 104; i++) {
    cout << " " << char(i) << " ";
  }
  cout << endl;
  for (int i = 0; i < Colon; i++) {
    for (int j = 0; j < Colon; j++) {
      print_square_color(board, i, j, M);
    }
    cout << "\x1b[0m";
    cout << (i + 1) << endl;
  }
  for (int i = 97; i <= 104; i++) {
    cout << " " << char(i) << " ";
  }
  cout << endl;
  cout << "\x1b[0m";
}
