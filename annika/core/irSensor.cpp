#ifndef __IR_CPP__
#define __IR_CPP__

class IRSensor {
    public:
        IRSensor(unsigned char out) : 
            outPin(out) {
        }

        void setup() {
            pinMode(this->outPin, INPUT);
        }
        boolean collision() {
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
        unsigned char outPin;
};

#endif