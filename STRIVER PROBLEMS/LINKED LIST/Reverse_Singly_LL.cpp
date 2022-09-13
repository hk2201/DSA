// *
//  * Definition for singly-linked list.
//  * struct ListNode {
//  *     int val;
//  *     ListNode *next;
//  *     ListNode() : val(0), next(nullptr) {}
//  *     ListNode(int x) : val(x), next(nullptr) {}
//  *     ListNode(int x, ListNode *next) : val(x), next(next) {}
//  * };

class Solution
{
public:
    ListNode *reverseList(ListNode *head)
    {
        ListNode *ptr = head;
        vector<int> ans;
        while (ptr != NULL)
        {
            ans.push_back(ptr->val);
            ptr = ptr->next;
        }
        reverse(ans.begin(), ans.end());

        ListNode *p1 = head;
        // p1->val = ans[0];
        int i = 0;

        while (p1 != NULL)
        {
            p1->val = ans[i];
            p1 = p1->next;

            i++;
        }
        return head;
    }

    // ListNode* reverseList(ListNode* head) {
    //     ListNode* newnode = NULL;
    //     while(head!=NULL){
    //         ListNode* next = head->next;
    //         head->next = newnode;
    //         newnode = head;
    //         head = next;
    //     }
    //     return newnode;
    // }
};