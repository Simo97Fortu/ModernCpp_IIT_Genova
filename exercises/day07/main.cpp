#include <memory>
#include <iostream>
#include <concepts>
#include <ranges>
#include <algorithm>


template <typename T>
T add (T a, T b) requires std::integral<T>{
    return a+b;
}

// is_incrementable concept definition
template<typename T>
concept is_incrementable = requires(T a) {
    { ++a } -> std::same_as<T&>;
    { a++ } -> std::same_as<T>;
};

// Function that uses the is_incrementable concept
template<is_incrementable T>
void increment_and_print(T& value) {
    std::cout << "Previous: " << value << ", Current: " << ++value << std::endl;
}

int main(int argc, char *argv[])
{
    {
        char a_char{10};
        char b_char(10);

        int  a_int{10};
        int  b_int{20};

        double a_double{10};
        double b_double{10};

        // TODO try to invoke the functions using
        // the three couple of arguments

        auto result_char = add(a_char, b_char);
        std::cout << "The result is "<< unsigned(result_char) << std::endl;

        auto result_int = add(a_int, b_int);
        std::cout << "The result is "<< result_int << std::endl;

        // auto result_double = add(a_double, b_double);
        // std::cout << "The result is "<< result_double << std::endl;

    }

    {
        // TODO write an "is_incrementable" concept and use it
        int i = 0;
        increment_and_print(i);  // Output: 1

        double d = 1.5;
        increment_and_print(d); // Output 2.5
    }

    {
        // TODO generate a series of numbers from 0 to 20
        // and print it only the even. You must use views

        // Generate a sequence of numbers from 0 to 20
        auto numbers = std::views::iota(0, 21);

        // Filter even numbers
        auto evens = numbers | std::views::filter([](int n) { return n % 2 == 0; });

        // Print the even numbers
        for (int n : evens) {
            std::cout << n << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}

