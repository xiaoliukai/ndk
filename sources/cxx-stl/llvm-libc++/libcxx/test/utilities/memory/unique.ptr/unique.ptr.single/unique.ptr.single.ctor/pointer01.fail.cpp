//===----------------------------------------------------------------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is dual licensed under the MIT and the University of Illinois Open
// Source Licenses. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

// <memory>

// unique_ptr

// Test unique_ptr(pointer) ctor

#include <memory>

// unique_ptr(pointer) ctor should require default Deleter ctor
class Deleter
{

    Deleter() {}

public:

    Deleter(Deleter&) {}
    Deleter& operator=(Deleter&) {}

    void operator()(void*) const {}
};

int main()
{
    std::unique_ptr<int, Deleter> p(new int);
}
