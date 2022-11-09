#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

#include <vector>
#include <memory>
#include <string>

namespace binary_search_tree {

template <typename T> class binary_tree {
private:
    T m_rootData;
    binary_tree* m_parentNode;
    binary_tree* m_previous;
    binary_tree* m_next;
    std::unique_ptr<binary_tree> m_leftTreePtr;
    std::unique_ptr<binary_tree> m_rightTreePtr;

public:
    class Iterator {
    private:
        binary_tree* m_currPos;

    public:
        Iterator() : Iterator(nullptr) {}
        Iterator(binary_tree* nodePtr) {
            m_currPos = nodePtr;
        }

        const T& operator *() const { return m_currPos->m_rootData; }
        Iterator& operator++ () { m_currPos = m_currPos->m_next; return *this; }
        bool operator == (const Iterator& rhs) const { return(m_currPos == rhs.m_currPos); }
        bool operator != (const Iterator& rhs) const { return(m_currPos != rhs.m_currPos); }

    };
    
    binary_tree(const T& inputData) : m_rootData(inputData), m_parentNode(nullptr), m_previous(nullptr), m_next(nullptr), m_leftTreePtr(nullptr), m_rightTreePtr(nullptr) {}
    
    void insert(const T& inputData) {
        binary_tree* parentNode;
        binary_tree* currentNode = this;
        bool isLeft{ false };

        while (currentNode != nullptr) {
            parentNode = currentNode;

            if (inputData > currentNode->m_rootData) {
                currentNode = currentNode->m_rightTreePtr.get();
                isLeft = false;
            }
            else {
                currentNode = currentNode->m_leftTreePtr.get();
                isLeft = true;
            }
        }

        if (isLeft) {
            parentNode->m_leftTreePtr = std::unique_ptr<binary_tree>(new binary_tree(inputData));
            currentNode = parentNode->m_leftTreePtr.get();

            currentNode->m_parentNode = parentNode;

            currentNode->m_next = currentNode->m_parentNode;
            currentNode->m_parentNode->m_previous = currentNode;

            binary_tree* parentparentNode = currentNode->m_parentNode->m_parentNode;
            
            if (parentparentNode != nullptr && 
            parentparentNode->m_rightTreePtr != nullptr && 
            parentparentNode->m_rightTreePtr.get() == currentNode->m_parentNode) {
                currentNode->m_previous = parentparentNode;
                parentparentNode->m_next = currentNode;
            }
            else if (parentparentNode != nullptr && 
            parentparentNode->m_leftTreePtr != nullptr && 
            parentparentNode->m_leftTreePtr.get() == currentNode->m_parentNode) {
                binary_tree* tempNode{ currentNode };
                
                while (tempNode->m_parentNode->m_parentNode != nullptr && 
                tempNode->m_parentNode->m_parentNode->m_leftTreePtr != nullptr &&
                tempNode->m_parentNode->m_parentNode->m_leftTreePtr.get() == tempNode->m_parentNode) {
                    tempNode = tempNode->m_parentNode;
                }

                if (tempNode->m_parentNode->m_parentNode != nullptr) {
                    currentNode->m_previous = tempNode->m_parentNode->m_parentNode;
                    tempNode->m_parentNode->m_parentNode->m_next = currentNode;
                }
                else {
                    currentNode->m_previous = nullptr;
                    currentNode->m_parentNode->m_next = currentNode;
                }
            }
        }
        else {
            parentNode->m_rightTreePtr = std::unique_ptr<binary_tree>(new binary_tree(inputData));
            currentNode = parentNode->m_rightTreePtr.get();

            currentNode->m_parentNode = parentNode;

            currentNode->m_previous = currentNode->m_parentNode;
            currentNode->m_parentNode->m_next = currentNode;

            binary_tree* parentparentNode = currentNode->m_parentNode->m_parentNode;
            
            if (parentparentNode != nullptr && 
            parentparentNode->m_leftTreePtr != nullptr && 
            parentparentNode->m_leftTreePtr.get() == currentNode->m_parentNode) {
                currentNode->m_next = parentparentNode;
                parentparentNode->m_previous = currentNode;
            }
            else if (parentparentNode != nullptr && 
            parentparentNode->m_rightTreePtr != nullptr && 
            parentparentNode->m_rightTreePtr.get() == currentNode->m_parentNode) {
                binary_tree* tempNode{ currentNode };
                
                while (tempNode->m_parentNode->m_parentNode != nullptr && 
                tempNode->m_parentNode->m_parentNode->m_rightTreePtr != nullptr &&
                tempNode->m_parentNode->m_parentNode->m_rightTreePtr.get() == tempNode->m_parentNode) {
                    tempNode = tempNode->m_parentNode;
                }

                if (tempNode->m_parentNode->m_parentNode != nullptr) {
                    currentNode->m_next = tempNode->m_parentNode->m_parentNode;
                    tempNode->m_parentNode->m_parentNode->m_previous = currentNode;
                }
                else {
                    currentNode->m_next = nullptr;
                    currentNode->m_parentNode->m_previous = currentNode;
                }
            }
        }
    }

    T& data() { return m_rootData; }
    std::unique_ptr<binary_tree<T>>& left() { return m_leftTreePtr; }
    std::unique_ptr<binary_tree<T>>& right() { return m_rightTreePtr; }

    Iterator begin() {
        binary_tree* current = this;

        while (current->m_previous != nullptr) {
            current = current->m_previous;
        }

        return Iterator(current);
    }

    Iterator end() {
        return Iterator();
    }
};

}

#endif