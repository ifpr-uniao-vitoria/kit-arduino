/*
 * Exemplo: Controle Básico de Motor DC com Relay
 * Autor: Deividson Luiz Okopnik
 * Placa: Arduino Uno
 *
 * Descrição:
 * Este código demonstra como ligar e desligar um Motor DC utilizando um módulo Relay.
 * O motor DC será ligado por 3 segundos e desligado por 2 segundos, repetidamente.
 *
 * Componentes Necessários:
 * - 1x Arduino Uno
 * - 1x Módulo Relay (1 canal)
 * - 1x Motor DC (pequeno, 5V ou 12V)
 * - 1x Fonte de alimentação externa para o Motor DC (se for 12V)
 * - Jumpers
 *
 * Instruções de Ligação (Wiring):
 * 1. Ligar o pino de Sinal (IN) do Módulo Relay ao Pino Digital 7 do Arduino.
 * 2. Ligar o VCC do Módulo Relay ao 5V do Arduino.
 * 3. Ligar o GND do Módulo Relay ao GND do Arduino.
 * 4. Conectar a Fonte Externa (ou 5V do Arduino, se for motor 5V) ao terminal COMUM (COM) do Relay.
 * 5. Conectar um terminal do Motor DC ao terminal NORMALMENTE ABERTO (NO) do Relay.
 * 6. Conectar o outro terminal do Motor DC ao GND da Fonte Externa (ou GND do Arduino).
 *
 * Observações:
 * O Relay atua como um interruptor controlado pelo Arduino.
 * A maioria dos módulos Relay é acionada com LOW (nível lógico baixo).
 * Certifique-se de que a fonte de alimentação do motor DC seja compatível com o motor.
 */

// Define o pino de controle do Relay
#define PINO_RELAY 7

void setup() {
  // Configura o pino do Relay como saída
  pinMode(PINO_RELAY, OUTPUT);

  // Garante que o motor comece desligado (Relay desativado)
  // Se o seu módulo for acionado com HIGH, mude para digitalWrite(PINO_RELAY, HIGH);
  digitalWrite(PINO_RELAY, HIGH);
}

void loop() {
  // Liga o Motor DC (aciona o Relay)
  // Se o seu módulo for acionado com HIGH, mude para digitalWrite(PINO_RELAY, HIGH);
  digitalWrite(PINO_RELAY, LOW);
  delay(3000); // Motor ligado por 3 segundos

  // Desliga o Motor DC (desativa o Relay)
  // Se o seu módulo for acionado com HIGH, mude para digitalWrite(PINO_RELAY, LOW);
  digitalWrite(PINO_RELAY, HIGH);
  delay(2000); // Motor desligado por 2 segundos
}
