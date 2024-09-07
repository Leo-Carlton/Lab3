#ifndef GATE_H   // Include guard
#define GATE_H


#include "definitions.h"
class Wire;  // Forward declaration of the Wire class


// ------------------ GATES ------------------------
 // Gates store all information. They are an active element. Gates can control the logiclevel of their wires. The tester class will loop over all gates in the circuit it is testing and continue to compute their outputs.

class Gate{
  public:
  virtual void ComputeGateLogic() =0;
  void ConnectTheInput(Wire& InputWire); //Only takes a wire
  void SetOutputWire(Wire& OutputWire);
  void PrintGateOutput();
  void SetAsOutputGate();
  Gate(std::string NameToSet); 
  ~Gate();
  std::string Name;
  int GateOutput; // Initialised to 2. Also needs to be accessed by the circuit class

  protected:
  Wire* InputWires[2]; // Initialsed to NULL Wire pointers -- Check if all gates dont have null wire connetions 
  Wire* OutputWire; // Initialised to NULL Wire pointer  
  bool IsOutputGate; // INitialised to false 

  int NumInputs; // If this is not 2 for the tester something is wrong 

};

// ----------------- SUBCLASS GATES ---------------------

class ANDGate : public Gate {
public:
  ANDGate(std::string NameToSet) : Gate(NameToSet) {} // Constructor that calls the base class constructor
  void ComputeGateLogic();
};

class ORGate : public Gate {
public:
  ORGate(std::string NameToSet) : Gate(NameToSet) {} // Constructor that calls the base class constructor
  void ComputeGateLogic();
};

class XORGate : public Gate {
public:
  XORGate(std::string NameToSet) : Gate(NameToSet) {} // Constructor that calls the base class constructor
  void ComputeGateLogic();
};

class NOTGate : public Gate {
public:
  NOTGate(std::string NameToSet) : Gate(NameToSet) {} // Constructor that calls the base class constructor
  void ComputeGateLogic();
};


#endif // MYCLASS_H
