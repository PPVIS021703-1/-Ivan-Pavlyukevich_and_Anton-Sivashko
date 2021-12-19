#include <vector>
#include "example.h"
#define RADIX 256

#ifndef LAB4_1_LSDRADIX_SORT_H
#define LAB4_1_LSDRADIX_SORT_H

int getByte(int elem, int i){
    return (sizeof(elem) > i) ? (elem >> ((3 - i) * 8) & 255) : -1;
}

template <typename T>
int getByte(T* elem, int i){
    return ((*elem).size() > 1) ? (*elem)[i] : -1;
}

template <typename T>
void LSDRadixSort(T tab[], int tabSize){
    int maxLength = sizeof(tab);

    for (int digit = maxLength - 1; digit >= 0; digit--){
        T* tabAux = new T[tabSize];
        for (int i = 0; i < tabSize; i++)
            tabAux[i] = 0;
        T* counter = new T[RADIX + 2];
        for (int i = 0; i < RADIX + 2; i++)
            counter[i] = 0;

        for (int i = 0; i < tabSize; ++i)
            counter[getByte(tab[i], digit) + 2]++;

        for (int i = 0; i < RADIX + 1; ++i)
            counter[i + 1] += counter[i];

        for (int i = 0; i < tabSize; ++i)
            tabAux[counter[getByte(tab[i], digit) + 1]++] = tab[i];

        for (int i = 0; i < tabSize; ++i)
            tab[i] = tabAux[i];
    }
}

template <typename T>
void LSDRadixSort(std::vector<T>& tab){
    int tabSize = tab.size();
    int maxLength = tab.size();

    for (int digit = maxLength - 1; digit >= 0; digit--){
        std::vector<T> tabAux(tabSize, 0);
        std::vector<T> counter(RADIX + 2, 0);

        for (int i = 0; i < tabSize; ++i)
            counter[getByte(tab[i], digit) + 2]++;

        for (int i = 0; i < RADIX + 1; ++i)
            counter[i + 1] += counter[i];

        for (int i = 0; i < tabSize; ++i)
            tabAux[counter[getByte(tab[i], digit) + 1]++] = tab[i];

        for (int i = 0; i < tabSize; ++i)
            tab[i] = tabAux[i];
    }
}

#endif //LAB4_1_LSDRADIX_SORT_H
