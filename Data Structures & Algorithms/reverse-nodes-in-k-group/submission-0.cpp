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
    ListNode* reverseKGroup(ListNode* head, int k) {

        if(head == nullptr || head->next == nullptr || k == 1)
            return head;

        vector<int> reqArray;

        ListNode* temp = head;

        while(temp != nullptr){
            reqArray.push_back(temp->val);
            temp = temp->next;
        }

        int n = reqArray.size();

        for(int i = 0; i + k <= n; i += k){

            int left = i;
            int right = i + k - 1;

            while(left < right){
                swap(reqArray[left], reqArray[right]);
                left++;
                right--;
            }
        }

        ListNode* dummy = new ListNode(-1);
        temp = dummy;

        for(int x : reqArray){
            temp->next = new ListNode(x);
            temp = temp->next;
        }

        return dummy->next;
    }
};