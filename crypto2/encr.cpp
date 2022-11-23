//
// Created by rhino on 23.11.2022.
//
#include "header.hpp"

void encr(const unsigned int &password, const std::string &file_name, const std::string &massage) {
    std::string str = massage;
    std::string result;
    if (str.size() % 2 != 0) str += static_cast<char>(0);
    for (size_t i = 0; i < str.size() / 2; i++) {
        std::bitset<16> part(std::bitset<8>(str[i * 2]).to_string() + std::bitset<8>(str[i * 2 + 1]).to_string());
        part = part >> 3 | part << 13;
        auto gam = std::bitset<16>(23);
        part ^= gam;
        unsigned char s1, s2;
        std::bitset<8> empty(0);
        for (size_t i = 0; i < 16; i++) {
            if (i < 8) {
                empty[i] = part[i];
            } else if (i == 8) {
                s2 = empty.to_ulong();
                empty[0] = part[i];
            } else if (i < 15) {
                empty[i - 8] = part[i];
            } else {
                empty[i - 8] = part[i];
                s1 = empty.to_ulong();
            }
        }
        result += s1;
        result += s2;
    }
    std::ofstream file(file_name, std::ios_base::out | std::ios_base::trunc);
    file.write((result).c_str(), result.size());
    file.close();
}
