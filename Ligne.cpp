/*************************************************************************
 Ligne  -  description
 -------------------
 début                : $Janvier 2019$
 copyright            : $Aymeric Cousaert, Mael Risbourg$
 e-mail               : $aymeric.cousaert@insa-lyon.fr,
                         mael.risbourg@insa-lyon.fr$
 *************************************************************************/

//---------- Réalisation de la classe <Ligne> (fichier Ligne.cpp) --------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
using namespace std;

//------------------------------------------------------ Include personnel
#include "Ligne.h"


//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type Ligne::Méthode(liste des paramètres)
// Algorithme :
//
//{
//} //----- Fin de Méthode
string Ligne::decompose(char sep, string uneLigne)
{
    int i = 0;
    char a = uneLigne[i];
    string retour = "";
    while (a != sep)
    {
        retour += a;
        a = uneLigne[++i];
    }
    return retour;
}

string Ligne::getCible()
{
    return cible;
}
string Ligne::getReferer()
{
    return referer;
}

int Ligne::getHeure()
{
    return heure;
}

void Ligne::afficher()
{
    cout << " " << ip;
    cout << " " << logName;
    cout << " " << authenticatedUser;
    cout << " " << jour;
    cout << " " << mois;
    cout << " " << annee;
    cout << " " << heure;
    cout << " " << minute;
    cout << " " << seconde;
    cout << " " << decalage;
    cout << " " << action;
    cout << " " << cible;
    cout << " " << status;
    cout << " " << donnees;
    cout << " " << referer;
    cout << " " << navigateur << endl;
}

bool Ligne::ExtensionEstImageouJs()
{
    for (int i = 0; i < 8; i++)
    {
        if (extension == EXTENSIONS[i])
        {
            return true;
        }
    }
    return false;
}

string Ligne::getExtension()
{
    return extension;
}

//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur
Ligne::Ligne(const Ligne & unLigne)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Ligne>" << endl;
#endif
} //----- Fin de Ligne (constructeur de copie)


Ligne::Ligne(string uneLigne)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Ligne>" << endl;
#endif
    ip = decompose(' ', uneLigne);
    uneLigne = uneLigne.replace(0, ip.size() + 1, "");
    logName = decompose(' ', uneLigne);
    uneLigne = uneLigne.replace(0, logName.size() + 1, "");
    authenticatedUser = decompose(' ', uneLigne);
    uneLigne = uneLigne.replace(0, authenticatedUser.size() + 2, "");
    string unJour = decompose('/', uneLigne);
    uneLigne = uneLigne.replace(0, unJour.size() + 1, "");
    jour = stoi(unJour);
    mois = decompose('/', uneLigne);
    uneLigne = uneLigne.replace(0, mois.size() + 1, "");
    string unAnnee = decompose(':', uneLigne);
    uneLigne = uneLigne.replace(0, unAnnee.size() + 1, "");
    annee = stoi(unAnnee);
    string uneHeure = decompose(':', uneLigne);
    uneLigne = uneLigne.replace(0, uneHeure.size() + 1, "");
    heure = stoi(uneHeure);
    string uneMinute = decompose(':', uneLigne);
    uneLigne = uneLigne.replace(0, uneMinute.size() + 1, "");
    minute = stoi(uneMinute);
    string uneSeconde = decompose(' ', uneLigne);
    uneLigne = uneLigne.replace(0, uneSeconde.size() + 1, "");
    seconde = stoi(uneSeconde);
    decalage = decompose(']', uneLigne);
    uneLigne = uneLigne.replace(0, decalage.size() + 3, "");
    action = decompose(' ', uneLigne);
    uneLigne = uneLigne.replace(0, action.size() + 1, "");
    cible = decompose('"', uneLigne);
    uneLigne = uneLigne.replace(0, cible.size() + 2, "");
    string unStatus = decompose(' ', uneLigne);
    uneLigne = uneLigne.replace(0, unStatus.size() + 1, "");
    status = stoi(unStatus);
    donnees = decompose(' ', uneLigne);
    uneLigne = uneLigne.replace(0, donnees.size() + 2, "");
    referer = decompose('"', uneLigne);
    uneLigne = uneLigne.replace(0, referer.size() + 3, "");
    navigateur = decompose('"', uneLigne);
    uneLigne = uneLigne.replace(0, navigateur.size() + 1, "");

    string tmp = cible;
    string poubelle = decompose('.',tmp);
    tmp = tmp.replace(0, poubelle.size(), "");
    extension = decompose(' ',tmp);
   
} //----- Fin de Ligne


Ligne::~Ligne()
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Ligne>" << endl;
#endif
} //----- Fin de ~Ligne


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
