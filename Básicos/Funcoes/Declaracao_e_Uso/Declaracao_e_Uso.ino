/*
 * Exemplo: Declaração e Uso de Funções
 * Autor: Deividson Luiz Okopnik
 * Placa: Arduino Uno
 *
 * Descrição:
 * Este código demonstra como criar e utilizar funções personalizadas para
 * organizar o código, evitar repetição e melhorar a legibilidade.
 * O exemplo utiliza funções para piscar um LED e para calcular o dobro de um número.
 *
 * Componentes Necessários:
 * - 1x Arduino Uno
 * - 1x LED (qualquer cor)
 * - 1x Resistor de 220 Ohm (para o LED)
 * - Jumpers
 *
 * Instruções de Ligação (Wiring):
 * 1. LED:
 *    a. Ânodo (perna mais longa) do LED -> Resistor de 220 Ohm -> Pino Digital 13 do Arduino.
 *    b. Catodo (perna mais curta) do LED -> Pino GND do Arduino.
 *
 * Observações:
 * Funções são blocos de código que realizam uma tarefa específica. Elas são
 * essenciais para a modularização e reutilização de código.
 */

// Definição do pino do LED
#define PINO_LED 13

// -----------------------------------------------------------------------------
// 1. Protótipos de Funções (Opcional, mas boa prática)
// Informa ao compilador que essas funções existem e serão definidas mais tarde.
void piscarLED(int tempo);
int calcularDobro(int numero);

// -----------------------------------------------------------------------------

void setup() {
  pinMode(PINO_LED, OUTPUT);
  Serial.begin(9600);
  Serial.println("--- Exemplo de Funções Iniciado ---");
}

void loop() {
  // 2. Chamada de Funções

  // Chama a função para piscar o LED rapidamente (200ms)
  Serial.println("Chamando a função piscarLED(200)...");
  piscarLED(200);

  // Chama a função para piscar o LED lentamente (500ms)
  Serial.println("Chamando a função piscarLED(500)...");
  piscarLED(500);

  // Chama a função que retorna um valor
  int resultado = calcularDobro(15);
  Serial.print("O dobro de 15 é: ");
  Serial.println(resultado);

  // Pausa longa antes de repetir
  delay(2000);
}

// -----------------------------------------------------------------------------
// 3. Definição das Funções

/**
 * Função para piscar o LED no PINO_LED.
 * @param tempo O tempo (em milissegundos) que o LED ficará ligado e desligado.
 */
void piscarLED(int tempo) {
  digitalWrite(PINO_LED, HIGH);
  delay(tempo);
  digitalWrite(PINO_LED, LOW);
  delay(tempo);
}

/**
 * Função que calcula e retorna o dobro de um número inteiro.
 * @param numero O número inteiro a ser dobrado.
 * @return O resultado da multiplicação por 2.
 */
int calcularDobro(int numero) {
  return numero * 2;
}
