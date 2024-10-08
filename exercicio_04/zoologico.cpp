#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Animal
{
    protected:
    string nome;

    private:
    int idade;
    string especie;
    float peso;
    bool validoAnimal;

    public:
    Animal(string nome, int idade, string especie, float peso)
    {
        if(idade>=0 && peso>0)
        {
            this->nome = nome;
            this->idade = idade;
            this->especie = especie;
            this->peso = peso;
            validoAnimal = true;
        }else
        {
            validoAnimal = false;
            cout << "Voce precisa digitar idade e peso validos \n";
        }
    }

    virtual void cuidadosEspeciais()
    {
        if(validoAnimal)
        {
            cout << "Agora voce esta cuidando do " << nome << endl;
        }else
        {
            cout << "Voce precisa registrar um animal com dados validos \n";
        }
    }

    virtual void exibirInformacoes()
    {
        if(validoAnimal)
        {
            cout << "nome: " << nome << endl;
            cout << "idade: " << idade << endl;
            cout << "especie: " << especie << endl;
            cout << "peso: " << peso << endl;
        }else
        {
            cout << "Existem dados invalidos desse animal \n";
        }
    }

    bool getvalidoAnimal()
    {
        return validoAnimal;
    }

    string getnome()
    {
        return nome;
    }

};

class Gato : public Animal
{
    public:
    Gato(string nome, int idade, string especie, float peso)
    : Animal(nome,idade,especie,peso){}

    void emitirSom()
    {
        if(getvalidoAnimal())
        {
            cout << "Miau, e o som que " << nome << " faz \n";
        }else
        {
            cout << "Este animal possui dados invalidos. Corrija \n";
        }
    }

    void cuidadosEspeciais() override
    {
        if(getvalidoAnimal())
        {
            Animal::cuidadosEspeciais();
            cout << "Voce da um belo banho no gatinho \n";
            cout << nome << " agora esta muito feliz e cheirando bem \n";

        }else
        {
            cout << "O gato nao esta registrado porque possui dados invalidos \n";
        }
    }

    void exibirInformacoes() override
    {
        if(getvalidoAnimal())
        {
            cout << "Gato \n";
            Animal::exibirInformacoes();
        }else
        {
            cout << "Nao eh possivel acessar esse metodo. Dados invalidos \n";
        }

    }
};

class Cachorro : public Animal
{
    public:
    Cachorro(string nome, int idade, string especie, float peso)
    : Animal(nome,idade,especie,peso){}

    void emitirSom()
    {
        if(getvalidoAnimal())
        {
            cout << nome << " late com um som muito amoroso \n";
        }else
        {
            cout << "Este cao possui dados invalidos de idade ou peso. Corrija \n";
        }
    }

    void cuidadosEspeciais() override
    {
        if(getvalidoAnimal())
        {
            Animal::cuidadosEspeciais();
            cout << "Voce limpa o pelo delicadamente de " << nome << endl;
            cout << "agora " << nome << " esta extremamente lindo \n";
        }else
        {
            cout << "Corrija os dados invalidos para acessar essa parte \n";
        }
    }

    void exibirInformacoes() override
    {
        if(getvalidoAnimal())
        {
            cout << "Cachorro \n";
            Animal::exibirInformacoes();
        }else
        {
            cout << "Nao eh possivel acessar esse metodo. Dados invalidos \n";
        }

    }

};

class Leao : public Animal
{
    public:
    Leao(string nome, int idade, string especie, float peso)
    : Animal(nome,idade,especie,peso){}

    void emitirSom()
    {
        if(getvalidoAnimal())
        {
            cout << nome << " emite um rugido muito intimidador \n";
        }else
        {
            cout << "Corrija os dados invalidos do leao para emitir um som \n";
        }
    }

    void cuidadosEspeciais()
    {
        if(getvalidoAnimal())
        {
            Animal::cuidadosEspeciais();
            cout << "Voce verifica a temperatura do leao \n";
            cout << nome << " esta com sua temperatura perfeita \n";        
        }else
        {
            cout << "Nao eh possivel acessar esse metodo porque o leao nao esta cadastrado \n";
            cout << "Corrija esses dados invalidos \n";
        }

    }

