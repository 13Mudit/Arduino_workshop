// Code to define the pin at which ldr will be attached
const int ldr_pin = A3;

// Code to define a variable which will hold the value of the ldr
int ldr_value;

// Code to define the pin at which buzzer will be attached
const int buzzer_pin = 9;

/*
    Prototype of a User Defined Function to make
    the Buzzer Beep at a certain rate
*/
void buzzer_beep(int ldr_input);

void setup()
{
    /*
        Here even though we are using analogWrite() our buzzer will still be attached
        to a digital pin hence unlike analogRead() we need to define OUTPUT pinMOde.
    */
    pinMode(buzzer_pin, OUTPUT);
}
void loop()
{
    /*
        analogRead(pin) is the function to
        read a sensor attached to an Analog Pin
    */
    ldr_value = analogRead(ldr_pin);

    /*
        Function Call to the buzzer_beep()
        with ldr_value as a parameter.
    */
    buzzer_beep(ldr_value);

}

void buzzer_beep(int ldr_input)
{
    /*
        Our goal with this function is to make
        buzzer beep with a certain beep rate.

        We want the buzzer beep faster if there
        is more light on the LDR and beep slower
        if less light on the LDR.

        Buzzer Beeping is similar to LED blinking
        We turn it on, wait for a certain time delay
        and then turn it on.

        Here we use the map function to convert the
        LDR sensor value to a time delay. Here we
        want a higher delay for a lower value which
        will cause a slower beep rate and similarly
        a lower delay for a higher sensor value which
        will cause a higher beep rate.

        Therefore we map values from 0 - 1023 to 800 - 100
    */
    int time_delay = map(ldr_input, 0, 1023, 800, 100);

    /*
        Commands to make a Buzzer Beep blink
    */
    digitalWrite(buzzer_pin, HIGH);
    delay(time_delay);
    digitalWrite(buzzer_pin, LOW);
    delay(time_delay);
}
