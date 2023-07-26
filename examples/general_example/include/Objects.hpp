#pragma once

#include <efc/RequestObject.hpp>

#include <string>

class TestObject : public efc::RequestObject {
public:
    TestObject() {};
    ~TestObject() {};
    std::string message;
};