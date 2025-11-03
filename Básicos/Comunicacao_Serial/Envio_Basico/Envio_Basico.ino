/*
 * Exemplo: Comunicação Serial Básica (Envio de Dados)
 * Autor: Deividson Luiz Okopnik
 * Placa: Arduino Uno
 *
 * Descrição:
 * Este código demonstra como o Arduino pode enviar dados de texto para o computador
 * através da porta serial. Esta é a principal forma de "debug" (verificação de erros)
 * e de comunicação entre o Arduino e um PC.
 *
 * Componentes Necessários:
 * - Apenas o Arduino Uno (sem componentes externos).
 *
 * Instruções de Ligação (Wiring):
 * - Nenhuma. Apenas conecte o Arduino ao computador via cabo USB.
 *
 * Observações:
 * O Monitor Serial do software Arduino (IDE) deve ser aberto para visualizar
 * os dados enviados. Certifique-se de que a taxa de transmissão (Baud Rate)
 * no Monitor Serial esteja configurada para 9600, que é o valor definido
 * na função Serial.begin().
 *
 * Diferença entre Serial.print() e Serial.println():
 * - Serial.print(): Envia o dado e MANTÉM o cursor na mesma linha.
 * - Serial.println(): Envia o dado e MOVE o cursor para a PRÓXIMA linha (adiciona um "\n").
 *   Isso é útil para formatar a saída de forma legível.
 */

// Variável para contar o número de vezes que o loop foi executado
int contador = 0;

void setup() {
  // Inicia a comunicação serial a 9600 bits por segundo (Baud Rate)
  Serial.begin(9600);

  // Mensagem de boas-vindas
  Serial.println("--- Comunicação Serial Iniciada ---");
  Serial.println("Aguardando 1 segundo para iniciar a contagem...");
  delay(1000);
}

void loop() {
  // Incrementa o contador
  contador++;

  // Envia uma mensagem de texto
  Serial.print("Contagem atual: ");

  // Envia o valor da variável contador e quebra a linha (println)
  Serial.println(contador);

  // Pausa de 500 milissegundos (meio segundo)
  delay(500);
}
