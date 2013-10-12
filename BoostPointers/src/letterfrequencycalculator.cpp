#include "letterfrequencycalculator.h"

freq::LetterFrequencyCalculator::LetterFrequencyCalculator()
{
}

unsigned int freq::LetterFrequencyCalculator::calculate(std::string &string, char target)
{
    int size = string.size();
    if (size == 0)
    {
        return 0;
    }
    int accum = 0;
    for(int i = 0 ; i < size ; ++i)
    {
        if (string.at(i) == target) {
            accum++;
        }
    }
    return accum*100/size;
}
