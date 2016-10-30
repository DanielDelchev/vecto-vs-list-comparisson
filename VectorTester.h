#ifndef VECTORTESTER_H_INCLUDED
#define VECTORTESTER_H_INCLUDED
#include <vector>
#include <iterator>

class VectorTester{

public:
    VectorTester(size_t count = 0);//O(n)
    VectorTester(const VectorTester& other)=default;
    VectorTester& operator=(const VectorTester& other)=default;
    virtual ~VectorTester();

    void clear(); /** O(n) performs pop_back n times */
    void push_back(int x); /** O(n) in the worst case scenario the vector will have to be resized leading to copying n elements the new array */
    void pop_back(); /** O(n) in the worst case scenario the vector will have to be resized leading to copying n elements the new array */

    void insertAt(size_t position, int x);/**< O(n) worst case if we insert at the start */
    void removeAt(size_t position);/**< O(n) worst case if we delete the first element */

    size_t capacity()const;/** O(1) */
    size_t size()const;/** O(1) */
    bool empty()const;/** O(1) */
    bool isSorted()const;/** O(1) */


    //iterators O(1)
    /** we can access any position of the vector directly  therefore getting an iterator to a position is constant */
    std::vector<int> :: iterator begin();
    std::vector<int> :: iterator end();
    std::vector<int> :: reverse_iterator rbegin();
    std::vector<int> :: reverse_iterator  rend();
    std::vector<int> :: const_iterator cbegin()const;
    std::vector<int> :: const_iterator cend()const;
    std::vector<int> :: const_reverse_iterator crbegin()const;
    std::vector<int> :: const_reverse_iterator  crend()const;

    void printContent()const; /* O(n) */

    //accessing position
    int& operator[](size_t position);/* O(1)*/
    const int& operator[](size_t position)const; /* O(1)*/

    // O(n*log(n))
    void sort();/** sorts the container using the <algorithm> library */
    //O(log(n)) if the array is sorted
    //O( n*log(n) + log(n) ) if the array is not sorted (we sort it before we find the element)
    int* findElement(int x);


    // THETE IS NO IMPLEMENTATION OF THE FOLLOWING TWO!
    VectorTester(VectorTester&& other)=delete;
    VectorTester& operator=(VectorTester&& other)=delete;
private:
    int find(int x,int left,int right)const;/** finds a specified element's position in the array through binary_search*/
    void destroy();        /** private destroy function */
    std::vector<int> vec; /** container */
    bool sorted;
};


#endif // VECTORTESTER_H_INCLUDED
