#include "config.h"
#include "value.h"
#include "apps.h"


void setup() {
  // put your setup code here, to run once:
  button1.GPIO = but1;
  button2.GPIO = but2;
  button3.GPIO = but3;
  pinMode(button1.GPIO, INPUT_PULLUP);   // cấu hình nút ấn 
  pinMode(button2.GPIO, INPUT_PULLUP);
  pinMode(button3.GPIO, INPUT_PULLUP);
  screen.getTFT().setRotation(1);

}

void mainScreen(){
    screen.mainScreenUi();
}


void wifiApp(){
  mouseWifi[0] = default_mouse_position;
  while(1){
    screen.horizontalSelector(3,0,0,wifiText,mouseWifi[0]);
    while(1){
      if(getButtonState(ptrbut1) == true){
        mouseWifi[0]++;
        if(mouseWifi[0] > 2) mouseWifi[0]=0;
        screen.horizontalSelector(3,0,0,wifiText,mouseWifi[0]);
      }
      if(getButtonState(ptrbut2) == true){
        break;
      }
      if(getButtonState(ptrbut3) == true){
        mouseWifi[0]--;
        if(mouseWifi[0] < 0) mouseWifi[0]=2;
        screen.horizontalSelector(3,0,0,wifiText,mouseWifi[0]);
      }
    }
    if(mouseWifi[0] == 0){
      wifi::connectWifi();  //done
    }
    if(mouseWifi[0] == 1){
      wifi::oldWifi();
    }
    if(mouseWifi[0] == 2){
      break;
    }

  }
}

void clockApp(){
  mouseClock = default_mouse_position;
  while(1){
    myClock::mainScreenClockApp(mouseClock);
    while(1){
      if(getButtonState(ptrbut1) == true){
        mouseClock++;
        if(mouseClock > 4) mouseClock = 0;
        myClock::mainScreenClockApp(mouseClock);
      }
      if(getButtonState(ptrbut2) == true){
        break;
      }
      if(getButtonState(ptrbut3) == true){
        mouseClock--;
        if(mouseClock < 0) mouseClock = 4;
        myClock::mainScreenClockApp(mouseClock);
      }
    }
    if(mouseClock == 0){
      myClock::updateTime();
    }
    if(mouseClock == 1){
      
    }
    if(mouseClock == 2){
      
    }
    if(mouseClock == 3){
      
    }
    if(mouseClock == 4){
      break;
    }
  }
}

void weatherApp(){

}

void IOTApp(){

}


void setupSystem(){
  mouseSetup[0] = default_mouse_position; 
  while(1){
    screen.horizontalSelector(5,0,0,setupText,mouseSetup[0]);
    while(1){
      if(getButtonState(ptrbut1) == true){
        mouseSetup[0]++;
        if(mouseSetup[0] > 4) mouseSetup[0]=0;
        screen.horizontalSelector(5,0,0,setupText,mouseSetup[0]);
      }
      if(getButtonState(ptrbut2) == true){
        break;
      }
      if(getButtonState(ptrbut3) == true){
        mouseSetup[0]--;
        if(mouseSetup[0] < 0) mouseSetup[0]=4;
        screen.horizontalSelector(5,0,0,setupText,mouseSetup[0]);
      }
    }
    if(mouseSetup[0] == 0){
      setupDevice::setupColor();
    }
    if(mouseSetup[0] == 1){
      setupDevice::percentOfBattery();
    }
    if(mouseSetup[0] == 2){

    }
    if(mouseSetup[0] == 3){

    }
    if(mouseSetup[0] == 4){
      break;
    }
  }
}


void app(){
  mouseApp = default_mouse_position;
  while(1){
    screen.matrixSelectoNOutsideText( 2, 3,appText,mouseApp);
    while(1){
      if(getButtonState(ptrbut1) == true){
        mouseApp++;
        if(mouseApp > 5){
          mouseApp = 0;
        }
        screen.matrixSelectoNOutsideText( 2, 3,appText,mouseApp);
      }
      if(getButtonState(ptrbut2) == true){
        break;
      }
      if(getButtonState(ptrbut3) == true){
        mouseApp--;
        if(mouseApp < 0){
          mouseApp = 5;
        }
        screen.matrixSelectoNOutsideText( 2, 3,appText,mouseApp);
      }
    }
    if(mouseApp == 0){
      wifiApp();
    }
    if(mouseApp == 1){
      clockApp();
    }
    if(mouseApp == 2){
      weatherApp();
    }
    if(mouseApp == 3){
      IOTApp();
    }
    if(mouseApp == 4){
      setupSystem();
    }
    if(mouseApp == 5){
      break;
    }
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  mainScreen();
  if(getButtonState(ptrbut1) == true || getButtonState(ptrbut3) == true){
    app();
  }
}
