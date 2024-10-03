#include <iostream>
#include <string>
using namespace std;

class Pessoa {
private:
    string nome;
    int idade;
    float altura;

    //validacao de idade e altura
    bool validacao(int idade_, float altura_)
    {
        if(idade_>=0 && altura_>0)
        {
            return true;
        } else
        {
            return false;
        }
    }

public:
    // Construtor
    Pessoa(string nome, int idade, float altura)
    {
        if(validacao(idade,altura))
        {
            this->nome = nome;
            this->idade = idade;
            this->altura = altura;
        } else
        {
            cout << "Dados invalidos \n";
            this->idade = 0;
            this->altura = 0.0;
        }
    }

    // Getters
    string get_nome() {
        return this->nome;
    }

    int get_idade() {
        return this->idade;
    }

    float get_altura() {
        return this->altura;
    }

    // Setters
    void set_nome(string nome) {
        this->nome = nome;
    }

    void set_idade(int idade) {
        if (idade >= 0) {
            this->idade = idade;
        } else {
            cout << "Idade invalida.\n";
        }
    }

    void set_altura(float altura) {
        if (altura >= 0) {
            this->altura = altura;
        } else {
            cout << "Altura invalida.\n";
        }
    }

    // Método para exibir os dados da pessoa
    void exibir_dados() {
        cout << "Nome: " << this->nome << endl;
        cout << "Idade: " << this->idade << " anos" << endl;
        cout << "Altura: " << this->altura << " metros" << endl;
    }
};

// Funções utilitárias
void exibir_informacoes(Pessoa);
void mudar_nome(Pessoa&, const string&);
void mudar_altura(Pessoa&, float);
void mudar_idade(Pessoa&, int);
void exibir_nome(Pessoa);
void exibir_idade(Pessoa);
void exibir_altura(Pessoa);

int main() {
    // Criando um objeto Pessoa
    Pessoa humano("Joao", -10, 1.70);

    // Exibindo informações iniciais
    exibir_informacoes(humano);

    // Alterando e exibindo o nome
    mudar_nome(humano, "Maria");
    exibir_nome(humano);

    // Alterando idade e altura
    mudar_idade(humano, 40);
    mudar_altura(humano, 2.0);

    // Exibindo as informações atualizadas
    exibir_informacoes(humano);

    return 0;
}

// Definindo as funções externas
void exibir_informacoes(Pessoa ser) {
    ser.exibir_dados();
}

void mudar_nome(Pessoa& ser, const string& novo_nome) {
    ser.set_nome(novo_nome);
}

void mudar_altura(Pessoa& ser, float nova_altura) {
    ser.set_altura(nova_altura);
}

void mudar_idade(Pessoa& ser, int nova_idade) {
    ser.set_idade(nova_idade);
}

void exibir_nome(Pessoa ser) {
    cout << "Nome: " << ser.get_nome() << endl;
}

void exibir_idade(Pessoa ser) {
    cout << "Idade: " << ser.get_idade() << endl;
}

void exibir_altura(Pessoa ser) {
    cout << "Altura: " << ser.get_altura() << endl;
}
