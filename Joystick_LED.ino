
// Name the pins

int JOYSTICK_X = A0;
int JOYSTICK_Y = A1;
int LED_UP = 3;
int LED_DOWN = 5;
int LED_LEFT = 6;
int LED_RIGHT = 9;

void setup () {
  // Analog inputs do not require initialization
  pinMode(LED_UP, OUTPUT);
  pinMode(LED_DOWN, OUTPUT);
  pinMode(LED_LEFT, OUTPUT);
  pinMode(LED_RIGHT, OUTPUT);
}

void loop () {
  // The joystick module is not perfectly centered, its "idle state" is between 450 and 550
  
  if(analogRead(JOYSTICK_Y) < 450) {
    analogWrite(LED_DOWN, map(analogRead(JOYSTICK_Y), 450, 0, 0, 255)); 
  } else if (analogRead(JOYSTICK_Y) > 550){
    analogWrite(LED_UP, map(analogRead(JOYSTICK_Y), 550, 1023, 0, 255));
  }
  if(analogRead(JOYSTICK_X) < 450) {
    analogWrite(LED_LEFT, map(analogRead(JOYSTICK_X), 450, 0, 0, 255)); 
  } else if (analogRead(JOYSTICK_X) > 550){
    analogWrite(LED_RIGHT, map(analogRead(JOYSTICK_X), 550, 1023, 0, 255));
  }
}
