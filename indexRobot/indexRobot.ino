#include <Servo.h>
#include <Ultrasonic.h>

#define TRIGGER_PIN 16      // correto  DO
#define ECHO_PIN 5          // correto  D1   
#define SERVO_PIN 4         // correto  D2
#define IR_PIN 10           // correto  D3
#define LEFT_MOTOR_IN1 14   // correto  D5
#define LEFT_MOTOR_IN2 12   // correto  D6
#define RIGHT_MOTOR_IN3 13  // correto D7
#define RIGHT_MOTOR_IN4 15  // correto D8

bool BUTTON_RUN = true; // botao do MQTT
bool BUTTON_STOP = true; // botao do MQTT

Servo servo;

Ultrasonic ultrasonic(TRIGGER_PIN, ECHO_PIN);

void setup()
{
  Serial.begin(9600);
  Serial.println("Lendo dados do sensor...");

  pinMode(LEFT_MOTOR_IN1, OUTPUT);
  pinMode(LEFT_MOTOR_IN2, OUTPUT);
  pinMode(RIGHT_MOTOR_IN3, OUTPUT);
  pinMode(RIGHT_MOTOR_IN4, OUTPUT);

  pinMode(IR_PIN, INPUT);

  servo.attach(SERVO_PIN);
  moveServo(90);
  delay(5000);
  moveRobot("girar");
}

void loop()
{
  if (BUTTON_RUN == true) { // botao do MQTT
    while (IRRead() == true) { // detectando a mesa
      if (distanceMeasure() >= 20) {
        moveServo(90);
        moveRobot("frente");
      }

      if (distanceMeasure() < 20) {
        moveRobot("parar");
        moveServo(0);
        if (distanceMeasure() > 20) {
          moveServo(90);
          moveRobot("esquerda");
          moveRobot("frente");
        }
        else
        {
          moveServo(180);
          if (distanceMeasure() > 20) {
            moveServo(90);
            moveRobot("direita");
            moveRobot("frente");
          }
        }
      }

      // TODO fazer integração com pub sub do mqtt ainda nao implementado
      // TODO colocar os dados que vao se enviados pelo MQTT aqui no final do while, para enviar a cada ciclo
    }
    moveServo(90);
    moveRobot("parar"); // se não tiver mesa ele vai parar
    moveRobot("inverter");
  }
  else if (BUTTON_RUN == false) {
    moveServo(90);
    moveRobot("parar"); // se não tiver mesa ele vai parar
  }
}
