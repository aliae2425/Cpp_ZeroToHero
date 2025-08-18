// 🎮 EXERCICE 03 : OPÉRATIONS ARITHMÉTIQUES
// Niveau : 🌱 ÉCHAUFFEMENT
// XP à gagner : 150 XP

/*
🎯 OBJECTIF :
Maîtriser les opérations arithmétiques de base en C++.
Créer une petite démonstration des calculs mathématiques.

📋 CONSIGNES :
1. Demander à l'utilisateur deux nombres
2. Effectuer toutes les opérations : +, -, *, /, %
3. Afficher les résultats de manière claire
4. Gérer la division par zéro (bonus)

💡 EXEMPLE DE SORTIE :
Entrez le premier nombre : 10
Entrez le deuxième nombre : 3

Résultats des opérations :
10 + 3 = 13
10 - 3 = 7
10 * 3 = 30
10 / 3 = 3.33333
10 % 3 = 1

✅ CRITÈRES DE VALIDATION :
- Utilise cin pour saisir les nombres
- Effectue les 5 opérations arithmétiques
- Affichage formaté et lisible
*/

#include <iostream>
using namespace std;

int main() {
    // 🔽 TON CODE ICI 🔽
    int nombre1, nombre2;
    cout << "Entrez le premier nombre : ";
    cin >> nombre1;  // Saisie du premier nombre
    cout << "Entrez le deuxième nombre : ";
    cin >> nombre2;  // Saisie du deuxième nombre

    if ( nombre2  == 0 ) { 
        cout << "Erreur : Division par zéro !" << endl;  // Gérer la division par zéro
        return 1;  // Sortie du programme avec erreur
    }

    // 🔽 EFFECTUE LES OPÉRATIONS ARITHMÉTIQUES ICI 🔽
    cout << endl << "Résultats des opérations :" << endl;
    cout << nombre1 << " + " << nombre2 << " = " << nombre1 + nombre2 << endl;
    cout << nombre1 << " - " << nombre2 << " = " << nombre1 - nombre2 << endl;
    cout << nombre1 << " * " << nombre2 << " = " << nombre1 * nombre2 << endl;
    cout << nombre1 << " / " << nombre2 << " = " << (double)nombre1 / nombre2 << endl;  // Cast pour division décimale
    cout << nombre1 << " % " << nombre2 << " = " << nombre1 % nombre2 << endl;

    // 🔼 TON CODE AU-DESSUS 🔼
    return 0;
}
