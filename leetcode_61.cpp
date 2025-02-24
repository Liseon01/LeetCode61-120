class Solution {
    public:
        ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next || k == 0) return head;
    
        // Step 1: 리스트 길이 계산
        int length = 1;
        ListNode* tail = head;
        while (tail->next) {
            tail = tail->next;
            length++;
        }
    
        // Step 2: k를 최적화
        k = k % length;
        if (k == 0) return head; // 회전할 필요 없음
    
        // Step 3: 새로운 끝 노드를 찾기
        int newTailPos = length - k - 1;
        ListNode* newTail = head;
        for (int i = 0; i < newTailPos; i++) {
            newTail = newTail->next;
        }
    
        // Step 4: 리스트 회전
        ListNode* newHead = newTail->next;
        newTail->next = nullptr;
        tail->next = head; // 원래 tail이 새로운 head를 가리키도록 연결
    
        return newHead;
        }
    };