/**
 * @file arrgs.cpp
 * @author Jose Luis Cruz (jlcruz@ipn.mx)
 * @brief Mas arreglos
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
    int arr[10];

    for (int i = 0; i < 10; i++)
    {
        *(arr + i) = i;
    }

    for (int i = 0; i < 10; i++)
    {
        cout << arr[i] << " ";
    }
    
    //cout << arr << endl;
    //cout << &arr << endl;

    return 0;
}
