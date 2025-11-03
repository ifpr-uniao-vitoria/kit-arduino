/*
 * Exemplo: Cores Básicas com LED RGB
 * Autor: Deividson Luiz Okopnik
 * Placa: Arduino Uno
 *
 * Descrição:
 * Demonstra o controle de um LED RGB (Cátodo Comum) utilizando a modulação por largura de pulso (PWM)
 * para criar as cores primárias (Vermelho, Verde, Azul) e secundárias (Amarelo, Ciano, Magenta).
 *
 * Componentes Necessários:
 * - 1x Arduino Uno
 * - 1x LED RGB (Cátodo Comum)
 * - 3x Resistor de 220 Ohm (ou valor similar)
 * - Jumpers
 *
 * Instruções de Ligação (Wiring - LED RGB Cátodo Comum):
 * 1. Pino Vermelho (R) do LED RGB -> Resistor 220 Ohm -> Pino Digital 6 (PWM) do Arduino.
 * 2. Pino Verde (G) do LED RGB -> Resistor 220 Ohm -> Pino Digital 5 (PWM) do Arduino.
 * 3. Pino Azul (B) do LED RGB -> Resistor 220 Ohm -> Pino Digital 3 (PWM) do Arduino.
 * 4. Pino Comum (perna mais longa) do LED RGB -> Pino GND do Arduino.
 *
 * Observações:
 * Se o seu LED RGB for Ânodo Comum, o pino comum deve ser ligado ao 5V, e as cores são acionadas
 * com LOW (0-255, onde 0 é brilho máximo e 255 é desligado).
 * Este código é para Cátodo Comum (0=desligado, 255=brilho máximo).
 */

// Definição dos pinos PWM (devem ser pinos com ~)
#define PINO_VERMELHO 6
#define PINO_VERDE 5
#define PINO_AZUL 3

void setup() {
  // Configura os pinos como saída
  pinMode(PINO_VERMELHO, OUTPUT);
  pinMode(PINO_VERDE, OUTPUT);
  pinMode(PINO_AZUL, OUTPUT);
}

// Função auxiliar para definir a cor
void setCor(int vermelho, int verde, int azul) {
  analogWrite(PINO_VERMELHO, vermelho);
  analogWrite(PINO_VERDE, verde);
  analogWrite(PINO_AZUL, azul);
}

void loop() {
  // Vermelho
  setCor(255, 0, 0);
  delay(1000);

  // Verde
  setCor(0, 255, 0);
  delay(1000);

  // Azul
  setCor(0, 0, 255);
  delay(1000);

  // Amarelo (Vermelho + Verde)
  setCor(255, 255, 0);
  delay(1000);

  // Ciano (Verde + Azul)
  setCor(0, 255, 255);
  delay(1000);

  // Magenta (Vermelho + Azul)
  setCor(255, 0, 255);
  delay(1000);

  // Branco (Todos ligados)
  setCor(255, 255, 255);
  delay(1000);

  // Desligado
  setCor(0, 0, 0);
  delay(1000);
}
