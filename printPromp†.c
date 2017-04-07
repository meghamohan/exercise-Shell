#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define BUFFER 1024

char *fetchCmd()
{
	char *cmd;
	size_t result, buffsize;

	buffsize = BUFFER;
	cmd = malloc(sizeof(char) * BUFFER);
	if (!cmd)
		printf("Error\n");
	result = getline(&cmd, &buffsize, stdin);
	return(cmd);
}

char **parseCommand(char *cmd)
{
	int buffsize = BUFFER, i = 0;
	char **tokens = malloc(buffsize * sizeof(char *));
	char *token;

//	printf("%s\n",cmd);
	if (!tokens)
		printf("error\n");
	token = strtok(cmd," ");
	while (token != NULL)
	{
		printf("Token: %s\n",token);
   		tokens[i] = token;
		printf("token = %s\n",tokens[i]);
    		i++;
		token = strtok(NULL, " ");
	}
	tokens[i] = NULL;
	return (tokens);
}
void printPrompt()
{
	char *cmd, **tokenizedArray;
	int i = 0;
	while(1)
	{
		printf("myShell$ ");
		cmd = fetchCmd();
		if (cmd == "exit") {
			break;
		}
		//printf("%s",cmd);
		tokenizedArray = parseCommand(cmd);

	/*	if (checkBuiltIn(tokenizedArray)
			execBuiltIn(tokenizedArray);
		else
			exeCmds(tokenizedArray);*/
	}
}



int main()
{
	printPrompt();
	return (0);
}
