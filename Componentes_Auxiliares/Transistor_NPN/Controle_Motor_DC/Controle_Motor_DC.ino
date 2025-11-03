/*
 * Exemplo: Controle de Motor DC com Transistor NPN (Intermediário)
 * Autor: Deividson Luiz Okopnik
 * Placa: Arduino Uno
 *
 * Descrição:
 * Este código demonstra como usar um Transistor NPN (como o BC548 ou 2N2222) para
 * controlar a ativação de um Motor DC, permitindo que o Arduino controle cargas
 * que exigem mais corrente do que seus pinos podem fornecer.
 *
 * Componentes Necessários:
 * - 1x Arduino Uno
 * - 1x Motor DC (pequeno)
 * - 1x Transistor NPN (ex: BC548, 2N2222)
 * - 1x Diodo de Roda Livre (Flyback Diode, ex: 1N4001)
 * - 1x Resistor (ex: 1k Ohm)
 * - Jumpers
 *
 * Instruções de Ligação (Wiring):
 * 1. Transistor NPN (Emissor, Base, Coletor):
 *    a. Emissor -> Pino GND do Arduino.
 *    b. Base -> Resistor de 1k Ohm -> Pino Digital 7 do Arduino.
 *    c. Coletor -> Um terminal do Motor DC.
 * 2. Motor DC:
 *    a. O outro terminal do Motor DC -> Pino 5V (ou fonte externa) do Arduino.
 * 3. Diodo de Roda Livre (Proteção):
 *    a. O lado com a faixa (Catodo) -> Pino 5V (ou fonte externa).
 *    b. O lado sem a faixa (Ânodo) -> Terminal do Motor DC conectado ao Coletor do Transistor.
 *
 * Observações:
 * O Transistor NPN atua como uma chave. Quando o pino 7 do Arduino está HIGH,
 * uma pequena corrente flui para a Base, ligando o Transistor e permitindo que
 * a corrente maior flua do 5V para o Motor e para o GND (Emissor).
 * O Diodo é crucial para proteger o Transistor contra picos de tensão gerados
 * pela bobina do motor ao ser desligado.
 */

// Definição do pino de controle da Base do Transistor
#define PINO_CONTROLE 7

void setup() {
  // Configura o pino como saída
  pinMode(PINO_CONTROLE, OUTPUT);
}

void loop() {
  // Liga o Motor DC
  digitalWrite(PINO_CONTROLE, HIGH);
  delay(3000); // Motor ligado por 3 segundos

  // Desliga o Motor DC
  digitalWrite(PINO_CONTROLE, LOW);
  delay(2000); // Motor desligado por 2 segundos
}
