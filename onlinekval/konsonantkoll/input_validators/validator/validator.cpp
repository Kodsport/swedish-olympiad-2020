#include "validator.h"

bool isConsonant(char c) {
    const string consonants = "bcdfghjklmnpqrstvwxz";
    return consonants.find(c) != string::npos;
}

void run() {
    bool allowSpaces = Arg("allowSpaces");
    int maxRepeated = Arg("maxRepeated");
    int maxLength = Arg("maxLength");

    string in = Line();
    Eof();

    // String length
    assert(in.size() >= 1);
    assert(in.size() <= maxLength);

    // Spaces
    bool hasSpace = in.find(' ') != string::npos;
    assert(!(hasSpace && !allowSpaces));

    // Only a-z and space
    for (char c : in) assert((c >= 'a' && c <= 'z') || c == ' ');

    // No spaces at end
    assert(in[0] != ' ');
    assert(in[in.size() - 1] != ' ');

    // Max repeated spaces/consonants
    char prev = -1;
    int count = 0;
    for (char c : in) {
        if (c != prev) {
            prev = c;
            count = 0;
        }
        count++;
        if (isConsonant(c)) {
            assert(count <= maxRepeated);
        }
        if (c == ' ') {
            assert(count <= 1);
        }
    }
}
