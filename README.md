<!--
*** Obrigado por estar vendo meu README. Se você tiver alguma sugestão
*** que possa melhorá-lo ainda mais dê um fork no repositório e crie uma Pull
*** Request ou abra uma Issue com a tag "sugestão".
*** Obrigado novamente! Agora vamos rodar esse projeto incrível :D
-->

<!-- TITLE -->

<p align="center">
  <h3 align="center">Self Driving Robot</h3>
</p>

<!-- TABLE OF CONTENTS -->

## Tabela de Conteúdo

- [Tabela de Conteúdo](#tabela-de-conteúdo)
- [Sobre o Projeto](#sobre-o-projeto)
  - [Feito Com](#feito-com)
- [Começando](#começando)
  - [Pré-requisitos](#pré-requisitos)
  - [Instalação](#instalação)
    - [Passo Adicional no Codigo Arduino](#passo-adicional-no-codigo-arduino)
    - [Conferindo o IP](#conferindo-o-ip)
- [Esquema Elétrico](#esquema-elétrico)
- [PCI Shield](#pci-shield)
- [Licença](#licença)
- [Contato](#contato)

<!-- ABOUT THE PROJECT -->

## Sobre o Projeto

O projeto foi desenvolvido para a matéria de Eletrônica do Curso de Engenharia de Computação. Apelidado de Self Driving Robot, este autômato tem como objetivo desviar de obstáculos e não cair de degraus.

### Feito Com

Abaixo segue o que foi utilizado na criação deste autômato:

- [NodeMCU ESP8266](https://www.amazon.com.br/Placa-Node-Esp8266-Wifi-Cp2102/dp/B00XJG7GEK/ref=sr_1_2?__mk_pt_BR=%C3%85M%C3%85%C5%BD%C3%95%C3%91&crid=2Z7Z3GNB0T0W5&keywords=nodemcu+esp8266&qid=1570998646&sprefix=nodemcu%2Caps%2C339&sr=8-2) - O NodeMCU ESP8266 é um MicroControlador parecido com Arduino que permite a compilação de codigos escritos em arduino e Lua.
- [Micro Servo Motor Tower Pro 9g Sg90](https://www.amazon.com.br/Micro-Servo-Motor-Acess%C3%B3rios-Arduino/dp/B07GHYCH38/ref=sr_1_1?__mk_pt_BR=%C3%85M%C3%85%C5%BD%C3%95%C3%91&crid=GRVZKVR70CDC&keywords=servo+motor+9g&qid=1570998681&sprefix=servo+motor%2Caps%2C385&sr=8-1) - O Micro Servo é utlizado para mover de um lado para o outro o sensor ultrassônico que está fixado nele.
- [Sensor Ultrassônico HC-SR04](https://www.amazon.com.br/Sensor-Ultrassom-Hc-sr04-Arduino-Ultrass%C3%B4nico/dp/B07GHZYG7Q/ref=sr_1_1?__mk_pt_BR=%C3%85M%C3%85%C5%BD%C3%95%C3%91&keywords=hc-sr04&qid=1570998816&sr=8-1) - O Sensor Ultrassônico serve para medir a distância de objetos que estão em sua frente atravez de ondas ultrassônicas.
- [Driver Motor Ponte H L928N](https://www.amazon.com.br/Driver-Motor-Ponte-H-L298n/dp/B01KF4QF4K/ref=sr_1_fkmr2_1?__mk_pt_BR=%C3%85M%C3%85%C5%BD%C3%95%C3%91&keywords=ponte+h+arduino&qid=1570998906&sr=8-1-fkmr2) - O Driver Motor é utilizado para o acionamento dos motores, já que eles precisam de uma corrente muito maior do que a fornecida pelo MicroControlador.
- [2x Motor DC 3V A 6V Com Redução + Roda](https://www.amazon.com.br/Motor-Redu%C3%A7%C3%A3o-Rob%C3%B3tica-Arduino-Carro/dp/B07GHYMBHJ/ref=sr_1_fkmr1_1?__mk_pt_BR=%C3%85M%C3%85%C5%BD%C3%95%C3%91&keywords=roda+boba+arduino&qid=1570999078&sr=8-1-fkmr1) - Os motores junto com suas caixas de redução é que vão dar movimento ao nosso Robô, com as caixas de redução temos um torque satisfatório para o Robô.
- [Chassi de Acrílico]() - É a estrutura onde tudo está montado e fixado.
- [Power Bank 5V 2.1A]() - É a fonte de energia que o nosso Robô vai utlizar para funcionar,  alimentando os motores, sensores e o MicroControlador.

<!-- GETTING STARTED -->

## Começando

Para conseguir utilizar o Robô, seja atravéz da web ou automático, siga os passos abaixo.

### Pré-requisitos

Antes de seguirmos para as configurações e uso do Robô, é ideal que você tenha o ambiente configurado para compilar codigos em Arduino e criar e testar aplicativos em React.

### Instalação

1. Para instalar e utilizar esse projeto o processo é bem simples, basta clonar este repositório utilizando o comando:

```sh
git clone https://github.com/lucasmori/self-driving-robot.git
```

2. Depois do projeto clonado você deve entrar na pasta `frontend` da raiz, e instalar as dependências do projeto utilizando o comando:

```sh
npm install
```
3. Dentro da pasta **src/services** entrando no arquivo `api.js` você precisa mudar o conteúdo de baseURL para o IP que seu NodeMCU ESP8266 gera.
[Conferir o IP](#conferindo-o-ip).

4. Para rodar o frontend do projeto pasta utilizar seguinte comando na raiz da pasta **frontend** comando:

```sh
npm start
```

Com isso o frontend será iniciado e poderá ser acessado pela porta que vai aparecer no terminal.

---

#### Passo Adicional no Codigo Arduino

Primeiramente na pasta **indexRobot**, no arquivo `indexRobot.ino`, devem ser alterados os seguintes campos presentes abaixo, para que funcione com sua rede internet.

```
#define STASSID "COLOQUE_O_NOME_DA_SUA_REDE_AQUI"
#define STAPSK  "COLOQUE_A_SENHA_DA_SUA_REDE_AQUI"
```
Em seguida será necessário compilar o codigo para o NodeMCU.

##### Conferindo o IP
Para conferir o IP que seu NodeMCU ESP8266 está gerando deve ser feita uma inicialização com o USB conectado, e abrir o monitor serial do arduino IDE, colocando a velocidade para 115200 será exibido algumas mensagens, e uma delas é o IP que ele está fornecendo.

---

<!-- ELETRIC SCHEMA -->

## Esquema Elétrico
[WIP]

<!-- PCI SHIELD -->

## PCI Shield
[WIP]

<!-- LICENSE -->

## Licença

Distribuído sob a licença do MIT. Veja `LICENSE` para mais informações.

<!-- CONTACT -->

## Contato

Lucas Mori - [Github](http://github.com/lucasmori)
