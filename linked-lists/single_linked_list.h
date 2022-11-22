#ifndef SINGLE_LINKED_LIST
#define SINGLE_LINKED_LIST

#include "iterator.h"

template<typename T>
class List{
    public:
        using value_type = T;
        using reference = value_type&;
        using const_reference = value_type const &;
        using iterator = Iterator<List>;

        List()
            : head(nullptr)
            , tail(nullptr){}

        ~List(){
            Node* temporary = new Node;
            Node* node = head;
            while(node != nullptr){
                temporary = node;
                node = node->next;
                delete temporary;
            }
        }

        iterator begin() const {return head;}
        iterator end() const {return tail->next;}

        void append(const_reference value){
            Node* node = new Node{value,nullptr};

            if(head == nullptr){
                head = node;
                return;
            }

            if(tail == nullptr){
                tail = node;
                head->next = tail;
                return;
            }

            tail->next = node;
            Node* temporary = node;
            node = tail;
            tail = temporary;
        }
    
        struct Node{
            value_type value;
            Node* next;
        };

    private:
        Node* head;
        Node* tail;
};

template<typename T>
void print(const List<T>& list){
    for(auto element : list){
        std::cout << element << '-';
    }
}

#endif