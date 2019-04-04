#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define OLED_RESET 4

#define LB_PIN 5
#define MB_PIN 6
#define RB_PIN 7

#define BUTTON_DELAY 50 // Debouncing / spamming delay in ms
#define HOLD_DELAY 1000 // Time to "hold" a button

Adafruit_SSD1306 screen(OLED_RESET);

void setup() { // Does not need to be copied
  pinMode(LB_PIN, INPUT);
  pinMode(MB_PIN, INPUT);
  pinMode(RB_PIN, INPUT);

  screen.begin(SSD1306_SWITCHCAPVCC, 0x3c);
  screen.setTextSize(1);
  screen.setTextColor(WHITE);
}

void loop() {
  static byte state = 0;

  switch(state){
    case 0:
      // State 0: 
      state0();
      checkButtons(&state);
      break;
    case 1:
      // State 1: 
      state1();
      checkButtons(&state);
      break;
    case 2:
      // State 2: 
      state2();
      checkButtons(&state);
      break;
    case 3:
      // State 3: 
      state3();
      checkButtons(&state);
      break;
    case 4:
      // State 4:
      state4();
      checkButtons(&state);
      break;
    case 5:
      // State 5:
      state5();
      checkButtons(&state);
      break;
    case 6:
      // State 6:
      state6();
      checkButtons(&state);
      break;
    case 7:
      // State 7:
      state7();
      checkButtons(&state);
      break;
    case 8:
      // State 8:
      state8();
      checkButtons(&state);
      break;
    case 9:
      // State 9:
      state9();
      checkButtons(&state);
      break;
    case 10:
      // State 10:
      state10();
      checkButtons(&state);
      break;
    case 11:
      // State 11:
      state11();
      checkButtons(&state);
      break;
    case 12:
      // State 12:
      state12();
      checkButtons(&state);
      break;
    case 15:
      // State 15:
      state15();
      state = 0;
      break;
    case 20:
      //State 20:
      state20();
      checkButtons(&state);
      break;
    case 21:
      //State 21:
      state21();
      checkButtons(&state);
      break;
    case 22:
      //State 22:
      state22();
      checkButtons(&state);
      break;
    case 25:
      //State 25:
      state25();
      checkButtons(&state);
      break;
    case 26:
      //State 26:
      state26();
      checkButtons(&state);
      break;
    case 27:
      //State 27:
      state27();
      checkButtons(&state);
      break;
  }
}

//###################################################################
//######################    BUTTON HANDLING    ######################
//###################################################################

/*
 * This function will handle the overall checking of the button inputs
 * and whether or not they were pressed or held. After determining the
 * type of button input, it will delegate the state changes to one of
 * 6 functions, with one for each type of possible button input
 * 
 * INPUTS: A pointer to the state byte in the main loop
 * 
 * OUTPUT: Nothing, will change state via a reference and pointer
 */
void checkButtons(byte *state){
  static unsigned long lastTime = 0;
  static byte lastState[3] = {0, 0, 0};
  static byte held = 0;

  // Read button states
  int leftButton = digitalRead(LB_PIN);
  int middleButton = digitalRead(MB_PIN);
  int rightButton = digitalRead(RB_PIN);

  // If sufficient time has elapsed since the last button press
  if(millis() - lastTime > BUTTON_DELAY){
    
    // If left button is pressed
    if(leftButton == 1 && leftButton != lastState[0]){
      lastTime = millis();
      held = 0;
      while(digitalRead(LB_PIN) == 1){ // Check if the button is being held
        if(millis() - lastTime > HOLD_DELAY){
          held = 1;
          lastTime = millis();
          break;
        }
      }
      if(held){
        *state = leftButtonHeld(*state);
      }
      else{
        *state = leftButtonPressed(*state);
      }
    }
    
    // If middle button is pressed
    if(middleButton == 1 && middleButton != lastState[1]){
      lastTime = millis();
      held = 0;
      while(digitalRead(MB_PIN) == 1){ // Check if the button is being held
        if(millis() - lastTime > HOLD_DELAY){
          held = 1;
          lastTime = millis();
          break;
        }
      }
      if(held){
        *state = middleButtonHeld(*state);
      }
      else{
        *state = middleButtonPressed(*state);
      }
    }
    
    // If right button is pressed
    if(rightButton == 1 && rightButton != lastState[2]){
      lastTime = millis();
      held = 0;
      while(digitalRead(RB_PIN) == 1){ // Check if the button is being held
        if(millis() - lastTime > HOLD_DELAY){
          held = 1;
          lastTime = millis();
          break;
        }
      }
      if(held){
        *state = rightButtonHeld(*state);
      }
      else{
        *state = rightButtonPressed(*state);
      }
    }
  }

  lastState[0] = leftButton;
  lastState[1] = middleButton;
  lastState[2] = rightButton;
}

