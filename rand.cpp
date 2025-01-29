#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main(){
   srand(time(NULL));
   cout << "Nombres au hasard : ";
   for (int i = 0; i<5; i++)
     cout << rand() % 100 << " ";
   cout << endl;
   return 0;
}

