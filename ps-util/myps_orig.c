#include <stdio.h>
#include <ctype.h> //is_digit()
#include <dirent.h>//dir management
#include <unistd.h> //para funcion read()
#include <fcntl.h> //para función open()

int isnumber(const char *str){
    for(int i=0;str[i];i++){
        if (isdigit(str[i])){
            return 1;
        }
    }
    return 0;
}

int main(void){

    DIR *dir = opendir("/proc");
    ssize_t bytes_read;
    char name[256];

    if (dir == NULL){
    perror("opendir");
    return 1;
    }

    struct dirent *entry;

    while ((entry = readdir(dir)) != NULL){
        if (entry->d_name == "." || entry->d_name == ".."){
            return 1;
        }
        if (isnumber(entry->d_name)){
            char path[256];
            snprintf(path, sizeof(path), "/proc/%s/comm",entry->d_name);
            int fd = open(path,O_RDONLY);
            if (fd == -1){
				perror("Error openning file");    // perror shows the error code of the syscall
				continue;
			}
            bytes_read = read(fd, name, sizeof(name)) > 0;//lee el archivo

			if (bytes_read == -1){
				perror("Error reading file");
				close(fd);
				return 1;
			}
            if (bytes_read > 0) {
                name[bytes_read] = '\0';
                name[strcspn(name, "\n")] = '\0';
                printf("%s\t%s\n",entry->d_name,name);  
            }
                
            close(fd);
        }
    }
    return 0;    
}