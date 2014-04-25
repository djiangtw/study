#!/usr/bin/python
def bsort(L):
    """ (list) -> NonType
    
    Sort the items of L from smallest to largest.

    >>> L = [7, 3, 5, 2]
    >>> bsort(L)
    >>> L
    [2, 3, 5, 7]
    """
    # The index of the last unsorted item.
    end = len(L) - 1

    while end != 0:
        for i in range(end):
            if L[i] > L[i+1]:
                L[i], L[i+1] = L[i+1], L[i]
        end = end - 1

if __name__ == '__main__':
    import doctest
    doctest.testmod()
