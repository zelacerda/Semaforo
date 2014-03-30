/*
Semáforo
Simula um sinal de trânsito
Bônus: buzina para incomodar o papai
v 1.0 - 17/09/2013
by Zé Lacerda

Ingredientes
* LEDs vermelho, amarelo e verde
* 3 resistores de 220 ohm (para os leds)
* Botão
* Resistor de 10K (para o botão)
* Buzzer
*/

// Define os pinos dos componentes
const int pino_verde = 3;
const int pino_amarelo = 4;
const int pino_vermelho = 5;
const int pino_buzzer = 13;
const int pino_botao = 2;

// Define os tempos para cada cor do semáforo (em milissegundos)
const int tempo_verde = 15000;
const int tempo_amarelo = 3000;
const int tempo_vermelho = 15000;

// Define os estados do semáforo
const int ESTADO_VERDE = 1;
const int ESTADO_AMARELO = 2;
const int ESTADO_VERMELHO = 3;

int estado = 0; // Estado do botão
int semaforo = ESTADO_VERDE; // Semáforo inicia no verde
long tempo_anterior = 0; // Contador de tempo inicial (em milissegundos)

void setup() {
  // Define os pinos de entrada e saída
  pinMode(pino_verde, OUTPUT);
  pinMode(pino_amarelo, OUTPUT);
  pinMode(pino_vermelho, OUTPUT);
  pinMode(pino_buzzer, OUTPUT);
  pinMode(pino_botao, INPUT); 

  // Inicia com o sinal verde aceso
  digitalWrite(pino_verde, HIGH);
  digitalWrite(pino_amarelo, LOW);
  digitalWrite(pino_vermelho, LOW);
}

void loop() {
  
  unsigned long tempo_atual = millis(); // Registra o tempo atual (em milissegundos) 
  
  // Verifica se o semáforo verde deve mudar para amarelo
  if (semaforo == ESTADO_VERDE && tempo_atual - tempo_anterior > tempo_verde) {
    sinal_amarelo();
    tempo_anterior = tempo_atual;  
  }

  // Verifica se o semáforo amarelo deve mudar para vermelho
  if (semaforo == ESTADO_AMARELO && tempo_atual - tempo_anterior > tempo_amarelo) {
    sinal_vermelho();
    tempo_anterior = tempo_atual;  
  }

  // Verifica se o semáforo vermelho deve mudar para verde
  if (semaforo == ESTADO_VERMELHO && tempo_atual - tempo_anterior > tempo_vermelho) {
    sinal_verde();
    tempo_anterior = tempo_atual;  
  }  

  estado = digitalRead(pino_botao);
  
  // Toca a buzina se o botão estiver pressionado
  if (estado == HIGH) {
    tone(pino_buzzer, 900);
    tone(pino_buzzer, 800);
  } else {
    noTone(pino_buzzer);
  }
  
}

void sinal_verde() {
  digitalWrite(pino_verde, HIGH);
  digitalWrite(pino_amarelo, LOW);
  digitalWrite(pino_vermelho, LOW);
  semaforo = ESTADO_VERDE;
}

void sinal_amarelo() {
  digitalWrite(pino_verde, LOW);
  digitalWrite(pino_amarelo, HIGH);
  digitalWrite(pino_vermelho, LOW);
  semaforo = ESTADO_AMARELO;
}

void sinal_vermelho() {
  digitalWrite(pino_verde, LOW);
  digitalWrite(pino_amarelo, LOW);
  digitalWrite(pino_vermelho, HIGH);
  semaforo = ESTADO_VERMELHO;
}
  
