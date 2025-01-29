#include <iostream>
#include <vector>
#include <string>
#include <exception>
#include <ctype.h>  // tolower
using namespace std;

/** Infrastructure minimale de test **/
#define CHECK(test) if (!(test)) cout << "Test failed in file " << __FILE__ \
                                       << " line " << __LINE__ << ": " #test << endl

enum class Tril { faux, inc, vrai };

Tril saisie() {
  char c;
  bool ok = false;
  Tril res;
  do {
    cout << "Donner un tril (v/f/i) : ";
    cin >> c;
    switch (c) {
      case 'v' : case 'V' : res = Tril::vrai; ok = true; break;
      case 'f' : case 'F' : res = Tril::faux; ok = true; break;
      case 'i' : case 'I' : res = Tril::inc; ok = true; break;
      default : cout << "erreur !" << endl;
    }
  } while (not ok);
  return res;
}

void affiche(Tril t) {
  string res;
  switch (t){
    case Tril::vrai : res = "vrai"; break;
    case Tril::faux : res = "faux"; break;
    case Tril::inc : res = "inc"; break;
  }
  cout << res << endl;
}

Tril from_bool(bool b) {
  return b ? Tril::vrai : Tril::faux;
}

bool to_bool(Tril t) {
  if(t == Tril::inc) throw logic_error("Impossible de convertir inc en bool");
  return t == Tril::vrai;
}


Tril non(Tril t) {
  if(t == Tril::inc) return t;
  return from_bool(not to_bool(t));
}

void test_non() {
  CHECK(non(Tril::vrai) == Tril::faux);
  CHECK(non(Tril::faux) == Tril::vrai);
}

Tril et(Tril a, Tril b) {
  if(a == Tril::faux || b == Tril::faux) {
    if(a == Tril::inc || b == Tril::inc) return Tril::inc;
    return Tril::faux;
  }
  if(a == Tril::inc || b == Tril::inc) return Tril::inc;
  else return Tril::vrai;
}

Tril ou(Tril a, Tril b){
  if((a == Tril::faux || b == Tril::vrai) || (a == Tril::vrai || b == Tril::faux)) return Tril::vrai;
  if((a == Tril::faux || b == Tril::faux) || (a == Tril::faux || b == Tril::inc) || (a == Tril::inc || b == Tril::faux)) return Tril::faux;
  else return Tril::vrai;
}

int main() {
  // Tests

  // Affichage
  Tril res = saisie();
  affiche(res);

  Tril t = from_bool(true);
  affiche(t);

  bool a = to_bool(Tril::vrai);
  cout << a << endl;

  affiche(non(Tril::vrai));

  affiche(et(Tril::inc, Tril::faux));

  affiche(et(Tril::vrai, Tril::faux));

  affiche(et(Tril::inc, Tril::inc));

  affiche(et(Tril::vrai, Tril::inc));

  affiche(ou(Tril::vrai, Tril::faux));

  return 0;
}