//###################################################################
//######################   STATE CHANGE LOGIC  ######################
//###################################################################

/*
 * This function will handle state change logic based on current state
 * and a left button press.
 * 
 * INPUTS: The current state
 * 
 * OUTPUT: The next state
 */
byte leftButtonPressed(byte state){
  switch(state){
    case 0:
      state = 3;
      break;
    case 1:
      state = 5;
      break;
    case 2:
      state = 0;
      break;
    case 3:
      state = 2;
      break;
    case 4:
      state = 12;
      break;
    case 5:
      state = 1;
      break;
    case 6:
      state = 4;
      break;
    case 7:
      state = 6;
      break;
    case 8:
      state = 7;
      break;
    case 9:
      state = 8;
      break;
    case 10:
      state = 9;
      break;
    case 11:
      state = 10;
      break;
    case 12:
      state = 11;
      break;
    case 20:
      state = 22;
      break;
    case 21:
      state = 20;
      break;
    case 22:
      state = 21;
      break;
    case 25:
      state = 26;
      break;
    case 26:
      state = 27;
      break;
    case 27:
      state = 25;
      break;
      
  }

  return state;
}

/*
 * This function will handle state change logic based on current state
 * and a left button hold.
 * 
 * INPUTS: The current state
 * 
 * OUTPUT: The next state
 */
byte leftButtonHeld(byte state){
  switch(state){
    case 0:
      //state = ;
      break;
    case 1:
      //state = ;
      break;
    case 2:
      //state = ;
      break;
    case 3:
      //state = ;
      break;
    case 4:
      //state = ;
      break;
    case 5:
      //state = ;
      break;
    case 6:
      //state = ;
      break;
    case 7:
      //state = ;
      break;
    case 8:
      //state = ;
      break;
    case 9:
      //state = ;
      break;
    case 10:
      //state = ;
      break;
    case 11:
      //state = ;
      break;
    case 12:
      //state = ;
      break;
    case 20:
      //state = ;
      break;
    case 21:
      //state = ;
      break;
    case 22:
      //state = ;
      break;
    case 25:
      //state = ;
      break;
    case 26:
      //state = ;
      break;
    case 27:
      //state = ;
      break;
  }

  return state;
}

/*
 * This function will handle state change logic based on current state
 * and a middle button press.
 * 
 * INPUTS: The current state
 * 
 * OUTPUT: The next state
 */
byte middleButtonPressed(byte state){
  switch(state){
    case 0:
      state = 1;
      break;
    case 1:
      state = 4;
      break;
    case 2:
      state = 1;
      break;
    case 3:
      state = 1;
      break;
    case 4: // Select plant 1
      state = 15;
      break;
    case 5:
      state = 20;
      break;
    case 6: // Select plant 2
      state = 15;
      break;
    case 7: // Select plant 3
      state = 15;
      break;
    case 8: // Select plant 4
      state = 15;
      break;
    case 9: // Select plant 5
      state = 15;
      break;
    case 10: // Select plant 6
      state = 15;
      break;
    case 11: // Select plant 7
      state = 15;
      break;
    case 12: // Select plant 8
      state = 15;
      break;
    case 20:
      state = 25;
      break;
    case 21:
      //state = ;
      break;
    case 22:
      //state = ;
      break;
    case 25: // sub from light hours
      //state = ;
      break;
    case 26: // sub from red intensity %
      //state = ;
      break;
    case 27: // sub from blue intensity %
      //state = ;
      break;
      
  }

  return state;
}

