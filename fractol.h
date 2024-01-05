
#ifndef FRACTOL_H
# define FRACTOL_
# include <stdio.h>  //   fprint debbugin quitar
# include <math.h> //PAra funciones con complejos
# include <unistd.h>   //write()
# include <stdlib.h>   //exit() EXIT_FAILURE    malloc free
# include "minilibx-linux/mlx.h"

#define ERROR_MESSAGE "Please enter \n \t\"./fractol mandelbrot\" or \"./fractol julia <value1_real> <value2_img>\"\n"
/*
*We use de square in the window definition to easier the math
*/

#define WIDTH 800 
#define HEIGHT 800
// Colores en formato RGB
#define BLACK   0x000000
#define RED     0xFF0000
#define GREEN   0x00FF00
#define BLUE    0x0000FF
#define YELLOW  0xFFFF00
#define CYAN    0x00FFFF
#define MAGENTA 0xFF00FF
#define WHITE   0xFFFFFF
#define PINK      0xFF1493
#define ORANGE    0xFFA500
#define PURPLE    0x800080
#define TURQUOISE 0x40E0D0
#define LIME      0x00FF00
#define CYAN      0x00FFFF





typedef struct s_complex  //er
{
    // real
    double  x;
    // i
    double  y;
}           t_complex;


/* IMAGE
*This de basically a Pixel buffer
* values obtained from mlx_data_addr() osea lo que te devueleve esta 
*función que hay en la imagen cuando se llama con esta función
*/
typedef struct	s_img {
	void	*img_ptr; //Pointer to image struc
	char	*pixel_ptr; //point to Pixell inicial
	int		bpp; // bits_per_pixel; usually 32 depend of the system
	int		line_len; //line_length; lo vamos a usar en la función de pixel 
                //put funtion nº de byte necesarios pata una fila de pixels
	int		endian; // no importante para manejo de bits en ciertas instrucciones
}				t_img;

/* fractal ID
*MLX stuff
*Image 
*Hooks Values
*/
typedef struct s_fractal {
    char    *name;
    //MLX
    void    *mlx_connection; // viene de mlx_init()
    void    *mlx_window; // viene de mlx_newwindow()
    //IMAGE
    t_img   img;
    //Hooks Values  Pendiente
    double escape_value; // hypotenusa  >2
    int iterations_definitions; //42

}       t_fractal;


//***Prototypes
//**** INIT
void fractal_init(t_fractal *fractal);
void    fractal_render(t_fractal *fractal);
//**** string utils ***
int ft_strncmp(char *str1, char *str2, int n);
void  putstr_fd(char *str, int fd);
/* math util*/

double map(double unscaled_num, double new_min, double new_max, double old_min, double oldmax);

t_complex square_complex(t_complex z);
t_complex sum_complex(t_complex s1, t_complex s2);

#endif


