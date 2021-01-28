#include <cstdlib>
#include <iostream>

//#include </usr/local/include/SDL2/SDL_version.h>
#if __has_include(<SDL_version.h>)
#include <SDL_version.h>
#else
#include <SDL2/SDL_version.h>
#endif

std::ostream& operator<<(std::ostream& out, const SDL_version& v)
{
    out << static_cast<int>(v.major) << '.';
    out << static_cast<int>(v.minor) << '.';
    out << static_cast<int>(v.patch);
    return out;
}

int main(int /*argc*/, char* /*argv*/[])
{
    using namespace std;

    SDL_version compiled = { 0, 0, 0 };
    SDL_version linked   = { 0, 0, 0 };

    SDL_VERSION(&linked);
    SDL_GetVersion(&compiled);
    
    cout << "second compiled: " << compiled << '\n';
    cout << "second linked: " << linked << endl;

    bool is_good = cout.good();

    int result = is_good ? EXIT_SUCCESS : EXIT_FAILURE;
    return result;
}