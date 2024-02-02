//
// Created by Henrique Pagnossi on 2024-01-30.
//
#pragma once

#include "bn_array.h"
#include "bn_unique_ptr.h"
#include "bn_common.h"
#include "graph_node.h"

namespace dl {
template<typename T>
class PriorityQueue {
public:
    PriorityQueue() {
        _size = 0;
    }
    void push(T element) {
        _elements[_size] = element;
        _size++;
        int i = _size - 1;
        while (i > 0 && _elements[i] < _elements[((i - 1) / 2)]) {
            T temp = _elements[i];
            _elements[i] = _elements[(i - 1) / 2];
            _elements[(i - 1) / 2] = temp;
            i = (i - 1) / 2;
        }
    }
    T pop() {
        T result = _elements[0];
        _elements[0] = _elements[_size - 1];
        _size--;
        return result;
    }
    T top() {
        return _elements[0];
    }
    bool empty() {
        return _size == 0;
    }
    int size() {
        return _size;
    }
private:
    int _size;
    bn::array<T,25> _elements;
};
}