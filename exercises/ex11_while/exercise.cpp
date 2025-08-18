// 🔄 EXERCICE 11 : BOUCLE WHILE
// Niveau : 🏋️‍♂️ DÉVELOPPEMENT
// XP à gagner : 200 XP

/*
🎯 OBJECTIF :
Apprendre les boucles while avec un jeu de devinette.
Premier exercice niveau DÉVELOPPEMENT !

📋 CONSIGNES :
1. Créer un nombre secret (entre 1-10)
2. Demander à l'utilisateur de deviner
3. Utiliser while pour répéter tant que pas trouvé
4. Compter les tentatives
5. Messages d'aide (trop grand/petit)

💡 CONCEPTS NOUVEAUX :
- Boucle while
- Compteurs
- Conditions de sortie

⚠️ ATTENTION :
- Éviter les boucles infinies !
- Modifier la condition dans la boucle
*/

#include <iostream>
#include <cstdlib>  // Pour rand() et srand()
#include <ctime>    // Pour time()
using namespace std;

int main() {
    // 🔽 TON CODE ICI 🔽
    srand(time(0)); // Initialiser le générateur de nombres aléatoires
    int nombreSecret = rand() % 10 + 1; // Génère un nombre secret entre 1 et 10
    int tentative = 0; // Compteur de tentatives
    int guess = 0; // Variable pour stocker la devinette de l'utilisateur
    bool found = false; // Indicateur de succès

    cout << "Bienvenue dans le jeu de devinette !" << endl;
    cout << "Devinez le nombre secret entre 1 et 10." << endl;
    while (!found) {
        cout << "Entrez votre devinette : ";
        cin >> guess; // Saisie de la devinette de l'utilisateur
        tentative++; // Incrémenter le compteur de tentatives

        if (guess < nombreSecret) {
            cout << "Trop petit ! Essayez encore." << endl; // Indication si trop petit
        } else if (guess > nombreSecret) {
            cout << "Trop grand ! Essayez encore." << endl; // Indication si trop grand
        } else {
            found = true; // Mettre à jour l'indicateur de succès
        }
    }

    cout << "Bravo ! Vous avez trouvé le nombre secret en " << tentative << " tentatives." << endl; // Succès
    cout << "Merci d'avoir joué !" << endl; // Message de fin    
    
    // 🔼 TON CODE AU-DESSUS 🔼
    return 0;
}
