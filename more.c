/*	More by L Kuru 4.1.1994 */

/* IBM OS/2 more works, but through pipes only + gives an */
/*	extra blank line on top of screen which is very confusing + */
/* changes your text window size */
/* 'fast' more ( by S. Lacy) can't handle colors + sends too long "tab'ed" */
/* lines off screen, normal too long lines -> last char of line is not used */

/* Redirection to a file not ok; ibm more even worse here; 'fast' more */
/* writes directly to screen, no redirection possible */
/* > -redirection doesn't work very well, type is recommended instead */

/* compiled with BC++ 1.0 for OS/2 */
/* wildcard support by linking WILDARGS.OBJ (by Borland) with source */

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<io.h>
#include<string.h>

int main(int argc, char *argv[])
{
struct text_info ti;
int x,y;
unsigned int lines;
int i,j,k;
FILE *rp;
char curline[134];
char blank[134]="";

gettextinfo(&ti);
x=ti.screenwidth+1;
y=ti.screenheight;
for(i=1;i<x-1;i++)strcat(blank," ");

/* my clrscr */
gotoxy(1,1);
for(i=1;i<y;i++)printf("%s ",blank);printf("%s",blank);
gotoxy(1,1);

/* open input stream */
for( k=0;k<argc;k++)
	{
	if(argc==1) {rp=stdin;}
		else if((rp=fopen(argv[k+1],"rt"))==NULL)
			{fprintf(stderr,"Error opening file %s.\n",argv[k+1]);exit(1);}

	/* count # of lines for % information */
	lines=0;
	if(argc!=1)
		{
		while (!feof(rp)){fgets(curline,x,rp);++lines;};
		rewind(rp);
		}

	/* my more; i used for %-info */
	i=0;
	while(!feof(rp))
		{
		fgets(curline,x,rp);
		printf("%s",curline);
		strcpy(curline,"");
		i++;
		if(wherey()==y)
			{
			printf("\r -- more --");
			if(argc!=1)printf("\b %s - %2d % --",argv[k+1],100*i/lines);

			j=getch();
			switch (j)
				{
				case 'q' :  /* 113 */
					fclose(rp);
					return(0);
					break;
				case 13 : /* enter */
					printf("\r%s\n\n\n\n",blank);
					gotoxy(1,y-4);
					break;
				case 'v' :/* version info */
					printf("\r%s\r -- more v 1.0 by qru --",blank);
					/* repeat this section to make enter and q work after v */
					j=getch();
					switch (j)
						{
						case 'q' :  /* 113 */
							fclose(rp);
							return(0);
							break;
						case 13 : /* enter */
							printf("\r%s\n\n\n\n",blank);
							gotoxy(1,y-4);
							break;
						default:
						;
						}				default:
				;
				}
			if(j!=13)   /* "default", clrscr */
				{
				gotoxy(1,1);
				for(j=1;j<y;j++)printf("%s ",blank);printf("\r%s",blank);
				gotoxy(1,1);
				}
			}
		}

	fclose(rp);
	if(argc==(k+2)||argc==1) return (0);
	}
return (0);
}
