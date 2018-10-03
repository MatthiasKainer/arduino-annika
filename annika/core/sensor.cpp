#ifndef __SENSOR_CPP__
#define __SENSOR_CPP__

class Sensor
{
  public:
    Sensor(int trigger_pin, int echo_pin)
        : trigPin(trigger_pin), echoPin(echo_pin)
    {
    }

    void setup() {
        pinMode(this->trigPin, OUTPUT);
        pinMode(this->echoPin, INPUT);
    }

    unsigned long readDistance()
    {
        digitalWrite(trigPin, LOW);
        delayMicroseconds(2);
        digitalWrite(trigPin, HIGH);
        delayMicroseconds(10);
        digitalWrite(trigPin, LOW);

        // Measure the response from the HC-SR04 Echo Pin
        // note that this is a blocking operation, so let's keep it short
        // a timeout of 10000 (10ms) is about 1 1/2 meters
        unsigned long duration = pulseIn(echoPin, HIGH, 10000);

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
