#include <stdio.h>

#define MAXSTRLEN 200
#define FILENAME "test.txt"

void readlines(){
  FILE *fp;
  fp = fopen( FILENAME , "r");
  char line[MAXSTRLEN];
  if (fp != 0){
    while ( fgets ( line, sizeof( line ), fp ) != 0 ) {
			fputs ( line, stdout );
		}//end while
    fclose(fp);
  }else{
    printf("filr %s can not be open \n", FILENAME);
  }//end if
}//end readlines

void writelines(){
  FILE *fp;
  fp = fopen(FILENAME , "w");
  fputs("hello world\n", fp );
  fputs("goodbye payam\n", fp);
  fclose(fp);

}//end writelines

void clearfile() {
	FILE *fp;
	fp = fopen( FILENAME, "w" );
	fclose( fp );
}

void deletefile() {
	if ( remove( FILENAME ) == 0 ) {
		printf( "%s file deleted.\n", FILENAME );
	} else {
		printf( "Unable to delete the file: %s.\n", FILENAME );
	}
}

void linecount( char *fn){
  int numline = 0;
  char line[MAXSTRLEN];
  FILE * fp;
  fp = fopen(fn, "r" );
  if (fp != 0){
    while (fgets(line,sizeof(line),fp)!= 0){
      numline++;
    }
    fclose(fp);
    printf("%s contain %d line of text \n", fn , numline);
  } else {
    printf("filw cant be open %s\n", fn);
      }
}

int main( int argc, char **argv ) {
	// deletefile();
	// clearfile();
	writelines();
	readlines();
  linecount(FILENAME);
	return 0;
}
