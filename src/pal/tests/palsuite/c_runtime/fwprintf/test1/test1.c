//
// Copyright (c) Microsoft. All rights reserved.
// Licensed under the MIT license. See LICENSE file in the project root for full license information. 
//

/*============================================================================
**
** Source:      test1.c
**
** Purpose:     A single, basic, test case with no formatting.
**              Test modeled after the sprintf series.        
**  

**
**==========================================================================*/

#include <palsuite.h>

/* 
 * Depends on memcmp, strlen, fopen, fgets, fseek and fclose.
 */

int __cdecl main(int argc, char *argv[])
{
    FILE *fp;
    char testfile[] = "testfile.txt";

    WCHAR *outstr;
    char checkstr[] = "hello world";
    char buf[256];

    if (PAL_Initialize(argc, argv) != 0)
    {
        return(FAIL);
    }

    outstr = convert(checkstr);
    if ((fp = fopen(testfile, "w+")) == NULL)
    {
        Fail("ERROR: fopen failed to create \"%s\"\n", testfile);
    }

    if ((fwprintf(fp, outstr)) < 0)
    {
        Fail("ERROR: fwprintf failed to print to \"%s\"\n", testfile);
    }

    if ((fseek( fp, 0, SEEK_SET)) != 0)
    {
         Fail("ERROR: Fseek failed to set pointer to beginning of file\n" );
    }
 

    if ((fgets( buf, 100, fp )) == NULL)
    {
        Fail("ERROR: fgets failed\n");
    }
    
    if (memcmp(checkstr, buf, strlen(checkstr)+1) != 0)
    {
        Fail("ERROR: expected %s, got %s\n", checkstr, buf);
    }


    if ((fclose( fp )) != 0)
    {
        Fail("ERROR: fclose failed to close \"%s\"\n", testfile);
    }

    PAL_Terminate();
    return PASS;
}
