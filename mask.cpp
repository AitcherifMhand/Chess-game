#include "mask.hpp"
#include "game.hpp"
#include "types.hpp"
#include <cctype>
#include <iostream>
#include <string>
// cette fonction initialise le masque a 0
void clear_mask(int M[][Colon]) {
  for (int i = 0; i < Colon; i++) {
    for (int j = 0; j < Colon; j++) {
      M[i][j] = 0;
    }
  }
}
bool test_king_check(string board[][Colon], int lig,int col,string color) {
  for(int i=lig-1;i>=0;i--){
    if(board[i][col]!="-" && !areSameCase(board[i][col][0],color[0])){
      return false;
    }
  }for(int i=lig+1;i<8u;i++){
    if(board[i][col]!="-" && !areSameCase(board[i][col][0],color[0])){
      return false;
    }
  }
  for(int i=col-1;i>=0;i--){
    if(board[lig][i]!="-" && !areSameCase(board[i][col][0],color[0])){
      return false;
    }
  }for(int i=col+1;i<8u;i++){
    if(board[lig][i]!="-" && !areSameCase(board[i][col][0],color[0])){
      return false;
    }
  }
  for (int i = lig + 1, j = col + 1; i < 8 && j < 8; i++, j++) {
    if (board[lig][col] != "-" &&!areSameCase(board[i][col][0],color[0])) {
      return false;
    }
  }
for (int i = lig + 1, j = col - 1; i < 8 && j < 8; i++, j++) {
    if (board[lig][col] != "-" && !areSameCase(board[i][col][0],color[0])) {
      return false;
    }
}for (int i = lig - 1, j = col + 1; i < 8 && j < 8; i++, j++) {
    if (board[lig][col] != "-" && !areSameCase(board[i][col][0],color[0])) {
      return false;
    }
    }for (int i = lig - 1, j = col - 1; i < 8 && j < 8; i++, j++) {
    if (board[lig][col] != "-" &&!areSameCase(board[i][col][0],color[0])) {
      return false;
    }
    }
  return true;
}

// cette fonction permet de recuperer la valeur d'une case d'un masque en precisant les cases ou elle peut avancer et les pieces qu'elle peut prender
int get_mask(int M[][Colon], int ind1, int ind2) { return M[ind1][ind2]; }