    void exibirInformacoes() override
    {
        if(getvalidoAnimal())
        {
            cout << "Leao \n";
            Animal::exibirInformacoes();
        }else
        {
            cout << "Nao eh possivel acessar esse metodo. Dados invalidogetvalidoAnimals \n";
        }

    }
};

class Alimento
{
    private:
    string tipoAlimento;
    int quantidadeAlimento;
    bool validoAlimento;

    public:
    Alimento(string tipoAlimento, int quantidadeAlimento)
    {
        if(quantidadeAlimento>0)
        {
            this->tipoAlimento = tipoAlimento;
            this->quantidadeAlimento = quantidadeAlimento;
            validoAlimento = true;
        }else
        {
            validoAlimento = false;
        }
    }

    bool getvalidoAlimento()
    {
        return validoAlimento;
    }

    const string getTipoAlimento()
    {
        return tipoAlimento;
    }

    int getQuantidadeDeAlimento()
    {
        return quantidadeAlimento;
    }

    void SetQuantidaDeAlimento()
    {
        if(quantidadeAlimento>0)
        {
            quantidadeAlimento-=1;
        }else
        {
            cout << "Nao eh possivel alimentar porque o estoque de " << tipoAlimento << " acabou \nAbasteca o estoque \n";
        }
    }

    void setQuantidaDeAlimento(int alimentos)
    {
        if(alimentos>0)
        {
            quantidadeAlimento+=alimentos;
        }else
        {
            cout << "Digite uma quantidade de alimentos possivel \n";
        }
    }
};


class Funcionarios
{
    private:
    string nome;
    string cargo;
    float salario;
    bool validoSalario;
    vector<Animal*> animal;
    

    Animal* verificador(Animal* animal)
    {
        
        for(auto& nav : this->animal)
          {
             if(nav->getnome() == animal->getnome())
              {                    
                  return nav;
              }
          }

        return nullptr;
        
    }

    public:
    Funcionarios(string nome, string cargo, float salario)
    {
        if(salario>0)
        {
            this->nome = nome;
            this->cargo = cargo;
            this->salario = salario;
            validoSalario = true;
        }else
        {
            cout << "Voce precisa digitar um salario valido \n";
            validoSalario = false;
        }
    }

    void cuidarDeUmAnimalNome(Animal* cuidarAnimal)
    {
        if(validoSalario)
        {

            if(cuidarAnimal->getvalidoAnimal() == true)
            {
                animal.push_back(cuidarAnimal);
            }else
            {
                cout << nome << " tem que cuidar de animais que estejam registrados \n";
            }
        }else
        {
            cout << "Este funcionario tem dados invalidos. Corrija \n";
        }
    }

    void calcularSalario()
    {
        if(validoSalario)
        {

            int quantidade = animal.size();
            if(quantidade>0)
            {
                salario*= quantidade;
                cout << "Salario de " << nome << " calculado \n";
             cout << "ele(a) esta cuidando de " << quantidade << " animais \n";
            }else
            {
                cout << "E necessario que o funcionario esteja cuidando de algum animal \n";
            }

        }else
        {
            cout << "Este funcionario tem dados invalidos. Corrija \n";
        }
    }

    void adicionarBonus()
    {
        if(validoSalario)
        {
            salario*= 0.10;
            cout << "Bonus de 10% para " << nome << endl;
        }else
        {
            cout << "Dados do funcionario estao invalidoos \n";
        }
    }

    void exibirInformacoes()
    {
        if(validoSalario)
        {
            cout << "Nome: " << nome << endl;
            cout << "Cargo: " << cargo << endl;
            cout << "Quantidade de animais em cuidado: " << animal.size() << endl;
        }else
        {
            cout << "Nao eh possivel acessar esse metodo porque o funcionario tem dados invalidos \n";
        }
    }

    void cuidadoEspeciaisNome(Animal* cuidadoAnimal)
    {
        if(validoSalario)
        {
            if(animal.size()>0)
            {
                cuidadoAnimal = verificador(cuidadoAnimal);
                if(cuidadoAnimal!=nullptr)
                {
                    cuidadoAnimal->cuidadosEspeciais();
                }else
                {
                    cout << "O animal em questao nao esta sob cuidados de " << nome << endl;
                }
            }else
            {
                cout << "O funcionario " << nome << " precisa estar cuidando de um animal \n";
            }
        }else
        {
            cout << "Este funcionario tem dados invalids. Corrija \n";
        }
    }

