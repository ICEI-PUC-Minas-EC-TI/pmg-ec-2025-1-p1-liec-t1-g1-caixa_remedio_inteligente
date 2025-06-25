#include "Compartimento.h"

Compartimento::Compartimento() {}

Compartimento::Compartimento(int pinoBotao, int pinoLed, int pinoServo) {
  this->pinoBotao = pinoBotao;
  pinMode(this->pinoBotao, INPUT);

  this->pinoLed = pinoLed;
  pinMode(this->pinoLed, OUTPUT);

  this->controleServo.attach(pinoServo);
  this->controleServo.write(0);

  this->botaoPressionado = false;
  this->tampaAberta = false;
}

bool Compartimento::estadoBotao() {
  return digitalRead(this->pinoBotao);
}

// modo = 1 -> abre a tampa e liga o LED
// modo = 0 -> fecha a tampa e desliga o LED
void Compartimento::controlaCompartimento(unsigned modo) {
  if (modo == 1) {
    digitalWrite(this->pinoLed, 1);

    this->abreTampa();
    this->tampaAberta = true;
  } else if (modo == 0) {
    digitalWrite(this->pinoLed, 0);

    this->fechaTampa();
    this->tampaAberta = false;
  }
}

void Compartimento::abreTampa() {
  if (!this->tampaAberta) {
    this->controleServo.write(45);
  }
}

void Compartimento::fechaTampa() {
  if (this->tampaAberta) {
    this->controleServo.write(0);
  }
}

void Compartimento::fechaTodos(Compartimento **vetComp, int qtdCompartimento) {
  for (int i = 0; i < qtdCompartimento; i++) {
    if (vetComp[i]->tampaAberta) {
      vetComp[i]->controlaCompartimento(0);
      delay(300);
    }
  }
}

void Compartimento::abreIndividual(Compartimento **vetComp, Compartimento *comp, int qtdCompartimento) {
  if (comp->tampaAberta) {
    comp->controlaCompartimento(0);
  } else {
    Compartimento::fechaTodos(vetComp, qtdCompartimento);

    comp->controlaCompartimento(1);
  }
}
