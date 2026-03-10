#include <stdio.h>
#include <dirent.h> // for opendir(), readdir(), closedir()
#include <sys/types.h> // for ino_t

int main(int argc, char *argv[]) {
    char* name = "."; 
    
    if (argc > 1 ){
        printf("Mostrando directorio: %s\n",argv[1]);
        name = argv[1];
    }
    struct dirent *entry;       // uses "entry" to use the "dirent" structure

    DIR *dir = opendir(name);

    if (dir == NULL){
        perror("opendir");
        return 1;
    }

    while ((entry = readdir(dir)) != NULL){
        printf("%lu %s\n", entry->d_ino, entry->d_name); // dirent has elements on it defined
                                                         // "->" to access pointer inside struct
    }
    closedir(dir);

    return 0;
}