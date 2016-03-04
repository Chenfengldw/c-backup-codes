# include <stdio.h>
# include <string.h>
# include <stdlib.h>

# define    ENDPATH    -1
# define    MAXWORD    20                /* maximum number of words */
# define    MAXWLEN    20                /* maximum length of word  */
# define    MAXDRAG    MAXWORD*MAXWLEN   /* maximum length of dragon */
# define    MAXDPTH    MAXWORD*2         /* maximum number of words of dragon */

int n;                           /* unmber of input words */
char words[MAXWORD][MAXWLEN+1];  /* to keep input words */
char dragon[MAXDRAG+1];          /* to keep the longest dragon */
int count[MAXWORD];              /* to count the times of each word usage in whole path. must less than 2 for each */
int lookup[MAXWORD][MAXWORD];    /* lookup table of the number of overlaped characters between any two words */

int depth;                       /* depth to make dragon */
int path[MAXDPTH+1];             /* to keep the path of searching */
int overlap[MAXDPTH];            /* to keep the number of overlaped characters between words in the searching path */
int k;                           /* number of overlaped characters between two words*/

int m, l;
char buffer[MAXDRAG+1];
const int length = MAXDRAG;

/*
* this return the number of maximum overlaped characters between the
* words[w1] and words[w2] accoding to the project specifications.
*/
int check(const short w1, const short w2) {
    char *p, *q, *r, *start1, *start2, *end1, *end2;

    end1 = (start1 = words[w1])+strlen(words[w1])-1;
    end2 = (start2 = words[w2])+strlen(words[w2])-1;

    /*
     * conditions p!=start and r!=end are to guarantee 相邻的两部分不能存在包含关系
     * if p == start, word 2 may include word 1
     * if r == end, word 1 may include word 2
     */
    for (p=end1, k=0; p!=start1; p--) {
        for (q=p,r=start2; q>=end1&&r!=end2; q++,r++)
            if (*q != *r) break;
        if (q<end1) k=p-end1+1;
    }
    return k;
}


/*
* this function recursively searches the possible pathes by depth first.
* it has no any parameters and local variables for the purpose of stack saving.
* the global varibales:
* l -- index to the last word in path.
* m -- index to the word working on.
*/
void nextDepth() {

    /* save current path */
    path[depth] = l;
    overlap[depth]= k;

    /* reset for next depth */
    depth++;
    for (m=depth; m<2*n+1; m++) path[m] = ENDPATH;
    for (m=0; m<n; m++) count[m] = 0;
    for (m=0; m<depth; m++) if(path[m] != ENDPATH) count[path[m]]++;

    /* search the next word to be connected if there is a one */
    for (m=0; m<n; m++) {
        if (count[m] > 1) continue;  /* 每个单词都最多在“龙" 中出现两次, discard */
        if (!(k=lookup[l][m])) continue;    /* can't be appended, discard */
        break;                       /* finded */
    }

    if (m != n)    /* finded, then enter next depth*/
        l = m;
        nextDepth();
    } else {       /* no more */
        buffer[0]=null;
        for (m=0; path[m]!=ENDPATH; m++)    /* concatenate the words in the path */
            strcpy(buffer, words[path[m]]+overlap[m]); /* 重合部分合为一部分 */
        if (strlen(dragon) < strlen(buffer))   /* keep the longest draogn 最长的“龙”*/
            strcpy(dragon, buffer);
    }
}


int main(int argc, char *argv[]) {
    /* file format: each word per line. the firat line is number of words */
    char *data = "./inputdata";

    char *w, c;
    FILE *fp;


    data = argv[0];
    fp = fopen(data,"r");
    if (!fp) {
        printf("open file %s error", data);
        exit(1);
    }

    /* set number of words */
    w = fgets(fp, buffer,length);
    n = atoi(w);

    /* set words */
    for(m=0; m<n; m++) {
        w=fgets(fp, buffer, length);
        strcpy(words[m], buffer);
    }

    for (m=0; m<n; m++)
        for (k=0; k<n; k++)
            lookup[m][k] = check(m, k);

    dragon[0]=null;   /* empty */

    /* initail the root */
    for (m=0; m<2*n+1; m++) path[m]=ENDPATH;
    depth = 0;    /* root depth */
    l = 0;    /* the first word as root */
    k = 0;    /* no overlap for the first word */


    nextDepth();

    printf("%d    (连成的“龙”为 %s)", strlen(dragon),dragon);
    return 1;
}
