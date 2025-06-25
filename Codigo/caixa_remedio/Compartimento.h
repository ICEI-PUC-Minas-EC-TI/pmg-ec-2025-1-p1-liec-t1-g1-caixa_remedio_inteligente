#ifndef COMPARTIMENTO_H
#define COMPARTIMENTO_H

#include <ESP32Servo.h>
#include <Arduino.h>

class Compartimento {
private:
  int pinoLed;
  int pinoBotao;
  Servo controleServo;

public:
  bool tampaAberta;
  bool botaoPressionado;

  Compartimento();
  Compartimento(int pinoBotao, int pinoLed, int pinoServo);

  bool estadoBotao();
  void controlaCompartimento(unsigned modo);
  void abreTampa();
  void fechaTampa();
  static void fechaTodos(Compartimento **vetComp, int qtdCompartimento);
  static void abreIndividual(Compartimento **vetComp, Compartimento *comp, int qtdCompartimento);
};

#endif