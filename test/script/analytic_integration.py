from sympy import *

x,y,z,n = symbols('x y z n',positive = true)


f  =  x**n
print(simplify(integrate(f,( x, 0, 1-z-y),(y, 0, 1-z),(z,0,1))))