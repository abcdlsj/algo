#include "../utils/heap.h"

int main() {
    vector<int> arr = {1, 3, 5, 4, 6, 13, 10, 9, 8, 15, 17};
    heapSort(arr);
    print(arr);
}