# Introdução

A Caixa de Remédio Inteligente surge como resposta a um desafio comum na área da saúde: o esquecimento frequente de tomar medicamentos nos horários corretos. Muitos pacientes, especialmente aqueles que fazem uso contínuo de múltiplos remédios, enfrentam dificuldades para manter a disciplina terapêutica. Organizadores tradicionais apenas armazenam os comprimidos, deixando ao usuário a responsabilidade de lembrar-se dos horários. Nossa proposta une hardware acessível e um aplicativo móvel intuitivo, com o objetivo de automatizar essa rotina, tornando o processo mais seguro, eficiente e cômodo.

## Problema

Usuários que precisam tomar vários medicamentos diariamente enfrentam:

- Esquecimento frequente, agravado por rotinas agitadas ou declínio cognitivo em idosos;

- Falta de feedback em tempo real sobre a hora correta de tomar o remédio;

- Dependência de cuidadores para lembrar ou liberar o acesso às doses;

- Soluções comerciais caras ou difíceis de operar, sobretudo para quem tem pouca afinidade com apps complexos.

Nosso projeto pretende mitigar o risco de não adesão ao simplificar a rotina: a caixa só abre nos horários programados no aplicativo, acionando um alerta sonoro/visual e garantindo que o usuário tenha o medicamento certo na hora certa. 

## Objetivos

**Objetivo geral**

Conceber e prototipar uma solução de baixo custo que integre ESP32, servo-motor e aplicativo App Inventor via Bluetooth, permitindo ao usuário programar, receber alerta e liberar a caixa de medicamentos de forma segura e intuitiva.

**Objetivos específicos**

1. Desenvolver o mecanismo eletromecânico de travamento/abertura com servo-motor, buzzer e LED, alimentado diretamente pelo ESP32;

2. Implementar a comunicação Bluetooth entre aplicativo – feito no MIT App Inventor – e o microcontrolador, garantindo pareamento simples e comandos confiáveis;

3. Criar interface minimalista: botões para cadastro de horário, abertura manual emergencial e configuração de áudio de alarme;

4. Prototipar gabinete sustentável em papel cartão de alta gramatura, validando rigidez, custo e facilidade de montagem em comparação a alternativas impressas em 3D;

5. Avaliar usabilidade e eficácia em cenário-piloto com usuários que tomam múltiplos medicamentos, coletando feedback sobre intuitividade e redução de esquecimentos.
 
## Público-Alvo

O projeto é direcionado a um público amplo, como:

- Idosos que precisam de organização e lembretes para tomar múltiplos medicamentos ao longo do dia;

- Jovens e adultos que, mesmo familiarizados com tecnologia, enfrentam dificuldades em manter a regularidade na medicação;

- Cuidadores e familiares que desejam acompanhar e facilitar o controle de medicações de pessoas sob sua responsabilidade.

Pensando na acessibilidade, o aplicativo foi desenvolvido com uma interface objetiva, com poucas funções e fácil navegação. Isso permite que qualquer pessoa, mesmo com pouco conhecimento tecnológico, consiga utilizá-lo com facilidade e confiança.
