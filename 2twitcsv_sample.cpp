#include <stdlib.h>
#include <stdio.h>

int EstimateCSVCellCount(const char *buf, size_t size)
{
	int ret = 0; char c, d=0;
	while (size) {
		c = *buf++; size--;
		if (c==',' || ((c=='\n' || c=='\r') && !(d=='\n' || d=='\r')))
			ret++;
		d = c;
	}
	return ret+1;	// allow overrun by 1
}

int main(int argc, char **argv)
{
	if (argc>1) {
		if (FILE *file = fopen(argv[1] , "rb")) {
			fseek(file, 0, SEEK_END);
			int l = ftell(file);
			rewind(file);
			if (char *pCSV = (char*)malloc(l+1)) { // allow overrun by 1
				fread(pCSV, l, 1, file); fclose(file);
				int guesstimateCells = EstimateCSVCellCount(pCSV, l);
				char **cells = (char**)malloc(sizeof(char*) * guesstimateCells), **o = cells;
				memset(cells, 0, sizeof(char**) * guesstimateCells);
				char *p = pCSV;
				#include "2twitcsv.h"
				for (int row=0; row<r; row++) {
					for (int col=0; col<c; col++)
						printf("%s,", cells[row*c+col] ? cells[row*c+col] : "");
					printf("\n");
				}
				free(cells);
				free(pCSV);
			}
		}
	} else
		printf("Usage:\n2twitcsv filename.csv\n");
	return 0;
}