void highlight_possible_moves_pawn(int M[][Colon], int ind1, int ind2,
                                   string S[][Colon]) {
    // On initialise le masque à zéro avant de commencer le calcul
  clear_mask(M);
    // On récupère le type de la pièce située à la position (ind1, ind2)
  string P = S[ind1][ind2];
// Si le pion est noir.
  if (P == "p") {
    if (ind1 == 1) {      // Si le pion est à sa position de départ, il peut avancer de 2 cases
      if (S[ind1 + 1][ind2] == "-")
        M[ind1 + 1][ind2] += 1;
      M[ind1 + 2][ind2] += 1;
            // Le pion peut prendre une pièce adverse en diagonale.
      if (isupper(S[ind1 + 1][ind2 + 1][0]))
        M[ind1 + 1][ind2 + 1] += 2;
      if (isupper(S[ind1 + 1][ind2 - 1][0]))
        M[ind1 + 1][ind2 - 1] += 2;
    } else {// Sinon, le pion ne peut avancer que d'une case.
      if (S[ind1 + 1][ind2] == "-")
        M[ind1 + 1][ind2] += 1;
            // Le pion peut prendre une pièce adverse en diagonale
      if (isupper(S[ind1 + 1][ind2 + 1][0]))
        M[ind1 + 1][ind2 + 1] += 2;
      if (isupper(S[ind1 + 1][ind2 - 1][0]))
        M[ind1 + 1][ind2 - 1] += 2;
    }
  }
  // Si le pion est blanc.
  if (P == "P") {
    if (ind1 == 6) {
       // Si le pion est à sa position de départ, il peut avancer de 2 cases.
      if (S[ind1 - 1][ind2] == "-")
        M[ind1 - 1][ind2] += 1;
      M[ind1 - 2][ind2] += 1;
       // Le pion peut prendre une pièce adverse en diagonale.
      if (islower(S[ind1 - 1][ind2 + 1][0]))
        M[ind1 - 1][ind2 + 1] += 2;
      if (islower(S[ind1 - 1][ind2 - 1][0]))
        M[ind1 - 1][ind2 - 1] += 2;
    } else {
      // Sinon, le pion ne peut avancer que d'une case.
      if (S[ind1 - 1][ind2] == "-")
        M[ind1 - 1][ind2] += 1;
      // Le pion peut prendre une pièce adverse en diagonale.
      if (islower(S[ind1 - 1][ind2 + 1][0]))
        M[ind1 - 1][ind2 + 1] += 2;
      if (islower(S[ind1 - 1][ind2 - 1][0]))
        M[ind1 - 1][ind2 - 1] += 2;
    }
  }
}
// cette fonction creer le masque des mouvemnts de la tour
void highlight_possible_moves_rook(int M[][Colon], int ind1, int ind2,
                                   string S[][Colon]) {
  clear_mask(M);// efface le masque M
  string P = S[ind1][ind2];// récupère la pièce en position ind1, ind2
  // boucle pour vérifier les positions verticales ascendantes
  for (int i = ind1 - 1; i >= 0; i--) {
    if (S[i][ind2] == "-") {// si la case est vide
      M[i][ind2] = 1;
    } else if (islower(S[i][ind2][0]) && P == "R") {// si la pièce est adverse et qu'on est une tour blanche
      M[i][ind2] = 2;
      break;
    } else if (isupper(S[i][ind2][0]) && P == "r") {// si la pièce est adverse et qu'on est une tour noire
      M[i][ind2] = 2;
      break;
    } else {// si la case est occupée par une pièce alliée ou qu'on est hors du plateau
      break;
    }
  }
  // boucle pour vérifier les positions verticales descendantes
  for (int i = ind1 + 1; i < Colon; i++) {
    if (S[i][ind2] == "-") { // si la case est vide
      M[i][ind2] = 1;
    } else if (islower(S[i][ind2][0]) && P == "R") {// si la pièce est adverse et qu'on est une tour blanche
      M[i][ind2] = 2;
      break;
    } else if (isupper(S[i][ind2][0]) && P == "r") {// si la pièce est adverse et qu'on est une tour noire
      M[i][ind2] = 2;
      break;
    } else {// si la case est occupée par une pièce alliée ou qu'on est hors du plateau
      break;
    }
  }
  // boucle pour vérifier les positions horizontales ascendantes
  for (int j = ind2 - 1; j >= 0; j--) {
    if (S[ind1][j] == "-") { // si la case est vide
      M[ind1][j] = 1;
    } else if (islower(S[ind1][j][0]) && P == "R") {// si la pièce est adverse et qu'on est une tour blanche
      M[ind1][j] = 2;
      break;
    } else if (isupper(S[ind1][j][0]) && P == "r") {// si la pièce est adverse et qu'on est une tour noire
      M[ind1][j] = 2;
      break;
    } else {
      break;
    }
  }
  for (int j = ind2 + 1; j < Colon; j++) {
    if (S[ind1][j] == "-") {
      M[ind1][j] = 1;
    } else if (islower(S[ind1][j][0]) && P == "R") {
      M[ind1][j] = 2;
      break;
    } else if (isupper(S[ind1][j][0]) && P == "r") {
      M[ind1][j] = 2;
      break;
    } else {
      break;
    }
  }
  M[ind1][ind2] = -1;
}

// cette fonction creer le masque des mouvemnts de roi en precisant ou il peut avancer et les pieces qu il peut prendre

