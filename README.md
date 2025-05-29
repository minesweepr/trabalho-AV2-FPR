# Trabalho Avaliativo
## Objetivo

Deve-se desenvolver um programa que:

* Leia dados de cursos de uma instituição a partir de um arquivo texto (cada linha contém informações de um curso, incluindo insumos e número de alunos).

* Armazene os dados em um vetor de structs.

* Calcule o CPC contínuo (média ponderada dos insumos) e determine a faixa do CPC (de 1 a 5) para cada curso.

* Classifique os cursos como “satisfatório” (CPC ≥ 3) ou “insatisfatório” (CPC < 3).

* Exiba:

     \> Código, CPC contínuo, CPC faixa e classificação de cada curso;

     \> Lista de cursos agrupados por faixa;

     \> IGC da instituição (média ponderada dos CPCs contínuos, usando o número de alunos como peso), também com faixa.

* O programa deve ainda:

     \> Permitir ao usuário adicionar novos cursos;

     \> Estar modularizado (uso de funções);

     \> Usar apenas estruturas estudadas até agora.


## Informações Gerais

- **Valor total**: 3pts
- **Data de entrega**: 15/06/2025
- **Data de início**: 25/05/2025
- ![Last Updated](https://img.shields.io/github/last-commit/minesweeper1989/trabalho-AV2-FPR)

## Observações Futuras
- **Nota**: TBA
- **Feedback**: TBA
Essa parte está garantida para quando se encerrar o período de entregas e o professor enviar a correção do trabalho.

## Notas
- Para garantir a funcionalidade do programa, é necessário criar um arquivo de texto chamado ```cursos.txt```. Esse arquivo pode estar vazio, mas, caso contenha dados, eles devem seguir o seguinte formato: 

  ```1234|3.45|2.87|1.98|4.05|2.50|1.34|1.76|2.32|258```
  
  Que pode ser lido como: 
  
  ```codigo|enade|idd|doutores|mestres|regtrabalho|orgdiped|infra|oport|alunos```
