//variadic templates (arbitrary # of type params)
#include <iostream>
using std::cout;

using std::endl;
#include <limits>
using std::numeric_limit;
#include <string>
using std::string;
using std::to_string;
#include <memory>;
using std::unique_ptr;
#include <forward>
using std::forward;

template<char... Digits>
constexpr unsigned long long operator"" _b()
{
	return Binary<Digits...>::value;
}

template<>
struct Binary<>
{
	static constexpr unsigned long long value =0;
}

template<char... Digits>
struct Binary;

template<char digit, char...Digits>
struct Binary<digit, Digits...>
{
	// compiler assertions
	static_assert(
		sizeof...(Digits)+1 <= numeric_limits<unsigned long long>::digits,
		"too many digits for unsigned long long");
	static_assert(
		digit == '1' || digit == '0',
		"only 1 and 0 allowed in binary literals");
	// wicked one-liner from Alex Cobun from PS!
	static constexpr unsigned long long value =
		((digit - '0') << sizeof...(Digits)) + Binary<Digits...>::value;
};

// references to references (forwarding)
template<typename T, typename... Args>
unique_ptr<T> unique(const Args&&... args)
{
	// reference collapsing (lvaue - lvalue -> lvalue, else -> rvalue)
	// with forward
	return unique_ptr<T>(new T(forward<Args>(args));
}

// 1st param
template<typename T>
void multi_print(const T &val) 
{
	cout << val << endl;
}
//other params
template<typename T, typename...Ts>
void multi_print(const T& val, const Ts&... values)
{
	cout << val << endl;
	multi_print(values...);
}
//rvalue template
template<typename T>
void multi_print(const T&& val) 
{
	cout << val << endl;
}
template<typename T, typename...Ts>
void multi_print(const T&& val, const Ts&&... values)
{
	cout << val << endl;
	multi_print(values...);
}
