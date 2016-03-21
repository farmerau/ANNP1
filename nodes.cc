#include "nodes.h"
#include <iostream>
#include <cstdlib>
#include <fstream>

using namespace std;
inputNode::inputNode(){
  numWeights = 0;
  outputWeights = NULL;
  val = 0;
}

void inputNode::setWeight(int index, double value){
  outputWeights[index] = value;
}

double inputNode::getWeight(int index){
  return outputWeights[index];
}

void inputNode::setVal(double x){
  val = x;
}

double inputNode::getVal(){
  return val;
}

void inputNode::constructWeights(int x){
  numWeights = x;
  outputWeights = new double[numWeights];
}

////====>START outputNode Class Stuff

outputNode::outputNode(){
  val = 0;
}

void outputNode::setVal(double x){
  val = x;
}

double outputNode::getVal(){
  return val;
}