/*
 * This function will handle state change logic based on current state
 * and a middle button hold.
 * 
 * INPUTS: The current state
 * 
 * OUTPUT: The next state
 */
byte middleButtonHeld(byte state){
  switch(state){
    case 0:
      //state = ;
      break;
    case 1:
      state = 0;
      break;
    case 2:
      //state = ;
      break;
    case 3:
      //state = ;
      break;
    case 4:
      state = 1;
      break;
    case 5:
      state = 0;
      break;
    case 6:
      state = 1;
      break;
    case 7:
      state = 1;
      break;
    case 8:
      state = 1;
      break;
    case 9:
      state = 1;
      break;
    case 10:
      state = 1;
      break;
    case 11:
      state = 1;
      break;
    case 12:
      state = 1;
      break;
    case 20:
      state = 1;
      break;
    case 21:
      state = 1;
      break;
    case 22:
      state = 1;
      break;
    case 25:
      state = 20;
      break;
    case 26:
      state = 20;
      break;
    case 27:
      state = 20;
      break;
  }

  return state;
}

/*
 * This function will handle state change logic based on current state
 * and a right button press.
 * 
 * INPUTS: The current state
 * 
 * OUTPUT: The next state
 */
byte rightButtonPressed(byte state){
  switch(state){
    case 0:
      state = 2;
      break;
    case 1:
      state = 5;
      break;
    case 2:
      state = 3;
      break;
    case 3:
      state = 0;
      break;
    case 4:
      state = 6;
      break;
    case 5:
      state = 1;
      break;
    case 6:
      state = 7;
      break;
    case 7:
      state = 8;
      break;
    case 8:
      state = 9;
      break;
    case 9:
      state = 10;
      break;
    case 10:
      state = 11;
      break;
    case 11:
      state = 12;
      break;
    case 12:
      state = 4;
      break;
    case 20:
      state = 21;
      break;
    case 21:
      state = 22;
      break;
    case 22:
      state = 20;
      break;
    case 25: // Add to light hours
      //state = ;
      break;
    case 26: // Add to red intensity %
      //state = ;
      break;
    case 27: // Add to blue intensity %
      //state = ;
      break;
      
  }

  return state;
}

/*
 * This function will handle state change logic based on current state
 * and a right button hold.
 * 
 * INPUTS: The current state
 * 
 * OUTPUT: The next state
 */
byte rightButtonHeld(byte state){
  switch(state){
    case 0:
      //state = ;
      break;
    case 1:
      //state = ;
      break;
    case 2:
      //state = ;
      break;
    case 3:
      //state = ;
      break;
    case 4:
      //state = ;
      break;
    case 5:
      //state = ;
      break;
    case 6:
      //state = ;
      break;
    case 7:
      //state = ;
      break;
    case 8:
      //state = ;
      break;
    case 9:
      //state = ;
      break;
    case 10:
      //state = ;
      break;
    case 11:
      //state = ;
      break;
    case 12:
      //state = ;
      break;
    case 20:
      //state = ;
      break;
    case 21:
      //state = ;
      break;
    case 22:
      //state = ;
      break;
    case 25:
      //state = ;
      break;
    case 26:
      //state = ;
      break;
    case 27:
      //state = ;
      break;
      
  }

  return state;
}

//###################################################################
//######################    STATE FUNCTIONS    ######################
//###################################################################

