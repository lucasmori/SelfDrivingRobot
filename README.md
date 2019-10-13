# Começando

## A idéia
O projeto foi desenvolvido para a matéria de Eletrônica do Curso de Engenharia de Computação. 

## Objetivo
Apelidado de SelfDrivingRobot, este autômato tem como objetivo desviar de objetos e obstáculos e não cair de estremidades e degrais.

## Funcionamento
Básicamente o funcionamento está totalmente por conta do próprio Robô, ele fica encarregado de desviar dos obstáculos e de não cair de degrais. As interações que podemos ter com ele é de iniciar ou desativar o modo de operação do Robô via Interface Web. 

## Instalação

Primeiramente na pasta _indexRobot/_, no arquivo _indexRobot.ino_, devem ser alterados os seguintes campos presentes abaixo, para que funcione com sua rede internet.

```
#define STASSID "COLOQUE_O_NOME_DA_SUA_REDE_AQUI"
#define STAPSK  "COLOQUE_A_SENHA_DA_SUA_REDE_AQUI"
```
Em seguida será nescessário compilar o codigo para o NodeMCU.

[WIP]
(Para iniciar o frontend do nosso projeto, onde teremos interação com o autômato é preciso ir na pasta _web/_ e executar o seguinde comando no terminal ``` npm start```.)

## Esquema Elétrico
[WIP]
## PCI Shield
[WIP]

## Materiais
- [NodeMCU ESP8266](https://www.amazon.com.br/Placa-Node-Esp8266-Wifi-Cp2102/dp/B00XJG7GEK/ref=sr_1_2?__mk_pt_BR=%C3%85M%C3%85%C5%BD%C3%95%C3%91&crid=2Z7Z3GNB0T0W5&keywords=nodemcu+esp8266&qid=1570998646&sprefix=nodemcu%2Caps%2C339&sr=8-2)  
- [Micro Servo Motor Tower Pro 9g Sg90](https://www.amazon.com.br/Micro-Servo-Motor-Acess%C3%B3rios-Arduino/dp/B07GHYCH38/ref=sr_1_1?__mk_pt_BR=%C3%85M%C3%85%C5%BD%C3%95%C3%91&crid=GRVZKVR70CDC&keywords=servo+motor+9g&qid=1570998681&sprefix=servo+motor%2Caps%2C385&sr=8-1)
- [Sensor Ultrassônico HC-SR04](https://www.amazon.com.br/Sensor-Ultrassom-Hc-sr04-Arduino-Ultrass%C3%B4nico/dp/B07GHZYG7Q/ref=sr_1_1?__mk_pt_BR=%C3%85M%C3%85%C5%BD%C3%95%C3%91&keywords=hc-sr04&qid=1570998816&sr=8-1)
- [Driver Motor Ponte H L928N](https://www.amazon.com.br/Driver-Motor-Ponte-H-L298n/dp/B01KF4QF4K/ref=sr_1_fkmr2_1?__mk_pt_BR=%C3%85M%C3%85%C5%BD%C3%95%C3%91&keywords=ponte+h+arduino&qid=1570998906&sr=8-1-fkmr2)
- [2x Motor DC 3V A 6V Com Redução + Roda](https://www.amazon.com.br/Motor-Redu%C3%A7%C3%A3o-Rob%C3%B3tica-Arduino-Carro/dp/B07GHYMBHJ/ref=sr_1_fkmr1_1?__mk_pt_BR=%C3%85M%C3%85%C5%BD%C3%95%C3%91&keywords=roda+boba+arduino&qid=1570999078&sr=8-1-fkmr1)
- [Chassi de Acrílico]()
- [Power Bank 5V 2.1A]()

## Licença
MIT License
Copyright (c) 2019 Lucas Mori

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
