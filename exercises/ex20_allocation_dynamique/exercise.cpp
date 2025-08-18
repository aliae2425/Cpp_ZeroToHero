/*
🎯 EXERCICE 20 : ALLOCATION DYNAMIQUE - CONCEPT CLÉ AVANCÉ
==========================================================

📚 THÉORIE ULTRA-DÉTAILLÉE :

L'ALLOCATION DYNAMIQUE permet de créer/détruire de la mémoire PENDANT l'exécution du programme.

🧠 ANALOGIE CONCRÈTE :
   - STATIQUE = Maison que tu achètes (taille fixe, durée de vie connue)
   - DYNAMIQUE = Hôtel où tu réserves des chambres (taille variable, tu choisis quand partir)

🏗️ DIFFÉRENCES FONDAMENTALES :

ALLOCATION STATIQUE (sur la PILE) :
- Déclaration : int arr[10];
- Taille FIXE connue à la compilation
- Destruction AUTOMATIQUE (fin de scope)
- Mémoire limitée (~1-8MB selon système)
- RAPIDE mais RIGIDE

ALLOCATION DYNAMIQUE (sur le TAS) :
- Création : int* ptr = new int[taille];
- Taille VARIABLE décidée à l'exécution  
- Destruction MANUELLE avec delete/delete[]
- Mémoire quasi-illimitée (RAM disponible)
- Plus LENT mais FLEXIBLE

📋 SYNTAXE ESSENTIELLE :
1. CRÉATION : new type;           // Un élément
2. CRÉATION : new type[taille];   // Tableau dynamique
3. DESTRUCTION : delete ptr;      // Un élément
4. DESTRUCTION : delete[] ptr;    // Tableau dynamique

⚠️ RÈGLES D'OR :
- Chaque NEW doit avoir son DELETE correspondant
- new[] → delete[] (pas delete simple !)
- Après delete, le pointeur devient "dangling"
- Toujours vérifier si new a réussi (peut échouer si plus de RAM)

🎯 POURQUOI C'EST CRUCIAL :
- Tableaux de taille inconnue à la compilation
- Structures de données qui grandissent/rétrécissent
- Gestion mémoire optimisée pour gros programmes
- Base des conteneurs STL (vector, list, etc.)

💡 MISSION PRATIQUE : Gestionnaire de tableau dynamique
1. Créer un tableau de taille variable (saisie utilisateur)
2. Remplir le tableau avec des valeurs
3. Effectuer des opérations (tri, recherche, stats)
4. Redimensionner le tableau si nécessaire
5. Libérer proprement la mémoire

🔥 DÉFI BONUS : Détection et gestion des fuites mémoire
*/

#include <iostream>
#include <algorithm>  // Pour std::sort
using namespace std;

int main() {

    // 🎯 TON DÉFI ICI
    int nbEtudiants;
    cout << "Nombre d'étudiants : ";
    cin >> nbEtudiants;
    
    // Allocation dynamique
    float* notes = new float[nbEtudiants];
    if (!notes) {
        cout << "Erreur allocation !" << endl;
        return -1;
    }
    
    // Saisie des notes
    for (int i = 0; i < nbEtudiants; i++) {
        cout << "Note étudiant " << (i+1) << " : ";
        cin >> notes[i];
    }
    
    // Calcul moyenne
    float somme = 0;
    for (int i = 0; i < nbEtudiants; i++) {
        somme += notes[i];
    }
    float moyenne = somme / nbEtudiants;
    
    cout << "Moyenne de la classe : " << moyenne << "/20" << endl;
    
    // Libération OBLIGATOIRE
    delete[] notes;
    notes = nullptr;

    return 0;
}

/*
📚 EXPLICATIONS APPROFONDIES À MAÎTRISER :

1. 🏗️ CRÉATION DYNAMIQUE :
   int taille = 5;
   int* tableau = new int[taille];    // Tableau de 5 entiers
   
   // Vérification (bonne pratique)
   if (!tableau) {
       cout << "Erreur allocation mémoire !" << endl;
       return -1;
   }

2. 🔧 UTILISATION :
   for (int i = 0; i < taille; i++) {
       tableau[i] = i * 10;           // Remplissage
       cout << tableau[i] << " ";     // Lecture
   }

3. 🗑️ LIBÉRATION (OBLIGATOIRE !) :
   delete[] tableau;                  // Libère le tableau
   tableau = nullptr;                 // Évite le dangling pointer

4. 🚨 ERREURS FATALES À ÉVITER :
   // ❌ Oubli de delete
   int* ptr = new int[100];
   // ... utilisation ...
   // Fin du programme → FUITE MÉMOIRE !
   
   // ❌ Mauvais delete
   int* arr = new int[10];
   delete arr;                        // ERREUR ! Doit être delete[]
   
   // ❌ Double delete
   delete[] arr;
   delete[] arr;                      // CRASH ! Déjà libéré

5. ✅ PATTERN CORRECT :
   int* donnees = new int[taille];
   // ... utilisation sécurisée ...
   delete[] donnees;
   donnees = nullptr;

💡 EXERCICES PROGRESSIFS :
A. Tableau dynamique simple avec new/delete
B. Fonction qui retourne un tableau dynamique
C. Redimensionnement de tableau (copie + nouvelle allocation)
D. Gestionnaire de mémoire avec compteur d'allocations
E. Simulation de fuite mémoire et détection
*/
