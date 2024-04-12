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




void lerProcesso(const string& nome_arquivo) {
    ifstream arquivo(nome_arquivo);
    if (!arquivo.is_open()) {
        cerr << "Erro ao abrir o arquivo!!!" << endl;
        return;
    }

    int num_linhas = 0;
    string linha, numero_base = "datasets/";
    while (getline(arquivo, linha)) {
        ++num_linhas;
        istringstream iss(linha);
        string token;
        // Ignora o primeiro token "Lx"
        iss >> token;
        int contador_numeros = 0;
        while (iss >> token) {
            ++contador_numeros;
            string numero = numero_base + token + ".txt";
            cout << numero;
            //vector<double> numeros = lerNumeros(numero); // Supondo que lerNumeros esteja definida em algum lugar
            // Faça algo com o vetor de números lidos, se necessário
        }
        cout << endl << "Na linha [" << num_linhas << "] tem [" << contador_numeros << "] textos chamados." << endl << endl;
    }

    arquivo.close();
}