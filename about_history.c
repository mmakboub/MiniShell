#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <stdlib.h>
int main(int argc, char** argv) 
{
    while (1) 
    {
      char *prompt = "minishell > ";
      char *input = readline(prompt);
      if(!input) // for EOF error
        break;
      add_history(input);
      //printf("%s\n", input);
      free (input);
    }

  return 0;
}