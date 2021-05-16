# C syntax with examples: Structures

* Initialization
* Structure type alias with `typedef`
* Structure alignment
* Structure bitfields
* Structure pointers
* Unions

Structure is a complex type which contains another types.
An instance of a structure is called *object*.
Members of a structure object are called *fields*.

	struct name {
		int i;
		char c;
	};
	struct name o;
	o.i = 0;

	struct { // unnamed structure
		int i;
		char c;
	} o;
	o.i = 0;

Structures can nest each other:

	struct nested_s {
		int i;
	};
	struct name {
		struct nested_s nested;
	};
	struct name o;
	o.nested.i = 0;

Structure objects can be defined immediately:

	struct {
		int i;
		char c;
	} o;


### Initialization

Objects fields are not initialized automatically, which means that they may have any random value.
It's an error to read uninitialized object fields and thus it's always good to initialize to zero.
Structure object fields can be immediately initialized to zero values:

	struct name {
		int i;
		char c;
	};
	struct name o = {};

or explicitly:

	struct name {
		int i;
		char c;
	};
	struct name o = {
		0,
		0,
	};

It's better to use field names when initializing a structure object:

	struct name {
		int i;
		char c;
	};
	struct name o = {
		.i = 0,
		.c = 0,
	};


### Structure type alias with `typedef`

	struct s {...};
	typedef struct s  my_type;
	my_type o;


### Structure alignment

It's believed that CPU operates (reads and writes) faster on numbers at memory address aligned to their size.
By default, each structure field is aligned to a particular number which is selected by compiler using the size of this field.
Thus, every `short` field is aligned to 2;  every `int` field is aligned to 4 and so on.

This program prints the size of an object and offset of its each field.

	#include <FFOS/std.h>

	void main()
	{
		struct {
			long long l;
			int i;
			short s;
			char c;
			// 1 byte hole here
		} o;
		fflog("sizeof=%L", sizeof(o));
		fflog("l.offset=%L", (long long)&o.l - (long long)&o);
		fflog("i.offset=%L", (long long)&o.i - (long long)&o);
		fflog("s.offset=%L", (long long)&o.s - (long long)&o);
		fflog("c.offset=%L", (long long)&o.c - (long long)&o);
	}

It prints:

	sizeof=16
	l.offset=0
	i.offset=8
	s.offset=12
	c.offset=14

Observe that by changing the structure declaration this way:

	struct {
		int i;
		// 4 byte hole here
		long long l;
		short s;
		char c;
		// 5 byte hole here
	} o;

The program's result is completely different now:

	sizeof=24
	l.offset=8
	i.offset=0
	s.offset=16
	c.offset=18


### Structure bitfields

To use the storage allocated for a structure more effectively we use bitfields.

	struct name {
		int b1 :1;
		int b2 :31;
	};

The size of this structure is 4 bytes, even if there are two `int` fields, because they are actually bitfields:
* `b1` uses just 1 bit of storage.
* `b2` uses 31 bits of storage.


### Structure pointers

When accessing structure fields through a pointer we use `(*pointer).` statement or `->` operator.

	struct name {
		int i;
	};
	struct name o;
	o.i = 0;

	struct name* p = &o;
	(*p).i = 1;
	// `o.i` is 1 now

	p->i = 2;
	// `o.i` is 2 now


### Unions

Unions are similar to structures - they can contain other types too.
But all fields inside a union share the same memory space.
In other words, compiler maps different types to a single memory region so we can access it in different ways convenient to us.
For example, it may be convenient when working with network packets.

	union name {
		int i;
		char lo;
	} u;
	u.i = -1;
	// now u.lo == 0xff on AMD64

The size of a union always equals to the size of its largest field.

Structures and unions can be mixed together.

	union name {
		int i;
		char c[4];
		struct {
			char a;
			int b;
		} o;
	} u;
