/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE23_Relative_Path_Traversal__wchar_t_file_ofstream_42.cpp
Label Definition File: CWE23_Relative_Path_Traversal.label.xml
Template File: sources-sink-42.tmpl.cpp
*/
/*
 * @description
 * CWE: 23 Relative Path Traversal
 * BadSource: file Read input from a file
 * GoodSource: Use a fixed file name
 * Sink: ofstream
 *    BadSink : Open the file named in data using ofstream::open()
 * Flow Variant: 42 Data flow: data returned from one function to another in the same source file
 *
 * */

#include "std_testcase.h"

#ifdef _WIN32
#define BASEPATH L"c:\\temp\\"
#else
#include <wchar.h>
#define BASEPATH L"/tmp/"
#endif

#ifdef _WIN32
#define FILENAME "C:\\temp\\file.txt"
#else
#define FILENAME "/tmp/file.txt"
#endif

#include <fstream>
using namespace std;

namespace CWE23_Relative_Path_Traversal__wchar_t_file_ofstream_42
{

#ifndef OMITBAD

static wchar_t * badSource(wchar_t * data)
{
    {
        /* Read input from a file */
        size_t dataLen = wcslen(data);
        FILE * pFile;
        /* if there is room in data, attempt to read the input from a file */
        if (FILENAME_MAX-dataLen > 1)
        {
            pFile = fopen(FILENAME, "r");
            if (pFile != NULL)
            {
                /* POTENTIAL FLAW: Read data from a file */
                if (fgetws(data+dataLen, (int)(FILENAME_MAX-dataLen), pFile) == NULL)
                {
                    printLine("fgetws() failed");
                    /* Restore NUL terminator if fgetws fails */
                    data[dataLen] = L'\0';
                }
                fclose(pFile);
            }
        }
    }
    return data;
}

void bad()
{
    wchar_t * data;
    wchar_t dataBuffer[FILENAME_MAX] = BASEPATH;
    data = dataBuffer;
    data = badSource(data);
    {
        ofstream outputFile;
        /* POTENTIAL FLAW: Possibly opening a file without validating the file name or path */
        outputFile.open((char *)data);
        outputFile.close();
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

static wchar_t * goodG2BSource(wchar_t * data)
{
    /* FIX: Use a fixed file name */
    wcscat(data, L"file.txt");
    return data;
}

/* goodG2B() uses the GoodSource with the BadSink */
static void goodG2B()
{
    wchar_t * data;
    wchar_t dataBuffer[FILENAME_MAX] = BASEPATH;
    data = dataBuffer;
    data = goodG2BSource(data);
    {
        ofstream outputFile;
        /* POTENTIAL FLAW: Possibly opening a file without validating the file name or path */
        outputFile.open((char *)data);
        outputFile.close();
    }
}

void good()
{
    goodG2B();
}

#endif /* OMITGOOD */

} /* close namespace */

/* Below is the main(). It is only used when building this testcase on
   its own for testing or for building a binary to use in testing binary
   analysis tools. It is not used when compiling all the testcases as one
   application, which is how source code analysis tools are tested. */

#ifdef INCLUDEMAIN

using namespace CWE23_Relative_Path_Traversal__wchar_t_file_ofstream_42; /* so that we can use good and bad easily */

int main(int argc, char * argv[])
{
    /* seed randomness */
    srand( (unsigned)time(NULL) );
#ifndef OMITGOOD
    printLine("Calling good()...");
    good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
