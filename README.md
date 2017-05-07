# Organização De Arquivos T1 (Turma A)

## Documentação Externa:
https://www.overleaf.com/9308801srxcvkdjrfdd

## Ordem dos campos

Especificado no PDF.

## Divisão do trabalho:
[número] representa a especificação no PDF.
Ver o PDF pois tem váris especificações não citadas aqui.

1. Leitura e gravação de registros (LTKills) - [2]
2. Impressão de todos os registros + task 1 (martchellop) - [3] e [5]
3. Impressão de um registro procurando um campo (BrunoGomesCoelho) - [4]
4. Impressão de registro de offset X e campo Y desse registro - [6]

## Tasks:
1. Criar função: dado *fp e um offset, imprima aquele registro [5]. Fazer modularizada para poder ser chamada por quem implementar a parte 3. Basta chamar essa função sequencialmente para a impressão de todos os registros [3].

## Tipos de arquivos
Devem existir 3 tipos de organização de arquivos diferentes:
- campos de tamanho fixo + campos de tamanho variável com indicador de tamanho + registros de tamanho variável com indicador de tamanho
- campos de tamanho fixo + campos de tamanho variável com indicador de tamanho + registros de tamanho variável com delimitadores entre registros
- campos de tamanho fixo + campos de tamanho variável com indicador de tamanho + registros de tamanho variável com número fixo de campos
O usuário deve escolher qual o tipo de organização de arquivos ele usará em uma execução. Portanto, ele pode uma das três configurações possíveis e o sistema deve fornecer as funcionalidades conforme descrito na especificação do trabalho.
