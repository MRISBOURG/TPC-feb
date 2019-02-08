/*************************************************************************
 Classement  -  description
 -------------------
 début                : $Janvier 2019$
 copyright            : $Aymeric Cousaert, Mael Risbourg$
 e-mail               : $aymeric.cousaert@insa-lyon.fr,
                         mael.risbourg@insa-lyon.fr$
 *************************************************************************/

//------ Réalisation de la classe <Classement> (fichier Classement.cpp) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
#include <map>
using namespace std;

//------------------------------------------------------ Include personnel
#include "Classement.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type Classement::Méthode(liste des paramètres)
// Algorithme :
//
//{
//} //----- Fin de Méthode

void Classement::afficher()
{
     cout << "Voici un Top 10 :" << endl;
     if (mapCibles[top[0]].nbApparition !=0){
         for (int i = 0; i < 10; i++)
         {
             if(mapCibles[top[i]].nbApparition !=0){
                cout << i + 1 << ". " << top[i] << " avec " << mapCibles[top[i]].nbApparition << " accès" << endl;
             }
             else{
                 cout<< "Il n'y a pas plus de sites" <<endl;
                 break;
             }
         }

     }
     else {
         cout<<"Il n'y a aucun résultats correspondant aux critères."<<endl;
     }

}





//------------------------------------------------- Surcharge d'opérateurs



//-------------------------------------------- Constructeurs - destructeur
Classement::Classement(const Classement & unClassement)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Classement>" << endl;
#endif
} //----- Fin de Classement (constructeur de copie)


Classement::Classement()
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Classement>" << endl;
#endif
    int min = 2147483647;
    int indMin = 0;
    string topNonTrie[10];
    int i = 0;
    for (map<string, informations>::iterator it = mapCibles.begin(); it != mapCibles.end(); ++it)
    {
        if (i < 9)
        {
                topNonTrie[i] = it->first;
        }
        else if (i == 9)
        {
                topNonTrie[i] = it->first;
            // On calcule le min
            for (int m = 0; m < 10; m++)
            {
                if (mapCibles[topNonTrie[m]].nbApparition < min)
                {
                    min = mapCibles[topNonTrie[m]].nbApparition;
                    indMin = m;
                }
            }
        }
        else
        {
            // On remplace le min il y a besoin
            if (it->second.nbApparition > min)
            {
                    topNonTrie[indMin] = it->first;
                // On recalcule le min
                for (int m = 0; m < 10; m++)
                {
                    if (mapCibles[topNonTrie[m]].nbApparition <= min)
                        // Le <= est important pour changer succesivement toutes les cibles aux apparitions minimales
                    {
                        min = mapCibles[topNonTrie[m]].nbApparition;
                        indMin = m;
                    }
                }
            }
        }
        i++;
    }
    // On trie le topNonTrie obtenu
    // Tableau qui permet de selectionner à quelles cibles on a encore accès (on va les éliminer au fur et à mesure que le Top 10 se remplit)
    int acces[10] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    int max = 0;

    for (int j = 0; j < 10; j++)
    {
        max = 0;
        int id = 0;
        for (int k = 0; k < 10; k++)
        {
            if (acces[k] == 1 && mapCibles[topNonTrie[k]].nbApparition > max)
            {
                max = mapCibles[topNonTrie[k]].nbApparition;
                id = k;
            }
        }
        acces[id] = 0;
        top[j] = topNonTrie[id];
    }
} //----- Fin de Classement


Classement::~Classement()
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Classement>" << endl;
#endif
} //----- Fin de ~Classement


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
