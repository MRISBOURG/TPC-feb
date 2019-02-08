/*************************************************************************
 Graphe  -  description
 -------------------
 début                : $Janvier 2019$
 copyright            : $Aymeric Cousaert, Mael Risbourg$
 e-mail               : $aymeric.cousaert@insa-lyon.fr,
 mael.risbourg@insa-lyon.fr$
 *************************************************************************/

//---------- Réalisation de la classe <Graphe> (fichier Graphe.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
#include <fstream>
#include <map>
using namespace std;

//------------------------------------------------------ Include personnel
#include "Graphe.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type Graphe::Méthode(liste des paramètres)
// Algorithme :
//
//{
//} //----- Fin de Méthode

//------------------------------------------------- Surcharge d'opérateurs
ostream& operator<<(ostream & flux, Graphe & unGraphe)
// Algorithme :
//
{
    flux << "digraph {" << endl;
    // Affichage des noeuds
    set<string> dejaAffiches;
    for (map<string, informations>::iterator it = mapCibles.begin(); it != mapCibles.end(); ++it)
    {
        flux << unGraphe.tabNoeud[it->first] << " [label=\"" << it->first << "\"];" << endl;
        dejaAffiches.insert(it->first);
        for (map<string, int>::iterator itbis = it->second.mapReferers.begin(); itbis != it->second.mapReferers.end(); ++itbis)
        {
            if (dejaAffiches.find(itbis->first) == dejaAffiches.end())
            {
                flux << unGraphe.tabNoeud[itbis->first] << " [label=\"" << itbis->first << "\"];" << endl;
                dejaAffiches.insert(itbis->first);
            }
        }
        
    }
    // Affichage des arcs
    for (map<string, informations>::iterator it = mapCibles.begin(); it != mapCibles.end(); ++it)
    {
        for (map<string, int>::iterator itbis = it->second.mapReferers.begin(); itbis != it->second.mapReferers.end(); ++itbis)
        {
            flux << unGraphe.tabNoeud[it->first] << " -> " << unGraphe.tabNoeud[itbis->first]<< " [label=\"" << itbis->second << "\"];" << endl;
        }
        
    }
  
    flux << "}" << endl;

    return flux;
} //----- Fin de operator =

//-------------------------------------------- Constructeurs - destructeur
Graphe::Graphe(const Graphe & unGraphe)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Graphe>" << endl;
#endif
} //----- Fin de Graphe (constructeur de copie)


Graphe::Graphe()
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Graphe>" << endl;
#endif
    int i = 0;
    for (map<string, informations>::iterator it = mapCibles.begin(); it != mapCibles.end(); ++it)
    {
        string noeud = "Node";
        noeud += to_string(i);
        tabNoeud.insert(pair<string,string>(it->first, noeud));
        for (map<string, int>::iterator itbis = it->second.mapReferers.begin(); itbis != it->second.mapReferers.end(); ++itbis)
        {
            if (tabNoeud.find(itbis->first) == tabNoeud.end())
            {
                i++;
                noeud = "Node";
                noeud += to_string(i);
                tabNoeud.insert(pair<string,string>(itbis->first, noeud));
            }
        }
        i++;
    }
} //----- Fin de Graphe


Graphe::~Graphe()
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Graphe>" << endl;
#endif
} //----- Fin de ~Graphe


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
