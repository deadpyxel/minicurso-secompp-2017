/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE400_Resource_Exhaustion__connect_socket_sleep_52b.c
Label Definition File: CWE400_Resource_Exhaustion.label.xml
Template File: sources-sinks-52b.tmpl.c
*/
/*
 * @description
 * CWE: 400 Resource Exhaustion
 * BadSource: connect_socket Read data using a connect socket (client side)
 * GoodSource: Assign count to be a relatively small number
 * Sinks: sleep
 *    GoodSink: Validate count before using it as a parameter in sleep function
 *    BadSink : Use count as the parameter for sleep withhout checking it's size first
 * Flow Variant: 52 Data flow: data passed as an argument from one function to another to another in three different source files
 *
 * */

#include "std_testcase.h"

#ifdef _WIN32
#include <winsock2.h>
#include <windows.h>
#include <direct.h>
#pragma comment(lib, "ws2_32") /* include ws2_32.lib when linking */
#define CLOSE_SOCKET closesocket
#else /* NOT _WIN32 */
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#define INVALID_SOCKET -1
#define SOCKET_ERROR -1
#define CLOSE_SOCKET close
#define SOCKET int
#endif

#define TCP_PORT 27015
#define IP_ADDRESS "127.0.0.1"
#define CHAR_ARRAY_SIZE (3 * sizeof(count) + 2)

#ifdef _WIN32
#define SLEEP Sleep
#else
#define SLEEP usleep
#endif

#ifndef OMITBAD

/* bad function declaration */
void CWE400_Resource_Exhaustion__connect_socket_sleep_52c_badSink(int count);

void CWE400_Resource_Exhaustion__connect_socket_sleep_52b_badSink(int count)
{
    CWE400_Resource_Exhaustion__connect_socket_sleep_52c_badSink(count);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
void CWE400_Resource_Exhaustion__connect_socket_sleep_52c_goodG2BSink(int count);

void CWE400_Resource_Exhaustion__connect_socket_sleep_52b_goodG2BSink(int count)
{
    CWE400_Resource_Exhaustion__connect_socket_sleep_52c_goodG2BSink(count);
}

/* goodB2G uses the BadSource with the GoodSink */
void CWE400_Resource_Exhaustion__connect_socket_sleep_52c_goodB2GSink(int count);

void CWE400_Resource_Exhaustion__connect_socket_sleep_52b_goodB2GSink(int count)
{
    CWE400_Resource_Exhaustion__connect_socket_sleep_52c_goodB2GSink(count);
}

#endif /* OMITGOOD */
