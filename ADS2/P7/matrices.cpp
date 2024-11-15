/**
 * @file matrices.cpp
 * @author Jose Luis Cruz (jlcruz@ipn.mx)
 * @brief
 * @version 0.1
 * @date 2024-11-14
 *
 * @copyright Copyright (c) 2024
 *
 */
#include <iostream>

using namespace std;

int main()
{
    int matriz[3][3];
    int *ptr;
    ptr = *matriz;

    for (int i = 0; i < 9; i++)
        *(ptr +i) = i;
        //*(*matriz + i) = i;
    

    for (int i = 0; i < 9; i++)
        cout << (*matriz)[i] << ((i + 1) % 3 ? ' ' : '\n');
    

    cout << matriz << endl << matriz + 1;
    return 0;
}
