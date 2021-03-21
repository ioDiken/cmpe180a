// /**
//  * @file hw5_mcp.h
//  * @brief Copy Files
//  * @sjsuid 011280893
//  * @author Nicolas Diken
//  */

// #ifndef E3CACFD1_4E4F_4BD9_A362_24B950FB746A
// #define E3CACFD1_4E4F_4BD9_A362_24B950FB746A

// #include <stdint.h>
// #include <stdbool.h>
// #include <string>
// #include <vector>
// #include <exception>
// #include <ostream>

// template<typename T>
// void bubbleSort(std::vector<T> &v);

// template<typename T>
// void swap(T &arg1, T &arg2);

// template <class T>
// class Stack
// {
// public:
//     Stack() = default;
//     ~Stack() = default;

//     T top()
//     {
//         if (!v.empty())
//         {
//             return v.back();
//         }
//         else
//         {
//             throw std::logic_error("Ya dun fucked up AA-ron");
//         }
//     }

//     T pop()
//     {
//         T e = top();
//         v.pop_back();
//         return e;
//     }

//     void push(T e)
//     {
//         v.push_back(e);
//     }

// private:
//     std::vector<T> v;
// };


// template <class T>
// class cArray
// {
// public:
//     cArray(int size)
//     {
//         if (size == 0)
//         {
//             throw std::logic_error("Size 0 is invalid!");
//         }

//         arr = new T[size];
//         memset(arr,0,sz*sizeof(T));
//         sz = size;
//     }

//     ~cArray() {delete arr;}

//     bool set(int i, T val)
//     {
//         if (i < sz)
//         {
//             arr[i] = val;
//             return true;
//         }
//         return false;
//     }

//     bool get(int i, T &val)
//     {
//         if (i < sz)
//         {
//             val = arr[i];
//             return true;
//         }
//         return false;
//     }

//     cArray<T>& operator=(const cArray<T>&)
//     {
//         cArray<T> a(this->sz);
//         for (int i = 0; i < this->sz; i++)
//         {
//             (void) a.set(i,this->arr[i]);
//         }
//         return a;
//     }

// private:
//     T *arr;
//     int sz;
// };

// // C++ template to print vector container elements
// template <typename T> 
// std::ostream& operator<<(std::ostream& os, cArray<T> arr) 
// { 
//     int i = 0;
//     T val;
//     os << "[";
//     while (true == arr.get(i++, val))
//     { 
//         os << val;
//         os << ", "; 
//     } 
//     os << "]\n"; 
//     return os; 
// }


// template <typename T>
// class GenericPointer
// {
// public:
//     GenericPointer(T *p)
//     {
//         // I asked you whether the class should store the value of the pointer
//         // or the pointer itself. And you said follow what the question says.
//         ptr = p;
//     }

//     ~GenericPointer()
//     {
//         // Why would you deallocaate memory associated with a pointer you don't own?
//         // I do not know. This is what makes the most logical sense. A class that didnt
//         // create the pointer deallocating it would be *EXTREMELY* dangerous
//         ptr = NULL;

//         // Setting ptr to NULL is pointless; as the memory holding the pointer will be
//         // deallocated when the class is destroyed anyways. But this is about as close
//         // as I could discern to what you mean.
//     }

//     T* operator->() const
//     {
//         return ptr;
//     }

//     // This is define within the class
//     T operator*() const
//     {
//         return *ptr;
//     }

// private:
//     T *ptr;
// };



// class Time 
// {
// public:
//     Time(int hh, int mm, int ss) : h(hh), m(mm), s(ss) {}

// private:
//     int h, m, s;
// };

// class TimeOfDay : public Time
// {
// public:
//     TimeOfDay(const int day, const int month, const int year, const int hour,
//                 const int minute, const int second);
//     ~TimeOfDay() = default;

//     const int getDay();
//     const int getMonth();
//     const int getYear();

//     bool setDay(const int day);
//     bool setMonth(const int month);
//     bool setYear(const int year);

// private:
//     int _day;
//     int _month;
//     int _year;

//     // Checks valid year. not really needed.
//     bool is_year_valid(const int year);
//     // Check month is valid
//     bool is_month_valid(const int month);
//     // check day is valid, depends on month & year
//     bool is_day_valid(const int year, const int month, const int day);
// };



// #endif /* E3CACFD1_4E4F_4BD9_A362_24B950FB746A */
