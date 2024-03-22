// Copyright 2021 NNTU-CS
#include <iostream>
using namespace std;

int countPairs1(int *arr, int len, int value) {
    int count = 0;
    for (int i = 0; i < len - 1; i++) {
        for (int j = i + 1; j < len; j++) {
            if (arr[i] + arr[j] == value) {
                count++;
                while (j < len - 1 && arr[j] == arr[j + 1]) {
                    j++;
                }
            }
        }
    }
    return count;
}

int countPairs2(int *arr, int len, int value) {
    int count = 0;
    int left = 0, right = len - 1;
    while (left < right) {
        if (arr[left] + arr[right] == value) {
            count++;
            while (left < right && arr[left] == arr[left + 1]) {
                left++;
            }
            while (left < right && arr[right] == arr[right - 1]) {
                right--;
            }
            left++;
            right--;
        } else if (arr[left] + arr[right] < value) {
            left++;
        } else {
            right--;
        }
    }
    return count;
}

int countPairs3(int *arr, int len, int value) {
    int count = 0;
    int *countArr = new int[value + 1]();
    for (int i = 0; i < len; i++) {
        if (value - arr[i] >= 0 && countArr[value - arr[i]] > 0) {
            count += countArr[value - arr[i]];
        }
        countArr[arr[i]]++;
    }
    delete[] countArr;
    return count;
}
