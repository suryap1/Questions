//
// Created by Tafseer Ahmed on 2/28/2018.
// Two arguments are supplied to the program
// first argument is the functionname to be searched
// second argument is the name of the file in which
// the source code is present in a single line with nextline,
// shown by "\n" symbol.
// syntax:
// ./<program-name> <functionname> <filename>
// eg. ./finddef func2 input.txt
//

#include <iostream>
#include <fstream>
#include <cstring>
#include <algorithm>

bool isDef(const char *f, const char *sc, unsigned int pos) {
    unsigned int N = strlen(f);
    for (int i = 0; i < N; i++) {
        if (f[i] != sc[pos++]) return false;
    }
    if (sc[pos] != '(') return false;
    while (sc[pos] != ')') pos++;
    return (sc[pos + 1] == '{');
}

unsigned int FindFunctionDefn(const char *f, const char *sc) {
    unsigned int lno = 1, size = strlen(sc);
    for (unsigned int i = 0; i < size; i++) {
        if (f[0] == sc[i]) {
            if (isDef(f, sc, i)) return lno;
        } else if (sc[i] == 92 && sc[i + 1] == 'n') {
            lno++;
        }
    }
    return 0;
}

int main(int argc, char *argv[]) {
    const char *src_file = argv[2];
    const char *strFunctionName = argv[1];
    char strSourceCode[10000];
    std::ifstream file(src_file);
    if (file.is_open()) {
        std::string line;
        getline(file, line);
        line.erase(remove_if(line.begin(), line.end(), isspace), line.end());
        std::strcpy(strSourceCode, line.c_str());
        file.close();
    } else {
        std::cout << "Error opening file\n";
    }
    std::cout << FindFunctionDefn(strFunctionName, strSourceCode);
    int p;
    std::cin >> p;
    return 0;
}
