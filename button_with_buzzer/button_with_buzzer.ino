
/*
    Code to define the pins being 
    used we use "const" because
    these values will never change 
*/
const int buzzer_pin = 3;
const int button_pin = 4;

void setup()
{
    /*
        Here we define how each pin
        will be used for either
        reading(INPUT) or writing(OUTPUT).
    */
    pinMode(button_pin, INPUT);
    pinMode(buzzer_pin, OUTPUT);
}

void loop()
{
    /*
        Function call to read the
        value at the button_pin to
        check if the button is pressed.
     */   
    int button_input = digitalRead(button_pin);

    /*  
        if the button_input is LOW we assume button
        is pressed which means a PULLED UP Configuration.
    */
    if(button_input == LOW)
    {
        // Playing the Buzzer if button is pressed.
        digitalWrite(buzzer_pin, HIGH);
    }
    /*
        Button released go back to high
        as it is in PULL UP configuration.
    */
    else if(button_pin == HIGH)
    {
        // Turn the Buzzer when button is released.
        digitalWrite(buzzer_pin, LOW);        
    }
}
