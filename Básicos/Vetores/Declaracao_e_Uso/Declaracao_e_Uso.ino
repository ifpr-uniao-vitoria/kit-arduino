/*
 * Exemplo: Declaração e Uso de Vetores (Arrays)
 * Autor: Deividson Luiz Okopnik
 * Placa: Arduino Uno
 *
 * Descrição:
 * Este código demonstra como declarar e utilizar vetores (arrays) para armazenar
 * múltiplos valores do mesmo tipo sob um único nome de variável.
 * O exemplo utiliza um vetor para armazenar os pinos de vários LEDs e outro
 * para armazenar uma sequência de notas musicais.
 *
 * Componentes Necessários:
 * - 1x Arduino Uno
 * - 3x LEDs (verde, amarelo, vermelho)
 * - 3x Resistores de 220 Ohm (para os LEDs)
 * - Jumpers
 *
 * Instruções de Ligação (Wiring):
 * 1. LED 1: Ânodo -> Resistor 220 Ohm -> Pino Digital 13. Catodo -> GND.
 * 2. LED 2: Ânodo -> Resistor 220 Ohm -> Pino Digital 12. Catodo -> GND.
 * 3. LED 3: Ânodo -> Resistor 220 Ohm -> Pino Digital 11. Catodo -> GND.
 *
 * Observações:
 * Vetores são úteis para lidar com coleções de dados, como os pinos de um
 * conjunto de LEDs ou uma série de leituras de sensores. O acesso aos elementos
 * é feito por um índice, que SEMPRE começa em 0.
 */

// -----------------------------------------------------------------------------
// 1. Declaração de Vetores

// Vetor para armazenar os pinos dos LEDs
// O tamanho do vetor é 3 (índices 0, 1 e 2)
const int pinosLED[] = {13, 12, 11};

// Vetor para armazenar uma sequência de números (ex: notas musicais)
// O tamanho do vetor é 5
int sequenciaNotas[] = {262, 294, 330, 349, 392}; // Frequências de C4, D4, E4, F4, G4

// Variável para armazenar o tamanho do vetor de pinos
const int NUM_LEDS = sizeof(pinosLED) / sizeof(pinosLED[0]);

// -----------------------------------------------------------------------------

void setup() {
  Serial.begin(9600);
  Serial.println("--- Exemplo de Vetores Iniciado ---");

  // 2. Uso de Vetores com Estrutura de Repetição (FOR)
  // Configura todos os pinos do vetor como OUTPUT
  for (int i = 0; i < NUM_LEDS; i++) {
    pinMode(pinosLED[i], OUTPUT);
    Serial.print("Pino ");
    Serial.print(pinosLED[i]);
    Serial.println(" configurado como OUTPUT.");
  }
}

void loop() {
  // 3. Acesso e Uso dos Elementos do Vetor

  // Pisca os LEDs em sequência usando o vetor de pinos
  for (int i = 0; i < NUM_LEDS; i++) {
    digitalWrite(pinosLED[i], HIGH); // Liga o LED no índice 'i'
    delay(200);
    digitalWrite(pinosLED[i], LOW);  // Desliga o LED no índice 'i'
  }

  // Exibe as notas musicais armazenadas no vetor
  Serial.print("\nSequência de Notas: ");
  for (int i = 0; i < 5; i++) {
    Serial.print(sequenciaNotas[i]); // Acessa o valor no índice 'i'
    Serial.print(" Hz ");
  }
  Serial.println();

  // Pausa longa antes de repetir
  delay(2000);
}
