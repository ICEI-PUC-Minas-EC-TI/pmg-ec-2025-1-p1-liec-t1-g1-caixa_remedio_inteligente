
# Materiais

Os materiais utilizados no projeto foram:

**ESP32** – Microcontrolador responsável pelo controle do hardware e pela comunicação com o aplicativo via Bluetooth.

**Servo Motor SG90** – Atuador utilizado para realizar o movimento de abertura e fechamento da tampa da caixa.

**Protoboard** – Base de montagem dos circuitos, permitindo conexões seguras e reutilizáveis.

**Jumpers (cabos de conexão)** – Para interligar os componentes na protoboard e conectar ao ESP32.

**Resistores** – Utilizados para controle de corrente em pontos estratégicos do circuito.

**LED** – Indicador visual de acionamento.

**Buzzer** – Componente sonoro que atua como alarme ao disparar a abertura programada.

**Caixa protótipo em papel resistente** – Estrutura física desenvolvida manualmente, substituindo a ideia original de impressão 3D.

**Cabo USB** – Utilizado para alimentar o ESP32 diretamente do computador durante o funcionamento.

# Desenvolvimento

O desenvolvimento da Caixa de Remédio Inteligente foi dividido em etapas específicas, contemplando a criação do aplicativo, montagem do hardware e a integração entre ambas as partes.

## Desenvolvimento do Aplicativo
**Interface**
A interface do aplicativo foi criada com o objetivo de ser simples, acessível e funcional, utilizando a plataforma MIT App Inventor. O layout apresenta:

- Uma tela inicial com botões de funções principais: definir alarme, abrir manualmente e tocar alarme;

- Uma tela dedicada para pareamento Bluetooth com o ESP32.

Todos os botões são bem posicionados, de fácil compreensão, e otimizados para atender usuários com diversos níveis de familiaridade com tecnologia.

**Código**

O código do aplicativo foi desenvolvido por meio da lógica de blocos do App Inventor. Cada botão está associado a comandos que são enviados via Bluetooth ao ESP32, sendo esses comandos interpretados como instruções específicas:

- Abrir a tampa;

- Ativar o buzzer e o LED;

- Encerrar o alarme.

A estrutura do código garante estabilidade e baixo risco de falhas durante a transmissão dos comandos.

### Interface

Descreva o desenvolvimento das telas do aplicativo.

### Código

Descreva o desenvolvimento do código do aplicativo.

## Desenvolvimento do Hardware

### Montagem

Descreva como foi o processo da montagem do projeto.

### Desenvolvimento do Código

Descreva como foi o desenvolvimento do código do arduino/ESP.

## Comunicação entre App e Hardware

Descreva como foi o processo de comunicação entre App e arduino/ESP.
