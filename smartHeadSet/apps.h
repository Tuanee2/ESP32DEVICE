#ifndef APPS_H
#define APPS_H

#include "config.h"
#include "UIPainter.h"
#include "interface.h"

namespace weather {
  void updateWeather(){
    screen.getTFT().fillScreen(TFT_BLACK);
    if(WiFi.status() != WL_CONNECTED){
      screen.getTFT().setTextSize(4);
      screen.getTFT().setTextColor(screen.getColor());
      screen.getTFT().setCursor(TFT_WIDTH/2,TFT_HEIGHT/2);
      screen.getTFT().setTextDatum(ML_DATUM);
      screen.getTFT().print("DISCONNECTED");
    }else{

    }
  }
  void getWeather(){

  }
  void displayWeather(){
    
  }
}

namespace myClock {
  
  void updateTime(){

  }
  void updateTimeWifi(){
    screen.getTFT().fillScreen(TFT_BLACK);
    if(WiFi.status() != WL_CONNECTED){
      screen.getTFT().setTextSize(4);
      screen.getTFT().setTextColor(screen.getColor());
      screen.getTFT().setCursor(TFT_WIDTH/2,TFT_HEIGHT/2);
      screen.getTFT().setTextDatum(ML_DATUM);
      screen.getTFT().print("DISCONNECTED");
    }else{

    }
  }
  void drawClock(int x,int y){
    screen.getSpriteIndex(0).fillScreen(TFT_BLACK);

    screen.getSpriteIndex(0).pushSprite(x,y);
  }
  void synRealTime(){

  }
  void alarm(){

  }
  void hourCount(){

  }
  void mainScreenClockApp(int mouse){
    drawClock(0,0);
    screen.horizontalSelector(5,TFT_WIDTH/2,0,clokText,mouse);
  };
}

namespace wifi {
  void connectWifi(){
    mouseWifi[1] = default_mouse_position;
    while(1){
      int numNetworks = WiFi.scanNetworks();
      int count = 0;
      for(int i=0;i < 7;i++){
        if(i+mouseWifi[1]==0){
          screen.drawTextInFrame("BACK",5,5,TFT_WIDTH-10,20,TFT_BLACK,TFT_WHITE);
        }else{
          if(i == 0){
            screen.drawTextInFrame(WiFi.SSID(i+mouseWifi[1]-1).c_str(),5,5,TFT_WIDTH-10,20,TFT_BLACK,TFT_WHITE);
          }else{
            screen.drawTextInFrame(WiFi.SSID(i+mouseWifi[1]-1).c_str(),5+i*25,5,TFT_WIDTH-10,20,TFT_BLACK,screen.getColor());
          }
        }
      }
      if(getButtonState(ptrbut1) == true){
        if(mouseWifi[1] < numNetworks){
          mouseWifi[1]++;
        }
      }
      if(getButtonState(ptrbut2) == true){
        break;
      }
      if(getButtonState(ptrbut3) == true){
        if(mouseWifi[1] > 0 ){
          mouseWifi[1]--;
        }
      }
    }
    if(mouseWifi[1]!=0){
      screen.getTFT().fillScreen(TFT_BLACK);
      screen.getTFT().setCursor(0,0);
      screen.getTFT().setTextSize(2);
      screen.getTFT().setTextColor(screen.getColor());
      screen.getTFT().print("Connecting");
      WiFi.begin(WiFi.SSID(mouseWifi[1]-1).c_str(), "20002000");
      while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        screen.getTFT().print(".");
      }
      screen.getTFT().fillScreen(TFT_BLACK);
      screen.getTFT().print("CONNECTED!");
      delay(2000);
    }
  }
  void oldWifi(){

  }
}

namespace setupDevice {
  void setupColor(){

  }
  void percentOfBattery(){

  }
}

namespace messeage {

}

namespace IOT {
  void light(){

  }
}
#endif