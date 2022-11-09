#include <iostream>

int main (){

    // Non const ref.
     std::cout << std::endl;
     std::cout << "Non const ref. : " << std::endl;

     int age{27};
     int &ref_age{age};

     std::cout << "age : " << age << std::endl;
     std::cout << "ref_age : " << ref_age << std::endl;

     // Can modify original veriable throught ref.

     std::cout << std::endl;
     std::cout << "Modify original variable through reference : " << std::endl;

     ref_age++; // modify through reference

     std::cout << "age : " << age << std::endl;
     std::cout << "ref_age : " << ref_age << std::endl;

     // const reference

     std::cout << std::endl;
     std::cout << "Const ref : " << std::endl;

     age = 30;
     const int &const_ref_age{age};

     std::cout << "age : " << age << std::endl;
     std::cout << "const_ref_age : " << const_ref_age << std::endl;

     // try to modify throug const ref

     // const_ref_age = 31; // Error

     // can achieve the smae thing as const ref with pointer : const pointer to const data
     //  remember that a ref by default is just like a const pointer. all we need
     //  to do is make the const pointer point to const data

     // const int* const const_ptr_to_const_age {&age};

     // *const_ptr_to_const_age = 32; // Error

    return 0;
}