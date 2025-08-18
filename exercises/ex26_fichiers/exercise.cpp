/*
🎯 EXERCICE 26 : FICHIERS - SYSTÈME DE SAUVEGARDE RESTAURANT
============================================================

📚 THÉORIE APPROFONDIE :

Les **fichiers** permettent de sauvegarder et lire des données de façon permanente ! 
Imagine un restaurant qui doit mémoriser ses ventes, ses clients, ses recettes...
Sans fichiers, tout disparaît quand le programme se ferme ! 🧠

En C++, on utilise `fstream` (file stream) - comme cout/cin mais pour les fichiers.
Au lieu d'écrire sur l'écran, on écrit dans un fichier sur le disque ! 🏗️

📋 SYNTAXE FONDAMENTALE :
```cpp
#include <fstream>

// ÉCRITURE
ofstream fichier("data.txt");  // Ouvrir en écriture
fichier << "Bonjour monde!";   // Écrire dedans
fichier.close();               // Fermer

// LECTURE  
ifstream lecture("data.txt");  // Ouvrir en lecture
string ligne;
getline(lecture, ligne);       // Lire une ligne
lecture.close();               // Fermer
```

⚡ DIFFÉRENCES AVEC LES CONCEPTS PRÉCÉDENTS :
- **Variables** : données temporaires en mémoire (RAM)
- **cout/cin** : interaction utilisateur en temps réel
- **Fichiers** : données permanentes sur disque (persiste après arrêt programme)

🎯 AVANTAGES FICHIERS :
- Persistance : données sauvées même après fermeture du programme
- Partage : plusieurs programmes peuvent lire les mêmes données
- Traçabilité : historique des opérations
- Configuration : paramètres sauvés entre sessions

💡 MISSION PRATIQUE : 
Crée un système de sauvegarde pour ton restaurant qui garde la trace !
1. Sauvegarder les ventes quotidiennes dans "ventes.txt"
2. Lire les ventes précédentes au démarrage du programme
3. Ajouter une nouvelle vente et la sauvegarder
4. Calculer et afficher les statistiques (total, moyenne, meilleur jour)
5. Créer un fichier "menu.txt" avec les plats et prix

🔥 BONUS : Créer un système de logs avec horodatage pour tracer toutes
les opérations du restaurant (ouverture, ventes, fermeture) !
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iomanip>

#ifdef _WIN32
    #include <windows.h>
    #include <io.h>
    #include <fcntl.h>
#endif

using namespace std;

// 🎯 Récupère tes enums du restaurant
enum JourSemaine {
    LUNDI, MARDI, MERCREDI, JEUDI, VENDREDI, SAMEDI, DIMANCHE
};

enum TypeMenu {
    VIANDE, POISSON, VEGETARIEN, PIZZA
};

struct recapJour {
    JourSemaine jour;
    int vente; // Montant des ventes pour ce jour
    int nombreDeTicket; // Nombre de tickets vendus
    float venteMoyenne() const {
        return static_cast<float>(vente) / nombreDeTicket; // Calcul de la vente moyenne
    };
};

// 🎯 TON CODE ICI - Fonction pour obtenir le nom du jour
string nomJour(JourSemaine jour) {
    // Implémente cette fonction !
    switch (jour) {
        case LUNDI: return "Lundi";
        case MARDI: return "Mardi";
        case MERCREDI: return "Mercredi";
        case JEUDI: return "Jeudi";
        case VENDREDI: return "Vendredi";
        case SAMEDI: return "Samedi";
        case DIMANCHE: return "Dimanche";
    }
    return "Inconnu";
}

// 🎯 TON CODE ICI - Fonction pour sauvegarder les ventes
void sauvegarderVentes(const vector<int>& ventes, const vector<string>& jours) {
    // Ouvre le fichier "ventes.txt" en écriture
    // Écrit chaque jour et sa vente
    ofstream fichier("ventes.txt");
    if (!fichier.is_open()) {
        cout << "Erreur lors de l'ouverture du fichier ventes.txt" << endl;
        return;
    }
    for(size_t i = 0; i < ventes.size(); i++) {
        fichier << jours[i] << ": " << ventes[i] << "€" << endl;
    }
    fichier.close(); // Ferme le fichier
    
}

// 🎯 TON CODE ICI - Fonction pour charger les ventes
vector<int> chargerVentes(vector<string>& jours) {
    vector<int> ventes;
    
    // Ouvre le fichier "ventes.txt" en lecture
    // Lit chaque ligne et récupère jour + vente
    // Retourne le vector des ventes
    ifstream fichier("ventes.txt");
    if (fichier.is_open()) {
        string ligne;
        while (getline(fichier, ligne)) {
            size_t pos = ligne.find(": ");
            if (pos != string::npos) {
                jours.push_back(ligne.substr(0, pos)); // Récupère le jour
                int vente = stoi(ligne.substr(pos + 2)); // Récupère la vente
                ventes.push_back(vente);
            }
        }
        fichier.close(); // Ferme le fichier
    } else {
        cout << "Erreur lors de l'ouverture du fichier ventes.txt" << endl;
    }
    fichier.close();
    
    return ventes;
}

// 🎯 TON CODE ICI - Fonction pour créer le fichier menu
void creerFichierMenu() {
    // Crée "menu.txt" avec tous les plats et prix
    ofstream fichier("menu.txt");
    if (fichier.is_open()) {
        fichier << "Menu Viande - 15€" << endl;
        fichier << "Menu Poisson - 18€" << endl;
        fichier << "Menu Vegetarien - 12€" << endl;
        fichier << "Menu Pizza - 10€" << endl;
        fichier.close(); // Ferme le fichier
    } else {
        cout << "Erreur lors de la création du fichier menu.txt" << endl;
    }
    fichier.close();
}

// 🎯 TON CODE ICI - Fonction pour afficher les statistiques
void afficherStatistiques(const vector<int>& ventes, const vector<string>& jours) {
    // Calcule et affiche :
    // - Total des ventes
    // - Moyenne par jour  
    // - Meilleur jour
    // - Pire jour
    int total = 0;
    JourSemaine meilleurJour = LUNDI;
    JourSemaine pireJour = LUNDI;
    vector<recapJour> recap;

    ifstream fichier("ventes.txt");
    if (fichier.is_open()) {
        string ligne;
        while (getline(fichier, ligne)) {
                size_t pos = ligne.find(": ");
                if (pos != string::npos) {
                    string jourStr = ligne.substr(0, pos);
                    int vente = stoi(ligne.substr(pos + 2));
                    
                    // Trouver le jour correspondant
                    JourSemaine jour = LUNDI;
                    for (int i = 0; i < 7; i++) {
                        if (jourStr == nomJour(static_cast<JourSemaine>(i))) {
                            jour = static_cast<JourSemaine>(i);
                            break;
                        }
                    }
                    
                    recap.push_back({jour, vente, 1}); // 1 ticket pour simplifier
                    total += vente;
                }
            }
        fichier.close(); // Ferme le fichier
    } else {
        cout << "Erreur lors de l'ouverture du fichier ventes.txt" << endl;
    }
}

int main() {
    // Pour Windows : active l'UTF-8 pour la console (accents, emoji)
    #ifdef _WIN32
        SetConsoleOutputCP(CP_UTF8);
        SetConsoleCP(CP_UTF8);
    #endif

    cout << "=== 📁 SYSTEME DE FICHIERS RESTAURANT ===" << endl << endl;

    vector<string> jours;
    
    // 🎯 TON CODE ICI - Charger les ventes existantes
    cout << "📖 Chargement des ventes précédentes..." << endl;
    vector<int> ventes = chargerVentes(jours);
    
    if (ventes.empty()) {
        cout << "Aucune donnée trouvée, initialisation..." << endl;
        // Données par défaut pour commencer
        jours = {"Lundi", "Mardi", "Mercredi", "Jeudi", "Vendredi", "Samedi", "Dimanche"};
        ventes = {250, 300, 180, 220, 450, 520, 380};
    }
    
    // 🎯 TON CODE ICI - Afficher les ventes actuelles
    
    
    // 🎯 TON CODE ICI - Demander une nouvelle vente
    cout << "\n💰 Ajouter une vente pour aujourd'hui ?" << endl;
    cout << "Entrez le montant (0 pour ignorer) : ";
    int nouvelleVente;
    cin >> nouvelleVente;
    
    if (nouvelleVente > 0) {
        // Ajouter la nouvelle vente
        jours.push_back("Aujourd'hui");
        ventes.push_back(nouvelleVente);
        cout << "✅ Vente ajoutée : " << nouvelleVente << "€" << endl;
    }
    
    // 🎯 TON CODE ICI - Sauvegarder les données
    cout << "\n💾 Sauvegarde des données..." << endl;
    sauvegarderVentes(ventes, jours);
    
    // 🎯 TON CODE ICI - Créer fichier menu
    cout << "📋 Création du fichier menu..." << endl;
    creerFichierMenu();
    
    // 🎯 TON CODE ICI - Afficher statistiques finales
    cout << "\n📊 STATISTIQUES FINALES :" << endl;
    afficherStatistiques(ventes, jours);
    
    cout << "\n✅ Toutes les données sont sauvegardées !" << endl;
    cout << "📁 Fichiers créés : ventes.txt, menu.txt" << endl;
    
    return 0;
}
