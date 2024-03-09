#ifndef UIPAINTER_H
#define UIPAINTER_H

#include <TFT_eSPI.h>

class Ui{
  private:
  TFT_eSPI tft = TFT_eSPI();
  TFT_eSprite tft_00 = TFT_eSprite(&tft);
  TFT_eSprite tft_01 = TFT_eSprite(&tft);
  TFT_eSprite tft_02 = TFT_eSprite(&tft);
  uint8_t red = 148;
  uint8_t green = 248;
  uint8_t blue = 252;
  uint16_t color;
  bool error = 0;
  uint16_t choiceColor,textColor;

  public:
  Ui(){
    init();
    uint16_t color = tft.color565(red,green,blue);
  }

  void init(){
    tft.init();
    tft_00.createSprite(TFT_WIDTH/2,TFT_HEIGHT);
    tft_01.createSprite(TFT_WIDTH,TFT_HEIGHT/2);
    tft_02.createSprite(TFT_WIDTH/2,TFT_HEIGHT/2);
  }

  void setRed(uint8_t red){
    if (red >= 0 && red <= 255) { // Kiểm tra giá trị green có nằm trong phạm vi hợp lệ không
        this->red = red;
    } else {
        // Nếu giá trị không hợp lệ, bạn có thể in ra cảnh báo hoặc thực hiện hành động khác tùy thuộc vào yêu cầu của bạn
        error = 1;
        Serial.println("Giá trị red không hợp lệ! Phải nằm trong khoảng từ 0 đến 255.");
        // Hoặc thực hiện hành động khác ở đây
    }
  }

  uint8_t getRed(){
    return red;
  }

  void setGreen(uint8_t green){
    if (green >= 0 && green <= 255) { // Kiểm tra giá trị green có nằm trong phạm vi hợp lệ không
        this->green = green;
    } else {
        // Nếu giá trị không hợp lệ, bạn có thể in ra cảnh báo hoặc thực hiện hành động khác tùy thuộc vào yêu cầu của bạn
        error = 1;
        Serial.println("Giá trị green không hợp lệ! Phải nằm trong khoảng từ 0 đến 255.");
        // Hoặc thực hiện hành động khác ở đây
    }
  }

  uint8_t getGreen(){
    return green;
  }

  void setBlue(uint8_t blue){
    if (blue >= 0 && blue <= 255) { // Kiểm tra giá trị green có nằm trong phạm vi hợp lệ không
        this->blue = blue;
    } else {
        // Nếu giá trị không hợp lệ, bạn có thể in ra cảnh báo hoặc thực hiện hành động khác tùy thuộc vào yêu cầu của bạn
        error = 1;
        Serial.println("Giá trị blue không hợp lệ! Phải nằm trong khoảng từ 0 đến 255.");
        // Hoặc thực hiện hành động khác ở đây
    }
  }

  uint8_t getBlue(){
    return blue;
  }

  uint16_t getColor(){
    return color;
  }

  void setDefaultColor(){
    red=148;
    green=248;
    blue=252;
  }

  void setError(bool error){
    this->error=error;
  }

  bool getError(){
    return error;
  }

  TFT_eSPI getTFT(){
    return tft;
  }

  TFT_eSprite& getSpriteIndex(int index){
    if(index == 0){
      return tft_00;
    }
    if(index == 1){
      return tft_01;
    }
    if(index == 2){
      return tft_02;
    }
  }

  void setSprite(int index,int width,int height){
    if(index == 0){
      tft_00.createSprite(width,height);
    }
    if(index == 1){
      tft_01.createSprite(width,height);
    }
    if(index == 2){
      tft_02.createSprite(width,height);
    }
  }

  void mainScreenUi(){

  }

  void matrixSelectoNOutsideText(int row,int col,const char* text[],int mouse){
    tft.fillScreen(TFT_BLACK);
    int width = (TFT_WIDTH/(4*col+1))*3;
    int height = (TFT_HEIGHT/(7*row))*3;
    int x=TFT_WIDTH/(4*col+1);
    int y=TFT_HEIGHT/(7*row);
    if(height >20){
      tft.setTextSize(2);
    }else{
      tft.setTextSize(1);
    }
    int count=0;
    for(int i=0;i<col;i++){
      for(int j=0;j<row;j++){
        if(count == mouse){
          choiceColor = TFT_WHITE;
          textColor = TFT_WHITE;
        }else{
          choiceColor = color;
          textColor = color;
        }
        tft.fillSmoothRoundRect(x + i*(TFT_WIDTH/(4*col+1))*4, y +j*(TFT_HEIGHT/(7*row))*4, width, height,2, choiceColor);
        tft.setCursor(x + (TFT_WIDTH/(4*col+1))*5/2 + i*(TFT_WIDTH/(4*col+1))*4,y + (TFT_HEIGHT/(7*row))*13/2 +j*(TFT_HEIGHT/(7*row))*4);
        tft.setTextDatum(ML_DATUM);
        tft.setTextColor(textColor);
        tft.print(text[count]);
        count++;
      }
    }
  }

  void horizontalSelector(int numOfBars,int x,int y,const char* text[],uint8_t mouse){
    
  }

  void horizontalSelector(int x,int y){

  }
  void drawTextInFrame(const char* text, int x, int y, int width, int height,uint16_t textColor,uint16_t backgroundColor){
    tft.fillSmoothRoundRect(x,y,width,height,backgroundColor,TFT_BLACK);
    tft.setTextColor(textColor);
    tft.setCursor(x+width/2,y+height/2);
    if(height >=18){
      tft.setTextSize(2);
    }else{
      tft.setTextSize(1);
    }
    tft.setTextDatum(ML_DATUM);
    tft.print(text);
  }
  

};

#endif