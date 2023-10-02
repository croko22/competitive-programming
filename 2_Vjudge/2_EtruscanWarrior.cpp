#include <iostream>
#include <math.h>
int main(int argc, char const *argv[])
{
    int t;
    long long n;
    std::cin >> t;
    while (t--)
    {
        std::cin >> n;
        std::cout << (long long)((sqrt(1 + 8 * n) - 1) / 2) << std::endl;
    }
    return 0;
}