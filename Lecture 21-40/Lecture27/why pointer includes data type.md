why creating pointer is like: \
`int *ptr = &value`

and not something like \
`pointer ptr = &value;`

Two reasons: \
in `int *ptr = &value;`

1. It shows what kind of data this pointer is pointing at like int, bool, float, etc.
2. Memory management gets easy as compilor knows data type.
