// 🎯 EXERCICE 04 : CONDITIONS SIMPLES (IF/ELSE)
// Niveau : 🌱 ÉCHAUFFEMENT
// XP à gagner : 150 XP
// Badge potentiel : 🎯 Expert Conditions

/*
🎯 OBJECTIF :
Apprendre les structures conditionnelles en C++.
Créer un programme qui classifie les utilisateurs par tranche d'âge.

📋 CONSIGNES :
1. Demander l'âge de l'utilisateur
2. Afficher un message selon l'âge :
   - Moins de 13 ans : "Tu es un enfant"
   - Entre 13 et 17 ans : "Tu es un adolescent"
   - Entre 18 et 64 ans : "Tu es un adulte"  
   - 65 ans et plus : "Tu es un senior"

💡 EXEMPLE DE SORTIE :
Entrez votre âge : 25
Tu es un adulte !

✅ CRITÈRES DE VALIDATION :
- Utilise if, else if, else
- Gère toutes les tranches d'âge
- Affichage personnalisé pour chaque cas

🏆 BONUS :
- Valide que l'âge est positif et réaliste (0-120)
- Ajoute des messages personnalisés amusants
*/

#include <iostream>
using namespace std;

int main() {
    // 🔽 TON CODE ICI 🔽
    cout << "Entrez votre âge : ";
    int age;
    cin >> age;  // Saisie de l'âge de l'utilisateur

    if (age < 13 && age >= 0) {
        cout << "Tu es un enfant !" << endl;  // Moins de 13 ans
    } else if (age >= 13 && age <= 17) {
        cout << "Tu es un adolescent !" << endl;  // Entre 13 et 17 ans
    } else if (age >= 18 && age < 65) {
        cout << "Tu es un adulte !" << endl;  // Entre 18 et 64 ans
    } else if (age >= 65 && age <= 120) {
        cout << "Tu es un senior !" << endl;  // 65 ans et plus
    } else {
        cout << "Âge invalide. Veuillez entrer un âge réaliste." << endl;  // Âge non valide
    }
    
    // 🔼 TON CODE AU-DESSUS 🔼
    return 0;
}
