#include <string>
#include <stack>

class HeapNode
{
        int val;
        HeapNode * left, * right;
        int size; // number of nodes in this subtree

    public:

        HeapNode(int v) : val(v), left(nullptr), right(nullptr), size(1) {}

        HeapNode(const HeapNode &) = delete;
        ~HeapNode() { delete left; delete right; }

        std::string str() const { return std::to_string(val); }
        std::string edges() const;

        bool empty() const { return size == 1; }

        void valid() const;

        void push(int x);
        int pop();

        // helper function
        void heapify();

        //iterator

        class ListIterator   //https://www.internalpointers.com/post/writing-custom-iterators-modern-cpp
    {
        //Iterator Tags
        using iterator_category = std::forward_iterator_tag;
        using difference_type   = std::ptrdiff_t;
        using value_type        = HeapNode;
        using pointer           = value_type*;  // or also value_type*
        using reference         = HeapNode&;  //reference returns payload of Node 

        private:
            pointer m_ptr;
            stack<HeapNode*> myStack;
        public:
        ListIterator(pointer ptr) : m_ptr(ptr){}
          reference operator*() const { return *m_ptr; }
                 
        pointer operator->() { return m_ptr; }

        // Prefix increment
        ListIterator& operator++() { 
            if(m_ptr->left == nullptr && m_ptr->right == nullptr){
                myStack.pop();
                return *this;
            }

            if(m_ptr->left != nullptr){
                
                myStack.push((m_ptr->left));
                m_ptr = m_ptr->left;
                ++(*this);
            }
            else if(m_ptr->right != nullptr){

                myStack.pop();
                myStack.push((m_ptr->right));
                m_ptr = m_ptr->right;
                ++(*this);
            }

        }  

        // Postfix increment
        ListIterator operator++(int) { ListIterator tmp = *this; ++(*this); return tmp; }

        friend bool operator== (const ListIterator& a, const ListIterator& b) { return a.m_ptr == b.m_ptr; };
        friend bool operator!= (const ListIterator& a, const ListIterator& b) { return a.m_ptr != b.m_ptr; };
        

    };


    ListIterator begin() {return ListIterator(this);}
    ListIterator end() {return ListIterator(NULL);}
};

inline std::string HeapNode::edges() const
{
    std::string r;

    if (left) r += str() + " --> " + left->str() + '\n';
    if (right) r += str() + " --> " + right->str() + '\n';

    if (left) r += left->edges();
    if (right) r += right->edges();

    return r;
}

inline void HeapNode::valid() const
{
    if ( left && val > left->val || right && val > right->val )
        throw "Heap invalid at node " + std::to_string(val);
    if (left) left->valid();
    if (right) right->valid();
}


