/*
 * @Author: abcdlsj 
 * @Date: 2020-08-13 18:46:28 
 * @Last Modified by:   abcdlsj 
 * @Last Modified time: 2020-08-13 18:46:28 
 */

#include <vector>

// 冒泡排序
void bubbleSort(std::vector<int> &arr) {
  int n = arr.size();
  for (int i = 0; i < n - 1; i++) {
    for (int j = 0; j < n - i - 1; j++) {
      if (arr[j] > arr[j + 1]) {
        std::swap(arr[j], arr[j + 1]);
      }
    }
  }
}

