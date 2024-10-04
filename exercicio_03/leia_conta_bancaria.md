Neste desafio, você irá implementar um sistema para gerenciar contas bancárias em um banco. O sistema permitirá que os clientes abram contas, realizem depósitos, saques, e exibam o saldo e as informações da conta. Além disso, você precisará implementar diferentes tipos de contas: contas correntes e contas poupança, cada uma com regras específicas.

Requisitos:
Criação de Contas:

O sistema deverá permitir a criação de contas bancárias. Cada conta deverá ter um nome de titular e um saldo inicial.
Haverá dois tipos de contas: Conta Corrente e Conta Poupança.
Conta Corrente:

A conta corrente permite que o cliente realize saques e depósitos.
Não pode permitir que o saldo fique negativo (sem cheque especial).
Conta Poupança:

A conta poupança também permite saques e depósitos, mas possui uma taxa de rendimento mensal que aumenta o saldo a cada mês.
O cliente poderá visualizar o saldo com os rendimentos acumulados.
Operações:

O sistema deve permitir as seguintes operações para qualquer tipo de conta:
Depósito: Adiciona um valor ao saldo da conta.
Saque: Subtrai um valor do saldo, mas não pode deixar o saldo negativo (mesmo para conta corrente).
Exibir informações: Exibe o nome do titular, o saldo atual, e o tipo de conta.
Aplicar rendimento (somente para contas poupança): Aplica uma taxa de 1% ao saldo, simulando o rendimento mensal.
Gerenciamento de Contas:

O sistema deve permitir que o banco gerencie múltiplas contas (utilizando um vetor de ponteiros para as contas).
Deve ser possível:
Exibir as informações de todas as contas.
Exibir as informações de uma conta específica com base no nome do titular.
Aplicar rendimento a todas as contas poupança.
Estrutura sugerida:
Você precisará de, pelo menos, as seguintes classes:

Classe Conta (classe base):

Atributos: nome do titular, saldo.
Métodos: depósito, saque, exibir informações.
Classe ContaCorrente (herda de Conta):

Sem atributos adicionais.
Regras específicas para saque e depósito (não pode ficar negativo).
Classe ContaPoupanca (herda de Conta):

Atributos: taxa de rendimento.
Métodos: aplicar rendimento (aumenta o saldo).
Classe Banco:

Gerencia um vetor de contas (tanto correntes quanto poupança).
Métodos para adicionar conta, exibir informações, aplicar rendimentos, etc.