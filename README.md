# Doubly-Linked-List
in This ADT Insertion and deletion are more efficient at both ends and in the middle because both the previous and next nodes are easily accessible.
More complex to implement and maintain due to the additional pointer. 
Can be easily reversed due to the backward pointers. 
Can be traversed in both directions (forward and backward). 
Uses more memory because each node has two pointers (next and previous). 
Time Complexity (for insertions/deletions at arbitrary positions): O(1) for insertion/deletion at both ends, O(n) for middle position (but with easier access due to both pointers).
