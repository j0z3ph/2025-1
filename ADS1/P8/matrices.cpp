/**
 * @file matrices.cpp
 * @author Jose Luis Cruz (jlcruz@ipn.mx)
 * @brief Matrices
 * @version 0.1
 * @date 2024-11-12
 *
 * @copyright Copyright (c) 2024
 *
 */
#include <iostream>

using namespace std;

int main()
{
    int matriz[3][3];
    int *ptr = *matriz;
    for (int i = 0; i < 9; i++)
    {
        *(ptr + i) = i;
        //ptr[i] = i;
    }

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << *(*(matriz + i) + j) << " ";
        }
        cout << endl;
    }

    cout << matriz << endl;
    cout << *matriz << endl;
    cout << matriz + 1 << endl;
    cout << *matriz + 1 << endl;

    return 0;
}
