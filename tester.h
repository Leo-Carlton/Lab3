#ifndef TESTER_H   // Include guard
#define TESTER_H

#include "definitions.h"
#include "wire.h"
#include "gate.h"

class Wire;
class Circuit;

// ---------------------- TESTER -------------------
 // Simply takes in a built circuit and prints the output to screen based on the configuration of the circuit

class TestCircuit{
  public:
  TestCircuit();
  ~TestCircuit();
  std::vector<Wire*> InputWirePointerVector;
  void AddCircuitToTest(Circuit& CircuitToRun);
  void ComputeCircuitOutput();

  private:
  Circuit* CircuitToTest;
  int NumDefinedOutputs;
};

#endif
