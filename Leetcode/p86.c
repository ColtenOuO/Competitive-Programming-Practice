/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* partition(struct ListNode* head, int x){
    struct ListNode *l , *r;

    l = (struct ListNode*)calloc(1,sizeof(struct ListNode));
    r = (struct ListNode*)calloc(1,sizeof(struct ListNode));

    struct ListNode* head_l = l;
    struct ListNode* head_r = r;
        while( head != NULL )
        {
            if( head -> val < x )
            {
                struct ListNode* new_node = (struct ListNode*)malloc(sizeof(struct ListNode));
                new_node -> val = head -> val;
                new_node -> next = NULL;
                l -> next = new_node;
                head = ( head -> next );

                l = ( l -> next );
            }
            else
            {
                struct ListNode* new_node = (struct ListNode*)malloc(sizeof(struct ListNode));
                new_node -> next = NULL;
                new_node -> val = head -> val;
                r -> next = new_node;
                head = ( head -> next );

                r = ( r -> next );
            }
        }

        struct ListNode* ans = NULL;
        struct ListNode* ptr = head_l -> next;
        struct ListNode* ans_head = NULL;
        while( ptr != NULL )
        {
            struct ListNode* new_node = (struct ListNode*)malloc(sizeof(struct ListNode));           
            new_node -> next = NULL;
            if( ans != NULL ) ans -> next = new_node;
            else ans_head = new_node;
            ans = new_node;
            (ans -> val) = (ptr -> val);
            ptr = ( ptr -> next );
        } 
        ptr = head_r -> next;
        while( ptr != NULL )
        {
            struct ListNode* new_node = (struct ListNode*)malloc(sizeof(struct ListNode));
            new_node -> next = NULL;
            if( ans != NULL ) ans -> next = new_node;
            else ans_head = new_node;
            ans = new_node;
            (ans -> val) = (ptr -> val);
            printf("%d\n",ptr -> val);

            ptr = ( ptr -> next );
        }

        return ans_head;
}