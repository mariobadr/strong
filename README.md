# strong

A C++ library for creating strong (aka opaque) typedefs

## When should I use strong typedefs?

Strong typedefs prevent (potentially dangerous) implicit conversions when dealing with custom types.
The default typedefs provided by C and C++ are not sufficient for type safety.
A custom class that wraps a plain-old-data type can provide that type safety.
There is an [excellent talk](https://www.youtube.com/watch?v=jLdSjh8oqmE) on the subject from CppCon2015 by Kyle Markley.
More motivation can be found in a [blog post](http://foonathan.net/blog/2016/10/19/strong-typedefs.html) about type safety by Jonathan Müller.

## Should I use this library?

I created this library to teach myself more about strong typedefs and how they are implemented in C++.
I would not recommend using this library in its current form.
The aforementioned names, Kyle Markley and Jonathan Müller, each have their own (more complete) libraries for strong typedefs that you can check out [here](https://sourceforge.net/projects/opaque-typedef/) and [here](https://github.com/foonathan/type_safe).

## Using this library (compilation)

This is a header-only library, so you can simply copy the header file into your project to use it.
Alternatively, you can install it or add it as a subdirectory to your project and then use CMake.
To use CMake, add the subdirectory and then use ``target_link_libraries`` with ``strong``.

## Creating a strong type

```C++
#include <strong.hpp>
#include <iostream>

struct my_type : strong::type<my_type, int>
{
  // inherit the base class's constructors
  using strong::type<my_type, int>::type;
}

int main()
{
  my_type test(52);
  
  // we can access the underlying value with the get function
  std::cout << strong::get(test) << "\n";
  
  return 0;
}
```
