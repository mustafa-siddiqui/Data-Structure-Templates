# Data-Structure-Templates
Simple data structure templates written using modern c++.

Made as a learning project to learn and implement modern C++ functionalities including but not limited to template classes, move semantics, smart pointers, OOP concepts like class relations, and design principles.

### Latest Progress

Node ID assignment seems to be fine. Could be implemented in a more robust and better way, but this is fine for our purposes.

Verifying `LinkedList.deleteNode()` method. Currently, the references to prev and next nodes in the `headPtr` and `tailPtr` cases are not being cleared by `reset()`. One is still able to access the nodes those pointers point to. Also cannot use `setPrevNodePtr()` or `setNextNodePtr()` with `nullptr` as a parameter -> results in a compilation error.

### To-do

- [ ] Verify `LinkedList.deleteNode()`
- [ ] Implement `LinkedList.find()`
- [ ] Implement `LinkedList.insertBefore()`
- [ ] Implement `LinkedList.insertAfter()`

### Known Limitations

Cannot create a `shared_ptr` to node object by using `make_shared<>()` from an already existing node object and pass it into LinkedList methods as an argument. The node objects referred to by the two pointers will be different. This is because `make_shared<>()` performs a constructor call and even though the values stored in the node objects are the same, the IDs won't be (probably due to the id mechanism implemented). To work around this, call `make_shared<>()` inside the method call and provide node value there. When needing to reference a node in the list, use `LinkedList.find()` and use the `shared_ptr` returned.

For example, you make a node object `node1` with value 10 & id 1. You create a shared pointer to it by using `make_shared<>(node1)` and call `LinkedList.insertFirst()`. Then you call `make_shared<>(node1)` again and call `LinkedList.deleteNode()`. You'll notice that the node will not be deleted and in the code you come across the part where the node to be deleted is not found in the list. You would think that the two `shared_ptr`s would point to the same object but they don't because perhaps the id of the node in the list is changed. Even if the id is the same, it still doesn't consider them as the same object and the two pointers are pointing to different objects in the end. 
