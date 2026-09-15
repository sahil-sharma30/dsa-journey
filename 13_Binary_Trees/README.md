## General Tree to Binary Tree Conversion
**Method:** Left-Child Right-Sibling (LCRS) Representation

To convert any General Tree (where nodes can have N children) into a strict Binary Tree, apply these two rules:

1. **Left Child = The Firstborn:** The oldest (leftmost) child of a node becomes its left child in the binary tree.
2. **Right Child = The Sibling:** All subsequent children of that same parent are disconnected from the parent and attached to the right side of their immediate older sibling, forming a chain.

**The Trade-off (Search vs. Memory):**
While this conversion degrades search efficiency (chaining siblings creates a right-leaning linked list, pushing search times toward `O(n)`), it is necessary for memory survival. It forces chaotic, unpredictable trees into a strictly controlled 2-pointer (`left` and `right`) system, preventing massive heap memory waste in C++.