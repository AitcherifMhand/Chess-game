#ifndef TYPES_HPP_ 
#define TYPES_HPP_
#include <string>
using namespace std;
const int Colon=8;
const string turn="w";
enum col { a=0, b=1, c=2, d=3, e=4, f=5, g=6,h=7 };
enum color{ n=2,B=1};
struct prise{
string P;
prise* svt;
};
#endif