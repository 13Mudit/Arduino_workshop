// Code to define the pin at which potentiometer will be attached
const int potentiometer_pin = A3;

// Code to define a variable which will hold the value of the potentiometer
int potentiometer_value;

// Code to define the pin at which LED will be attached
const int led_pin = 9;

// Code to define a variable which will hold the value for the LED to output
int led_output_value;

void setup()
{
    /*
        Here even though we are using analogWrite() our LED will still be attached
        to a digital pin hence unlike analogRead() we need to define OUTPUT pinMOde.
    */
    pinMode(led_pin, OUTPUT);
}
void loop()
{
    /*
        analogRead(pin) is the function to
        read a sensor attached to an Analog Pin
    */
    potentiometer_value = analogRead(potentiometer_pin);

    /*
        The arduino ADC is 10-bit hence it gives value
        in range 0 - 1023 but the PWM output is only 8-bit
        so we need to convert or map our potentiometer value
        from 0 - 1023(2^10 = 1024) to 0 - 255(2^8 = 256) to
        use for analog output on the LED.

        map(value, old_min, old_max, new_min, new_max)
    */
    led_output_value = map(potentiometer_value, 0, 1023, 0, 255);

    /*
        Now after getting the led_output_value we call
        analogWrite() function with corresponding pin
        and the value to use.

        This will output a Square Wave based on the given
        input of a certain Duty Cycle with 0 as 0%
        and 255 as 100%
    */
    analogWrite(led_pin, led_output_value);

}
