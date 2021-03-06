/* ---------------------------
Laboratoire : 10
Fichier : readWriteFile.cpp
Auteur(s) : Besseau
Date :  21.01.2020

But : Ce fichier contient les méthodes permettants de lire et d'écrire
des informations sur des fichiers

Remarque(s) :

Compilateur : g++ 7.4.0

--------------------------- */

#include "readWriteFile.h"

using namespace std;

vector<string> getDataFromFiles(const string &path) {
    vector<string> output;
    fstream ofile;
    ofile.open(path, ios::in);
    if (ofile.fail()) {
        cerr << "error opening file " << path << endl;
        ofile.close();
        return output;
    }

    for (string line; getline(ofile, line);) {
        output.push_back(line);
    }
    ofile.close();
    return output;
}

bool writeDataToFiles(const string &path, const vector<string> &list) {
    fstream ofile;
    ofile.open(path, ios::out);
    if (ofile.fail()) {
        cerr << "error writing to file " << path << endl;
        ofile.close();
        return false;
    }
    for (const string &line : list) {
        ofile << line << endl;
    }
    ofile.close();
    return true;
}