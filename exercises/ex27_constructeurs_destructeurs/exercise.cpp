/*
🎯 EXERCICE 27 : CONSTRUCTEURS ET DESTRUCTEURS - GESTION CYCLE DE VIE
===================================================================

📚 THÉORIE APPROFONDIE :

Les **CONSTRUCTEURS** et **DESTRUCTEURS** gèrent le CYCLE DE VIE des objets ! 🔄
C'est comme l'ouverture/fermeture d'un restaurant : actions automatiques au début/fin.

🏗️ **CONSTRUCTEURS** : Appelés automatiquement à la CRÉATION d'un objet
- Initialisation des attributs
- Allocation de ressources (mémoire, fichiers...)
- Configuration de l'état initial

💥 **DESTRUCTEURS** : Appelés automatiquement à la DESTRUCTION d'un objet
- Libération de la mémoire
- Fermeture de fichiers/connexions
- Nettoyage des ressources

📋 TYPES DE CONSTRUCTEURS :
```cpp
class Restaurant {
private:
    string nom;
    int capacite;
    double* revenus; // Pointeur pour allocation dynamique
    
public:
    // 1️⃣ CONSTRUCTEUR PAR DÉFAUT (sans paramètres)
    Restaurant();
    
    // 2️⃣ CONSTRUCTEUR AVEC PARAMÈTRES
    Restaurant(string n, int cap);
    
    // 3️⃣ CONSTRUCTEUR DE COPIE
    Restaurant(const Restaurant& autre);
    
    // 4️⃣ DESTRUCTEUR (un seul par classe)
    ~Restaurant();
};
```

⚡ SYNTAXES AVANCÉES :
```cpp
// LISTE D'INITIALISATION (plus efficace !)
Restaurant::Restaurant(string n, int cap) : nom(n), capacite(cap) {
    revenus = new double[30]; // Allocation dynamique
    cout << "🏗️ Restaurant '" << nom << "' créé !" << endl;
}

// DESTRUCTEUR avec nettoyage
Restaurant::~Restaurant() {
    delete[] revenus; // Libération mémoire !
    cout << "💥 Restaurant '" << nom << "' fermé !" << endl;
}
```

🎯 **RÈGLE D'OR - RAII** (Resource Acquisition Is Initialization) :
- Si tu alloues → tu libères
- Si tu ouvres → tu fermes
- Constructeur acquiert → Destructeur libère

💡 MISSION PRATIQUE : 
Crée un système de **Bibliothèque** avec gestion automatique des ressources !

1. Classe `Livre` avec constructeurs multiples
2. Classe `Bibliotheque` avec allocation dynamique
3. Constructeur de copie pour duplication sécurisée
4. Destructeur avec libération automatique de mémoire
5. Tester l'ordre d'appel constructeurs/destructeurs

🔥 BONUS AVANCÉ : 
- Compteur statique de livres créés/détruits
- Gestion d'erreurs en cas d'allocation échouée
- Constructeur de déplacement (move constructor)
*/

#include <iostream>
#include <string>
#include <memory>

using namespace std;

// 📖 CLASSE LIVRE - Concepts de base constructeurs/destructeurs
class Livre {
private:
    string titre;
    string auteur;
    int annee;
    static int nombreLivres; // Compteur statique
    
public:
    // 🎯 TON CODE ICI - Déclarer tous les constructeurs
    
    // 1️⃣ Constructeur par défaut
    
    
    // 2️⃣ Constructeur avec paramètres
    
    
    // 3️⃣ Constructeur de copie
    
    
    // 4️⃣ Destructeur
    
    
    // 📋 Méthodes utilitaires
    void afficher() const;
    static int getNombreLivres() { return nombreLivres; }
    
    // Getters
    string getTitre() const { return titre; }
    string getAuteur() const { return auteur; }
    int getAnnee() const { return annee; }
};

// 🏛️ CLASSE BIBLIOTHEQUE - Gestion dynamique avancée
class Bibliotheque {
private:
    string nom;
    Livre* livres;    // Tableau dynamique de livres
    int capacite;
    int nbLivres;
    
public:
    // 🎯 TON CODE ICI - Constructeurs avec allocation dynamique
    
    // Constructeur avec paramètres
    
    
    // Constructeur de copie (ESSENTIEL pour allocation dynamique !)
    
    
    // Destructeur avec libération mémoire
    
    
    // 📚 Méthodes de gestion
    void ajouterLivre(const Livre& livre);
    void afficherCatalogue() const;
    int getNombreLivres() const { return nbLivres; }
};

// 🎯 TON CODE ICI - Implémentations des constructeurs/destructeurs

