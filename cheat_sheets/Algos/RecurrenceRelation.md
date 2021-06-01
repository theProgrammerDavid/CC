### Recurrence Relation

------

There are two important things that one needs to figure out before  implementing a recursive function:

- `recurrence relation`: the relationship between the result of a problem and the result of its subproblems.
- `base case`: the case where one can compute the answer directly without any further recursion calls. Sometimes, the base cases are also called *bottom cases*, since they are often the cases where the problem has been reduced to the minimal scale, *i.e.* the bottom, if we consider that dividing the problem into subproblems is in a top-down manner.

> Once we figure out the above two elements, to implement a recursive function we simply call the function itself according to the  `recurrence relation` until we reach the `base case`.

