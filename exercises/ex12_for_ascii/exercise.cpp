// 🔐 EXERCICE 12 : BOUCLE FOR + CARACTÈRES ASCII
// Niveau : 🏋️‍♂️ DÉVELOPPEMENT
// XP à gagner : 250 XP

/*
🎯 OBJECTIF COMBO :
Apprendre les boucles for + manipulation ASCII avec un chiffreur César.
Rattrapage du concept ASCII sauté !

📋 CONSIGNES :
1. Demander un texte à chiffrer
2. Demander un décalage (1-25)
3. Utiliser for pour parcourir chaque caractère
4. Appliquer le décalage ASCII (A→B, B→C, etc.)
5. Afficher le texte chiffré

💡 CONCEPTS NOUVEAUX :
- Boucle for avec compteur
- Conversion char ↔ int
- Manipulation ASCII
- Algorithme César

💡 AIDE ASCII :
- 'A' = 65, 'Z' = 90
- 'a' = 97, 'z' = 122
- Conversion : (char)(lettre + decalage)
*/

#include <iostream>
#include <string>
using namespace std;

const int base = 'A'; // Base pour les majuscules

void chiffrage(string& chaine, int decalage) {
    for( char& c : chaine ) {
        if (isalpha(c)) { // Vérifie si c'est une lettre
            if (isupper(c)) {
                c = (c - 'A' + decalage) % 26 + 'A'; // Applique le décalage pour les majuscules
            } else if (islower(c)) {
                c = (c - 'a' + decalage) % 26 + 'a'; // Applique le décalage pour les minuscules
            }
        }
    }
}

void dechiffrage(string& chaine, int decalage) {
    for( char& c : chaine ) {
        if (isalpha(c)) { // Vérifie si c'est une lettre
            if (isupper(c)) {
                c = (c - 'A' - decalage + 26) % 26 + 'A'; // Applique le décalage inverse pour les majuscules
            } else if (islower(c)) {
                c = (c - 'a' - decalage + 26) % 26 + 'a'; // Applique le décalage inverse pour les minuscules
            }
        }
    }
}


int main() {
    // 🔽 TON CODE ICI 🔽
    int decalage;
    string texte;
    cout << "Entrez le texte à chiffrer : ";
    getline(cin, texte); // Saisie du texte à chiffrer
    cout << "Entrez le décalage (1-25) : ";
    cin >> decalage; // Saisie du décalage

    // Vérification du décalage
    if (decalage < 1 || decalage > 25) {
        cout << "Le décalage doit être entre 1 et 25." << endl;
        return 1; // Sortie du programme avec erreur
    }

    // Chiffrement du texte
    chiffrage(texte, decalage);
    cout << "Texte chiffré : " << texte << endl;

    cout << "Voulez-vous déchiffrer le texte ? (o/n) : ";
    char choix;
    cin >> choix; // Saisie du choix de l'utilisateur
    if (choix == 'o' || choix == 'O') {
        dechiffrage(texte, decalage);
        cout << "Texte déchiffré : " << texte << endl;
    }
    // 🔼 TON CODE AU-DESSUS 🔼
    return 0;
}
