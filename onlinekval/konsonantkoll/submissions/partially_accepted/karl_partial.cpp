#include <iostream>
#include <string>
using namespace std;

void removeTriple(string& w, char c) {
  string search = string(3, c);
  size_t pos;
  while ((pos = w.find(search)) != string::npos) {
    w.erase(pos + 2, 1);
  }
}

int main() {
  string w;
  cin >> w;

  for (char c : "bcdfghjklmnpqrstvwxz") removeTriple(w, c);
  cout << w << endl;

  return 0;
}
