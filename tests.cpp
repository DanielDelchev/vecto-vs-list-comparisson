#include "tests.h"
#include <iostream>
#include <iomanip>
#include <fstream>
std::default_random_engine generator;

int generateRandomNumberInInterval(int a,int b){
    std::uniform_int_distribution<int> distribution(a,b);
    return  distribution(generator);
}

double ListTesterConstructorTest(size_t count){
    using namespace std::chrono;
    high_resolution_clock::time_point start = high_resolution_clock::now();
    ListTester generic (count);
    high_resolution_clock::time_point finish = high_resolution_clock::now();
    duration<int,std::milli> time_span = duration_cast<duration<int,std::milli>>(finish - start);
    return time_span.count();
}

double ListTesterPushBackTest(size_t count){
    using namespace std::chrono;
    ListTester generic;
    high_resolution_clock::time_point start = high_resolution_clock::now();
    for (size_t i=0;i<count;i++){
        generic.push_back(i);
    }
    high_resolution_clock::time_point finish = high_resolution_clock::now();
    duration<int,std::milli> time_span = duration_cast<duration<int,std::milli>>(finish - start);
    return time_span.count();
}

double ListTesterRandomInsert(size_t count){
    using namespace std::chrono;
    ListTester generic(1000000);
    high_resolution_clock::time_point start = high_resolution_clock::now();
    for (size_t i=0;i<count;i++){
        int randomPosition=generateRandomNumberInInterval(0,20000000);
        generic.insertAt(randomPosition,i);
    }
    high_resolution_clock::time_point finish = high_resolution_clock::now();
    duration<int,std::milli> time_span = duration_cast<duration<int,std::milli>>(finish - start);
    return time_span.count();
}

double ListTesterRandomRemove(size_t count){
    using namespace std::chrono;
    ListTester generic(1000000);
    high_resolution_clock::time_point start = high_resolution_clock::now();
    for (size_t i=0;i<count;i++){
        int randomPosition=generateRandomNumberInInterval(0,20000000);
        generic.removeAt(randomPosition);
    }
    high_resolution_clock::time_point finish = high_resolution_clock::now();
    duration<int,std::milli> time_span = duration_cast<duration<int,std::milli>>(finish - start);
    return time_span.count();
}

double ListTesterEqualOperator(size_t count){
    using namespace std::chrono;
    ListTester generic1(count);
    ListTester generic2(count);
    high_resolution_clock::time_point start = high_resolution_clock::now();
    generic1=generic2;
    high_resolution_clock::time_point finish = high_resolution_clock::now();
    duration<int,std::milli> time_span = duration_cast<duration<int,std::milli>>(finish - start);
    return time_span.count();
}

double ListTesterSortTest(size_t count){
    using namespace std::chrono;
    ListTester generic;
    for (size_t i=0;i<count;i++){
        generic.push_back(generateRandomNumberInInterval(-1024,1024));
    }
    high_resolution_clock::time_point start = high_resolution_clock::now();
    generic.sort();
    high_resolution_clock::time_point finish = high_resolution_clock::now();
    duration<int,std::milli> time_span = duration_cast<duration<int,std::milli>>(finish - start);
    return time_span.count();
}

double ListTesterFindTest(size_t size,size_t count){
    using namespace std::chrono;
    ListTester generic;
    for (size_t i=0;i<count;i++){
        generic.push_back(i);//pushing only negative numbers
    }
    for (size_t i=0;i<count;i++){
        generic.insertAt(generateRandomNumberInInterval(0,size-1),i);//only positives
    }
    high_resolution_clock::time_point start = high_resolution_clock::now();
    for (size_t i=0;i<count;i++){
        generic.findElement(generateRandomNumberInInterval(0,size-1));
    }
    high_resolution_clock::time_point finish = high_resolution_clock::now();
    duration<int,std::milli> time_span = duration_cast<duration<int,std::milli>>(finish - start);
    return time_span.count();
}

double VectorTesterConstructorTest(size_t count){
    using namespace std::chrono;
    high_resolution_clock::time_point start = high_resolution_clock::now();
    VectorTester generic (count);
    high_resolution_clock::time_point finish = high_resolution_clock::now();
    duration<int,std::milli> time_span = duration_cast<duration<int,std::milli>>(finish - start);
    return time_span.count();
}

