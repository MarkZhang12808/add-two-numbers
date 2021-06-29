/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* out = new ListNode();
        int carry = 0;
        ListNode* temp1 = l1;
        ListNode* temp2 = l2;
        ListNode* tempOut = out;
        while(1){
            int newValue = 0;
            if(temp1 == nullptr && temp2 != nullptr){
                newValue = temp2->val + carry;
            }
            else if(temp1 != nullptr && temp2 == nullptr){
                newValue = temp1->val + carry;
            }
            else{
                newValue = temp1->val + temp2->val + carry;
            }
            carry = 0;
            if(newValue > 9){
                carry = 1;
                newValue = newValue - 10;
            }
            tempOut->val = newValue;
            if(temp1->next != nullptr || temp2->next != nullptr){
                tempOut->next = new ListNode();
                tempOut = tempOut->next;
                if(temp1->next == nullptr) temp1->next = new ListNode();
                temp1 = temp1->next;
                if(temp2->next == nullptr) temp2->next = new ListNode();
                temp2 = temp2->next;
            }
            else{
                if(carry != 0){
                tempOut->next = new ListNode(1);
                }
                break;
            }
        }
        return out;
    }
};
