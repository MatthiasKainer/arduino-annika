#ifndef __IR_CPP__
#define __IR_CPP__

class IRSensor {
    public:
        IRSensor(unsigned char out, unsigned char vcc) : 
            outPin(out), vccPin(vcc) {
        }

        void setup() {
            pinMode(this->outPin, OUTPUT);
            pinMode(this->vccPin, INPUT);
            digitalWrite(this->vccPin, HIGH);
        }
        boolean detect() {
            if (!this->alert) {
                this->alert = digitalRead(this->outPin) == LOW;
            }

            return this->alert;
        }
        void resolve() {
            this->alert = false;
        }
    private:
        boolean alert;
        unsigned char vccPin;
        unsigned char gndPin;
        unsigned char outPin;
};

#endif