# Organização De Arquivos T1 (Turma A)

## Divisão do trabalho:
1. Leitura e gravação de registros (LTKills)
2. Impressão de todos os registros + task 2
3. Impressão de um registro procurando um campo (BrunoGomesCoelho)
4. Impressão de registro de offset X e campo Y desse registro + task 2

## Tasks:
1. Criar função: dado *fp e offset, imprima o campo (precisa de um inteiro pra saber se o campo tem tamanho fixo, se for tamanho fixo esse inteiro é o tamanho do campo a ser impresso, se for -1, o tamanho é variável)
2. Criar função: dado *fp e um offset, imprima todo o registro
3. Criar função: procure pelo valor X no campo Y e imprima todos os registros para os quais isso seja verdade

## Tipos de arquivos
Devem existir 3 tipos de organização de arquivos diferentes:
- campos de tamanho fixo + campos de tamanho variável com indicador de tamanho + registros de tamanho variável com indicador de tamanho
- campos de tamanho fixo + campos de tamanho variável com indicador de tamanho + registros de tamanho variável com delimitadores entre registros
- campos de tamanho fixo + campos de tamanho variável com indicador de tamanho + registros de tamanho variável com número fixo de campos
O usuário deve escolher qual o tipo de organização de arquivos ele usará em uma execução. Portanto, ele pode uma das três configurações possíveis e o sistema deve fornecer as funcionalidades conforme descrito na especificação do trabalho.
