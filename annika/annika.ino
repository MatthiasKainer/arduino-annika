#include "core/sonicSensor.cpp"
#include "core/converter.cpp"
#include "core/drive.cpp"
#include "core/irSensor.cpp"

unsigned long moveUntil = 0;
Direction toMove;

const unsigned char MOTOR_A = 3;
const unsigned char  MOTOR_B = 11;
const unsigned char  DIR_A = 12;
const unsigned char  DIR_B = 13;
const unsigned char  BREAK_A = 9;
const unsigned char  BREAK_B = 8;
const SonicSensor sonicSensor(5, 6);
const IRSensor ir(11, 12, 13);
const Drive drive({ MOTOR_A, DIR_A, BREAK_A }, {MOTOR_B, DIR_B, BREAK_B});

void setup()
{
    Serial.begin(9600);
    drive.setup();
    ir.setup();
    sonicSensor.setup();
    Serial.println("Hello I am Annika. I will search you. And then run away.");
    Serial.println(":)");
}

void actRandomly() {
    moveUntil = millis() + random(50, 300);
    toMove = random(0, 2) > 0 ? LEFT : RIGHT;
}

void logTimeElapsed(String message) {
    Serial.print(message + ": ");
    Serial.println(millis());
}

void loop()
{
    // get time in ms since last run
    unsigned long now = millis();
    logTimeElapsed("start loop");

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
    logTimeElapsed("after repeat");

    if (ir.collision()) {
        actRandomly();
        ir.resolve();
        return;
    }
    
    Range range = convert(sonicSensor.readDistance());
    logTimeElapsed("after read distance");

    switch (range)
    {
    case OK:
        drive.fast();
        break;
    case WARN:
        drive.slow();
        break;
    case ERROR:
        actRandomly();
        break;
    }

    if (ir.collision()) {
        actRandomly();
        ir.resolve();
    }
    logTimeElapsed("end loop");
}
