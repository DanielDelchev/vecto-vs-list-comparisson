#include "VectorTester.h"
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
void VectorTester::destroy(){
}

/**
 * @brief Class destructor
 * @detailed virtual destructor for the class, currently does nothing since no dynamic memory is being handled manually
 * @see VectorTester::destroy()
 * @return nothing
 * @date 16/01/2016
 */
VectorTester::~VectorTester(){
    destroy();
}

/**
 * @brief Class constructor
 * @detailed creates a VectorTester whith n integers integers inserted in its vector container
 * @param count - the number of elements to be intialized in the container
 * @return nothing it s a constructor
 * @date 16/01/2016
 */
VectorTester::VectorTester(size_t count):sorted(false){
    vec.assign(count,42);/** replaces the content of the container with "count" cpoies of 42 */
}                           /** since this is a constructor no destruction of old elements takes place */

/**
 * @brief container capacity
 * @detailed returns the current capacity of the container
 * @return the current capacity of the container
 * @date 16/01/2016
 */
size_t VectorTester::capacity()const{
    return vec.vector::capacity();
}

/**
 * @brief container size
 * @detailed returns the current size of the container meaning how many integers are stored in it currently
 * @return the current size of the container
 * @date 16/01/2016
 */
size_t VectorTester::size()const{
    return vec.vector::size();
}

/**
 * @brief check wheter the container is empty
 * @detailed performs a check whether the container is empty
 * @return wheter the container is empty
 * @date 16/01/2016
 */
bool VectorTester::empty()const{
    return vec.vector::empty();
}

/**
 * @brief adds an integer at the back of the container
 * @detailed puts the given integer at the back of the container which is a vector
 * @return void
 * @param x - the integer we are adding
 * @date 16/01/2016
 */
void VectorTester::push_back(int x){
    if (size()!=0 && x < vec[size()-1] ){
        sorted = false;
    }
    vec.vector::push_back(x);
}

/**
 * @brief removes an integer from the back of the container
 * @detailed removes the last integer at the back of the container
 * @return void
 * @date 16/01/2016
 */
void VectorTester::pop_back(){
    vec.vector::pop_back();
}

/**
 * @brief removes all content from the container
 * @detailed removes all integers in the vector using the pop_back() member-function
 * @return void
 * @see pop_back()
 * @date 16/01/2016
 */
void VectorTester::clear(){
    while (!empty()){
        pop_back();
    }
}

/**
 * @brief inserts an element into the container
 * @detailed adds the integer x at the specified positon of the container (if possible) if position is not valid then position%=size
 * @return void
 * @param position- the index of the position at which we want to add the element x
 * @param x - the integer we want to add
 * @date 16/01/2016
 */
void VectorTester::insertAt(size_t position,int x){
    sorted = false;
    if (position < size()){
        std::vector<int> :: iterator at_pos = begin() + position;
        vec.vector::insert(at_pos,x);
    }
    if (position >= size() && empty()){ // if the position is not valid and container is empty
        std::vector<int> :: iterator at_pos = begin();
        vec.vector::insert(at_pos,x);
    }
    else if (position >= size() && !empty()){ // if the position is not valid and container not empty
        std::vector<int> :: iterator at_pos = begin() + (position % size()); //if containe was empty we would be performing (int)position % 0
        vec.vector::insert(at_pos,x);
    }
 }

 /**
 * @brief removes an element from the container
 * @detailed removes the integer at the specified positon of the container (if possible) if position is not valid then position%=size
 * @return void
 * @param position- the index of the position from which we want to remove an element
 * @date 16/01/2016
 */
void VectorTester::removeAt(size_t position){
    if (!empty()){//making sure the container is not empty already, in which case removing is impossible
        if (position < size()){
            std::vector<int> :: iterator at_pos = begin() + position;
            vec.vector::erase(at_pos);
        }
        if (position >= size()){
            std::vector<int> :: iterator at_pos = begin() + (position % size());
            vec.vector::erase(at_pos);
        }
    }
 }


 /**
 * @brief iterator
 * @return an iterator to the beginning of the container
 * @date 16/01/2016
 */
