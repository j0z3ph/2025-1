#include <iostream>

using namespace std;

int main()
{
    double pi = 3.1416234234;
    char str[100];
    sprintf(str, "%.2lf", pi);

    string str2(str);

    cout << str2;

    return 0;
}
