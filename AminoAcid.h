/*author: Zeke Elkins and Shannon White
/date: 2/18/14
/description: amino acid class
*/

#ifndef _AminoAcid_ 
#define _AminoAcid_

#include <iostream>
#include <string>
using namespace std;

class AminoAcid {

 private:
  string aminoName;
  double propensity;

 public:
  AminoAcid(string); //constructor
  void setAminoName(string);
  string getAminoName();
  double getPropensity();

};

#endif
