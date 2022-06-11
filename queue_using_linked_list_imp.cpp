#include "queue_using_linked_list.h"
#include <iostream>
// Node::Node()
// {
// }
Queue::Queue()
{
    // this->head = NULL;
    // this->tail = NULL;
}
void Node::setData(int val)
{
    this->data = val;
}
void Node::setNext()
{
    this->next = NULL;
}
// Node *Queue::createNode(int val)
// {
//     Node *newNode = new Node();
//     newNode->setData(val);
//     newNode->setNext();
//     return newNode;
// }
// int Node::getData() { return this->data; }
// void Queue::enqueue(int val)
// {
//     Node *newNode = createNode(val);
//     if (this->head == NULL)
//     {
//         this->head = this->tail = newNode;
//     }
// }
// void Queue::display()
// {
//     std::cout << head->getData() << std::endl;
// }