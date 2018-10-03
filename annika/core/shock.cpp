#ifndef __SHOCK_CPP__
#define __SHOCK_CPP__

class Shock {
    public:
        Shock(unsigned char pin) : 
            shockPin(pin) {
        }

        void setup() {
            pinMode(this->shockPin, INPUT);
        }
        boolean detect() {
            if (!this->alert) {
                this->alert = digitalRead(this->shockPin) == HIGH;
            }

            return this->alert;
        }
        void resolve() {
            this->alert = false;
        }
    private:
        boolean alert;
        unsigned char shockPin;
};

#endif