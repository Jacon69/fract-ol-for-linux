#include "fractol.h"
// ft_strncmp Compare two streem and return and if they are iquals
int ft_strncmp(char *str1, char *str2, int n)
{
    if (NULL == str1 || NULL == str2 )
        return (-1);
    while (*str1 == *str2 && *str1 && n > 0)
    {
        str1++;
        str2++;
        n--;
    }
    return (*str1 - *str2);
}

void  putstr_fd(char *str, int fd)
{
    if (NULL == str || 0 > fd )
        return;
    if (*str != '\0')
    {
        write(fd, str, 1);
        putstr_fd(str +1, fd);
    }
} 