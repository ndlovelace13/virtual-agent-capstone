// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "VirtualAgent/TextStorage.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeTextStorage() {}

// Begin Cross Module References
ENGINE_API UClass* Z_Construct_UClass_UActorComponent();
UPackage* Z_Construct_UPackage__Script_VirtualAgent();
VIRTUALAGENT_API UClass* Z_Construct_UClass_UTextStorage();
VIRTUALAGENT_API UClass* Z_Construct_UClass_UTextStorage_NoRegister();
// End Cross Module References

// Begin Class UTextStorage
void UTextStorage::StaticRegisterNativesUTextStorage()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UTextStorage);
UClass* Z_Construct_UClass_UTextStorage_NoRegister()
{
	return UTextStorage::StaticClass();
}
struct Z_Construct_UClass_UTextStorage_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintSpawnableComponent", "" },
		{ "ClassGroupNames", "Custom" },
		{ "IncludePath", "TextStorage.h" },
		{ "ModuleRelativePath", "TextStorage.h" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UTextStorage>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_UTextStorage_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UActorComponent,
	(UObject* (*)())Z_Construct_UPackage__Script_VirtualAgent,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UTextStorage_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UTextStorage_Statics::ClassParams = {
	&UTextStorage::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	nullptr,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	0,
	0,
	0x00B000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UTextStorage_Statics::Class_MetaDataParams), Z_Construct_UClass_UTextStorage_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UTextStorage()
{
	if (!Z_Registration_Info_UClass_UTextStorage.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UTextStorage.OuterSingleton, Z_Construct_UClass_UTextStorage_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UTextStorage.OuterSingleton;
}
template<> VIRTUALAGENT_API UClass* StaticClass<UTextStorage>()
{
	return UTextStorage::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(UTextStorage);
UTextStorage::~UTextStorage() {}
// End Class UTextStorage

// Begin Registration
struct Z_CompiledInDeferFile_FID_Users_ndlov_Documents_Unreal_Projects_virtual_agent_capstone_VirtualAgent_Source_VirtualAgent_TextStorage_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UTextStorage, UTextStorage::StaticClass, TEXT("UTextStorage"), &Z_Registration_Info_UClass_UTextStorage, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UTextStorage), 3723300031U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_ndlov_Documents_Unreal_Projects_virtual_agent_capstone_VirtualAgent_Source_VirtualAgent_TextStorage_h_245441473(TEXT("/Script/VirtualAgent"),
	Z_CompiledInDeferFile_FID_Users_ndlov_Documents_Unreal_Projects_virtual_agent_capstone_VirtualAgent_Source_VirtualAgent_TextStorage_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_ndlov_Documents_Unreal_Projects_virtual_agent_capstone_VirtualAgent_Source_VirtualAgent_TextStorage_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
