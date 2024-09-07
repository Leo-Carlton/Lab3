#ifndef WIRE_H   // Include guard
#define WIRE_H


#include "definitions.h" // These will be added 

// --------------------- WIRES -------------------------
 //Wires are a passive element. 


class Wire{
  public:
  Wire(std::string NameToSet);
  ~Wire();
  void SetInputLogic(int LogicToSet);
  void SetAsInputWire();
  int LogicLevel; // Initialised to UNDEF // Needs to be public in order to be controlled by a gate
  bool CheckIfInput();

  private:
  bool IsInputWire; // Initiased to False
  std::string Name;

};

#endif
