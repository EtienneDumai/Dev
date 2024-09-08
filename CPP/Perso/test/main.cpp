#include <iostream>
using namespace std;
/**
 * @brief 
 * 
 * @param a 
 * @param b 
 * @return int 
 */
int add(int a, int b)
{
    return a + b;
}
float add(float a, float b)
{
    return a + b;
}
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
