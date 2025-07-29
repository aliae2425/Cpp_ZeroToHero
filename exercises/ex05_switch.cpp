// 🔀 EXERCICE 05 : SWITCH/CASE
// Niveau : 🌱 ÉCHAUFFEMENT
// XP à gagner : 150 XP
// Badge potentiel : 🔀 Maître du Switch

/*
🎯 OBJECTIF :
Apprendre la structure switch/case en créant un menu de calculatrice.
Alternative élégante aux longues chaînes if/else.

📋 CONSIGNES :
1. Afficher un menu d'opérations (+, -, *, /, %)
2. Demander à l'utilisateur son choix (caractère)
3. Demander deux nombres
4. Utiliser switch/case pour exécuter l'opération
5. Afficher le résultat

💡 EXEMPLE DE SORTIE :
=== CALCULATRICE ===
1. Addition (+)
2. Soustraction (-)
3. Multiplication (*)
4. Division (/)
5. Modulo (%)
Votre choix : +

Entrez le premier nombre : 10
Entrez le deuxième nombre : 3
Résultat : 10 + 3 = 13

✅ CRITÈRES DE VALIDATION :
- Utilise switch/case (pas if/else)
- Gère toutes les opérations (+, -, *, /, %)
- Inclut un default pour choix invalides
- Utilise break dans chaque case

🏆 BONUS :
- Gère la division par zéro
- Menu bien formaté et professionnel
*/

#include <iostream>
using namespace std;

void afficherMenu() {
    cout << "=== CALCULATRICE ===" << endl;
    cout << "1. Addition (+)" << endl;
    cout << "2. Soustraction (-)" << endl;
    cout << "3. Multiplication (*)" << endl;
    cout << "4. Division (/)" << endl;
    cout << "5. Modulo (%)" << endl;
    cout << "Votre choix : ";
}

double operation(char& choix, int nombre1, int nombre2) {
    switch (choix) {
        case '+':
        case '1':
            choix = '+';
            return nombre1 + nombre2;  // Addition
        case '-':
        case '2':
            choix = '-';
            return nombre1 - nombre2;  // Soustraction
        case '*':
        case '3':
            choix = '*';
            return nombre1 * nombre2;  // Multiplication
        case '/':
        case '4':
            choix = '/';
            if (nombre2 == 0) {
                cout << "Erreur : Division par zéro !" << endl;
                return -1;  // Retourne 0 en cas d'erreur
            }
            return (double) nombre1 / nombre2;  // Division
        case '%':
        case '5':
            choix = '%';
            return nombre1 % nombre2;  // Modulo
        default:
            cout << "Choix invalide !" << endl;
            return -1;  // Retourne 0 pour choix invalide
    }
}

int main() {
    // 🔽 TON CODE ICI 🔽
    afficherMenu();  // Affiche le menu des opérations   
    char choix;
    cin >> choix;  // Saisie du choix de l'utilisateur    

    int nombre1, nombre2;
    cout << "Entrez le premier nombre : ";
    cin >> nombre1;  // Saisie du premier nombre
    cout << "Entrez le deuxième nombre : ";
    cin >> nombre2;  // Saisie du deuxième nombre

    // Appel de la fonction pour effectuer l'opération
    double resultat = operation(choix, nombre1, nombre2);
    // Affichage du résultat
    
    if (resultat != -1) {  // Vérifie si l'opération a réussi
        cout << "Résultat : " << nombre1 << " " << choix << " " << nombre2 << " = " << resultat << endl;
    }
    
    // 🔼 TON CODE AU-DESSUS 🔼
    return 0;
}