void state0(){
        screen.clearDisplay();
        
        String tempString = "t"; //String(piss.getTemperature(), 1);
        String soilString = "sm"; //String(piss.getMoisture());
        String humiString = "h"; //String(piss.getHumidity());
        String waterString = "w"; //String(piss.getWateredMin());
    
        screen.clearDisplay();
        screen.setTextSize(1.5);
        screen.setTextColor(WHITE);
        screen.setCursor(0, 0);

        // draw options menu on bottom
        screen.drawLine(0, 50, 128, 50, WHITE);
        screen.drawRect(45, 53, 38, 11, WHITE);
        screen.setCursor(53, 55);
        screen.print("MENU");
        screen.fillTriangle(5, 58, 13, 54, 13, 62, WHITE);
        screen.fillTriangle(123, 58, 115, 54, 115, 62, WHITE);
    
        // Line 1
        screen.setCursor(0, 0);
        screen.print("Temperature:");
        screen.setCursor(84, 0);
        screen.print(tempString + " C");
    
        // Line 2
        screen.setCursor(0, 10);
        screen.print("Humidity:");
        screen.setCursor(90, 10);
        screen.print(humiString + " %");
    
        // Line 3
        screen.setCursor(0, 20);
        screen.print("Soil Moisture:");
        screen.setCursor(90, 20);
        screen.print(soilString + " %");
        
        // Line 4
        screen.setCursor(0, 30);
        screen.print("Last watered:");
        screen.setCursor(90, 30);
        screen.print(waterString + " m");
        
        screen.display();
}

void state1(){
        screen.clearDisplay();
  
        screen.setCursor(0, 0);
        screen.print("[Main menu]");

        screen.drawLine(0, 8, 128, 8, WHITE);

        screen.setCursor(0, 12);
        screen.setTextColor(BLACK, WHITE);
        screen.print("Select plant...");
        screen.setTextColor(WHITE, BLACK);

        screen.setCursor(0, 22);
        screen.print("Customize settings...");

        // draw options menu on bottom
        screen.drawLine(0, 50, 128, 50, WHITE);
        screen.drawRect(45, 53, 38, 11, WHITE);
        screen.setCursor(50, 55);
        screen.print("ENTER");
        screen.fillTriangle(5, 62, 13, 62, 9, 54, WHITE);
        screen.fillTriangle(123, 54, 115, 54, 119, 62, WHITE);

        screen.display();
}

void state2(){
        screen.clearDisplay();

        // Line 1
        screen.setCursor(0, 0);
        screen.print("Plant Name:");
        screen.setCursor(98, 0);
        screen.print("bepis");
    
        // Line 2
        screen.setCursor(0, 10);
        screen.print("Light Hours:");
        screen.setCursor(98, 10);
        screen.print("VAL");
    
        // Line 3
        screen.setCursor(0, 20);
        screen.print("Ideal Temp:");
        screen.setCursor(98, 20);
        screen.print("VAL");
        
        // Line 4
        screen.setCursor(0, 30);
        screen.print("Ideal Humidity:");
        screen.setCursor(98, 30);
        screen.print("VAL");

        // draw options menu on bottom
        screen.drawLine(0, 50, 128, 50, WHITE);
        screen.drawRect(45, 53, 38, 11, WHITE);
        screen.setCursor(53, 55);
        screen.print("MENU");
        screen.fillTriangle(5, 58, 13, 54, 13, 62, WHITE);
        screen.fillTriangle(123, 58, 115, 54, 115, 62, WHITE);

        screen.display();
}

void state3(){
        screen.clearDisplay();

        // Line 1
        screen.setCursor(0, 0);
        screen.print("Water Level:");
        screen.setCursor(98, 0);
        screen.print("VAL");
    
        // Line 2
        screen.setCursor(0, 10);
        screen.print("Tank Refilled:");
        screen.setCursor(98, 10);
        screen.print("VAL");
    
        // Line 3
        screen.setCursor(0, 20);
        screen.print("Days On:");
        screen.setCursor(98, 20);
        screen.print("VAL");
        
        // Line 4
        screen.setCursor(0, 30);
        screen.print("<LINE 4>");
        screen.setCursor(98, 30);
        screen.print("VAL");

        // draw options menu on bottom
        screen.drawLine(0, 50, 128, 50, WHITE);
        screen.drawRect(45, 53, 38, 11, WHITE);
        screen.setCursor(53, 55);
        screen.print("MENU");
        screen.fillTriangle(5, 58, 13, 54, 13, 62, WHITE);
        screen.fillTriangle(123, 58, 115, 54, 115, 62, WHITE);

        screen.display();
}

