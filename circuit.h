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
  void AddGate(int type, std::string NameToSet);
  void AddWire(std::string NameToSet);
  void ConnectGates(const std::string& WireName, const std::string& GateProvidingOutputName, const std::string& GateToInputName); // Can connect the output of one gate as the input of another gate 
  void ConnectInputWire(const std::string& WireName, const std::string& GateName); // Basic Connect wire 
  void SetOutputGate(const std::string& GateName); 
  void SetInputWire(const std::string& WireName);

  void ComputeOutputs();

  Wire* GetWireByName(const std::string& Name);
  Gate* GetGateByName(const std::string& Name);


  int NumInputWires;

  int NumWires; // These should be private but the TEST CLASS NEEDS THEM
  int NumOutputGates; // Test class needs to access this too

  std::vector<Wire*> InputWires; //Vector of the pointers that point to the inputs, some share with with the reg wires 
  std::vector<Gate*> OutputGates;

  private:

  std::map<std::string, Wire*> WireMap;
  std::map<std::string, Gate*> GateMap;

  int NumGates;



  std::vector<Wire*> CircuitWires; // Vector of Wires
  std::vector<Gate*> CircuitGates; // Vector of Gates


  int NumDefinedGates;
};

#endif
