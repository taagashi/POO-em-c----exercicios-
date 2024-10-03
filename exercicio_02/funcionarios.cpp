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

    virtual ~Funcionarios(){}

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

    virtual void exibir_info() //exibe as informacoes gerais dos funcionarios
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
            cout << "Salario de " << get_nome() << " foi calculado \n";
        }else
        {
            cout << "Nao eh possivel calcular o salario porque existem dados faltando \n";
        }
    }

    void exibir_info() override
    {
        cout << "Horista \n";
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
            cout << "Salario de " << get_nome() << " foi calculado \n";
        } else
        {
            cout << "Nao e possivel calcular o salario \n";
        }
    }

    void exibir_info() override
    {
        if(verificador(this->quantidade_vendas))
        {
            cout << "Vendedor(a) \n";
            Funcionarios::exibir_info();
            cout << "Vendas feitas: " << this->quantidade_vendas << endl;
        }else
        {
            cout << "Vendedor(a) \n";
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

    int demicao(const string seach_nome)
    {
        int tamanho = firma.size();
        for(int i=0 ; i<tamanho ; i++)
        {
            if(firma[i]->get_nome() == seach_nome)
            {
                return i;
            }
        }
        return -1;
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
            cout << endl;
        } else
        {
            cout << "Funcionario nao foi encontrado \n";
        }
    }

    void calcular_salario_horistas()
    {
        for(auto& nav : firma)
        {

            Funcionario_horista* horista = dynamic_cast<Funcionario_horista*>(nav);
            if(horista!=nullptr)
            {
                horista->calcular_salario();
                cout << endl;
            }
        }
    }

    void calcular_salario_horista_nome(const string nome)
    {
        if(achar_funcionario(nome)!=nullptr)
        {
            Funcionario_horista* horista = dynamic_cast<Funcionario_horista*>(achar_funcionario(nome));
            horista->calcular_salario();
        }else
        {
            cout << "Funcionario horista nao foi encontrado \n";
        }
    }

    void calcular_salario_vendedores()
    {
        for(auto& nav : firma)
        {
            Funcionario_vendedor* vendedor = dynamic_cast<Funcionario_vendedor*>(nav);
            if(vendedor!=nullptr)
            {
                vendedor->calcular_salario();
                cout << endl;
            }
        }
    }

    void calcular_salario_vendedor_nome(const string nome)
    {
        if(achar_funcionario(nome)!=nullptr)
        {
           Funcionario_vendedor* vendedor = dynamic_cast<Funcionario_vendedor*>(achar_funcionario(nome));
           vendedor->calcular_salario();
        } else
        {
            cout << "Funcionario vendedor nao foi encontrado \n";
        }
    }

    void demitir_funcionario_nome(const string nome)
    {
        int posicao = demicao(nome);
      if(posicao!= -1)
      {
        cout << firma[posicao]->get_nome() << " foi demitido(a) \n";
        delete firma[posicao];
        firma.erase(firma.begin()+posicao);
      } else
      {
        cout << "Fucionario nao foi encontrado \n";
      }
      
    }

    ~Empresa()
    {
        for(auto& nav : firma)
        {
            delete nav;
        }
    }
    
};

void calcular_bonus_funcionarios(Empresa&);
void calcular_bonus_nome(Empresa&, const string);
void exibir_info_funcionarios(Empresa&);
void exibir_info_nome(Empresa&, const string);
void calcular_salario_horistas(Empresa&);
void calcular_salario_horista_nome(Empresa&, const string);
void calcular_salario_vendedores(Empresa&);
void calcular_salario_vendedor_nome(Empresa&, const string);
void demitir_funcionario_nome(Empresa&, const string);



int main()
{
     Empresa funcionarios;
     funcionarios.contratar_funcionario(new Funcionario_horista("Joao",2000,4,5));
     funcionarios.contratar_funcionario(new Funcionario_vendedor("Maria",4000,2));
     funcionarios.contratar_funcionario(new Funcionario_horista("Anderson",3000,5,6));
     
     exibir_info_funcionarios(funcionarios);
     
     calcular_bonus_funcionarios(funcionarios);
     calcular_bonus_nome(funcionarios,"Anderson");
     
     calcular_salario_horistas(funcionarios);
     calcular_salario_vendedores(funcionarios);
     
     exibir_info_nome(funcionarios, "Joao");
     
     demitir_funcionario_nome(funcionarios, "Joao");
     
     exibir_info_funcionarios(funcionarios);

}






void calcular_bonus_funcionarios(Empresa& funcionario)
{
    funcionario.calcular_bonus_funcionarios();
}

void calcular_bonus_nome(Empresa& funcionario, const string nome)
{
    funcionario.calcular_bonus_nome(nome);
}

void exibir_info_funcionarios(Empresa& funcionario)
{
    funcionario.exibir_info_funcionarios();
}

void exibir_info_nome(Empresa& funcionario, const string nome)
{
    funcionario.exibir_info_nome(nome);
}

void calcular_salario_horistas(Empresa& funcionario)
{
    funcionario.calcular_salario_horistas();
}

void calcular_salario_horista_nome(Empresa& funcionario, const string nome)
{
    funcionario.calcular_salario_horista_nome(nome);
}

void calcular_salario_vendedores(Empresa& funcionario)
{
    funcionario.calcular_salario_vendedores();
}

void calcular_salario_vendedor_nome(Empresa& funcionario, const string nome)
{
    funcionario.calcular_salario_vendedor_nome(nome);
}

void demitir_funcionario_nome(Empresa& funcionario, const string nome)
{
    funcionario.demitir_funcionario_nome(nome);
}