#include <iostream>

int main() {
    // Define the alphabet and its range
    const char init = 'a';
    const char end = 'z';
    const char range = end - init + 1;

    // str is the input string, out is the output string
    const std::string str  {"abacyz"};
    std::string out(str.size(), 'a');

    // By how much do we rotate the iput string
    const int8_t rot = -26;

    // Index to write the output
    auto idx = 0U;

    // Rotate each character in str
    for(auto ch : str) {
        // Displacement is the new character index translated
        // so that 'a' is zero. Note that it can take negative
        // values, but always in the range [-range + 1, range - 1]
        const auto displacement = ((ch - init) + rot) % range;

        // If the displacement is negative, we add range, so that
        // it takes a possitive value between init and end, otherwise
        // just add the displacement to init
        char encoded;
        if (displacement < 0) {
            encoded = init + range + displacement;
        } else {
            encoded = init + displacement;
        }
        out[idx++] = encoded;
    }
    std::cout << str << std::endl;
    std::cout << out << std::endl;
}
