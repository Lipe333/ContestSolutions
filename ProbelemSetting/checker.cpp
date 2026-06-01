#include <bits/stdc++.h>
#include "testlib.h"

using namespace std;

string normalize(string s){
    for(char &c : s) c = tolower(c);
    return s;
}

int main(int argc, char *argv[]) {
    registerTestlibCmd(argc, argv);

    string jans = ans.readToken();
    string pans = ouf.readToken();

    jans = normalize(jans);
    pans = normalize(pans);

    if (jans != pans) {
        quitf(_wa, "esperado %s, encontrado %s", jans.c_str(), pans.c_str());
    }

    quitf(_ok, "resposta correta: %s", pans.c_str());
}