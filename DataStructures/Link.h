#ifndef LINK_H
#define LINK_H

template <typename E> class Link {
public:
  E element;
  Link *next;
  explicit Link(const E &elemval, Link *nextval = nullptr) {
    element = elemval;
    next = nextval;
  }
  explicit Link(Link *nextval = nullptr) { next = nextval; }
};

#endif