    void listaAnimaisCuidadosNome(Animal* cuidadoAnimal)
    {
        if(validoSalario)
        {
            if(animal.size()>0)
            {
                cuidadoAnimal = verificador(cuidadoAnimal);
                if(cuidadoAnimal!=nullptr)
                {
                    cuidadoAnimal->exibirInformacoes();
                }else
                {
                    cout << "O animal em questao nao esta sob cuidados de " << nome << endl;
                }
            }else
            {
                cout << "O funcionario " << nome << " precisa estar cuidando de um animal \n";
            }
        }else
        {
            cout << "Este funcionario tem dados invalidos. Corrija \n";
        }
    }

    void listaTodosAnimaisCuidados()
    {
        if(validoSalario)
        {
            if(animal.size()>0)
            {
                for(auto& nav : animal)
                {
                     nav->exibirInformacoes();
                    cout << endl;
                }

            }else
            {
                cout << "Este funcionario nao esta cuidando de nenhum animal \n";
            }   
        }else
        {
            cout << "Este funcionario tem dados invalidos. Corrija \n";
        }
    }

    void alimentarAnimalNome(Animal* cuidadoAnimal, Alimento* alimento)
    {
        if(validoSalario)
        {
            if(animal.size()>0)
            {
                cuidadoAnimal = verificador(cuidadoAnimal);
                if(cuidadoAnimal!=nullptr && alimento->getvalidoAlimento())
                {
                    alimento->SetQuantidaDeAlimento();
                    cout << cuidadoAnimal->getnome() << " foi muito bem alimentado com " << alimento->getTipoAlimento() << endl;
                }else
                {
                    cout << "Animal nao esta sob cuidados do funcionario " << nome << " ou o alimento tem dados invalidos \n";
                }
            }else
            {
                cout << "O funcionario precisa cuidar de pelo menos um animal para alimeta-lo \n";
            }
        }else
        {
            cout << "Este funcionario possui dados invalidos \n";
        }    
    }

    void verEstoqueDeAlimento(Alimento* alimento)
    {
        if(validoSalario)
        {
            if(alimento->getvalidoAlimento())
            {
                cout << "Existem " << alimento->getQuantidadeDeAlimento() << " " << alimento->getTipoAlimento() << " no estoque \n";
            }else
            {
                cout << "Este alimento possui qunatidades invalidas \n";
            }
        }else
        {
            cout << "Funcionario nao pode realizar essa acao porque possui dados invalidos \n";
        }
    }

    void ReporEstoqueAlimento(Alimento* alimento, int novaQuantidade)
    {
        if(validoSalario)
        {
            if(alimento->getvalidoAlimento())
            {
                alimento->setQuantidaDeAlimento(novaQuantidade);
            }else
            {
                cout << "Este alimento possui quantidades invalidas \n";
            }
        }else
        {
            cout << "Funcionario nao pode realizar essa acao porque possui dados invalidos \n";
        }
    }


};


int main()
{
    Funcionarios thaua("Thaua","Cuidador",20000);

    Alimento carne ("Carne",30);
    Alimento racao ("Racao",20);

    Gato mimi("mimi",12,"felino",12);
    Cachorro dogma("Dogma",19,"Bulldog",20.2);
    Leao lion("Lion",20,"sei nao",50.3);

    thaua.cuidarDeUmAnimalNome(&mimi);
    thaua.cuidarDeUmAnimalNome(&dogma);

    thaua.cuidadoEspeciaisNome(&dogma);

    thaua.alimentarAnimalNome(&mimi,&carne);
    thaua.alimentarAnimalNome(&dogma,&racao);

    thaua.verEstoqueDeAlimento(&carne);

    thaua.ReporEstoqueAlimento(&carne,1);
    thaua.ReporEstoqueAlimento(&racao,10);

    thaua.calcularSalario();
    
    thaua.exibirInformacoes();

    thaua.listaTodosAnimaisCuidados();

    
    
    
}



