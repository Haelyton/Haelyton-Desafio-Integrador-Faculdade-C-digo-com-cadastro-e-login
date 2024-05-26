#include <iostream> //Biblioteca principal para saída e entrada de dados
#include <string>   //Biblioteca Manipulção de textos
#include <cstdlib>  //Biblioteca para funções relacionadas ao sistema
#include <vector>   //Biblioteca para utilização de vetores
#include <iomanip>
using namespace std;

bool isUserLogged = false; // Variável Booleana para verificar se o usuário está Logado
const double valor_nosso_app = 35;
// Custos por programador
const double programador_senior = 100;
const double programador_pleno = 60;
const double programador_back_end = 40;
const double programador_front_end = 40;

// Tempo de desenvolvimento
const int dias_semana = 5; // 5x8 = 40
const int horas_trabalhadas_diariamente = 8;
const int semanas_totais_trabalhadas = 12; // 40x24 =960 horas trabalhadas

// Cálculos Custos
double calculo_custos_programadores = (programador_senior + programador_pleno + programador_front_end + programador_back_end); // Soma do salário de todos os programadores = 240
double calculo_horas_trabalhadas = (dias_semana * horas_trabalhadas_diariamente);                                              // 40 horas trabalhadas
double calculo_horas_semanas = (calculo_horas_trabalhadas * semanas_totais_trabalhadas);                                       // 960 horas trabalhadas

// Cálculo Final Desenvolvimento
double horas_vezes_custo_programadores = (calculo_custos_programadores * calculo_horas_semanas);
// Caso haja novo cadastro de custo no sistema
double valor_soma_total = 0;
struct Usuario // Estrutura struct para fazer a representação de um Usuário
{
    string nomeUsuario; // Armazenar o NOME DE USUÁRIO cadastrado
    string email;       // Armazenar o E-mail cadastrado
    string senha;       // Armazenar a Senha cadastrada
    string cpf;         // Armazenar o CPF cadastrado
};

struct Despesa // Estrutura struct para armazenar valores das despesas
{
    string data;
    double valor;
    string categoria;
    string descricao;
    string metodo_pagamento;
    int pagantes;
};

bool validarEmail(const string &email) // Função para validar o formato do E-mail ao se cadastrar
{
    return (email.find("@gmail.com") != string::npos); // Verifica se o E-mail possui a substring(@gmail.com)
}
bool validarSenha(const string &senha) // Função para validar a quantidade de caracteres infomadas no cadastro da senha
{
    return (senha.length() >= 8); // Verifica se a senha possui no minímo 8 caracteres
}