double VectorTesterPushBackTest(size_t count){
    using namespace std::chrono;
    VectorTester generic;
    high_resolution_clock::time_point start = high_resolution_clock::now();
    for (size_t i=0;i<count;i++){
        generic.push_back(i);
    }
    high_resolution_clock::time_point finish = high_resolution_clock::now();
    duration<int,std::milli> time_span = duration_cast<duration<int,std::milli>>(finish - start);
    return time_span.count();
}

double VectorTesterRandomInsert(size_t count){
    using namespace std::chrono;
    VectorTester generic(1000000);
    high_resolution_clock::time_point start = high_resolution_clock::now();
    for (size_t i=0;i<count;i++){
        int randomPosition=generateRandomNumberInInterval(0,20000000);
        generic.insertAt(randomPosition,i);
    }
    high_resolution_clock::time_point finish = high_resolution_clock::now();
    duration<int,std::milli> time_span = duration_cast<duration<int,std::milli>>(finish - start);
    return time_span.count();
}

double VectorTesterRandomRemove(size_t count){
    using namespace std::chrono;
    VectorTester generic(1000000);
    high_resolution_clock::time_point start = high_resolution_clock::now();
    for (size_t i=0;i<count;i++){
        int randomPosition=generateRandomNumberInInterval(0,20000000);
        generic.removeAt(randomPosition);
    }
    high_resolution_clock::time_point finish = high_resolution_clock::now();
    duration<int,std::milli> time_span = duration_cast<duration<int,std::milli>>(finish - start);
    return time_span.count();
}

double VectorTesterEqualOperator(size_t count){
    using namespace std::chrono;
    VectorTester generic1(count);
    VectorTester generic2(count);
    high_resolution_clock::time_point start = high_resolution_clock::now();
    generic1=generic2;
    high_resolution_clock::time_point finish = high_resolution_clock::now();
    duration<int,std::milli> time_span = duration_cast<duration<int,std::milli>>(finish - start);
    return time_span.count();
}

double VectorTesterSortTest(size_t count){
    using namespace std::chrono;
    VectorTester generic;
    for (size_t i=0;i<count;i++){
        generic.push_back(generateRandomNumberInInterval(-1024,1024));
    }
    high_resolution_clock::time_point start = high_resolution_clock::now();
    generic.sort();
    high_resolution_clock::time_point finish = high_resolution_clock::now();
    duration<int,std::milli> time_span = duration_cast<duration<int,std::milli>>(finish - start);
    return time_span.count();
}

double VectorTesterFindTest(size_t size,size_t count){
    using namespace std::chrono;
    VectorTester generic;
    for (size_t i=0;i<count;i++){
        generic.insertAt(generateRandomNumberInInterval(0,size-1),i);
    }
    high_resolution_clock::time_point start = high_resolution_clock::now();
    for (size_t i=0;i<count;i++){
        generic.findElement(generateRandomNumberInInterval(0,size-1));
    }
    high_resolution_clock::time_point finish = high_resolution_clock::now();
    duration<int,std::milli> time_span = duration_cast<duration<int,std::milli>>(finish - start);
    return time_span.count();
}



double ListTesterRandomInsertIterator(size_t count){
    using namespace std::chrono;
    ListTester generic;
    std::list < std::list<int> :: iterator > iterators;
    for (size_t i=0;i<count;i++){//for each element added, create an iterator for it
        generic.push_front(i);
        iterators.list::push_back(generic.begin());
    }
    high_resolution_clock::time_point start = high_resolution_clock::now();
    std::list < std::list<int> :: iterator > :: iterator iteratorForIterators = iterators.begin();
    for (size_t i=0;i<count;i++,++iteratorForIterators){
        generic.insertAt(*iteratorForIterators,i);
    }
    high_resolution_clock::time_point finish = high_resolution_clock::now();
    duration<int,std::milli> time_span = duration_cast<duration<int,std::milli>>(finish - start);
    return time_span.count();
}


