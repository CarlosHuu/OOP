#include "building.h"

// color setting
#define NONE  "\e[0m"
#define RED   "\e[31m"

// global variables
bool warning_flag = false;

//===================================//
//             BASE CLASS            //
//===================================//
template class Building<int>;
template class Building<char>;
template class Building<float>;

template < class T>
Building<T>::Building(T* _resource){
    resource = _resource;
};

template < class T >
Building<T>::~Building(){};

template < class T >
T Building<T>::production(int *workforce, float *foodstuff){
    if(!warning_flag){
        warning_flag = true;
        cout << RED << "If you see this warning, it means your forget to "
                    << "set the member function of base class as virtual !!!" 
                    << NONE << endl << endl;
    }
    *foodstuff -= 500;    
    return resource[0];
};

//===================================//
//           DERIVED CLASS           //
//===================================//

// Complete the member function statement of "Generation"
// You can refer to class "Exploitation" below

// ↓↓↓ write down your code below ↓↓↓
template class Generation<int>;
template class Generation<float>;

template < class T >
Generation<T>::Generation(T* _resource) : Building<T>::Building(_resource) {};

template < class T >
T Generation<T>::production(int *workforce, float *foodstuff){
    *foodstuff -= 10;
    
    T get_resource = Building<T>::resource[0];
    
    
    return  (get_resource) *0.4;
};


// ↑↑↑ write down your code above ↑↑↑

template class Exploitation<char>;
template class Exploitation<float>;

template < class T >
Exploitation<T>::Exploitation(T* _resource) : Building<T>::Building(_resource) {};

template < class T >
T Exploitation<T>::production(int *workforce, float *foodstuff){
    *foodstuff -= (*workforce / 2) * 1.2;

    T get_resource = Building<T>::resource[0];

    Building<T>::resource++;

    return get_resource;
};