#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Parte 1: escreva aqui as classes Astronauta, Voo e Agencia.
// Depois, em cada comando, apague a linha do cout com "TODO" e descomente
// a chamada ao metodo da Agencia.

class Astronauta
{
private:
    string cpf;
    string nome;
    int idade;
    bool vivo;
    bool disponivel;
    vector<int> voosParticipados;

public:
    Astronauta(string cpf, string nome, int idade)
    {
        this->cpf = cpf;
        this->nome = nome;
        this->idade = idade;
        vivo = true;
        disponivel = true;
    }

    string getCpf() const
    {
        return cpf;
    }

    string getNome() const
    {
        return nome;
    }

    int getIdade() const
    {
        return idade;
    }

    bool estaVivo() const
    {
        return vivo;
    }

    bool estaDisponivel() const
    {
        return disponivel;
    }

    void embarcar()
    {
        if (vivo)
        {
            disponivel = false;
        }
    }

    void desembarcar()
    {
        if (vivo)
        {
            disponivel = true;
        }
    }

    void morrer()
    {
        vivo = false;
        disponivel = false;
    }

    void registrarParticipacao(int codigo)
    {
        voosParticipados.push_back(codigo);
    }
    vector<int> getVoosParticipados() const
    {
        return voosParticipados;
    }
};

class Voo
{
private:
    int codigo;
    string estado;
    vector<string> cpfs;

public:
    Voo(int codigo)
    {
        this->codigo = codigo;
        estado = "planejado";
    }

    int getCodigo() const
    {
        return codigo;
    }

    string getEstado() const
    {
        return estado;
    }

    int getQuantidadeAstronautas() const
    {
        return cpfs.size();
    }
    string getCpf(int posicao) const
    {
        return cpfs[posicao];
    }

    bool temAstronauta(string cpf)
    {
        for (int i = 0; i < cpfs.size(); i++)
        {
            if (cpfs[i] == cpf)
            {
                return true;
            }
        }
        return false;
    }

    void adicionarAstronauta(string cpf)
    {
        cpfs.push_back(cpf);
    }

    bool removerAstronauta(string cpf)
    {
        for (int i = 0; i < cpfs.size(); i++)
        {
            if (cpfs[i] == cpf)
            {
                cpfs.erase(cpfs.begin() + i);
                return true;
            }
        }
        return false;
    }

    void lancar()
    {
        estado = "em curso";
    }

    void explodir()
    {
        estado = "finalizado com explosao";
    }

    void finalizar()
    {
        estado = "finalizado com sucesso";
    }
};

class Agencia
{
private:
    vector<Astronauta> astronautas;
    vector<Voo> voos;

    int buscarAstronauta(string cpf)
    {
        for (int i = 0; i < astronautas.size(); i++)
        {
            if (astronautas[i].getCpf() == cpf)
            {
                return i;
            }
        }
        return -1;
    }

    int buscarVoo(int codigo)
    {
        for (int i = 0; i < voos.size(); i++)
        {
            if (voos[i].getCodigo() == codigo)
            {
                return i;
            }
        }
        return -1;
    }

    int vooEmCursoDe(string cpf)
    {
        for (int i = 0; i < voos.size(); i++)
        {
            if (voos[i].getEstado() == "em curso" && voos[i].temAstronauta(cpf))
            {
                return i;
            }
        }
        return -1;
    }

public:
    void cadastrarAstronauta(string cpf, string nome, int idade)
    {
        if (buscarAstronauta(cpf) != -1)
        {
            cout << "ERRO: astronauta com CPF " << cpf << " ja cadastrado" << endl;
            return;
        }
        Astronauta novo(cpf, nome, idade);
        astronautas.push_back(novo);
        cout << "OK: astronauta " << cpf << " cadastrado" << endl;
    }

    void cadastrarVoo(int codigo)
    {
        if (buscarVoo(codigo) != -1)
        {
            cout << "ERRO: voo " << codigo << " ja cadastrado" << endl;
            return;
        }

        Voo novo(codigo);
        voos.push_back(novo);
        cout << "OK: voo " << codigo << " cadastrado" << endl;
    }

    void adicionarAstronauta(string cpf, int codigo)
    {
        int posA = buscarAstronauta(cpf);
        int posV = buscarVoo(codigo);
        if (posA == -1)
        {
            cout << "ERRO: astronauta " << cpf << " nao cadastrado" << endl;
            return;
        }
        if (posV == -1)
        {
            cout << "ERRO: voo " << codigo << " nao cadastrado" << endl;
            return;
        }
        if (voos[posV].getEstado() != "planejado")
        {
            cout << "ERRO: voo " << codigo << " nao esta planejado" << endl;
            return;
        }
        if (!astronautas[posA].estaVivo())
        {
            cout << "ERRO: astronauta " << cpf << " esta morto" << endl;
            return;
        }
        if (voos[posV].temAstronauta(cpf))
        {
            cout << "ERRO: astronauta " << cpf << " ja esta no voo " << codigo << endl;
            return;
        }
        voos[posV].adicionarAstronauta(cpf);
        cout << "OK: astronauta " << cpf << " adicionado ao voo " << codigo << endl;
    }

