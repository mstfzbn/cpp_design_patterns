#pragma once
#include <string>
#include <memory>

struct Address
{
    std::string street, city;
    int suite;
};

struct Contact
{
    std::string name;
    Address* address;
    //std::shared_ptr<Address> address;

    Contact( const Contact& rhs) : name{ rhs.name }
    {
        address = new Address
        {
                rhs.address->street,
                rhs.address->city,
                rhs.address->suite
        };
    };
};


