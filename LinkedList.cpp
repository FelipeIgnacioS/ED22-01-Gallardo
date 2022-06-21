#include "LinkedList.hpp"

LinkedList::LinkedList(Node node){
    first = node;
}
bool LinkedList::empty(){
    if(first == nullptr) return true;
    return false;
}

int LinkedList::size(){
    int i=0;
    while(first-> next !=nullptr){
        first = first->next;
    }
    return i;
}