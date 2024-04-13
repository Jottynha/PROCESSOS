#include "analise.hpp"
using namespace std;
vector<double> lerNumeros(const string& nome_arquivo) {
    vector<double> numeros;

    // Abre o arquivo para leitura
    ifstream arquivo(nome_arquivo);

    if (!arquivo.is_open()) {
        throw runtime_error("Erro ao abrir o arquivo!");
    }

    string linha;
    while (getline(arquivo, linha)) {
        istringstream iss(linha);
        string token;
        while (getline(iss, token, ' ')) {
            numeros.push_back(stod(token));
        }
    }

    arquivo.close();

    return numeros;
}

double somativa(const vector<double> numeros){
    double soma = 0.0;
    for (size_t i=0; i < numeros.size(); i++) {
        soma += numeros[i];
    }
    return sqrt(soma);
}

string removeChar(string str, char ch) {
    string resultado;
    for (char c : str) {
        if (c != ch) {
            resultado += c;
        }
    }
    return resultado;
}


void lerProcesso(const string& entrada, const string& saida, int processo) {
    double totalLinha=0, totalProcesso=0;
    ifstream arquivo(entrada);
    if (!arquivo.is_open()) {
        cerr << "Erro ao abrir o arquivo!!!" << endl;
        return;
    }
    int num_linhas = 0; 
    string linha, string_base = "datasets/";
    while (getline(arquivo, linha)) {
        ++num_linhas;
        istringstream iss(linha);
        string token;
        iss >> token; // Ignora o primeiro token "Lx"
        int contador_numeros = 0;
        while (iss >> token) { // lendo cada arquivo txt chamado
            ++contador_numeros;
            string numero = string_base + token + ".txt";
            numero = removeChar(numero,',');
            vector<double> numeros = lerNumeros(numero);
            double temp = somativa(numeros); 
            cout << endl << " SOMATIVA DO ARQUIVO [" << numero << "] = [" << temp << "]";
            totalLinha += temp;
        }
        cout << endl << endl << "Na linha [" << num_linhas << "] tem [" << contador_numeros << "] textos chamados." << endl;
        cout << endl << endl << "A Somativa da linha é [" << totalLinha <<  "]" << endl << endl;
        totalProcesso += totalLinha;
    }
    ofstream output(saida,ios::app);
    if (!output.is_open()) {
        cerr << "Erro ao abrir o arquivo!!!" << endl;
        return;
    }
    output << "[TOTAL PROCESSO " << processo << "]" << endl << totalProcesso << endl; 
    output.close(); 
    arquivo.close(); 
}

void principal(const string& saida){
    int quantidade;
    cout << "Digite a quantidade de processos a serem computados: ";
    cin >> quantidade;
    string string_base = "datasets/";
    ofstream output(saida,ios::app);
    clock_t start = clock(); // Inicia o cronômetro
    for(int i=1;i<quantidade+1;i++){
        string numero = string_base + "P";
        numero += to_string(i);
        numero += ".txt";
        cout << numero;
        lerProcesso(numero,saida,i);
    }
    clock_t end = clock(); // Finaliza o cronômetro
    double elapsed_secs = double(end - start) / CLOCKS_PER_SEC;
    cout << "Tempo decorrido: " << elapsed_secs << " segundos." << endl;
    output << endl << endl << "[TEMPO DE EXECUÇÃO]:" << elapsed_secs << "segundos.";
}