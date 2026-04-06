#include "Buffer.h"
#include <cstring>

Buffer::Buffer(string&& text) {
    data = new char[text.size() + 1];
    strcpy(data, text.c_str());
}

char* Buffer::getData() {
    return data;
}

Buffer::~Buffer() {
    delete[] data;
}