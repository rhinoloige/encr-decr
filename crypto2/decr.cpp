//
// Created by rhino on 23.11.2022.
//
#include "header.hpp"

void decr(const unsigned int &password, const std::string &file_name) {
    std::string result, time, str1;
    std::ifstream file(file_name, std::ios_base::in);
    if (file.is_open()) while (getline(file, time)) str1 += time;
    file.close();
    for (size_t i = 0; i < str1.size() / 2; i++) {
        std::bitset<16> part1(std::bitset<8>(str1[i * 2]).to_string() + std::bitset<8>(str1[i * 2 + 1]).to_string());
        auto gam1 = std::bitset<16>(23);
        part1 ^= gam1;
        part1 = part1 << 3 | part1 >> 13;
        unsigned char s1, s2;
        std::bitset<8> empty(0);
        for (size_t i = 0; i < 16; i++) {
            if (i < 8) {
                empty[i] = part1[i];
            } else if (i == 8) {
                s2 = empty.to_ulong();
                empty[0] = part1[i];
            } else if (i < 15) {
                empty[i - 8] = part1[i];
            } else {
                empty[i - 8] = part1[i];
                s1 = empty.to_ulong();
            }
        }
        result += s1;
        result += s2;
    }
    std::ofstream file1(file_name, std::ios_base::out | std::ios_base::trunc);
    file1.write(result.c_str(), result.size());
    file1.close();
}
