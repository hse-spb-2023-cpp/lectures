#ifndef FOO_H_
#define FOO_H_

#include <iosfwd>  // smaller than <iostream>, only forward declarations
// namespace std { struct ostream; }  // bad!

struct Foo {};

std::ostream& operator<<(std::ostream&, const Foo&);

#endif  // FOO_H_
