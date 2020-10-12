#include <iostream>
#include <vector>

/*
左右指针不取右，j 和 j + 1
void quickSort(int* arr, int left, int right) {
    if (left >= right) {
        return;
    }
    int pivot = arr[left + ((right - left) >> 1)];
    int i = left - 1;
    int j = right + 1;
    while (i < j) {
        while (arr[++i] < pivot) {
        }
        while (arr[--j] > pivot) {
        }
        if (i < j) {
            swap(arr[i], arr[j]);
        }
    }
    quickSort(arr, left, j);
    quickSort(arr, j + 1, right);
}
左右指针不取左，i - 1 和 i
void quickSort(int* arr, int left, int right) {
    if (left >= right) {
        return;
    }
    int pivot = arr[(static_cast<int64_t>(left) + right + 1) >> 1];
    int i = left - 1;
    int j = right + 1;
    while (i < j) {
        while (arr[++i] < pivot) {
        }
        while (arr[--j] > pivot) {
        }
        if (i < j) {
            swap(arr[i], arr[j]);
        }
    }
    quickSort(arr, left, i - 1);
    quickSort(arr, i, right);
}
快慢指针法，取左
void quickSort(int* arr, int left, int right) {
    if (left >= right) {
        return;
    }
    int pivot = arr[left];
    int i = left;
    int j = left + 1;
    while (j <= right) {
        if (arr[j] < pivot) {
            ++i;
            swap(arr[i], arr[j]);
        }
        ++j;
    }
    swap(arr[i], arr[left]);
    quickSort(arr, left, i - 1);
    quickSort(arr, i + 1, right);
}
快慢指针法，取右
void quickSort(int* arr, int left, int right) {
    if (left >= right) {
        return;
    }
    int pivot = arr[right];
    int i = left - 1;
    int j = left;
    while (j < right) {
        if (arr[j] < pivot) {
            ++i;
            swap(arr[i], arr[j]);
        }
        ++j;
    }
    ++i;
    swap(arr[i], arr[right]);
    quickSort(arr, left, i - 1);
    quickSort(arr, i + 1, right);
}
*/

// 普通快排
int partation(std::vector<int> &arr, int begin, int end) {
    int cpr = arr[end], le = begin, ri = end - 1;
    while (le < ri) {
        while (le < ri && arr[le] < cpr)
            le++;
        while (le < ri && arr[ri] >= cpr)
            ri--;
        std::swap(arr[le], arr[ri]);
    }
    if (arr[le] >= cpr) {
        std::swap(arr[le], arr[end]);
    } else {
        le++;
    }

    return le;
}

void quickSort1Helper(std::vector<int> &arr, int begin, int end) {
    if (begin >= end)
        return;
    int par = partation(arr, begin, end);
    quickSort1Helper(arr, begin, par - 1);
    quickSort1Helper(arr, par + 1, end);
}

void quickSort1(std::vector<int> &arr) {
    quickSort1Helper(arr, 0, arr.size() - 1);
}

// 三数取中快排
void pivot(std::vector<int> &arr, int begin, int end) {
    int mid = begin + (end - begin) / 2;
    if (arr[begin] > arr[mid])
        std::swap(arr[begin], arr[mid]);
    if (arr[begin] > arr[end])
        std::swap(arr[begin], arr[end]);
    if (arr[mid] > arr[end])
        std::swap(arr[mid], arr[end]);

    std::swap(arr[mid], arr[end - 1]);
}

int partation2(std::vector<int> &arr, int begin, int end) {
    pivot(arr, begin, end);
    int cpr = arr[end - 1], le = begin, ri = end - 1;
    while (le < ri) {
        while (le < ri && arr[le] < cpr)
            le++;
        while (le < ri && arr[ri] >= cpr)
            ri--;
        std::swap(arr[le], arr[ri]);
    }

    if (le < end) {
        std::swap(arr[le], arr[end - 1]);
    }

    return le;
}

void quickSort2Helper(std::vector<int> &arr, int begin, int end) {
    if (begin >= end)
        return;
    int par = partation2(arr, begin, end);
    quickSort2Helper(arr, begin, par - 1);
    quickSort2Helper(arr, par + 1, end);
}
void quickSort2(std::vector<int> &arr) {
    quickSort2Helper(arr, 0, arr.size() - 1);
}

int main() {
    std::vector<int> arr = {4, 2, 1, 1,  2,  1, 2, 4,  5,  6,  7,  3,   1,
                            9, 3, 1, 19, 92, 8, 3, 10, 29, 92, 82, 100, 12};
    std::vector<int> arr2(arr);
    quickSort1(arr);
    quickSort2(arr2);
    for (int i = 0; i < arr.size(); i++) {
        std::cout << arr[i] << " " << arr2[i] << '\n';
    }
}