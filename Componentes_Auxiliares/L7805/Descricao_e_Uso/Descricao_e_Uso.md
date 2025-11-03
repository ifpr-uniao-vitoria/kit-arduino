# CI Regulador de Tensão L7805

*   **Autor:** Deividson Luiz Okopnik
*   **Placa:** Arduino Uno (Uso Auxiliar)
*   **Componente:** CI L7805 (Regulador de Tensão de 5V)

## Descrição
O **L7805** é um circuito integrado regulador de tensão linear que fornece uma saída de **5 Volts** estável, desde que a tensão de entrada (Input) esteja entre 7V e 35V. É um componente essencial para alimentar circuitos que exigem exatamente 5V, especialmente quando a fonte de alimentação principal (como uma bateria de 9V ou 12V) fornece uma tensão maior.

## Componentes Necessários
*   1x CI L7805
*   1x Fonte de Tensão de Entrada (ex: 9V)
*   2x Capacitor (ex: 0.33µF na entrada e 0.1µF na saída, para estabilização)
*   Jumpers

## Instruções de Ligação (Wiring)
A ligação do L7805 é simples, mas requer atenção à pinagem (geralmente, olhando de frente, os pinos são: Input, Ground, Output):

1.  **Pino 1 (Input):** Conecte a tensão de entrada (ex: 9V da bateria).
2.  **Pino 2 (Ground):** Conecte ao GND (terra) da fonte de entrada e ao GND do circuito de saída (comum).
3.  **Pino 3 (Output):** Fornece a tensão regulada de 5V. Conecte ao VCC do circuito que você deseja alimentar.

**Capacitores de Estabilização:**
*   Um capacitor (ex: 0.33µF) deve ser colocado entre o **Input (Pino 1)** e o **Ground (Pino 2)**.
*   Um capacitor (ex: 0.1µF) deve ser colocado entre o **Output (Pino 3)** e o **Ground (Pino 2)**.

## Observações
*   O L7805 dissipa o excesso de tensão em forma de calor. Se a diferença entre a tensão de entrada e a de saída for grande (ex: 12V para 5V) e a corrente consumida for alta, um **dissipador de calor** é obrigatório para evitar o superaquecimento e a queima do CI.
*   Este CI não é controlado pelo Arduino, mas sim um componente auxiliar de alimentação. Não há código Arduino associado ao seu funcionamento.
*   O Arduino Uno já possui um regulador de 5V, mas o L7805 é útil para alimentar componentes externos que consomem muita corrente ou para criar uma fonte de 5V separada.
