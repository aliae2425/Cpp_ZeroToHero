// 🔢 EXERCICE 02 : VARIABLES ET TYPES DE BASE
// Niveau : 🌱 ÉCHAUFFEMENT  
// XP à gagner : 150 XP
// Badge potentiel : 🔢 Maître des Variables

/*
🎯 OBJECTIF :
Apprendre à déclarer et utiliser les différents types de variables en C++.
Tu vas manipuler des nombres, du texte et des valeurs booléennes.

📋 CONSIGNES :
1. Déclarer une variable de chaque type : int, float, double, char, string, bool
2. Leur assigner des valeurs appropriées
3. Afficher chaque variable avec une description
4. Montrer la différence de précision entre float et double

💡 EXEMPLE DE SORTIE ATTENDUE :
Entier : 42
Nombre décimal (float) : 3.14159
Nombre décimal (double) : 3.141592653589793
Caractère : A
Chaîne : Hello C++
Booléen : 1 (ou true)

✅ CRITÈRES DE VALIDATION :
- Utilise au moins 6 types de variables différents
- Affiche chaque variable avec une étiquette claire
- Le programme compile et s'exécute correctement

🏆 BONUS :
- Utilise sizeof() pour afficher la taille en mémoire de chaque type
- Essaie d'afficher un bool avec boolalpha pour voir "true/false"
*/

#include <iostream>
#include <string>
using namespace std;

int main() {
    // 🔽 DÉCLARE TES VARIABLES ICI 🔽
    int nombre = 42;           // Nombres entiers
    float decimal = 3.14f;     // Nombres décimaux (précision simple)
    double precision = 3.141592653589793; // Nombres décimaux (double précision)
    char lettre = 'A';         // Un seul caractère
    string texte = "Hello C++"; // Une chaîne de caractères
    bool condition = true;     // Une valeur booléenne
    
    
    // 🔽 AFFICHE TES VARIABLES ICI 🔽
    cout << "=== VARIABLES DE BASE ===" << endl;
    cout << "Entier : " << nombre << endl;
    cout << "Nombre décimal (float) : " << decimal << endl;
    cout << "Nombre décimal (double) : " << precision << endl;
    cout << "Caractère : " << lettre << endl;
    cout << "Chaîne : " << texte << endl;
    cout << "Booléen : " << boolalpha << condition << endl;
    
    // Bonus : Afficher la taille de chaque type
    cout << endl << "=== TAILLES DES TYPES EN MÉMOIRE ===" << endl;
    cout << "Taille de int : " << sizeof(nombre) << " octets" << endl;
    cout << "Taille de float : " << sizeof(decimal) << " octets" << endl;
    cout << "Taille de double : " << sizeof(precision) << " octets" << endl;
    cout << "Taille de char : " << sizeof(lettre) << " octets" << endl;
    cout << "Taille de string : " << sizeof(texte) << " octets" << endl;
    cout << "Taille de bool : " << sizeof(condition) << " octets" << endl;
    // 🔼 TON CODE AU-DESSUS 🔼
    return 0;
}
