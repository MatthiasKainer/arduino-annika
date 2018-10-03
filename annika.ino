#include "core/sensor.cpp"
#include "core/converter.cpp"
#include "core/drive.cpp"

unsigned long moveUntil = 0;
Direction toMove;

const unsigned char MOTOR_A = 3;
const unsigned char  MOTOR_B = 11;
const unsigned char  DIR_A = 12;
const unsigned char  DIR_B = 13;
const unsigned char  BREAK_A = 9;
const unsigned char  BREAK_B = 8;
const Sensor sensor(5, 6);
const Drive drive({ MOTOR_A, DIR_A, BREAK_A }, {MOTOR_B, DIR_B, BREAK_B});

void setup()
{
    Serial.begin(9600);
    drive.setup();
    Serial.println("Hello I am Annika. I will search you. And then run away.");
    Serial.println(":)");
}

void loop()
{
    // get time in ms since last run
    unsigned long now = millis();
    Serial.print("start loop: ");
    Serial.println(millis());
    if (now < moveUntil)
    {
        switch (toMove)
        {
        case LEFT:
            drive.left();
            break;
        case RIGHT:
            drive.right();
            break;
        default:
            moveUntil = now - 1;
            break;
        }

        return;
    }
        
    Serial.print("after repeat: ");
    Serial.println(millis());

    Range range = convert(sensor.readDistance());

    Serial.print("after read distance: ");
    Serial.println(millis());

    switch (range)
    {
    case OK:
        drive.fast();
        break;
    case WARN:
        drive.slow();
        break;
    case ERROR:
        moveUntil = now + random(50, 300);
        toMove = random(0, 2) > 0 ? LEFT : RIGHT;
        break;
    }

    Serial.print("end loop: ");
    Serial.println(millis());
}
