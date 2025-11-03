/*
 * Exemplo: Tons Musicais com Buzzer
 * Autor: Deividson Luiz Okopnik
 * Placa: Arduino Uno
 *
 * Descrição:
 * Este código utiliza a função tone() para tocar uma sequência de notas musicais (escala de Dó maior)
 * em um buzzer passivo.
 *
 * Componentes Necessários:
 * - 1x Arduino Uno
 * - 1x Buzzer Passivo
 * - Jumpers
 *
 * Instruções de Ligação (Wiring):
 * 1. Pino Positivo (+) do Buzzer -> Pino Digital 8 do Arduino.
 * 2. Pino Negativo (-) do Buzzer -> Pino GND do Arduino.
 *
 * Observações:
 * Se estiver usando um Buzzer Ativo, ele emitirá um som contínuo ao ser ligado,
 * e a função tone() não funcionará. Para um Buzzer Ativo, use digitalWrite() para ligar/desligar.
 * Este exemplo é para Buzzer Passivo.
 */

// Define o pino onde o buzzer está conectado
#define PINO_BUZZER 8

// Define as frequências das notas musicais (escala de Dó maior)
#define NOTA_DO 262
#define NOTA_RE 294
#define NOTA_MI 330
#define NOTA_FA 349
#define NOTA_SOL 392
#define NOTA_LA 440
#define NOTA_SI 494
#define NOTA_DO_ALTO 523

void setup() {
  // Não é necessário configurar o pino como OUTPUT, a função tone() faz isso.
}

void loop() {
  // Toca a escala de Dó maior
  tocarNota(NOTA_DO, 500);
  tocarNota(NOTA_RE, 500);
  tocarNota(NOTA_MI, 500);
  tocarNota(NOTA_FA, 500);
  tocarNota(NOTA_SOL, 500);
  tocarNota(NOTA_LA, 500);
  tocarNota(NOTA_SI, 500);
  tocarNota(NOTA_DO_ALTO, 500);

  delay(1000); // Pausa de 1 segundo
}

// Função auxiliar para tocar uma nota por um certo tempo
void tocarNota(int frequencia, int duracao) {
  tone(PINO_BUZZER, frequencia, duracao);
  delay(duracao);
  noTone(PINO_BUZZER); // Para o som
  delay(50);           // Pequena pausa entre as notas
}
