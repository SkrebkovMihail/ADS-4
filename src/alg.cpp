// Copyright 2021 NNTU-CS

int countPairs1(int *arr, int len, int value) {
    int count = 0;
    for (int i = 0; i < len - 1; i++) {
        for (int j = i + 1; j < len; j++) {
            if (arr[i] + arr[j] == value) {
                count++;
                break;
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
    int i = 0, j = len - 1;
    while (i < j) {
        if (arr[i] + arr[j] == value) {
            count++;
            i++;
            j--;
            while (i < j && arr[i] == arr[i - 1]) {
                i++;
            }
            while (i < j && arr[j] == arr[j + 1]) {
                j--;
            }
        } else if (arr[i] + arr[j] < value) {
            i++;
        } else {
            j--;
        }
    }
    return count;
}
