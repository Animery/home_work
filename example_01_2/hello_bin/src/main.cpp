#include <cstdlib>
#include <greeting.hpp>

int main(int /*argc*/, char * /*argv*/[])
{
    const char *user_var = std::getenv("USER");
    const char *host_var = std::getenv("HOSTNAME");

    std::string_view user = user_var != nullptr ? user_var : "USER - environment variable not found";
    std::string_view host = host_var != nullptr ? host_var : "HOST - environment variable not found";

    // bool is_good = greeting(user, host);
    // int result = is_good ? EXIT_SUCCESS : EXIT_FAILURE;
    // return result;

    return !greeting(user, host);
}
