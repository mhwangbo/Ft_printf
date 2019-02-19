# Ft_printf
  Discover variadic functions in C in a particularly relevant context as well as learn about a great example of a basic "dispatcher" in C via the use of an array of function's pointers
  The key to a successful ft_printf is a well-structured and good extensible code.
  
## Mandatory part
- [x] You have to recode the libc’s printf function.
- [x] Your function will be called ft_printf and will be prototyped similarly to printf.
- [x] You won’t do the buffer management in the printf function.
- [x] You have to manage the following conversions: csp
- [x] You have to manage the following conversions: diouxX with the following flags: hh, h, l and ll.
- [x] You have to manage the following conversion: f with the following flags: l and L.
- [x] You must manage %%
- [x] You must manage the flags #0-+ and space
- [x] You must manage the minimum field-width
- [x] You must manage the precision

## Bonus part
- [x] More detailed conversions management: e and g. Be careful, your L flag must works with both of them to validate this bonus.
- [x] More detailed flags management: *, $ and ’.
- [x] Non-existing flags management: %b to print in binary, %r to print a string of nonprintable characters, %k to print a date in any ordinary ISO format etc.
- [x] Management of alter tools for colors, fd or other fun stuff like that :)
