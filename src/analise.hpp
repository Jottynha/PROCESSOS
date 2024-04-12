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
double lerLinha();
void lerProcesso(const string& nome_arquivo);

#endif // ANALISE_HPP
