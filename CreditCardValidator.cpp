#include <iostream>
#include <string>
#include <vector>

int DoubleAndSumEverySecondDigitFromRight(std::string &num)
{
    bool skipFlag = false;
    int sum = 0;
    for (int i = num.size() - 1; i >= 0; i--)
    {
        skipFlag = !skipFlag;
        if (skipFlag)
            continue;
        int value = num[i] - '0';
        std::cout << "Value: " << value << std::endl;

        value *= 2;
        if (value > 9)
        {
            std::cout << "Value1: " << (value % 10) << std::endl;
            sum += (value % 10);
            std::cout << "Value2: " << (value / 10) << std::endl
                      << std::endl;
            sum += (value / 10);
        }
        else
            sum += value;
    }
    return sum;
}

int SumOddNumberedDigitsFromRight(std::string &num)
{
    bool skipFlag = true;
    int sum = 0;
    for (int i = num.size() - 1; i >= 0; i--)
    {
        skipFlag = !skipFlag;
        if (skipFlag)
            continue;
        int value = num[i] - '0';
        std::cout << "Value: " << value << std::endl;
        sum += value;
    }
    return sum;
}

int main()
{
    std::string cardNum = "60110009901394242";
    std::cout << DoubleAndSumEverySecondDigitFromRight(cardNum)
              << std::endl;
    std::cout << SumOddNumberedDigitsFromRight(cardNum)
              << std::endl;

    int sum = DoubleAndSumEverySecondDigitFromRight(cardNum) + SumOddNumberedDigitsFromRight(cardNum);
    std::cout << "Credit Card is " << ((sum % 10) == 0 ? "Valid" : "Not Valid") << std::endl;
    return sum % 10 == 0;
}