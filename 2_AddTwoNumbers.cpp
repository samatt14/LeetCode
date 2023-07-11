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
        ListNode* output = nullptr;

        int carryOver = 0;

        ListNode* currNode;

        while(l1 != nullptr || l2 != nullptr){
            int val1;
            int val2; 

            if(l1 == nullptr){
                val1 = 0;
            }
            else{
                val1 = l1->val;
            }

            if(l2 == nullptr){
                val2 = 0;
            }
            else{
                val2 = l2->val;
            }

            int result = val1 + val2 + carryOver;
            
            ListNode* tmp = new ListNode(result%10);
            
            if(output == nullptr){
                output = tmp;
                currNode = tmp;
            }
            else{
                currNode->next = tmp;
                currNode = currNode->next;
            }
            
            carryOver = result/10;

            if(l1 != nullptr){
                l1 = l1->next;
            }
            if(l2 != nullptr){
                l2 = l2->next;
            }
        }

        if(carryOver != 0){
            ListNode* tmp = new ListNode(carryOver);
            
            if(output == nullptr){
                output = tmp;
            }
            else{
                currNode->next = tmp;
            }
        }

        return output;
    }
};
