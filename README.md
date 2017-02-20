# strong

A C++ library for creating strong (aka opaque) typedefs

## When should I use strong typedefs?

Strong typedefs prevent (potentially dangerous) implicit conversions when dealing with custom types.
The default typedefs provided by C and C++ are not sufficient for type safety.
A custom class that wraps a plain-old-data type can provide that type safety.
There is an [excellent talk](https://www.youtube.com/watch?v=jLdSjh8oqmE) on the subject from CppCon2015 by Kyle Markley.
More motivation can be found in a [blog post](http://foonathan.net/blog/2016/10/19/strong-typedefs.html) about type safety by Jonathan Müller.
