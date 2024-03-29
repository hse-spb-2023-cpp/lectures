* Almost all programming languages and libraries work with *bytes*.
  Not numbers, not characters, bytes, octets even (there were non 8-bit bytes).
* Byte is a number between 0 and 255 (not always, see -128..127).
* You cannot see bit inside a byte. Only arithmetic operations: divide byte by two, take a modulo...
  Even `>>` and `<<`, `&`.
* Interpreting bytes is a question of convention.

* Negative numbers are modulo 256 (two complement)
  * -128 = 128 (mod 256)
  * -1 = 255 (mod 256)
* Multibyte integers are typically stored in either order:
  * little endian (x86): `a[0] + 256 * a[1]`
      0x1234 ~ 0x34   0x12
  * big endian ("network byte order"): `a[0] * 256 + a[1]`
      0x1234 ~ 0x12   0x34
