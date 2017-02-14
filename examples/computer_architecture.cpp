#include <strong.hpp>

// Create a type that counts number of cycles
struct cycle_count : strong::type<cycle_count, int> {
  // inherit the base class's constructors
  using type::type;
};

// Create a type that counts number of instructions
struct instruction_count : strong::type<instruction_count, int> {
  using type::type;
};

// Create a type for frequencies (hertz)
struct frequency : strong::type<frequency, double> {
  using type::type;
};

// Create a type for periods (inverse of frequency)
struct period : strong::type<period, double> {
  using type::type;
};

// Calculate the period given a frequency
constexpr period inverse(frequency const & hertz)
{
  return period(1.0 / static_cast<double>(hertz));
}

int main() {
  cycle_count cycles(50);
  instruction_count instructions(10000);
  frequency clock_rate(2.6);
  period p = inverse(clock_rate);

  return 0;
}
