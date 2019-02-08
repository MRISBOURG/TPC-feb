/*************************************************************************
 Ligne  -  description
 -------------------
 début                : $Janvier 2019$
 copyright            : $Aymeric Cousaert, Mael Risbourg$
 e-mail               : $aymeric.cousaert@insa-lyon.fr,
                         mael.risbourg@insa-lyon.fr$
 *************************************************************************/

//---------- Interface de la classe <Ligne> (fichier Ligne.h) ------------
#if ! defined (LIGNE_H)
#define LIGNE_H
#include <string>
using namespace std;


//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes
const string EXTENSIONS[8] {".jpg", ".png", ".gif", ".jpeg", ".bmp", ".tif", ".ico", ".js"};
//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Ligne>
//
//
//------------------------------------------------------------------------

class Ligne
{
    //----------------------------------------------------------------- PUBLIC
    
public:
    //----------------------------------------------------- Méthodes publiques
    // type Méthode(liste des paramètres);
    // Mode d'emploi :
    //
    // Contrat :
    //
    static string decompose(char sep, string uneLigne);
    
    void afficher();
    
    string getCible();
    
    string getReferer();
    
    int getHeure();
    
    bool ExtensionEstImageouJs();
    
    string getExtension();
    
    //------------------------------------------------- Surcharge d'opérateurs
    Ligne & operator=(const Ligne & unLigne);
    // Mode d'emploi :
    //
    // Contrat :
    //
    
    
    //-------------------------------------------- Constructeurs - destructeur
    Ligne(const Ligne & unLigne);
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //
    
    Ligne(string uneLigne);
    // Mode d'emploi :
    //
    // Contrat :
    //
    
    virtual ~Ligne();
    // Mode d'emploi :
    //
    // Contrat :
    //
    
    //------------------------------------------------------------------ PRIVE
    
protected:
    //----------------------------------------------------- Méthodes protégées
    
    //----------------------------------------------------- Attributs protégés
    
    string ip;
    string logName;
    string authenticatedUser;
    int jour;
    string mois;
    int annee;
    int heure;
    int minute;
    int seconde;
    string decalage;
    string action;
    string cible;
    string extension;
    int status;
    string donnees;
    string referer;
    string navigateur;
    
};

//-------------------------------- Autres définitions dépendantes de <Ligne>

#endif // LIGNE_H
