/*
🎯 EXERCICE 24 : STRUCTURES - GROUPER LES DONNÉES
=================================================

📚 THÉORIE APPROFONDIE :

Une STRUCTURE est un TYPE PERSONNALISÉ qui groupe plusieurs variables de types différents.

🧠 ANALOGIE CONCRÈTE :
   - Structure = FICHE D'IDENTITÉ qui contient plusieurs informations
   - Nom, âge, taille, email... = MEMBRES de la structure
   - Chaque personne = INSTANCE de la structure

🏗️ SYNTAXE FONDAMENTALE :
struct NomStructure {
    type1 membre1;
    type2 membre2;
    // ... autres membres
};

⚡ DIFFÉRENCES AVEC LES CONCEPTS PRÉCÉDENTS :

TABLEAUX : Même type de données, accès par index [0], [1]...
STRUCTURES : Types différents mélangés, accès par nom membre.nom, membre.age

🎯 AVANTAGES STRUCTURES :
- Code plus lisible et organisé
- Passage de paramètres simplifié
- Modélisation du monde réel
- Base pour les classes (POO)

💡 MISSION PRATIQUE : 
Créer un système de gestion d'étudiants avec :
1. Structure Etudiant (nom, prénom, âge, 3 notes)
2. Fonction pour saisir un étudiant
3. Fonction pour afficher un étudiant  
4. Créer un tableau de 3 étudiants
5. Calculer et afficher la moyenne de classe
6. Trouver l'étudiant avec la meilleure moyenne

🔥 BONUS : Ajouter une fonction de recherche par nom
*/

#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
using namespace std;

// 🎯 TON CODE ICI - Crée ta structure et tes fonctions

const int CLASSLENGHT = 3; // Taille du tableau d'étudiants
const int NOTESLENGHT = 3; // Taille du tableau de notes

struct etudiant {
    string nom;
    string prenom;
    int age;
    float notes[3]; // Tableau de 3 notes
    float moyenne() const {
        return (notes[0] + notes[1] + notes[2]) / NOTESLENGHT; // Calcul de la moyenne
    }
};

void inputEtudiant(etudiant& e) {
    cout << "Nom : ";
    cin >> e.nom;
    cout << "prenom : ";
    cin >> e.prenom;
    cout << "age : ";
    cin >> e.age;
    for (int i = 0; i < 3; i++) {
        int note;
        cout << "Note " << (i + 1) << " : ";
        cin >> note;
        if ( note < 20 && note > 0){
            e.notes[i] = note;    
        }else {
            // Gérer les notes invalides
            cout << "Note invalide, veuillez entrer une note entre 0 et 20." << endl;
            i--; // Refaire la saisie de cette note
        }

    }
}

void printEtudiant(const etudiant& e) {
    cout << "Etudiant : " << e.nom << " " << e.prenom << endl;
    cout << "Notes : ";
    for (int i = 0; i < 3; i++) {
        cout << e.notes[i] << (i < 2 ? ", " : "");
    }
    cout << endl;
    cout << "moyenne : "<<e.moyenne() << endl; // Affiche la moyenne
}

etudiant meilleurEtudiant(const etudiant* classe) {
    etudiant meilleur = classe[0];
    float meilleureMoyenne = 0.0;
    
    for (int i = 0; i < CLASSLENGHT ; i++) {
        float moyenne = classe[i].moyenne();
        if (moyenne > meilleureMoyenne) {
            meilleureMoyenne = moyenne;
            meilleur = classe[i];
        }
    }
    return meilleur;
}

float moyenneClasse(const etudiant* classe) {
    float somme = 0.0;
    for (int i = 0; i < CLASSLENGHT; i++) {
        somme += classe[i].moyenne(); // Utilise la méthode moyenne de la structure
    }
    return somme / CLASSLENGHT;
}


int main() {
    cout << "=== 📋 SYSTÈME DE GESTION D'ETUDIANTS ===" << endl;
    
    // 🎯 TON CODE ICI - Implémente le système complet
    etudiant classe[3]; // Tableau de 3 étudiants
    for (etudiant& e : classe) {
        cout << "Saisie des informations de l'etudiant :" << endl;
        cout << "============================" << endl;
        inputEtudiant(e); // Saisie des informations de chaque étudiant
        cout << "============================" << endl;
    }

    cout << endl << "=== BILAN DES ETUDIANTS ===" << endl;
    for (const etudiant& e : classe) {
        printEtudiant(e); // Affichage des informations de chaque étudiant
    }
    cout << endl << "Moyenne de la classe : " << setprecision(2) << fixed << moyenneClasse(classe) << endl;
    etudiant meilleur = meilleurEtudiant(classe);
    cout << "Meilleur etudiant : " << meilleur.nom << " " << meilleur.prenom << " avec une moyenne de ";
    cout << meilleur.moyenne() << endl;

    return 0;
}

/*
📚 AIDE-MÉMOIRE SYNTAXE :

1. DÉCLARATION STRUCTURE :
   struct Etudiant {
       string nom;
       int age;
       float moyenne;
   };

2. CRÉATION INSTANCE :
   Etudiant etudiant1;
   etudiant1.nom = "Alice";

3. FONCTION AVEC STRUCTURE :
   void afficher(const Etudiant& e) {
       cout << e.nom;
   }

4. TABLEAU DE STRUCTURES :
   Etudiant classe[3];
   classe[0].nom = "Bob";

⭐ Teste avec : Alice/Dupont/20/15/16/14, Bob/Martin/19/12/13/11
*/
