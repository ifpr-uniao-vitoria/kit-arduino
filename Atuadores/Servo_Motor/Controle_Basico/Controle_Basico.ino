/*
 * Exemplo: Controle Básico de Servo Motor
 * Autor: Deividson Luiz Okopnik
 * Placa: Arduino Uno
 *
 * Descrição:
 * Este código demonstra o controle básico de um Servo Motor, movendo-o de 0 a 180 graus e vice-versa.
 *
 * Componentes Necessários:
 * - 1x Arduino Uno
 * - 1x Servo Motor (ex: SG90)
 * - Jumpers
 *
 * Instruções de Ligação (Wiring):
 * 1. Fio Vermelho (VCC/Alimentação) do Servo Motor -> Pino 5V do Arduino.
 * 2. Fio Marrom/Preto (GND/Terra) do Servo Motor -> Pino GND do Arduino.
 * 3. Fio Laranja/Amarelo (Sinal/PWM) do Servo Motor -> Pino Digital 9 (PWM) do Arduino.
 *
 * Observações:
 * Para servos maiores que o SG90, é altamente recomendado o uso de uma fonte de alimentação externa
 * para evitar danos ao regulador de tensão do Arduino.
 */

#include <Servo.h>

// Define o pino de sinal do servo
#define PINO_SERVO 9

Servo meuServo; // Cria um objeto servo para controlar o servo

void setup() {
  // Anexa o objeto servo ao pino definido
  meuServo.attach(PINO_SERVO);
}

void loop() {
  int pos;

  // Move o servo de 0 a 180 graus
  for (pos = 0; pos <= 180; pos += 1) {
    meuServo.write(pos); // Define a posição do servo
    delay(15);          // Aguarda 15ms para o servo se mover
  }

  // Move o servo de 180 a 0 graus
  for (pos = 180; pos >= 0; pos -= 1) {
    meuServo.write(pos); // Define a posição do servo
    delay(15);          // Aguarda 15ms para o servo se mover
  }
}
