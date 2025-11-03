/*
 * Exemplo: Controle de LED com Sensor de Luz (LDR)
 * Autor: Deividson Luiz Okopnik
 * Placa: Arduino Uno
 *
 * Descrição:
 * Este código lê o valor analógico de um LDR (Sensor de Luz) e usa esse valor para controlar
 * o brilho de um LED (PWM), simulando um dimmer automático.
 *
 * Componentes Necessários:
 * - 1x Arduino Uno
 * - 1x Sensor de Luz (LDR)
 * - 1x Resistor de 10k Ohm (para o divisor de tensão do LDR)
 * - 1x LED (qualquer cor)
 * - 1x Resistor de 220 Ohm (para o LED)
 * - Jumpers
 *
 * Instruções de Ligação (Wiring):
 * 1. Circuito do LDR (Divisor de Tensão):
 *    a. Uma perna do LDR -> Pino 5V do Arduino.
 *    b. A outra perna do LDR -> Pino Analógico A0 do Arduino.
 *    c. A mesma perna do LDR conectada ao A0 -> Resistor de 10k Ohm -> Pino GND do Arduino.
 * 2. Circuito do LED:
 *    a. Ânodo (perna mais longa) do LED -> Resistor de 220 Ohm -> Pino Digital 10 (PWM) do Arduino.
 *    b. Catodo (perna mais curta) do LED -> Pino GND do Arduino.
 *
 * Observações:
 * O valor lido pelo LDR (0 a 1023) é mapeado para o brilho do LED (0 a 255).
 * Em ambientes claros, o valor do LDR é baixo, e o LED acende mais forte.
 * Em ambientes escuros, o valor do LDR é alto, e o LED acende mais fraco (ou vice-versa, dependendo da montagem).
 */

// Definição dos pinos
#define PINO_LDR A0
#define PINO_LED 10 // Deve ser um pino PWM (com ~)

void setup() {
  pinMode(PINO_LED, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // 1. Lê o valor do LDR (0 a 1023)
  int valorLDR = analogRead(PINO_LDR);

  // 2. Mapeia o valor do LDR (0-1023) para o brilho do LED (0-255)
  // Invertemos o mapeamento para que, quanto mais escuro (valorLDR alto), mais forte o LED acenda.
  // Se quiser o contrário, use: int brilhoLED = map(valorLDR, 0, 1023, 0, 255);
  int brilhoLED = map(valorLDR, 0, 1023, 255, 0);

  // 3. Garante que o valor esteja dentro do limite (0 a 255)
  brilhoLED = constrain(brilhoLED, 0, 255);

  // 4. Controla o brilho do LED
  analogWrite(PINO_LED, brilhoLED);

  // Imprime os valores no Monitor Serial
  Serial.print("Valor LDR: ");
  Serial.print(valorLDR);
  Serial.print(" -> Brilho LED: ");
  Serial.println(brilhoLED);

  delay(50);
}
