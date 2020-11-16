#include "holberton.h"

/**
 * free_member - free build config members 
 * Return: Nothing
 */
void free_member(config *build)
{
    if (build->env)
    {
        free_list(build->env);
    }
    if (build->args)
    {
        free_args(build->args);
    }
    if (build->buffer)
    {
        free(build->buffer);
    }
}

void free_list()
{
    
}

void free_args()
{
    
}