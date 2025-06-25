
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

### Interface

A interface do aplicativo foi criada com o objetivo de ser simples, acessível e funcional, utilizando a plataforma MIT App Inventor. O layout apresenta:

- Uma tela inicial com botões de funções principais: definir alarme, abrir manualmente e tocar alarme;

- Uma tela dedicada para pareamento Bluetooth com o ESP32.

Todos os botões são bem posicionados, de fácil compreensão, e otimizados para atender usuários com diversos níveis de familiaridade com tecnologia.

### Código

O código do aplicativo foi desenvolvido por meio da lógica de blocos do App Inventor. Cada botão está associado a comandos que são enviados via Bluetooth ao ESP32, sendo esses comandos interpretados como instruções específicas:

- Abrir a tampa;

- Ativar o buzzer e o LED;

- Encerrar o alarme.

A estrutura do código garante estabilidade e baixo risco de falhas durante a transmissão dos comandos.


## Desenvolvimento do Hardware

### Montagem

A montagem do hardware foi realizada de forma progressiva:

1. Organização da protoboard com o ESP32, servo motor, buzzer, LED e resistores.

2. Conexão dos componentes utilizando jumpers, de acordo com os pinos de controle definidos no código.

3. Execução de testes preliminares por meio do Tinkercad, simulando a montagem antes da execução física.

4. Fixação do conjunto eletrônico à caixa feita em papel resistente, adaptando-se às limitações técnicas do momento.

Embora a proposta inicial envolvesse um modelo impresso em 3D, a equipe optou pela versão manual devido à indisponibilidade da impressora 3D no laboratório da faculdade.

### Desenvolvimento do Código

O código foi implementado na Arduino IDE, utilizando as bibliotecas BluetoothSerial e ESP32Servo. A estrutura geral é composta por:

- Setup: inicialização da comunicação serial, configuração dos pinos e preparação do servo motor.

- Loop principal: leitura dos comandos Bluetooth e execução das ações conforme os dados recebidos.

O controle das ações se dá com base em condições simples, garantindo que cada instrução enviada pelo aplicativo resulte em uma resposta direta e confiável por parte do ESP32.

## Comunicação entre App e Hardware

A comunicação entre o aplicativo e o microcontrolador ESP32 ocorre via Bluetooth, de forma estável e contínua. No App Inventor, foi utilizada a funcionalidade nativa de Bluetooth para se conectar ao dispositivo, com blocos que enviam strings específicas quando os botões são acionados.

No ESP32, a biblioteca BluetoothSerial foi utilizada para escutar essas mensagens e converter os comandos em ações físicas, como o movimento do servo motor, o acionamento do buzzer ou a sinalização com o LED. Esse processo torna a comunicação eficiente e de fácil replicação.
