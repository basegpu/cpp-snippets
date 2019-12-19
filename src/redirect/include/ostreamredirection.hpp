#pragma once

#include <iostream>

namespace redirect
{

    class OStreamRedirection
    {
    public:

        OStreamRedirection(std::ostream& original, std::ostream& target) :
            original_(original),
            buffer_orig(original.rdbuf())
        {
            // Redirect
            this->original_.rdbuf(target.rdbuf());
        }

        ~OStreamRedirection()
        {
            this->original_.rdbuf(this->buffer_orig);
        }

    private:
        // Backup of original stream
        std::ostream& original_;
        std::streambuf* buffer_orig;
    };
}
