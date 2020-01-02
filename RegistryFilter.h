#pragma once
#include "common.h"
#include "StringFilters.h"

typedef class RegistryBlockingFilter
{
	static BOOLEAN BlockRegistryOperation(_In_ PVOID KeyObject,
										  _In_ PUNICODE_STRING ValueName,
										  _In_ ULONG OperationFlag
										  );

	static NTSTATUS RegistryCallback(_In_ PVOID CallbackContext,
									 _In_ REG_NOTIFY_CLASS OperationClass,
									 _In_ PVOID Argument2
									);

	//
	// Contains strings to block various registry operations.
	//
	static PSTRING_FILTERS RegistryStringFilters;

	//
	// Cookie used to remove registry callback.
	//
	static LARGE_INTEGER RegistryFilterCookie;
public:
	RegistryBlockingFilter (
		_In_ PDRIVER_OBJECT DriverObject,
		_Out_ NTSTATUS* Initialized
		);
	~RegistryBlockingFilter();

	static PSTRING_FILTERS GetStringFilters();
} REGISTRY_BLOCKING_FILTER, *PREGISTRY_BLOCKING_FILTER;

#define STRING_REGISTRY_FILTERS_TAG 'rFmP'
#define REGISTRY_KEY_NAME_TAG 'nKmP'