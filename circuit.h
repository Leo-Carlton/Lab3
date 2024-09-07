#ifndef CIRCUIT_H   // Include guard
#define CIRCUIT_H


#include "definitions.h"

class Gate;
class Wire;


// ----------------- CIRCUITS ------------------------------

// Max of 4 inputs

// The circuit constructor should, line by line, construct the circuit based on the text file

class Circuit{
  public:
  Circuit(); //This will intialise everything, then read the text file to build a circuit 
  ~Circuit();
  void AddGate(*Gate);
  void AddWire(*Wire);
  void ConnectGates(*Wire WireToUse, *Gate GateProvidingOutput, Gate* GateToInput); // Can connect the output of one gate as the input of another gate 
  void ConnectInputWire(Wire* WireToUse, Gate* GateToConnect); // Basic Connect wire 
  void SetOutputGate(Gate* Gate); 
  void SetInputWire(Wire* Wire);

  void ComputeOutputs();

  int NumInputWires;

  int NumWires; // These should be private but the TEST CLASS NEEDS THEM
  int NumOutputGates; // Test class needs to access this too

  std::vector<Wire*> InputWires; //Vector of the pointers that point to the inputs, some share with with the reg wires 
  std::vector<Gate*> OutputGates;

  private:

  int NumGates;

  std::vector<Wire*> CircuitWires; // Vector of Wires
  std::vector<Gate*> CircuitGates; // Vector of Gates


  int NumDefinedGates;
};

#endif
