/*
 * Exemplo: Estrutura de Controle If/Else
 * Autor: Deividson Luiz Okopnik
 * Placa: Arduino Uno
 *
 * Descrição:
 * Este código demonstra o uso da estrutura condicional 'if/else' para tomar decisões
 * no programa. O exemplo simula a verificação de um valor de sensor (potenciômetro)
 * para decidir se um LED deve ser ligado ou desligado.
 *
 * Componentes Necessários:
 * - 1x Arduino Uno
 * - 1x Potenciômetro (para simular um sensor)
 * - 1x LED (qualquer cor)
 * - 1x Resistor de 220 Ohm (para o LED)
 * - Jumpers
 *
 * Instruções de Ligação (Wiring):
 * 1. Potenciômetro:
 *    a. Pino Lateral 1 -> Pino 5V do Arduino.
 *    b. Pino Lateral 2 -> Pino GND do Arduino.
 *    c. Pino Central (Wiper) -> Pino Analógico A0 do Arduino.
 * 2. LED:
 *    a. Ânodo (perna mais longa) do LED -> Resistor de 220 Ohm -> Pino Digital 13 do Arduino.
 *    b. Catodo (perna mais curta) do LED -> Pino GND do Arduino.
 *
 * Observações:
 * A estrutura 'if/else' é fundamental para a lógica de qualquer programa, permitindo
 * que o código execute diferentes blocos de instruções com base em uma condição.
 */

// Definição dos pinos
#define PINO_POTENCIOMETRO A0
#define PINO_LED 13

// Define o valor limite para ligar o LED
const int LIMITE_LIGAR = 500;

void setup() {
  // Configura o pino do LED como saída
  pinMode(PINO_LED, OUTPUT);
  // Inicia a comunicação serial para debug
  Serial.begin(9600);
  Serial.println("--- Exemplo If/Else Iniciado ---");
}

void loop() {
  // 1. Lê o valor do potenciômetro (0 a 1023)
  int valorSensor = analogRead(PINO_POTENCIOMETRO);

  // 2. Estrutura de Controle If/Else
  // Verifica se o valor lido é maior ou igual ao limite
  if (valorSensor >= LIMITE_LIGAR) {
    // Se a condição for VERDADEIRA (True), executa este bloco
    digitalWrite(PINO_LED, HIGH); // Liga o LED
    Serial.print("Valor (");
    Serial.print(valorSensor);
    Serial.println(") >= 500. LED LIGADO.");
  } else {
    // Se a condição for FALSA (False), executa este bloco
    digitalWrite(PINO_LED, LOW); // Desliga o LED
    Serial.print("Valor (");
    Serial.print(valorSensor);
    Serial.println(") < 500. LED DESLIGADO.");
  }

  // Pequena pausa para estabilizar a leitura e a serial
  delay(100);
}
