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
class Solution
{
public:
    bool isPalindrome(ListNode *head)
    {
        vector<int> nums;
        while (head != NULL)
        {
            nums.push_back(head->val);
            head = head->next;
        }

        if (nums.size() == 1)
        {
            return true;
        }
        int r = 0;
        int left = nums.size() - 1;
        while (r < left)
        {

            if (nums[r] == nums[left])
            {

                r++;
                left--;
                // return true;
            }
            else
            {
                return false;
            }
        }

        return true;
    }
};








// /**
//  * Definition for singly-linked list.
//  * struct ListNode {
//  *     int val;
//  *     ListNode *next;
//  *     ListNode() : val(0), next(nullptr) {}
//  *     ListNode(int x) : val(x), next(nullptr) {}
//  *     ListNode(int x, ListNode *next) : val(x), next(next) {}
//  * };
//  */
// class Solution {
// public:
    
//     ListNode* findmid(ListNode* head){
//         ListNode* slow = head;
//         ListNode* fast = head;
//         while(fast!=NULL && fast->next!=NULL){
//             slow = slow->next;
//             fast = fast->next->next;
//         }
        
//         return slow;
//     }
    
//     ListNode* reverse(ListNode* head){
//         ListNode* prev=NULL,*curr=head,*nex=NULL;
//         while(curr!=NULL){
//             nex = curr->next;
//             curr->next = prev;
//             prev = curr;
//             curr=nex;
//         }
        
//         return prev;
//     }
    
//     bool compareLL(ListNode* h,ListNode* h2){
//         while(h!=NULL && h2!=NULL){
//             if(h->val != h2->val){
//                 return false;
//             }
//             h = h->next;
//             h2 = h2->next;
//         }
//         return true;
//     }
    
    
    
//     bool isPalindrome(ListNode* head) {
//         ListNode* h = head;
//         ListNode* mid = findmid(h);
//         ListNode* h2 = reverse(mid);
        
//         return compareLL(h,h2);
//     }
// };