#include "definitions.h"
#include "circuit.h"
#include "wire.h"
#include "gate.h"

Wire* Circuit::GetWireByName(const std::string& Name) {
    return WireMap[Name];
}

Gate* Circuit::GetGateByName(const std::string& Name) {
    return GateMap[Name];
}

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

    std::ifstream infile("input.txt");
    std::string line;

    while (std::getline(infile, line)) {
        std::istringstream iss(line);
        std::string command;
        iss >> command;

        if (command == "CONSTRUCT") {
            std::string objectType, objectName;
            iss >> objectType >> objectName;
            if (objectType == "WIRE") {
                AddWire(objectName);
                std::cout << "Constructing Wire" << std::endl;
            } else {
                if (objectType == "ANDGATE"){
                    AddGate(0, objectName);
                    std::cout << "Constructing AndGate" << std::endl;
                }
                if (objectType == "ORGATE"){
                    AddGate(1, objectName);
                    std::cout << "Constructing OrGate" << std::endl;
                }
                if (objectType == "XORGATE"){
                    AddGate(2, objectName);
                    std::cout << "Constructing XorGate" << std::endl;
                }
                if (objectType == "NOTGATE"){
                    AddGate(3, objectName);
                    std::cout << "Constructing NotGate" << std::endl;
                }
             // Further if branching needed for the different gates
                // Put Construct Gate function, with the arg as the name
            }
        } 
        else if (command == "SET") {
            std::string objectName, property;
            iss >> objectName >> property;
            if (property == "INPUT") {
                SetInputWire(objectName);
                std::cout << "Setting "<< objectName << " as Input" << std::endl;
            } else if (property == "OUTPUT") {
                SetOutputGate(objectName);
                std::cout << "Setting " << objectName <<  " as Output" << std::endl;
            }
        } else if (command == "CONNECT") {
            std::string objectType, source, to, target;
            iss >> objectType >> source >> to >> target;
            if (objectType == "WIRE") {
                ConnectInputWire(source, target);
                std::cout << "Connecting " << source << " to " <<  target << std::endl;
            }
            if (objectType == "GATE") {
                std::string NumWiresString = std::to_string(NumWires);
                AddWire(NumWiresString);
                ConnectGates(NumWiresString,source,target);
                std::cout << "Connecting " << source << " to " <<  target << std::endl;
            }
        }
    }

}

Circuit::~Circuit(){}

void Circuit::SetOutputGate(const std::string& GateName) {
    Gate* gate = GetGateByName(GateName);
    if (gate) {
        gate->SetAsOutputGate();
        OutputGates.push_back(gate);
        NumOutputGates++;
    }
}

void Circuit::SetInputWire(const std::string& WireName) {
    Wire* wire = GetWireByName(WireName);
    if (wire) {
        wire->SetAsInputWire();
        InputWires.push_back(wire);
        NumInputWires++;
    }
}

void Circuit::ConnectGates(const std::string& WireName, const std::string& GateProvidingOutputName, const std::string& GateToInputName) {
    Wire* wire = GetWireByName(WireName);
    Gate* gateProvidingOutput = GetGateByName(GateProvidingOutputName);
    Gate* gateToInput = GetGateByName(GateToInputName);

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

void Circuit::ConnectInputWire(const std::string& WireName, const std::string& GateName) {
    Wire* wire = GetWireByName(WireName);
    Gate* gate = GetGateByName(GateName);

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
