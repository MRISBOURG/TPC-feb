/*************************************************************************
 Graphe  -  description
 -------------------
 début                : $Janvier 2019$
 copyright            : $Aymeric Cousaert, Mael Risbourg$
 e-mail               : $aymeric.cousaert@insa-lyon.fr,
 mael.risbourg@insa-lyon.fr$
 *************************************************************************/

//---------- Interface de la classe <Graphe> (fichier Graphe.h) ----------------
#if ! defined ( GRAPHE_H )
#define GRAPHE_H

//--------------------------------------------------- Interfaces utilisées
#include "Classement.h"
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Graphe>
//
//
//------------------------------------------------------------------------

class Graphe 
{
    //----------------------------------------------------------------- PUBLIC
    
public:
    //----------------------------------------------------- Méthodes publiques
    // type Méthode(liste des paramètres);
    // Mode d'emploi :
    //
    // Contrat :
    //
    
    //------------------------------------------------- Surcharge d'opérateurs
    friend ostream & operator<<(ostream & flux, Graphe & unGraphe);
    
    //-------------------------------------------- Constructeurs - destructeur
    Graphe(const Graphe & unGraphe);
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //
    
    Graphe();
    // Mode d'emploi :
    //
    // Contrat :
    //
    
    virtual ~Graphe();
    // Mode d'emploi :
    //
    // Contrat :
    //
    
    //------------------------------------------------------------------ PRIVE
    
protected:
    //----------------------------------------------------- Méthodes protégées
    
    //----------------------------------------------------- Attributs protégés
    map<string,string> tabNoeud;
};

//-------------------------------- Autres définitions dépendantes de <Graphe>

#endif // GRAPHE_H
