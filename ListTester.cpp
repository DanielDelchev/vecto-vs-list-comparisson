#include "ListTester.h"
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <iostream>
#include <algorithm>

/**
 * @brief this function currenty does nothing
 * @detailed this function is private and it contains the action which must be preformed in the destructor,should any dynamic memory be handled manually
 * @see VectorTester::~VectorTester()
 * @return nothing, function is void
 * @date 16/01/2016
 */
void ListTester::destroy(){
}

/**
 * @brief Class destructor
 * @detailed virtual destructor for the class, currently does nothing since no dynamic memory is being handled manually
 * @see VectorTester::destroy()
 * @return nothing
 * @date 16/01/2016
 */
ListTester::~ListTester(){
    destroy();
}

/**
 * @brief Class constructor
 * @detailed creates a ListTester whith n integers inserted in its vector container
 * @param count - the number of elements to be intialized in the container
 * @return nothing it s a constructor
 * @date 17/01/2016
 */
ListTester::ListTester(size_t count){
    listContainer.assign(count,42);/** replaces the content of the container with "count" cpoies of 42 */
}                                  /** since this is a constructor no destruction of old elements takes place */

/**
 * @brief counts the elements in the container
 * @return the current size of the container
 * @date 17/01/2016
 */
size_t ListTester:: size()const{
    return listContainer.list::size();
}

/**
 * @brief checks if the container is empty
 * @return result of the check
 * @date 17/01/2016
 */
bool ListTester:: empty()const{
    return listContainer.list::empty();
}
/**
 * @brief adds an element at the back of the container (list)
 * @param the element we are adding
 * @return void
 * @date 17/01/2016
 */
void ListTester::push_back(int x){
    listContainer.list::push_back(x);
}

/**
 * @brief adds an element at the front of the container (list)
 * @param the element we are adding
 * @return void
 * @date 17/01/2016
 */
void ListTester::push_front(int x){
    listContainer.list::push_front(x);
}

/**
 * @brief removes an element from the back of the container (list)
 * @return void
 * @date 17/01/2016
 */
void ListTester::pop_back(){
    listContainer.list::pop_back();
}

/**
 * @brief removes an element from the front of the container (list)
 * @return void
 * @date 17/01/2016
 */
void ListTester::pop_front(){
    listContainer.list::pop_front();
}

/**
 * @brief removes all elements from the list, leaving it empty
 * @return void
 * @date 17/01/2016
 */
void ListTester::clear(){
    listContainer.list::clear();
}

 /**
 * @brief prints the list's content
 * @return void
 * @date 17/01/2016
 */
void ListTester::printContent()const{
    std::list<int> :: const_iterator start=cbegin();
    std::list<int> :: const_iterator ending=cend();
    for (;start!=ending;++start){
        std::cout<<*start<<" ";
    }
    std::cout<<std::endl;
}


/**
 * @brief iterator
 * @return an iterator to the beginning of the container
 * @date 17/01/2016
 */
std::list<int> :: iterator ListTester::begin(){
    return listContainer.list :: begin();
}
 /**
 * @brief iterator
 * @return an iterator to the end of the container
 * @date 17/01/2016
 */
std::list<int> :: iterator ListTester::end(){
    return listContainer.list :: end();
}
 /**
 * @brief iterator
 * @return an iterator to the reversed beginning of the container
 * @date 17/01/2016
 */
std::list<int> :: reverse_iterator ListTester::rbegin(){
    return listContainer.list :: rbegin();
}

 /**
 * @brief iterator
 * @return an iterator to the reversed end of the container
 * @date 17/01/2016
 */
std::list<int> :: reverse_iterator ListTester::rend(){
    return listContainer.list :: rend();
}

 /**
 * @brief constant iterator
 * @return a constant iterator to the beginning of the container
 * @date 17/01/2016
 */
std::list<int> :: const_iterator ListTester::cbegin()const{
    return listContainer.list :: cbegin();
}

 /**
 * @brief constnat iterator
 * @return a constant iterator to the end of the container
 * @date 17/01/2016
 */
std::list<int> :: const_iterator ListTester::cend()const{
    return listContainer.list :: cend();
}

 /**
 * @brief constnat iterator
 * @return a constant iterator to the reversed beginning of the container
 * @date 17/01/2016
 */
std::list<int> :: const_reverse_iterator ListTester::crbegin()const{
    return listContainer.list :: crbegin();
}

 /**
 * @brief constant iterator
 * @return a constant iterator to the reversed end of the container
 * @date 17/01/2016
 */
std::list<int> :: const_reverse_iterator  ListTester::crend()const{
    return listContainer.list :: crend();
}

 /**
 * @brief sorts container's elements in ascending order using sort function provided for list containers
 * @return void
 * @date 17/01/2016
 */
void ListTester::sort(){
    listContainer.list::sort();
}


 /**
 * @brief find an element in the container and returns a pointer to it
 * @param x - the element we are looking for
 * @return pointer to the element or NULL if it has not been found
 * @date 17/01/2016
 */
int* ListTester::findElement(int x){
    int* result=NULL;
    std::list<int> :: iterator start=begin();
    std::list<int> :: iterator ending=end();
    for (;start!=ending;++start){
        if( *start == x ){
            result= &(*start);
        }
    }
    return result; //if not found return null
}


/**
 * @brief inserts the element X in the list at the specified position
 @ @param x - the number we are adding
 * @param position - the position we are adding it to (if not valid position then position = position % size)
 * @return void
 * @date 17/01/2016
 */
void ListTester::insertAt(size_t position, int x){
    if ( size() == 0 ){ //if the container is empty
        push_back(x);
    }
    else if(position < size() ){//using list::insert
        std::list<int> :: iterator start = begin();
        for(size_t i=0;i<position;i++){
            ++start;
        }
        listContainer.list::insert(start,x);
    }
    else if (position >= size() && size()!=0) {
        position %= size();
        insertAt(position,x);
    }
}

/**
 * @brief removes an element of the list from a specified position
 * @param position - the position we are removing from (if not valid position then position = position % size)
 * @return void
 * @date 17/01/2016
 */
void ListTester::removeAt(size_t position){
    if (!empty()){
        std::list<int> :: iterator start = begin();
        if(position < size()){
            for (size_t i=0;i<position;i++){
                ++start;
            }
            listContainer.list::erase(start);
        }
        else if (position >= size()){
            position %= size();
            for (size_t i=0;i<position;i++){
                ++start;
            }
            listContainer.list::erase(start);
        }
    }
}

/**
 * @brief inserts the element X in the list at the specified position
 @ @param x - the number we are adding
 * @param position - the position we are adding it to (if not valid position then position = position % size)
 * @return void
 * @date 17/01/2016
 */
void ListTester::insertAt(std::list<int> :: iterator it, int x){
    listContainer.insert(it,x);
}

/**
 * @brief removes an element of the list from a specified position
 * @param position - the position we are removing from (if not valid position then position = position % size)
 * @return void
 * @date 17/01/2016
 */
void ListTester::removeAt(std::list<int> :: iterator it){
    listContainer.list::erase(it);
}
