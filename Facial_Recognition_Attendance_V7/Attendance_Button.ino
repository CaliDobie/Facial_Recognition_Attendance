int PUSH_BUTTON = 2;
//int time = 1000*1;  //set delay time in seconds

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(PUSH_BUTTON, INPUT_PULLUP);
  Serial.begin(9600);
}

enum States {START, INIT, PRESS, DEPRESS} state;
int input;

void loop() {
  switch (state) 
  {
    case START:
      digitalWrite(LED_BUILTIN, LOW);  //led off
      state = INIT;
      break;

    case INIT:
      digitalWrite(LED_BUILTIN, LOW);  //led off
      if (digitalRead(PUSH_BUTTON) == LOW)  //button press
      {
        state = PRESS;
      } 
      if (digitalRead(PUSH_BUTTON) == HIGH)  //button unpress 
      {
        state = INIT;
      }
      break;

    case PRESS:
      digitalWrite(LED_BUILTIN, LOW);  //led off
      if (digitalRead(PUSH_BUTTON) == HIGH)  //button unpress
      {
        state = DEPRESS;
      } 
      if (digitalRead(PUSH_BUTTON) == LOW)  //button press 
      {
        state = PRESS;
      }
      break;

    case DEPRESS:
      digitalWrite(LED_BUILTIN, HIGH);  //led on
      Serial.write('a');
      //delay(time);
      input = Serial.readString().toInt();
      if (input == 0)
      {
        state = INIT;
      }
      break;

    default:
      break;
  }
}