#define _WIN32_DCOM
#include <iostream>
using namespace std;
#include <comdef.h>
#include <Wbemidl.h>

# pragma comment(lib, "wbemuuid.lib")

int main(int argc, char **argv)
{
CoInitializeEx(0,COINIT_MULTITHREADED);
try
{
if(SUCCEEDED(CoInitializeSecurity(NULL,-1,NULL,NULL,RPC_C_AUTHN_LEVEL_DEFAULT,RPC_C_IMP_LEVEL_IMPERSONATE,NULL,EOAC_NONE,NULL)))
{
IWbemLocator *pLoc=NULL;
if(SUCCEEDED(CoCreateInstance(CLSID_WbemLocator,0,CLSCTX_INPROC_SERVER,IID_IWbemLocator,(LPVOID *)&pLoc)))
{
IWbemServices *pSvc=NULL;
if(SUCCEEDED(pLoc->ConnectServer(_bstr_t(L"ROOT\\WMI"),NULL,NULL,0,NULL,0,0,&pSvc)))
{
if(SUCCEEDED(CoSetProxyBlanket(pSvc,RPC_C_AUTHN_WINNT,RPC_C_AUTHZ_NONE,NULL,RPC_C_AUTHN_LEVEL_CALL,RPC_C_IMP_LEVEL_IMPERSONATE,NULL,EOAC_NONE)))
{
IEnumWbemClassObject* pEnumerator=NULL;
if(SUCCEEDED(pSvc->ExecQuery(bstr_t("WQL"),bstr_t("SELECT * FROM MSAcpi_ThermalZoneTemperature"),WBEM_FLAG_FORWARD_ONLY|WBEM_FLAG_RETURN_IMMEDIATELY,NULL,&pEnumerator)))
{
IWbemClassObject *pclsObj;
ULONG uReturn=0;
while(pEnumerator)
{
pEnumerator->Next(WBEM_INFINITE, 1, &pclsObj, &uReturn);
if(0==uReturn)
break;
VARIANT vtProp;
VariantInit(&vtProp);
pclsObj->Get(L"CurrentTemperature", 0, &vtProp, 0, 0);
wcout << "Current CPU Temperature : " << (vtProp.intVal - 2732)/10.0 << endl;
VariantClear(&vtProp);
pclsObj->Release();
}
}
}
pSvc->Release();
}
pLoc->Release();
}
}
}
catch (_com_error err)
{
}
CoUninitialize();
return 0;
}
