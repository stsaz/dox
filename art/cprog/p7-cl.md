# C syntax with examples: Conditions, Loops

Contents:

* Conditional statements
	* if
	* Ternary conditional
	* switch
* Loops
	* while
	* do..while
	* for
	* break
	* continue
	* goto

## Conditional statements

### if

	int i = ...;
	if (i == 2) {
		// code to execute if `i` is 2
	}

It's not required to use `{}` if there's just 1 statement as body.

	int i = ...;
	if (i == 2)
		i = 0;

Condition with an `else`

	int i = ...;
	if (i == 2) {
		// code to execute if `i` is 2
	} else {
		// code to execute if `i` is not 2
	}

Multiple conditions

	int i = ...;
	if (i == 2) {
		// code to execute if `i` is 2
	} else if (i == 4) {
		// code to execute if `i` is 4
	} else {
		// code to execute if none of the above
	}

### Ternary conditional

	int i = ...;
	int n = (i == 2) ? 4 : 8;
	// `n` is 4 if `i == 2` or 8 otherwise

### switch

`switch` is convenient to use instead of multiple `if..else if` statements which test the same variable.

	int i = ...;
	switch (i) {
	case 0:
		// code to execute if `i` is 0
		break;
	case 1:
		// code to execute if `i` is 1
		break;
	}

`switch` with `default`

	int i = ...;
	switch (i) {
	case 0:
		// code to execute if `i` is 0
		break;
	case 1:
		// code to execute if `i` is 1
		break;
	default:
		// code to execute if none of the above
	}

`switch` with `fallthrough`

	int i = ...;
	switch (i) {
	case 0:
		// code to execute if `i` is 0
		// fallthrough
	case 1:
		// code to execute if `i` is 0 or 1
		break;
	}

When `// fallthrough` is used instead of `break;` it means that execution continues (falls through) to the next `case` block.


## Loops

Loops are used to execute the same code multiple times.

### while

`while` loop checks if statement is true before entering the loop body.
If statement is false, loop body isn't executed at all.

	int i = 0;
	while (i < 10) {
		// this loop body is executed 10 times
		i++;
	}

### do..while

`do..while` loop checks if statement is true after the body is processed.
If statement is false, loop body isn't executed again.

	int i = 0;
	do {
		// this loop body is executed 10 times
		i++;
	} while (i < 10);

### for

`for` loop consists of 3 parts:

1. Statement which is executed only once before the loop.  Usually, we define a new variable.
2. Condition statement is checked before entering the loop body.  Usually, we check for the variable's value.
3. Statement which is executed every time after the loop body.  Usually, we increment the variable.

	for (int i = 0;  i < 10;  i++) {
		// this loop body is executed 10 times
	}

`for` loop with manual break condition:

	for (int i = 0;  ;  i++) {
		if (i < 10)
			break;
		// this code is executed is executed 10 times
	}

Simple `for` loop:

	for (;;) {
		if (...)
			break;
		// this code is executed until the condition above becomes true
	}

### break

Using `break` instruction we can exit loops at any time.

	for (int i = 0;  i < 10;  i++) {
		// this part of loop body is executed from 1 to 10 times
		if (...) {
			// this part of loop body is executed 1 time only before exitting the loop
			break;
			// code here would never be executed
		}
		// this part of loop body is executed from 0 to 10 times
	}

### continue

Using `continue` instruction we can jump to the condition checking code at any time.

	for (int i = 0;  i < 10;  i++) {
		if (...) {
			continue;
			// code here would never be executed
		}
		// this part of loop body is executed from 0 to 10 times
	}

### goto

When a `switch` statement is used inside a loop we can't use `break` to exit the loop while we are inside `switch`.

	for (;;) {
		switch (...) {
		case 0:
			break; // exit `switch`, but not `for`
		}
	}

We solve this by using `goto`:

	for (;;) {
		switch (...) {
		case 0:
			goto done; // exit loop immediately
		}
	}

	done:
	...

We can use the same technique for nested loops.

	for (;;) {
		for (...) {
			if (...)
				goto done; // exit both loops immediately
		}
	}

	done:
	...
