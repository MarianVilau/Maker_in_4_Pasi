#ifndef Motor_h
#define Motor_h

class Motor
{
private:
  uint8_t directionPin;
  uint8_t speedPin;
  
public:
  uint8_t speed;
  Motor(uint8_t dirPin, uint8_t speedPin, uint8_t speed)
  {
    this->directionPin = dirPin;
    this->speedPin = speedPin;
    this->speed = speed;
  }

  void RunMotor(bool direction, float factor=1.0f)
  {
    digitalWrite(this->directionPin, direction ? HIGH : LOW);
    analogWrite(this->speedPin, (!direction ? speed : 255-speed) * factor);
  }
  void Stop()
  {
    digitalWrite(this->directionPin, LOW);
    analogWrite(this->speedPin, LOW);
  }
};

#endif