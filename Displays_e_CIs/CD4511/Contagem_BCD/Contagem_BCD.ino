/*
 * Exemplo: Contagem em Display 7 Segmentos com CI CD4511 (Intermediário)
 * Autor: Deividson Luiz Okopnik
 * Placa: Arduino Uno
 *
 * Descrição:
 * Este código demonstra o uso do CI decodificador BCD para 7 segmentos CD4511 para
 * simplificar o controle de um Display de 7 Segmentos, usando apenas 4 pinos digitais
 * do Arduino (em vez de 7).
 *
 * Componentes Necessários:
 * - 1x Arduino Uno
 * - 1x Display 7 Segmentos (Cátodo Comum)
 * - 1x CI CD4511 (Decodificador BCD para 7 Segmentos)
 * - 7x Resistor de 220 Ohm
 * - Jumpers
 *
 * Instruções de Ligação (Wiring - CD4511 com Display Cátodo Comum):
 * 1. CI CD4511:
 *    a. Pino VDD (16) -> 5V do Arduino.
 *    b. Pino VSS (8) -> GND do Arduino.
 *    c. Pino LT (3) e BI (4) -> 5V do Arduino (para manter o display ligado e sem teste).
 *    d. Pino LE (5) -> GND do Arduino (para manter o latch transparente).
 * 2. Entradas BCD (A, B, C, D):
 *    a. Pino A (7) -> Pino Digital 2 do Arduino.
 *    b. Pino B (1) -> Pino Digital 3 do Arduino.
 *    c. Pino C (2) -> Pino Digital 4 do Arduino.
 *    d. Pino D (6) -> Pino Digital 5 do Arduino.
 * 3. Saídas do CD4511 (a-g) -> Resistor 220 Ohm -> Segmentos correspondentes do Display.
 * 4. Pino Comum (Cátodo) do Display -> Pino GND do Arduino.
 *
 * Observações:
 * O CD4511 é um decodificador BCD para 7 segmentos, o que significa que ele aceita
 * um número binário de 4 bits (BCD) e o converte automaticamente para o padrão
 * de 7 segmentos.
 */

// Definição dos pinos de entrada BCD (A, B, C, D)
#define PINO_A 2
#define PINO_B 3
#define PINO_C 4
#define PINO_D 5

void setup() {
  // Configura os pinos BCD como OUTPUT
  pinMode(PINO_A, OUTPUT);
  pinMode(PINO_B, OUTPUT);
  pinMode(PINO_C, OUTPUT);
  pinMode(PINO_D, OUTPUT);
}

// Função para enviar um número (0-9) para o CD4511
void enviarNumero(int numero) {
  // O número é convertido para BCD (Binary Coded Decimal)
  digitalWrite(PINO_A, bitRead(numero, 0)); // Bit 0
  digitalWrite(PINO_B, bitRead(numero, 1)); // Bit 1
  digitalWrite(PINO_C, bitRead(numero, 2)); // Bit 2
  digitalWrite(PINO_D, bitRead(numero, 3)); // Bit 3
}

void loop() {
  for (int i = 0; i < 10; i++) {
    enviarNumero(i);
    delay(1000); // Exibe cada número por 1 segundo
  }
}
