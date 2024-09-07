#include "definitions.h"
#include "tester.h"
#include "circuit.h"


TestCircuit::TestCircuit(){
  NumDefinedOutputs = 0;
}

TestCircuit::~TestCircuit(){}

void TestCircuit::AddCircuitToTest(Circuit &CircuitToRun){
  CircuitToTest = &CircuitToRun;
}

void TestCircuit::ComputeCircuitOutput(){
  if (CircuitToTest->NumInputWires == 2){
    for (int i = 0; i < 2 ; i++){
      for (int j = 0; j < 2; j++){
        CircuitToTest->InputWires[0]->SetInputLogic(i);
        CircuitToTest->InputWires[1]->SetInputLogic(j);
        CircuitToTest->ComputeOutputs();

        // Print the outputs
        std::cout << "Inputs: " << i << "," << j << std::endl;
        for (int k =0; k < CircuitToTest->NumOutputGates; k++){
          std::cout << CircuitToTest->OutputGates[k]->Name << ": " << CircuitToTest->OutputGates[k]->GateOutput << std::endl;
        }
      }
    }
  }
}
