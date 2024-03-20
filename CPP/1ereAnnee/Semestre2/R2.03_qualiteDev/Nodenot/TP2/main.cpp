#include <iostream>
using namespace std;

int maxSum(int value, int maxint);

int main(void)
{
    int valValue;
    int valMaxInt;
    int tabValue[] = {7, 5, -5, 2, 2};
    const int NBTESTS = 5;
    int tabMaxInt[] = {30, 20, 10, 1, 4};
    int results[] = {28, 15, -1, -1, 3};
    int cpterreurs = 0;
    for (int i = 0; i < NBTESTS; i++)
    {
        int valValue = tabValue[i];
        int valMaxInt = tabMaxInt[i];
        int resultAutoMaxsum = results[i];
        int resultobtenu = maxSum(valValue, valMaxInt);
        if (!(resultobtenu == resultAutoMaxsum))
            cpterreurs++;
        cout << "value=" + to_string(valValue) + " maxInt=" + to_string(valMaxInt) + " : resultat attendu par Oracle etait :" + to_string(resultAutoMaxsum) + " resultat obtenu=" + to_string(resultobtenu) << endl;
    }
    cout << "NbTests effectues: " + to_string(NBTESTS) + " et Nbtests failed :" + to_string(cpterreurs);
    return 0;
}

int maxSum(int value, int maxint)
{
    if (value < 0)
    {
        return -1;
    }
    else if ((value*(value+1)/2)>maxint)
    {
        return -1;
    }
    else
    {
        return (value*(value+1)/2);
    }
    
    
}