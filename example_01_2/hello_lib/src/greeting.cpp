#include <iostream>
#include <greeting.hpp>

bool greeting(std::string_view user_name, std::string_view host_name)
{
    
    std::cout << "Hello, " << user_name << " from " << host_name << " PC" << std::endl;

    return std::cout.good();
}