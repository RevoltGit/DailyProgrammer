#include <err.h>
#include <errno.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

static void
dogen(bool *cur, bool *next, size_t len)
{
        size_t i;
        bool left, right;

        for (i = 0; i < len; i++) {
                left = (i > 0) ? cur[i - 1] : false;
                right = (i < len - 1) ? cur[i + 1] : false;
                next[i] = left ^ right;
        }
}

static void
printline(bool *line, size_t len)
{
        size_t i;

        for (i = 0; i < len; i++)
                putchar(line[i]? 'x' : ' ');
        putchar('\n');
}

int
main(int argc, char **argv)
{
        bool *line, *next, *tmp;
        char *p;
        size_t len;
        unsigned i;

        if (argc < 2)
                errx(1, "input");
        len = strlen(argv[1]);

        line = malloc(len);
        if (line == NULL)
                err(1, "malloc");
        next = malloc(len);
        if (next == NULL)
                err(1, "malloc");

        for (p = argv[1]; *p; p++)
                line[p - argv[1]] = (*p == '1')? true : false;

        for (i = 0; i < 26; i++) {
                printline(line, len);
                dogen(line, next, len);
                tmp = line;
                line = next;
                next = tmp;
        }

        return (0);
}
