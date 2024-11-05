/**
 * @file main.cpp
 * @author Jose Luis Cruz (jlcruz@ipn.mx)
 * @brief Mi primer arreglo
 * @version 0.1
 * @date 2024-11-04
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include<iostream>
#include<cstdlib>
#include<ctime>

using namespace std;

int main()
{
    srand(time(NULL));
    int arrg[10];
    int arrg2[3][3];


    for (int i = 0; i < 10; i++)
    {
        arrg[i] = (rand()%41) - 20;
    }

    for (int i = 0; i < 10; i++)
    {
        cout << arrg[i] << " ";
    }
    
    


    
    return 0;
}
