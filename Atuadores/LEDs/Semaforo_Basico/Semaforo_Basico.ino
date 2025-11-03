/*
 * Exemplo: Semáforo Básico com LEDs
 * Autor: Deividson Luiz Okopnik
 * Placa: Arduino Uno
 *
 * Descrição:
 * Simula o funcionamento básico de um semáforo, acendendo os LEDs vermelho, amarelo e verde
 * em sequência.
 *
 * Componentes Necessários:
 * - 1x Arduino Uno
 * - 1x LED Vermelho
 * - 1x LED Amarelo
 * - 1x LED Verde
 * - 3x Resistor de 220 Ohm (ou valor similar)
 * - Jumpers
 *
 * Instruções de Ligação (Wiring):
 * 1. LED Vermelho (ânodo, perna mais longa) -> Resistor 220 Ohm -> Pino Digital 13.
 * 2. LED Amarelo (ânodo, perna mais longa) -> Resistor 220 Ohm -> Pino Digital 12.
 * 3. LED Verde (ânodo, perna mais longa) -> Resistor 220 Ohm -> Pino Digital 11.
 * 4. Catodo (perna mais curta) de todos os LEDs -> Pino GND do Arduino.
 *
 * Observações:
 * Os resistores são essenciais para limitar a corrente e proteger os LEDs de queimar.
 */

// Definição dos pinos
#define PINO_VERMELHO 13
#define PINO_AMARELO 12
#define PINO_VERDE 11

void setup() {
  // Configura os pinos como saída
  pinMode(PINO_VERMELHO, OUTPUT);
  pinMode(PINO_AMARELO, OUTPUT);
  pinMode(PINO_VERDE, OUTPUT);
}

void loop() {
  // 1. Vermelho (Pare)
  digitalWrite(PINO_VERMELHO, HIGH);
  digitalWrite(PINO_AMARELO, LOW);
  digitalWrite(PINO_VERDE, LOW);
  delay(5000); // 5 segundos

  // 2. Amarelo (Atenção)
  digitalWrite(PINO_VERMELHO, HIGH); // Mantém o vermelho aceso por um breve momento (opcional)
  digitalWrite(PINO_AMARELO, HIGH);
  digitalWrite(PINO_VERDE, LOW);
  delay(2000); // 2 segundos

  // 3. Verde (Siga)
  digitalWrite(PINO_VERMELHO, LOW);
  digitalWrite(PINO_AMARELO, LOW);
  digitalWrite(PINO_VERDE, HIGH);
  delay(5000); // 5 segundos

  // 4. Amarelo (Atenção antes de voltar ao vermelho)
  digitalWrite(PINO_VERMELHO, LOW);
  digitalWrite(PINO_AMARELO, HIGH);
  digitalWrite(PINO_VERDE, LOW);
  delay(2000); // 2 segundos
}
