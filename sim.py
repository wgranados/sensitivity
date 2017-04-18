#!/usr/bin/python3
import sys


def usage():
    """
    Prints usage instructions for script to standard out 
    :return: None
    """
    print('Usage:\n\tsim NUM [LOG]')
    print('\tNUM - number to create a superset on in base 10 and greater than 0')
    print('\tLOG - optional, print the game to standard out, pass in as yes')


def logger():
    pass



def differ_by_one_bit(num_one, num_two):
    """
    Determines if two numbers differ by one bit.
    :param num_one: int, param1
    :param num_two: int, param2 
    :return: True if num_one and num_two differ by 1 bit
    """
    # bitwise
    n = num_one ^ num_two
    return (n & n-1) == 0


def simulate(num):
    """
    
    :param num: int, number of ordinals to go up to
    :return: True or False
    """
    adj = [[] for i in range(num)]
    for i in range(1, num+1):
        for j in range(1, num+1):
            if differ_by_one_bit(i, j):
                adj[i].append(j)



if __name__ == '__main__':
    argv = list(sys.argv)
    if len(argv) <= 1 or len(argv) > 3:
        usage()
        exit(1)

    N = int(sys.argv[1], 10)
    result = None
    if N > 0:
        simulate(N)
    else:
        usage()
        exit(1)


