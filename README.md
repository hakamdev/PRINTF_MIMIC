# PRINTF_MIMIC
This project is a function that mimics the libc printf function!

### Makefile Rules
``` shell
$> make ###creates the libftprintf.a library!
```
``` shell
$> make NAME=<name.a> ###creates the library with the given <name.a>!
```
``` shell
$> make clean ###cleans up the object files (*.o)!
```
``` shell
$> make fclean ###cleans up the whole project (*.o & *.a)!
```
``` shell
$> make re ###rebuilds the libftprintf.a!
```
``` shell
$> make norm ###checks the *.c & *.h files for norm errors!
```
### The Ft_printf Support
  My ft_printf support the following formats: %D  %d  %i  %u  %x  %X  %p  %c  %s  %%</br>
  And the following flgas: - 0 . *
