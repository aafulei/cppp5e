// 19/05/26 = Sun

// an extra demo to accompany Exercise 18.5
// throw and catch various standard exceptions as specified by the user
// throw and catch repeatedly, until told to stop

#include <cctype>
#include <exception>
#include <iostream>

using namespace std;

// a factory function to throw standard exceptions as specified by the user
bool throw_a_standard_exception()
{
    cout << "----- Standard exception Class Hierarchy -----\n"
            "0. - exception\n"
            "1.     - bad_cast\n"
            "2.     - runtime_error\n"
            "3.         - overflow_error\n"
            "4.         - underflow_error\n"
            "5.         - range_error\n"
            "6.     - logic_error\n"
            "7.         - domain_error\n"
            "8.         - invalid_argument\n"
            "9.         - out_of_range\n"
            "10.        - length_error\n"
            "11.    - bad_alloc\n"
            "----------------------------------------------\n" << endl;
    unsigned num;
    // read until getting a valid number or Q from input
    while (true) {
        cout << "Enter a number (0-11) to throw an exception, or Q to quit: ";
        if (::toupper(cin.peek()) == 'Q' || cin.eof())
            return false;
        cin >> num;
        if (cin && num <= 11)
            break;
        else {
            cin.clear();
            cin.ignore(256, '\n');
        }
    }
    // discard characters and newline following the valid input
    cin.ignore(256, '\n');
    // throw exceptions according to the number
    switch (num) {
        case 0: throw exception();
        case 1: throw bad_cast();
        case 2: throw runtime_error("std::runtime_error");
        case 3: throw overflow_error("std::overflow_error");
        case 4: throw underflow_error("std::underflow_error");
        case 5: throw range_error("std::range_error");
        case 6: throw logic_error("std::logic_error");
        case 7: throw domain_error("std::domain_error");
        case 8: throw invalid_argument("std::invalid_argument");
        case 9: throw out_of_range("std::out_of_range");
        case 10: throw length_error("std::length_error");
        case 11: throw bad_alloc();
    }
    return true;
}

void catch_a_standard_exception()
{
    while (true) {
        try {
            if (!throw_a_standard_exception())
                return;
        }
        catch (const bad_cast & e)          { cerr << "\nCaught a " << e.what() << "!\n" << endl; }
        catch (const overflow_error & e)    { cerr << "\nCaught a " << e.what() << "!\n" << endl; }
        catch (const underflow_error & e)   { cerr << "\nCaught a " << e.what() << "!\n" << endl; }
        catch (const range_error & e)       { cerr << "\nCaught a " << e.what() << "!\n" << endl; }
        catch (const runtime_error & e)     { cerr << "\nCaught a " << e.what() << "!\n" << endl; }
        catch (const domain_error & e)      { cerr << "\nCaught a " << e.what() << "!\n" << endl; }
        catch (const invalid_argument & e)  { cerr << "\nCaught a " << e.what() << "!\n" << endl; }
        catch (const out_of_range & e)      { cerr << "\nCaught a " << e.what() << "!\n" << endl; }
        catch (const length_error & e)      { cerr << "\nCaught a " << e.what() << "!\n" << endl; }
        catch (const logic_error & e)       { cerr << "\nCaught a " << e.what() << "!\n" << endl; }
        catch (const bad_alloc & e)         { cerr << "\nCaught a " << e.what() << "!\n" << endl; }
        catch (const exception & e)         { cerr << "\nCaught a " << e.what() << "!\n" << endl; }
    }
}

int main()
{
    catch_a_standard_exception();
    return 0;
}
