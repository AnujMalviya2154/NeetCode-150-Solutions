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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<int> combinedList;
        for(int i = 0; i < lists.size(); i++) {
            ListNode* temp = lists[i];
            while(temp != nullptr) {
                combinedList.push_back(temp->val);
                temp = temp->next;
            }
        }
        sort(combinedList.begin(),combinedList.end());
        ListNode* dummy = new ListNode(-1);
        ListNode* temp = dummy;
        for(int i=0;i<combinedList.size();i++){
            temp->next = new ListNode(combinedList[i]);
            temp = temp->next;
        }
        return dummy->next;
        
    }
};
