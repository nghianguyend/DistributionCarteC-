// Correction pour l'exercice de bridge
#include <iostream>
#include <vector>
#include <array>
#include <string>
using namespace std;

/** Infrastructure minimale de test **/
#define CHECK(test) if (!(test)) cout << "Test failed in file " << __FILE__ \
                                       << " line " << __LINE__ << ": " #test << endl

                                       
const array<string, 4> couleurs_unicode = { {u8"♠", u8"♥", u8"♦", u8"♣" } };
const array<array<string, 14>, 4> cartes_unicode = { {
    {u8"🂢", u8"🂣", u8"🂤", u8"🂥", u8"🂦", u8"🂧", u8"🂨", u8"🂩",
     u8"🂪", u8"🂫", u8"🂭", u8"🂮", u8"🂡"},
    {u8"🂲", u8"🂳", u8"🂴", u8"🂵", u8"🂶", u8"🂷", u8"🂸", u8"🂹",
     u8"🂺", u8"🂻", u8"🂽", u8"🂾", u8"🂱"},
    {u8"🃂", u8"🃃", u8"🃄", u8"🃅", u8"🃆", u8"🃇", u8"🃈", u8"🃉",
     u8"🃊", u8"🃋", u8"🃍", u8"🃎", u8"🃁"},
    {u8"🃒", u8"🃓", u8"🃔", u8"🃕", u8"🃖", u8"🃗", u8"🃘", u8"🃙",
     u8"🃚", u8"🃛", u8"🃝", u8"🃞", u8"🃑"},   
     } };


enum class CouleurCarte {pique, coeur, carreau, trefle};

enum class ValeurCarte {
  v2, v3, v4, v5, v6, v7, v8, v9, v10, Valet, Dame, Roi, As};

struct Carte {
  CouleurCarte couleur;
  ValeurCarte valeur;
};

using MainJ = array<Carte, 13>;

MainJ exemple1 = {{
    {CouleurCarte::pique, ValeurCarte::As},
    {CouleurCarte::pique, ValeurCarte::Roi},
    {CouleurCarte::pique, ValeurCarte::v10},
    {CouleurCarte::pique, ValeurCarte::v2},
    {CouleurCarte::coeur, ValeurCarte::As},
    {CouleurCarte::coeur, ValeurCarte::Dame},
    {CouleurCarte::coeur, ValeurCarte::v10},
    {CouleurCarte::coeur, ValeurCarte::v9},
    {CouleurCarte::coeur, ValeurCarte::v8},
    {CouleurCarte::coeur, ValeurCarte::v7},
    {CouleurCarte::coeur, ValeurCarte::v4},
    {CouleurCarte::trefle, ValeurCarte::Valet},
    {CouleurCarte::trefle, ValeurCarte::v6}
  }};

MainJ exemple2 = {{
    {CouleurCarte::pique, ValeurCarte::v2},
    {CouleurCarte::coeur, ValeurCarte::As},
    {CouleurCarte::coeur, ValeurCarte::v9},
    {CouleurCarte::trefle, ValeurCarte::As},
    {CouleurCarte::trefle, ValeurCarte::Roi},
    {CouleurCarte::trefle, ValeurCarte::Dame},
    {CouleurCarte::trefle, ValeurCarte::Valet},
    {CouleurCarte::trefle, ValeurCarte::v10},
    {CouleurCarte::carreau, ValeurCarte::As},
    {CouleurCarte::carreau, ValeurCarte::v10},
    {CouleurCarte::carreau, ValeurCarte::v9},
    {CouleurCarte::carreau, ValeurCarte::v7},
    {CouleurCarte::carreau, ValeurCarte::v6}
  }};

array<int, 13> ptHCarte {{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 2, 3, 4 }};

// la fonction qui remplace le tableau, avec vc de type valeurCarte
int pointHCarte(ValeurCarte vc){
  return ptHCarte[static_cast<int>(vc)];
}

void test_pointHCarte() {
  CHECK(pointHCarte(ValeurCarte::As) == 4);
  CHECK(pointHCarte(ValeurCarte::Roi) == 3);
  CHECK(pointHCarte(ValeurCarte::Dame) == 2);
  CHECK(pointHCarte(ValeurCarte::Valet) == 1);
  CHECK(pointHCarte(ValeurCarte::v10) == 0);
}

int nbreCarteCouleur(MainJ m, CouleurCarte c) {
  int sum = 0;
  for(int i = 0; i < m.size(); i++){
    if(c == m[i].couleur) sum++;
  }
  return sum;
}

void test_nbreCarteCouleur() {
  CHECK(nbreCarteCouleur(exemple1, CouleurCarte::pique) == 4);
  CHECK(nbreCarteCouleur(exemple1, CouleurCarte::coeur) == 7);
  CHECK(nbreCarteCouleur(exemple2, CouleurCarte::trefle) == 5);
}

int evaluePtD(MainJ m) {
  int ptd = 0;
  array<int, 4>tab_cartes = {0, 0, 0, 0};

  for(const auto&cartes : m){
    tab_cartes[static_cast<int>(cartes.couleur)] ++;
  }

  for(const auto&couleur : tab_cartes){
    if(couleur == 0) ptd += 3;
    if(couleur == 1) ptd += 2;
    if(couleur == 2) ptd += 1;
  }
  return ptd;
}

