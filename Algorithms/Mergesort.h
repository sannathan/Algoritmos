#ifndef MERGESORT_H
#define MERGESORT_H

#include "../DataStructures/Link.h"

// Função auxiliar para encontrar o meio da lista usando slow/fast pointers
template <typename E>
Link<E>* findMiddle(Link<E>* head) {
    if (head == NULL || head->next == NULL)
        return head;
    
    Link<E>* slow = head;
    Link<E>* fast = head->next;
    
    // Fast anda 2x mais rápido que slow
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    
    return slow;
}

// Função para mesclar duas listas ordenadas
template <typename E, typename Comp>
Link<E>* merge(Link<E>* left, Link<E>* right, Comp comp) {
    // Nó dummy para facilitar a construção da lista resultante
    Link<E> dummy;
    Link<E>* current = &dummy;
    
    // Enquanto ambas as listas têm elementos
    while (left != NULL && right != NULL) {
        // Compara usando o comparador fornecido
        if (comp.prior(left->element, right->element)) {
            current->next = left;
            left = left->next;
        } else {
            current->next = right;
            right = right->next;
        }
        current = current->next;
    }
    
    // Anexa o restante da lista que não acabou
    if (left != NULL)
        current->next = left;
    else
        current->next = right;
    
    return dummy.next;
}

// Função principal do Merge Sort para listas ligadas
template <typename E, typename Comp>
Link<E>* mergesort(Link<E>* head, Comp comp) {
    // Caso base: lista vazia ou com apenas 1 elemento
    if (head == NULL || head->next == NULL)
        return head;
    
    // Encontra o meio da lista
    Link<E>* middle = findMiddle(head);
    Link<E>* rightHalf = middle->next;
    
    // Quebra a lista em duas metades
    middle->next = NULL;
    
    // Ordena recursivamente cada metade
    Link<E>* leftSorted = mergesort(head, comp);
    Link<E>* rightSorted = mergesort(rightHalf, comp);
    
    // Mescla as duas metades ordenadas
    return merge(leftSorted, rightSorted, comp);
}

// Versão simplificada sem comparador (usa operator<)
template <typename E>
Link<E>* mergesort(Link<E>* head) {
    // Caso base: lista vazia ou com apenas 1 elemento
    if (head == NULL || head->next == NULL)
        return head;
    
    // Encontra o meio da lista
    Link<E>* middle = findMiddle(head);
    Link<E>* rightHalf = middle->next;
    
    // Quebra a lista em duas metades
    middle->next = NULL;
    
    // Ordena recursivamente cada metade
    Link<E>* leftSorted = mergesort(head);
    Link<E>* rightSorted = mergesort(rightHalf);
    
    // Mescla as duas metades ordenadas
    Link<E> dummy;
    Link<E>* current = &dummy;
    
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
    
    // Anexa o restante
    if (leftSorted != NULL)
        current->next = leftSorted;
    else
        current->next = rightSorted;
    
    return dummy.next;
}

#endif
