//
// Created by Felipe Costa on 4/22/16.
//

#ifndef CROSSENGINEDESKTOP_OPTIONAL_H
#define CROSSENGINEDESKTOP_OPTIONAL_H

class optional_empty {
};

template<unsigned long size>
class optional_base {
public:
    // Default - invalid.

    optional_base() : m_bValid(false) { }

    optional_base &operator=(optional_base const &t) {
        m_bValid = t.m_bValid;
        return *this;
    }

    //Copy constructor
    optional_base(optional_base const &other)
            : m_bValid(other.m_bValid) { }

    //utility functions
    bool const valid() const { return m_bValid; }

    bool const invalid() const { return !m_bValid; }

protected:
    bool m_bValid;
    char m_data[size];  // storage space for T
};

template<class T>
class optional : public optional_base<sizeof(T)> {
public:
    // Default - invalid.

    optional() { }

    optional(T const &t) {
        construct(t);
        this->m_bValid = (true);
    }

    optional(optional_empty const &) { }

    optional &operator=(T const &t) {
        if (this->m_bValid) {
            *GetT() = t;
        }
        else {
            construct(t);
            this->m_bValid = true;    // order important for exception safety.
        }

        return *this;
    }

    //Copy constructor
    optional(optional const &other) {
        if (other.m_bValid) {
            construct(*other);
            this->m_bValid = true;    // order important for exception safety.
        }
    }

    optional &operator=(optional const &other) {
        assert(!(this == &other));    // don't copy over self!
        if (this->m_bValid) {                        // first, have to destroy our original.
            this->m_bValid = false;    // for exception safety if destroy() throws.
            // (big trouble if destroy() throws, though)
            destroy();
        }

        if (other.m_bValid) {
            construct(*other);
            this->m_bValid = true;    // order vital.

        }
        return *this;
    }


    bool const operator==(optional const &other) const {
        if ((!valid()) && (!other.valid())) { return true; }
        if (valid() ^ other.valid()) { return false; }
        return ((**this) == (*other));
    }

    bool const operator<(optional const &other) const {
        // equally invalid - not smaller.
        if ((!valid()) && (!other.valid())) { return false; }

        // I'm not valid, other must be, smaller.
        if (!valid()) { return true; }

        // I'm valid, other is not valid, I'm larger
        if (!other.valid()) { return false; }

        return ((**this) < (*other));
    }

    ~optional() { if (this->m_bValid) destroy(); }

    // Accessors.

    T const &operator*() const { return *GetT(); }

    T &operator*() { return *GetT(); }

    T const *const operator->() const { return GetT(); }

    T *const operator->() { return GetT(); }

    //This clears the value of this optional variable and makes it invalid once again.
    void clear() {
        if (this->m_bValid) {
            this->m_bValid = false;
            destroy();
        }
    }

    //utility functions
    bool const valid() const { return this->m_bValid; }

    bool const invalid() const { return !this->m_bValid; }

private:


    T const *const GetT() const { return reinterpret_cast<T const *const>(this->m_data); }

    T *const GetT() { return reinterpret_cast<T *const>(this->m_data); }

    void construct(T const &t) { new(GetT()) T(t); }

    void destroy() { GetT()->~T(); }
};

#endif //CROSSENGINEDESKTOP_OPTIONAL_H
