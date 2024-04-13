#ifndef ANALISE_HPP
#define ANALISE_HPP
#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <ctime>

using namespace std;

vector<double> lerNumeros(const string& nome_arquivo);
double somativa(const vector<double>);
void lerProcesso(const string& entrada, const string& saida, int processo);
void principal(const string& saida);
string removeChar(string str, char ch);

#endif // ANALISE_HPP
