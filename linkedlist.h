#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include<iostream>

template<class ItemType>
class Node;

template<class ItemType>
class List;


template<class ItemType>
class Node
{
    friend class List<ItemType>;
    public:
    Node() : m_next(NULL) {}
    Node(const ItemType & anItem) : m_item(anItem), m_next(NULL) {}
    Node(const ItemType & anItem, Node<ItemType> *nextNodePtr) : m_item(anItem), m_next(nextNodePtr) {}

    void setItem(const ItemType & anItem);
    void setNext(Node<ItemType> *nextNodePtr);
    ItemType getItem() const;
    



    private:
    int m_item;
    int m_next;
};
template<class ItemType>
class List
{
    public:
    List() {}
    
    bool addItem(const ItemType & anEntry);

    private:
    Node<ItemType> *pfirst;

};


#endif //LINKEDLIST_H