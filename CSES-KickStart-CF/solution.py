'''
	Time complexity: O(N ^ 2)
	Space complexity: O(N)

	where 'N' is the size of the given array.
'''

# Swap arr[i] with arr[j]
def swap(arr, i, j):

    arr[i], arr[j] = arr[j], arr [i]
    return arr


# Returns index of element if present in array, else return -1.
def indexOf(arr, element):
    for i in range(len(arr)):
        if (arr[i] == element):
            return i

    return -1


# Returns the minimum number of swaps required to sort the array.
def minSwaps(arr):

    count = 0
    temp = arr[0:len(arr)]

    temp.sort()

    for i in range(len(arr)):

        '''
            Checking whether the current element
            is at the right place or not.
        '''
        if (arr[i] != temp[i]):
            count += 1

            '''
                Swap the current element with the right index
                so that arr[0] to arr[i] is sorted.
            '''
            swap(arr, i, indexOf(arr, temp[i]))

    return count


