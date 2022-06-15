// Started at 11:52 6-15-2022

#include <iostream>
#include "Movies.h"

Movies::Movies() {
}

Movies::~Movies() {
}

bool Movies::add_movie(std::string name, std::string rating, int watched) {
    for(const Movie &movie: movies) {
        if(movie.get_name() == name)
            return false;
    }
    Movie temp {name, rating, watched};
    movies.push_back(temp);
    return true;
}

bool Movies::increment_watched(std::string name) {
    for(Movie &movie: movies) {
        if(movie.get_name() == name) {
            movie.increment_watched();
            return true;
        }
    }
    return false;
}

void Movies::display() const {
    if(movies.size() == 0) {
        std::cout << "No movies to display\n" << std::endl;
    } else {
        std::cout << "\n==================================" << std:: endl;
        for(const auto &movie: movies) 
            movie.display();
         std::cout << "\n==================================" << std:: endl;
    }
}

// Section 14
// Mystring - staring point
#include <iostream>
#include "Mystring.h"

using namespace std;

int main() {
    Mystring empty;
    Mystring larry{"larry"};
    Mystring stooge {larry};
    
    empty.display();
    larry.display();
    stooge.display();
    
    return 0;
}

#ifndef MYSTRING_H
#define MYSTRING_H

class Mystring
{
private:
    char *str;
public:
    Mystring();
    Mystring(const char *s);
    Mystring(const Mystring &source);
    ~Mystring();
    void display() const;
    int get_length() const;
    const char *get_str() const;
    
};

#endif // MYSTRING_H

#include <cstring>
#include <iostream>
#include "Mystring.h"

// No-args constructor
Mystring::Mystring() 
    : str{nullptr} {
    str = new char[1];
    *str ='\0';
}

// Overloaded contructor
Mystring::Mystring(const char *s) 
    : str {nullptr} {
        if(s == nullptr) {
            str = new char[1];
            *str = '\0';
        } else {
        str = new char[std::strlen(s)+1];
        std::strcpy(str, s);
    }
}

// Copy constructor
Mystring::Mystring(const Mystring &source) 
    : str{nullptr} {
        str = new char[std::strlen(source.str) + 1];
        std::strcpy(str, source.str);
}

// Destructor
Mystring::~Mystring() {
    delete [] str;
}

// Display method
void Mystring::display() const {
    std::cout << str << ": " << get_length() << std::endl;
}

// length getter
int Mystring::get_length() const { return std::strlen(str); }

// string getter
const char *Mystring::get_str() const { return str; }

// Section 14
// Overloading copy assingment
#include <iostream>
#include <vector>
#include "Mystring.h"

using namespace std;

int main() {
    Mystring a {"Hello"};
    Mystring b;
    b = a;
    
    b = "This is a test";
    
    
    
    Mystring empty;
    Mystring larry("Larry");
    Mystring stooge {larry};
    Mystring stooges;
    
    empty = stooge;
    
    empty.display();
    larry.display();
    stooge.display();
    empty.display();
    
    stooges = "Larry, Moe, and Curly";
    stooges.display();
    
    vector<Mystring> stooges_vec;
    stooges_vec.push_back("Larry");
    stooges_vec.push_back("Moe");
    stooges_vec.push_back("Curly");
    
    cout << "=== Loop 1 ===============" << endl;
    for(const Mystring &s: stooges_vec) 
        s.display();
        
    
    cout << "=== Loop 2 ===============" << endl;
    for(Mystring &s: stooges_vec)
        s = "Changed";
        
    cout << "=== Loop 3 ===============" << endl;
    for(const Mystring &s: stooges_vec)
        s.display();
    
    return 0;
}

#ifndef _MYSTRING_H_
#define _MYSTRING_H_

class Mystring
{
private:
    char *str;
public:
    Mystring();
    Mystring(const char *s);
    Mystring(const Mystring &source);
    ~Mystring();
    
    Mystring &operator=(const Mystring &rhs);
    
    void display() const;
    
    int get_length() const;
    const char *get_str() const;
};

#endif // _MYSTRING_H_

#include <cstring>
#include <iostream>
#include "Mystring.h"

// No-args constructor
Mystring::Mystring() 
    : str{nullptr} {
    str = new char[1];
    *str = '\0';    
}

// Overloaded constructor
Mystring::Mystring(const char *s)
    : str {nullptr} {
        if(s==nullptr) {
            str = new char[1];
            *str = '\0';
        } else {
            str = new char[std::strlen(s)+1];
            std::strcpy(str, s);
        }
}

