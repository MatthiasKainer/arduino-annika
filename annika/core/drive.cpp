#ifndef __DRIVE_CPP__
#define __DRIVE_CPP__

const unsigned char SPEED_LOW = 150;
const unsigned char SPEED_HIGH = 200;

struct MotorPins
{
    unsigned char Motor;
    unsigned char Direction;
    unsigned char Break;
};

class Drive
{
  public:
    Drive(MotorPins motor_1, MotorPins motor_2)
        : motor1(motor_1), motor2(motor_2)
    {
    }

    void setup()
    {
        this->registerMotor(&this->motor1);
        this->registerMotor(&this->motor2);
    }

    void left() {
        this->drive(&motor1, SPEED_LOW, true);
        this->drive(&motor2, SPEED_LOW, false);
    }
    void right() {
        this->drive(&motor1, SPEED_LOW, false);
        this->drive(&motor2, SPEED_LOW, true);
    }
    void fast() {
        this->drive(&motor1, SPEED_HIGH, true);
        this->drive(&motor2, SPEED_HIGH, true);
    }
    void slow() {
        this->drive(&motor1, SPEED_LOW, true);
        this->drive(&motor2, SPEED_LOW, true);
    }

  private:
    void drive(MotorPins *motor, unsigned char power, boolean reverse)
    {
        analogWrite(motor->Motor, power);
        digitalWrite(motor->Break, LOW);
        digitalWrite(motor->Direction, reverse ? HIGH : LOW);
    }

    void registerMotor(MotorPins *motor)
    {
        pinMode(motor->Motor, OUTPUT);
        pinMode(motor->Direction, OUTPUT);
        pinMode(motor->Break, OUTPUT);
    }

    MotorPins motor1;
    MotorPins motor2;
};

#endif