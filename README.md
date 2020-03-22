# Integral-Derivative
This program calculates the integral and the derivative of one of those functions ;

 f1(x) = x^2 / 4

 f2(X) = (-x^3 + 3x^2 + x-4√x)/2x√x

 f3(x) = sin(x)^2 - cos(x)^2

 f4(x) = sin(x)/1+cos(2x)

 f5(x) = e^x

 f6(x) = sinh(x)/ex^2

for calculating the integral , we used Riemann integral ;
* our distribution size is decided by the user .
* now we have the distribution and the points we take are the median points in the segment.
* by Riemann method we calculate the value of the function in the point and multiple it by the delta
  since we are working with equal delta for each segment ,
  we calculated the sum of the function values in the med points for each segments , and then
  multiple it with delta (which is equal for all segments ).
for calculating the derivative value ; 
 * calculate the value of function( point + h )
 * calculate the value of function ( point - h )
 * return the difference between the two value / 2*h .
The integral and derivative are done in infi.c
The NumericalAnalyzer contain the six different function and the main which runs the infi.c functions.

