/*
🎯 EXERCICE 25 : ENUMERATIONS - GESTION DE JOURS DE RESTAURANT
==============================================================

📚 THÉORIE APPROFONDIE :

Les **énumérations (enum)** sont des types de données qui permettent de définir 
un ensemble fini de valeurs nommées. Imagine un restaurant qui a des menus différents 
selon les jours - plutôt que d'utiliser des nombres (0=lundi, 1=mardi...), 
les énumérations donnent des noms significatifs ! 🧠

En C++, au lieu d'écrire `int jour = 1;` (qu'est-ce que 1 ?), 
tu écris `Jour aujourdhui = MARDI;` (c'est clair ! 🏗️)

📋 SYNTAXE FONDAMENTALE :
```cpp
enum NomEnum {
    VALEUR1,     // = 0 par défaut
    VALEUR2,     // = 1 par défaut  
    VALEUR3 = 5, // valeur explicite
    VALEUR4      // = 6 (suit la séquence)
};
```

⚡ DIFFÉRENCES AVEC LES CONCEPTS PRÉCÉDENTS :
- **Variables** : stockent des valeurs quelconques
- **Constantes** : valeur fixe unique
- **Enums** : ensemble limité de valeurs nommées et logiquement liées

🎯 AVANTAGES ENUMERATIONS :
- Code plus lisible : `ROUGE` vs `0`
- Prévention d'erreurs : impossible d'assigner une valeur invalide
- Auto-complétion IDE : voir toutes les valeurs possibles
- Maintenance facile : changer l'ordre n'affecte pas la logique

💡 MISSION PRATIQUE : 
Crée un système de gestion pour un restaurant qui adapte son menu selon le jour !
1. Créer une énumération `JourSemaine` avec les 7 jours
2. Créer une énumération `TypeMenu` (VIANDE, POISSON, VEGETARIEN, PIZZA)
3. Fonction `obtenirMenu(JourSemaine jour)` qui retourne le TypeMenu du jour
4. Fonction `afficherMenu(TypeMenu menu)` qui affiche le nom et prix du menu
5. Programme principal qui teste tous les jours de la semaine

🔥 BONUS : Ajouter une fonction `joursAvecMenu(TypeMenu menu)` qui liste 
tous les jours où ce menu est servi !
*/

#include <iostream>
using namespace std;

// 🎯 TON CODE ICI - Définis tes énumérations et fonctions

enum JourSemaine {
    LUNDI, MARDI, MERCREDI, JEUDI, VENDREDI, SAMEDI, DIMANCHE
};

enum TypeMenu {
    VIANDE, POISSON, VEGETARIEN, PIZZA
};

TypeMenu obtenirMenu(JourSemaine jour) {
    switch (jour) {
        case LUNDI:
        case MARDI:
            return VIANDE; // Menu viande
        case MERCREDI:
            return POISSON; // Menu poisson
        case JEUDI:
            return VEGETARIEN; // Menu vegetarien
        case VENDREDI:
            return PIZZA; // Menu pizza
        case SAMEDI:
        case DIMANCHE:
            return VEGETARIEN; // Weekend vegetarien
        default:
            return VEGETARIEN; // Par défaut
    }
}

void afficherMenu(TypeMenu menu) {
    switch (menu) {
        case VIANDE:
            cout << "Menu Viande - 15€" << endl;
            break;
        case POISSON:
            cout << "Menu Poisson - 18€" << endl;
            break;
        case VEGETARIEN:
            cout << "Menu Vegetarien - 12€" << endl;
            break;
        case PIZZA:
            cout << "Menu Pizza - 10€" << endl;
            break;
        default:
            cout << "Menu Inconnu" << endl;
    }
}



int main() {
    cout << "=== 🍽️  RESTAURANT 'LES ENUMS GOURMET' ===" << endl;
    
    // 🎯 TON CODE ICI - Teste ton système pour tous les jours
    
    for (int i = LUNDI; i <= DIMANCHE; i++) {
        JourSemaine jour = static_cast<JourSemaine>(i);
        TypeMenu menu = obtenirMenu(jour);
        
        cout << "Jour : " << jour << " - ";
        afficherMenu(menu);
    }
    
    return 0;
}
