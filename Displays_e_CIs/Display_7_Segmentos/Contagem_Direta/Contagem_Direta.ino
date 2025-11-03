/*
 * Exemplo: Contagem Simples em Display 7 Segmentos (Cátodo Comum)
 * Autor: Deividson Luiz Okopnik
 * Placa: Arduino Uno
 *
 * Descrição:
 * Este código demonstra a contagem de 0 a 9 em um Display de 7 Segmentos de Cátodo Comum,
 * controlando cada segmento diretamente com um pino digital do Arduino.
 *
 * Componentes Necessários:
 * - 1x Arduino Uno
 * - 1x Display 7 Segmentos (Cátodo Comum)
 * - 7x Resistor de 220 Ohm
 * - Jumpers
 *
 * Instruções de Ligação (Wiring - Cátodo Comum):
 * 1. Pino Comum (Cátodo) do Display -> Pino GND do Arduino.
 * 2. Segmento A -> Resistor 220 Ohm -> Pino Digital 2.
 * 3. Segmento B -> Resistor 220 Ohm -> Pino Digital 3.
 * 4. Segmento C -> Resistor 220 Ohm -> Pino Digital 4.
 * 5. Segmento D -> Resistor 220 Ohm -> Pino Digital 5.
 * 6. Segmento E -> Resistor 220 Ohm -> Pino Digital 6.
 * 7. Segmento F -> Resistor 220 Ohm -> Pino Digital 7.
 * 8. Segmento G -> Resistor 220 Ohm -> Pino Digital 8.
 *
 * Observações:
 * Para um Display de Ânodo Comum, o pino comum deve ser ligado ao 5V, e os segmentos
 * são ligados com LOW (0) para acender.
 */

// Mapeamento dos pinos do Arduino para os segmentos (a, b, c, d, e, f, g)
const int pinosSegmentos[] = {2, 3, 4, 5, 6, 7, 8};

// Padrões de bits para os números 0 a 9 (para Cátodo Comum: HIGH acende)
// Ordem: a, b, c, d, e, f, g
const byte digitos[10][7] = {
  {1, 1, 1, 1, 1, 1, 0}, // 0
  {0, 1, 1, 0, 0, 0, 0}, // 1
  {1, 1, 0, 1, 1, 0, 1}, // 2
  {1, 1, 1, 1, 0, 0, 1}, // 3
  {0, 1, 1, 0, 0, 1, 1}, // 4
  {1, 0, 1, 1, 0, 1, 1}, // 5
  {1, 0, 1, 1, 1, 1, 1}, // 6
  {1, 1, 1, 0, 0, 0, 0}, // 7
  {1, 1, 1, 1, 1, 1, 1}, // 8
  {1, 1, 1, 1, 0, 1, 1}  // 9
};

void setup() {
  // Configura todos os pinos como OUTPUT
  for (int i = 0; i < 7; i++) {
    pinMode(pinosSegmentos[i], OUTPUT);
  }
}

// Função para exibir um dígito
void exibirDigito(int digito) {
  for (int i = 0; i < 7; i++) {
    digitalWrite(pinosSegmentos[i], digitos[digito][i]);
  }
}

void loop() {
  for (int i = 0; i < 10; i++) {
    exibirDigito(i);
    delay(1000); // Exibe cada número por 1 segundo
  }
}
