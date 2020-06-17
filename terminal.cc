#include "terminal.hh"

namespace foreground {
char const *const black = "\033[30m";
char const *const red = "\033[31m";
char const *const green = "\033[32m";
char const *const yellow = "\033[33m";
char const *const blue = "\033[34m";
char const *const magenta = "\033[35m";
char const *const cyan = "\033[36m";
char const *const white = "\033[37m";
char const *const clear = "\033[39m";
} // namespace foreground

namespace background {
char const *const black = "\033[40m";
char const *const red = "\033[41m";
char const *const green = "\033[42m";
char const *const yellow = "\033[43m";
char const *const blue = "\033[44m";
char const *const magenta = "\033[45m";
char const *const cyan = "\033[46m";
char const *const white = "\033[47m";
char const *const clear = "\033[49m";
} // namespace background

namespace screen {
char const *const clear = "\033[2J";
}

namespace cursor {
char const *const origin = "\033[1;1H";
}
