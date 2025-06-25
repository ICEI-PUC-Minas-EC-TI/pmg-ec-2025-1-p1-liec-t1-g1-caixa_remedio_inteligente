#include <ESP32Servo.h>

#define nComp 3

#define buzzer 27

#define led1 4
#define led2 18
#define led3 19

#define botao1 27
#define botao2 26
#define botao3 25

#define servo1 21
#define servo2 22
#define servo3 23

class Compartimento {
   public:
    int led;
    int botao;
    Servo servo;

    bool pressionado;
    bool aberto;

    Compartimento() {}

    Compartimento(int pinoBotao, int pinoLed, int pinoServo) {
        pinMode(pinoBotao, INPUT);
        this->botao = pinoBotao;

        pinMode(pinoLed, OUTPUT);
        this->led = pinoLed;

        this->servo.attach(pinoServo);
        this->servo.write(0);

        this->aberto = false;
    }

    void controlaCompartimento(unsigned modo) {
        // modo = 1 -> abre a tampa e liga o LED
        // modo != 1 -> fecha a tampa e desliga o LED

        if (modo == 1) {
            this->abre();
            this->aberto = true;

            digitalWrite(this->led, 1);
        } else {
            this->fecha();
            this->aberto = false;

            digitalWrite(this->led, 0);
        }
    }

    void abre() {
        if (!this->aberto) {
            this->controlaCompartimento(1);
        }
    }

    void fecha() {
        this->controlaCompartimento(0);
        delay(300);

        this->aberto = false;
    }
};

void fechaCompartimentosAbertos(Compartimento vetComp[]);
void processaBotoesCompartimentos(Compartimento vetComp[]);

Compartimento *vetCompartimento[nComp];

void setup() {
    Serial.begin(9600);
    pinMode(buzzer, OUTPUT);

    vetCompartimento[0] = new Compartimento(botao1, led1, servo1);
    vetCompartimento[1] = new Compartimento(botao2, led2, servo2);
    vetCompartimento[2] = new Compartimento(botao3, led3, servo3);

    tone(buzzer, 440, 200);
}

void loop() {
         processaBotoesCompartimentos(vetCompartimento);
         delay(100);
    }
}

void fechaCompartimentosAbertos(Compartimento **vetComp) {
    for (int i = 0; i < nComp; i++) {
        if (vetComp[i]->aberto) {
            vetComp[i]->controlaCompartimento(0);
            delay(300);
        }
    }
}

void processaBotoesCompartimentos(Compartimento **vetComp) {
    for (int i = 0; i < nComp; i++) {
        if (digitalRead(vetComp[i]->botao) == HIGH) {
            if (!vetComp[i]->pressionado) {
                vetComp[i]->pressionado = true;

                if (vetComp[i]->aberto) {
                    vetComp[i]->fecha();
                    break;
                } else {
                    fechaCompartimentosAbertos(vetComp);

                    vetComp[i]->abre();
                }
            }
        } else {
            vetComp[i]->pressionado = false;
        }
    }
}
