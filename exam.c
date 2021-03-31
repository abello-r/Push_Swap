#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int width;
int height;
char bg;

float x;
float y;
float w;
float h;
char type;
char color;

char *draw;

void output()
{
    int i = -1;
    while (++i < height)
    {
        write(1, draw + i * width, width);
        write(1, "\n", 1);
    }
    free(draw);
}


int check (float xw, float yh)
{
    if (xw < x || x + w < xw || yh < y || y + h < yh)
        return(0);
    if (xw < x + 1 || x + w < xw + 1 || yh < y + 1 || y + h < yh + 1)
        return(2);
    return(1);
}


void drawing(void)
{
    int xw = -1;
    int yh = -1;
    int hit = -1;

    while (++xw < width)
    {
        yh = -1;
        while (++yh < height)
        {
            hit = check((float)xw, (float)yh);
            if (hit == 2 || (hit == 1 && type == 'R'))
                draw[xw + yh * width] = color;
        }
    }
}

int parseo(FILE *file)
{
    int scan_ret = 0;
    int i = 0;

    if (fscanf(file, "%d %d %c\n", &width, &height, &bg) != 3)
        return(1);
    if (width < 1 || width > 300 || height < 1 || height > 300)
        return(1);
    if ((draw = malloc(width * height)) == NULL)
        return(1);
    while(i < width * height)
        draw[i++] = bg;
    while((scan_ret = fscanf(file, "%c %f %f %f %f %c\n", &type, &x, &y, &w, &h, &color)) == 6)
    {
        if (w <= 0 || h <= 0 || (type != 'r' && type != 'R'))
            return(1);
        drawing();
    }
    if (scan_ret != -1)
        return(1);
    output();
    return(0);
}

int main (int argc, char **argv)
{
    FILE *file;
    
    if (argc != 2)
    {
        write(1, "Error: arguments\n", 17);
        return(1);
    }
    if (!(file = fopen(argv[1], "r")) || parseo(file))
    {
        write(1, "Error: File | parseo\n", 21);
        return(1);
    }
    fclose(file);
    return(0);
}