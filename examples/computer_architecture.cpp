#include <strong.hpp>

// Create a type that counts number of cycles
struct cycle_count : strong::type<cycle_count, int> {
  // inherit the base class's constructors
  using strong::type<cycle_count, int>::type;
};

// Create a type that counts number of instructions
struct instruction_count : strong::type<instruction_count, int> {
  using strong::type<instruction_count, int>::type;
};

// Create a type for frequencies (hertz)
struct frequency : strong::type<frequency, double> {
  using strong::type<frequency, double>::type;
};

// Create a type for periods (inverse of frequency)
struct period : strong::type<period, double> {
  using strong::type<period, double>::type;
};

// Calculate the period given a frequency
constexpr period inverse(frequency const & hertz)
{
  return period(1.0 / static_cast<double>(hertz));
}

int main() {
  cycle_count cycles(50);

  instruction_count to_be_moved_instructions(10000);
  // call move constructor
  instruction_count instructions = std::move(to_be_moved_instructions);

  frequency clock_rate(2.6);
  period p1 = inverse(clock_rate);

  // move construct from rvalue temporary
  period p2 = inverse(frequency(3.2));

  return 0;
}
