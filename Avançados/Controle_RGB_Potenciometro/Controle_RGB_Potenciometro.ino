/*
 * Exemplo: Controle de Cores RGB com Potenciômetro (Avançado)
 * Autor: Deividson Luiz Okopnik
 * Placa: Arduino Uno
 *
 * Descrição:
 * Este código demonstra o controle de um LED RGB (Cátodo Comum) utilizando um único
 * potenciômetro para variar a cor. O potenciômetro é dividido em 3 faixas, cada
 * uma controlando a intensidade de uma cor primária (Vermelho, Verde ou Azul).
 *
 * Componentes Necessários:
 * - 1x Arduino Uno
 * - 1x Potenciômetro (ex: 10k Ohm)
 * - 1x LED RGB (Cátodo Comum)
 * - 3x Resistor de 220 Ohm
 * - Jumpers
 *
 * Instruções de Ligação (Wiring):
 * 1. Potenciômetro:
 *    a. Pino Central (Wiper) -> Pino Analógico A0 do Arduino.
 *    b. Pinos Laterais -> 5V e GND do Arduino.
 * 2. LED RGB (Cátodo Comum):
 *    a. Pino Vermelho (R) do LED RGB -> Resistor 220 Ohm -> Pino Digital 6 (PWM) do Arduino.
 *    b. Pino Verde (G) do LED RGB -> Resistor 220 Ohm -> Pino Digital 5 (PWM) do Arduino.
 *    c. Pino Azul (B) do LED RGB -> Resistor 220 Ohm -> Pino Digital 3 (PWM) do Arduino.
 *    d. Pino Comum (perna mais longa) do LED RGB -> Pino GND do Arduino.
 *
 * Observações:
 * O potenciômetro (0-1023) é dividido em 3 faixas:
 * - 0 a ~341: Controla o Vermelho (Verde e Azul desligados)
 * - ~342 a ~682: Controla o Verde (Vermelho e Azul desligados)
 * - ~683 a 1023: Controla o Azul (Vermelho e Verde desligados)
 *
 * Para um controle mais suave, seria necessário usar 3 potenciômetros (um para cada cor).
 * Este exemplo usa 1 potenciômetro para demonstrar o mapeamento de faixas.
 */

// Definição dos pinos PWM do LED RGB
#define PINO_VERMELHO 6
#define PINO_VERDE 5
#define PINO_AZUL 3

// Definição do pino do Potenciômetro
#define PINO_POTENCIOMETRO A0

void setup() {
  // Configura os pinos como saída
  pinMode(PINO_VERMELHO, OUTPUT);
  pinMode(PINO_VERDE, OUTPUT);
  pinMode(PINO_AZUL, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // 1. Lê o valor do potenciômetro (0 a 1023)
  int valorPot = analogRead(PINO_POTENCIOMETRO);

  int vermelho = 0;
  int verde = 0;
  int azul = 0;

  // 2. Divide o potenciômetro em 3 faixas (aprox. 341 valores por faixa)
  if (valorPot < 342) {
    // Faixa 1: Controla o Vermelho (0 a 255)
    vermelho = map(valorPot, 0, 341, 0, 255);
    Serial.print("Vermelho: ");
    Serial.println(vermelho);
  } else if (valorPot < 683) {
    // Faixa 2: Controla o Verde (0 a 255)
    verde = map(valorPot, 342, 682, 0, 255);
    Serial.print("Verde: ");
    Serial.println(verde);
  } else {
    // Faixa 3: Controla o Azul (0 a 255)
    azul = map(valorPot, 683, 1023, 0, 255);
    Serial.print("Azul: ");
    Serial.println(azul);
  }

  // 3. Define a cor do LED RGB
  analogWrite(PINO_VERMELHO, vermelho);
  analogWrite(PINO_VERDE, verde);
  analogWrite(PINO_AZUL, azul);

  delay(10);
}
