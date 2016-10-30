#ifndef TESTS_H_INCLUDED
#define TESTS_H_INCLUDED

#include "ListTester.h"
#include "VectorTester.h"
#include "chrono"
#include "random"

/**
 * @brief this function generates a pseudo random number from [a;b]
 * @param a - beginning of interval
 * @param b - end of interval
 * @return pseudo random integer
 * @date 17/01/2016
 */
int generateRandomNumberInInterval(int a,int b);

/**
 * @brief this function tests how many milliseconds take to create a ListTester object with count elements
 * @param count - the count of elements with which the object to be initialized upon constructuion
 * @return the count of milliseconds
 * @date 17/01/2016
 */
double ListTesterConstructorTest(size_t count);

/**
 * @brief this function tests how many milliseconds take to push "count" elements to the back of the container
 * @param count - the count of elements to be pushed
 * @return the count of milliseconds
 * @date 17/01/2016
 */
double ListTesterPushBackTest(size_t count);

/**
 * @brief this function tests how many milliseconds take to add "count" elements to a random position of the container
 * @param count - the count of elements to be added
 * @return the count of milliseconds
 * @date 17/01/2016
 */
double ListTesterRandomInsert(size_t count);

/**
 * @brief this function tests how many milliseconds take to remove "count" elements to a random position of the container
 * @param count - the count of elements to be removed
 * @return the count of milliseconds
 * @date 17/01/2016
 */
double ListTesterRandomRemove(size_t count);

/**
 * @brief applies operator = over 2 objects
 * @param how many elements exist in both objects when the operator is applied
 * @return the count of milliseconds
 * @date 17/01/2016
 */
double ListTesterEqualOperator(size_t count);

/**
 * @brief sorts the elements in the container in an ascending order
 * @param how many elements exist when the sorting is applied
 * @return the count of milliseconds
 * @date 17/01/2016
 */
double ListTesterSortTest(size_t count);

/**
 * @brief Finds "count" elements in a list with "size" elements
 * @param count - how many elements exist when the sorting is applied
 * @param size - the count of the elements in the container
 * @return the count of milliseconds
 * @date 17/01/2016
 */
double ListTesterFindTest(size_t size, size_t count=1024);


/**
 * @brief this function tests how many milliseconds take to create a VectorTester object with count elements
 * @param count - the count of elements with which the object to be initialized upon constructuion
 * @return the count of milliseconds
 * @date 17/01/2016
 */
double VectorTesterConstructorTest(size_t count);

/**
 * @brief this function tests how many milliseconds take to push "count" elements to the back of the container
 * @param count - the count of elements to be pushed
 * @return the count of milliseconds
 * @date 17/01/2016
 */
double VectorTesterPushBackTest(size_t count);

/**
 * @brief this function tests how many milliseconds take to add "count" elements to a random position of the container
 * @param count - the count of elements to be added
 * @return the count of milliseconds
 * @date 17/01/2016
 */
double VectorTesterRandomInsert(size_t count);

/**
 * @brief this function tests how many milliseconds take to remove "count" elements to a random position of the container
 * @param count - the count of elements to be removed
 * @return the count of milliseconds
 * @date 17/01/2016
 */
double VectorTesterRandomRemove(size_t count);

/**
 * @brief applies operator = over 2 objects
 * @param how many elements exist in both objects when the operator is applied
 * @return the count of milliseconds
 * @date 17/01/2016
 */
double VectorTesterEqualOperator(size_t count);

/**
 * @brief sorts the elements in the container in an ascending order
 * @param how many elements exist when the sorting is applied
 * @return the count of milliseconds
 * @date 17/01/2016
 */
double VectorTesterSortTest(size_t count);

/**
 * @brief Finds "count" elements in a vector with "size" elements
 * @detailed if the vector has not been sorted it will be sorted before any searching is applied
 * @param count - how many elements exist when the sorting is applied
 * @param size - the count of the elements in the container
 * @date 17/01/2016
 * @return the count of milliseconds
 */
double VectorTesterFindTest(size_t size, size_t count=1024);


/**
 * @brief Peforms all tests for 5 values and puts the result in a textfile
 * @return void
 * @date 17/01/2016
 */



/**
 * @brief this function tests how many milliseconds take to add "count" elements to a random position of the container
 * @detailed in this test a ListTester is created ,and we store Iterators to iterators to all position we are about to add
 * @param count - the count of elements to be added
 * @return the count of milliseconds
 * @date 17/01/2016
 */
double ListTesterRandomInsertIterator(size_t count);

/**
 * @brief this function tests how many milliseconds take to remove "count" elements to a random position of the container
 * @detailed in this test a ListTester is created ,and we store Iterators to iterators to all position we are about to remove
 * @param count - the count of elements to be removed
 * @return the count of milliseconds
 * @date 17/01/2016
 */
double ListTesterRandomRemoveIterator(size_t count);


                                                                        //10K               //100K          //250k
void TakeDownResults(size_t first=256, size_t second=1000, size_t third=10000 ,size_t fourth= 100000, size_t fifth=250000);
#endif // TESTS_H_INCLUDED
