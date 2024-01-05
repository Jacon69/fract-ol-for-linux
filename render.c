#include "fractol.h"
/*
z = z**2 +c Siendo una serie recursiva donde z0=0  y c es el punto en el 
que estamos evaluando si pertenece al  conjunto de mandelbroc
*/

static void  my_pixel_put(int x ,int y, t_img *img ,int color)
{
    int offset;

    offset = (y * img->line_len) + (x * img->bpp / 8);
    *(unsigned int *)(img->img_ptr + offset) = color;

}

static void handle_pixel(int x,int y,t_fractal *fractal)
{
    t_complex   z;
    t_complex   c;
    int         i;
    int color;
    i = 0;
//1ª interacción
    z.x = 0.0;
    z.y = 0.0;
    c.x = map( x, -2, 2, 0, WIDTH);
    c.y = map( y, -2, 2, 0, HEIGHT);
    while (i < fractal->iterations_definitions)
    {
        z = sum_complex(square_complex(z),c);
        if ((z.x * z.x) + (z.y * z.y) > fractal->escape_value)   //Aquí expreso que cumple que la hipotenusa es mayor que 2
        {
            color = map(i, BLACK , WHITE, 0, fractal->iterations_definitions);
            my_pixel_put(x, y, &fractal->img, color);
            return;
        }
        ++i;
    }
    my_pixel_put(x, y, &fractal->img, LIME);

}

/*

*/

void    fractal_render(t_fractal *fractal)
{
    int x;
    int y;
    
    y=-1;
    while (++y < HEIGHT)
    {
        x=-1;
        while (++x < WIDTH)
        {
            handle_pixel(x,y,fractal);
        }
    }
    mlx_put_image_to_window(fractal->mlx_connection,
                            fractal->mlx_window,
                            fractal->img.img_ptr,
                            0,0);
}