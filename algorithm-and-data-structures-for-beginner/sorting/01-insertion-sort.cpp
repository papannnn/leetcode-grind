#include <iostream>
#include <vector>

int main () {
    std::vector<int> arr{9, 8, 7, 6, 5, 4, 3, 2, 1};

    for (int i = 1; i < arr.size(); i++) {
        int j = i;
        while (j && arr[j] < arr[j - 1]) {
            std::swap(arr[j], arr[j - 1]);
            j--;
        }
    }

    for (const int& n : arr) {
        std::cout << n << " ";
    }
    std::cout << std::endl;
}