void state4(){
        screen.clearDisplay();
  
        screen.setCursor(0, 0);
        screen.print("Select Plant:");

        screen.drawLine(0, 8, 128, 8, WHITE);

        screen.setTextColor(BLACK, WHITE);
        screen.setCursor(0, 12);
        screen.print("Plant 1");
        screen.setTextColor(WHITE, BLACK);

        screen.setCursor(0, 22);
        screen.print("Plant 2");

        screen.setCursor(0, 32);
        screen.print("Plant 3");

        screen.setCursor(0, 42);
        screen.print("Plant 4");

        // draw options menu on bottom
        screen.drawLine(0, 50, 128, 50, WHITE);
        screen.drawRect(45, 53, 38, 11, WHITE);
        screen.setCursor(50, 55);
        screen.print("ENTER");
        screen.fillTriangle(5, 62, 13, 62, 9, 54, WHITE);
        screen.fillTriangle(123, 54, 115, 54, 119, 62, WHITE);

        screen.display();
}

void state5(){
        screen.clearDisplay();
  
        screen.setCursor(0, 0);
        screen.print("[Main menu]");

        screen.drawLine(0, 8, 128, 8, WHITE);

        screen.setCursor(0, 12);
        screen.print("Select plant...");

        screen.setCursor(0, 22);
        screen.setTextColor(BLACK, WHITE);
        screen.print("Customize settings...");
        screen.setTextColor(WHITE, BLACK);

        // draw options menu on bottom
        screen.drawLine(0, 50, 128, 50, WHITE);
        screen.drawRect(45, 53, 38, 11, WHITE);
        screen.setCursor(50, 55);
        screen.print("ENTER");
        screen.fillTriangle(5, 62, 13, 62, 9, 54, WHITE);
        screen.fillTriangle(123, 54, 115, 54, 119, 62, WHITE);

        screen.display();
}

void state6(){
        screen.clearDisplay();
  
        screen.setCursor(0, 0);
        screen.print("Select Plant:");

        screen.drawLine(0, 8, 128, 8, WHITE);

        screen.setCursor(0, 12);
        screen.print("Plant 1");

        screen.setTextColor(BLACK, WHITE);
        screen.setCursor(0, 22);
        screen.print("Plant 2");
        screen.setTextColor(WHITE, BLACK);
        
        screen.setCursor(0, 32);
        screen.print("Plant 3");

        screen.setCursor(0, 42);
        screen.print("Plant 4");

        // draw options menu on bottom
        screen.drawLine(0, 50, 128, 50, WHITE);
        screen.drawRect(45, 53, 38, 11, WHITE);
        screen.setCursor(50, 55);
        screen.print("ENTER");
        screen.fillTriangle(5, 62, 13, 62, 9, 54, WHITE);
        screen.fillTriangle(123, 54, 115, 54, 119, 62, WHITE);

        screen.display();
}

void state7(){
        screen.clearDisplay();
  
        screen.setCursor(0, 0);
        screen.print("Select Plant:");

        screen.drawLine(0, 8, 128, 8, WHITE);

        screen.setCursor(0, 12);
        screen.print("Plant 1");

        screen.setCursor(0, 22);
        screen.print("Plant 2");

        screen.setTextColor(BLACK, WHITE);
        screen.setCursor(0, 32);
        screen.print("Plant 3");
        screen.setTextColor(WHITE, BLACK);
        
        screen.setCursor(0, 42);
        screen.print("Plant 4");

        // draw options menu on bottom
        screen.drawLine(0, 50, 128, 50, WHITE);
        screen.drawRect(45, 53, 38, 11, WHITE);
        screen.setCursor(50, 55);
        screen.print("ENTER");
        screen.fillTriangle(5, 62, 13, 62, 9, 54, WHITE);
        screen.fillTriangle(123, 54, 115, 54, 119, 62, WHITE);

        screen.display();
}

void state8(){
        screen.clearDisplay();
  
        screen.setCursor(0, 0);
        screen.print("Select Plant:");

        screen.drawLine(0, 8, 128, 8, WHITE);

        screen.setCursor(0, 12);
        screen.print("Plant 1");

        screen.setCursor(0, 22);
        screen.print("Plant 2");

        screen.setCursor(0, 32);
        screen.print("Plant 3");

        screen.setTextColor(BLACK, WHITE);
        screen.setCursor(0, 42);
        screen.print("Plant 4");
        screen.setTextColor(WHITE, BLACK);
        
        // draw options menu on bottom
        screen.drawLine(0, 50, 128, 50, WHITE);
        screen.drawRect(45, 53, 38, 11, WHITE);
        screen.setCursor(50, 55);
        screen.print("ENTER");
        screen.fillTriangle(5, 62, 13, 62, 9, 54, WHITE);
        screen.fillTriangle(123, 54, 115, 54, 119, 62, WHITE);

        screen.display();
}

