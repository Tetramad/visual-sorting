NAME = bubble comb quick insertion shell selection heap counting radix bitonic_merge

CXX = g++
CXXFLAGS += -std=c++17 -Wpedantic -Wall -Wextra -Werror

.PHONY: all
all: $(NAME)

.PHONY: clean
clean:
	$(RM) $(NAME)

%: %.cc prober.hh prober.cc
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) -o $@ $< prober.cc $(LDFLAGS) $(LDLIBS)
