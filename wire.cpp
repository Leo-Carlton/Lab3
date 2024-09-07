#include "definitions.h"
#include "wire.h"


bool Wire::CheckIfInput(){
  if (IsInputWire == true){
    return true;
  }
  else{
    return false;
  }
};

Wire::Wire(std::string NameToSet){
  Name = NameToSet;
  IsInputWire = false;
  LogicLevel = UNDEF;
}

Wire::~Wire(){}

void Wire::SetInputLogic(int LogicToSet){
  if(IsInputWire){
    LogicLevel = LogicToSet;
  }
}

void Wire::SetAsInputWire(){
  IsInputWire = true;
}
