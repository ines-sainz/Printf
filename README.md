# FT\_PRINTF 🔨✨

## Project Overview

`ft_printf` is a custom implementation of the standard C function `printf()`, designed to deepen understanding of variadic functions and formatted output.

It explores how one of the most fundamental functions in C operates internally. It involves handling a variable number of arguments, parsing format strings, and producing well-structured output for different data types.

By rebuilding printf() from scratch, it encourages clean code practices and modular design. It also helps solidify concepts crucial for systems-level programming.

---

## What Does `ft_printf()` Do? 🧠


The `ft_printf()` function mimics the behavior of the standard C `printf()` by formatting and printing data based on a format string and a variable number of arguments.
Its prototype looks like this:

```c
int ft_printf(const char *format, ...);
```

It supports multiple format specifiers such as:

* `%c` – print a single character
* `%s` – print a string
* `%p` – print a pointer in hexadecimal format
* `%d` – print a signed integer
* `%i` – print a signed integer
* `%u` – print an unsigned integer
* `%x` – print an unsigned hexadecimal (lowercase)
* `%X` – print an unsigned hexadecimal (uppercase)
* `%%` – print a literal `%` sign

---

## What Is a Variadic Function? 🔄

A **variadic function** in C is one that accepts a variable number of arguments. This is achieved using macros defined in `<stdarg.h>`:

* `va_start()` – Initializes access to the variadic arguments.
* `va_arg()` – Accesses the next argument.
* `va_end()` – Cleans up.

`ft_printf()` uses these tools to read and process arguments dynamically based on the format string.

---

## Key Aspects 📌

* 🧠 **Variadic Functions (`<stdarg.h>`)** The implementation requires using `va_start`, `va_arg`, and `va_end` to manage a variable number of arguments — key concept in advanced C programming.

* 🧹 **Format String Parsing** Parse and interpret complex format strings and represent them correctly with precision

* 🔠 **Type Handling** Properly convert and display different data types like integers, characters, strings, and pointers

* 🧱 **Modular Code Design** Logic in small, testable and reusable components that are easy to extend and maintain

* 🔊 **Custom Output** Use `write()` directly to output to the console, mimicking low-level printing without relying on standard buffering

* 🐞 **Robustness and Debugging:** Addressed edge cases like null strings and unsupported format specifiers for a stable and reliable implementation.
