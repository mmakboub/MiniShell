#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <stdlib.h>
int main(int argc, char** argv) 
{
  int i = 0;
  while (1) 
  {
    char *prompt = "minishell > ";
    char *input = readline(prompt);
    if(!input) // for EOF error
      break;
    add_history(input);
    while(argv[i] && argv[1][i]) =
    //printf("%s\n", input);
    free (input);
    }

  return 0;
