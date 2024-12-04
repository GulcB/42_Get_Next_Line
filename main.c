#include <stdio.h>
#include "get_next_line.h"
#include "get_next_line_bonus.h"

#define MAX_LINES 1000

int main()
{
    char *read;
    char *line[MAX_LINES];
    int line_count;
    int i;
    int fd;
    int fd2;

    line_count = 0;
    i = 0;

    fd = open("main.c", O_RDONLY);
    fd2 = open("a.txt", O_CREAT | O_WRONLY | O_TRUNC, 0777);

    while ((read = get_next_line(fd)) != NULL)
        line[line_count++] = read;

    i = line_count -1;
    while (i >= 0)
    {
        write(fd2, line[i], ft_strlen(line[i]));
        free(line[i]);
        i--;
    }
}
