#include <iostream>
#include <fstream>
#include <sstream>
#include <cmath>
#include <iomanip>
#include "Utils.hpp"

using namespace std;

int main()
{
    string file_input="data.csv";
    string file_output="result.txt";
    ifstream in_str(file_input);
    ofstream out_str(file_output);

    if (in_str.fail()||out_str.fail())
    {
        cerr<<"C'e' un errore nella lettura di '"<<file_input<<"' o nella creazione di '"<< file_output<<"'"<<endl;
        return 1;
    }

    string linea; //stringa dove vado a mettere la riga del file

    // assegnare il valore del capitale investito
    in_str >> linea;
    double S=ConvertiDato<double>(linea);

    // assegnare il valore del numero di asset
    in_str >> linea;
    int n=ConvertiDato<int>(linea);

    // saltare la linea con solo caratteri
    in_str >> linea;

    //memorizzare i valori dei pesi e dei tassi di ritorno
    double* w=new double[n]; //array con i pesi
    double* r=new double[n]; //array con i tassi
    MemorizzaPesiTassi(in_str,n,w,r);
    in_str.close(); //la lettura del file è finita

    //calcolo del valore finale
    double V=0;
    for(int i=0;i<n;i++)
    {
        V+=(1+r[i])*S*w[i];
    }

    //calcolo del tasso di ritorno complessivo
    double R=V/S-1;

    //stampare sul file di output
    out_str.setf(ios_base::fixed); //fisso 2 cifre dopo la virgola per S
    out_str << setprecision(2);
    out_str << "S= "<<S<<", ";
    out_str.unsetf(ios_base::fixed);
    out_str << setprecision(6);
    out_str << "n= "<<n<<endl;
    StampaArray(out_str,w,n,'w');
    StampaArray(out_str,r,n,'r');
    out_str << "Rate of return of the portfolio: " <<R<<endl;
    out_str << setprecision(2);
    out_str.setf(ios_base::fixed);
    out_str << "V: "<<V<<endl;
    out_str.close(); //la stampa dei risultati è finita

    delete[] w; //eliminazione della memoria richiesta prima dell'uscita dal blocco
    delete[] r;
    return 0;
}
