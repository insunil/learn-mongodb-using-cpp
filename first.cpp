// C++ Program to Get Environment Variable
#include <cstdlib>
#include <iostream>
using namespace std;

int main()
{
    // Specify the name of the environment variable
    const char* env_var_name = "MONGODB_URI";

    // Get the value of the environment variable
    const char* env_var_value = getenv(env_var_name);

    // Check if the environment variable was found
    if (env_var_value != nullptr) {
        cout << env_var_name << " = " << env_var_value<< endl;
    }
    else {
        cout << "Environment variable " << env_var_name<< " not found." << endl;
    }

    return 0;
}
