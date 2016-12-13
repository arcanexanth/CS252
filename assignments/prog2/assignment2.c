//Libraries
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <signal.h>

//Max line length
#define LINE_MAX_LENGTH 1024

//Max argument size
#define ARGSIZE 32

//Delimiters
#define DELIMS " \t\n\r"

//line display
void twd();
char* readLine();
char** lsh_split_line(char* line);

//built in commands
int commands(char** args);
int cd(char** args);
int exitShell();

//execute programs
int execute(char** args);
//input outputv
void redirect(char** args);
//check if command is running in the background
int bCheck(char** args);
void handler(int sig);

int main(int argc, char** argv){
   
   twd(); 
}

//Terminal print
void twd(){
   char* line; //line to be parsed
   char** args; //arguments
   char cmdl[LINE_MAX_LENGTH]; // current working directory
   int status = 1;

   do{
	printf("%s>", getcwd(cmdl, sizeof(cmdl)));
	line = readLine();
	//printf("This is the line variable: %s", line);
	args = lsh_split_line(line);
	status = commands(args);

	free(line);
	free(args);
   }while (status);
}

//reads the line and returns it
char* readLine(){
  ssize_t lineSize = 0;
  char *line = NULL;
  getline(&line, &lineSize, stdin);
  return line;
}

/*splits the line it was given. Used lsh_split_line from brennan.io/2015/01/16/write-ashell-in-c/ because we couldn't understand how to make parser given work.*/
char** lsh_split_line(char* line){
  
   int bufsize = ARGSIZE, position = 0;
   char** tokens = malloc(bufsize * sizeof(char*));
   char* token;

   if(!tokens){
      fprintf(stderr, "lsh: allocation error\n");
      exit(EXIT_FAILURE);
   }
   
   token = strtok(line, DELIMS);
   while(token != NULL){
     //printf(" got here");
     tokens[position]= token;
     position++;
     
     if(position >= bufsize){
       bufsize += ARGSIZE;
       tokens = realloc(tokens, bufsize * sizeof(char*));
       if(!tokens) {
          fprintf(stderr, "lsh: allocation error\n");
	  exit(EXIT_FAILURE);
       }
       
     }
     token = strtok(NULL, DELIMS);
   }
   tokens[position] = NULL;
   return tokens;
}

//checks whether a command is built in or not
int commands(char** args){
  int result;
  if( args[0] == NULL){
	return 1;
  }else if(strcmp(args[0], "cd") == 0){
     result = cd(args);
     return result;
  }else if(strcmp(args[0], "exit") ==0){
     result = exitShell();
     return result;
  }else{ result = execute(args);
     return result;
  }
}

//Built in commands
int cd(char** args){
  
  if(args[1] == NULL){
    fprintf(stderr, "Please type a directory\n");
  }else{
    if(chdir(args[1]) != 0)
      fprintf(stderr, "Not a working directory. Try again\n");
  }
return 1;
}

int exitShell(){
  return 0;
}

//runs programs
int execute(char** args){
  int bResult;
  bResult = bCheck(args);
  pid_t pid;
  int status;
  pid_t wPid;
  pid = fork();

  //Check to see if it forked properly
   if(pid ==0){
      redirect(args);
      int cPid = getpid();
      if(execvp(args[0],args) < 0){
         fprintf(stderr, "Error: Cannot start program\n");
      }
      exit(0);
   }else if(pid<0){
      fprintf(stderr, "Error: Failure to fork\n");
   }else if(bResult==1){
       signal(SIGCHLD, handler);
   }else{
      int pPid = getpid();
      if(bResult == 0){
        do{
         wPid = waitpid(pid, &status, WUNTRACED);
	 }while(!WIFEXITED(status) && !WIFSIGNALED(status));
      }
   }
   bResult=0;
  return 1;
}

void redirect(char** args){
 int position = 0;

 char* in;
 char* out;
 while(args[position] != NULL){
     if(strcmp(args[position], "<") == 0){
       in = args[position + 1];
       freopen(in, "r", stdin);
       args[position] = NULL;
     }
     if(strcmp(args[position], ">") == 0){
       out = args[position+1];
       freopen(out,"w", stdout);
       args[position] = NULL;
     }
    position++;
   }
}

int bCheck(char** args){
  int check = 1;
  int i = args[0][strlen(args[0])-1];
  if(i == '&'){
     args[0][strlen(args[0])-1] = '\0';
     return check = 1;
  }else{
     return check = 0;
   }
}

void handler(int sig){
   pid_t pid;
   while((pid = waitpid(-1, NULL, WNOHANG)) > 0){
   	printf("Killed background process: %d\n", pid);
   }
   return;
}