#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Animal
{
    protected:
    string nome;

    private:
    int idade;
    string especie;
    float peso;
    bool validoAnimal;

    public:
    Animal(string nome, int idade, string especie, float peso)
    {
        if(idade>=0 && peso>0)
        {
            this->nome = nome;
            this->idade = idade;
            this->especie = especie;
            this->peso = peso;
            validoAnimal = true;
        }else
        {
            validoAnimal = false;
            cout << "Voce precisa digitar idade e peso validos \n";
        }
    }

    virtual void cuidadosEspeciais()
    {
        if(validoAnimal)
        {
            cout << "Agora voce esta cuidando do " << nome << endl;
        }else
        {
            cout << "Voce precisa registrar um animal com dados validos \n";
        }
    }

    virtual void exibirInformacoes()
    {
        if(validoAnimal)
        {
            cout << "nome: " << nome << endl;
            cout << "idade: " << idade << endl;
            cout << "especie: " << especie << endl;
            cout << "peso: " << peso << endl;
        }else
        {
            cout << "Existem dados invalidos desse animal \n";
        }
    }

    bool getvalidoAnimal()
    {
        return validoAnimal;
    }

    string getnome()
    {
        return nome;
    }

};

class Gato : public Animal
{
    public:
    Gato(string nome, int idade, string especie, float peso)
    : Animal(nome,idade,especie,peso){}

    void emitirSom()
    {
        if(getvalidoAnimal())
        {
            cout << "Miau, e o som que " << nome << " faz \n";
        }else
        {
            cout << "Este animal possui dados invalidos. Corrija \n";
        }
    }

    void cuidadosEspeciais() override
    {
        if(getvalidoAnimal())
        {
            Animal::cuidadosEspeciais();
            cout << "Voce da um belo banho no gatinho \n";
            cout << nome << " agora esta muito feliz e cheirando bem \n";

        }else
        {
            cout << "O gato nao esta registrado porque possui dados invalidos \n";
        }
    }

    void exibirInformacoes() override
    {
        if(getvalidoAnimal())
        {
            cout << "Gato \n";
            Animal::exibirInformacoes();
        }else
        {
            cout << "Nao eh possivel acessar esse metodo. Dados invalidos \n";
        }

    }
};

class Cachorro : public Animal
{
    public:
    Cachorro(string nome, int idade, string especie, float peso)
    : Animal(nome,idade,especie,peso){}

    void emitirSom()
    {
        if(getvalidoAnimal())
        {
            cout << nome << " late com um som muito amoroso \n";
        }else
        {
            cout << "Este cao possui dados invalidos de idade ou peso. Corrija \n";
        }
    }

    void cuidadosEspeciais() override
    {
        if(getvalidoAnimal())
        {
            Animal::cuidadosEspeciais();
            cout << "Voce limpa o pelo delicadamente de " << nome << endl;
            cout << "agora " << nome << " esta extremamente lindo \n";
        }else
        {
            cout << "Corrija os dados invalidos para acessar essa parte \n";
        }
    }

    void exibirInformacoes() override
    {
        if(getvalidoAnimal())
        {
            cout << "Cachorro \n";
            Animal::exibirInformacoes();
        }else
        {
            cout << "Nao eh possivel acessar esse metodo. Dados invalidos \n";
        }

    }

};

class Leao : public Animal
{
    public:
    Leao(string nome, int idade, string especie, float peso)
    : Animal(nome,idade,especie,peso){}

    void emitirSom()
    {
        if(getvalidoAnimal())
        {
            cout << nome << " emite um rugido muito intimidador \n";
        }else
        {
            cout << "Corrija os dados invalidos do leao para emitir um som \n";
        }
    }

    void cuidadosEspeciais()
    {
        if(getvalidoAnimal())
        {
            Animal::cuidadosEspeciais();
            cout << "Voce verifica a temperatura do leao \n";
            cout << nome << " esta com sua temperatura perfeita \n";        
        }else
        {
            cout << "Nao eh possivel acessar esse metodo porque o leao nao esta cadastrado \n";
            cout << "Corrija esses dados invalidos \n";
        }

    }

