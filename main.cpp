#include <iostream>
#include <string>
#include <fstream>
#include <list>
#include <map>
#include <cstring>

using namespace std;

#include "Ligne.h"
#include "Classement.h"
#include "Graphe.h"

map<string, informations> mapCibles;

informations remplissage(Ligne& uneLigne)
{
    informations infos;
    infos.nbApparition = 1;
    infos.mapReferers.insert(pair<string,int>(uneLigne.getReferer(), 1));
    return infos;
}

void inserer(Ligne& l)
{
    if (mapCibles.find(l.getCible()) == mapCibles.end())
    {
        informations infos = remplissage(l);
        mapCibles.insert(pair<string,informations>(l.getCible(), infos));
    }
    else if (mapCibles[l.getCible()].mapReferers.find(l.getReferer()) == mapCibles[l.getCible()].mapReferers.end())
    {
        mapCibles[l.getCible()].mapReferers.insert(pair<string,int>(l.getReferer(),1));
        mapCibles[l.getCible()].nbApparition++;
    }
    else
    {
        mapCibles[l.getCible()].mapReferers[l.getReferer()]++;
        mapCibles[l.getCible()].nbApparition++;
    }
}

int main(int argc, char* argv[])
{
    int heure = 0;
    string fichierDot = "";
    string fichierLog = "";
    bool optionG = false;
    bool optionE = false;
    bool optionT = false;
    int i = 1;
    while (i < argc)
    {
        if (strcmp(argv[i],"-g") == 0)
        {
            optionG = true;
            if (i == argc - 1)
            {
                cerr << "[Erreur 5] Le nom du fichier associé à l'option g n'a pas été spécifié." << endl;
                return 0;
            }
            fichierDot = argv[i + 1];
            i++;
        }
        else if (strcmp(argv[i],"-e") == 0)
        {
            optionE = true;
        }
        else if (strcmp(argv[i],"-t") == 0)
        {
            optionT = true;
            if (i == argc - 1)
            {
                cerr << "[Erreur 4] L'heure n'a pas été spécifiée." << endl;
                return 0;
            }
            heure = atoi(argv[i + 1]);
            if (heure < 0 || heure > 23)
            {
                cerr << "[Erreur 3] L'heure spécifiée doit être comprise entre 0 et 23 inclus." << endl;
                return 0;
            }
            if ((strcmp(argv[i + 1], "0") != 0 && heure == 0))
            {
                cerr << "[Erreur 4] L'heure n'a pas été spécifiée." << endl;
                return 0;
            }
            i++;
        }
        else if (i == argc - 1)
        {
             fichierLog = argv[i];
        }
        else
        {
            cerr << "[Erreur 7] Une option spécifiée au moins n'existe pas." << endl;
            return 0;
        }
        i++;
    }
    string ligneFichier;
    if (fichierLog == argv[0])
    {
        cerr << "[Erreur 6] Le nom du fichier journal n'a pas été spécifié." << endl;
    }
    ifstream fichier(fichierLog, ios::in);
    if (fichier)
    {
        while (getline(fichier, ligneFichier))
        {
            Ligne ligne = Ligne(ligneFichier);
            if (!optionE && !optionT)
            {
                inserer(ligne);
            }
            else if (!ligne.ExtensionEstImageouJs() && optionE && !optionT)
            {
                inserer(ligne);
            }
            else if (ligne.getHeure() >= heure && ligne.getHeure() < heure + 1 && optionT && !optionE)
            {
                inserer(ligne);
            }
            else if (!ligne.ExtensionEstImageouJs() && ligne.getHeure() >= heure && ligne.getHeure() < heure + 1 && optionE && optionT)
            {
                inserer(ligne);
            }
            else {}
        }
        fichier.close();
    }
    else
    {
        cerr << "[Erreur 1] Le fichier à analyser n'a pas pu être ouvert." << endl;
        return 0;
    }
    if (optionG)
    {
        if (fichierDot == "")
        {
            cerr << "[Erreur 5] Le nom du fichier associé à l'option g n'a pas été spécifié." << endl;
            return 0;
        }
        ofstream fichier(fichierDot, ios::out);
        if (fichier)
        {
            Graphe unGraphe;
            fichier << unGraphe << endl;
        }
        else
        {
             cerr << "[Erreur 2] Le fichier dot fourni n'a pas pu être ouvert." << endl;
            return 0;
        }
    }
    Classement CiblesLesPlusVisitees = Classement();
    CiblesLesPlusVisitees.afficher();
    return 0;
}
