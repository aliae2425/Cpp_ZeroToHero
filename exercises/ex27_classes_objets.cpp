/*
🎯 EXERCICE 27 : CLASSES ET OBJETS - SYSTÈME POO RESTAURANT
===========================================================

📚 THÉORIE APPROFONDIE :

Les **classes** sont des "moules" pour créer des objets ! Imagine un restaurant :
au lieu d'avoir des variables éparses (nom, prix, stock), tu crées une classe "Plat"
qui rassemble toutes ces données ET les fonctions qui les manipulent ! 🧠

Une **classe** = données (attributs) + fonctions (méthodes) dans un seul endroit.
Un **objet** = instance concrète d'une classe (comme "Pizza Margherita" issue de la classe "Plat"). 🏗️

📋 SYNTAXE FONDAMENTALE :
```cpp
class NomClasse {
private:                    // Données privées (encapsulation)
    type attribut1;
    type attribut2;
    
public:                     // Interface publique
    NomClasse();            // Constructeur
    void methode1();        // Méthodes
    type getAttribut1();    // Accesseur (getter)
    void setAttribut1(type val); // Mutateur (setter)
};
```

⚡ DIFFÉRENCES AVEC LES CONCEPTS PRÉCÉDENTS :
- **Structures** : données groupées, méthodes optionnelles
- **Fonctions** : traitent des données externes
- **Classes** : données ET méthodes encapsulées, interface contrôlée

🎯 AVANTAGES CLASSES :
- Encapsulation : données protégées, interface claire
- Réutilisabilité : même "moule" pour créer plein d'objets
- Maintenance : modification en un seul endroit
- Modélisation réaliste : objets du monde réel

💡 MISSION PRATIQUE : 
Transforme ton restaurant en système POO avec une classe Plat complète !
1. Créer une classe "Plat" avec attributs privés (nom, prix, disponible)
2. Implémenter constructeur pour initialiser un plat
3. Créer méthodes publiques (afficher, changerPrix, toggleDisponibilite)
4. Ajouter getters/setters pour accéder aux attributs en sécurité
5. Créer plusieurs objets Plat et tester toutes les méthodes

🔥 BONUS : Ajouter une méthode statique pour compter le nombre total
de plats créés et une méthode pour calculer un prix TTC avec TVA !
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

// 🎯 TON CODE ICI - Définir la classe Plat
class Plat {
private:
    // Attributs privés (encapsulation)
    string nom;          // Nom du plat
    double prix;        // Prix du plat
    bool disponible;    // Disponibilité du plat (true/false)
    static int nombrePlats; // Compteur de plats créés (statique)
    
    
public:
    // Constructeur
    // Plat(string nom, double prix);
    Plat(string nom, double prix) : nom(nom), prix(prix), disponible(true) {
        // Initialiser les attributs
        nombrePlats++; // Incrémenter le compteur
    }   
    
    
    // Méthodes publiques
    // void afficher() const;
    void afficher() const {
        cout << "Plat : " << nom << ", Prix : " << prix << "€, Disponible : " 
             << (disponible ? "Oui" : "Non") << endl;
    }
    // void changerPrix(double nouveauPrix);
    void changerPrix(double nouveauPrix) {
        prix = nouveauPrix; // Met à jour le prix du plat
    }
    // void toggleDisponibilite();
    void toggleDisponibilite() {
        disponible = !disponible; // Inverse la disponibilité
    }
    
    
    // Getters (accesseurs)
    // string getNom() const;
    string getNom() const {
        return nom; // Retourne le nom du plat
    }
    // double getPrix() const;
    double getPrix() const {
        return prix; // Retourne le prix du plat
    }
    // bool estDisponible() const;
    bool estDisponible() const {
        return disponible; // Retourne la disponibilité du plat
    }
    // 🔥 BONUS - Méthodes avancées
    static int getNombrePlats() {
        return nombrePlats; // Retourne le nombre total de plats créés
    }

    
    
    // Setters (mutateurs) 
    // void setNom(const string& nouveauNom);
    void setNom(const string& nouveauNom) {
        nom = nouveauNom; // Met à jour le nom du plat
    }
    // void setPrix(double nouveauPrix);
    void setPrix(double nouveauPrix) {
        prix = nouveauPrix; // Met à jour le prix du plat
    }
    // void setDisponibilite(bool dispo);
    void setDisponibilite(bool dispo) {
        disponible = dispo; // Met à jour la disponibilité du plat
    }
    
    static void ajouterPlats(int nombre) {
        nombrePlats += nombre;
    }
    
    // 🔥 BONUS - Méthodes avancées
    // static int getNombrePlats();
    // double prixTTC(double tauxTVA = 0.20) const;
    double prixTTC(double tauxTVA = 0.20) const {
        return prix * (1 + tauxTVA); // Calcule le prix TTC avec TVA
    }

    double bilanPlatTTC(double tauxTVA = 0.20) const {
        return nombrePlats * prixTTC(tauxTVA); // Calcule le bilan TTC du plat
    }


};

// 🎯 TON CODE ICI - Implémentation des méthodes (en dehors de la classe)

// Constructeur
// Plat::Plat(string nom, double prix) {
//     // Initialiser les attributs
// }

// Exemple méthode
// void Plat::afficher() const {
//     // Afficher les infos du plat
// }

// ... autres implémentations


int Plat::nombrePlats = 0; // Initialisation du compteur de plats

int main() {
    cout << "=== 🍽️ RESTAURANT POO - SYSTÈME CLASSES ===" << endl << endl;
    
    // 🎯 TON CODE ICI - Créer plusieurs objets Plat
    cout << "📋 Création du menu avec des objets Plat :" << endl;
    
    Plat plat1("Pizza Margherita", 12.50);
    Plat plat2("Salade César", 9.80);
    Plat plat3("Burger Bacon", 15.00);
    
    // 🎯 TON CODE ICI - Tester les méthodes
    cout << "\n🍕 Test des méthodes sur les plats :" << endl;
    
    plat1.afficher();
    plat1.changerPrix(13.00);
    plat1.afficher();

    
    
    // 🎯 TON CODE ICI - Tester getters/setters
    cout << "\n🔧 Test des getters/setters :" << endl;
    
    cout << "Nom du plat 2 : " << plat2.getNom() << endl;
    plat2.setDisponibilite(false);
    cout << "Plat 2 disponible ? " << plat2.estDisponible() << endl;
    
    
    // 🎯 TON CODE ICI - Gérer la disponibilité
    cout << "\n🔄 Test toggle disponibilité :" << endl;
    
    plat3.toggleDisponibilite();
    plat3.afficher();
    
    
    // 🔥 BONUS - Tester méthodes avancées
    cout << "\n🚀 BONUS - Fonctionnalités avancées :" << endl;
    
    cout << "Nombre total de plats : " << Plat::getNombrePlats() << endl;
    cout << "Prix TTC Pizza : " << plat1.prixTTC() << "€" << endl;
    
    
    cout << "\n✅ Tests POO terminés ! Objets créés et manipulés avec succès !" << endl;
    
    return 0;
}
