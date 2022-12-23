#include <iostream>
#include <iomanip>
#include <ios>

double h{3.37812201319879182361820919}, i{2003.0}, j{1.34e-10};

void std_endl_n(){

    // std::endl : Place a new line '\n' are different thing.
    printf("< - - - std::endl and blackslash n - - ->\n\n");
    std::cout << "Hello"; // w/o std::endl
    std::cout << " World";

    std::cout << std::endl;
    std::cout << std::endl;

    std::cout << "Hellow" << std::endl; // w std::std::endl
    std::cout << "World";

    std::cout << std::endl;
    std::cout << std::endl;

    std::cout << "Hellow\n"; // it a same function
    std::cout << "World";
}

void std_flush(){

    // std::flush : flushes the output buffer to its final destination.
    printf("< - - - std::flush - - ->\n\n");
    std::cout << "This is a nice message. . ." << std::endl;
    std::cout << std::flush;
}

void std_setw(){

    // std::setw() : Adjust the field with for the item about to be printed.
    // std::left, std::internal, std::right "default" : justified the output either left or right
    // std::setfill(' ') : fill the spaces.
    printf("< - - - std::setw() - - ->\n");
    printf("< - - - std::left, internal, right - - ->\n");
    printf("< - - - std::setfill() - - ->\n\n");
    std::cout << "Unformatted table" << std::endl;
    std::cout << "Daniel" << " " << "Gray" << " 25" << std::endl;
    std::cout << "Stanley" << " " << "Woods" << " 33" << std::endl;
    std::cout << "Josh" << " " << "Ball" << " 21" << std::endl;

    std::cout << std::endl;
    std::cout << "Formatted table" << std::endl << std::left;
    std::cout << std::setw(10) << "Daniel" << std::setw(10) << "Gray" << std::setw(10) << "25" << std::endl;
    std::cout << std::setw(10) << "Stanley" << std::setw(10) << "Woods" << std::setw(10) << "33" << std::endl;
    std::cout << std::setw(10) << "Josh" << std::setw(10) << "Ball" << std::setw(10) << "21" << std::endl;
    std::cout << std::right;

    std::cout << std::endl << std::internal;
    int colW[]{5, 10, 15, 20};
    std::cout << std::setfill('.');
    std::cout << "Formatted table with vars" << std::endl;
    std::cout << std::setw(colW[2]) << "First name" << std::setw(colW[2]) << "Last name" << std::setw(colW[1]) << "Age" << std::endl;
    std::cout << std::internal;
    std::cout << std::setw(colW[1]) << "Daniel" << std::setw(colW[1]) << "Gray" << std::setw(colW[0]) << "25" << std::endl;
    std::cout << std::setw(colW[1]) << "Stanley" << std::setw(colW[1]) << "Woods" << std::setw(colW[0]) << "33" << std::endl;
    std::cout << std::setw(colW[1]) << "Josh" << std::setw(colW[1]) << "Ball" << std::setw(colW[0]) << "21" << std::endl;
}

void std_boolalpha(){

    printf("< - - - std::boolalpha, noboolalpha - - ->\n\n");
    std::cout << std::boolalpha; // std::boolalpha : to see value true or false instead of 0 and 1.
    bool a = true, b = false;

    std::cout << "Show bool a: " << a << std::endl;
    std::cout << "Show bool b: " << b << std::endl;

    std::cout << std::noboolalpha; // set back to default.
    std::cout << "Show bool a: " << a << std::endl;
    std::cout << "Show bool b: " << b << std::endl;
}

void std_showpos(){

    printf("< - - - std::showpos, noshowpos - - ->\n\n");
    int c{6}, d{-9}; // std::showpos : show positive sign

    std::cout << std::showpos;
    std::cout << "Show a: " << c << std::endl;
    std::cout << "Show b: " << d << std::endl;

    std::cout << std::noshowpos; // default
    std::cout << "Show a: " << c << std::endl;
    std::cout << "Show b: " << d << std::endl;
}

