#ifndef LETTERFREQUENCYCALCULATOR_H
#define LETTERFREQUENCYCALCULATOR_H
#include <string>

namespace freq
{


class LetterFrequencyCalculator
{
public:
    LetterFrequencyCalculator();
    unsigned int calculate(std::string & string, char target);
};

}
#endif // LETTERFREQUENCYCALCULATOR_H
