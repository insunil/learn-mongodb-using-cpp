#include <envpp/envpp.h>

int main() {
    envpp::load(".env");

    // Access environment variables
    std::string variable = std::getenv("VARIABLE_NAME");

    return 0;
}
