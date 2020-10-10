#include "IndexBuffer.h"

#include "Renderer.h"

IndexBuffer::IndexBuffer(const unsigned int* data, unsigned int count)
    : _count(count)
{
    glCall(glGenBuffers(1, &_rendererId));
    glCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _rendererId));
    glCall(glBufferData(GL_ELEMENT_ARRAY_BUFFER, count * sizeof(unsigned int), data, GL_STATIC_DRAW));
}

IndexBuffer::~IndexBuffer() {
    glCall(glDeleteBuffers(1, &_rendererId));
}

void IndexBuffer::bind() const {
    glCall(glBindBuffer(GL_ARRAY_BUFFER, _rendererId));
}

void IndexBuffer::unbind() const {
    glCall(glBindBuffer(GL_ARRAY_BUFFER, 0));
}