void std_dec_oct_hex_upcase(){

    printf("< - - - std::dec, oct, hex - - ->\n"); // std::dec, oct, hex : show binary
    printf("< - - - std::uppercase, nouppercase - - ->\n\n");
    int e{92133}, f{-883123};
    double g{3412.532};

    std::cout << std::endl;
    std::cout << "Default and different basses" << std::endl;
    std::cout << "Reveal the number: " << e << std::endl;
    std::cout << "Reveal the number: " << f << std::endl;
    std::cout << "Reveal the number: " << g << std::endl;

    std::cout << std::endl;
    std::cout << "Reveal the number (dec): " << std::dec << e << std::endl;
    std::cout << "Reveal the number (oct): " << std::oct << e << std::endl;
    std::cout << "Reveal the number (hex): " << std::hex << e << std::endl;

    std::cout << std::endl;
    std::cout << std::uppercase;
    std::cout << "Reveal the number (dec): " << std::dec << f << std::endl;
    std::cout << "Reveal the number (oct): " << std::oct << f << std::endl;
    std::cout << "Reveal the number (hex): " << std::hex << f << std::endl;

    std::cout << std::endl;
    std::cout << std::nouppercase;
    std::cout << "Reveal the number (dec): " << std::dec << g << std::endl;
    std::cout << "Reveal the number (oct): " << std::oct << g << std::endl;
    std::cout << "Reveal the number (hex): " << std::hex << g << std::endl;
    std::cout << std::dec; // make to default
}

void std_ios_fixed_scientific(){

    // using include <ios>
    printf("< - - - std::fixed, scientific - - ->\n\n");

    std::cout << std::endl;
    std::cout << "Double (Default: use scientific where necessary)" << std::endl;
    std::cout << "h: " << h << std::endl;
    std::cout << "i: " << i << std::endl;
    std::cout << "j: " << j << std::endl;

    std::cout << std::endl;
    std::cout << "Double (Fixed)" << std::endl;
    std::cout << std::fixed;
    std::cout << "h: " << h << std::endl;
    std::cout << "i: " << i << std::endl;
    std::cout << "j: " << j << std::endl;

    std::cout << std::endl;
    std::cout << "Double (Scientific)" << std::endl;
    std::cout << std::scientific;
    std::cout << "h: " << h << std::endl;
    std::cout << "i: " << i << std::endl;
    std::cout << "j: " << j << std::endl;

    std::cout << std::endl;
    std::cout << "Double (Default)" << std::endl;
    std::cout.unsetf(std::ios::scientific | std::ios::fixed); // this code to bring back to default.
    std::cout << "h: " << h << std::endl;
    std::cout << "i: " << i << std::endl;
    std::cout << "j: " << j << std::endl;
}

void std_setprecision(){

    printf("< - - - std::setprecision() - - ->\n\n");
    j = 1.30231298172341982172;

    std::cout << "j (6): " << j << std::endl; // defualt
    std::cout << std::setprecision(10);
    std::cout << "j (10): " << j << std::endl;
    std::cout << std::setprecision(20);
    std::cout << "j (20): " << j << std::endl;
    std::cout << std::setprecision(6);
}

void std_showpoint(){

    printf("< - - - std::showpoint, noshowpoint - - ->\n\n"); // show trailling zeros if necessary

    double k{34.1}, l(101.99), n(12.0), m{45};

    std::cout << std::endl;

    std::cout << "Default 'noshowpoint" << std::endl;
    std::cout << "k: " << k << std::endl;
    std::cout << "l: " << l << std::endl;
    std::cout << "n: " << n << std::endl;
    std::cout << "m: " << m << std::endl;

    std::cout << std::showpoint << std::setprecision(10) << std::endl;
    std::cout << "k: " << k << std::endl;
    std::cout << "l: " << l << std::endl;
    std::cout << "n: " << n << std::endl;
    std::cout << "m: " << m << std::endl;

    std::cout << std::noshowpoint << std::endl;
    std::cout << "k: " << k << std::endl;
    std::cout << "l: " << l << std::endl;
    std::cout << "n: " << n << std::endl;
    std::cout << "m: " << m << std::endl;

    std::cout << std::showbase << std::endl; // ???
    std::cout << "k: " << k << std::endl;
    std::cout << "l: " << l << std::endl;
    std::cout << "n: " << n << std::endl;
    std::cout << "m: " << m << std::endl;
}

int main(){

    // input/out manipulator

    std_endl_n();
    std::cout << std::endl << std::endl;
    std_flush();
    std::cout << std::endl << std::endl;
    std_setw();
    std::cout << std::endl << std::endl;
    std_boolalpha();
    std::cout << std::endl << std::endl;
    std_showpos();
    std::cout << std::endl << std::endl;
    std_dec_oct_hex_upcase();
    std::cout << std::endl << std::endl;
    std_ios_fixed_scientific();
    std::cout << std::endl << std::endl;
    std_setprecision();
    std::cout << std::endl << std::endl;
    std_showpoint();

    return 0;
}