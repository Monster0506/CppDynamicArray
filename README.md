# C++ Dynamic Array Implementation
This is a quick implementation of a dynamically resizing array in C++. It was built to understand a bit more clearly how containers in STL work internally. 

This class manages raw memory allocation with `::operator new`, object construction via placement new, manual destruction of elements, and geometric resizing.

Dynamic growth is handled by allocating new storage, move-constructing existing elements,and freeing old space.

Eventually, I will implement many more of the STL container API.
