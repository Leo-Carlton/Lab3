// Leo Carlton
// 520431960
// Lab 3
#include "definitions.h"
#include "wire.h"
#include "gate.h"
#include "circuit.h"
#include "tester.h"
  
int main(){

  Circuit BuildCircuitFromTxt;
  TestCircuit Test;
  Test.AddCircuitToTest(BuildCircuitFromTxt);
  Test.ComputeCircuitOutput();
  return 0;
};
