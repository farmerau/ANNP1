#include <iostream>
#include <cstdlib>
#include <fstream>

using namespace std;

class inputNode{
public:
  inputNode(); //Default constructor
  //Getters and Setters
  void setWeight (int index, double value);
  double getWeight (int index);
  void setVal (double x);
  double getVal();
  void constructWeights(int x);

private:
  double val;
  double* outputWeights;
  int numWeights;
};

class outputNode{
public:
  outputNode();
  void setVal (double x);
  double getVal();
private:
  double val;
};
