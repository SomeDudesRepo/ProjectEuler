#include "problem019.h" 
 
#include "../../log.h" 
 
namespace 
{ 

const int kMonthCount = 12;
const int kDays[kMonthCount] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
const std::string kDayNames[] = { "Mo", "Tu", "We", "Th", "Fr", "Sa", "Su" };

int CheckExtraDay(const int& year, const int& month)
{
    if (month != 1)
        return 0;

    if (year % 4 != 0)
        return 0;

    if (year % 100 == 0)
    {
        if (year % 400 == 0)
        {
//            Log("Returning 1 for year: " + std::to_string(year));
            return 1;
        }
        else
        {
            return 0;
        }
    }

//    Log("Returning 1 for year: " + std::to_string(year));
    return 1;
}

uint64_t SundaysOnA1st(const int& day, const int& start, const int& end)
{ 
    int count(0), curr(day);
    for (int year(start); year <= end; ++year)
    {
        for (int month(0); month != kMonthCount; ++month)
        {
            if (curr == 6)
            {
                Log("1st of " + std::to_string(month + 1) + "/" + std::to_string(year) +
                    " on day " + kDayNames[curr]);
                ++count;
            }
            curr = (curr + kDays[month] + CheckExtraDay(year, month)) % 7;
        }
//        Log("Count of year " + std::to_string(year) + ": " + std::to_string(count));
    }
    return static_cast<uint64_t>(count);
} 
 
}  // namespace 
 
Problem019::Problem019(const int& day, const int& start, const int& end)
    :   BaseRunnable(SundaysOnA1st(day, start, end)) {}
