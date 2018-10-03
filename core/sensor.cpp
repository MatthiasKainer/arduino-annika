#ifndef __SENSOR_CPP__
#define __SENSOR_CPP__

class Sensor
{
  public:
    Sensor(int trigger_pin, int echo_pin)
        : trigPin(trigger_pin), echoPin(echo_pin)
    {
        pinMode(trigger_pin, OUTPUT);
        pinMode(echo_pin, INPUT);
    }

    unsigned long readDistance()
    {
        digitalWrite(trigPin, LOW);
        delayMicroseconds(2);
        digitalWrite(trigPin, HIGH);
        delayMicroseconds(10);
        digitalWrite(trigPin, LOW);

        // Measure the response from the HC-SR04 Echo Pin

        unsigned long duration = pulseIn(echoPin, HIGH); //, 100000);

        // Determine distance from duration
        // Use 343 metres per second as speed of sound

        unsigned long distance = (duration / 2) * 0.0343;
        return distance;
    }

  private:
    static const int MAX_DISTANCE = 500; // MAX = 500 CM
    unsigned int trigPin;
    unsigned int echoPin;
};

#endif
