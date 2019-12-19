#pragma once

#include <iostream> 
#include <string>

namespace redirect
{
    
    class ScopedRedirect
    {
    public:

        ScopedRedirect(std::ostream& original, std::ostream& target) :
            original_(original),
            buffer_orig(original.rdbuf())
        {
            // Redirect
            this->original_.rdbuf(target.rdbuf());
        }

        ~ScopedRedirect()
        {
            this->original_.rdbuf(this->buffer_orig);
        }

    private:
        // Backup of original stream
        std::ostream& original_;
        std::streambuf* buffer_orig;
    };
}