    void removerAstronauta(string cpf, int codigo)
    {
        int posA = buscarAstronauta(cpf);
        int posV = buscarVoo(codigo);
        if (posA == -1)
        {
            cout << "ERRO: astronauta " << cpf << " nao cadastrado" << endl;
            return;
        }
        if (posV == -1)
        {
            cout << "ERRO: voo " << codigo << " nao cadastrado" << endl;
            return;
        }
        if (voos[posV].getEstado() != "planejado")
        {
            cout << "ERRO: voo " << codigo << " nao esta planejado" << endl;
            return;
        }
        if (!voos[posV].temAstronauta(cpf))
        {
            cout << "ERRO: astronauta " << cpf << " nao esta no voo " << codigo << endl;
            return;
        }
        voos[posV].removerAstronauta(cpf);
        cout << "OK: astronauta " << cpf << " removido do voo " << codigo << endl;
    }

    void lancarVoo(int codigo)
    {
        int posV = buscarVoo(codigo);
        if (posV == -1)
        {
            cout << "ERRO: voo " << codigo << " nao cadastrado" << endl;
            return;
        }
        if (voos[posV].getEstado() != "planejado")
        {
            cout << "ERRO: voo " << codigo << " nao esta planejado" << endl;
            return;
        }
        if (voos[posV].getQuantidadeAstronautas() == 0)
        {
            cout << "ERRO: voo " << codigo << " nao possui astronautas" << endl;
            return;
        }
        for (int j = 0; j < voos[posV].getQuantidadeAstronautas(); j++)
        {
            string cpf = voos[posV].getCpf(j);
            int posA = buscarAstronauta(cpf);
            if (!astronautas[posA].estaVivo())
            {
                cout << "ERRO: astronauta " << cpf << " esta morto" << endl;
                return;
            }
            if (!astronautas[posA].estaDisponivel())
            {
                cout << "ERRO: astronauta " << cpf << " esta indisponivel" << endl;
                return;
            }
        }
        for (int j = 0; j < voos[posV].getQuantidadeAstronautas(); j++)
        {
            string cpf = voos[posV].getCpf(j);
            int posA = buscarAstronauta(cpf);
            astronautas[posA].embarcar();
            astronautas[posA].registrarParticipacao(codigo);
        }
        voos[posV].lancar();
        cout << "OK: voo " << codigo << " lancado" << endl;
    }

    void explodirVoo(int codigo)
    {
        int posV = buscarVoo(codigo);
        if (posV == -1)
        {
            cout << "ERRO: voo " << codigo << " nao cadastrado" << endl;
            return;
        }
        if (voos[posV].getEstado() != "em curso")
        {
            cout << "ERRO: voo " << codigo << " nao esta em curso" << endl;
            return;
        }
        for (int j = 0; j < voos[posV].getQuantidadeAstronautas(); j++)
        {
            string cpf = voos[posV].getCpf(j);
            int posA = buscarAstronauta(cpf);
            astronautas[posA].morrer();
        }
        voos[posV].explodir();
        cout << "OK: voo " << codigo << " explodiu" << endl;
    }

    void finalizarVoo(int codigo)
    {
        int posV = buscarVoo(codigo);
        if (posV == -1)
        {
            cout << "ERRO: voo " << codigo << " nao cadastrado" << endl;
            return;
        }
        if (voos[posV].getEstado() != "em curso")
        {
            cout << "ERRO: voo " << codigo << " nao esta em curso" << endl;
            return;
        }
        for (int j = 0; j < voos[posV].getQuantidadeAstronautas(); j++)
        {
            string cpf = voos[posV].getCpf(j);
            int posA = buscarAstronauta(cpf);
            astronautas[posA].desembarcar();
        }
        voos[posV].finalizar();
        cout << "OK: voo " << codigo << " finalizado com sucesso" << endl;
    }

    void listarVoos()
    {
        cout << "LISTA DE VOOS" << endl;
        vector<string> estados = {"planejado", "em curso", "finalizado com sucesso", "finalizado com explosao"};

        for (int e = 0; e < estados.size(); e++)
        {
            cout << "== " << estados[e] << " ==" << endl;
            bool algum = false;
            for (int i = 0; i < voos.size(); i++)
            {
                if (voos[i].getEstado() == estados[e])
                {
                    algum = true;
                    cout << "Voo " << voos[i].getCodigo() << ": ";
                    if (voos[i].getQuantidadeAstronautas() == 0)
                    {
                        cout << "sem astronautas" << endl;
                    }
                    else
                    {
                        for (int j = 0; j < voos[i].getQuantidadeAstronautas(); j++)
                        {
                            string cpf = voos[i].getCpf(j);
                            int pos = buscarAstronauta(cpf);
                            cout << cpf << " " << astronautas[pos].getNome();
                            if (j < voos[i].getQuantidadeAstronautas() - 1)
                            {
                                cout << ", ";
                            }
                        }
                        cout << endl;
                    }
                }
            }
            if (!algum)
            {
                cout << "(nenhum)" << endl;
            }
        }
    }