// Copy constructor
Mystring::Mystring(const Mystring &source) 
    : str {nullptr} {
        str = new char[std::strlen(source.str) + 1];
        std::strcpy(str, source.str);
}

// Destructor
Mystring::~Mystring() {
    delete [] str;
}

// Copy assingmnet
Mystring &Mystring::operator=(const Mystring &rhs) {
    std::cout << "Copy assingment" << std::endl;
    if(this == &rhs) 
        return *this;
    delete [] this->str;
    str = new char[std::strlen(rhs.str) + 1];
    std::strcpy(this->str, rhs.str);
    return *this;
}

// Display method
void Mystring::display() const {
    std::cout << str << ": " << get_length() << std::endl;
}

// getters
int Mystring::get_length() const { return std::strlen(str); }
const char *Mystring::get_str() const { return str; }

// Section 14
// Overloading move constructor and move assingment operator
#include <iostream>
#include <vector>
#include "Mystring.h"

using namespace std;

int main() {
    
    Mystring a{"Hello"};
    a = Mystring{"Hola"};
    a = "Bonjour";
    
    
    Mystring empty;
    Mystring larry("Larry");
    Mystring stooge {larry};
    Mystring stooges;
    
    empty = stooge;

    
    empty = "Funny"; 
    
    
    empty.display();
    larry.display();
    stooge.display();
    empty.display();
    
    stooges = "Larry, Moe, and Curly";  
    stooges.display();
    
    vector<Mystring> stooges_vec;
    stooges_vec.push_back("Larry");
    stooges_vec.push_back("Moe");
    stooges_vec.push_back("Curly");  
    
    cout << "=== Loop 1 ==================" << endl;
    for (const Mystring &s: stooges_vec) 
        s.display();
        
    cout << "=== Loop 2 ==================" << endl;
    for (Mystring &s: stooges_vec)
        s = "Changed";
        
    cout << "=== Loop 3 ==================" << endl;
    for (const Mystring &s: stooges_vec) 
        s.display();
    
    return 0;
}

#include <iostream>
#include <cstring>
#include "Mystring.h"

 // No-args constructor
Mystring::Mystring() 
    : str{nullptr} {
    str = new char[1];
    *str = '\0';
}

// Overloaded constructor
Mystring::Mystring(const char *s)
    : str {nullptr} {
    if(s==nullptr) {
        str = new char[1];
        *str = '\0';
    } else {
        str = new char[strlen(s)+1];
        strcpy(str, s);
    }
}

// Copy constructor
Mystring::Mystring(const Mystring &source)
    : str {nullptr} {
        str = new char[strlen(source.str) + 1];
        strcpy(str, source.str);
        std::cout << "Copy constructor used" << std::endl;
}


// Move constructor
Mystring::Mystring( Mystring &&source) 
    :str(source.str) {
        source.str = nullptr;
        std::cout << "Move constructor used" << std::endl;
}

 // Destructor
Mystring::~Mystring() {
    if (str == nullptr) {
        std::cout << "Calling destructor for Mystring : nullptr" << std::endl;
    } else {
         std::cout << "Calling destructor for Mystring : " << str << std::endl;
    }
    delete [] str;
}

 // Copy assignment
Mystring &Mystring::operator=(const Mystring &rhs) {
    std::cout << "Using copy assignment" << std::endl;

    if (this == &rhs) 
        return *this;
    delete [] str;
    str = new char[strlen(rhs.str) + 1];
    strcpy(str, rhs.str);
    return *this;
}

// Move assignment
Mystring &Mystring::operator=(Mystring &&rhs) {
    std::cout << "Using move assignment" << std::endl;
    if (this == &rhs) 
        return *this;
    delete [] str;
    str = rhs.str;
    rhs.str = nullptr;
    return *this;    
}

// Display method
void Mystring::display() const {
    std::cout << str << " : " << get_length() << std::endl;
}

 // getters
 int Mystring::get_length() const { return strlen(str); }
 const char *Mystring::get_str() const { return str; }

#ifndef MYSTRING_H
#define MYSTRING_H

class Mystring
{
private:
    char *str;
public:
    Mystring();
    Mystring(const char *s);
    Mystring(const Mystring &source);
    Mystring(Mystring &&source);
    ~Mystring();
    
    Mystring &operator=(const Mystring &rhs);
    Mystring &operator=(Mystring &&rhs);
    
    void display() const;
    
    int get_length() const;
    const char *get_str() const;
};

#endif // MYSTRING_H

// Ended at 5:54 6-15-2022
