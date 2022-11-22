#include <iostream>

int main (){

    // Declare pointer and reference

     double double_value{12.34};

     double &ref_double_value{double_value}; // Reference to double_value

     double *ptr_double_value{&double_value}; // Pointer to double_value

     // print
    std::cout << "double_value : " << double_value << std::endl;
    std::cout << "ref_double_value : " << ref_double_value << std::endl;
    std::cout << "ptr_double_value : " << ptr_double_value << std::endl;
    std::cout << "*ptr_double_value : " << *ptr_double_value << std::endl;

     // wrtting through ptr

    std::cout << std::endl;
    std::cout << "WRITING THROUGH POINTER : " << std::endl;

     *ptr_double_value = 15.44;

     // print
    std::cout << "double_value : " << double_value << std::endl;
    std::cout << "ref_double_value : " << ref_double_value << std::endl;
    std::cout << "ptr_double_value : " << ptr_double_value << std::endl;
    std::cout << "*ptr_double_value : " << *ptr_double_value << std::endl;

     // WRITTING THROUGH REFERENCE
    std::cout << std::endl;
    std::cout << "WRITING THROUGH REFERENCE : " << std::endl;

     ref_double_value = 18.44;

    std::cout << "double_value : " << double_value << std::endl;
    std::cout << "ref_double_value : " << ref_double_value << std::endl;
    std::cout << "ptr_double_value : " << ptr_double_value << std::endl;
    std::cout << "*ptr_double_value : " << *ptr_double_value << std::endl;

    std::cout << std::endl;

     double_value = 12.34;

     ref_double_value = double_value;

     double other_double_value{100.23};

     // this works, but doesn't make ref_double_value it merely changes the value referenced by ref_double_value to 100.23

     ref_double_value = other_double_value;

     // if you change ref_double_value now, other_double_value stays the sane proving that ref_double_value is note referencing other_double_value;
     ref_double_value = 333.33;

    std::cout << "double_value : " << double_value << std::endl;
    std::cout << "other_double_value : " << other_double_value << std::endl;
    std::cout << "ref_double_value : " << ref_double_value << std::endl;

     // ptr can point somewhere else
    std::cout << std::endl;
    std::cout << "A PTR CAN POINT SOMEWHERE ELSE : " << std::endl;

     ptr_double_value = &other_double_value;

    std::cout << "double_value : " << double_value << std::endl;
    std::cout << "ref_double_value : " << ref_double_value << std::endl;
    std::cout << "ptr_double_value : " << ptr_double_value << std::endl;
    std::cout << "*ptr_double_value : " << *ptr_double_value << std::endl;
    std::cout << "other_double_value : " << other_double_value << std::endl;

    std::cout << std::endl;
    std::cout << "CHANGING THE NOW POINTIED TO VALUE : " << std::endl;

     *ptr_double_value = 555.66;

    std::cout << "double_value : " << double_value << std::endl;
    std::cout << "ref_double_value : " << ref_double_value << std::endl;
    std::cout << "ptr_double_value : " << ptr_double_value << std::endl;
    std::cout << "*ptr_double_value : " << *ptr_double_value << std::endl;
    std::cout << "other_double_value : " << other_double_value << std::endl;

     double *const const_p_double_value{&double_value};

     // const_p_double_value = &other_double_value; // error

    return 0;
}