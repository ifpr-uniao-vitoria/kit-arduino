/*
 * Exemplo: Contador Controlado por Potenciômetro em Display 7 Segmentos com HC595N (Avançado)
 * Autor: Deividson Luiz Okopnik
 * Placa: Arduino Uno
 *
 * Descrição:
 * Este código demonstra a integração de três componentes:
 * 1. Potenciômetro: Lê um valor analógico.
 * 2. HC595N (Shift Register): Controla os 7 segmentos do display.
 * 3. Display 7 Segmentos: Exibe um número de 0 a 9, que é determinado pela posição do potenciômetro.
 *
 * Componentes Necessários:
 * - 1x Arduino Uno
 * - 1x Potenciômetro (ex: 10k Ohm)
 * - 1x CI 74HC595N (Shift Register)
 * - 1x Display 7 Segmentos (Cátodo Comum)
 * - 7x Resistor de 220 Ohm
 * - Jumpers
 *
 * Instruções de Ligação (Wiring):
 * 1. Potenciômetro:
 *    a. Pino Central (Wiper) -> Pino Analógico A0 do Arduino.
 *    b. Pinos Laterais -> 5V e GND do Arduino.
 * 2. CI 74HC595N:
 *    a. Pino DS (14 - Data) -> Pino Digital 11 do Arduino.
 *    b. Pino SHCP (11 - Shift Clock) -> Pino Digital 12 do Arduino.
 *    c. Pino STCP (12 - Latch Clock) -> Pino Digital 8 do Arduino.
 *    d. VCC (16) e OE (13) -> 5V.
 *    e. GND (8) e MR (10) -> GND.
 * 3. Display 7 Segmentos (Cátodo Comum):
 *    a. Pino Comum (Cátodo) -> Pino GND do Arduino.
 *    b. Segmentos A-G (com resistores de 220 Ohm) -> Saídas Q0-Q6 do HC595N (Q7 não usado).
 *       - Q0 -> Segmento A
 *       - Q1 -> Segmento B
 *       - Q2 -> Segmento C
 *       - Q3 -> Segmento D
 *       - Q4 -> Segmento E
 *       - Q5 -> Segmento F
 *       - Q6 -> Segmento G
 *
 * Observações:
 * O valor lido pelo potenciômetro (0-1023) é mapeado para um número de 0 a 9.
 * O HC595N é usado para enviar o padrão de bits do número mapeado para o display.
 */

// Definição dos pinos de controle do HC595N
#define PINO_LATCH 8   // STCP (Pino 12 do 74HC595)
#define PINO_CLOCK 12  // SHCP (Pino 11 do 74HC595)
#define PINO_DATA 11   // DS (Pino 14 do 74HC595)

// Definição do pino do Potenciômetro
#define PINO_POTENCIOMETRO A0

// Padrões de bits para os números 0 a 9 (para Cátodo Comum: 1 acende o segmento)
// Ordem dos bits no byte: Q0(A), Q1(B), Q2(C), Q3(D), Q4(E), Q5(F), Q6(G), Q7(DP)
const byte digitos[] = {
  B01111110, // 0
  B00001100, // 1
  B10110110, // 2
  B10011110, // 3
  B11001100, // 4
  B11011010, // 5
  B11111010, // 6
  B00001110, // 7
  B11111110, // 8
  B11011110  // 9
};

void setup() {
  // Configura os pinos do HC595N como OUTPUT
  pinMode(PINO_LATCH, OUTPUT);
  pinMode(PINO_CLOCK, OUTPUT);
  pinMode(PINO_DATA, OUTPUT);
  Serial.begin(9600);
}

// Função para enviar um byte (8 bits) para o 74HC595
void enviarDados(byte dados) {
  digitalWrite(PINO_LATCH, LOW);
  shiftOut(PINO_DATA, PINO_CLOCK, LSBFIRST, dados); // Usamos LSBFIRST para a ordem dos segmentos
  digitalWrite(PINO_LATCH, HIGH);
}

void loop() {
  // 1. Lê o valor do potenciômetro (0 a 1023)
  int valorPot = analogRead(PINO_POTENCIOMETRO);

  // 2. Mapeia o valor do potenciômetro (0-1023) para um número de 0 a 9
  int numeroExibir = map(valorPot, 0, 1023, 0, 9);

  // 3. Obtém o padrão de bits para o número
  byte padraoBits = digitos[numeroExibir];

  // 4. Envia o padrão de bits para o HC595N
  enviarDados(padraoBits);

  // Imprime os valores no Monitor Serial
  Serial.print("Valor Pot: ");
  Serial.print(valorPot);
  Serial.print(" -> Número Exibido: ");
  Serial.println(numeroExibir);

  delay(50);
}
