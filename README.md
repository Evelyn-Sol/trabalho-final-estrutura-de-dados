Sistema de Fila Hospitalar por Prioridade

Este projeto foi desenvolvido como trabalho final da disciplina Estrutura de Dados. O objetivo foi implementar uma fila de atendimento hospitalar baseada em prioridades, simulando o fluxo de pacientes e gerando estatísticas relevantes sobre o atendimento.

🏥 Objetivo

Criar uma estrutura de dados capaz de:

Organizar pacientes por níveis de prioridade;

Simular a chegada e o atendimento em uma fila hospitalar;

Registrar estatísticas sobre o processo.

⚙️ Funcionalidades
✔️ Cadastro de pacientes

Cada paciente possui:

Senha

Prioridade (v = vermelha, a = amarela, d = verde, b = azul)

Horário de chegada

✔️ Fila com prioridade

A fila utiliza uma estrutura que garante que pacientes com maior prioridade sejam atendidos primeiro.

✔️ Estatísticas geradas

Ao final da simulação, o sistema exibe:

Total de pacientes atendidos

Total atendido por prioridade

Pico de lotação da fila

Tempo médio de espera

Tempo máximo de espera

🧱 Estruturas de Dados Utilizadas

Filas para organizar pacientes por nível de prioridade

Structs para armazenar informações dos pacientes

Funções para tranformação de horas

Funções para menu

Biblitecas queue e algorithm
