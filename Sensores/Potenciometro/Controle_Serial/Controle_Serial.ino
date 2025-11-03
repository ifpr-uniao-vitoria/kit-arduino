/*
 * Exemplo: Leitura de Potenciômetro e Controle Serial
 * Autor: Deividson Luiz Okopnik
 * Placa: Arduino Uno
 *
 * Descrição:
 * Este código lê o valor analógico de um potenciômetro e o imprime no Monitor Serial.
 * É o exemplo fundamental para entender a leitura de entradas analógicas.
 *
 * Componentes Necessários:
 * - 1x Arduino Uno
 * - 1x Potenciômetro (qualquer valor, ex: 10k Ohm)
 * - Jumpers
 *
 * Instruções de Ligação (Wiring):
 * 1. Pino Lateral 1 do Potenciômetro -> Pino 5V do Arduino.
 * 2. Pino Lateral 2 do Potenciômetro -> Pino GND do Arduino.
 * 3. Pino Central (Wiper) do Potenciômetro -> Pino Analógico A0 do Arduino.
 *
 * Observações:
 * Ao girar o potenciômetro, o valor lido no pino A0 varia de 0 (GND) a 1023 (5V).
 */

// Definição do pino
#define PINO_POTENCIOMETRO A0

void setup() {
  // Inicia a comunicação serial
  Serial.begin(9600);
}

void loop() {
  // Lê o valor do potenciômetro (0 a 1023)
  int valorPot = analogRead(PINO_POTENCIOMETRO);

  // Imprime o valor no Monitor Serial
  Serial.print("Valor do Potenciômetro: ");
  Serial.println(valorPot);

  delay(100); // Pequena pausa para estabilizar a leitura
}
