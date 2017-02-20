#ifndef STRONG_STRONG_HPP
#define STRONG_STRONG_HPP

#include <type_traits>
#include <utility>

/**
 * Namespace for creating strong typedefs.
 */
namespace strong {

/**
 * A strong typedef wrapper around some Type.
 *
 * Allows the programmer to define a strong type to avoid comparing values that have the same type
 * but are logically different. For example, IDs in a geographic map application for intersections
 * and streets may both be integers, but one should not logically compare an intersection ID with
 * a street ID.
 *
 * Strong typedefs that inherit from this class can be explicitly converted to their base Type,
 * but not implicitly converted. For more information please see:
 * http://en.cppreference.com/w/cpp/language/cast_operator
 *
 * @tparam Tag A unique identifier for this type
 * @tparam Type The actual type (e.g. int) to use
 */
template<class Tag, typename Type>
class type {
public:
  /**
   * The default constructor of type will attempt to initialize the underlying value with its own
   * default constructor.
   */
  constexpr type() : value()
  {
  }

  /**
   * Initialize the underlying value via a copy or move.
   *
   * @param v The value to copy.
   */
  explicit constexpr type(Type const &v) : value(v)
  {
  }

  /**
   * Move constructor.
   *
   * If Type's move constructor does not throw, then this move constructor will have noexcept
   * enabled, which will allow for certain optimizations. For more information, please refer
   * to https://akrzemi1.wordpress.com/2014/04/24/noexcept-what-for/
   *
   * @param v The value to move.
   */
  explicit constexpr type(Type && v) noexcept(std::is_nothrow_move_constructible<Type>::value)
    : value(static_cast<Type &&>(v))
  {
  }

  /**
   * Enables explicit conversion of the type.
   *
   * @return The underlying value.
   */
  explicit operator Type &() noexcept
  {
    return value;
  }

  /**
   * Enables const-correct explicit conversion of the type.
   *
   * @return The underlying value.
   */
  explicit constexpr operator Type const &() const noexcept
  {
    return value;
  }
private:
  Type value;
};

namespace detail {
/**
 * A dummy function used to help determine the type of the underlying value of a strong typedef.
 */
template <class Tag, typename Type>
Type dummy_function(type<Tag, Type>);
}

/**
 * Determine the type of the underlying value of a strong typedef.
 */
template <class Typedef>
using underlying_type = decltype(detail::dummy_function(std::declval<Typedef>()));

/**
 * Operations to enable on strong typedefs.
 */
namespace op {

/**
 * Tests for equality or inequality between identical strong types.
 *
 * @tparam Tag The strong typedef to compare.
 * @tparam Result The return type of the comparison
 */
template<class Tag, typename Result = bool>
class equals {
public:
  /**
   * Test for equality.
   *
   * @param lhs The left-hand side of the relational expression.
   * @param rhs The right-hand side of the relational expression.
   * @return The result of the comparison.
   */
  friend constexpr Result operator==(Tag const &lhs, Tag const &rhs) {
    using type = underlying_type<Tag>;
    return static_cast<type const &>(lhs) == static_cast<type const &>(rhs);
  }

  /**
   * Test for inequality.
   *
   * @param lhs The left-hand side of the relational expression.
   * @param rhs The right-hand side of the relational expression.
   * @return The result of the comparison.
   */
  friend constexpr Result operator!=(Tag const &lhs, Tag const &rhs) {
    return !(lhs == rhs);
  }
};
}

}

#endif //STRONG_STRONG_HPP
