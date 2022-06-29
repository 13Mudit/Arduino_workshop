// Code to define the pin at which potentiometer will be attached
const int potentiometer_pin = A3;

// Code to define a variable which will hold the value of the potentiometer
int potentiometer_value;

void setup()
{
    /*
        This is a function call to tell Arduino
        and the computer to start Serial Communication.

        Here the paramater "9600" is the rate at which
        data bits will be coming and the Arduino IDE will
        show you the values based on this rate.
    */
    Serial.begin(9600);
    /*
        Do notice that we have not called pinMode(potentiometer_pin, INPUT)
        we do not need to tell INPUT or OUTPUT for analog pins as they will
        only be used for taking INPUT. 
     */
}

void loop()
{
    /*
        analogRead(pin) is the function to
        read a sensor attached to an Analog Pin
    */
    potentiometer_value = analogRead(potentiometer_pin);

    /*
        This is the code to print anything on the
        Serial Monitor. Here you will see values 
        in the range of 0 - 1023 as the Arduino
        Nano has a 10-bit ADC and 2^10 = 1024
        possible number of values
    */
    Serial.println(potentiometer_value);
}
