#include <stdio.h>
#include <stdlib.h>


int main(int argc, char *argv[])
{
	FILE *f = NULL;

	int c, i;

	int   num;
	char  s[256];
	float fl;
	long  f_size = 0;

	if (argc > 1)
	{
		f = fopen(argv[1], "rb");
	}
	else
	{
		char filename[256];

		printf("Data file name not provided. Please, enter name: ");
		scanf("%s", filename);
		f = fopen(filename, "rb");
	}

	if (f == NULL)
	{
		printf("Error: file was not read!\n");
		exit(1);
	}

	for (i = 0; (c = getc(f)) != EOF; i++)
	{
		ungetc(c, f);

		fread(&num, sizeof(int), 1, f);
		fread(s, sizeof(char), 256, f);
		fread(&fl, sizeof(float), 1, f);

		f_size += sizeof(int) + sizeof(char) * 256 + sizeof(float);


		printf("Chunk %d:\n\t%d\n\t%s\n\t%f\n", i + 1, num, s, fl);

	}

	printf("File size: %ld bytes\n", f_size);

	return 0;
}