std::vector<int> :: iterator VectorTester::begin(){
    return vec.vector::begin();
}
 /**
 * @brief iterator
 * @return an iterator to the end of the container
 * @date 16/01/2016
 */
std::vector<int> :: iterator VectorTester::end(){
    return vec.vector::end();
}
 /**
 * @brief iterator
 * @return an iterator to the reversed beginning of the container
 * @date 16/01/2016
 */
std::vector<int> :: reverse_iterator VectorTester::rbegin(){
    return vec.vector :: rbegin();
}

 /**
 * @brief iterator
 * @return an iterator to the reversed end of the container
 * @date 16/01/2016
 */
std::vector<int> :: reverse_iterator VectorTester::rend(){
    return vec.vector::rend();
}

 /**
 * @brief constant iterator
 * @return a constant iterator to the beginning of the container
 * @date 16/01/2016
 */
std::vector<int> :: const_iterator VectorTester::cbegin()const{
    return vec.vector::cbegin();
}

 /**
 * @brief constnat iterator
 * @return a constant iterator to the end of the container
 * @date 16/01/2016
 */
std::vector<int> :: const_iterator VectorTester::cend()const{
    return vec.vector::cend();
}

 /**
 * @brief constnat iterator
 * @return a constant iterator to the reversed beginning of the container
 * @date 16/01/2016
 */
std::vector<int> :: const_reverse_iterator VectorTester::crbegin()const{
    return vec.vector::crbegin();
}

 /**
 * @brief constant iterator
 * @return a constant iterator to the reversed end of the container
 * @date 16/01/2016
 */
std::vector<int> :: const_reverse_iterator  VectorTester::crend()const{
    return vec.vector::crend();
}

 /**
 * @brief prints the vector content
 * @return void
 * @date 16/01/2016
 */
void VectorTester::printContent()const{
    size_t counter= size();
    for (size_t i=0;i<counter;++i){
        std::cout<<vec[i]<<" ";
    }
    std::cout<<std::endl;
}

 /**
 * @brief  operator for reference
 * @return reference to the integer in the specified position
 * @param position - the position for which a reference is returned
 * @date 16/01/2016
 */
int& VectorTester::operator[](size_t position){
    return vec[position];
}

 /**
 * @brief  operator for constant reference
 * @return constant reference to the integer in the specified position
 * @param position - the position for which a constant reference is returned
 * @date 16/01/2016
 */
const int& VectorTester::operator[](size_t position)const{
    return vec[position];
}


 /**
 * @brief  tells us if the container is sorted ascendingly
 * @return a check whether the container is sorted ascendingly
 * @date 16/01/2016
 */
bool VectorTester::isSorted()const{
    return sorted;
}

 /**
 * @brief  sorts the vector using <algorithm> library function sort(iterator,iterator)
 * @return void
 * @date 16/01/2016
 */
 void VectorTester::sort(){
    std::sort(vec.begin(),vec.end());
    sorted=true;
 }


 /**
 * @brief  performs binary search
 * @detailed this function is private and shall not be called over an unsorted container
 * @return the position at which the element has been found or -1 if it hasnt been found
 * @date 16/01/2016
 */
int VectorTester::find(int x,int left,int right)const{
        if (left>right){
            return -1;
        }
        int medium = (left + right)/2;
        if ( vec[medium] ==x){
            return medium;
        }
        else if (x > vec[medium]){
            return find(x,medium+1,right);
        }
        else {
            return find(x,left,right-1);
        }
        return -1;
 }

 /**
 * @brief  performs binary search
 * @detailed this function is public
 * @return pointer to the element we sought in the container or NULL if it hasnt been found
 * @date 16/01/2016
 */
int* VectorTester::findElement(int x){
    if (empty()){
        return NULL;
    }
    if (!sorted){
        sort();
    }
    int result = find(x,0,size()-1);
    if (result == -1){
        return NULL;
    }
    return &(this->operator[](result));
}
