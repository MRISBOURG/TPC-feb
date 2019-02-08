/*************************************************************************
 Classement  -  description
 -------------------
 début                : $Janvier 2019$
 copyright            : $Aymeric Cousaert, Mael Risbourg$
 e-mail               : $aymeric.cousaert@insa-lyon.fr,
                         mael.risbourg@insa-lyon.fr$
 *************************************************************************/

//---------- Interface de la classe <Classement> (fichier Classement.h) --
#if ! defined (CLASSEMENT_H)
#define CLASSEMENT_H

//--------------------------------------------------- Interfaces utilisées
#include <set>

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types
typedef
struct informations
{
    int nbApparition;
    map<string, int> mapReferers;
} informations;

extern map<string, informations> mapCibles;

//------------------------------------------------------------------------
// Rôle de la classe <Classement>
// Cette classe constitue le classement des cibles les plus visitées
//
//------------------------------------------------------------------------

class Classement 
{
    //----------------------------------------------------------------- PUBLIC
    
public:
    //----------------------------------------------------- Méthodes publiques
    // type Méthode(liste des paramètres);
    // Mode d'emploi :
    //
    // Contrat :
    //
    void afficher();
    
    //------------------------------------------------- Surcharge d'opérateurs
    Classement & operator=(const Classement & unClassement);
    // Mode d'emploi :
    //
    // Contrat :
    //
    
    
    //-------------------------------------------- Constructeurs - destructeur
    Classement(const Classement & unClassement);
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //
    
    Classement();
    // Mode d'emploi :
    //
    // Contrat :
    //
    
    virtual ~Classement();
    // Mode d'emploi :
    //
    // Contrat :
    //
    
    //------------------------------------------------------------------ PRIVE
    
protected:
    //----------------------------------------------------- Méthodes protégées
    
    //----------------------------------------------------- Attributs protégés
    string top[10];
};

//-------------------------------- Autres définitions dépendantes de <Classement>

#endif // CLASSEMENT_H
