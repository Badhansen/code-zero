# A naive recursive implementation
# of 0-1 Knapsack Problem
# Returns the maximum value that
# can be put in a knapsack of
# capacity W


def knapsack_rec(W, wt, val, n):
    """
    :param W: Maximum size of a knapsack
    :param wt: Items weight list
    :param val: Items value list
    :param n: Number of items
    :return: Returns the maximum value that can put in a knapsack capacity W

    Time Complexity: O(2^n): As there are redundant sub-problems
    Auxiliary Space: O(1): As no extra data structure has been for storing values
    """
    if n == 0 or W == 0:
        return 0
    if wt[n - 1] > W:
        return knapsack(W, wt, val, n - 1)
    else:
        return max(val[n - 1] + knapsack(W - wt[n - 1], wt, val, n - 1),
                   knapsack(W, wt, val, n - 1))


def knapsack(W, wt, val, n):
    """
    :param W: Maximum size of a knapsack
    :param wt: Items weight list
    :param val: Items value list
    :param n: Number of items
    :return: Returns the maximum value that can put in a knapsack capacity W

    Time Complexity: O(2^n): As there are redundant sub-problems
    Auxiliary Space: O(1): As no extra data structure has been for storing values
    """
    K = [[0 for x in range(W + 1)] for x in range(n + 1)]
    for i in range(n + 1):
        for w in range(W + 1):
            if i == 0 or w == 0:
                K[i][w] = 0
            elif wt[i - 1] <= w:
                K[i][w] = max(val[i - 1] + K[i - 1][w - wt[i - 1]],
                              K[i - 1][w])
            else:
                K[i][w] = K[i - 1][w]
    for i in range(n + 1):
        for w in range(W + 1):
            print(K[i][w], end=" ")
        print()
    return K[n][w]


val = [60, 100, 120]
wt = [10, 20, 30]
W = 50
n = len(val)
print(knapsack(W, wt, val, n))
