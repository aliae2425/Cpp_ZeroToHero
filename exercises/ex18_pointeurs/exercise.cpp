/*
🎯 EXERCICE 18 : POINTEURS - CONCEPT CLÉ APPROFONDI
==================================================

📚 THÉORIE ULTRA-DÉTAILLÉE :

Un POINTEUR est une VARIABLE qui stocke l'ADRESSE MÉMOIRE d'une autre variable.

🧠 ANALOGIE CONCRÈTE : 
   - Variable normale = MAISON avec une adresse (ex: "123 Rue Victor Hugo")
   - Pointeur = POST-IT avec l'adresse écrite dessus
   - Déréférencement = Suivre l'adresse pour aller à la maison

🏗️ ARCHITECTURE MÉMOIRE :
   [ADRESSE]    [CONTENU]
   0x1000   →   42        (variable int x)
   0x2000   →   0x1000    (pointeur vers x)

📋 SYNTAXE FONDAMENTALE :
1. DÉCLARATION : type* nom;           // Pointeur vers un type
2. ADRESSE : &variable;               // Récupère l'adresse 
3. DÉRÉFÉRENCEMENT : *pointeur;       // Accède au contenu
4. ASSIGNATION : pointeur = &variable; // Le pointeur "pointe vers"

⚡ DIFFÉRENCES PRATIQUES POINTEURS vs RÉFÉRENCES :

POINTEURS :
✅ Peuvent être réassignés (pointer vers autre chose)
✅ Peuvent être NULL/nullptr
✅ Arithmétique possible (ptr + 1, ptr++)
✅ Gestion mémoire dynamique (new/delete)
❌ Syntaxe plus complexe
❌ Risque de segfault si mal utilisés

RÉFÉRENCES :
✅ Syntaxe plus simple (comme un alias)
✅ Pas de risque NULL
✅ Initialisation obligatoire
❌ Ne peuvent pas être réassignées
❌ Pas d'arithmétique
❌ Pas de gestion mémoire dynamique

🎯 MISSION PRATIQUE : Gestionnaire de variables avec pointeurs
1. Créer des variables de différents types
2. Utiliser des pointeurs pour les manipuler
3. Démontrer les avantages/inconvénients vs références
4. Simulation d'échange de valeurs (swap)
5. Parcours de tableau avec arithmétique de pointeurs

💡 FOCUS : Comprendre QUAND et POURQUOI utiliser pointeurs vs références
*/

#include <iostream>
using namespace std;


// 🎯 DÉFI : Implémente cette fonction
void multiplierParDeux(int* nombre) {
    // TON CODE ICI
    *nombre *= 2; // Multiplie la valeur pointée par 2
}

int main() {
    
    // 🧪 TESTS À EFFECTUER
    int a = 5, b = 10, c = 7;
    cout << "Avant : a=" << a << ", b=" << b << ", c=" << c << endl;
    
    multiplierParDeux(&a);
    multiplierParDeux(&b);  
    multiplierParDeux(&c);
    
    cout << "Après : a=" << a << ", b=" << b << ", c=" << c << endl;
    // Résultat attendu : a=10, b=20, c=14
    
    return 0;
}

/*
📚 EXPLICATIONS APPROFONDIES À MAÎTRISER :

1. 🏠 DÉCLARATION ET INITIALISATION :
   int x = 42;        // Variable normale
   int* ptr = &x;     // Pointeur vers x
   int& ref = x;      // Référence vers x (pour comparaison)

2. 🔍 ACCÈS AUX VALEURS :
   cout << x;         // Affiche 42 (valeur directe)
   cout << &x;        // Affiche 0x1000 (adresse de x)
   cout << ptr;       // Affiche 0x1000 (contenu du pointeur = adresse de x)
   cout << *ptr;      // Affiche 42 (déréférencement = valeur pointée)

3. 🔄 MODIFICATION :
   *ptr = 100;        // Change x via le pointeur
   cout << x;         // Affiche 100 (x a été modifié)

4. 🎯 RÉASSIGNATION :
   int y = 99;
   ptr = &y;          // Maintenant ptr pointe vers y
   ref = y;           // ❌ ERREUR ! Référence ne peut pas être réassignée

5. 🧮 ARITHMÉTIQUE DE POINTEURS :
   int arr[] = {10, 20, 30};
   int* p = arr;      // Pointe vers le premier élément
   cout << *p;        // Affiche 10
   p++;               // Avance au prochain élément
   cout << *p;        // Affiche 20
   cout << *(p+1);    // Affiche 30

⚠️ PIÈGES MORTELS À ÉVITER :
- Pointeur non initialisé : int* ptr; *ptr = 5; // CRASH !
- Pointeur NULL : int* ptr = nullptr; *ptr = 5; // CRASH !
- Dangling pointer : Pointeur vers mémoire libérée
- Double delete : Libérer la même mémoire deux fois

🎮 EXERCICES PRATIQUES :
A. Créer et manipuler des pointeurs simples
B. Comparer pointeur vs référence pour même tâche
C. Fonction swap() avec pointeurs
D. Parcours tableau avec arithmétique de pointeurs
E. Démonstration des pièges courants (contrôlés)
*/
