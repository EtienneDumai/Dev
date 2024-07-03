#include <iostream>
using namespace std;
int main()
{
    cout << "Hello, World!" << endl;
    #define DEBUG_ON = true;
    #ifdef DEBUG_ON
    cout << "INIT : " << __LINE__ << endl;
    #endif
    return 0;
}
// #define DEBUG_ON = true;
// #ifdef DEBUGON
//     cout << "INIT : " << __LINE__ << endl;
// #endif