// Initialisation du compteur statique
int Livre::nombreLivres = 0;

// === IMPLÉMENTATIONS CLASSE LIVRE ===

// Constructeur par défaut
Livre::Livre() {
    // 🎯 TON CODE ICI
    
}

// Constructeur avec paramètres + liste d'initialisation
Livre::Livre(/* paramètres */) {
    // 🎯 TON CODE ICI
    
}

// Constructeur de copie
Livre::Livre(/* paramètre copie */) {
    // 🎯 TON CODE ICI
    
}

// Destructeur
Livre::~Livre() {
    // 🎯 TON CODE ICI
    
}

void Livre::afficher() const {
    cout << "📖 \"" << titre << "\" par " << auteur << " (" << annee << ")" << endl;
}

// === IMPLÉMENTATIONS CLASSE BIBLIOTHEQUE ===

// Constructeur avec allocation dynamique
Bibliotheque::Bibliotheque(/* paramètres */) {
    // 🎯 TON CODE ICI - Utiliser new[] pour allocation
    
}

// Constructeur de copie (copie profonde !)
Bibliotheque::Bibliotheque(/* paramètre copie */) {
    // 🎯 TON CODE ICI - Copie profonde du tableau
    
}

// Destructeur avec libération
Bibliotheque::~Bibliotheque() {
    // 🎯 TON CODE ICI - Utiliser delete[]
    
}

void Bibliotheque::ajouterLivre(const Livre& livre) {
    if (nbLivres < capacite) {
        livres[nbLivres] = livre; // Appelle automatiquement le constructeur de copie !
        nbLivres++;
        cout << "✅ Livre ajouté à la bibliothèque !" << endl;
    } else {
        cout << "❌ Bibliothèque pleine !" << endl;
    }
}

void Bibliotheque::afficherCatalogue() const {
    cout << "\n📚 === CATALOGUE BIBLIOTHÈQUE \"" << nom << "\" ===" << endl;
    cout << "Livres disponibles : " << nbLivres << "/" << capacite << endl;
    for (int i = 0; i < nbLivres; i++) {
        cout << "  " << (i+1) << ". ";
        livres[i].afficher();
    }
    cout << "=====================================\n" << endl;
}

int main() {
    cout << "=== 🏛️ BIBLIOTHÈQUE - CONSTRUCTEURS/DESTRUCTEURS ===" << endl << endl;
    
    // 🎯 PHASE 1 : Test constructeurs de Livre
    cout << "📚 PHASE 1 : Création de livres" << endl;
    
    {
        // 🎯 TON CODE ICI - Créer des livres avec différents constructeurs
        cout << "Livres actifs : " << Livre::getNombreLivres() << endl;
        
        // Constructeur par défaut
        
        // Constructeur avec paramètres
        
        // Constructeur de copie
        
        cout << "Livres créés : " << Livre::getNombreLivres() << endl;
        
    } // 💥 Sortie de scope → destructeurs appelés automatiquement !
    
    cout << "Livres après destruction : " << Livre::getNombreLivres() << endl << endl;
    
    // 🎯 PHASE 2 : Test Bibliothèque avec allocation dynamique
    cout << "🏛️ PHASE 2 : Gestion bibliothèque" << endl;
    
    {
        // 🎯 TON CODE ICI - Créer bibliothèque et ajouter livres
        
        // Créer bibliothèque
        
        // Créer et ajouter des livres
        
        // Afficher catalogue
        
        // Test constructeur de copie de bibliothèque
        
    } // 💥 Destructeurs automatiques avec libération mémoire !
    
    // 🔥 PHASE 3 : BONUS - Test avancé allocation/libération
    cout << "\n🚀 PHASE 3 : Tests avancés" << endl;
    
    // 🎯 TON CODE ICI - Tests supplémentaires
    
    cout << "\n✅ Tous les tests terminés ! Ressources libérées automatiquement !" << endl;
    cout << "Compteur final de livres : " << Livre::getNombreLivres() << endl;
    
    return 0;
}

/*
🎯 OBJECTIFS D'APPRENTISSAGE :
✅ 1. Maîtriser les différents types de constructeurs
✅ 2. Comprendre l'importance des destructeurs pour la gestion mémoire
✅ 3. Implémenter la copie profonde pour les ressources dynamiques
✅ 4. Observer l'ordre d'appel constructeurs/destructeurs
✅ 5. Appliquer le principe RAII (Resource Acquisition Is Initialization)

🔥 BONUS À EXPLORER :
- Constructeurs délégués (C++11)
- Move constructors et move semantics
- Smart pointers pour gestion automatique
- Exception safety dans les constructeurs
*/
