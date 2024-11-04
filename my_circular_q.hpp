#include <vector>

template <typename T>
class my_circular_q{
public:
    size_t max_items = 0;  
    size_t overrun = 0;
    typename std::vector<T>::size_type _head;
    typename std::vector<T>::size_type _tail;
    std::vector<T> _v;

    using value_type = T;

    my_circular_q() = default;

    explicit my_circular_q(size_t max_items)
        : max_items(max_items + 1),
          _v(max_items) {}
    
    void push_back(T &&item){
        if (max_items > 0){
            _v[_tail] = std::move(item);
            _tail = (_tail + 1) % max_items;

            if (_tail == _head)
            {
                _head = (_head + 1) % max_items;
                overrun = overrun + 1;
            }
        }
    }
    T& front(){
        return _v[_head];
    }

    const T& front() const {
        return _v[_head];
    }

    void pop_front(){
        _head = (_head + 1) % max_items; 
    }
};
