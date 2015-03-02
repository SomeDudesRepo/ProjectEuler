#include "problem006.h"

#include <string>

#include "../../log.h"

namespace
{

int GetSquareSum(const int& n)
{
    const int square(static_cast<const int>(std::pow(n, 2)));
    return square * (square + (2 * n) + 1) / 4;
}

/*
A formula that can be used instead of the calculation is explained at
http://www.trans4mind.com/personal_development/mathematics/series/sumNaturalSquares.htm
*/
int GetSumOfSquares(const int& n)
{
    if (n == 0)
        return n;
    int sum(0);
    for (int i(1); i <= n; ++i)
        sum += static_cast<int>(std::pow(i, 2));
    return sum;
}

int CalculateDifference(const int& min, const int& max)
{
    const int squareSumMax(GetSquareSum(max)),
              squareSumMin(GetSquareSum(min)),
              sumOfSquaresMax(GetSumOfSquares(max)),
              sumOfSquaresMin(GetSumOfSquares(min));
    Log("squareSumMax: " + std::to_string(squareSumMax));
    Log("squareSumMin: " + std::to_string(squareSumMin));
    Log("sumOfSquaresMax: " + std::to_string(sumOfSquaresMax));
    Log("sumOfSquaresMin: " + std::to_string(sumOfSquaresMin));
    return squareSumMax - squareSumMin - sumOfSquaresMax + sumOfSquaresMin;
}

}  // namspace

Problem006::Problem006(const int& min, const int& max)
    :   BaseRunnable(CalculateDifference(min - 1, max)) {}
