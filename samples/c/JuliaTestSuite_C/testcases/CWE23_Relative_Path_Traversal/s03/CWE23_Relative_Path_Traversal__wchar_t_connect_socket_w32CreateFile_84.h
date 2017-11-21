/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE23_Relative_Path_Traversal__wchar_t_connect_socket_w32CreateFile_84.h
Label Definition File: CWE23_Relative_Path_Traversal.label.xml
Template File: sources-sink-84.tmpl.h
*/
/*
 * @description
 * CWE: 23 Relative Path Traversal
 * BadSource: connect_socket Read data using a connect socket (client side)
 * GoodSource: Use a fixed file name
 * Sinks: w32CreateFile
 *    BadSink : Open the file named in data using CreateFile()
 * Flow Variant: 84 Data flow: data passed to class constructor and destructor by declaring the class object on the heap and deleting it after use
 *
 * */

#include "std_testcase.h"

#ifdef _WIN32
#define BASEPATH L"c:\\temp\\"
#else
#include <wchar.h>
#define BASEPATH L"/tmp/"
#endif

namespace CWE23_Relative_Path_Traversal__wchar_t_connect_socket_w32CreateFile_84
{

#ifndef OMITBAD

class CWE23_Relative_Path_Traversal__wchar_t_connect_socket_w32CreateFile_84_bad
{
public:
    CWE23_Relative_Path_Traversal__wchar_t_connect_socket_w32CreateFile_84_bad(wchar_t * dataCopy);
    ~CWE23_Relative_Path_Traversal__wchar_t_connect_socket_w32CreateFile_84_bad();

private:
    wchar_t * data;
};

#endif /* OMITBAD */

#ifndef OMITGOOD

class CWE23_Relative_Path_Traversal__wchar_t_connect_socket_w32CreateFile_84_goodG2B
{
public:
    CWE23_Relative_Path_Traversal__wchar_t_connect_socket_w32CreateFile_84_goodG2B(wchar_t * dataCopy);
    ~CWE23_Relative_Path_Traversal__wchar_t_connect_socket_w32CreateFile_84_goodG2B();

private:
    wchar_t * data;
};

#endif /* OMITGOOD */

}
