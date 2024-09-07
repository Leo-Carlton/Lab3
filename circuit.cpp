#include "definitions.h"
#include "circuit.h"
#include "wire.h"
#include "gate.h"

void Circuit::ComputeOutputs(){
  NumDefinedGates = 0;
  while (NumDefinedGates != NumGates){
    for (int i = 0; i<NumGates ; i++){
      CircuitGates[i]->ComputeGateLogic();
      if (CircuitGates[i]->GateOutput != UNDEF){
        NumDefinedGates++;
      }
    }
  }
}

Circuit::Circuit(){
  NumWires = 0;
  NumGates = 0;
  NumInputWires = 0;
  NumOutputGates = 0;
  NumDefinedGates = 0;
}

Circuit::~Circuit(){}

void Circuit::SetOutputGate(*Gate gate) {
    if (gate) {
        gate->SetAsOutputGate();
        OutputGates.push_back(gate);
        NumOutputGates++;
    }
}

void Circuit::SetInputWire(Wire* wire) {
    if (wire) {
        wire->SetAsInputWire();
        InputWires.push_back(wire);
        NumInputWires++;
    }
}

void Circuit::ConnectGates(Wire* wire, Gate* gateProvidingOutput, Gate* gateToInput) {
    if (wire && gateProvidingOutput && gateToInput) {
        gateProvidingOutput->SetOutputWire(*wire);

        // Check if the target gate is a NOT gate
        NOTGate* notGate = dynamic_cast<NOTGate*>(gateToInput);
        if (notGate) {
            // Connect the input wire twice if it's a NOT gate
            notGate->ConnectTheInput(*wire);
            notGate->ConnectTheInput(*wire);
        } else {
            // Otherwise, connect the input wire once
            gateToInput->ConnectTheInput(*wire);
        }
    }
}

void Circuit::ConnectInputWire(Wire* wire, Gate* gate) {

    if (wire && gate) {
        // Check if the gate is a NOT gate
        NOTGate* notGate = dynamic_cast<NOTGate*>(gate);
        if (notGate) {
            // Connect the input wire twice if it's a NOT gate
            notGate->ConnectTheInput(*wire);
            notGate->ConnectTheInput(*wire);
        } else {
            // Otherwise, connect the input wire once
            gate->ConnectTheInput(*wire);
        }
    }
}

// Type: 0 = AND, 1 = OR, 2= XOR, 3 = NOT
void Circuit::AddGate(int type, std::string NameToSet){
    Gate* gate = nullptr;
    if (type == 0) gate = new ANDGate(NameToSet);
    else if (type == 1) gate = new ORGate(NameToSet);
    else if (type == 2) gate = new XORGate(NameToSet);
    else if (type == 3) gate = new NOTGate(NameToSet);

    if (gate) {
        CircuitGates.push_back(gate);
        GateMap[NameToSet] = gate;
        NumGates++;
    }
}

void Circuit::AddWire(std::string NameToSet){
    Wire* wire = new Wire(NameToSet);
    CircuitWires.push_back(wire);
    WireMap[NameToSet] = wire;
    NumWires++;
}
