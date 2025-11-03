/*
 * Exemplo: Declaração e Uso Básico de Variáveis
 * Autor: Deividson Luiz Okopnik
 * Placa: Arduino Uno
 *
 * Descrição:
 * Este código demonstra a declaração e o uso de diferentes tipos de variáveis
 * (int, float, char, boolean) no ambiente Arduino (linguagem C/C++).
 * O resultado é exibido no Monitor Serial.
 *
 * Componentes Necessários:
 * - Apenas o Arduino Uno (sem componentes externos).
 *
 * Instruções de Ligação (Wiring):
 * - Nenhuma. Apenas conecte o Arduino ao computador e abra o Monitor Serial.
 *
 * Observações:
 * Este é um exemplo fundamental para entender como armazenar e manipular dados.
 */

// -----------------------------------------------------------------------------
// 1. Declaração de Variáveis Globais
// Variáveis declaradas fora de qualquer função são globais e podem ser usadas
// em qualquer parte do código (setup e loop).

// Variável para armazenar números inteiros (sem casas decimais)
int contador = 0;

// Variável para armazenar números com casas decimais
float temperatura = 25.5;

// Variável para armazenar um único caractere
char letra = 'A';

// Variável booleana: armazena apenas verdadeiro (true) ou falso (false)
boolean estadoLigado = true;

// -----------------------------------------------------------------------------

void setup() {
  // Inicia a comunicação serial para enviar dados ao computador
  Serial.begin(9600);

  // Mensagem inicial
  Serial.println("--- Exemplo de Variáveis ---");
}

void loop() {
  // -----------------------------------------------------------------------------
  // 2. Uso e Manipulação de Variáveis

  // Incrementa o contador a cada iteração do loop
  contador = contador + 1; // É o mesmo que "contador++;"

  // Altera o valor da temperatura
  temperatura = temperatura + 0.1;

  // Inverte o estado booleano (true vira false, false vira true)
  estadoLigado = !estadoLigado;

  // -----------------------------------------------------------------------------
  // 3. Exibição dos Valores

  Serial.print("Contador (int): ");
  Serial.println(contador); // println quebra a linha

  Serial.print("Temperatura (float): ");
  Serial.println(temperatura);

  Serial.print("Letra (char): ");
  Serial.println(letra);

  Serial.print("Estado Ligado (boolean): ");
  Serial.println(estadoLigado); // Exibe 1 para true e 0 para false

  // -----------------------------------------------------------------------------

  // Pausa de 1 segundo para facilitar a leitura no Monitor Serial
  delay(1000);
}
