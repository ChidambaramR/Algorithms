#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/inotify.h>
#include <unistd.h>
#include <string.h>

#define EVENT_SIZE  ( sizeof (struct inotify_event) )
#define BUF_LEN     ( 1024 * ( EVENT_SIZE + 16 ) )

static void cat(FILE *fp, int k){
    char *string[4096];
    int lines=0;
    size_t len;
    int read;

    // Read the file line by line
    while((read = getline(&string[lines%k], &len, fp)) != -1){
    	lines++;
    }

    // Print the k lines
    for(read=0; read<k; read++)
	printf("%s",string[read]);
}

int main(int argc, char **argv){
  	int length, i = 0;
  	int fd;
  	int wd;
  	char buffer[BUF_LEN];
	FILE *fp;
	
  	fd = inotify_init();

  	if(fd < 0){
    		perror( "inotify_init" );
  	}

	wd = inotify_add_watch( fd, ".", IN_MODIFY);
	if(wd == -1){
		perror("Watch failure\n");
		exit(0);
	}

	while(1){
  		length = read( fd, buffer, BUF_LEN );

  	if(length < 0){
    		perror( "read" );
  	}
	i = 0;
  	while(i < length){
    		struct inotify_event *event = ( struct inotify_event * ) &buffer[ i ];

      			if(event->mask & IN_MODIFY){
				if(strstr(argv[1], event->name)){
          				printf( "The file %s was modified.\n", argv[1]);
					fp = fopen(argv[1], "r"); 
					if(!fp){
						printf("File not found\n");
						exit(0);
					}
					cat(fp,5);
					fclose(fp);
				}	
      			}
    	i += EVENT_SIZE + event->len;
  	}
	}

  	(void)inotify_rm_watch( fd, wd );
  	(void)close( fd );

  	return 0;
}
