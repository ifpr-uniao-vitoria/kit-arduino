/*
 * Exemplo: Controle de 8 LEDs com CI 74HC595N (Shift Register) (Intermediário)
 * Autor: Deividson Luiz Okopnik
 * Placa: Arduino Uno
 *
 * Descrição:
 * Este código demonstra como usar o CI 74HC595N (Shift Register) para controlar 8 LEDs
 * usando apenas 3 pinos digitais do Arduino, economizando pinos.
 *
 * Componentes Necessários:
 * - 1x Arduino Uno
 * - 1x CI 74HC595N (Shift Register)
 * - 8x LED (qualquer cor)
 * - 8x Resistor de 220 Ohm
 * - Jumpers
 *
 * Instruções de Ligação (Wiring):
 * 1. CI 74HC595N:
 *    a. Pino VCC (16) e Pino OE (13) -> 5V do Arduino.
 *    b. Pino GND (8) e Pino MR (10) -> GND do Arduino.
 * 2. Pinos de Controle (3 pinos do Arduino):
 *    a. Pino DS (14 - Data) -> Pino Digital 11 do Arduino.
 *    b. Pino SHCP (11 - Shift Clock) -> Pino Digital 12 do Arduino.
 *    c. Pino STCP (12 - Latch Clock) -> Pino Digital 8 do Arduino.
 * 3. Saídas Q0 a Q7 (15, 1-7) -> Resistor 220 Ohm -> Ânodo do LED.
 * 4. Catodo do LED -> Pino GND do Arduino.
 *
 * Observações:
 * O 74HC595N é um registrador de deslocamento serial-in, paralelo-out.
 * A função shiftOut() do Arduino simplifica o envio dos dados.
 */

// Definição dos pinos de controle
#define PINO_LATCH 8   // STCP (Pino 12 do 74HC595)
#define PINO_CLOCK 12  // SHCP (Pino 11 do 74HC595)
#define PINO_DATA 11   // DS (Pino 14 do 74HC595)

void setup() {
  // Configura os pinos como OUTPUT
  pinMode(PINO_LATCH, OUTPUT);
  pinMode(PINO_CLOCK, OUTPUT);
  pinMode(PINO_DATA, OUTPUT);
}

// Função para enviar um byte (8 bits) para o 74HC595
void enviarDados(byte dados) {
  // 1. Coloca o Latch em LOW (prepara para receber dados)
  digitalWrite(PINO_LATCH, LOW);

  // 2. Envia o byte de dados (MSBFIRST = bit mais significativo primeiro)
  shiftOut(PINO_DATA, PINO_CLOCK, MSBFIRST, dados);

  // 3. Coloca o Latch em HIGH (trava os dados e atualiza as saídas)
  digitalWrite(PINO_LATCH, HIGH);
}

void loop() {
  // Acende os LEDs em sequência
  for (int i = 0; i < 8; i++) {
    byte dados = 1 << i; // Cria um byte com apenas 1 bit ligado
    enviarDados(dados);
    delay(200);
  }

  // Apaga todos
  enviarDados(0);
  delay(500);

  // Acende todos
  enviarDados(255);
  delay(500);
}
