
// Nombro los pines

int JOYSTICK_X = A0;
int JOYSTICK_Y = A1;
int LED_ARRIBA = 3;
int LED_ABAJO = 5;
int LED_IZQ = 6;
int LED_DER = 9;

void setup () {
  // Las entradas analógicas no necesitan inicialización
  pinMode(LED_ARRIBA, OUTPUT);
  pinMode(LED_ABAJO, OUTPUT);
  pinMode(LED_IZQ, OUTPUT);
  pinMode(LED_DER, OUTPUT);
}

void loop () {
  // El módulo joystick no se centra perfectamente, su "estado de reposo" se encuentra entre 450 y 550
  
  if(analogRead(JOYSTICK_Y) < 450) {
    analogWrite(LED_ABAJO, map(analogRead(JOYSTICK_Y), 450, 0, 0, 255)); // map(valor leido, "cero", "final", "inicio led", "fin led")
  } else if (analogRead(JOYSTICK_Y) > 550){
    analogWrite(LED_ARRIBA, map(analogRead(JOYSTICK_Y), 550, 1023, 0, 255));
  }
  if(analogRead(JOYSTICK_X) < 450) {
    analogWrite(LED_IZQ, map(analogRead(JOYSTICK_X), 450, 0, 0, 255)); // map(valor leido, "cero", "final", "inicio led", "fin led")
  } else if (analogRead(JOYSTICK_X) > 550){
    analogWrite(LED_DER, map(analogRead(JOYSTICK_X), 550, 1023, 0, 255));
  }
}
