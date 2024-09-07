
#include "definitions.h"
#include "wire.h"
#include "gate.h"



Gate::Gate(std::string NameToSet){
  Name = NameToSet;
  InputWires[0] = nullptr;
  InputWires[1] = nullptr;
  OutputWire = nullptr;
  IsOutputGate = false;
  GateOutput = UNDEF;
  NumInputs = 0;
}

void Gate::SetAsOutputGate(){
  IsOutputGate = true;
}

void Gate::PrintGateOutput(){
  std::cout << GateOutput << std::endl;
}

Gate::~Gate(){}

void Gate::ConnectTheInput(Wire &InputWire){
  if (NumInputs > 2){
    std::cout << "Too Many Inputs to Gate" << std::endl;
  }
  InputWires[NumInputs] = &InputWire;
  NumInputs++;
}

void Gate::SetOutputWire(Wire &SetOutputWire){
  OutputWire = &SetOutputWire;
}

void ANDGate::ComputeGateLogic(){
  if (InputWires[0]->LogicLevel == UNDEF || InputWires[1]->LogicLevel == UNDEF){
      GateOutput = UNDEF;
  } else if (InputWires[0]->LogicLevel == HIGH && InputWires[1]->LogicLevel == HIGH){
      GateOutput = HIGH;
  } else {
      GateOutput = LOW;
  }

  // Only set the output wire if it's not a nullptr
  if (OutputWire != nullptr) {
      OutputWire->LogicLevel = GateOutput;
  }
}



void ORGate::ComputeGateLogic(){
  if (InputWires[0]->LogicLevel == UNDEF || InputWires[1]->LogicLevel == UNDEF){
      GateOutput = UNDEF;
  } else if (InputWires[0]->LogicLevel == 1|| InputWires[1]->LogicLevel == 1){
      GateOutput = HIGH;
  } else {
      GateOutput = LOW;
  }

  // Only set the output wire if it's not a nullptr
  if (OutputWire != nullptr) {
      OutputWire->LogicLevel = GateOutput;
  }
}



void XORGate::ComputeGateLogic(){
  if (InputWires[0]->LogicLevel == UNDEF || InputWires[1]->LogicLevel == UNDEF){
      GateOutput = UNDEF;
  } else if (InputWires[0]->LogicLevel != InputWires[1]->LogicLevel){
      GateOutput = HIGH;
  } else {
      GateOutput = LOW;
  }

  // Only set the output wire if it's not a nullptr
  if (OutputWire != nullptr) {
      OutputWire->LogicLevel = GateOutput;
  }
}


// Not gates do not care about the second input
// When a not gate is connected, that wire will connect to both inputs automatically

void NOTGate::ComputeGateLogic(){
  if (InputWires[0]->LogicLevel == UNDEF){
      GateOutput = UNDEF;
  } else if (InputWires[0]->LogicLevel == HIGH){
      GateOutput = LOW;
  } else if (InputWires[0]->LogicLevel == LOW) {
      GateOutput = HIGH;
  }

  // Only set the output wire if it's not a nullptr
  if (OutputWire != nullptr) {
      OutputWire->LogicLevel = GateOutput;
  }
}
