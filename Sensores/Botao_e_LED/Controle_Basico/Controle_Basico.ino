/*
 * Exemplo: Controle de LED com Botão (Push Button)
 * Autor: Deividson Luiz Okopnik
 * Placa: Arduino Uno
 *
 * Descrição:
 * Este código demonstra a leitura digital de um botão (Push Button) para acender e apagar um LED.
 * O LED acende enquanto o botão estiver pressionado.
 *
 * Componentes Necessários:
 * - 1x Arduino Uno
 * - 1x Botão (Push Button)
 * - 1x LED (qualquer cor)
 * - 1x Resistor de 10k Ohm (Pull-down para o botão)
 * - 1x Resistor de 220 Ohm (para o LED)
 * - Jumpers
 *
 * Instruções de Ligação (Wiring):
 * 1. Circuito do Botão (Configuração Pull-down):
 *    a. Um terminal do Botão -> Pino 5V do Arduino.
 *    b. O terminal diagonalmente oposto do Botão -> Pino Digital 2 do Arduino.
 *    c. O mesmo terminal conectado ao Pino 2 -> Resistor de 10k Ohm -> Pino GND do Arduino.
 * 2. Circuito do LED:
 *    a. Ânodo (perna mais longa) do LED -> Resistor de 220 Ohm -> Pino Digital 13 do Arduino.
 *    b. Catodo (perna mais curta) do LED -> Pino GND do Arduino.
 *
 * Observações:
 * A configuração Pull-down garante que o pino digital 2 leia LOW quando o botão não estiver pressionado
 * e HIGH quando estiver pressionado.
 */

// Definição dos pinos
#define PINO_BOTAO 2
#define PINO_LED 13

void setup() {
  // Configura o pino do botão como entrada
  pinMode(PINO_BOTAO, INPUT);
  // Configura o pino do LED como saída
  pinMode(PINO_LED, OUTPUT);
}

void loop() {
  // Lê o estado do botão
  int estadoBotao = digitalRead(PINO_BOTAO);

  // Verifica se o botão está pressionado (HIGH)
  if (estadoBotao == HIGH) {
    digitalWrite(PINO_LED, HIGH); // Acende o LED
  } else {
    digitalWrite(PINO_LED, LOW);  // Apaga o LED
  }
}
