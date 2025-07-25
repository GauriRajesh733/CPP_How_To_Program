// Chapter15_Notes.cpp

#include <iostream>
#include <iterator>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <list>
using namespace std;

template<typename Container> void pushIntElems(stack<int, Container>& stackRef);

template<typename T, typename Container> void popElems(stack<T, Container>& stackRef);

int main()
{
    // intro to containers

    // RECALL: templatized data structures
    // -> linked lists, stacks, queues, binary trees, deques, arrays, etc.

    // sequence containers represent LINEAR data structures
    // sequence and associative containers are FIRST-CLASS CONTAINERS

    // stack, que, priority_queue are CONTAINER ADAPTERS (view sequence container
    // in constrained manner)

    // common member functions: constructor, copy constructor, move constructor (move contents
    // to new container of same type and old container no longer has data, avoid overhead of copying),
    // destructor, empty, insert, size

    // intro to iterators

    // similar to pointers, they point to first class container elements
    // specific operations: ++ to move onto next elem, * to dereference iterator to use element 
    // it points to, etc.

    // ex. istream_iterator for input and ostream_iterator for output
    cout << "Enter 2 integers:" << endl;

    istream_iterator<int> inputInt{ cin };

    int number1{ *inputInt }; // dereference to read int value
    ++inputInt; // move iterator to next input value
    int number2{ *inputInt };

    ostream_iterator<int> outputInt{ cout };
    cout << "You entered the numbers:" << endl;
    *outputInt = number1;
    cout << endl;
    outputInt++;
    *outputInt = number2;
    cout << endl;

    // NOTE: iterators can fall into categories: input/output, forward, bidirectional, random access (most powerful)

    // intro to algorithms 

    // ex. inserting, deleting, searching, sorting, etc.(operate indirectly on 
    // container elems through iterators)

    // sequence containers

    // array, vector, deque, list, and forward_list (first 3 built on arrays; last 2 built on linked lists)
    // NOTE: vectors are most appropriate for appending but not for inserting in middle or at beginning
    //       since RECALL: vectors have contiguous memory locations
    // NOTE: deques are most appropriate if you frequently add to front and end
    // NOTE: lists are most appropriate if you frequently add to middle and/or extremes


    // ex. output vector contents with iterators
    
    // NOTE: loop continues as long as constIterator has NOT reached
    // end of vector
    vector<int> numbers {1, 2, 3, 4, 5};

    // NOTE: constant iterator used here
    for (auto const& num : numbers) {
        cout << num << " "; // dereferences constIterator to get element value
    }
    cout << endl;

    // ex. copy algorithm
    // NOTE: cbegin() and cend() are constant interators!
    //       cend() means past the end of the last element and cbegin
    //       points to first elem in container
    ostream_iterator<int> output{ cout, " " };
    copy(numbers.cbegin(), numbers.cend(), output);
    cout << endl;

    list<int> values;
    values.push_front(2);
    values.push_back(1);
    values.push_front(5);
    values.push_back(3);
    values.push_front(3);
    values.push_back(3);
    values.push_back(4);

    copy(values.cbegin(), values.cend(), output);
    cout << endl;

    values.sort();

    values.unique(); // remove duplicates

    copy(values.cbegin(), values.cend(), output);

    cout << endl;

    values.remove(3); // remove all instances of 3

    copy(values.cbegin(), values.cend(), output);
    cout << endl;

    // ex. RECALL: deques (NOTE: usually higher overhead than vector,
    // more efficient for insertions/deletions in middle than vector
    // but not as efficient as list)

    // associative containers
    // -> provide DIRECT ACCESS to store and retrive elements via KEYS (search keys)
    // -> multiset, set, multimap, and map (maintains keys in sorted order) 
    //    + 4 corresponding unordered associative containers
    // NOTE: multiset can store duplicate elements (efficiently access all values of key)
    // NOTE: duplicate keys allowed in multimap (one to many relationship)
    // NOTE: once again, if order doesn't matter you can use the unordered version
    
    // container adapters
    // -> stack, queue, priority_queue
    // not first class containers since no actual data structure implementation in which elems stored
    // and do not support iterators
    // push() and pop() supported


    // NOTE: while by default stacks are created based on deques,
    // can specify vector or list as well
    stack<int> intDequeStack;
    stack<int, vector<int>> intVectorStack;
    stack<int, list<int>> intListStack;

    pushIntElems(intDequeStack);
    pushIntElems(intVectorStack);
    pushIntElems(intListStack);

    popElems(intDequeStack);
    popElems(intVectorStack);
    popElems(intListStack);

   
    // RECALL: queues
    
    // RECALL: priority queues
    // -> enable insertions in sorted order into underlying data structure
    // -> by default elems stored in vector, inserted in priority order
    //    which is done using a heap (always maintains largest value or highest priority elem)

    priority_queue<double> priorities;

    priorities.push(3.2);
    priorities.push(-4.5);
    priorities.push(9.7);

    while (!priorities.empty()) {
        cout << priorities.top() << ' ';
        priorities.pop();
    }
    cout << endl;



    // bitset
    // -> useful for representing set of bit flags, fixed in size at compile time
    // -> alternative for bit manipulation (chapter 22)
    // -> ex. methods: flip, reset, set, count, any, all, etc.
}

template<typename Container>
void pushIntElems(stack<int, Container>& stackRef)
{
    for (int i = 0; i < 10; i++) {
        stackRef.push(i);
        cout << stackRef.top() << ' ';
    }
    cout << endl;
}

template<typename T, typename Container>
void popElems(stack<T, Container>& stackRef)
{
    while (!stackRef.empty()) {
        cout << stackRef.top() << ' ';
        stackRef.pop();
    }
    cout << endl;

}

