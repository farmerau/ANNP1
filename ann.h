#include "nodes.h"
#include <string>
#include <fstream>
#include <iostream>

using namespace std;

class ann{

public:
  ann();
  void go();

private:
  //So that we know which files we're using for I/O.
  string win;
  string pin;
  string out;
  //END FILE NAMES
  int numIn; //Number of input nodes
  int numOut; //Number of output nodes.

  int numPatterns; //Number of Patterns we're going to run.
  int numValPerPat; //Number of Values per Pattern (Should = numIn)
  int maxPatVal; //Maximum possible value for pattern val.

  inputNode* inputs;
  outputNode* outputs;

  ifstream patternFile;
  ifstream weightFile;
  ofstream outFile;

  string outputBuffer;

  double* store = NULL;
  void loadWeights();
  void testPatterns();
  double* prepareForSigmoid();
  void sigmoid(double* );
  void append();
  void writeOutput();
};