void cadastro(vector<Usuario> &usuarios) // Função para criação de um novo cadastro
{
    Usuario novoUsuario;   // Variável para armazenar as informações digitadas pelo usuário no cadastro
    string opcaoValidacao; // Variável para verificar se o cadastro informado está correto
    do
    {
        cout << "\n---------------------------------------------------------------------------------------\n"
             << endl;
        cout << "Precisamos de algumas informacoes para realizar o seu cadastro!" << endl;
        cout << "\nDigite seu Nome Completo: "; // Solicita ao usuário seu nome completo
        getline(cin, novoUsuario.nomeUsuario);  // Faz a leitura do nome

        do // Inicio do Looping
        {
            cout << "Digite seu e-mail (nome@gmail.com): "; // Solicita o E-mail do usuário
            getline(cin, novoUsuario.email);                // Leitura do E-mail
            if (!validarEmail(novoUsuario.email))           // Validação do formato do E-mail
            {
                system("cls");                     // Limpeza de BUFFER
                cout << "E-mail Invalido" << endl; // Caso formato do E-mail seja inválido, apresenta mensagem de erro
            }
            else // Verifica se o E-mail inserido é válido
            {
                system("cls"); // Limpeza de BUFFER
                // Exibe novamente o nome do usuário, CPF e o E-mail
                cout << "NOME: " << novoUsuario.nomeUsuario << endl;
                cout << "E-mail: " << novoUsuario.email << endl;
            }
        } while (!validarEmail(novoUsuario.email)); // Continua solicitando um E-mail Válido até que o E-mail fornecido seja válido
        do // Inicio do Looping
        {
            cout << "Digite sua senha: ";         // Solicita Senha para o cadastro
            getline(cin, novoUsuario.senha);      // Leitura da senha
            if (!validarSenha(novoUsuario.senha)) // Validação da quantidade de caracteres para o cadastro da senha
            {
                system("cls");                                                   // Limpeza de BUFFER
                cout << "A senha precisa de 8 digitos para ser segura!" << endl; // Fornece informações para uma senha segura
            }
            else // Verifica se a senha é válida
            {
                system("cls"); // Limpeza de BUFFER
                // Exibe novamente o nome do usuário, CPF, E-mail;
                cout << "NOME: " << novoUsuario.nomeUsuario << endl;
                cout << "E-mail: " << novoUsuario.email << endl;
                cout << "Senha: "
                     << "**" << endl;
            }

        } while (!validarSenha(novoUsuario.senha)); // Looping continua solicitando a Senha até que ela seja válida
        cout << "\n---------------------------------------------------------------------------------------" << endl;
        cout << "\n";
        cout << "Seu Cadastro esta correto? (sim/nao)" << endl; // Pergunta ao usuário se as informações estão corretas
        getline(cin, opcaoValidacao);                           // Leitura da resposta sim ou nao
    } while (opcaoValidacao != "sim"); // Continua o looping de cadastro até que a resposta seja sim
    if (opcaoValidacao == "sim")
    {
        system("cls || clear");
        usuarios.push_back(novoUsuario);
        cout << "Agora realize seu Login\n"
             << endl;
        return;
    }
}

bool login(vector<Usuario> &usuarios) // Função para efetuar o Login após o cadastro
{

    string email, senha;
    do
    {
        cout << "--------LOGIN--------" << endl; // Mensagem de Título apresentando o menu Login
        cout << "Digite seu e-mail: ";           // Solicita o mesmo E-mail cadastrado
        getline(cin, email);                     // Leitura do E-mail
        bool usuarioEcontrado = false;           // Variável para verificar se o E-mail foi econtrado na lista de Usuários
        for (Usuario &usuario : usuarios)        // loop for que percorre a lista de usuários
        {
            if (usuario.email == email) // Verifica a validação do E-mail correspondente a lista de usuário
            {
                usuarioEcontrado = true;      // Define a variável de controle como true, indicando que o usuário foi encontrado
                cout << "Digite sua senha: "; // Solicitação para digitar a senha
                getline(cin, senha);          // Leitura da senha
            }
            if (usuario.senha == senha) // Verifica a validação da senha correspondente na lista de usuário
            {
                usuarioEcontrado = true;
                system("cls");
                cout << "Login Realizado " << endl;                         // Apresenta a mensagem de Login Realizado
                cout << "Bem vindo " << usuario.nomeUsuario << "!" << endl; // Exibi o nome do usuário logado
                cout << "<=======================================================>" << endl;
                isUserLogged = true;
                // Se o Login do usuário for true, o looping e interrompido
                return true; // Retorna true, indicando login realizado
            }
            else // Verifica a validação do E-mail e da senha se estiveram incorretos
            {
                system("cls");                               // Limpeza de BUFFER
                cout << "E-mail ou Senha incorreta" << endl; // Mensagem de E-mail ou senha incorreta
                login(usuarios);                             // Puxa novamente a função login gerando um novo looping
                return false;                                // Retorna falso, indicando falha no login
            }
        }
        if (!usuarioEcontrado) // Se nenhum usuário correspondente foi encontrado
        {
            system("cls"); // Limpeza de BUFFER
            char opcaoUsuarioNaoEncontrado;
            cout << "---------------------------------------------------------------------------------------" << endl;
            cout << "\nUsuario nao encontrado\n" // Mensagem de Usuário não encontrado
                 << endl;
            cout << "Voce deve se cadastrar para acessar o sistema!" << endl; // Fornecendo informação de como o usuário deve prosseguir
            cout << "\n---------------------------------------------------------------------------------------\n"
                 << endl;
            cout << "1 - Cadastrar-se agora" << endl;    // Opção para o Usuário realizar o cadastro
            cout << "2 - Fazer login novamente" << endl; // Opção para o Usuário realizar o Login novamente
            cout << "3 - Sair do sistema" << endl;       // Opção para o usuário sair do sistema
            cout << "Digite a sua opcao: ";              // Solicitando qual opção o usuário deseja
            cin >> opcaoUsuarioNaoEncontrado;            // Leitura da Opção
            cin.ignore();                                // Ignora quaisquer caracter pendete no BUFFER de Entrada
            switch (opcaoUsuarioNaoEncontrado)
            {
            case '1':
                system("cls");      // Limpeza de BUFFER
                cadastro(usuarios); // Chama a Função cadastro
                break;
            case '2':
                system("cls");   // Limpeza de BUFFER
                login(usuarios); // Chama a Função Login
                break;
            case '3':
                cout << "Saindo..." << endl; // Exibe Mensagem de Saída
                cout << "..." << endl;       // Mensagem de espera
                exit(0);                     // Sai do Programa
                break;
            default: // Caso nenhuma opção seja válida sai do Switch
                break;
            }
        }
    } while (!validarEmail(email)); // Continuação de loop, até que o E-mail seja validado
    return false; // Retorna falso, indicando que o Login não foi realizado
}

