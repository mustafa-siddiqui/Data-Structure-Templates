# Data-Structure-Templates
Simple data structure templates written using modern c++.

Made as a learning project to learn and implement modern C++ functionalities including but not limited to template classes, move semantics, smart pointers, OOP concepts like class relations, and design principles.

### Latest Progress

Node ID assignment seems to be fine. Could be implemented in a more robust and better way, but this is fine for our purposes.

Verifying LinkedList.deleteNode() method. Currently, the references to prev and next nodes in the headPtr and tailPtr cases are not being cleared by reset(). One is still able to access the nodes those pointers point to. Also cannot use setPrevNodePtr() or setNextNodePtr() with nullptr as a parameter -> results in a compilation error.

### To-do

[ ] Verify LinkedList.deleteNode()  
[ ] Implement LinkedList.find()  
[ ] Implement LinkedList.insertBefore()  
[ ] Implement LinkedList.insertAfter()  
