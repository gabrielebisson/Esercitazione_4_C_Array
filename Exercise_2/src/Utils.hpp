#pragma once

#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

template<typename T>
T ConvertiDato(const string& stringa);

void StampaArray(ofstream& ofs,double* r,const int& n,char c);

void MemorizzaPesiTassi(ifstream& ifs, const int& n,double* w, double* r);
