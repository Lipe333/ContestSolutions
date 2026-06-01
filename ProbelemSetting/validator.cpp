#include "testlib.h"
#include <string>

using namespace std;

int main(int argc, char* argv[]) {
    registerValidation(argc, argv);
    
    int n = inf.readInt(1, 1000000, "N");
    inf.readEoln();
    
    vector<long long> a = inf.readLongs(n, 1, 1000000000LL, "A");

    inf.readEoln();
    inf.readEof();
    
    return 0;
}