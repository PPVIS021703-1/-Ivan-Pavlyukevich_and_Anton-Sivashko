#include <iostream>
#include <vector>
#include "example.h"
#include "shell_sort.h"
#include "LSDRadix_sort.h"


int main() {
    // *********    Shell sort    *********
    // arr
    // int
    std::cout << "*********    Shell sort    *********\n\n";
    std::cout << "arr:\n";

    std::cout << "int:\n";
    int shell_int[10] = { 0, 6, 2, 5, 1, 3, 8, 5, 7, 4 };
    for(int i = 0; i < 10; i++)
        std::cout << shell_int[i] << ' ';
    shell_sort(shell_int, 10);
    std::cout << std::endl;
    for(int i = 0; i < 10; i++)
        std::cout << shell_int[i] << ' ';
    std::cout << std::endl << std::endl;

    // char
    std::cout << "char:\n";
    char shell_char[27] = "mnbvcxzlkjhgfdsapoiuytrewq";
    for(int i = 0; i < 26; i++)
        std::cout << shell_char[i] << ' ';
    shell_sort(shell_char, 27);
    std::cout << std::endl;
    for(int i = 1; i < 27; i++)
        std::cout << shell_char[i] << ' ';
    std::cout << std::endl << std::endl;

    // example_class
    std::cout << "example class:\n";
    example shell_example[10] = { 0, 6, 2, 5, 1, 3, 8, 5, 7, 4 };
    for(int i = 0; i < 10; i++)
        std::cout << shell_example[i].get() << ' ';
    shell_sort(shell_example, 10);
    std::cout << std::endl;
    for(int i = 0; i < 10; i++)
        std::cout << shell_example[i].get() << ' ';
    std::cout << std::endl << std::endl;


    // vector
    // int
    std::cout << "vector<int>:\n";
    std::vector<int> vector_shell_int { 0, 6, 2, 5, 1, 3, 8, 5, 7, 4 };
    for(int i = 0; i < vector_shell_int.size(); i++)
        std::cout << vector_shell_int[i] << ' ';
    std::cout << std::endl;
    shell_sort(vector_shell_int);
    for(int i = 0; i < vector_shell_int.size(); i++)
        std::cout << vector_shell_int[i] << ' ';
    std::cout << std::endl << std::endl;

    // char
    std::cout << "vector<char>:\n";
    std::vector<char> vector_shell_char { 'm', 'n', 'b', 'v', 'c', 'x', 'z', 'l', 'k', 'j', 'h', 'g', 'f',
                                         'd', 's', 'a', 'p', 'o', 'i', 'u', 'y', 't', 'r', 'e', 'w', 'q' };
    for(int i = 0; i < vector_shell_char.size(); i++)
        std::cout << vector_shell_char[i] << ' ';
    std::cout << std::endl;
    shell_sort(vector_shell_char);
    for(int i = 0; i < vector_shell_char.size(); i++)
        std::cout << vector_shell_char[i] << ' ';
    std::cout << std::endl << std::endl;

    // example class
    std::cout << "vector<example_class>:\n";
    std::vector<int> vector_shell_example { 0, 6, 2, 5, 1, 3, 8, 5, 7, 4 };
    for(int i = 0; i < vector_shell_example.size(); i++)
        std::cout << vector_shell_example[i] << ' ';
    std::cout << std::endl;
    shell_sort(vector_shell_example);
    for(int i = 0; i < vector_shell_example.size(); i++)
        std::cout << vector_shell_example[i] << ' ';
    std::cout << std::endl << std::endl;


    // *********    LSD sort    *********
    // arr
    std::cout << "*********    LSD sort    *********\n\n";
    std::cout << "arr:\n";

    // int
    std::cout << "int:\n";
    int LSD_int[15] = {7,4,4,89,34,12,54,12,5,1,0,3,67,22,21 };
    for(int i = 0; i < 15; i++)
        std::cout << LSD_int[i] << ' ';
    LSDRadixSort(LSD_int, 15);
    std::cout << std::endl;
    for(int i = 0; i < 15; i++)
        std::cout << LSD_int[i] << ' ';
    std::cout << std::endl << std::endl;

    // char
    std::cout << "char:\n";
    char LSD_char[27] = "mnbvcxzlkjhgfdsapoiuytrewq";
    for(int i = 0; i < 26; i++)
        std::cout << LSD_char[i] << ' ';
    LSDRadixSort(LSD_char, 27);
    std::cout << std::endl;
    for(int i = 1; i < 27; i++)
        std::cout << LSD_char[i] << ' ';
    std::cout << std::endl << std::endl;


    // vector
    std::cout << "vector:\n";

    // int
    std::cout << "vector<int>:\n";
    std::vector<int> vector_LSD_int { 7, 4, 4, 89, 34, 12, 54, 12, 5, 1, 0, 3, 67, 22, 21 };
    for(int i = 0; i < vector_LSD_int.size(); i++)
        std::cout << vector_LSD_int[i] << ' ';
    std::cout << std::endl;
    LSDRadixSort(vector_LSD_int);
    for(int i = 0; i < vector_LSD_int.size(); i++)
        std::cout << vector_LSD_int[i] << ' ';
    std::cout << std::endl << std::endl;

    // char
    std::cout << "vector<char>:\n";
    std::vector<char> vector_LSD_char { 'm', 'n', 'b', 'v', 'c', 'x', 'z', 'l', 'k', 'j', 'h', 'g', 'f',
                                       'd', 's', 'a', 'p', 'o', 'i', 'u', 'y', 't', 'r', 'e', 'w', 'q' };
    for(int i = 0; i < vector_LSD_char.size(); i++)
        std::cout << vector_LSD_char[i] << ' ';
    std::cout << std::endl;
    LSDRadixSort(vector_LSD_char);
    for(int i = 0; i < vector_LSD_char.size(); i++)
        std::cout << vector_LSD_char[i] << ' ';
    std::cout << std::endl << std::endl;

    return 0;
}
