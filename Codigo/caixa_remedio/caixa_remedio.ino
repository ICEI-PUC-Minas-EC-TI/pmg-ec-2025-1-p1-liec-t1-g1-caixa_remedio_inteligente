#define nComp 3

#define buzzer 4

#define led1 13
#define led2 14
#define led3 26

#define botao1 32
#define botao2 35
#define botao3 34

#define servo1 18
#define servo2 19
#define servo3 21

#include <Compartimento.h>

Compartimento *vetCompartimento[] = {
  new Compartimento(botao1, led1, servo1),
  new Compartimento(botao2, led2, servo2),
  new Compartimento(botao3, led3, servo3)
};

void setup() {
  Serial.begin(9600);

  pinMode(buzzer, OUTPUT);
  tone(buzzer, 440, 200);
}

void loop() {
  processaBotoesCompartimentos(vetCompartimento);
  delay(25);
}

// função responsável por tratar do I/O e agir como controle dos compartimentos
void processaBotoesCompartimentos(Compartimento **vetComp) {
  for (int i = 0; i < nComp; i++) {
    if (vetComp[i]->estadoBotao()) {
      if (!vetComp[i]->botaoPressionado) {
        vetComp[i]->botaoPressionado = true;

        Compartimento::abreIndividual(vetComp, vetComp[i], nComp);

        tone(buzzer, 440, 200);
      }
    } else {
      vetComp[i]->botaoPressionado = false;
    }
  }
}
