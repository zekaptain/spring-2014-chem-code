/*author: Zeke Elkins, Shannon White
/date: 2/18/14
/description: driver 
*/

#include "AminoAcid.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <math.h> //exp propensity equation
#include <string>
#include <climits>

using namespace std;


int main(int argc, const char * argv[]) {

  //read in the amino file
  ifstream infile;
  infile.open("aminoChain.txt", ifstream::in);

  vector<AminoAcid*> name;
  string line;

  //use file for amino chain
  while (infile >> line) {
    name.push_back(new AminoAcid(line));
  }

  //close file
  infile.close();

  //ask user for cin temp
  double temp;
  cout << "What is the temperature?" << endl;
  cin >> temp;

  //sum up propensities
  double total = 0;
  for (double i=0; i < name.size(); i++) {
    total = total + name.at(i)-> getPropensity();
  }

  //minimum propensity (most helical) 
  double sum = 0;
  double minSum = 1E300;
  double minJ = 1E300;
  double minI = 1E300;
  string nameJ;
  string nameI;
  double a;
  double firstAmino;
  double lastAmino;
  double minFirstAmino = 1E300;
  double minLastAmino = 1E300;


  for (double j=4; j<6; j++) {
    for (double i=0; i<name.size()-j; i++) {
      sum = 0;
      for (a=0; a<j; a++) {
	sum = sum + name.at(i+a)->getPropensity();
	firstAmino = i;
	lastAmino = i+a;
      }
      if (sum < -(0.0019872041 * temp * log(0.05))) {
	minSum = sum;
	minFirstAmino = firstAmino;
	minLastAmino = lastAmino;
	minJ = name.at(i)->getPropensity();
	minI = name.at(i+a)->getPropensity();
	nameJ = name.at(i)->getAminoName();
	nameI = name.at(i+a)->getAminoName();

        cout << "Propensity: " << minSum << endl;
        cout << "Aminos  " << minFirstAmino << " through  " << minLastAmino << endl;
        cout << "First amino: "  << endl << " " << nameJ << ": " << minJ <<  endl; 
        cout << "Last amino: " << endl << " " << nameI << ": " << minI << endl;
      }
      /*
      if (sum < -(0.0019872041 * temp * log(0.05))) {
	minSum = sum;
      }
      */
    }
  }


  // cout << "Propensity: " << minSum << endl;
  //cout << "Aminos  " << minFirstAmino << " through  " << minLastAmino << endl;
  //cout << "First amino: "  << endl << " " << nameJ << ": " << minJ <<  endl; 
  //cout << "Last amino: " << endl << " " << nameI << ": " << minI << endl;

  //calulate the % propensity using equation

  double finalResult;
  finalResult = exp (-(total)/(0.0019872041 * temp));

  //output answer
  cout << finalResult;
  cout << endl;


}