void state9(){
        screen.clearDisplay();
  
        screen.setCursor(0, 0);
        screen.print("Select Plant:");

        screen.drawLine(0, 8, 128, 8, WHITE);

        screen.setTextColor(BLACK, WHITE);
        screen.setCursor(0, 12);
        screen.print("Plant 5");
        screen.setTextColor(WHITE, BLACK);

        screen.setCursor(0, 22);
        screen.print("Plant 6");

        screen.setCursor(0, 32);
        screen.print("Plant 7");

        screen.setCursor(0, 42);
        screen.print("Plant 8");

        // draw options menu on bottom
        screen.drawLine(0, 50, 128, 50, WHITE);
        screen.drawRect(45, 53, 38, 11, WHITE);
        screen.setCursor(50, 55);
        screen.print("ENTER");
        screen.fillTriangle(5, 62, 13, 62, 9, 54, WHITE);
        screen.fillTriangle(123, 54, 115, 54, 119, 62, WHITE);

        screen.display();
}

void state10(){
        screen.clearDisplay();
  
        screen.setCursor(0, 0);
        screen.print("Select Plant:");

        screen.drawLine(0, 8, 128, 8, WHITE);

        screen.setCursor(0, 12);
        screen.print("Plant 5");

        screen.setTextColor(BLACK, WHITE);
        screen.setCursor(0, 22);
        screen.print("Plant 6");
        screen.setTextColor(WHITE, BLACK);
        
        screen.setCursor(0, 32);
        screen.print("Plant 7");

        screen.setCursor(0, 42);
        screen.print("Plant 8");

        // draw options menu on bottom
        screen.drawLine(0, 50, 128, 50, WHITE);
        screen.drawRect(45, 53, 38, 11, WHITE);
        screen.setCursor(50, 55);
        screen.print("ENTER");
        screen.fillTriangle(5, 62, 13, 62, 9, 54, WHITE);
        screen.fillTriangle(123, 54, 115, 54, 119, 62, WHITE);

        screen.display();
}

void state11(){
        screen.clearDisplay();
  
        screen.setCursor(0, 0);
        screen.print("Select Plant:");

        screen.drawLine(0, 8, 128, 8, WHITE);

        screen.setCursor(0, 12);
        screen.print("Plant 5");

        screen.setCursor(0, 22);
        screen.print("Plant 6");

        screen.setTextColor(BLACK, WHITE);
        screen.setCursor(0, 32);
        screen.print("Plant 7");
        screen.setTextColor(WHITE, BLACK);
        
        screen.setCursor(0, 42);
        screen.print("Plant 8");

        // draw options menu on bottom
        screen.drawLine(0, 50, 128, 50, WHITE);
        screen.drawRect(45, 53, 38, 11, WHITE);
        screen.setCursor(50, 55);
        screen.print("ENTER");
        screen.fillTriangle(5, 62, 13, 62, 9, 54, WHITE);
        screen.fillTriangle(123, 54, 115, 54, 119, 62, WHITE);

        screen.display();
}

void state12(){
        screen.clearDisplay();
  
        screen.setCursor(0, 0);
        screen.print("Select Plant:");

        screen.drawLine(0, 8, 128, 8, WHITE);

        screen.setCursor(0, 12);
        screen.print("Plant 5");

        screen.setCursor(0, 22);
        screen.print("Plant 6");

        screen.setCursor(0, 32);
        screen.print("Plant 7");

        screen.setTextColor(BLACK, WHITE);
        screen.setCursor(0, 42);
        screen.print("Plant 8");
        screen.setTextColor(WHITE, BLACK);
        
        // draw options menu on bottom
        screen.drawLine(0, 50, 128, 50, WHITE);
        screen.drawRect(45, 53, 38, 11, WHITE);
        screen.setCursor(50, 55);
        screen.print("ENTER");
        screen.fillTriangle(5, 62, 13, 62, 9, 54, WHITE);
        screen.fillTriangle(123, 54, 115, 54, 119, 62, WHITE);

        screen.display();
}

