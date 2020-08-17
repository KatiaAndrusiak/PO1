// Program testowy
//
// Należy dopisać klasę Worker program się kompilował
// i dawał wyjście podane na końcu tego pliku.
//

#include <iostream>

#include "worker.h"

using namespace std;

int main() {
    
    Worker *empl1 = new Worker("Ben Maddy");
    Worker *empl2 = new Worker("Kid Shultz");
    
    cout << *empl1 << endl;
    cout << *empl2 << endl;
    
    delete empl1;
    delete empl2;
    
    return 0;
}

/* ** Wyjście **
Ben Maddy
Kid Shultz
*/