/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE253_Incorrect_Check_of_Function_Return_Value__char_fscanf_17.c
Label Definition File: CWE253_Incorrect_Check_of_Function_Return_Value.label.xml
Template File: point-flaw-17.tmpl.c
*/
/*
 * @description
 * CWE: 253 Incorrect Check of Return Value
 * Sinks: fscanf
 *    GoodSink: Correctly check if fscanf() failed
 *    BadSink : Incorrectly check if fscanf() failed
 * Flow Variant: 17 Control flow: for loops
 *
 * */

#include "std_testcase.h"

#ifndef _WIN32
#include <wchar.h>
#endif

#ifndef OMITBAD

void CWE253_Incorrect_Check_of_Function_Return_Value__char_fscanf_17_bad()
{
    int j;
    for(j = 0; j < 1; j++)
    {
        {
            /* By initializing dataBuffer, we ensure this will not be the
             * CWE 690 (Unchecked Return Value To NULL Pointer) flaw for fgets() and other variants */
            char dataBuffer[100] = "";
            char * data = dataBuffer;
            /* FLAW: fscanf() might fail, in which case the return value will be EOF (-1), but
             * we are checking to see if the return value is 0 */
            if (fscanf(stdin, "%99s\0", data) == 0)
            {
                printLine("fscanf failed!");
            }
        }
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* good1() uses the GoodSinkBody in the for statements */
static void good1()
{
    int k;
    for(k = 0; k < 1; k++)
    {
        {
            /* By initializing dataBuffer, we ensure this will not be the
             * CWE 690 (Unchecked Return Value To NULL Pointer) flaw for fgets() and other variants */
            char dataBuffer[100] = "";
            char * data = dataBuffer;
            /* FIX: check for the correct return value */
            if (fscanf(stdin, "%99s\0", data) == EOF)
            {
                printLine("fscanf failed!");
            }
        }
    }
}

void CWE253_Incorrect_Check_of_Function_Return_Value__char_fscanf_17_good()
{
    good1();
}

#endif /* OMITGOOD */

/* Below is the main(). It is only used when building this testcase on
   its own for testing or for building a binary to use in testing binary
   analysis tools. It is not used when compiling all the testcases as one
   application, which is how source code analysis tools are tested. */

#ifdef INCLUDEMAIN

int main(int argc, char * argv[])
{
    /* seed randomness */
    srand( (unsigned)time(NULL) );
#ifndef OMITGOOD
    printLine("Calling good()...");
    CWE253_Incorrect_Check_of_Function_Return_Value__char_fscanf_17_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE253_Incorrect_Check_of_Function_Return_Value__char_fscanf_17_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
