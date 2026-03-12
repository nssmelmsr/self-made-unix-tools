#include<stdio.h>
#include<unistd.h> //para read()
#include<fcntl.h> //para open

int main(int argc, char *argv[]){
    int fd;					// file descriptor
	char buffer[4096]; 		// maximum to read
	ssize_t bytes_read;
    int word = 0, lines = 0, bytes = 0; //
    char in_word = 0;

	if (argc < 2){
		fprintf(stderr,"Please choose a file\n"); //show custom error 
		return 1;
	}
    else{
        fd = open(argv[1], O_RDONLY); //open file to read only
		if (fd == -1){
    		perror("Error openning file");    // perror shows the error code of the syscall
    		return 1;
		}
        while ((bytes_read = read(fd, buffer, sizeof(buffer))) > 0){ // read whole file
            bytes += bytes_read;                          
                
            for (int i = 0; i < bytes_read ; i++ ){
                if (buffer[i] == '\n' ){            // when line ends, word ends
                    lines++;
                    
                }
                if ((buffer[i] == ' ' || buffer[i] == '\t' || buffer[i] == '\n')){ //word ends
                    in_word = 0;
                }
                else if (in_word == 0){
                    in_word = 1;
                    word++;
                }
            }
        }
		if (bytes_read == -1){
   			perror("read");
			close(fd);
			return 1;
        }
        close(fd);
        printf("lines: %d\nwords: %d\nbytes: %d\n", lines,word,bytes);
        return 0;
    }

}