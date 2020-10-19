#include <stdio.h>

int main()
{
    /* A nice long string */
    char string[256];

    printf( "Please enter a long string: " );

    /* notice stdin being passed in */
    fgets ( string, 256, stdin );

    printf( "You entered a very long string: %s", string );

    /*  Note: fgets includes a '\n' at the end just like .nextLine() from java,
              so you have to account for that:

        char input[256];
        int i;

        fgets( input, 256, stdin );

        for ( i = 0; i < 256; i++ )
        {
            if ( input[i] == '\n' )
            {
                input[i] = '\0';
                break;
            }
        }
    */

    //getchar();
    return 0;
}
