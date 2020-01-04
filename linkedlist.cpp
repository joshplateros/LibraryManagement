#include "linkedlist.h"

template<class ItemType>
void Node<ItemType>::setItem(const ItemType & anItem)
{
    m_item = anItem;
} 
template<class ItemType>
void Node<ItemType>::setNext(Node<ItemType> *newNodePtr)
{
    m_next = newNodePtr;    
}

template<class ItemType>
bool List<ItemType>::addItem(const ItemType & anEntry)
{
    Node<ItemType> *newNodePtr = new Node<ItemType>();
    newNodePtr -> setItem(anEntry);
    newNodePtr -> m_next(NULL);
        
}