void registrarDespesa(vector<Despesa> &despesas)
{
    Despesa novaDespesa;
    system("cls");
    cout << "Registrar Nova Custo" << endl;
    cout << "-----------------------" << endl;

    cout << "Valor: ";
    cin >> novaDespesa.valor;
    cin.ignore(); // Ignorar o restante da linha após a leitura do valor

    cout << "Descricao: ";
    getline(cin, novaDespesa.descricao);

    despesas.push_back(novaDespesa);
    system("cls");
    cout << "Custo registrada com sucesso!" << endl;
}
void listarCustos(const vector<Despesa> &despesas)
{

    system("cls");
    cout << "Custo com o Software:" << endl;
    cout << "-----------------" << endl;
    cout << "Licenca: " << endl;                                              // colocar valor da licenca do software
    cout << "Desenvolvimento: R$" << horas_vezes_custo_programadores << endl; // valor do desenvolvimento
    cout << "Manutencao: " << endl;                                           // Valor do desenvolvimento
    cout << "Suporte tecnico: " << endl;                                      // valor do suporte mensal
    cout << "Treinamento do sistema: " << endl;                               // valor do treinamento do sistema
    cout << "Total dos Custos: " << endl;                                     // valor total dos custos
    cout << "-----------------" << endl;

    for (const auto &despesa : despesas)
    {
        cout << "Valor: " << despesa.valor << endl;
        cout << "Descricao: " << despesa.descricao << endl;
        cout << "-----------------" << endl;
    }
}
void calcular_nossos_custos(vector<Despesa> &despesas)
{
    Despesa quantidade;
    system("cls");
    cout << "Insira a quantidade de pagantes: " << endl;
    cin >> quantidade.pagantes;

    double valor_soma_total = horas_vezes_custo_programadores;
    for (const auto &despesa : despesas)
    {
        valor_soma_total += despesa.valor;
    }
    cout << valor_soma_total << endl;
    double preco_usuario_pagante = (valor_soma_total / quantidade.pagantes); // Calcular o Preço por Usuário Pagante
    double vendas_necessarias = (valor_soma_total / valor_nosso_app);        // Número de vendas necesárias
    cout << setprecision(2) << fixed << preco_usuario_pagante << " reais de custo por assinante " << endl;
    cout << setprecision(0) << fixed << vendas_necessarias << " oque eu preciso" << endl;

    if (quantidade.pagantes < vendas_necessarias)
    {
        double vendas_faltantes = (vendas_necessarias - quantidade.pagantes);
        cout << "Faltam " << vendas_faltantes << "Vendas ate o ponto de equilibrio" << endl;
    }
    else if (quantidade.pagantes > vendas_necessarias)
    {
        float porcentagem_lucro = ((quantidade.pagantes / vendas_necessarias) * 100);
        cout << "parabens voce passou o ponto de equilibrio e arrecadou " << porcentagem_lucro << "%" << " de lucro" << endl;
    }
    else if (quantidade.pagantes == vendas_necessarias)
    {
        cout << "voce chegou no ponto de equilibrio";
    }
}
void opcoesDespesas(vector<Despesa> &despesas)
{

    system("cls");
    int opcao;
    do
    {
        cout << "Sistema de Registro de Despesas" << endl;
        cout << "1. Registrar Novo Custo" << endl;
        cout << "2. Listar custos" << endl;
        cout << "3. Calcular Percentual de Lucro" << endl;
        cout << "4. Sair" << endl;
        cout << "Escolha uma opcao: ";
        cin >> opcao;
        cin.ignore(); // Ignorar o restante da linha após a leitura da opção

        switch (opcao)
        {
        case 1:
            registrarDespesa(despesas);
            break;
        case 2:
            listarCustos(despesas);
            break;
        case 3:
            calcular_nossos_custos(despesas);
            break;
        case 4:
            cout << "Saindo do sistema..." << endl;
            break;
        default:
            cout << "Opcaoo invalida. Tente novamente." << endl;
        }
    } while (opcao != 4);

    if (opcao == 4)
    {
        exit(0);
    }
}

