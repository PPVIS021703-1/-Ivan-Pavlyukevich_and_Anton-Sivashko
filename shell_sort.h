#include <vector>
#include "example.h"

#ifndef LAB4_1_SHELL_SORT_H
#define LAB4_1_SHELL_SORT_H

template <typename T>
void swap(T &arr1, T &arr2){
    T temp = arr1;
    arr1 = arr2;
    arr2 = temp;
}

template <typename T>
void shell_sort(T arr[], int length){
    for (int gap = length / 2; gap > 0; gap /= 2)
        for (int j = gap; j < length; j++)
            for(int k = j - gap; k >= 0; k -= gap)
                if (arr[k + gap] >= arr[k])
                    break;
                else
                    swap<T>(arr[k + gap], arr[k]);
}

template <typename T>
void shell_sort(std::vector<T> &arr) {
    for (int gap = arr.size() / 2; gap > 0; gap /= 2)
        for (int j = gap; j < arr.size(); j++)
            for(int k = j - gap; k >= 0; k -= gap)
                if (arr[k + gap] >= arr[k])
                    break;
                else
                    std::swap(arr[k + gap], arr[k]);
}

template <>
void shell_sort(example arr[], int length)
{
    for (int gap = length / 2; gap > 0; gap /= 2)
        for (int j = gap; j < length; j++)
            for(int k = j - gap; k >= 0; k -= gap)
                if (arr[k + gap].get() >= arr[k].get())
                    break;
                else
                    std::swap(arr[k + gap], arr[k]);
}

template <>
void shell_sort(std::vector<example>& arr){
    for (int gap = arr.size() / 2, j = gap, k = j - gap;
         gap > 0 && j < arr.size() && k >= 0;
         gap /= 2, j++, k -= gap)
        if (arr[k + gap].get() >= arr[k].get())
            break;
        else
            std::swap(arr[k + gap], arr[k]);
}

#endif //LAB4_1_SHELL_SORT_H
