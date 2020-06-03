NAME = bubble comb quick insertion shell selection heap

CXX = g++
CXXFLAGS += -Wpedantic -Wall -Wextra -Werror

.PHONY: all
all: $(NAME)

.PHONY: clean
clean:
	$(RM) $(NAME)

%: %.cc prober.hh prober.cc
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) -o $@ $< prober.cc $(LDFLAGS) $(LDLIBS)
