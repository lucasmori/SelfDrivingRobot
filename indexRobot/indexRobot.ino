#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <ESP8266mDNS.h>

#ifndef STASSID
#define STASSID "COLOQUE_O_NOME_DA_SUA_REDE_AQUI"
#define STAPSK  "COLOQUE_A_SENHA_DA_SUA_REDE_AQUI"
#endif

const char* ssid = STASSID;
const char* password = STAPSK;
int go = false;
void handleRUN();
void handleSTOP();
ESP8266WebServer server(80);

// ------------------------------------------------

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
  Serial.begin(115200);
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  Serial.println("");

  // Wait for connection
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("Connected to ");
  Serial.println(ssid);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());

  if (MDNS.begin("esp8266")) {
    Serial.println("MDNS responder started");
  }

  server.on("/",HTTP_GET, handleRoot);
  server.on("/run", HTTP_POST, handleRUN);
  server.on("/stop", HTTP_POST, handleSTOP);
  server.on("/inline", []() {
    server.send(200, "text/plain", "this works as well");
  });
 
  server.onNotFound(handleNotFound);

  server.begin();
  Serial.println("HTTP server started");

  // -----------------------------

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
void handleRUN() {
  go = true;
  //server.sendHeader("Location", "/");
  server.send(303, "text/plan", "the robot is running");
}

void handleSTOP() {
  go = false;
  //server.sendHeader("Location", "/");
  server.send(303, "text/plan", "the robot has stop");
}
void loop()
{

  server.handleClient();
  if (go == true) {

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
  }
  moveRobot("parar");
  servo.write(90);

} // end loop
