# Testes do Projeto

Os testes da Caixa de Remédio Inteligente foram realizados após a montagem do circuito eletrônico e o desenvolvimento inicial do aplicativo. Primeiramente, foram executados testes individuais com os componentes, utilizando o terminal serial da Arduino IDE para validar o funcionamento do servo motor, buzzer, LED e comunicação Bluetooth.

Com os componentes integrados, a equipe realizou testes práticos utilizando o aplicativo desenvolvido no App Inventor. Foi possível verificar que, ao acionar os botões do aplicativo, o comando era recebido corretamente pelo ESP32, que então executava a ação correspondente, como a abertura da caixa ou a ativação do alarme sonoro e visual.

O sistema apresentou boa estabilidade na comunicação e tempo de resposta satisfatório. A simplicidade da interface também foi validada por usuários do próprio grupo, que conseguiram operar o aplicativo sem dificuldade.

Entretanto, foram observadas algumas limitações: a alimentação do ESP32 é feita exclusivamente via cabo USB, restringindo a mobilidade do dispositivo; a estrutura da caixa, feita em papel resistente, apresenta baixa durabilidade; e o aplicativo ainda não fornece feedback visual após a execução de um comando, o que pode gerar dúvidas ao usuário.

Apesar dessas questões, o protótipo se mostrou funcional e promissor para futuras melhorias.
