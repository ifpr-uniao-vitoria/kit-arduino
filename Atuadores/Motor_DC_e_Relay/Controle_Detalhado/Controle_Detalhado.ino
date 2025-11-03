/*
 * Exemplo: Controle Detalhado de Motor DC com Módulo Relay
 * Autor: Deividson Luiz Okopnik
 * Placa: Arduino Uno
 *
 * Descrição:
 * Este código demonstra o acionamento de um Motor DC através de um Módulo Relay,
 * com foco na descrição detalhada do circuito de acionamento e na segurança.
 * O motor será ligado por 3 segundos e desligado por 2 segundos, repetidamente.
 *
 * Componentes Necessários:
 * - 1x Arduino Uno
 * - 1x Módulo Relay (1 canal)
 * - 1x Motor DC (pequeno, 5V ou 12V)
 * - 1x Fonte de alimentação externa para o Motor DC (se for 12V ou se o motor 5V consumir muita corrente)
 * - Jumpers
 *
 * Instruções de Ligação (Wiring):
 *
 * **Circuito de Controle (Lado Arduino):**
 * 1. **Pino de Sinal (IN) do Módulo Relay** -> Pino Digital 7 do Arduino.
 * 2. **VCC do Módulo Relay** -> Pino 5V do Arduino.
 * 3. **GND do Módulo Relay** -> Pino GND do Arduino.
 *
 * **Circuito de Potência (Lado Motor):**
 * 4. **Fonte de Alimentação do Motor (+):** Conecte o positivo da fonte externa (ou 5V do Arduino) ao terminal **COMUM (COM)** do Relay.
 * 5. **Motor DC (Terminal 1):** Conecte um terminal do Motor DC ao terminal **NORMALMENTE ABERTO (NO)** do Relay.
 * 6. **Motor DC (Terminal 2):** Conecte o outro terminal do Motor DC ao **GND** da Fonte de Alimentação do Motor (ou GND do Arduino).
 *
 * **Detalhes do Acionamento:**
 * - O Relay atua como um interruptor controlado pelo Arduino.
 * - A maioria dos módulos Relay é acionada com **LOW** (nível lógico baixo) no pino IN.
 * - Quando o pino 7 do Arduino está **LOW**, o Relay fecha o circuito entre COM e NO, ligando o motor.
 * - Quando o pino 7 do Arduino está **HIGH**, o Relay abre o circuito, desligando o motor.
 *
 * Observações:
 * - **IMPORTANTE:** Nunca alimente um motor DC diretamente pelos pinos do Arduino. O Relay isola o circuito de controle (Arduino) do circuito de potência (Motor).
 * - Certifique-se de que a fonte de alimentação do motor DC seja compatível com o motor.
 */

// Define o pino de controle do Relay
#define PINO_RELAY 7

void setup() {
  // Configura o pino do Relay como saída
  pinMode(PINO_RELAY, OUTPUT);

  // Garante que o motor comece desligado (Relay desativado - HIGH para módulos LOW-trigger)
  digitalWrite(PINO_RELAY, HIGH);
}

void loop() {
  // Liga o Motor DC (aciona o Relay - LOW para módulos LOW-trigger)
  digitalWrite(PINO_RELAY, LOW);
  Serial.println("Motor Ligado");
  delay(3000); // Motor ligado por 3 segundos

  // Desliga o Motor DC (desativa o Relay - HIGH para módulos LOW-trigger)
  digitalWrite(PINO_RELAY, HIGH);
  Serial.println("Motor Desligado");
  delay(2000); // Motor desligado por 2 segundos
}
