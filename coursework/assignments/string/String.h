#ifndef STRING_H
#define STRING_H

#include <iostream>
#include <cstddef>

class String {
public:
    String();
    explicit String(const char* s);
    ~String() noexcept;
    String(const String& s) noexcept;
    const char* data() const;
    bool empty() const;
    size_t size() const;
    String& append(const String& str);
    String& append(const char* str);

private:
    static int count_;
    char* data_;
    size_t len_;
};

#endif // STRING_H
