#include  <stdio.h>
#include  <sys/types.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>

#define MAX_INPUT_SIZE 1024
#define MAX_TOKEN_SIZE 64
#define MAX_NUM_TOKENS 64
int number=0;

/* Splits the string by space and returns the array of tokens
*
*/
char **tokenize(char *line)
{
  char **tokens = (char **)malloc(MAX_NUM_TOKENS * sizeof(char *));
  char *token = (char *)malloc(MAX_TOKEN_SIZE * sizeof(char));
  int i, tokenIndex = 0, tokenNo = 0;

  for(i =0; i < strlen(line); i++){

    char readChar = line[i];

    if (readChar == ' ' || readChar == '\n' || readChar == '\t'){
      token[tokenIndex] = '\0';
      if (tokenIndex != 0){
	tokens[tokenNo] = (char*)malloc(MAX_TOKEN_SIZE*sizeof(char));
	strcpy(tokens[tokenNo++], token);
	tokenIndex = 0; 
      }
    } else {
      token[tokenIndex++] = readChar;
    }
  }
  //number=tokenNo;
  free(token);
  tokens[tokenNo] = NULL ;
  number=tokenNo;
  return tokens;
}
char **tokenize1(char *line)
{
  char **tokens = (char **)malloc(MAX_NUM_TOKENS * sizeof(char *));
  char *token = (char *)malloc(MAX_TOKEN_SIZE * sizeof(char));
  int i, tokenIndex = 0, tokenNo = 0;

  for(i =0; (i < strlen(line)&&line[i]!='&'); i++){

    char readChar = line[i];

    if (readChar == ' ' || readChar == '\n' || readChar == '\t'){
      token[tokenIndex] = '\0';
      if (tokenIndex != 0){
	tokens[tokenNo] = (char*)malloc(MAX_TOKEN_SIZE*sizeof(char));
	strcpy(tokens[tokenNo++], token);
	tokenIndex = 0; 
      }
    } else {
      token[tokenIndex++] = readChar;
    }
  }
 
  free(token);
  tokens[tokenNo] = NULL ;
  return tokens;
}
int flag;
int fun(int signum)
{
	//printf("i am in ctrl c  and flag value is=%d\n",flag);
     setpgid(flag,flag);
     kill(flag,SIGTERM);
	return 0;
}
int main(int argc, char* argv[]) {
	char  line[MAX_INPUT_SIZE];            
	char  **tokens;              
	int i;
    char *ancestor = (char *)malloc(MAX_TOKEN_SIZE * sizeof(char));
	strcat(ancestor,"/");
	strcat(ancestor,"SHELL-CODE");
	int y=0;
	// new code
	int q=0;
	int arr[64];
	for(i=0;i<64;i++)
	  arr[i]=-2;
    char **new_tokens;
	while(1) {			
		/* BEGIN: TAKING INPUT */
		bzero(line, sizeof(line));
		int t;  
		printf("%s$ ",ancestor);
		scanf("%[^\n]", line);
		getchar();
		for(t=0;t<64;t++)
		{
		   int st;

		   if(arr[t]>0)
		   {
		     int v;
             
			 v=waitpid(arr[t], &st, WNOHANG);
			 if(v==arr[t]&&WIFEXITED(st))
			 {
				printf("%s$ ",ancestor);
				//printf("status=%d   ",st);
				//printf("process id = %d ",arr[t]);
				printf("Shell: Background process finished\n");
				arr[t]=-2;
			}
		   }
		}
		line[strlen(line)] = '\n'; //terminate with new line
		tokens = tokenize(line);
		new_tokens=tokenize1(line);
		//new line
		//new_toknes=tokenize1(line)
		if(tokens[0]==NULL)
		{
			continue;
		}
		int k=0;
		while(tokens[k]!=NULL)
		{
			k++;
			/* code */
		}
		if(strcmp(tokens[0],"exit")==0)
		{
			
			int j;
			int indicator=0;
			for(j=0;j<64;j++)
			{
				if(arr[j]!=-2)
				 {
					indicator++;
					int l=kill(arr[j],SIGTERM);
				 }
			}
			   for(j=1;j<=indicator;j++)
			    {
				 int q=wait(NULL);
			    }

			 for(i=0;tokens[i]!=NULL;i++)
			    {
			     free(tokens[i]);
		        }
		        free(tokens);
			for(i=0;new_tokens[i]!=NULL;i++){
			     free(new_tokens[i]);
		        }
		        free(new_tokens);	
			return 0;
		}
		if(strcmp(tokens[0],"cd")==0)
			{
				//printf("%s\n",tokens[1]);
				if(strcmp(tokens[1],"..")==0)
				{
					
                   //printf("want to change directory to go the parent \n");

				   int n=strlen(ancestor);
				   //int i,j;
				   int q=0;
				   for(i=n-1;(ancestor[i]!='/'&&i!=0);i--)
				   {
					 q++;
				   }
				   
					//printf("str = %s\n",str);
					//printf("anscestor = %s\n",ancestor);
					int x=chdir(tokens[1]); 
					//printf(" x = %d\n",x);
					 if(x==-1)
				     {
					   int n=strlen(tokens[1]);
				     }
					 else
					 {	
					    ancestor[strlen(ancestor)-q-1]='\0';
						 
					 }  
				}
				else
				{
				  if(number<=2)
				  {
				  strcat(ancestor,"/");
				  strcat(ancestor,tokens[1]);
				  }
				  y=strlen(ancestor);
				  int x;
				  if(number>2)
				  {

                      printf(" error :wrong structure of directory name\n");
					  number=0; 
				  }
				  else
				  {
					
				    x=chdir(tokens[1]);
				  }

				  if(x==-1)
				  {
					int n=strlen(tokens[1]);
					ancestor[strlen(ancestor)-n-1]='\0';
				  }
				//else
				//{
                   //printf("%s",ancestor);
				//}
				}
			//	}
				continue;
			   
			}
		if(strcmp(tokens[k-1],"&")==0)
		{

			int bg=fork();
			
            setpgid(bg,bg);
			if(bg<0)
			{
				printf("fork failed for background process\n");
			}
			else if(bg==0)
			{
				//code to be addded incomplete below line code
				execvp(new_tokens[0],new_tokens);
				printf("command execution failed of background\n");
				exit;
			}
			else
			{
				for(i=0;i<64;i++)
				{
					if(arr[i]==-2)
					  {
						arr[i]=bg;
						break;
					  }
				}
                
				continue;
			}
		}
		else
		{
		  int fc=fork();
          flag=fc;
		if(fc<0)
		{
			fprintf(stderr, "%s\n","Unable to create child process\n");
		}
		else if(fc==0)
		{
			if(strcmp(tokens[0],"cd")!=0)
			{
			execvp(tokens[0],tokens);
			printf("Command execution failed \n");
			exit(1);
			}		
			//exit(1);
		}
		else{
			int l;
			int wc ;
			signal(SIGINT,fun);
			wc=waitpid(fc,NULL,0);		
		}
		}
		for(i=0;tokens[i]!=NULL;i++){
			free(tokens[i]);
		}
		free(tokens);
		for(i=0;new_tokens[i]!=NULL;i++){
			free(new_tokens[i]);
		}
		free(new_tokens);
	}
	return 0;
}

