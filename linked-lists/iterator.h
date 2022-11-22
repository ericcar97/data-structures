#ifndef ITERATOR_H
#define ITERATOR_H

template<class List>
class Iterator{
    public:
        using value_type = typename List::value_type;
        using reference = value_type&;
        using pointer = typename List::Node*;
        using self = Iterator<List>;

        Iterator() : address_(nullptr) {};
        Iterator(pointer address) : address_(address){};

        self& operator ++(){
            address_ = address_->next;
            return *this;
        }

        self operator ++(int) {
            self copy = *this;
            address_ = address_->next;
            return *this;
        }

        pointer operator->(){
            return address_;
        }

        reference operator*(){
            return address_->value;
        }

        friend bool operator == (const Iterator& lhs, const Iterator& rhs){
            return rhs.address_ == lhs.address_;
        }

        friend bool operator != (const Iterator& lhs, const Iterator& rhs){
            return !(rhs.address_ == lhs.address_);
        }

    private:
        pointer address_;
};

#endif