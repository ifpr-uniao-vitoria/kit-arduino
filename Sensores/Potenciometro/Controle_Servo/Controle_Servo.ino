/*
 * Exemplo: Potenciômetro Controlando Servo Motor (Intermediário)
 * Autor: Deividson Luiz Okopnik
 * Placa: Arduino Uno
 *
 * Descrição:
 * Este código demonstra a integração de dois componentes: o potenciômetro é usado
 * como um "dial" para controlar a posição angular de um servo motor.
 *
 * Componentes Necessários:
 * - 1x Arduino Uno
 * - 1x Potenciômetro (ex: 10k Ohm)
 * - 1x Servo Motor (ex: SG90)
 * - Jumpers
 *
 * Instruções de Ligação (Wiring):
 * 1. Potenciômetro:
 *    a. Pino Lateral 1 -> Pino 5V do Arduino.
 *    b. Pino Lateral 2 -> Pino GND do Arduino.
 *    c. Pino Central (Wiper) -> Pino Analógico A0 do Arduino.
 * 2. Servo Motor:
 *    a. Fio Vermelho (VCC/Alimentação) -> Pino 5V do Arduino.
 *    b. Fio Marrom/Preto (GND/Terra) -> Pino GND do Arduino.
 *    c. Fio Laranja/Amarelo (Sinal/PWM) -> Pino Digital 9 (PWM) do Arduino.
 *
 * Observações:
 * A função map() é crucial para converter a faixa de leitura do potenciômetro (0-1023)
 * para a faixa de ângulo do servo (0-180).
 */

#include <Servo.h>

// Definição dos pinos
#define PINO_POTENCIOMETRO A0
#define PINO_SERVO 9

Servo meuServo; // Cria um objeto servo

void setup() {
  meuServo.attach(PINO_SERVO); // Anexa o objeto servo ao pino
  Serial.begin(9600);
}

void loop() {
  // 1. Lê o valor do potenciômetro (0 a 1023)
  int valorPot = analogRead(PINO_POTENCIOMETRO);

  // 2. Mapeia o valor do potenciômetro (0-1023) para o ângulo do servo (0-180)
  int anguloServo = map(valorPot, 0, 1023, 0, 180);

  // 3. Define a posição do servo
  meuServo.write(anguloServo);

  // Imprime os valores no Monitor Serial
  Serial.print("Valor Pot: ");
  Serial.print(valorPot);
  Serial.print(" -> Angulo Servo: ");
  Serial.println(anguloServo);

  delay(15); // Pequena pausa para o servo se mover
}
