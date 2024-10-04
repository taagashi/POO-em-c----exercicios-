#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Conta
{
    private:
    string titular;
    float saldo;

    protected:
    bool existe(float money) //vou considerar que uma conta so existe se tiver um valor valido
    {
        return money>=0;
    }

    public:
    //construtor
    Conta(string titular, float saldo)
    {
        if(saldo<0)
        {
            cout << "Voce precisa digitar um saldo valido \n";
            this->saldo=-1;
        }else
        {
            this->titular = titular;
            this->saldo = saldo;
        }
    }

    void depositar(float valor)
    {
        if(existe(this->saldo))
        {
            if(valor>0)
            {
                this->saldo+=valor;
                cout << "Valor de " << valor << "R$ depositado na conta: " << this->titular << endl;
            } else
            {
                cout << "Digite um valor de deposito valido \n";
            }
        }else
        {
            cout << "Essa conta nao existe pois possui informacoes invalidas \n";
        }
    }

    void sacar(float valor)
    {
        if(existe(this->saldo) && this->saldo>0)
        {
            if(valor<=this->saldo && valor>=0)
            {
                this->saldo-=valor;
                cout << "Saque de " << valor << "R$ feito na conta: " << this->titular << endl;
            }else
            {
                cout << "Esse nao eh um valor valido de saque \n";
            }
        } else
        {
            cout << "Nao eh possivel realizar essa acao \n";
        }
    }

    virtual void exibir_info()
    {
        if(existe(this->saldo))
        {
            cout << "Titular: " << this->titular << endl;
            cout << "Saldo: " << this->saldo << endl;
        }else
        {
            cout << "Essa conta nao existe pois possui informacoes invalidas \n";
        }
    }


    void set_saldo(float valor)
    {
        this->saldo+=valor;
    }

    float get_saldo()
    {
        return this->saldo;
    }

    const string get_titular()
    {
        return this->titular;
    }
};

class Conta_corrente : public Conta
{
    public:
    Conta_corrente(string titular, float valor):Conta(titular,valor){}

    void exibir_info() override
    {
        cout << "Conta corrente \n";
        Conta::exibir_info();
    }
};

class Conta_poupanca : public Conta
{
    private:
    float taxa_rendimento;

    public:
    Conta_poupanca(string titular, float valor, float taxa_rendimento)
    :Conta(titular,valor){
        if(taxa_rendimento>=0)
        {
            this->taxa_rendimento = taxa_rendimento;
        } else
        {
            cout << "Taxa de rendimento invalida \n";
            this->taxa_rendimento = -1;
        }
    }

    void aplicar_rendimento()
    {
        if(existe(get_saldo()) && this->taxa_rendimento!=-1)
        {
            cout << "Taxa de rendimento de " << this->taxa_rendimento << " aplicada \n";
            set_saldo(this->taxa_rendimento);
        }else
        {
            cout << "Erro, voce possui dados de conta invalidos \n";
        }
    }

    void exibir_info() override
    {
        cout << "Conta poupanca \n";
        Conta::exibir_info();
    }
};


class Banco
{
    private:
    vector<Conta*>contas;

    bool verificacao() //verifica se existe conta no banco
    {
        return contas.size()>0;
    }

    Conta* procurar_conta(const string nome)
    {
        for(auto& nav : contas)
        {
            if(nav->get_titular() == nome)
            {
                return nav;
            }
        }
        return nullptr;
    }
    
    public:
    void abrir_conta(Conta* cont)
    {
        contas.push_back(cont);
    }

    void depositar_nome(const string nome, float valor)
    {
        if(procurar_conta(nome)!=nullptr && verificacao())
        {
                Conta* titular = procurar_conta(nome);
                titular->depositar(valor);
        }else
        {
            cout << "Essa conta eh invalida pois possui dados invalidos. Corrija\n";
        }
    }

    void sacar_nome(const string nome, float valor)
    {
        if(procurar_conta(nome)!=nullptr && verificacao())
        {
            Conta* titular = procurar_conta(nome);
            titular->sacar(valor);
        }else
        {
            cout << "Essa conta eh invalida para realiar saque. Coloque dados validos \n";
        }
    }

    void aplicar_rendimento_nome(const string nome)
    {
        if(procurar_conta(nome) && verificacao())
        {
            Conta_poupanca* titular = dynamic_cast<Conta_poupanca*>(procurar_conta(nome));

            if(titular!=nullptr)
            {

            (procurar_conta(nome));
            titular->aplicar_rendimento();

            } else
            {
                cout << "Nao existem contas poupanca registrada com esse nome\n";
            }
        } else
        {
            cout << "Dados de conta invalidos \n";
        }
    }

    void exibir_contas()
    {
        if(verificacao())
        {
           for(auto& nav : contas)
           {
                nav->exibir_info();
                cout << endl;
           }
        } else
        {
            cout << "Voce precisa adicionar uma conta para fazer esse processo \n";
        }
        
    }

    void exibir_conta_nome(const string nome)
    {
        if(verificacao())
        {
            if(procurar_conta(nome))
            {
                Conta* titular = procurar_conta(nome);
                titular->exibir_info();
            }else
            {
                cout << "Esse nome nao esta cadastrado \n";
            }
        } else
        {
            cout << "Crie uma conta para efetuar acao \n";
        }
    }


};

void depositar_nome(Banco&, const string, float);
void sacar_nome(Banco&, const string, float);
void exibir_contas(Banco&);
void exibir_conta_nome(Banco&, const string);
void aplicar_rendimento_nome(Banco&, const string);


int main()
{
    Banco contas;
    contas.abrir_conta(new Conta_corrente("Thaua",20));
    contas.abrir_conta(new Conta_poupanca("Joao",3000,200));

    exibir_contas(contas);

    depositar_nome(contas,"Thaua",1500);
    depositar_nome(contas,"Joao",2000);

    sacar_nome(contas,"Joao",5000);
    sacar_nome(contas,"Thaua",1519);

    aplicar_rendimento_nome(contas, "Joao");

    exibir_conta_nome(contas,"Joao");
    exibir_conta_nome(contas,"Thaua");

    return 0;
}





void depositar_nome(Banco& conta, const string nome, float valor)
{
    conta.depositar_nome(nome,valor);
}

void sacar_nome(Banco& conta, const string nome, float valor)
{
    conta.sacar_nome(nome,valor);
}

void exibir_contas(Banco& conta)
{
    conta.exibir_contas();
}

void exibir_conta_nome(Banco& conta, const string nome)
{
    conta.exibir_conta_nome(nome);
}

void aplicar_rendimento_nome(Banco& conta, const string nome)
{
    conta.aplicar_rendimento_nome(nome);
}