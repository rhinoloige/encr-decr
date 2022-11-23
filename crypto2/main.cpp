#include "header.hpp"

int main(int argc, const char *argv[]) {
    if (argc != 5) {
        std::cerr << "Error: Use 5 parameters\n";
        return 5;
    }
    const std::string style(argv[1]);
    const std::string file_name(argv[2]);
    const std::string massage(argv[3]);
    const std::string pas_str(argv[4]);
    unsigned int password;
    try {
        unsigned int res = stoi(pas_str);
        password = res;
    }
    catch (std::invalid_argument n) {
        std::cerr << "Error";
        return 4;
    }
    if (style == "encryption") {
        encr(password, file_name, massage);
    } else if (style == "decryption") {
        decr(password, file_name);
    } else {
        std::cerr << "Error";
        return 3;
    }
    return 0;
}
