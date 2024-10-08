#ifndef VIEW_HPP_ 
#define VIEW_HPP_
#include <string>
#include"board.hpp"
#include "types.hpp"
void Empty1(string board[][Colon]);
void set_background(string board[][Colon], int i, int j, int M[][Colon]);
void set_foreground(string board[][Colon], int i, int j);
void print_board(string board[][Colon], int M[][Colon]);
void print_square_color(string board[][Colon], int i, int j, int M[][Colon]);
#endif
