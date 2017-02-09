#include <strong_types.hpp>

namespace st = strong_types;

// Create a type that counts number of cycles
struct cycle_count : st::type<cycle_count, int> {
  // inherit the base class's constructors
  using type::type;
};

// Create a type that counts number of instructions
struct instruction_count : st::type<instruction_count, int> {
  using type::type;
};

// Create a type for frequencies (hertz)
struct frequency : st::type<frequency, double> {
  using type::type;
};

int main() {
  cycle_count cycles(50);
  instruction_count instructions(10000);
  frequency clock_rate(2.6);

  return 0;
}
