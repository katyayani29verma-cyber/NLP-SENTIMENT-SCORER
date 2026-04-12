#include "Buffer.h"
#include <cstring> // for strcpy

// --------------------------------------------------
// Constructor
// - Allocates memory dynamically
// - Copies text into char array
// --------------------------------------------------
Buffer::Buffer(string&& text) {
    // Allocate memory (+1 for null terminator '\0')
    data = new char[text.size() + 1];

    // Copy string content into char array
    strcpy(data, text.c_str());
}

// --------------------------------------------------
// Getter function
// - Returns pointer to stored data
// --------------------------------------------------
char* Buffer::getData() {
    return data;
}

// --------------------------------------------------
// Destructor
// - Frees dynamically allocated memory
// --------------------------------------------------
Buffer::~Buffer() {
    delete[] data;
}