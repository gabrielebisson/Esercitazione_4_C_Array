#include "Utils.hpp"

using namespace std;

template<typename T>
T ConvertiDato(const string& stringa)
{
    size_t pos=stringa.find(';');
    string sottostringa=stringa.substr(pos+1);
    istringstream convertitore(sottostringa);
    T esito;
    convertitore >> esito;
    return esito;
}

template double ConvertiDato<double>(const string& stringa);
template int ConvertiDato<int>(const string& stringa);

void StampaArray(ofstream& ofs,double* r,const int& n,char c)
{
    ofs << c <<" = [";
    for(int i=0;i<n;i++)
    {
        ofs << " "<< r[i];
    }
    ofs << " ]"<<endl;
}

void MemorizzaPesiTassi(ifstream& ifs, const int& n,double* w, double* r) //assumo che il file di input sia scritto correttamente
{
    string linea;
    string sottostringa;
    double val;
    size_t pos;
    istringstream convertitore(sottostringa);
    for(int i=0;i<n;i++)
    {
        //memorizzazione dei pesi
        ifs >> linea;
        pos=linea.find(';');
        sottostringa=linea.substr(1,pos-1);
        convertitore.clear();
        convertitore.str(sottostringa);
        convertitore >> val;
        w[i]=val;

        //memorizzazione dei tassi
        sottostringa=linea.substr(pos+1);
        convertitore.clear();
        convertitore.str(sottostringa);
        convertitore >> val;
        r[i]=val;
    }
}
