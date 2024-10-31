/**
 * @file arreglos.cpp
 * @author Jose Luis Cruz (jlcruz@ipn.mx)
 * @brief Mi primer programa con arreglos :>
 * @version 0.1
 * @date 2024-10-31
 *
 * @copyright Copyright (c) 2024
 *
 */
#include <iostream>
#include <cstdlib>
#include <ctime>
#define N 10

using namespace std;

int main()
{
    srand(time(NULL));
    int arrg[N];

    for (int i = 0; i < N; i++)
    {
        arrg[i] = (rand()%41) - 20;
    }

    cout << "[ ";
    for (int i = 0; i < N; i++)
    {
        cout << arrg[i] << " ";
    }
    cout << "]" << endl;
    

    return 0;
}
