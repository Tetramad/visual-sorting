NAME = bubble comb quick insertion shell selection heap counting radix bitonic_merge

CXX = g++
CXXFLAGS += -std=c++17 -Wpedantic -Wall -Wextra -Werror -pthread

.PHONY: all
all: $(NAME)

.PHONY: clean
clean:
	$(RM) $(NAME)

%: %.cc probius.cc probius.hh terminal.hh terminal.cc
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) -o $@ $< probius.cc terminal.cc  $(LDFLAGS) $(LDLIBS)
