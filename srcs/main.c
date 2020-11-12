/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vminomiy <vminomiy@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 20:58:41 by vminomiy          #+#    #+#             */
/*   Updated: 2020/11/12 19:08:17 by vminomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "msh.h"

char        **split_line(char *line)
{
    int     bsize;
    int     pos;
    char    **tokens;
    char    *tok;

    bsize = BUFFER_SIZE;
    pos = 0;
    tokens = malloc(bsize * sizeof(char *));
    if (!tokens)
    {
        write(1, "Allocation Error\n", 17);
        exit(EXIT_FAILURE);
    }
    tok = strtok(line, DELIM);
    while (tok != NULL)
    {
        tokens[pos] = tok;
        pos++;
        if (pos >= bsize)
        {
            bsize += BUFFER_SIZE;
            tokens = realloc(tokens, bsize * sizeof(char *));
            if (!tokens)
            {
                write(1, "Allocation Error\n", 17);
                exit(EXIT_FAILURE);
            }
        }
		tok = strtok(NULL, DELIM);
    }
	tokens[pos] = NULL;
	return (tokens);
}

char        *read_line()
{
    int     pos;
    int     bsize;
    char    *buffer;
    int     x;

    bsize = BUFFER_SIZE;
    buffer = malloc(sizeof(char) * bsize);
    if(!buffer)
    {
        write(1, "Allocation Error\n", 17);
        exit(EXIT_FAILURE);
    }
    pos = 0;
    while(1)
    {
        x = getchar();
        if (x == EOF || x == '\n')
        {
            buffer[pos] = '\0';
            return (buffer);
        }
        else
            buffer[pos] = x;
        pos++;
        if (pos >= bsize)
        {
            bsize += BUFFER_SIZE;
            buffer = realloc(buffer, bsize);
            if (!buffer)
            {
                write(1, "Allocation Error\n", 17);
                exit(EXIT_FAILURE);
            }
        }
    }
}

void        msh_loop()
{
    char    *line;
    char    **args;
    int     status;

    while (status == 1)
    {
        write(1, "> ", 2);
        line = read_line();
        args = split_line(line);
        status = execute(args);

        free(line);
        free(args);
    }
    
}

int         main(int argc, char **argv)
{
    // Carregar Config file

    // Run Loop
    msh_loop();

    //Cleanup
    // Shut down

    return (EXIT_SUCCESS);

}