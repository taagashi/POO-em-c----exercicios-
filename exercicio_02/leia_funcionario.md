Exercício: Sistema de Gestão de Funcionários
Você vai implementar um sistema para gerenciar funcionários em uma empresa. O sistema deve permitir o cadastro de diferentes tipos de funcionários (horistas e vendedores), realizar cálculos de salários e bônus, além de exibir as informações dos funcionários e gerenciar demissões. Siga os passos abaixo para criar o sistema.

Requisitos:
Classe base Funcionarios:

Atributos:
nome (string): Nome do funcionário.
salario (float): Salário do funcionário.
Métodos:
Construtor que inicializa o nome e verifica se o salário é válido (maior que 0).
calcular_bonus: Aplica um bônus de 10% ao salário do funcionário.
exibir_info: Exibe o nome e o salário do funcionário.
Classe derivada Funcionario_horista (herda de Funcionarios):

Atributos adicionais:
horas_trabalhadas(int): Quantidade de horas trabalhadas pelo funcionário.
valor_por_hora: Valor recebido por cada hora trabalhada.
Métodos:
Construtor que inicializa horas_trabalhadas e valor_por_hora.
calcular_salario: Calcula o salário baseado nas horas trabalhadas e no valor por hora.
Sobrescreva o método exibir_info para mostrar também as horas trabalhadas e o valor por hora.
Classe derivada Funcionario_vendedor (herda de Funcionarios):

Atributos adicionais:
quantidade_vendas (int): Número de vendas realizadas pelo funcionário.
Métodos:
Construtor que inicializa a quantidade de vendas.
calcular_salario: Calcula o salário baseado na quantidade de vendas.
Sobrescreva o método exibir_info para mostrar também a quantidade de vendas.
Classe Empresa:

Atributos:
Um vetor de ponteiros para armazenar os funcionários da empresa.
Métodos:
contratar_funcionario: Adiciona um novo funcionário à empresa.
calcular_bonus_funcionarios: Calcula o bônus para todos os funcionários da empresa.
exibir_info_funcionarios: Exibe as informações de todos os funcionários.
Métodos adicionais para demitir funcionários e calcular salários específicos para horistas e vendedores.
Desafios Extras:
Demitir Funcionário: Crie um método que remova um funcionário da empresa.
Calcular Bônus Individual: Adicione a funcionalidade de calcular o bônus para um funcionário específico com base no nome.
Calcular Salário de Horistas/Vendedores: Crie métodos que calculem os salários de todos os horistas ou vendedores na empresa.
Regras:
Verifique se os dados de entrada (salários, horas, vendas) são válidos.
Certifique-se de que as funções de exibição só mostrem dados válidos.
Utilize herança para evitar duplicação de código entre os tipos de funcionários.