    void listarMortos()
    {
        cout << "ASTRONAUTAS MORTOS" << endl;
        bool algum = false;
        for (int i = 0; i < astronautas.size(); i++)
        {
            if (!astronautas[i].estaVivo())
            {
                algum = true;
                cout << astronautas[i].getCpf() << " " << astronautas[i].getNome() << " - voos:";
                vector<int> voosDele = astronautas[i].getVoosParticipados();
                for (int k = 0; k < voosDele.size(); k++)
                {
                    cout << " " << voosDele[k];
                }
                cout << endl;
            }
        }
        if (!algum)
        {
            cout << "(nenhum)" << endl;
        }
    }

    void listarAstronautas()
    {
        cout << "LISTA DE ASTRONAUTAS" << endl;

        cout << "== disponiveis ==" << endl;
        bool algum = false;
        for (int i = 0; i < astronautas.size(); i++)
        {
            if (astronautas[i].estaVivo() && vooEmCursoDe(astronautas[i].getCpf()) == -1)
            {
                algum = true;
                cout << astronautas[i].getCpf() << " " << astronautas[i].getNome()
                     << " (" << astronautas[i].getIdade() << " anos)" << endl;
            }
        }
        if (!algum)
        {
            cout << "(nenhum)" << endl;
        }

        cout << "== em voo ==" << endl;
        algum = false;
        for (int i = 0; i < astronautas.size(); i++)
        {
            int posV = vooEmCursoDe(astronautas[i].getCpf());
            if (astronautas[i].estaVivo() && posV != -1)
            {
                algum = true;
                cout << astronautas[i].getCpf() << " " << astronautas[i].getNome()
                     << " (" << astronautas[i].getIdade() << " anos)"
                     << " - voo " << voos[posV].getCodigo() << endl;
            }
        }
        if (!algum)
        {
            cout << "(nenhum)" << endl;
        }

        cout << "== mortos ==" << endl;
        algum = false;
        for (int i = 0; i < astronautas.size(); i++)
        {
            if (!astronautas[i].estaVivo())
            {
                algum = true;
                cout << astronautas[i].getCpf() << " " << astronautas[i].getNome()
                     << " (" << astronautas[i].getIdade() << " anos)" << endl;
            }
        }
        if (!algum)
        {
            cout << "(nenhum)" << endl;
        }
    }

    void historico(string cpf)
    {
        int posA = buscarAstronauta(cpf);
        if (posA == -1)
        {
            cout << "ERRO: astronauta " << cpf << " nao cadastrado" << endl;
            return;
        }
        cout << "HISTORICO DE " << cpf << " " << astronautas[posA].getNome() << endl;
        bool algum = false;
        for (int i = 0; i < voos.size(); i++)
        {
            if (voos[i].getEstado() != "planejado" && voos[i].temAstronauta(cpf))
            {
                algum = true;
                cout << "voo " << voos[i].getCodigo() << ": " << voos[i].getEstado() << endl;
            }
        }
        if (!algum)
        {
            cout << "(nenhum voo)" << endl;
        }
    }
};

int main()
{
    Agencia agencia;
    string comando;

    while (cin >> comando)
    { // le uma palavra; para no FIM ou quando a entrada acaba
        if (comando == "FIM")
        {
            break;
        }
        else if (comando == "CADASTRAR_ASTRONAUTA")
        {
            string cpf, nome;
            int idade;
            cin >> cpf >> idade;
            getline(cin >> ws, nome); // o nome vem por ultimo e pode ter espacos
            agencia.cadastrarAstronauta(cpf, nome, idade);
        }
        else if (comando == "CADASTRAR_VOO")
        {
            int codigo;
            cin >> codigo;
            agencia.cadastrarVoo(codigo);
        }
        else if (comando == "ADICIONAR_ASTRONAUTA")
        {
            string cpf;
            int codigo;
            cin >> cpf >> codigo;
            agencia.adicionarAstronauta(cpf, codigo);
        }
        else if (comando == "REMOVER_ASTRONAUTA")
        {
            string cpf;
            int codigo;
            cin >> cpf >> codigo;
            agencia.removerAstronauta(cpf, codigo);
        }
        else if (comando == "LANCAR_VOO")
        {
            int codigo;
            cin >> codigo;
            agencia.lancarVoo(codigo);
        }
        else if (comando == "EXPLODIR_VOO")
        {
            int codigo;
            cin >> codigo;
            agencia.explodirVoo(codigo);
        }
        else if (comando == "FINALIZAR_VOO")
        {
            int codigo;
            cin >> codigo;
            agencia.finalizarVoo(codigo);
        }
        else if (comando == "LISTAR_VOOS")
        {
            agencia.listarVoos();
        }
        else if (comando == "LISTAR_MORTOS")
        {
            agencia.listarMortos();
        }
        else if (comando == "LISTAR_ASTRONAUTAS")
        {
            agencia.listarAstronautas();
        }
        else if (comando == "HISTORICO")
        {
            string cpf;
            cin >> cpf;
            agencia.historico(cpf);
        }
        else
        {
            cout << "ERRO: comando desconhecido " << comando << endl;
        }
    }

    return 0;
}