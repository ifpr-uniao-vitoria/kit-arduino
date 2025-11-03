/*
 * Exemplo: Leitura Digital de Sensor de Linha (MH-Sensor-Series)
 * Autor: Deividson Luiz Okopnik
 * Placa: Arduino Uno
 *
 * Descrição:
 * Este código demonstra a leitura digital de um sensor de linha (IR refletivo),
 * que é comumente usado em robôs seguidores de linha. O LED interno do Arduino
 * (pino 13) acenderá quando o sensor detectar uma linha escura (ou vice-versa,
 * dependendo da calibração do sensor).
 *
 * Componentes Necessários:
 * - 1x Arduino Uno
 * - 1x Sensor de Linha (MH-Sensor-Series)
 * - Jumpers
 *
 * Instruções de Ligação (Wiring):
 * 1. Pino VCC do Sensor -> Pino 5V do Arduino.
 * 2. Pino GND do Sensor -> Pino GND do Arduino.
 * 3. Pino OUT (Sinal Digital) do Sensor -> Pino Digital 2 do Arduino.
 *
 * Observações:
 * O sensor de linha MH-Sensor-Series geralmente possui um potenciômetro para
 * ajustar a sensibilidade (limiar de detecção).
 * O valor lido (HIGH ou LOW) depende da calibração e se o sensor está sobre
 * uma superfície clara ou escura.
 */

// Definição dos pinos
#define PINO_SENSOR 2
#define PINO_LED_INTERNO 13

void setup() {
  // Configura o pino do sensor como entrada
  pinMode(PINO_SENSOR, INPUT);
  // Configura o LED interno como saída
  pinMode(PINO_LED_INTERNO, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // Lê o estado do sensor
  int estadoSensor = digitalRead(PINO_SENSOR);

  // Imprime o estado no Monitor Serial
  Serial.print("Estado do Sensor (0=Linha Detectada, 1=Fundo Claro): ");
  Serial.println(estadoSensor);

  // Acende o LED interno se a linha for detectada (assumindo LOW = Linha Detectada)
  if (estadoSensor == LOW) {
    digitalWrite(PINO_LED_INTERNO, HIGH); // LED aceso
  } else {
    digitalWrite(PINO_LED_INTERNO, LOW);  // LED apagado
  }

  delay(100);
}
