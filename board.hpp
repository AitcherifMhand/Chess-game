#ifndef BOARD_HPP_ 
#define BOARD_HPP_
#include <string>
#include "types.hpp"
using namespace std;
void move_piece(string board[][Colon], int ligD, int colD, int ligA, int colA);
void set_square1(string board[][Colon], int ligD, int colD, int ligA,int colA);
string get_square1(string board[][Colon], int lig, int col);
void start1(string board[][Colon]);
#endif