#include "ann.h"
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <string>
#include <sstream>

using namespace std;

ann::ann(){
  inputs = NULL;
  outputs = NULL;
  win = "weights.in";
  pin = "patterns.in";
  out = "outputs.out";
  numIn = 0;
  numOut = 0;
}

void ann::go(){
  loadWeights();
  testPatterns();
  writeOutput();
}

void ann::loadWeights(){
  weightFile.open(win.c_str());
  if (weightFile.fail()){
    cout << "Error opening " << win << "...";
    exit(1);
  }
  weightFile >> numIn;
  weightFile >> numOut;
  inputs = new inputNode[numIn];
  for (int i = 0; i < numIn; i++){
    inputs[i].constructWeights(numOut);
  }
  outputs = new outputNode[numOut];
  for (int i = 0; i < (numIn * numOut); i++){
    double temp;
    weightFile >> temp;
    inputs[i/numIn].setWeight((i%numOut), temp);
  }
  weightFile.close();
}

void ann::testPatterns(){
  patternFile.open(pin.c_str());
  if (patternFile.fail()){
    cout << "Error opening " << pin << "...";
    exit(2);
  }
  patternFile >> numPatterns;
  patternFile >> numValPerPat;
  patternFile >> maxPatVal;
  if (numPatterns != numIn){
    cout << "Pattern file incompatible with this network (Number of Patterns != Number of Inputs).";
    exit(3);
  }
  for (int j = 0; j < numPatterns; j++){
    for (int i = 0; i < (numValPerPat); i++){
      double temp;
      patternFile >> temp;
      inputs[i].setVal(temp/maxPatVal);
    }
    sigmoid(prepareForSigmoid());
    append();
  }
}

double* ann::prepareForSigmoid(){
  store = new double[numOut];
  double temp = 0;
  for (int i = 0; i < numOut; i++){
    for (int j = 0; j < numIn; j++){
      temp += (inputs[j].getWeight(i)*(inputs[j].getVal()));
    }
    store[i] = temp;
  }
  return store;
}

void ann::sigmoid(double* temp){
  for (int i = 0; i < numOut; i++){
    outputs[i].setVal(1/(1+exp(-temp[i])));
  }
}

void ann::append(){
  for (int i = 0; i < numOut; i++){
    if (i != 0){
      outputBuffer = outputBuffer + " ";
    }
    stringstream temp;
    temp << numOut;
    outputBuffer = outputBuffer + temp.str();
  }
  outputBuffer = outputBuffer + "\n";
}

void ann::writeOutput(){
  outFile.open(out.c_str());
  outFile << numPatterns << "\n";
  outFile << outputBuffer;
  outFile.close();
}
