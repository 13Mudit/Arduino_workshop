/*
  Written by Mudit Aggarwal at TI-CEPD, NSUT
  on 27th June, 2022
  To convert text to morse and give output with a buzzer and LED

  the const string text is converted to morse character by character
  using the lookup table, the resultant string, comprising of . and - is then
  output using LED and(or) buzzer as per following

  dit (dot -> . ) => a singular pulse duration specified in morse_delay variable
  dah (dash-> - ) => continous high pulse of duration equivalent to 3 dits

  delay between two consecutive morse characters => duration equivalent to 1 dit
  delay between two consecutive letters => duration equivalent to 3 dits
  delay between two consecutive words => duration equivalent to 5 dits
*/

//Duration of 1 dit, determines speed of morse transmission
const int morse_delay = 500; //ms

//Pin specifications
const int buzzer_pin = 6;
const int led_pin = 13;

//text to be converted to morse
const char* text = "sos";
int index;  //will hold index of current letter being converted in text


//morse code for 26 letters
const char* morse[] = {
                       ".-",    //a
                       "-...",  //b
                       "-.-.",  //c
                       "-..",   //d
                       ".",     //e
                       "..-.",  //f
                       "--.",   //g
                       "....",  //h
                       "..",    //i
                       ".---",  //j
                       "-.-",   //k
                       ".-..",  //l
                       "--",    //m
                       "-.",    //n
                       "---",   //o
                       ".--.",  //p
                       "--.-",  //q
                       ".-.",   //r
                       "...",   //s
                       "-",     //t
                       "..-",   //u
                       "...-",  //v
                       ".--",   //w
                       "-..-",  //x
                       "-.--",  //y
                       "--.."   //z
                      };


void dit(){
  digitalWrite(led_pin, HIGH);
  digitalWrite(buzzer_pin, HIGH);
  delay(morse_delay);
  digitalWrite(led_pin, LOW);
  digitalWrite(buzzer_pin, LOW);
  delay(morse_delay);
}

void dah(){
  digitalWrite(led_pin, HIGH);
  digitalWrite(buzzer_pin, HIGH);
  delay(3*morse_delay);           //Duration 3 * dit
  digitalWrite(led_pin, LOW);
  digitalWrite(buzzer_pin, LOW);
  delay(morse_delay);
}


void setup() {
  //Setting up pins as output
  pinMode(buzzer_pin, OUTPUT);
  pinMode(led_pin, OUTPUT);

  //initialize index
  index = 0;
}

void loop() {
  if(text[index] == '\0'){  //Strings are terminated by default by \0(Null character)
    //Extra delay at the end of Word
    delay(2*morse_delay);

    //reset the index to 0
    index = 0;
  }
  
  char current_char = text[index];  //get characer to decode

  //**implicit character to integer conversion**
  int morse_index = current_char - 'a'; //get the characters index in the morse lookup table

  //loop over morse representation of current character and call dit and dah accordingly
  for(int i=0; morse[morse_index][i] != '\0'; i++){ //loop until we reach end of our morse representation string
    if(morse[morse_index][i] == '.'){
      dit();
    }
    else if(morse[morse_index][i] == '-'){
      dah();
    }
  }
  delay(3*morse_delay); //delay between 2 consecutive letters

  index++;  //increment index
}
