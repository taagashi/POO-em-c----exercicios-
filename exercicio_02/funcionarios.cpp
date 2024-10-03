#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Funcionarios
{
    private:
    string nome;
    
    protected:
    float salario;

    bool verificador_salario(float salario)
    {
        return salario>0;
    }
    public:
    //construtor
    Funcionarios(string nome, float salario)
    {
        if(verificador_salario(salario))
        {
            this->nome = nome;
            this->salario = salario;
        }else
        {
            cout << nome << " possui dados invalidos. Digite um salario valido \n";
            this->salario=0;
        }
    }

       void calcular_bonus() //bonus de 10%
    {
        if(verificador_salario(this->salario))
        {
            cout << "Bonus de " <<  this->nome << " foi calculado \n";
           this->salario+=salario*0.10;
        } else
        {
            cout << "Dados do salario invalidos \n";
           
        }
    }

    virtual void exibir_info()
    {
        if(verificador_salario(this->salario))
        {
            cout << "Nome: " << this->nome << endl;
            cout << "Salario: " << this->salario << endl;
        } else
        {
            cout << "Nao eh possivel exibir dados de um funcionario invalido \n";
        }
    }

    const string get_nome()
    {
        return this->nome;
    }
};

class Funcionario_horista : public Funcionarios
{
    private:
    int horas_trabalhadas=0;
    float valor_por_hora=0;

    bool verificador(int horas_trabalhadas, float valor_por_hora)
    {
        return horas_trabalhadas>=0 && valor_por_hora>0;
    }

    public:
    Funcionario_horista(string nome, float salario, int horas_trabalhadas, float valor_por_hora)
    :Funcionarios(nome,salario)
    {
        if(verificador(horas_trabalhadas,valor_por_hora))
        {
            this->horas_trabalhadas = horas_trabalhadas;
            this->valor_por_hora = valor_por_hora;
        } else
        {
            cout << "Nao pode adicionar dados negativos \n";
        }
    }

    void calcular_salario()
    {
        if(verificador(this->horas_trabalhadas,this->valor_por_hora))
        {
             this->salario+=(this->horas_trabalhadas*this->valor_por_hora*0.10);
        }else
        {
            cout << "Nao eh possivel calcular o salario porque existem dados faltando \n";
        }
    }

    void exibir_info() override
    {
        Funcionarios::exibir_info();
        cout << "Horas trabalhadas: " << this->horas_trabalhadas << endl; 
        cout << "Valor por hora: " << this->valor_por_hora << endl;
    }
};

class Funcionario_vendedor : public Funcionarios
{
    private:
    int quantidade_vendas=-1;

    bool verificador(int quantidade)
    {
        return quantidade>=0;
    }
    public:
    Funcionario_vendedor(string nome, float salario, int quantidade_vendas):Funcionarios(nome,salario)
    {
        if(verificador(quantidade_vendas))
        {
            this->quantidade_vendas = quantidade_vendas;
        } else
        {
            cout << "A quantidade e invalida \n";
        }
    }

    void calcular_salario()
    {
        if(verificador(this->quantidade_vendas))
        {
            this->salario+= this->quantidade_vendas*0.10;
        } else
        {
            cout << "Nao e possivel calcular o salario \n";
        }
    }

    void exibir_info() override
    {
        if(verificador(this->quantidade_vendas))
        {
            Funcionarios::exibir_info();
            cout << "Vendas feitas: " << this->quantidade_vendas << endl;
        }else
        {
            this->quantidade_vendas = 0;
            Funcionarios::exibir_info();
            cout << "Vendas feitas: " << this->quantidade_vendas << endl;
        }
    }
};

class Empresa
{
    private:
    vector<Funcionarios*>firma;

    Funcionarios* achar_funcionario(const string seach_nome)
    {
        for(auto& nav : firma)
        {
            if(nav->get_nome() == seach_nome)
            {
                return nav;
                break;
            }
        }
        return nullptr;
    }
    public:
    void contratar_funcionario(Funcionarios* func)
    {
        firma.push_back(func);
    }

    void calcular_bonus_funcionarios()
    {
        for(auto& nav : firma)
        {
            nav->calcular_bonus();
            cout << endl;
        }
    }

    void calcular_bonus_nome(const string nome)
    {
        if(achar_funcionario(nome)!=nullptr)
        {
            Funcionarios* funcionario = achar_funcionario(nome);
            funcionario->calcular_bonus();
        } else
        {
            cout << "Funcionario nao foi encontrado \n";
        }
    }

    void exibir_info_funcionarios()
    {
        for(auto& nav : firma)
        {
            nav->exibir_info();
            cout << endl;
        }
    }

    void exibir_info_nome(const string nome)
    {
        if(achar_funcionario(nome)!=nullptr)
        {
            Funcionarios* funcionario = achar_funcionario(nome);
            funcionario->exibir_info();
        } else
        {
            cout << "Funcionario nao foi encontrado \n";
        }
    }
};

int main()
{
     Empresa funcionarios;
     funcionarios.contratar_funcionario(new Funcionario_horista("Thaua",30,4,5));
     funcionarios.contratar_funcionario(new Funcionario_vendedor("Maria",40,2));
     funcionarios.exibir_info_nome("Thaua");

}