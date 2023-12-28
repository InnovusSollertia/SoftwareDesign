#include <iostream>  
#include <random> 
#include <ctime>

int main()
{
    std::mt19937 gen(time(0));
    std::uniform_int_distribution<> uid(1, 100);
    std::cout << "Age: " << uid(gen) << " " << std::endl;
}
