#include <Servo.h>
#include <Ultrasonic.h>

#define TRIGGER_PIN D0
#define ECHO_PIN D1
#define SERVO_PIN D2
#define IR_PIN D3
#define LEFT_MOTOR_IN1 D5
#define LEFT_MOTOR_IN2 D6
#define RIGHT_MOTOR_IN3 D7
#define RIGHT_MOTOR_IN4 D8

Servo servo;

Ultrasonic ultrasonic(TRIGGER_PIN, ECHO_PIN);

void setup()
{
  pinMode(LEFT_MOTOR_IN1, OUTPUT);
  pinMode(LEFT_MOTOR_IN2, OUTPUT);
  pinMode(RIGHT_MOTOR_IN3, OUTPUT);
  pinMode(RIGHT_MOTOR_IN4, OUTPUT);
  pinMode(IR_PIN, INPUT);
  servo.attach(SERVO_PIN);
  delay(5000);
  servo.write(90);
}

void frente() {
  if (distanceMeasure() > 30) {
    moveRobot("frente");
  }
}


void loop()
{
  while (IRRead()) {

    if (distanceMeasure() > 30) {
      frente();
    }
    else if (distanceMeasure() < 30) {
      moveRobot("parar");
      servo.write(0);
      delay(500);
      if (distanceMeasure() > 20) {
        moveRobot("direita");
        delay(500);
        moveRobot("parar");
        servo.write(90);
        delay(500);
        frente();
      }
      else {

        servo.write(179);
        delay(500);
        if (distanceMeasure() > 20) {
          moveRobot("esquerda");
          delay(500);
          moveRobot("parar");
          servo.write(90);
          delay(500);
          frente();
        }
      }
    }

  } // end IRRead
  moveRobot("parar");
  servo.write(90);
} // end loop