double ListTesterRandomRemoveIterator(size_t count){
    using namespace std::chrono;
    ListTester generic;
    std::list < std::list<int> :: iterator > iterators;
    for (size_t i=0;i<count;i++){//for each element added, create an iterator for it
        generic.push_front(i);
        iterators.list::push_back(generic.begin());
    }
    high_resolution_clock::time_point start = high_resolution_clock::now();
    std::list < std::list<int> :: iterator > :: iterator iteratorForIterators = iterators.begin();
    for (size_t i=0;i<count;i++,++iteratorForIterators){
        generic.removeAt(*iteratorForIterators);
    }
    high_resolution_clock::time_point finish = high_resolution_clock::now();
    duration<int,std::milli> time_span = duration_cast<duration<int,std::milli>>(finish - start);
    return time_span.count();
}




void TakeDownResults(size_t first, size_t second, size_t third,size_t fourth,size_t fifth){
    using namespace std;
    fstream fs("TestResults.txt",ios::out|ios::trunc);
    fs<<"**************************************************************************************************"<<endl;
    cout<<"VectorTester!"<<endl;
    fs<<"Results for VectorTester:"<<endl;
    fs<<"Construcing"<<endl;
    fs<<"Constructing with "<<first<<" elements in "<<VectorTesterConstructorTest(first)<<" milliseconds"<<endl;
    fs<<"Constructing with "<<second<<" elements in "<<VectorTesterConstructorTest(second)<<" milliseconds"<<endl;
    fs<<"Constructing with "<<third<<" elements in "<<VectorTesterConstructorTest(third)<<" milliseconds"<<endl;
    fs<<"Constructing with "<<fourth<<" elements in "<<VectorTesterConstructorTest(fourth)<<" milliseconds"<<endl;
    fs<<"Constructing with "<<fifth<<" elements in "<<VectorTesterConstructorTest(fifth)<<" milliseconds"<<endl;
    cout<<"PushBack"<<endl;
    fs<<"PushBack"<<endl;
    fs<<"PushingBack "<<first<<" elements in "<<VectorTesterPushBackTest(first)<<" milliseconds"<<endl;
    fs<<"PushingBack "<<second<<" elements in "<<VectorTesterPushBackTest(second)<<" milliseconds"<<endl;
    fs<<"PushingBack "<<third<<" elements in "<<VectorTesterPushBackTest(third)<<" milliseconds"<<endl;
    fs<<"PushingBack "<<fourth<<" elements in "<<VectorTesterPushBackTest(fourth)<<" milliseconds"<<endl;
    fs<<"PushingBack "<<fifth<<" elements in "<<VectorTesterPushBackTest(fifth)<<" milliseconds"<<endl;
    fs<<"RandomInsert"<<endl;
    cout<<"RandomInsert"<<endl;
    fs<<"RandomInsert of "<<first<<" elements in "<<VectorTesterRandomInsert(first)<<" milliseconds"<<endl;
    fs<<"RandomInsert of "<<second<<" elements in "<<VectorTesterRandomInsert(second)<<" milliseconds"<<endl;
    fs<<"RandomInsert of "<<third<<" elements in "<<VectorTesterRandomInsert(third)<<" milliseconds"<<endl;
    fs<<"RandomInsert of "<<fourth<<" elements in "<<VectorTesterRandomInsert(fourth)<<" milliseconds"<<endl;
    fs<<"RandomInsert of "<<fifth<<" elements in "<<VectorTesterRandomInsert(fifth)<<" milliseconds"<<endl;
    cout<<"RandomRemove"<<endl;
    fs<<"RandomRemove"<<endl;
    fs<<"RandomRemove of "<<first<<" elements in "<<VectorTesterRandomRemove(first)<<" milliseconds"<<endl;
    fs<<"RandomRemove of "<<second<<" elements in "<<VectorTesterRandomRemove(second)<<" milliseconds"<<endl;
    fs<<"RandomRemove of "<<third<<" elements in "<<VectorTesterRandomRemove(third)<<" milliseconds"<<endl;
    fs<<"RandomRemove of "<<fourth<<" elements in "<<VectorTesterRandomRemove(fourth)<<" milliseconds"<<endl;
    fs<<"RandomRemove of "<<fifth<<" elements in "<<VectorTesterRandomRemove(fifth)<<" milliseconds"<<endl;
    cout<<"Operator= over 2 objects with various sizes "<<endl;
    fs<<"Operator= over 2 objects with "<<endl;
    fs<<first<<" elements in "<<VectorTesterEqualOperator(first)<<" milliseconds"<<endl;
    fs<<second<<" elements in "<<VectorTesterEqualOperator(second)<<" milliseconds"<<endl;
    fs<<third<<" elements in "<<VectorTesterEqualOperator(third)<<" milliseconds"<<endl;
    fs<<fourth<<" elements in "<<VectorTesterEqualOperator(fourth)<<" milliseconds"<<endl;
    fs<<fifth<<" elements in "<<VectorTesterEqualOperator(fifth)<<" milliseconds"<<endl;
    cout<<"Sorting containers with various size "<<endl;
    fs<<"Sorting with: "<<endl;
    fs<<first<<" elements in "<<VectorTesterSortTest(first)<<" milliseconds"<<endl;
    fs<<second<<" elements in "<<VectorTesterSortTest(second)<<" milliseconds"<<endl;
    fs<<third<<" elements in "<<VectorTesterSortTest(third)<<" milliseconds"<<endl;
    fs<<fourth<<" elements in "<<VectorTesterSortTest(fourth)<<" milliseconds"<<endl;
    fs<<fifth<<" elements in "<<VectorTesterSortTest(fifth)<<" milliseconds"<<endl;
    fs<<"Searching for elements 1024 times in a container with "<<endl;
    cout<<"Searching for elements 1024 times in a container with "<<endl;
    fs<<first<<" elements in "<<VectorTesterFindTest(first)<<" milliseconds"<<endl;
    fs<<second<<" elements in "<<VectorTesterFindTest(second)<<" milliseconds"<<endl;
    fs<<third<<" elements in "<<VectorTesterFindTest(third)<<" milliseconds"<<endl;
    fs<<fourth<<" elements in "<<VectorTesterFindTest(fourth)<<" milliseconds"<<endl;
    fs<<fifth<<" elements in "<<VectorTesterFindTest(fifth)<<" milliseconds"<<endl;
    fs<<"**************************************************************************************************"<<endl;
    fs<<"Results for ListTester:"<<endl;
    cout<<"ListTester!"<<endl;
    fs<<"Construcing"<<endl;
    cout<<"Constructing"<<endl;
    fs<<"Constructing with "<<first<<" elements in "<<ListTesterConstructorTest(first)<<" milliseconds"<<endl;
    fs<<"Constructing with "<<second<<" elements in "<<ListTesterConstructorTest(second)<<" milliseconds"<<endl;
    fs<<"Constructing with "<<third<<" elements in "<<ListTesterConstructorTest(third)<<" milliseconds"<<endl;
    fs<<"Constructing with "<<fourth<<" elements in "<<ListTesterConstructorTest(fourth)<<" milliseconds"<<endl;
    fs<<"Constructing with "<<fifth<<" elements in "<<ListTesterConstructorTest(fifth)<<" milliseconds"<<endl;
    cout<<"PushBack"<<endl;
    fs<<"PushBack"<<endl;
    fs<<"PushingBack "<<first<<" elements in "<<ListTesterPushBackTest(first)<<" milliseconds"<<endl;
    fs<<"PushingBack "<<second<<" elements in "<<ListTesterPushBackTest(second)<<" milliseconds"<<endl;
    fs<<"PushingBack "<<third<<" elements in "<<ListTesterPushBackTest(third)<<" milliseconds"<<endl;
    fs<<"PushingBack "<<fourth<<" elements in "<<ListTesterPushBackTest(fourth)<<" milliseconds"<<endl;
    fs<<"PushingBack "<<fifth<<" elements in "<<ListTesterPushBackTest(fifth)<<" milliseconds"<<endl;
    cout<<"RandomInsert"<<endl;
    fs<<"RandomInsert"<<endl;
    fs<<"RandomInsert of "<<first<<" elements in "<<ListTesterRandomInsert(first)<<" milliseconds"<<endl;
    fs<<"RandomInsert of "<<second<<" elements in "<<ListTesterRandomInsert(second)<<" milliseconds"<<endl;
    fs<<"RandomInsert of "<<third<<" elements in "<<ListTesterRandomInsert(third)<<" milliseconds"<<endl;
    fs<<"RandomInsert of "<<fourth<<" elements in "<<ListTesterRandomInsert(fourth)<<" milliseconds"<<endl;
    cout<<"RandomRemove"<<endl;
    fs<<"RandomRemove"<<endl;
    fs<<"RandomRemove of "<<first<<" elements in "<<ListTesterRandomRemove(first)<<" milliseconds"<<endl;
    fs<<"RandomRemove of "<<second<<" elements in "<<ListTesterRandomRemove(second)<<" milliseconds"<<endl;
    fs<<"RandomRemove of "<<third<<" elements in "<<ListTesterRandomRemove(third)<<" milliseconds"<<endl;
    fs<<"RandomRemove of "<<fourth<<" elements in "<<ListTesterRandomRemove(fourth)<<" milliseconds"<<endl;
    cout<<"Inserting with prdetermined iterators"<<endl;
    fs<<"Insert with prdetermined iterators of "<<endl;
    fs<<first<<" elements in "<<ListTesterRandomInsertIterator(first)<<" milliseconds"<<endl;
    fs<<second<<" elements in "<<ListTesterRandomInsertIterator(second)<<" milliseconds"<<endl;
    fs<<third<<" elements in "<<ListTesterRandomInsertIterator(third)<<" milliseconds"<<endl;
    fs<<fourth<<" elements in "<<ListTesterRandomInsertIterator(fourth)<<" milliseconds"<<endl;
    fs<<fifth<<" elements in "<<ListTesterRandomInsertIterator(fifth)<<" milliseconds"<<endl;
    cout<<"Remove with prdetermined iterators"<<endl;
    fs<<"Remove with prdetermined iterators of "<<endl;
    fs<<first<<" elements in "<<ListTesterRandomRemoveIterator(first)<<" milliseconds"<<endl;
    fs<<second<<" elements in "<<ListTesterRandomRemoveIterator(second)<<" milliseconds"<<endl;
    fs<<third<<" elements in "<<ListTesterRandomRemoveIterator(third)<<" milliseconds"<<endl;
    fs<<fourth<<" elements in "<<ListTesterRandomRemoveIterator(fourth)<<" milliseconds"<<endl;
    fs<<fifth<<" elements in "<<ListTesterRandomRemoveIterator(fifth)<<" milliseconds"<<endl;
    fs<<"Operator= over 2 objects with: "<<endl;
    cout<<"Operator= over 2 objects with various sizes "<<endl;
    fs<<first<<" elements in "<<ListTesterEqualOperator(first)<<" milliseconds"<<endl;
    fs<<second<<" elements in "<<ListTesterEqualOperator(second)<<" milliseconds"<<endl;
    fs<<third<<" elements in "<<ListTesterEqualOperator(third)<<" milliseconds"<<endl;
    fs<<fourth<<" elements in "<<ListTesterEqualOperator(fourth)<<" milliseconds"<<endl;
    fs<<fifth<<" elements in "<<ListTesterEqualOperator(fifth)<<" milliseconds"<<endl;
    cout<<"Sorting containers with various size"<<endl;
    fs<<"Sorting with: "<<endl;
    fs<<first<<" elements in "<<ListTesterSortTest(first)<<" milliseconds"<<endl;
    fs<<second<<" elements in "<<ListTesterSortTest(second)<<" milliseconds"<<endl;
    fs<<third<<" elements in "<<ListTesterSortTest(third)<<" milliseconds"<<endl;
    fs<<fourth<<" elements in "<<ListTesterSortTest(fourth)<<" milliseconds"<<endl;
    fs<<fifth<<" elements in "<<ListTesterSortTest(fifth)<<" milliseconds"<<endl;
    cout<<"Searching for elements 1024 times in a containers of various size"<<endl;
    fs<<"Searching for elements 1024 times in a container with "<<endl;
    fs<<first<<" elements in "<<ListTesterFindTest(first)<<" milliseconds"<<endl;
    fs<<second<<" elements in "<<ListTesterFindTest(second)<<" milliseconds"<<endl;
    fs<<third<<" elements in "<<ListTesterFindTest(third)<<" milliseconds"<<endl;
    fs<<fourth<<" elements in "<<ListTesterFindTest(fourth)<<" milliseconds"<<endl;
    fs<<fifth<<" elements in "<<ListTesterFindTest(fifth)<<" milliseconds"<<endl;
    fs.close();
}

