
# Logging Functionality

This is used to send error/debug messages to the standard error stream (`std::cerr`). 

The implementation of this is in this way because it was done for learning and experimenting with interfaces, abstract and base classes, state machines etc. 
Obviously, given the use of the functionality, it will be much more simpler (and faster) to just encapsulate the stream output part under a general function. 
Something like the following:

```cpp
void LOGGING::logMessage(std::string message) {
#ifdef DEBUG
  std::cerr << "[ DEBUG ]: " << message << std::endl;
#endif
  return;
}
```
