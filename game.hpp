#ifndef GAME_HPP_ 
#define GAME_HPP_
#include <string>
#include<iostream>
#include <cctype>
#include"types.hpp"
#include"board.hpp"
#include "view.hpp"
#include "historique.hpp"
string choix_color();
bool areSameCase(char c1, char c2);
bool test_square(string board[][Colon],int i,int j,int M[][Colon]);
int convertToEnum(string col);
void one_run(string board[][Colon],int M[][Colon],string turn);
void one_run_human(string board[][Colon],int M[][Colon],string color);
void one_run_computer(string board[][Colon],int M[][Colon],string color);
bool test_run(int M[][Colon],int i,int j);
void choose_mouvement_human(string board[][Colon],int M[][Colon],string color);
void choose_mouvement_computer(string board[][Colon],int M[][Colon],string color);
void joue_human(string board[][Colon],int M[][Colon],bool check);
void jouer_Ordi(string board[][Colon],int M[][Colon],bool check);
#endif