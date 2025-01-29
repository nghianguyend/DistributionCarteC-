#include <cstdlib>
#include <iostream>
#include <string>
#include <array>
using namespace std;

// CF: http://xahlee.info/comp/unicode_index.html

const array<string, 4> couleurs = { {u8"♣", u8"♦", u8"♥", u8"♠"} };
const array<array<string, 14>, 4> cartes = { {
    {u8"🃒", u8"🃓", u8"🃔", u8"🃕", u8"🃖", u8"🃗", u8"🃘", u8"🃙",
     u8"🃚", u8"🃛", u8"🃜", u8"🃝", u8"🃞", u8"🃑"},
    {u8"🃂", u8"🃃", u8"🃄", u8"🃅", u8"🃆", u8"🃇", u8"🃈", u8"🃉",
     u8"🃊", u8"🃋", u8"🃌", u8"🃍", u8"🃎", u8"🃁"},
    {u8"🂲", u8"🂳", u8"🂴", u8"🂵", u8"🂶", u8"🂷", u8"🂸", u8"🂹",
     u8"🂺", u8"🂻", u8"🂼", u8"🂽", u8"🂾", u8"🂱"},
    {u8"🂢", u8"🂣", u8"🂤", u8"🂥", u8"🂦", u8"🂧", u8"🂨", u8"🂩",
     u8"🂪", u8"🂫", u8"🂬", u8"🂭", u8"🂮", u8"🂡"} } };

int main() {
  for (int i=0; i<4; i++) {
    cout << couleurs[i] << " ";
  }
  cout << endl;
  for (int i=0; i<4; i++) {
    for (int j=0; j < 14; j++) {
      cout << cartes[i][j];
    }
  cout << endl;
  }
  cout << cartes[2][11] << endl;
  return EXIT_SUCCESS;
}