void test_evaluePtD() {
  CHECK(evaluePtD(exemple1) == 4);
  CHECK(evaluePtD(exemple2) == 3);
}

int evaluePtH(MainJ m) {
  int pth = 0;
  for(const auto& cartes : m){
    if(cartes.valeur == ValeurCarte::As) pth += 4;
    if(cartes.valeur == ValeurCarte::Roi) pth += 3;
    if(cartes.valeur == ValeurCarte::Dame) pth += 2;
    if(cartes.valeur == ValeurCarte::Valet) pth += 1;
  }
  return pth;
}

void test_evaluePtH() {
  CHECK(evaluePtH(exemple1) == 14);
  CHECK(evaluePtH(exemple2) == 18);
}

// Fonction pour convertir une chaine en couleur de carte
CouleurCarte stringToCouleurCarte(const string& CouleurStr){
  if(CouleurStr == "pique") return CouleurCarte::pique;
  if(CouleurStr == "trefle") return CouleurCarte::trefle;
  if(CouleurStr == "coeur") return CouleurCarte::coeur;
  if(CouleurStr == "carreau") return CouleurCarte::carreau;
  throw invalid_argument("Couleur invalide");
}

// Fonction pour convertir une chaîne en ValeurCarte
ValeurCarte stringToValeurCarte(const string& ValeurStr){
  if (ValeurStr == "2") return ValeurCarte::v2;
  if (ValeurStr == "3") return ValeurCarte::v3;
  if (ValeurStr == "4") return ValeurCarte::v4;
  if (ValeurStr == "5") return ValeurCarte::v5;
  if (ValeurStr == "6") return ValeurCarte::v6;
  if (ValeurStr == "7") return ValeurCarte::v7;
  if (ValeurStr == "8") return ValeurCarte::v8;
  if (ValeurStr == "9") return ValeurCarte::v9;
  if (ValeurStr == "10") return ValeurCarte::v10;
  if (ValeurStr == "Valet") return ValeurCarte::Valet;
  if (ValeurStr == "Dame") return ValeurCarte::Dame;
  if (ValeurStr == "Roi") return ValeurCarte::Roi;
  if (ValeurStr == "As") return ValeurCarte::As;
  throw invalid_argument("Valeur invalide");
}

Carte SaisirCarte(){
  string couleurStr, valeurStr;
  cout << "Entrez la couleur de la carte (pique, coeur, carreau, trefle): ";
  cin >> couleurStr;
  cout << "Entrez la valeur de la carte (2, 3, 4, 5, 6, 7, 8, 9, 10, Valet, Dame, Roi, As): ";
  cin >> valeurStr;

  CouleurCarte couleur;
  ValeurCarte valeur;

  try{
    couleur = stringToCouleurCarte(couleurStr);
    valeur = stringToValeurCarte(valeurStr);
  } catch(const invalid_argument& e){
    cerr << e.what() << endl;
    return SaisirCarte();
  }
  return{couleur, valeur};
}

MainJ SaisirMain() {
  MainJ main_carte;

  for (int i = 0; i < 13; i++) {
    main_carte[i] = SaisirCarte();

    // Vérification des doublons
    for (int j = 0; j < i; j++) { // Vérifier toutes les cartes précédentes
      if (main_carte[j].couleur == main_carte[i].couleur &&
          main_carte[j].valeur == main_carte[i].valeur) {
        cerr << "Erreur : Cette carte est déjà dans la main. Veuillez entrer une autre carte." << endl;
        i--; // Redemander une carte pour cette position
        break;
      }
    }
  }

  return main_carte;
}

string valeurCartetoString(ValeurCarte vc){
  switch(vc){
    case ValeurCarte::v2: return "2";
    case ValeurCarte::v3: return "3";
    case ValeurCarte::v4: return "4";
    case ValeurCarte::v5: return "5";
    case ValeurCarte::v6: return "6";
    case ValeurCarte::v7: return "7";
    case ValeurCarte::v8: return "8";
    case ValeurCarte::v9: return "9";
    case ValeurCarte::v10: return "10";
    case ValeurCarte::Valet: return "V";
    case ValeurCarte::Dame: return "D";
    case ValeurCarte::Roi: return "R";
    case ValeurCarte::As: return "A";
    default : return "";
  }
}

string couleurCartetoString(CouleurCarte vc){
  switch(vc){
    case CouleurCarte::carreau : return "K";
    case CouleurCarte::coeur : return "C";
    case CouleurCarte::pique : return "P";
    case CouleurCarte::trefle : return "T";
    default : return "";
  }
}

void MainAffiche(const MainJ& main, bool useUnicode = false){
  for(const auto& carte : main){
    if(useUnicode){
      int couleurIndex = static_cast<int>(carte.couleur);
      int valeurIndex = static_cast<int>(carte.valeur);
      cout << cartes_unicode[couleurIndex][valeurIndex] << ", ";
    }else{
      cout << valeurCartetoString(carte.valeur) << ", " << couleurCartetoString(carte.couleur) << " ";
    } 
  }
  cout << endl;
}



int main() {
  // Tests
  test_nbreCarteCouleur();
  test_evaluePtD();
  test_evaluePtH();
  test_pointHCarte();

  // Affichage
  // MainJ test = SaisirMain();
  MainJ main_test = SaisirMain();
  cout << "Votre main est : " << endl;
  MainAffiche(main_test, true);

  return 0;
}
