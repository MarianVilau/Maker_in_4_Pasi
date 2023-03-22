#ifndef BUZZER_h
#define BUZZER_h

class Buzzer{

private:
    uint8_t buzzerPin;
    uint frequency;
public:
    int duration;
    
    Buzzer (uint8_t pin, uint frequency, int duration)
    {
        this->buzzerPin = pin;
        this->frequency = frequency;
        this->duration = duration;
    }

    void Run()
    {
        tone(this->buzzerPin, this->frequency);
    }
    void Stop()
    {
        noTone(this->buzzerPin);
    }
};


#endif
