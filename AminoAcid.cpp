/*author: Zeke Elkins and Shannon White
/date: 2/18/14
/description: aminoacid .cpp
*/

#include "AminoAcid.h"
#include <string>
#include <iostream>

AminoAcid::AminoAcid(string name) {
  aminoName = name;

  
  if (aminoName == "ALA") {
    propensity = 0.0;
  }
  if (aminoName == "ARG"){
    propensity = 0.21;
  }
  if (aminoName == "ASN") {
    propensity = 0.65;
  }
  if (aminoName == "ASP") {
    propensity = 0.69;
  }
  if (aminoName == "CYS") {
    propensity = 0.68;
  }
  if (aminoName == "GLU") {
    propensity = 0.40;
  }
  if (aminoName == "GLN") {
    propensity = 0.39;
  }
  if (aminoName == "GLY") {
    propensity = 1;
  }
  if (aminoName == "HIS") {
    propensity = 0.61;
  }
  if (aminoName == "ILE") {
    propensity = 0.41;
  }
  if (aminoName == "LEU") {
    propensity = 0.21;
  }
  if (aminoName == "LYS") {
    propensity = 0.26;
  }
  if (aminoName == "MET") {
    propensity = 0.24;
  }
  if (aminoName == "PHE") {
    propensity = 0.45;
  }
  if (aminoName == "PRO") {
    propensity = 3.16;
  }
  if (aminoName == "SER") {
    propensity = 0.5;
  }
  if (aminoName == "THR") {
    propensity = 0.66;
  }
  if (aminoName == "TRP") { 
    propensity = 0.49;
  }
  if (aminoName == "TYR") {
    propensity = 0.53;
  }
  if (aminoName == "VAL") { 
    propensity = 0.61;
  }
}

void AminoAcid::setAminoName(string n) {
  aminoName = n;
}

string AminoAcid::getAminoName() {
  return aminoName;
}

double AminoAcid::getPropensity(){
  return propensity;
}
