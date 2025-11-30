#ifndef MERGESORT_H
#define MERGESORT_H

#include "../DataStructures/Link.h"

template <typename E> Link<E> *findMiddle(Link<E> *head) {
  if (head == NULL || head->next == NULL)
    return head;

  Link<E> *slow = head;
  Link<E> *fast = head->next;

  while (fast != NULL && fast->next != NULL) {
    slow = slow->next;
    fast = fast->next->next;
  }

  return slow;
}

template <typename E, typename Comp>
Link<E> *merge(Link<E> *left, Link<E> *right, Comp comp) {
  Link<E> dummy;
  Link<E> *current = &dummy;

  while (left != NULL && right != NULL) {
    if (comp.prior(left->element, right->element)) {
      current->next = left;
      left = left->next;
    } else {
      current->next = right;
      right = right->next;
    }
    current = current->next;
  }

  if (left != NULL)
    current->next = left;
  else
    current->next = right;

  return dummy.next;
}

template <typename E, typename Comp>
Link<E> *mergesort(Link<E> *head, Comp comp) {
  if (head == NULL || head->next == NULL)
    return head;

  Link<E> *middle = findMiddle(head);
  Link<E> *rightHalf = middle->next;

  middle->next = NULL;

  Link<E> *leftSorted = mergesort(head, comp);
  Link<E> *rightSorted = mergesort(rightHalf, comp);

  return merge(leftSorted, rightSorted, comp);
}

template <typename E> Link<E> *mergesort(Link<E> *head) {
  if (head == NULL || head->next == NULL)
    return head;

  Link<E> *middle = findMiddle(head);
  Link<E> *rightHalf = middle->next;

  middle->next = NULL;

  Link<E> *leftSorted = mergesort(head);
  Link<E> *rightSorted = mergesort(rightHalf);

  Link<E> dummy;
  Link<E> *current = &dummy;

  while (leftSorted != NULL && rightSorted != NULL) {
    if (leftSorted->element < rightSorted->element) {
      current->next = leftSorted;
      leftSorted = leftSorted->next;
    } else {
      current->next = rightSorted;
      rightSorted = rightSorted->next;
    }
    current = current->next;
  }

  if (leftSorted != NULL)
    current->next = leftSorted;
  else
    current->next = rightSorted;

  return dummy.next;
}

#endif
