#include "historique.hpp"
#include "board.hpp"
#include "mask.hpp"
#include "types.hpp"
#include "view.hpp"
#include <fstream>
#include <iostream>
#include <string>
using namespace std;
void MAJ_historique(string board[][Colon]) {
  ofstream MAJhistorique("Historique.txt", ios::app); // ouvre le fichier

  if (!MAJhistorique) {
    cout << "Error !." << endl;
    return;
  }

  MAJhistorique << FEN(board) << endl; // ajoute le nouvel Fen au fichier
  MAJhistorique.close();
}
// la fonction FEN permet de recupere la notation FEN de plateau
string FEN(string board[][Colon]) {
  string fen = ""; // Initialisation de la chaîne FEN
  int cp = 0;      // Compteur pour le nombre de cases vides
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      string Case = board[i][j]; // Récupération du contenu de la case
      if (Case == "-") {     // Si la case est vide, on incrémente le compteur
        cp++;
      } else {
        if (cp > 0) { // Si on a rencontré des cases vides précédemment, on
                      // ajoute leur nombre à la chaîne FEN
          fen += to_string(cp);
          cp = 0;
        }
        fen += Case; // On ajoute le contenu de la case à la chaîne FEN
      }
    }
    if (cp > 0) { // Si on a rencontré des cases vides à la fin de la ligne, on
                  // ajoute leur nombre à la chaîne FEN
      fen += to_string(cp);
      cp = 0;
    }
    if (i < 7) { // On ajoute un '/' entre chaque ligne de l'échiquier, sauf à
                 // la fin
      fen += '/';
    }
  }
  cout << fen; // Affichage de la chaîne FEN
  return fen;
}
// la fonction write_fen cree un fichier .txt auquel on ecrit la representation fen de l'echiquier
void write_FEN(string board[][Colon]) {
  ofstream MyFile("Historique.txt");

  MyFile << FEN(board);
  MyFile.close();
}
// la fonction read_fen lis un fichier .txt passe en parametre qui contient la  representation fen de l'echiquier
void read_FEN(string board[][Colon]) {
  string His;
  ifstream MyReadFile("Historique.txt");
  while (getline(MyReadFile, His)) {
    cout << His;
  }
  MyReadFile.close();
}