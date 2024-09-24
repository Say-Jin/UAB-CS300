#ifndef deque_h
#define deque_h

class Deque {
    private: 
        struct Node {
            int val;
            Node *nextNode;
            Node *previousNode;
            Node(int cVal);
        };
    
        Node *topOfQueue;
        Node*bottomOfQueue;

    public:
        Deque();
        // Getters
        Node *getTopOfQueue();
        Node *getBottomOfQueue();
        // Setters
        void setTopOfQueue(Node *n);
        void setBottomOfQueue(Node *n);

        // adds to the front of the queue
        void push_front(int i);
        // adds to the back of the queue
        void push_back(int i);
        // deletes the front value in the queue
        int pop_front();
        // deletes the back value in the queue
        int pop_back();
        // returns the value at the front queue
        int peak_front();
        // returns the value at the back of the queue
        int peak_back();
        // deletes all of the values in the queue
        void remove_all();

        ~Deque();
};


#endif