This is an implementation of a `std::vector` like growable array, but in plain
C code. The result is a type safe, easy to use, dynamic array that has a
familiar set of operations.

It works by using the same trick as many allocators, which is to slightly
allocate more data than requested, and using that extra padding in the front
as storage for meta-data. Thus any non-null vector looks like this in memory:

	+------+----------+---------+
	| size | capacity | data... |
	+------+----------+---------+
	                  ^
	                  | user's pointer

Where the user is given a pointer to first element of `data`. This way the
code has trivial access to the necessary meta-data, but the user need not be
concerned with these details. The total overhead is `2 * sizeof(size_t)` per
vector.
