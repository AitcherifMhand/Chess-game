#ifndef MASK_HPP_ 
#define MASK_HPP_
#include <string>
#include<iostream>
#include <cctype>
#include"types.hpp"
#include"board.hpp"
#include"game.hpp"
#include "view.hpp"
int get_mask(int M[][Colon],int ind1,int ind2);
void highlight_possible_moves_rook(int M[][Colon],int ind1,int ind2,string S[][Colon]);
bool highlight_possible_moves(int M[][Colon],int ind1,int ind2,string S[][Colon],string color);
void clear_mask(int M[][Colon]);
void highlight_possible_moves_king(int M[][Colon],int ind1,int ind2,string S[][Colon],string color);
void highlight_possible_moves_knight(int M[][Colon], int ind1, int ind2,string S[][Colon]);
void  highlight_possible_moves_queent(int M[][Colon],int ind1,int ind2,string S[][Colon]);
void  highlight_possible_moves_bishop(int M[][Colon],int ind1,int ind2,string S[][Colon]);
void highlight_possible_moves_pawn(int M[][Colon], int ind1, int ind2,
                                   string S[][Colon]);
void highlight_movable_pieces(int M[][Colon], string S[][Colon],string color);
bool movable_piece(int i, int j, string S[][Colon],int M[][Colon]);
void highlight_attacked_pieces(int M[][Colon],string S[][Colon],string color);
bool test_king_check(string board[][Colon], int lig,int col,string color);
#endif