#!/usr/bin/python3
import sys
import queue


def usage():
    """
    Prints usage instructions for script to standard out 
    :return: None
    """
    print('Usage:\n\tsim N K [LOG]')
    print('\tN- number to create a superset on in base 10 and greater than 0')
    print('\tK- some shit')
    print('\tLOG - optional, print the game to standard out, pass in as yes')


def get_nk(args):
    """
    Attempts to parse N,K from input.
    :param args: list of str
    :return: tuple(int, int)
    """
    try:
        n = int(args[1], 10)
        k = int(args[2], 10)
        return n, k
    except ValueError:
        return -1, -1


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


def simulate(n, k):
    """
    
    :param num: int, number of ordinals to go up to
    :return: True or False
    """
    adj = {'0'*k:[]}
    q = queue.Queue()
    q.put(adj)
    while not q.empty():
        sub_graph = q.get()
        for key in sub_graph:
            for i in range(n):





if __name__ == '__main__':
    argv = list(sys.argv)
    if len(argv) <= 1 or len(argv) > 3:
        usage()
        exit(1)
    N, K = get_nk(argv)
    if N > 0 and K > 0:
        simulate(N, K)
    else:
        usage()
        exit(1)


