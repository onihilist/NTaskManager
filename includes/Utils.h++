#ifndef UTILS_HPP
#define UTILS_HPP

#include <string>

namespace Utils {
    namespace color {
        inline constexpr const char* Reset         = "\033[0m";
        inline constexpr const char* Black         = "\033[30m";
        inline constexpr const char* Red           = "\033[31m";
        inline constexpr const char* Green         = "\033[32m";
        inline constexpr const char* Yellow        = "\033[33m";
        inline constexpr const char* Blue          = "\033[34m";
        inline constexpr const char* Magenta       = "\033[35m";
        inline constexpr const char* Cyan          = "\033[36m";
        inline constexpr const char* White         = "\033[37m";

        inline constexpr const char* BrightBlack   = "\033[90m";
        inline constexpr const char* BrightRed     = "\033[91m";
        inline constexpr const char* BrightGreen   = "\033[92m";
        inline constexpr const char* BrightYellow  = "\033[93m";
        inline constexpr const char* BrightBlue    = "\033[94m";
        inline constexpr const char* BrightMagenta = "\033[95m";
        inline constexpr const char* BrightCyan    = "\033[96m";
        inline constexpr const char* BrightWhite   = "\033[97m";
    }
}

#endif

