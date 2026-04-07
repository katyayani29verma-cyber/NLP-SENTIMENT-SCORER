#ifndef BUFFER_H
#define BUFFER_H

#include <string>
using namespace std;

// --------------------------------------------------
// Buffer Class
// Purpose:
// - Stores text using Dynamic Memory Allocation (DMA)
// - Demonstrates move semantics
// --------------------------------------------------
class Buffer {
    char* data;   // pointer to dynamically allocated memory

public:
    // Constructor using move semantics
    // Takes rvalue string to avoid unnecessary copying
    Buffer(string&& text);

    // Returns stored data
    char* getData();

    // Destructor to free memory
    ~Buffer();
};

#endif