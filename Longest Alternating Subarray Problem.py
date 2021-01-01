# Function to find the length of longest sublist with alternative
# Positive and Negative elements


def find_longest_sublist(A):
    """ Find the longest sublist """
    max_len = 1
    end_index = 0
    curr_len = 1
    
    for i in range(1, len(A)):
        if A[i] * A[i - 1] < 0:
            curr_len += 1
            if curr_len > max_len:
                max_len = curr_len
                end_index = i
        else:
            curr_len = 1
    
    sub_list = A[end_index - max_len + 1:end_index + 1]
    print("The Longest alternative sublist is : ", sub_list)


if __name__ == '__main__':
    A = [1, -2, 6, 4, -3, 2, -4, -3]
    find_longest_sublist(A)
