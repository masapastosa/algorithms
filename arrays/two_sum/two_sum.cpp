#include <iostream>
#include <vector>
#include <unordered_map>

/*
 * Given an array of integers, return indices of the two numbers such that they add up to a specific target.
 *
 * You may assume that each input would have exactly one solution, and you may not use the same element twice.
 */

std::vector<int> two_numbers(std::vector<int> &arr, int target) {
    bool found = false;
    std::unordered_map<int, int> indexes;
    std::vector<int> ret;

    std::vector<int>::iterator it;
    int i;
    for(i = 0, it = arr.begin(); it != arr.end(); it++, i++) {
        int diff = target - (*it);
        auto index = indexes.find(diff);
        if (index != indexes.end()) {
            // Element exists in the map
            ret.push_back(index->second);
            ret.push_back(i);
            found = true;
            break;
        } else {
            indexes[*it] = i;
        }
    }

    if (!found) {
        std::cout << "Solution not found" << std::endl;
    }

    return ret;
}

int main() {
    std::vector<int> nums = {2, 7, 11, 15};
    int target = 9;
    auto ret = two_numbers(nums, target);
    for (auto it = ret.begin(); it != ret.end(); it++) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}
