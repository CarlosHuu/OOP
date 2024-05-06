#include <bits/stdc++.h>

using namespace std;

//===================================//
//             BASE CLASS            //
//===================================//
template <class T>
class Building{
    public:
        Building(T* _resource);
        ~Building();
        
        // Complete the member function declaration of base class "Building"
        // You can refer to the statement in building.cpp

        // ↓↓↓ write down your code below ↓↓↓
        virtual T production(int *workforce, float *foodstuff);


        // ↑↑↑ write down your code above ↑↑↑

    protected:
        T* resource;
};

//===================================//
//           DERIVED CLASS           //
//===================================//
template <class T>
class Generation: public Building<T>{
    public: 
        Generation(T* _resource);
        T production(int *workforce, float *foodstuff);
};


// Complete the class declaration of "Exploitation"
// You can refer to class "Generation" above

// ↓↓↓ write down your code below ↓↓↓
template <class T>
class Exploitation: public Building<T>{
    public: 
        Exploitation(T* _resource);
        T production(int *workforce, float *foodstuff);
};


// ↑↑↑ write down your code above ↑↑↑