
import time

def rwh_primes(n):
    # https://stackoverflow.com/questions/2068372/fastest-way-to-list-all-primes-below-n-in-python/3035188#3035188
    """ Returns  a list of primes < n """
    sieve = [True] * n
    for i in xrange(3,int(n**0.5)+1,2):
        if sieve[i]:
            sieve[i*i::2*i]=[False]*((n-i*i-1)/(2*i)+1)
    return [2] + [i for i in xrange(3,n,2) if sieve[i]]

print ("Starting test")
abs_start_time = time.time()
limit = 10**9
n = 10
while n < limit:
    start_time = time.time()
    rwh_primes(n)
    duration = time.time() - start_time
    print "Time taken: {}".format('% 2.3F' % duration) 
    n*=10

print ("Test Finished")
duration = time.time() - abs_start_time

print "Total time taken: {}".format('% 2.3F' % duration) 
              