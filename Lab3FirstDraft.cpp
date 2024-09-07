// Leo Carlton
// 520431960
// Lab 3
#include <iostream>

// Define possible logic states

const int LOW = 0;
const int HIGH = 1;
const int UNDEF = 2;

// --------------------- WIRES -------------------------
 //Wires are a passive element. 

class Wire{
  public:
  Wire(std::string NameToSet);
  ~Wire();
  void SetInputLogic(int LogicToSet);
  void SetAsInputWire();
  int LogicLevel; // Initialised to UNDEF // Needs to be public in order to be controlled by a gate

  private:
  bool IsInputWire; // Initiased to False
  std::string Name;

};
