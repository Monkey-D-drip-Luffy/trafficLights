/* Project_5B_Start_1738 
This code will turn on lights in the order of left to right
*/
#define westGreen 5  // This is the pin assinments
#define westYellow 6
#define westRed 2
#define westButton 3

#define cross_button 4  // press to cross

#define eastGreen 10
#define eastYellow 11
#define eastRed 12
#define eastButton 13

#define yellowBlinkTime 500

boolean trafficWest = true;  // west = true, east = false
int flowTime = 10000;
int changeDelay = 2000;



void setup() {
  pinMode(westButton, INPUT);
  pinMode(eastButton, INPUT);
  pinMode(westRed, OUTPUT);
  pinMode(westYellow, OUTPUT);
  pinMode(westGreen, OUTPUT);
  pinMode(eastRed, OUTPUT);
  pinMode(eastYellow, OUTPUT);
  pinMode(eastGreen, OUTPUT);

  digitalWrite(westRed, LOW);
  digitalWrite(westYellow, LOW);
  digitalWrite(westGreen, HIGH);
  digitalWrite(eastRed, HIGH);
  digitalWrite(eastYellow, LOW);
  digitalWrite(eastGreen, LOW);
}

void loop() {
  if (digitalRead(westButton) == HIGH) {
    if (trafficWest != true) {
      trafficWest = true;
      delay(flowTime);



      /* digitalWrite(eastGreen, LOW);
      digitalWrite(eastYellow, HIGH);
      delay(changeDelay);
      digitalWrite(eastYellow, LOW);
      digitalWrite(eastRed, HIGH);
*/
      changeGreentoRed(eastGreen, eastYellow, eastRed);

      delay(changeDelay);
      /* for (int a = 0; a < 5; a++) {
           digitalWrite(westYellow, LOW);
        delay(yellowBlinkTime);
        digitalWrite(westYellow, HIGH);
        delay(yellowBlinkTime);
  */
      changeYellowLight(westYellow);

      /*digitalWrite(westYellow, LOW);
      digitalWrite(westRed, LOW);
      digitalWrite(westGreen, HIGH);*/
      changetoGreen(westGreen, westYellow, westRed);
    }
  }
  if (digitalRead(eastButton) == HIGH) {
    if (trafficWest == true) {
      trafficWest = false;
      delay(flowTime);
      /*digitalWrite(westGreen, LOW);
      digitalWrite(westYellow, HIGH);
      delay(changeDelay);
      digitalWrite(westYellow, LOW);
      digitalWrite(westRed, HIGH);*/
      changeGreentoRed(westGreen, westYellow, westRed);
      delay(changeDelay);
    }
    /*  for (int a = 0; a < 5; a++) {
          digitalWrite(eastYellow, LOW);
          delay(yellowBlinkTime);
          digitalWrite(eastYellow, HIGH);
          delay(yellowBlinkTime);
        } */

    changeYellowLight(eastYellow);
    /* digitalWrite(eastYellow, LOW);
      digitalWrite(eastRed, LOW);
      digitalWrite(eastGreen, HIGH);*/

    changetoGreen(eastGreen, eastYellow, eastRed);

    (digitalRead(cross_button) == HIGH);
    {
      cross_traiffic(eastGreen, eastYellow, eastRed);
    }
  }
  if (digitalRead(cross_button) == HIGH) {
   if ((trafficWest) == HIGH) // turn off westGreen
    delay(changeDelay);
  changeGreentoRed(eastGreen, eastYellow, eastRed);
  changeGreentoRed(westGreen, westYellow, westRed);
  
  
    // turn on pedestrian light

    // turn off pedestrian light
  }
}


void changeYellowLight(int yellowDirection) {  // yellow funtions
  for (int a = 0; a < 5; a++) {
    digitalWrite(yellowDirection, LOW);
    delay(yellowBlinkTime);
    digitalWrite(yellowDirection, HIGH);
    delay(yellowBlinkTime);
  }
}


void changeGreentoRed(int green, int yellow, int red) {  // green to red funtions
  digitalWrite(green, LOW);
  digitalWrite(yellow, HIGH);
  delay(changeDelay);
  /*digitalWrite(yellow, LOW);
  digitalWrite(yellow, HIGH); */
  delay(changeDelay);
  digitalWrite(red, HIGH);
}

void changetoGreen(int green, int yellow, int red) {  // green funtions
  digitalWrite(yellow, LOW);
  digitalWrite(red, LOW);
  digitalWrite(green, HIGH);
}

void cross_traiffic(int green, int yellow, int red) {  // button press
  digitalWrite(yellow, LOW);
  digitalWrite(red, HIGH);
  digitalWrite(green, LOW);
}