    void exibirInformacoes() override
    {
        if(getvalidoAnimal())
        {
            cout << "Leao \n";
            Animal::exibirInformacoes();
        }else
        {
            cout << "Nao eh possivel acessar esse metodo. Dados invalidogetvalidoAnimals \n";
        }

    }
};

class Alimento
{
    private:
    string tipoAlimento;
    int quantidadeAlimento;
    bool validoAlimento;

    public:
    Alimento(string tipoAlimento, int quantidadeAlimento)
    {
        if(quantidadeAlimento>0)
        {
            this->tipoAlimento = tipoAlimento;
            this->quantidadeAlimento = quantidadeAlimento;
            validoAlimento = true;
        }else
        {
            validoAlimento = false;
        }
    }

    bool getvalidoAlimento()
    {
        return validoAlimento;
    }

    const string getTipoAlimento()
    {
        return tipoAlimento;
    }

    int getQuantidadeDeAlimento()
    {
        return quantidadeAlimento;
    }

    void SetQuantidaDeAlimento()
    {
        if(quantidadeAlimento>0)
        {
            quantidadeAlimento-=1;
        }else
        {
            cout << "Nao eh possivel alimentar porque o estoque de " << tipoAlimento << " acabou \nAbasteca o estoque \n";
        }
    }

    void setQuantidaDeAlimento(int alimentos)
    {
        if(alimentos>0)
        {
            quantidadeAlimento+=alimentos;
        }else
        {
            cout << "Digite uma quantidade de alimentos possivel \n";
        }
    }
};


class Funcionarios
{
    private:
    string nome;
    string cargo;
    float salario;
    bool validoSalario;
    vector<Animal*> animal;
    

    Animal* verificador(Animal* animal)
    {
        
        for(auto& nav : this->animal)
          {
             if(nav->getnome() == animal->getnome())
              {                    
                  return nav;
              }
          }

        return nullptr;
        
    }

    public:
    Funcionarios(string nome, string cargo, float salario)
    {
        if(salario>0)
        {
            this->nome = nome;
            this->cargo = cargo;
            this->salario = salario;
            validoSalario = true;
        }else
        {
            cout << "Voce precisa digitar um salario valido \n";
            validoSalario = false;
        }
    }

    void cuidarDeUmAnimalNome(Animal* cuidarAnimal)
    {
        if(validoSalario)
        {

            if(cuidarAnimal->getvalidoAnimal() == true)
            {
                animal.push_back(cuidarAnimal);
            }else
            {
                cout << nome << " tem que cuidar de animais que estejam registrados \n";
            }
        }else
        {
            cout << "Este funcionario tem dados invalidos. Corrija \n";
        }
    }

    void calcularSalario()
    {
        if(validoSalario)
        {

            int quantidade = animal.size();
            if(quantidade>0)
            {
                salario*= quantidade;
                cout << "Salario de " << nome << " calculado \n";
             cout << "ele(a) esta cuidando de " << quantidade << " animais \n";
            }else
            {
                cout << "E necessario que o funcionario esteja cuidando de algum animal \n";
            }

        }else
        {
            cout << "Este funcionario tem dados invalidos. Corrija \n";
        }
    }

    void adicionarBonus()
    {
        if(validoSalario)
        {
            salario*= 0.10;
            cout << "Bonus de 10% para " << nome << endl;
        }else
        {
            cout << "Dados do funcionario estao invalidoos \n";
        }
    }

    void exibirInformacoes()
    {
        if(validoSalario)
        {
            cout << "Nome: " << nome << endl;
            cout << "Cargo: " << cargo << endl;
            cout << "Quantidade de animais em cuidado: " << animal.size() << endl;
        }else
        {
            cout << "Nao eh possivel acessar esse metodo porque o funcionario tem dados invalidos \n";
        }
    }

    void cuidadoEspeciaisNome(Animal* cuidadoAnimal)
    {
        if(validoSalario)
        {
            if(animal.size()>0)
            {
                cuidadoAnimal = verificador(cuidadoAnimal);
                if(cuidadoAnimal!=nullptr)
                {
                    cuidadoAnimal->cuidadosEspeciais();
                }else
                {
                    cout << "O animal em questao nao esta sob cuidados de " << nome << endl;
                }
            }else
            {
                cout << "O funcionario " << nome << " precisa estar cuidando de um animal \n";
            }
        }else
        {
            cout << "Este funcionario tem dados invalids. Corrija \n";
        }
    }

