/*
🎯 EXERCICE 16 : TABLEAUX SIMPLES - RAFRAÎCHISSEMENT COMPLET
==============================================================

📚 THÉORIE APPROFONDIE :

Un TABLEAU est une COLLECTION D'ÉLÉMENTS du même type, stockés de manière CONTIGUË en mémoire.

🧠 ANALOGIE : Imagine un parking avec des places numérotées 0, 1, 2, 3...
   - Chaque place = un élément du tableau
   - Le numéro de place = l'INDEX
   - Toutes les voitures sont du même type = même type de données

📋 CONCEPTS CLÉS :
1. DÉCLARATION : type nom[taille];
2. INDEX : commence à 0, va jusqu'à (taille-1)
3. ACCÈS : nom[index] pour lire/écrire
4. MÉMOIRE : éléments stockés côte à côte

⚠️  PIÈGES COURANTS :
- Index hors limites (crash ou comportement bizarre)
- Confusion entre taille et dernier index
- Oubli d'initialisation

🎯 MISSION : Créer un gestionnaire de notes d'étudiants avec :
1. Saisie de 5 notes
2. Calcul de la moyenne
3. Recherche de la note maximale et minimale
4. Affichage formaté des résultats

💡 BONUS : Gestion des erreurs de saisie
*/

#include <iostream>
#include <iomanip>  // Pour std::setprecision
using namespace std;

const int TAILLE = 5; // Taille du tableau

float moyenne(const float (&notes)[TAILLE]) {
    float sum = 0.0;
    for(int i = 0; i < TAILLE; i++) {
        sum += notes[i]; // Additionne chaque note
    }
    return sum / TAILLE; // Retourne la moyenne
}

float max(const float (&notes)[TAILLE]) {
    float maxNote = notes[0]; // Initialiser avec la première note
    for(int i = 1; i < TAILLE; i++) {
        if (notes[i] > maxNote) {
            maxNote = notes[i]; // Met à jour la note maximale
        }
    }
    return maxNote; // Retourne la note maximale
}

float min(const float (&notes)[TAILLE]) {
    float minNote = notes[0]; // Initialiser avec la première note
    for(int i = 1; i < TAILLE; i++) {
        if (notes[i] < minNote) {
            minNote = notes[i]; // Met à jour la note minimale
        }
    }
    return minNote; // Retourne la note minimale
}

void printBultin(const float (&notes)[TAILLE]) {
    cout << "=== BILAN DES NOTES ===" << endl;
    cout << "Notes saisies : " << endl;
    for(int i = 0; i < TAILLE; i++) {
        cout << "Note " << i+1 << " : " << setprecision(2) << fixed << notes[i] << "/20" << endl;
    }
    cout << endl;
    cout << "Moyenne : " << setprecision(2) << fixed << moyenne(notes) << endl;
    cout << "Note maximale : " << setprecision(2) << fixed << max(notes) << endl;
    cout << "Note minimale : " << setprecision(2) << fixed << min(notes) << endl;
}

void saisirNotes(float (&notes)[TAILLE]) {
    cout << "Entrez " << TAILLE << " notes (0-20) :" << endl;
    for(int i = 0; i < TAILLE; i++) {
        cout << "Note " << i+1 << ": ";
        cin >> notes[i];
        if (notes[i] < 0 || notes[i] > 20) {
            cout << "Note invalide, veuillez entrer une note entre 0 et 20." << endl;
            i--; // Refaire la saisie pour cette note
        }
    }
}

int main() {
    float notes[TAILLE]; // Déclaration du tableau de notes
    saisirNotes(notes); // Saisie des notes
    printBultin(notes); // Affichage du bilan
    return 0;
}

/*
📚 EXPLICATIONS DÉTAILLÉES À COMPRENDRE :

1. 🏗️ DÉCLARATION : float notes[5];
   - Réserve 5 cases mémoire consécutives
   - Chaque case peut contenir un float
   - Index valides : 0, 1, 2, 3, 4

2. 🔢 ACCÈS : notes[i]
   - notes[0] = première note
   - notes[4] = cinquième note
   - notes[5] = ❌ ERREUR ! Index hors limite

3. 🔄 PARCOURS : for (int i = 0; i < 5; i++)
   - i va de 0 à 4 (inclus)
   - Condition < 5 (pas <= 4) pour éviter erreurs

4. 🧮 CALCUL : somme += notes[i]
   - Additionne chaque élément du tableau
   - Équivalent à : somme = somme + notes[i]

⭐ TESTE ton code avec des notes comme : 15.5, 12.0, 18.5, 9.5, 16.0
   Résultat attendu : Moyenne = 14.30, Max = 18.5, Min = 9.5
*/