void highlight_possible_moves_king(int M[][8], int ind1, int ind2,
                                   string S[][8],string color) {
  clear_mask(M);// Efface les anciennes positions marquées sur la matrice M
  string P = S[ind1][ind2];// Récupère le type de pièce (majuscule ou minuscule)
  int i, j;
// Parcourt les cases voisines de la pièce
  for (i = ind1 - 1; i <= ind1 + 1; i++) {
    for (j = ind2 - 1; j <= ind2 + 1; j++) {
      // Vérifie que la case voisine est bien sur le plateau de jeu
      if (i >= 0 && i < 8 && j >= 0 && j < 8) {        // Si la case voisine est vide, marque la case avec un 1
        if (S[i][j] == "-" && test_king_check(S, i, j, color) ) {
          M[i][j] += 1;
        } else// Si la case voisine contient une pièce ennemie, marque la case avec un 2
          if (islower(P[0]) && isupper(S[i][j][0] &&  test_king_check(S, i, j, color))) {
          M[i][j] += 2;
        } else if (isupper(P[0]) && islower(S[i][j][0])&&  test_king_check(S, i, j, color)) {
          M[i][j] += 2;
        }
      }
    }
  }

  M[ind1][ind2] = -1;// Marque la case de la pièce avec un -1 pour ne pas la considérer dans les prochains mouvements possibles
}
// cette fonction creer le masque des mouvemnts de la reine en precisant ou elle peut avancer et les pieces qu elle peut prendre
void highlight_possible_moves_queen(int M[][Colon], int ind1, int ind2,
                                    string S[][Colon]) {
  clear_mask(M);// Effacer la matrice de masquage
  string P = S[ind1][ind2];// Stocker la pièce sélectionnée dans la variable P
  // Vérifier les mouvements en haut
  for (int i = ind1 - 1; i >= 0; i--) {
    if (S[i][ind2] == "-") {
      M[i][ind2] = 1;
    } else if (islower(S[i][ind2][0]) && P == "Q") {
      M[i][ind2] = 2;
      break;
    } else if (isupper(S[i][ind2][0]) && P == "q") {
      M[i][ind2] = 2;
      break;
    } else {
      break;
    }
  }
  // Vérifier les mouvements en bas
  for (int i = ind1 + 1; i < Colon; i++) {
    if (S[i][ind2] == "-") {
      M[i][ind2] = 1;
    } else if (islower(S[i][ind2][0]) && P == "Q") {
      M[i][ind2] = 2;
      break;
    } else if (isupper(S[i][ind2][0]) && P == "q") {
      M[i][ind2] = 2;
      break;
    } else {
      break;
    }
  }
  // Vérifier les mouvements à gauche
  for (int j = ind2 - 1; j >= 0; j--) {
    if (S[ind1][j] == "-") {
      M[ind1][j] = 1;
    } else if (islower(S[ind1][j][0]) && P == "Q") {
      M[ind1][j] = 2;
      break;
    } else if (isupper(S[ind1][j][0]) && P == "q") {
      M[ind1][j] = 2;
      break;
    } else {
      break;
    }
  }
  // Vérifier les mouvements à droite
  for (int j = ind2 + 1; j < Colon; j++) {
    if (S[ind1][j] == "-") {
      M[ind1][j] = 1;
    } else if (islower(S[ind1][j][0]) && P == "Q") {
      M[ind1][j] = 2;
      break;
    } else if (isupper(S[ind1][j][0]) && P == "q") {
      M[ind1][j] = 2;
      break;
    } else {
      break;
    }
  }
  // Cette boucle parcourt les diagonales 
  for (int i = ind1 + 1, j = ind2 + 1; i < 8 && j < 8; i++, j++) {
    if (S[i][j] == "-") {
      M[i][j] += 1;
    } else if (isupper(P[0]) != isupper(S[i][j][0])) {
      M[i][j] += 2;
      break;
    } else {
      break;
    }
  }
  // Cette boucle parcourt les diagonales en haut à gauche de la position actuelle de la pièce,
  for (int i = ind1 - 1, j = ind2 - 1; i >= 0 && j >= 0; i--, j--) {
    if (S[i][j] == "-") {
      M[i][j] += 1;
    } else if (isupper(P[0]) != isupper(S[i][j][0])) {
      M[i][j] += 2;
      break;
    } else {
      break;
    }
  }
  // Cette boucle parcourt les diagonales en haut à droite de la position actuelle de la pièce,
  for (int i = ind1 - 1, j = ind2 + 1; i >= 0 && j < 8; i--, j++) {
    if (S[i][j] == "-") {
      M[i][j] += 1;
    } else if (isupper(P[0]) != isupper(S[i][j][0])) {
      M[i][j] += 2;
      break;
    } else {
      break;
    }
  }
  // Cette boucle parcourt les diagonales en bas à gauche de la position actuelle de la pièce,
  for (int i = ind1 + 1, j = ind2 - 1; i < 8 && j >= 0; i++, j--) {
    if (S[i][j] == "-") {
      M[i][j] += 1;
    } else if (isupper(P[0]) != isupper(S[i][j][0])) {
      M[i][j] += 2;
      break;
    } else {
      break;
    }
  }
// Cette ligne marque la position actuelle de la pièce comme occupée pour éviter qu'elle ne soit considérée comme une case vide.
  M[ind1][ind2] = -1;
}
// cette fonction creer le masque des mouvemnts du fou en precisant ou il peut avancer et les pieces qu il peut prendre
void highlight_possible_moves_bishop(int M[][Colon], int ind1, int ind2,
                                     string S[][Colon]) {
  clear_mask(M);
  string P = S[ind1][ind2];
    // Boucle pour les mouvements diagonaux supérieurs droits
  for (int i = ind1 + 1, j = ind2 + 1; i < 8 && j < 8; i++, j++) {
    if (S[i][j] == "-") {
      M[i][j] += 1;
    } else if (isupper(P[0]) != isupper(S[i][j][0])) {
      M[i][j] += 2;
      break;
    } else {
      break;
    }
  }
   // Boucle pour les mouvements diagonaux inférieurs gauches
  for (int i = ind1 - 1, j = ind2 - 1; i >= 0 && j >= 0; i--, j--) {
    if (S[i][j] == "-") {
      M[i][j] += 1;
    } else if (isupper(P[0]) != isupper(S[i][j][0])) {
      M[i][j] += 2;
      break;
    } else {
      break;
    }
  }
   // Boucle pour les mouvements diagonaux supérieurs gauches
  for (int i = ind1 - 1, j = ind2 + 1; i >= 0 && j < 8; i--, j++) {
    if (S[i][j] == "-") {
      M[i][j] += 1;
    } else if (isupper(P[0]) != isupper(S[i][j][0])) {
      M[i][j] += 2;
      break;
    } else {
      break;
    }
  }
  // Boucle pour les mouvements diagonaux inférieurs droits
  for (int i = ind1 + 1, j = ind2 - 1; i < 8 && j >= 0; i++, j--) {
    if (S[i][j] == "-") {
      M[i][j] += 1;
    } else if (isupper(P[0]) != isupper(S[i][j][0])) {
      M[i][j] += 2;
      break;
    } else {
      break;
    }
  }

  M[ind1][ind2] = -1;
}
// Cette fonction met en évidence les mouvements possibles pour un cavalier à partir de la position donnée.
void highlight_possible_moves_knight(int M[][Colon], int ind1, int ind2,
                                     string S[][Colon]) {
  clear_mask(M);// Efface le masque existant
  string P = S[ind1][ind2];// Récupère la pièce à la position donnée
  int i, j;
  // Parcourt toutes les cases autour de la position donnée
  for (i = ind1 - 2; i <= ind1 + 2; i++) {
    for (j = ind2 - 2; j <= ind2 + 2; j++) {// Vérifie si la case se trouve à l'intérieur de l'échiquier
      if (i >= 0 && i < 8 && j >= 0 && j < 8) { // Vérifie si la case correspond à un mouvement valide du cavalier (en L)
        if ((abs(i - ind1) == 1 && abs(j - ind2) == 2) ||
            (abs(i - ind1) == 2 && abs(j - ind2) == 1)) {
          // Vérifie si la case est vide
          if (S[i][j] == "-") {
            M[i][j] = 1;// Marque la case comme déplacement possible
          } 
            // Vérifie si la case contient une pièce ennemie (cavalier de couleur opposée)
          else if (islower(P[0]) && isupper(S[i][j][0])) {
            M[i][j] = 2;
          } 
            // Vérifie si la case contient une pièce ennemie (cavalier de couleur opposée)
          else if (isupper(P[0]) && islower(S[i][j][0])) {
            M[i][j] = 2;
          }
        }
      }
    }
  }
  M[ind1][ind2] = -1;// Marque la position actuelle du cavalier comme occupée pour éviter qu'elle ne soit considérée comme une case vide.
}
// donne le masque  de la piece rentrer en  parametre
bool highlight_possible_moves(int M[][Colon], int ind1, int ind2,
                              string S[][Colon],string color) {
  string P = S[ind1][ind2];
  if (P == "R" || P == "r") {
    highlight_possible_moves_rook(M, ind1, ind2, S);
    return true;
  }

  if (P == "K" || P == "k") {
    highlight_possible_moves_king(M, ind1, ind2, S,color);
    return true;
  }
  if (P == "Q" || P == "q") {
    highlight_possible_moves_queen(M, ind1, ind2, S);
    return true;
  }
  if (P == "B" || P == "b") {
    highlight_possible_moves_bishop(M, ind1, ind2, S);
    return true;
  }
  if (P == "N" || P == "n") {
    highlight_possible_moves_knight(M, ind1, ind2, S);
    return true;
  }
  if (P == "P" || P == "p") {
    highlight_possible_moves_pawn(M, ind1, ind2, S);
    return true;
  }
  return false;
}
bool movable_piece(int i, int j, string S[][Colon], int M[][Colon]) {
  for (int lig = 0; lig < Colon; lig++) {
    for (int col = 0; col < Colon; col++) {
      if (M[lig][col] != -1 && M[lig][col] != 0) {
        movable_piece(i, j, S, M);
        return true;
      }
    }
  }
  return false;
}

void highlight_movable_pieces(int M[][Colon], string S[][Colon],string color) {
       clear_mask(M);
    for(int i=0;i<8;i++){
      for(int j=0;j<8;j++){
        if(S[i][j]!="-" && areSameCase(S[i][j][0],color[0])){
          if(test_square(S,i,j,M)){
            M[i][j]=4;
          }
        }
      }
    }
}


void highlight_attacked_pieces(int M[][Colon], string S[][Colon],string color) {
    clear_mask(M);
    for(int i=0;i<8;i++){
      for(int j=0;j<8;j++){
        if(S[i][j]!="-" && areSameCase(S[i][j][0],color[0])){
          if(!test_king_check(S,i,j,color)){
            M[i][j]=3;
          }
        }
      }
    }
}