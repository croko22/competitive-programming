#include <iostream>
int main(int argc, char const *argv[])
{
    int velocity, time;
    while (std::cin >> velocity >> time)
    {
        std::cout << 2 * velocity * time << std::endl;
    }
    return 0;
}