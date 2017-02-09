#ifndef STRONG_TYPES_STRONG_TYPES_HPP
#define STRONG_TYPES_STRONG_TYPES_HPP

#include <type_traits>

/**
 * Namespace for creating strong typedefs.
 */
namespace strong_types {

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
   * Copy constructor.
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

}

#endif //STRONG_TYPES_STRONG_TYPES_HPP
