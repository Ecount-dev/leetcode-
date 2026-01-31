class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* dummyHead = new ListNode(0); // 设置一个虚拟头结点
        virtualHead->next = head; // 将虚拟头结点指向head，这样方便后面做删除操作
		ListNode* cur = virtualHead;    // 使用cur指针遍历链表
        while (cur->next != NULL) {
			if (cur->next->val == val) {    // 找到需要删除的节点
                ListNode* tmp = cur->next;
                cur->next = cur->next->next;
                delete tmp;
            }
            else {
                cur = cur->next;
            }
        }
		head = virtualHead->next;       // 更新head指针
        delete virtualHead;
        return head;
    }
};