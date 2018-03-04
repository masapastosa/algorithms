#include <iostream>
#include <vector>

/*
 * Given a sorted array, remove the duplicates in-place such that each element appear only once and return the new
 * length.
 *
 * Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra
 * memory.
 */

int remove_dups(std::vector<int> &arr) {
    if (arr.size() == 0) {
        return 0;
    }

    int j = 0;
    for (int i = 1; i < arr.size(); i++) {
        if (arr[j] != arr[i]) arr[++j] = arr[i];
    }

    return j + 1;
}

int main() {
    std::vector<int> list = {1,1,1,2,3,3,4,4};
    int count = remove_dups(list);
    for (int i=0; i < count; i++) {
        std::cout << list[i] << " ";
    }
    std::cout << std::endl;
}
