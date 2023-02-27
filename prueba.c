#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>

char *my_strcpy (char *dest, char const *src);
void my_putchar (char c);
int my_putstr(char const *str);
int my_put_nbr (int nb);
int my_printf(const char *format, ...)
{
    va_list arguments;
    int index = 0;
    int symbol = *format;

    va_start(arguments, format);
    while (symbol != '\0') {
        symbol = symbol + 1;
        while (symbol != '%') {
            printf(va_arg (arguments, char));
            //printf ("%s \n", "Educative");
            my_putchar('\n');
            return(0);
        }
        symbol = symbol + 1;
        return(0);
    }

    while (format[index]) {
        if(format[index] == 'd') {
        my_put_nbr(va_arg(arguments, int));
        }else if (format[index] == 'c') {
            my_putchar(va_arg(arguments, int));
        }
        index = index + 1;
        return 0;
    }
    va_end(arguments);
    return 0;
}

int main ()
{
    char str [5];
    my_strcpy (str, "toto");
    str [1] = 6;
    my_printf("%d\n", 90);
    my_printf("%c\n", 'f');
    return 0;
}