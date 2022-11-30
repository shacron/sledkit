#include <stdio.h>

/* Statement of license status */
/* To the extent possible under law, Steve Bollinger has waived all copyright and related or neighboring rights to towers. This work is published from: United States. */
/* http://creativecommons.org/publicdomain/zero/1.0/ */

/******
 * Towers of Hanoi
 ******/

#define PRINTDEBUGGINGOUTPUT 0

enum { numdiscs = 5 };

// Pegs are kept in bottom to top order because all changes occur at the top.
// A 0 disc is no disc
typedef int pegdiscsarray[numdiscs+1];

pegdiscsarray pegslist[3];
int pegheights[3];

void InitPegs(pegdiscsarray *pegdiscs, int *pegheights)
{
    for (int lp = 0; lp < numdiscs + 1; ++lp)
    {
        pegdiscs[0][lp] = numdiscs - lp;
        pegdiscs[1][lp] = pegdiscs[2][lp] = 0;
    }
    pegheights[0] = numdiscs;
    pegheights[1] = pegheights[2] = 0;
}

void MakeDiscAppearance(char *discbuffer, int discsize, int maxdiscsize)
{
    discbuffer[maxdiscsize] = discsize ? '*' : '|';
    for (int lp = 0; lp < maxdiscsize; ++lp)
    {
        // this string will be discsize asterisks preceeded by maxdiscsize-discsize spaces
        // followed by a pipe. followed by discsize asterisks followed by maxdiscsize-discsize spaces
        char discchar = lp < (maxdiscsize-discsize) ? ' ' : '*';
        discbuffer[lp] = discbuffer[maxdiscsize*2-lp] = discchar;
    }
    discbuffer[1+maxdiscsize*2] = '\0';

#if defined(PRINTDEBUGGINGOUTPUT) && PRINTDEBUGGINGOUTPUT
   printf("Disk size %i produced %s\n",discsize,discbuffer);
#endif
}

void PrintPegs(const pegdiscsarray *pegdiscs, int numdiscs)
{
    // There is a single unit space on the left and right ends of the base.
    // There are two units space between each peg. There are two such spaces.
    // Each peg has room for a disc of width numdiscs. A disc of width numdiscs
    // is actually a width of 1 for the peg and numdiscs unit spaces on either side.
    const int totalbasewidth = 1 + 1 + 2 + 2 + 3 * (1 + numdiscs * 2);

    // Print the levels
    for (int level = numdiscs; level >= 0; --level)
    {
        char discappearance[3][2+2*numdiscs];
    
        putchar(' ');
        for (int peg = 0; peg < 3; ++peg)
        {
            MakeDiscAppearance(discappearance[peg],pegdiscs[peg][level],numdiscs);
        }
        printf(" %s  %s  %s\n",discappearance[0],discappearance[1],discappearance[2]);
    }

    // Print the base
    putchar(' ');
    for (int lp = 0; lp < totalbasewidth; ++lp)
    {
        putchar('=');
    }
    putchar('\n');
}

// Use naive algorithm.
// Move any disc right that can be moved that isn't the last
// one moved.
void FindAMove(pegdiscsarray *pegdiscs, int *pegheights)
{
    static int lastpegdestination = -1; // uninited

    for (int candidatepeg = 0; candidatepeg < 3; ++candidatepeg)
    {
        if (candidatepeg == lastpegdestination)
            continue;

        if (0 == pegheights[candidatepeg])
            continue;

        int candidatediscsize = pegdiscs[candidatepeg][pegheights[candidatepeg]-1];

#if defined(PRINTDEBUGGINGOUTPUT) && PRINTDEBUGGINGOUTPUT
        printf("Candidate disc size %d\n",candidatediscsize);
#endif

        int foundapeg = -1; // no peg found

        // Find a peg we can move this to, starting from the right
        for (int targetpeg = 2; targetpeg >= 0; --targetpeg)
        {
            if (0 == pegheights[targetpeg])
            {
#if defined(PRINTDEBUGGINGOUTPUT) && PRINTDEBUGGINGOUTPUT
                printf("Found an empty target peg %d\n",targetpeg);
#endif
                foundapeg = targetpeg;
                break;
            }

            int targetpegdiscsize = pegdiscs[targetpeg][pegheights[targetpeg]-1];

#if defined(PRINTDEBUGGINGOUTPUT) && PRINTDEBUGGINGOUTPUT
            printf("target size, peg: %d,%d source size, peg %d, %d\n",targetpegdiscsize,targetpeg,candidatediscsize,candidatepeg);
#endif

            if (0 == targetpegdiscsize || candidatediscsize < targetpegdiscsize)
            {
#if defined(PRINTDEBUGGINGOUTPUT) && PRINTDEBUGGINGOUTPUT
                printf("Found a target peg %d\n",targetpeg);
#endif
                foundapeg = targetpeg;
                break;
            }
        }

        // Make the move if we found it.
        if (-1 != foundapeg)
        {
            // note maximized code density!
            pegdiscs[foundapeg][pegheights[foundapeg]++] = candidatediscsize;
            pegdiscs[candidatepeg][--pegheights[candidatepeg]] = 0;
            lastpegdestination = foundapeg;
            break;
        }
    }
}

int main(void) {
    InitPegs(pegslist,pegheights);
    PrintPegs(pegslist,numdiscs);

    while (pegheights[2] < numdiscs)
    {
        puts("\n\n");
        FindAMove(pegslist,pegheights);
        PrintPegs(pegslist,numdiscs);
    }

    return 0;
}
