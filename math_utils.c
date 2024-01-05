#include "fractol.h"
 /*
 This funtion adapt the values of the windows to the values that we need for the result
 mandelbrot set are between -2 and 1   we adap the values  [0..799]-> [-2..2]
  */
double map(double unscaled_num, double new_min, double new_max, double old_min, double oldmax) 
{
    return (new_max - new_min) * (unscaled_num - old_min) / (oldmax - old_min) + new_min;
}

t_complex sum_complex(t_complex s1, t_complex s2)
{
    t_complex result;
    
    result.x = s1.x +s2.x;
    result.y = s1.y +s2.y;
    return(result);
}


t_complex square_complex(t_complex z)
{
    t_complex result;
    result.x = (z.x * z.x) - (z.y * z.y) ;
    result.y = 2 * z.x +z.y;
    return(result);

}