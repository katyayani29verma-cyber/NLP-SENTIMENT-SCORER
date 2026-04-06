#ifndef BUFFER_H
#define BUFFER_H

#include <string>
using namespace std;

class Buffer {
    char* data;

public:
    Buffer(string&& text);   // move semantics
    char* getData();
    ~Buffer();
};

#endif