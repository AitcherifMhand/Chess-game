#include "game.hpp"
#include "board.hpp"
#include "mask.hpp"
#include "types.hpp"
#include "historique.hpp"
#include "view.hpp"
#include <iostream>
#include <cctype>
#include <string>
using namespace std;
string choix_color() {
    string color;
    // Affiche les options de couleurs disponibles
    cout << " 1-blanc(B) \n 2-noir(n) \n: ";
    // Demande à l'utilisateur de saisir une couleur
    cin >> color;
    while (color != "B" && color != "n") { // Si la couleur saisie n'est pas valide, affiche un message d'erreur et redemande une saisie
        cout << "reessayez: ";
        cin >> color;
    }
    // Si la couleur saisie est valide, la fonction la renvoie
    return color;
}
bool test_run(int M[][Colon], int i, int j) {
  if (M[i][j] == 1 || M[i][j] == 2)// si la valeur est égale à 1 ou 2
    return true;// renvoyer true 
  if (M[i][j] == 0)// sinon, si la valeur est égale à 0
    return false;// renvoyer false
}
bool test_square(string board[][Colon], int i, int j, int M[][Colon]) {
  // Parcourt toutes les cases du carré de taille Colon à partir de la position (i, j)
    for (int lig = i; lig < i + Colon; lig++) {
        for (int col = j; col < j + Colon; col++) {
          // Vérifie si la case à la position (lig, col) est valide
            if (!test_run(M, lig, col))
                return false;// Si la case n'est pas valide, retourne false immédiatement
        }
    }
  // Si toutes les cases sont valides, retourne true
    return true;
}
void one_run(string board[][Colon], int M[][Colon], string color) {
  one_run_human(board, M,color);
  one_run_computer(board, M, color);
}
int convertToEnum(string col) {
 // On retourne un entier correspondant à la colonne
  if (col == "a")
    return 0;
  if (col == "b")
    return 1;
  if (col == "c")
    return 2;
  if (col == "d")
    return 3;
  if (col == "e")
    return 4;
  if (col == "f")
    return 5;
  if (col == "g")
    return 6;
  if (col == "h")
    return 7;
}
bool areSameCase(char c1, char c2) {
  // Si les deux caractères sont en majuscules ou en minuscules, ils sont du même type de case
    if (isupper((c1)) && isupper((c2)))
        return true;
    if (islower((c1)) && islower((c2)))
        return true;
  
    return false;
}

