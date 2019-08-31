/* O Sensor de Distância Ultrassônico HC-SR04 é capaz de medir distâncias de 2cm a 4m com ótima precisão e baixo preço.
Este módulo possui um circuito pronto com emissor e receptor acoplados e 4 pinos (VCC, Trigger, ECHO, GND) para medição.

Você ainda pode acoplar este sensor neste suporte para sensor ultrassônico, facilitando a prototipagem do seu projeto.

Funcionamento:
Para começar a medição é necessário alimentar o módulo e colocar o pino Trigger em nível alto por mais de 10us.
Assim, o sensor emitirá uma onda sonora que, ao encontrar um obstáculo, rebaterá de volta em direção ao módulo.
Durante o tempo de emissão e recebimento do sinal, o pino ECHO ficará em nível alto. Logo, o cálculo da distância pode ser
feito de acordo com o tempo em que o pino ECHO permaneceu em nível alto após o pino Trigger ter sido colocado em nível alto.

Distância = [Tempo ECHO em nível alto * Velocidade do Som] / 2

A velocidade do som poder ser considerada idealmente igual a 340 m/s, logo o resultado é obtido em metros se considerado o 
tempo em segundos. Na fórmula, a divisão por 2 deve-se ao fato de que a onda é enviada e rebatida, ou seja, ela percorre 2 vezes 
a distância procurada.

Especificações:
– Alimentação: 5V DC
– Corrente de Operação: 2mA
– Ângulo de efeito: 15°
– Alcance.: 2cm ~ 4m
– Precisão.: 3mm 
Link: https://www.filipeflop.com/produto/sensor-de-distancia-ultrassonico-hc-sr04/
*/
#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>

//Firebase settings
#define FIREBASE_HOST "<YOUR_FIREBASE_PROJECT_NAME>.firebaseio.com"
#define FIREBASE_AUTH "<YOUR_FIREBASE_SECRET>"

//Wi-Fi settings
#define WIFI_SSID "<YOUR_WIFI_NETWORK_NAME>"
#define WIFI_PASSWORD "<YOUR_WIFI_NETWORK_PASSWORD>"

//Define trigger and echo digital pins
const int trigPin = 4;
const int echoPin = 3;

// The amount of time the ultrassonic wave will be travelling for
long duration = 0;
// Define the distance variable
double distance = 0;


void getDistance()
{
    // Clear trigPin
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);

    // trigPin HIGH por 10ms
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);

    //Reads echoPin, returns the travel time of the sound wave in ms
    duration = pulseIn(echoPin, HIGH);

    // Calculating the distance, in centimeters, using the formula described in the first section.
    distance = duration * 0.034 / 2;
  
    // Sends the distance value to Firebase
    Firebase.setFloat("distance", distance);

}