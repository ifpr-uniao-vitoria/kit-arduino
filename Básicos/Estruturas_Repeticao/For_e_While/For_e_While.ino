/*
 * Exemplo: Estruturas de Repetição For e While
 * Autor: Deividson Luiz Okopnik
 * Placa: Arduino Uno
 *
 * Descrição:
 * Este código demonstra e compara o uso das duas principais estruturas de repetição
 * do Arduino: 'for' e 'while'. O exemplo utiliza LEDs para ilustrar o funcionamento
 * de cada estrutura.
 *
 * Componentes Necessários:
 * - 1x Arduino Uno
 * - 3x LEDs (verde, amarelo, vermelho)
 * - 3x Resistores de 220 Ohm (para os LEDs)
 * - Jumpers
 *
 * Instruções de Ligação (Wiring):
 * 1. LED Verde: Ânodo -> Resistor 220 Ohm -> Pino Digital 13. Catodo -> GND.
 * 2. LED Amarelo: Ânodo -> Resistor 220 Ohm -> Pino Digital 12. Catodo -> GND.
 * 3. LED Vermelho: Ânodo -> Resistor 220 Ohm -> Pino Digital 11. Catodo -> GND.
 *
 * Observações:
 * - O 'for' é ideal quando se sabe o número exato de repetições.
 * - O 'while' é ideal quando a repetição depende de uma condição ser verdadeira.
 */

// Definição dos pinos dos LEDs
#define PINO_LED_VERDE 13
#define PINO_LED_AMARELO 12
#define PINO_LED_VERMELHO 11

void setup() {
  // Configura os pinos dos LEDs como saída
  pinMode(PINO_LED_VERDE, OUTPUT);
  pinMode(PINO_LED_AMARELO, OUTPUT);
  pinMode(PINO_LED_VERMELHO, OUTPUT);

  // Inicia a comunicação serial
  Serial.begin(9600);
  Serial.println("--- Exemplo For e While Iniciado ---");
}

void loop() {
  // -----------------------------------------------------------------------------
  // 1. Demonstração da Estrutura FOR
  // O 'for' é usado para repetir um bloco de código um número fixo de vezes.
  // Sintaxe: for (inicialização; condição; incremento)

  Serial.println("\n--- INÍCIO DO FOR: Pisca LED Verde 5 vezes ---");
  for (int i = 0; i < 5; i++) {
    digitalWrite(PINO_LED_VERDE, HIGH);
    delay(200);
    digitalWrite(PINO_LED_VERDE, LOW);
    delay(200);
    Serial.print("Repetição FOR: ");
    Serial.println(i + 1);
  }
  Serial.println("--- FIM DO FOR ---");
  delay(1000);

  // -----------------------------------------------------------------------------
  // 2. Demonstração da Estrutura WHILE
  // O 'while' repete um bloco de código ENQUANTO uma condição for verdadeira.

  Serial.println("\n--- INÍCIO DO WHILE: LED Amarelo acende por 3 segundos ---");
  digitalWrite(PINO_LED_AMARELO, HIGH);
  long tempoInicial = millis(); // Pega o tempo atual em milissegundos

  // Repete enquanto o tempo decorrido for menor que 3000ms (3 segundos)
  while (millis() - tempoInicial < 3000) {
    // O código aqui dentro se repete, mas não fazemos nada além de esperar
    // (A condição é verificada a cada iteração)
  }

  digitalWrite(PINO_LED_AMARELO, LOW);
  Serial.println("--- FIM DO WHILE ---");
  delay(1000);

  // -----------------------------------------------------------------------------
  // 3. Demonstração de uma Repetição Infinita (Loop Principal)
  // O loop() principal do Arduino é, na verdade, um 'while(true)' infinito.
  // Para ilustrar, piscamos o LED Vermelho uma vez e esperamos 2 segundos.

  Serial.println("\n--- LOOP PRINCIPAL (While Infinito) ---");
  digitalWrite(PINO_LED_VERMELHO, HIGH);
  delay(500);
  digitalWrite(PINO_LED_VERMELHO, LOW);
  delay(1500); // Total de 2 segundos de espera
}