int main() // Função Principal
{
    vector<Usuario> usuarios; // Declaração de um vetor para armazenar múltiplos usuários
    vector<Despesa> despesas; // Declaração de um vetor para armazenar múlitplas despesas
    char opcao;               // variável para identificar a escolha do usuário
    while (!isUserLogged)     // Loop continua até que usuário esteja logado
    {
        system("cls");
        cout << "\n----------------SEJA BEM-VINDO----------------" << endl;
        cout << "\nSISTEMA DE GERENCIAMENTO FINANCEIRO PARA STARTUPS\n"
             << endl;
        cout << "Aqui voce pode registrar suas despesas e fazer projecoes\nde lucros, baseado no seu modelo de negocio\n"
             << endl;
        cout << "-----------------------------------------------" << endl;
        cout << "Escolha sua opcao: " << endl; // Exibi uma mensagem de Boas-Vindas para o Usuário
        cout << "1 - Cadastre-se" << endl;     // Opção para o Usuário realizar o cadastro
        cout << "2 - Faca Login" << endl;      // Opção para o Usuário realizar o Login
        cout << "Digite aqui sua opcao: ";     // Solicita ao Usuário sua escolha
        cin >> opcao;                          // Realiza a leitura da escolha do usuário
        system("cls");                         // Limpeza de BUFFER

        cin.ignore(); // Ignora quaisquer caracter pendente no BUFFER de Entrada

        switch (opcao) // Função Switch para a escolha do usuario
        {
        case '1':               // Caso a o valor de 'opcao' seja '1'
            cadastro(usuarios); // Chama primeiro a função cadastro de usuário
            login(usuarios);    // Após realizar o cadastro puxa a função login
            break;
        case '2':            // Caso a o valor de 'opcao' seja '2'
            login(usuarios); // Puxa a função Login
            break;
        default:                                  // Caso o valor de 'opcao' seja diferente de '1' e '2'
            cout << "Opcao invalida... " << endl; // Mensagem de Opção Inválida
            break;
        }
    }
    if (isUserLogged)
    {
        opcoesDespesas(despesas); // Chama a função para gerenciamento das despesas após login bem-sucedido
    }

    registrarDespesa(despesas);
    listarCustos(despesas);
    calcular_nossos_custos(despesas);

    return 0;
}