void state15(){
        screen.clearDisplay();

        screen.setCursor(0, 0);
        screen.print("Selected Plant:");

        screen.setCursor(0, 10);
        screen.print("PLANT NAME");

        screen.display();

        delay(1000);
}

void state20(){
        screen.clearDisplay();
  
        screen.setCursor(0, 0);
        screen.print("[Settings Menu]");

        screen.drawLine(0, 8, 128, 8, WHITE);

        screen.setTextColor(BLACK, WHITE);
        screen.setCursor(0, 12);
        screen.print("Light Settings");
        screen.setTextColor(WHITE, BLACK);

        screen.setCursor(0, 22);
        screen.print("Moisture Settings");

        screen.setCursor(0, 32);
        screen.print("Watering Settings");

        //screen.setCursor(0, 42);
        //screen.print("Option 4");

        // draw options menu on bottom
        screen.drawLine(0, 50, 128, 50, WHITE);
        screen.drawRect(45, 53, 38, 11, WHITE);
        screen.setCursor(50, 55);
        screen.print("ENTER");
        screen.fillTriangle(5, 62, 13, 62, 9, 54, WHITE);
        screen.fillTriangle(123, 54, 115, 54, 119, 62, WHITE);

        screen.display();
}

void state21(){
        screen.clearDisplay();
  
        screen.setCursor(0, 0);
        screen.print("[Settings Menu]");

        screen.drawLine(0, 8, 128, 8, WHITE);

        screen.setCursor(0, 12);
        screen.print("Light Settings");

        screen.setTextColor(BLACK, WHITE);
        screen.setCursor(0, 22);
        screen.print("Moisture Settings");
        screen.setTextColor(WHITE, BLACK);
        
        screen.setCursor(0, 32);
        screen.print("Watering Settings");

        //screen.setCursor(0, 42);
        //screen.print("Option 4");

        // draw options menu on bottom
        screen.drawLine(0, 50, 128, 50, WHITE);
        screen.drawRect(45, 53, 38, 11, WHITE);
        screen.setCursor(50, 55);
        screen.print("ENTER");
        screen.fillTriangle(5, 62, 13, 62, 9, 54, WHITE);
        screen.fillTriangle(123, 54, 115, 54, 119, 62, WHITE);

        screen.display();
}

void state22(){
        screen.clearDisplay();
  
        screen.setCursor(0, 0);
        screen.print("[Settings Menu]");

        screen.drawLine(0, 8, 128, 8, WHITE);

        screen.setCursor(0, 12);
        screen.print("Light Settings");

        screen.setCursor(0, 22);
        screen.print("Moisture Settings");

        screen.setTextColor(BLACK, WHITE);
        screen.setCursor(0, 32);
        screen.print("Watering Settings");
        screen.setTextColor(WHITE, BLACK);
        
        //screen.setCursor(0, 42);
        //screen.print("Option 4");

        // draw options menu on bottom
        screen.drawLine(0, 50, 128, 50, WHITE);
        screen.drawRect(45, 53, 38, 11, WHITE);
        screen.setCursor(50, 55);
        screen.print("ENTER");
        screen.fillTriangle(5, 62, 13, 62, 9, 54, WHITE);
        screen.fillTriangle(123, 54, 115, 54, 119, 62, WHITE);

        screen.display();
}

