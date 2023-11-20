#ifndef NODE_H
#define NODE_H

#endif // NODE_H

namespace VN{
template<class T>
class Node{
public:

    Node<T>* next;
    Node<T>* prev;
    T dado;

    Node(const T dado): dado(dado), next(nullptr) {};




};

}
