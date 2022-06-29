/*
 * Written by Mudit Aggarwal at TI-CEPD, NSUT
 * on 27th June, 2022
 * 
 * A game to memorize and recall sequence of LED blinks
 * 
*/

const int led_1 = 6;
const int led_2 = 7;
const int led_3 = 8;

const int button_1 = 3;
const int button_2 = 4;
const int button_3 = 5;

const int win_led = 9;
const int lose_led = 10;

const int led_on_delay = 500; //ms

const int sequence_size = 3;

int sequence[sequence_size];
int sequence_index;

bool button_pressed;

void setup() {
  pinMode(led_1, OUTPUT);
  pinMode(led_2, OUTPUT);
  pinMode(led_3, OUTPUT);

  pinMode(button_1, INPUT);
  pinMode(button_2, INPUT);
  pinMode(button_3, INPUT);

  pinMode(win_led, OUTPUT);
  pinMode(lose_led, OUTPUT);

  for(int i=0; i<sequence_size; i++){
    sequence[i] = random(1, 4);

    switch(sequence[i]){
      case 1: digitalWrite(led_1, HIGH);
              delay(led_on_delay);
              digitalWrite(led_1, LOW);
              delay(led_on_delay);
              break;
      case 2: digitalWrite(led_2, HIGH);
              delay(led_on_delay);
              digitalWrite(led_2, LOW);
              delay(led_on_delay);
              break;
      case 3: digitalWrite(led_3, HIGH);
              delay(led_on_delay);
              digitalWrite(led_3, LOW);
              delay(led_on_delay);
              break;
      default:  break;
    }
  }

  sequence_index = 0;  
  button_pressed = false;
}

void loop() {
  int button_1_input = digitalRead(button_1);
  int button_2_input = digitalRead(button_2);
  int button_3_input = digitalRead(button_3);

  
  if(sequence[sequence_index] == 1 && !button_pressed){
    if(button_1_input == LOW){
      sequence_index++;
      button_pressed = true;
    }
    else if(button_2_input == LOW || button_3_input == LOW){
      digitalWrite(lose_led, HIGH); //Player loses
    }
  }
  if(sequence[sequence_index] == 2 && !button_pressed){
    if(button_2_input == LOW){
      sequence_index++;
      button_pressed = true;
    }
    else if(button_1_input == LOW || button_3_input == LOW){
      digitalWrite(lose_led, HIGH); //Player loses
    }
  }
  if(sequence[sequence_index] == 3 && !button_pressed){
    if(button_3_input == LOW){
      sequence_index++;
      button_pressed = true;
    }
    else if(button_1_input == LOW || button_2_input == LOW){
      digitalWrite(lose_led, HIGH); //Player loses
    }
  }


  if(button_1_input == HIGH && button_2_input == HIGH && button_3_input == HIGH){
    button_pressed = false;
  }

  
  if(sequence_index >= sequence_size){
    digitalWrite(win_led, HIGH);  //Player Won
  }
}