void state25(){
        screen.clearDisplay();
  
        screen.setCursor(0, 0);
        screen.print("[../Light Settings]");

        screen.drawLine(0, 8, 128, 8, WHITE);

        // Draw arrows (86, 122), y value changes
        screen.drawTriangle(87, 15, 92, 12, 92, 18, WHITE);
        screen.drawTriangle(127, 15, 122, 12, 122, 18, WHITE);
        
        // Draw labels
        screen.setTextColor(BLACK, WHITE);
        screen.setCursor(0, 12);
        screen.print("Light Hours:");
        screen.setTextColor(WHITE, BLACK);

        screen.setCursor(0, 22);
        screen.print("RED %:");

        screen.setCursor(0, 32);
        screen.print("BLUE %:");

        // Draw values
        screen.setCursor(98, 12);
        screen.print("VAL");

        screen.setCursor(98, 22);
        screen.print("VAL");

        screen.setCursor(98, 32);
        screen.print("VAL");

        //screen.setCursor(0, 42);
        //screen.print("Option 4");

        // draw options menu on bottom
        screen.drawLine(0, 50, 128, 50, WHITE);
        
        screen.drawRect(45, 53, 38, 11, WHITE);
        screen.setCursor(50, 55);
        screen.print(" SUB ");

        screen.drawRect(89, 53, 38, 11, WHITE);
        screen.setCursor(94, 55);
        screen.print(" ADD ");
        
        screen.fillTriangle(5, 54, 13, 54, 9, 62, WHITE);

        screen.display();
}

void state26(){
        screen.clearDisplay();
  
        screen.setCursor(0, 0);
        screen.print("[../Light Settings]");

        screen.drawLine(0, 8, 128, 8, WHITE);

        // Draw arrows (86, 122), y value changes
        screen.drawTriangle(87, 25, 92, 22, 92, 28, WHITE);
        screen.drawTriangle(127, 25, 122, 22, 122, 28, WHITE);
        
        // Draw labels
        screen.setCursor(0, 12);
        screen.print("Light Hours:");

        screen.setTextColor(BLACK, WHITE);
        screen.setCursor(0, 22);
        screen.print("RED %:");
        screen.setTextColor(WHITE, BLACK);
        
        screen.setCursor(0, 32);
        screen.print("BLUE %:");

        // Draw values
        screen.setCursor(98, 12);
        screen.print("VAL");

        screen.setCursor(98, 22);
        screen.print("VAL");

        screen.setCursor(98, 32);
        screen.print("VAL");

        //screen.setCursor(0, 42);
        //screen.print("Option 4");

        // draw options menu on bottom
        screen.drawLine(0, 50, 128, 50, WHITE);
        
        screen.drawRect(45, 53, 38, 11, WHITE);
        screen.setCursor(50, 55);
        screen.print(" SUB ");

        screen.drawRect(89, 53, 38, 11, WHITE);
        screen.setCursor(94, 55);
        screen.print(" ADD ");
        
        screen.fillTriangle(5, 54, 13, 54, 9, 62, WHITE);

        screen.display();
}

void state27(){
        screen.clearDisplay();
  
        screen.setCursor(0, 0);
        screen.print("[../Light Settings]");

        screen.drawLine(0, 8, 128, 8, WHITE);

        // Draw arrows (86, 122), y value changes
        screen.drawTriangle(87, 35, 92, 32, 92, 38, WHITE);
        screen.drawTriangle(127, 35, 122, 32, 122, 38, WHITE);
        
        // Draw labels
        screen.setCursor(0, 12);
        screen.print("Light Hours:");

        screen.setCursor(0, 22);
        screen.print("RED %:");

        screen.setTextColor(BLACK, WHITE);
        screen.setCursor(0, 32);
        screen.print("BLUE %:");
        screen.setTextColor(WHITE, BLACK);
        
        // Draw values
        screen.setCursor(98, 12);
        screen.print("VAL");

        screen.setCursor(98, 22);
        screen.print("VAL");

        screen.setCursor(98, 32);
        screen.print("VAL");

        //screen.setCursor(0, 42);
        //screen.print("Option 4");

        // draw options menu on bottom
        screen.drawLine(0, 50, 128, 50, WHITE);
        
        screen.drawRect(45, 53, 38, 11, WHITE);
        screen.setCursor(50, 55);
        screen.print(" SUB ");

        screen.drawRect(89, 53, 38, 11, WHITE);
        screen.setCursor(94, 55);
        screen.print(" ADD ");
        
        screen.fillTriangle(5, 54, 13, 54, 9, 62, WHITE);

        screen.display();
}
