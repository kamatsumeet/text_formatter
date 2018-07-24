#include "stdio.h"
#include "stdlib.h"

#define WIDTH 60
#define SPACE ' '
#define NEWLINE '\n'

int main(){

	int this_char = 0;
	int prev_char = 0;
	int size_width = 0;
	FILE *file_1 = fopen("input.txt","r");
	FILE *file_2 = fopen("output.txt","w");

	if (file_1 == NULL){
		perror("Failed to open Input file !!");
		exit(1);
	}

	if (file_2 == NULL){
		perror("Failed to open Output file !!");
		exit(1);
	}

	while ((this_char = getc(file_1)) != EOF){

		if(prev_char!=NEWLINE && prev_char!=SPACE){

			if ((size_width<=WIDTH)&&(this_char!=NEWLINE)){
				putc(this_char, file_2);
				++size_width;
			}

			else if ((size_width<=WIDTH)&&(this_char==NEWLINE)){
				putc(this_char, file_2);
				size_width=0;
			}
	
			else if (size_width>WIDTH){
				putc(NEWLINE, file_2);
				if(this_char==SPACE){
					size_width=0;
				}
				else{
					putc(this_char, file_2);
					size_width=1;
				}
			}
		}

		else if (prev_char==NEWLINE){

			if((size_width<=WIDTH)&&(this_char!=SPACE)&&(this_char!=NEWLINE)){
				putc(this_char, file_2);
				++size_width;
			}

			else if((size_width<=WIDTH)&&(this_char==SPACE)){
			}

			else if ((size_width<=WIDTH)&&(this_char==NEWLINE)){
				putc(this_char, file_2);
				size_width=0;
			}
	
			else if (size_width>WIDTH){
				putc(NEWLINE, file_2);
				if(this_char==SPACE){
					size_width=0;
				}
				else{
					putc(this_char, file_2);
					size_width=1;
				}
			}
		}

		else if (prev_char==SPACE){

			if((size_width<=WIDTH)&&(this_char!=SPACE)&&(this_char!=NEWLINE)){
				putc(this_char, file_2);
				++size_width;
			}

			else if((size_width<=WIDTH)&&(this_char==SPACE)){
			}

			else if ((size_width<=WIDTH)&&(this_char==NEWLINE)){
				putc(this_char, file_2);
				size_width=0;
			}
	
			else if (size_width>WIDTH){
				putc(NEWLINE, file_2);
				if(this_char==SPACE){
					size_width=0;
				}
				else{
					putc(this_char, file_2);
					size_width=1;
				}
			}
		}

	
		prev_char = this_char;

	}

	fclose(file_1);
	fclose(file_2);
	return(0);
}

	

