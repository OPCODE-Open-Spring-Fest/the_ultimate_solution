// SMART HOME AUTOMATION AND SECURITY
// TASKS - USE SENSORS(TEMP, HUMIDITY, GAS, LIGHT) , KEYPAD , LCD , SERVO MOTOR .
// Include all required libraries for the tasks you infer from the provided task.
#include <Arduino.h> 
#include<keypad.h>
#include<string.h>
// initialize object for liquidcrystal library and define pins

// define pins for gas sensor,buzzer,temperature and humidity sensor and servo.
 
const byte ROWS = 4; // define number of rows for the keypad
const byte COLS = 4; // define number of columns for the keypad
// define pins for keypad
byte rowPins[ROWS] = {13,12,11,10};
byte colPins[COLS] = {7,6,5,4};

#define Password_Length  5          // define password length
char Data[Password_Length];             // variable to store entered password
char Master[Password_Length] = "12345"; // set your password here in any variable.
byte data_count = 0, master_count = 5;  // count password characters(entered and preset);
bool Pass_is_good;
bool door = false;
char customKey;
#define buzzerPin 9;
// define the values of each buttons of the keyboard.
char keys[ROWS][COLS] ={{'1','2','3','A'}
                        {'4','5','6','B'}
                        {'7','8','9','C'}
                        {'*','0','#','D'}
                        };
Keypad customKeypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );
void setup()
{
    //initialize all required parameters and objects to complete the task.
    for(int i=0;i<ROWS;i++){
      pinMode(rowPins[i],INPUT);
    }
    for(int i=0;i<COLS;i++){
      pinMode(colPins[i],INPUT);
    }
    pinMode(buzzerPin,OUTPUT);
    Serial.begin(9600);                       
    //print on LCD "THE ULTIMATE AUTOMATION AND SECURITY SYSTEM" once.
}

void loop()
{
    // Secure door using password unlocking.
    if (door == true)
    {
        customKey = customKeypad.getKey(); // Take input using appropriate function
        if (customKey == '#')
            door = false;
    }
    else
        Open();

    // Read temperature and humidity values from the sensor
    float temperature = ; // Read temperature in Celsius.
    float humidity = ;    // Read humidity as percentage.
    // Check if any reading failed(unable to read) and exit (to try again)
    if ()
    {
        Serial.println("reading failed");
        return;
    }
    delay(); // Wait for 1 seconds between readings

    // print readings from sensor on lcd.

    // Read smoke/co2 level from the sensor
    float gasval;
    gasval = ;
    // map ideal reading of gas sensor per cent.
    // Print the Gas intensity value on LCD.

    // Read light intensity from the sensor
    // Print the light intensity value

    // SET ALL ALERTS ON A BUZZER -->CHANGE FREQUENCY OF ALERTS FOR CHANGING VALUE OF INTENSITIES.
    if (temperature > 50 && temperature < 60)

    else if (temperature > 60 && temperature < 90)
    tone(temppin, 1800, 1000);

    else if (temperature > 90)

    if (gasval > 10 && gasval < 30)

    else if (gasval > 30 && gasval < 70)

    else if (gasval > 70)
    tone(gaspin, 3000, 1000);

    if (humidity > 50 && humidity < 60)

    else if (humidity > 60 && humidity < 80)

    else if (humidity > 80)
}
// function to open the gate by rotating servo if correct password entered.

void Open()
{
    customKey = customKeypad.getKey(); // take input using appropriate function.
    if (customKey)
    {

      Data[data_count] = customKey;
      //alter value of data_count every time a input is received.
      data_count++;

    }

    // compare the entered password with preset password
    if (data_count == Password_Length )
    {
        if (!strcmp(Data, Master)) // if password is true
        {
             // Mention function to open the door using servo.
             ServoOpen();
            door = true; // set value of door(bool type) as open.
            delay(1000); //give some delay
        }
        else // mention circumstances after entering wrong password.
        {
             // beep alarm once
             tone(buzzerPin,1000,1000)
             //set value of door(bool type) as close.
             door=false;
        }
        delay(1000);

         //Mention function to clear the entered data.
        clearData();
    }
}

//  function to open the gate using servo.
void ServoOpen()
{
    
}
//  function to clear the entered data.
void clearData()
{
    while (data_count != 0)
    {
        Data[data_count--] = 0;
    }
    return;
}

