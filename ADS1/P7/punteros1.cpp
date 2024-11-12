/**
 * @file punteros1.cpp
 * @author Jose Luis Cruz (jlcruz@ipn.mx)
 * @brief Mi primer puntero :>
 * @version 0.1
 * @date 2024-11-11
 *
 * @copyright Copyright (c) 2024
 *
 */
#include <iostream>

using namespace std;

int main()
{
    int arrg[100];
    arrg[0] = 666;
    arrg[1] = 999;
    double variable = 10.0;
    int *ptr;
    ptr = arrg;

    *(ptr - 120) = 777;

    cout << variable << endl
         << &variable << endl
         << ptr+1 << endl
         << *ptr << endl
         << *(arrg + 0) << endl
         << *(arrg+1) << endl
         << arrg[1] << endl
         << arrg << endl
         << &arrg << endl
         << ptr << endl
         << &ptr << endl
         << *(ptr-120) << endl;

    return 0;
}
