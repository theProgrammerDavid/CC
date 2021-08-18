import math

def is_prime(num):
   for val in range(2, int(math.sqrt(num)) + 1):
       if num % val == 0:
           return False

   return True

def largest_prime(num):
   maxp = 0
   n = int(math.sqrt(num)) + 1
   for val in range(2, n):

       if num % val == 0:
           if is_prime(val):
               maxp = max(maxp, val)

           if is_prime(num // val):
               maxp = max(maxp, num // val)

   if not maxp:
       return num

   return maxp

number = int(input())

l = largest_prime(number)

if l == number:
   count = 0

else:
   count = 1

number = l
while number > 0:

   while is_prime(number):

       number -= 1
       count += 1
       if number == 0:

           print(count)
           break

   number = largest_prime(number)

   count += 1