    void listaAnimaisCuidadosNome(Animal* cuidadoAnimal)
    {
        if(validoSalario)
        {
            if(animal.size()>0)
            {
                cuidadoAnimal = verificador(cuidadoAnimal);
                if(cuidadoAnimal!=nullptr)
                {
                    cuidadoAnimal->exibirInformacoes();
                }else
                {
                    cout << "O animal em questao nao esta sob cuidados de " << nome << endl;
                }
            }else
            {
                cout << "O funcionario " << nome << " precisa estar cuidando de um animal \n";
            }
        }else
        {
            cout << "Este funcionario tem dados invalidos. Corrija \n";
        }
    }

    void listaTodosAnimaisCuidados()
    {
        if(validoSalario)
        {
            if(animal.size()>0)
            {
                for(auto& nav : animal)
                {
                     nav->exibirInformacoes();
                    cout << endl;
                }

            }else
            {
                cout << "Este funcionario nao esta cuidando de nenhum animal \n";
            }   
        }else
        {
            cout << "Este funcionario tem dados invalidos. Corrija \n";
        }
    }

    void alimentarAnimalNome(Animal* cuidadoAnimal, Alimento* alimento)
    {
        if(validoSalario)
        {
            if(animal.size()>0)
            {
                cuidadoAnimal = verificador(cuidadoAnimal);
                if(cuidadoAnimal!=nullptr && alimento->getvalidoAlimento())
                {
                    alimento->SetQuantidaDeAlimento();
                    cout << cuidadoAnimal->getnome() << " foi muito bem alimentado com " << alimento->getTipoAlimento() << endl;
                }else
                {
                    cout << "Animal nao esta sob cuidados do funcionario " << nome << " ou o alimento tem dados invalidos \n";
                }
            }else
            {
                cout << "O funcionario precisa cuidar de pelo menos um animal para alimeta-lo \n";
            }
        }else
        {
            cout << "Este funcionario possui dados invalidos \n";
        }    
    }

    void verEstoqueDeAlimento(Alimento* alimento)
    {
        if(validoSalario)
        {
            if(alimento->getvalidoAlimento())
            {
                cout << "Existem " << alimento->getQuantidadeDeAlimento() << " " << alimento->getTipoAlimento() << " no estoque \n";
            }else
            {
                cout << "Este alimento possui qunatidades invalidas \n";
            }
        }else
        {
            cout << "Funcionario nao pode realizar essa acao porque possui dados invalidos \n";
        }
    }

    void ReporEstoqueAlimento(Alimento* alimento, int novaQuantidade)
    {
        if(validoSalario)
        {
            if(alimento->getvalidoAlimento())
            {
                alimento->setQuantidaDeAlimento(novaQuantidade);
            }else
            {
                cout << "Este alimento possui quantidades invalidas \n";
            }
        }else
        {
            cout << "Funcionario nao pode realizar essa acao porque possui dados invalidos \n";
        }
    }


};


int main()
{
    Funcionarios thaua("Thaua","Cuidador",20000);

    Alimento carne ("Carne",30);
    Alimento racao ("Racao",20);

    Gato mimi("mimi",12,"felino",12);
    Cachorro dogma("Dogma",19,"Bulldog",20.2);
    Leao lion("Lion",20,"sei nao",50.3);

    thaua.cuidarDeUmAnimalNome(&mimi);
    thaua.cuidarDeUmAnimalNome(&dogma);

    thaua.cuidadoEspeciaisNome(&dogma);

    thaua.alimentarAnimalNome(&mimi,&carne);
    thaua.alimentarAnimalNome(&dogma,&racao);

    thaua.verEstoqueDeAlimento(&carne);

    thaua.ReporEstoqueAlimento(&carne,1);
    thaua.ReporEstoqueAlimento(&racao,10);

    thaua.calcularSalario();
    
    thaua.exibirInformacoes();

    thaua.listaTodosAnimaisCuidados();

    
    
    
}



