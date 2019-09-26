#include <string>
#include <exception>
#include "container.hpp"
#include "variant.hpp"

namespace container
{
    Container::~Container()
    {
        for (auto kv : *this)
        {
            delete kv.second;
        }
    }

    int Container::GetSize()
    {
        return this->size();
    }

    Variant_t Container::GetItem(const std::string& label)
    {
        if (this->count(label) == 0)
        {
            throw std::out_of_range("no item found.");
        }
        return this->at(label);
    }
}
