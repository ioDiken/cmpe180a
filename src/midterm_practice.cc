/**
 * @file hw5_mcp.h
 * @brief Copy Files
 * @sjsuid 011280893
 * @author Nicolas Diken
 */

#include "midterm_practice.h"

// -----------------------------------------------------------------------------
// Shit

// template<typename T>
// void bubbleSort(std::vector<T> &v)
// {
//     for (int i = 0; i < v.size(); i++)
//     {
//         for (int j = 0; j < i-1; j++)
//         {
//             if (v[j] > v[j+1])
//             {
//                 swap<T>(v[j],v[j+1]);
//             }
//         }
//     }
// }

// template<typename T>
// void swap(T &arg1, T &arg2)
// {
//     T tmp = arg1;
//     arg1 = arg2;
//     arg2 = tmp;
// }

// GenericPointer::GenericPointer(T *p)
// {
//     // I asked you whether the class should store the value of the pointer
//     // or the pointer itself. And you said follow what the question says.
//     ptr = p;
// }

// GenericPointer::~GenericPointer()
// {
//     ptr = NULL;
// }


// TimeOfDay::TimeOfDay(const int day, const int month, const int year, 
//                         const int hour, const int minute, const int second)
//                 : Time(hour,minute,second)
// {
//     if (is_year_valid(year))
//         _year = year;
//     if (is_month_valid(month))
//         _month = month;
//     if (is_day_valid(year,month,day))
//         _day = day;
// }

// int TimeOfDay::getDay()
// {
//     return _day;
// }

// int TimeOfDay::getMonth()
// {
//     return _month;
// }

// int TimeOfDay::getYear()
// {
//     return _year;
// }

// bool TimeOfDay::setDay(const int day)
// {
//     if (is_day_valid(_year,_month,day))
//     {
//         _day = day;
//         return true;
//     }
//     return false;
// }

// // this could break day, but we'll worry about that another time
// bool TimeOfDay::setMonth(const int month)
// {
//     if (is_month_valid(month))
//     {
//         _month = month;
//         return true;
//     }
//     return false;
// }

// // this could break day, but we'll worry about that another time
// bool TimeOfDay::setYear(const int year)
// {
//     if (is_year_valid(year))
//     {
//         _year = year;
//         return true;
//     }
//     return false;
// }