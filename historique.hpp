#ifndef BOARD_HPP_ 
#define BOARD_HPP_
#include "view.hpp"
#include "mask.hpp"
#include "types.hpp"
#include <iostream>
#include <string>
void MAJ_historique(string board[][Colon]);
string FEN(string board[][Colon]);
void write_FEN(string board[][Colon]);
void read_FEN(string board[][Colon]);
#endif