#include <ESP32Servo.h>

#define nComp 3

#define buzzer 6

#define led1 13
#define led2 12
#define led3 8

#define botao1 2
#define botao2 4
#define botao3 7

#define servo1 11
#define servo2 10
#define servo3 9

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
            this->servo.write(45);
            this->aberto = true;

            digitalWrite(this->led, 1);
        } else {
            this->servo.write(0);
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

Compartimento comps[nComp];
BluetoothSerial SerialBT;

void setup() {
    Serial.begin(9600);

    SerialBT.begin("Caixa de Remédio");
    Serial.println("Pronto para parear!");

    pinMode(buzzer, OUTPUT);

    comps[0] = Compartimento(botao1, led1, servo1);
    comps[1] = Compartimento(botao2, led2, servo2);
    comps[2] = Compartimento(botao3, led3, servo3);

    tone(buzzer, 440, 200);
}

void loop() {
    processaBotoesCompartimentos(comps);
    delay(20);
}

void fechaCompartimentosAbertos(Compartimento vetComp[]) {
    for (int i = 0; i < nComp; i++) {
        if (vetComp[i].aberto) {
            vetComp[i].controlaCompartimento(0);
            delay(300);
        }
    }
}

void processaBotoesCompartimentos(Compartimento vetComp[]) {
    for (int i = 0; i < nComp; i++) {
        if (digitalRead(vetComp[i].botao) == HIGH) {
            if (!vetComp[i].pressionado) {
                vetComp[i].pressionado = true;

                if (vetComp[i].aberto) {
                    vetComp[i].fecha();
                    break;
                } else {
                    fechaCompartimentosAbertos(vetComp);

                    vetComp[i].abre();
                }
            }
        } else {
            vetComp[i].pressionado = false;
        }
    }
}