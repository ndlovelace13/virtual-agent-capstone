// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeVirtualAgent_init() {}
	static FPackageRegistrationInfo Z_Registration_Info_UPackage__Script_VirtualAgent;
	FORCENOINLINE UPackage* Z_Construct_UPackage__Script_VirtualAgent()
	{
		if (!Z_Registration_Info_UPackage__Script_VirtualAgent.OuterSingleton)
		{
			static const UECodeGen_Private::FPackageParams PackageParams = {
				"/Script/VirtualAgent",
				nullptr,
				0,
				PKG_CompiledIn | 0x00000000,
				0x0276945F,
				0x299B1FF9,
				METADATA_PARAMS(0, nullptr)
			};
			UECodeGen_Private::ConstructUPackage(Z_Registration_Info_UPackage__Script_VirtualAgent.OuterSingleton, PackageParams);
		}
		return Z_Registration_Info_UPackage__Script_VirtualAgent.OuterSingleton;
	}
	static FRegisterCompiledInInfo Z_CompiledInDeferPackage_UPackage__Script_VirtualAgent(Z_Construct_UPackage__Script_VirtualAgent, TEXT("/Script/VirtualAgent"), Z_Registration_Info_UPackage__Script_VirtualAgent, CONSTRUCT_RELOAD_VERSION_INFO(FPackageReloadVersionInfo, 0x0276945F, 0x299B1FF9));
PRAGMA_ENABLE_DEPRECATION_WARNINGS