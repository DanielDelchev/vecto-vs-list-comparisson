#ifndef LISTTESTER_H_INCLUDED
#define LISTTESTER_H_INCLUDED
#include <list>
#include <iterator>
class ListTester{

public:
    ListTester(size_t count = 0);//O(n)
    ListTester(const ListTester& other)=default;
    ListTester& operator=(const ListTester& other)=default;
    virtual ~ListTester();

    void clear(); /** O(n) */
    void push_back(int x); /** O(1) constant */
    void pop_back(); /** O(1) constant */

    void push_front(int x); /** O(1) constant */
    void pop_front(); /** O(1) constant  */

    void insertAt(size_t position, int x);/**< O(1)  if we have an iterator to the position ,O(n) otherwise*/
    void removeAt(size_t position);/**< O(1) if we have an iterator to the position, O(n) otherwise*/

    void insertAt(std::list<int> :: iterator it, int x);/**< O(1) */
    void removeAt(std::list<int> :: iterator it);/**< O(1) */


    size_t size()const;/** O(1) */
    bool empty()const;/** O(1) */


    //iterators O(1)
    /** we can only directly access front and back of the list */
    std::list<int> :: iterator begin();
    std::list<int> :: iterator end();
    std::list<int> :: reverse_iterator rbegin();
    std::list<int> :: reverse_iterator  rend();
    std::list<int> :: const_iterator cbegin()const;
    std::list<int> :: const_iterator cend()const;
    std::list<int> :: const_reverse_iterator crbegin()const;
    std::list<int> :: const_reverse_iterator  crend()const;

    void printContent()const; /* O(n) */

    // O(n*log(n))
    void sort();/** sorts the container using the sort function provided for list from stl */

    int* findElement(int x);//O(n)

    // THETE IS NO IMPLEMENTATION OF THE FOLLOWING TWO!
    ListTester(ListTester&& other)=delete;
    ListTester& operator=(ListTester&& other)=delete;

private:
    void destroy();
    std::list<int> listContainer;
};


#endif // LISTTESTER_H_INCLUDED
