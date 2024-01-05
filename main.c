/*

This is the Fractol Project
Julies set & Mandelbrot set
Able to take command line args to disipline
    whitch fractal render
    able to take command line args to shape Julia, i.e (in exemplo) x, y coordinates
    
    ESC close the process without leaks
    CLICKS x Windows close the process without leaks
            Code has to pass norminetted




*/
#include "fractol.h"



/* "I have two kind of prom"
*  ~./fractol mandelbrot
* ~./fractol julia <real> <i>
*the main funtion has to be TL,DR  Too Long; Didn't Read    
*/

int main (int ac, char *av[])
{   
    t_fractal   fractal; //esta es la estructura que me va a buffering la imagen
    if ((2 == ac) && ft_strncmp(av[1], "mandelbrot", 10) == 0 || (4 == ac) && ft_strncmp(av[1], "julia", 5) == 0)
    {
        //Promt correct
        fractal.name = av[1];
        fractal_init(&fractal); //1 paso
        fractal_render(&fractal); //2 paso  
        mlx_loop(fractal.mlx_connection);

    }
    else
    {
        putstr_fd(ERROR_MESSAGE, STDERR_FILENO); 
        exit(EXIT_FAILURE);
    }
return (0);
}