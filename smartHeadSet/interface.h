#ifndef INTERFACE_H
#define INTERFACE_H

// BUTTON INTERFACE
struct button{
  uint8_t GPIO;
  int lastState;
  int currentState;
};

bool getButtonState(button* button){
  button->currentState = digitalRead(button->GPIO);
  if(button->currentState == LOW && button->lastState == HIGH){
    button->lastState = LOW;
    return true;
  }else if(button->currentState == HIGH && button->lastState == LOW){
    button->lastState = HIGH;
    return false;
  }else{
    return false;
  }
}


#endif