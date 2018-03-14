#include <iostream>

/*
 * You are given two non-empty linked lists representing two non-negative integers.
 * The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.
 * 
 * You may assume the two numbers do not contain any leading zero, except the number 0 itself.
 */

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* add_two_numbers(ListNode* L1, ListNode* L2) {
    int curr_mul = 1;
    int first_num = 0;
    ListNode *tmp = L1;
    while (tmp) {
        first_num += tmp->val * curr_mul;
        curr_mul *= 10;
        tmp = tmp->next;
    }

    std::cout << "First number: " << first_num << std::endl;

    curr_mul = 1;
    int second_num = 0;
    tmp = L2;
    while (tmp) {
        second_num += tmp->val * curr_mul;
        curr_mul *= 10;
        tmp = tmp->next;
    }

    std::cout << "Second number: " << second_num << std::endl;

    int final_num = first_num + second_num;

    std::cout << "Returning: " << final_num << std::endl;

    int curr_num = final_num;

    if (!curr_num) {
        return new ListNode(0);
    }

    ListNode *prev_node = NULL;
    ListNode *curr_node = NULL;

    // First iteration outside to save return node
    int curr_digit = curr_num % 10;
    curr_node = new ListNode(curr_digit);
    prev_node = curr_node;
    curr_num /= 10;

    ListNode *ret_node = curr_node;

    while (curr_num) {
        int curr_digit = curr_num % 10;
        curr_node = new ListNode(curr_digit);
        prev_node->next = curr_node;
        prev_node = curr_node;

        curr_num /= 10;
    }

    return ret_node;
}

int main() {
    ListNode l00(2), l01(4), l02(3);
    ListNode l10(5), l11(6), l12(4);

    l00.next = &l01;
    l01.next = &l02;

    l10.next = &l11;
    //l11.next = &l12;

    ListNode *res = add_two_numbers(&l00, &l10);

    std::cout << "Res: (";
    while (res) {
        std::cout << res->val << " ->";
        ListNode *tmp = res->next;
        delete res;
        res = tmp;
    }
    std::cout << ")" << std::endl;
}