void choose_mouvement_human(string board[][Colon], int M[][Colon],string color) {
  clear_mask(M);
  int ligA, ligD, ncolA, ncolD;// déclaration de quatre variables entières
  string colA, colD;
  
  while(ligD<1 || ligD>8 || ncolD>7|| ncolD<0){
     cout << "choisissez votre pieces(ligne,colone)";
  cout << "ligne (1->>8): ";
  cin >> ligD;
  cout << "colonne(a->>h): ";
  cin >> colD;
  ncolD = convertToEnum(colD);
  }
  while (board[ligD - 1][ncolD] == "-") {// tant que la case choisie ne contient pas de pièce
    cout << "choisissez une case avec une piece!!";
    cin >> ligD;
    cin >> colD;
    ncolD = convertToEnum(colD);
  }
  highlight_possible_moves(M, ligD - 1, ncolD, board,color);
while(!test_square(board,ligD-1,ncolD,M) && !areSameCase(board[ligD-1][ncolD][0], color[0]) ) {
    cout << "choisissez une autre case!!";
    cin >> ligD;
    cin >> colD;
    ncolD = convertToEnum(colD);
  highlight_possible_moves(M, ligD - 1, ncolD, board,color);// Met en évidence les mouvements possibles pour la pièce sélectionnée
  }
  print_board(board, M);// Affiche le plateau de jeu mis à jour avec les mouvements possibles
  cout<<"case d'arrivee(ligne):";
  cin >> ligA;
  cout<<"case d'arrivee(col):";
  cin >> colA;
  ncolA = convertToEnum(colA);
  while (test_run(M, ligA - 1, ncolA) == false) {// Tant que le mouvement choisi n'est pas possible
    cout << "mouvement impossible reessayez!!";
    cin >> ligA;
    cin >> colA;
    ncolA = convertToEnum(colA);
  }
  move_piece(board, ligD - 1, ncolD, ligA - 1, ncolA);// Déplace la pièce sélectionnée vers la nouvelle case choisie
}
void one_run_human(string board[][Colon], int M[][Colon],string color) {
  choose_mouvement_human(board, M,color);// Appelle la fonction pour permettre à l'utilisateur de choisir une pièce et son déplacement
  clear_mask(M);// Efface les masques de mouvement pour la prochaine pièce sélectionnée
  print_board(board, M);// Affiche le plateau de jeu mis à jour
}
void one_run_computer(string board[][Colon], int M[][Colon], string color) {
  choose_mouvement_computer(board, M, color);// Appelle la fonction pour permettre à l'utilisateur de choisir une pièce et son déplacement
  print_board(board, M);// Affiche le plateau de jeu mis à jour
    clear_mask(M);// Efface les masques de mouvement pour la prochaine pièce sélectionnée

}
void choose_mouvement_computer(string board[][Colon], int M[][Colon], string color) {
   // Déclaration et initialisation de variables
    int valid_moves[280][2];// Tableau pour stocker les mouvements valides
    int num_valid_moves = 0;// Nombre total de mouvements valides
    // Boucle pour parcourir toutes les cases du plateau de jeu
    for (int ligD = 0; ligD < 8; ligD++) {
        for (int colD = 0; colD < 8; colD++) {
          // Vérification si la case contient une pièce de la couleur choisie
            if (areSameCase(board[ligD][colD][0],color[0] )) {
              // Mise en évidence des mouvements possibles pour cette pièce
                highlight_possible_moves(M, ligD, colD, board,color);
               // Boucle pour parcourir toutes les cases du plateau de jeu
                for (int ligA = 0; ligA < 8; ligA++) {
                    for (int colA = 0; colA < 8; colA++) {// Vérification si le mouvement est valide
                        if (test_run(M, ligA, colA)) {
                          // Ajout du mouvement à la liste des mouvements valides
                            valid_moves[num_valid_moves][0] = ligD;
                            valid_moves[num_valid_moves][1] = colD;
                            num_valid_moves++;
                            valid_moves[num_valid_moves][0] = ligA;
                            valid_moves[num_valid_moves][1] = colA;
                            num_valid_moves++;
                        }
                    }
                }
            }
        }
    }
  // Vérification si des mouvements valides ont été trouvés
    if (num_valid_moves > 0) {// Sélection d'un mouvement aléatoire parmi les mouvements valides
        int rand_index = rand() % (num_valid_moves / 2);
        int ligD = valid_moves[rand_index * 2][0];
        int colD = valid_moves[rand_index * 2][1];
        int ligA = valid_moves[rand_index * 2 + 1][0];
        int colA = valid_moves[rand_index * 2 + 1][1];
      // Déplacement de la pièce sélectionnée
        move_piece(board, ligD, colD, ligA, colA);
    }
    
}
void joue_human(string board[][Colon], int M[][Colon], bool check) {
  int coups=0;
  cout<<"Choisissez la couleur de vos pièces";
  string color1=choix_color(); 
  cout<<"Choisissez la couleur des pièces adverses";
  string color2=choix_color(); 
  print_board(board, M);
    // La boucle while s'exécute tant que la variable booléenne 'check' est vraie et le nombre de coups ne dépasse pas 50 coups
  while (check == true && coups<=50) {
    clear_mask(M);
    cout << "***joueur 1***" << endl;
    one_run_human(board, M,color1);
    cout << "***joueur 2***" << endl;
    one_run_human(board, M,color2);
    coups++;
  }
}
void jouer_Ordi(string board[][Colon], int M[][Colon], bool check) {// Initialisation des variables
  int coups = 0;
  cout << "Choisissez la couleur de vos pièces";
  string color1 = choix_color();
  cout << "Choisissez la couleur des pièces adverses";
  string color2 = choix_color();
   // Efface le masque de cases disponibles et affiche le plateau
  clear_mask(M);
  print_board(board, M);
  // Boucle tant qu'il y a échec et que le nombre de coups est inférieur ou égal à 50
  while (check && coups <= 50) {
    clear_mask(M);// Efface le masque de cases disponibles
    cout << "*** Joueur 1 ***" << endl;// Tour du joueur 1 (humain)
    one_run_human(board, M, color1);
    coups++;
    cout << "*** Joueur 2 (Ordinateur) ***" << endl;// Tour du joueur 2 (ordinateur)
    one_run_computer(board, M, color2);
    coups++;
  }
}
