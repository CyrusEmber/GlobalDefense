// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "GlobalDefense/Testing/TestingPawn.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeTestingPawn() {}
// Cross Module References
	ENGINE_API UClass* Z_Construct_UClass_APawn();
	ENGINE_API UClass* Z_Construct_UClass_USceneComponent_NoRegister();
	GLOBALDEFENSE_API UClass* Z_Construct_UClass_ATestingPawn();
	GLOBALDEFENSE_API UClass* Z_Construct_UClass_ATestingPawn_NoRegister();
	UPackage* Z_Construct_UPackage__Script_GlobalDefense();
// End Cross Module References
	void ATestingPawn::StaticRegisterNativesATestingPawn()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ATestingPawn);
	UClass* Z_Construct_UClass_ATestingPawn_NoRegister()
	{
		return ATestingPawn::StaticClass();
	}
	struct Z_Construct_UClass_ATestingPawn_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_OurVisibleComponent_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_OurVisibleComponent;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ATestingPawn_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_APawn,
		(UObject* (*)())Z_Construct_UPackage__Script_GlobalDefense,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ATestingPawn_Statics::DependentSingletons) < 16);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ATestingPawn_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Navigation" },
		{ "IncludePath", "Testing/TestingPawn.h" },
		{ "ModuleRelativePath", "Testing/TestingPawn.h" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ATestingPawn_Statics::NewProp_OurVisibleComponent_MetaData[] = {
		{ "Category", "TestingPawn" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Testing/TestingPawn.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ATestingPawn_Statics::NewProp_OurVisibleComponent = { "OurVisibleComponent", nullptr, (EPropertyFlags)0x0010000000080009, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ATestingPawn, OurVisibleComponent), Z_Construct_UClass_USceneComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ATestingPawn_Statics::NewProp_OurVisibleComponent_MetaData), Z_Construct_UClass_ATestingPawn_Statics::NewProp_OurVisibleComponent_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ATestingPawn_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATestingPawn_Statics::NewProp_OurVisibleComponent,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_ATestingPawn_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ATestingPawn>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_ATestingPawn_Statics::ClassParams = {
		&ATestingPawn::StaticClass,
		"Game",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_ATestingPawn_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_ATestingPawn_Statics::PropPointers),
		0,
		0x009000A4u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ATestingPawn_Statics::Class_MetaDataParams), Z_Construct_UClass_ATestingPawn_Statics::Class_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ATestingPawn_Statics::PropPointers) < 2048);
	UClass* Z_Construct_UClass_ATestingPawn()
	{
		if (!Z_Registration_Info_UClass_ATestingPawn.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ATestingPawn.OuterSingleton, Z_Construct_UClass_ATestingPawn_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_ATestingPawn.OuterSingleton;
	}
	template<> GLOBALDEFENSE_API UClass* StaticClass<ATestingPawn>()
	{
		return ATestingPawn::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(ATestingPawn);
	ATestingPawn::~ATestingPawn() {}
	struct Z_CompiledInDeferFile_FID_UE_GlobalDefense_Source_GlobalDefense_Testing_TestingPawn_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UE_GlobalDefense_Source_GlobalDefense_Testing_TestingPawn_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_ATestingPawn, ATestingPawn::StaticClass, TEXT("ATestingPawn"), &Z_Registration_Info_UClass_ATestingPawn, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ATestingPawn), 3250260530U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UE_GlobalDefense_Source_GlobalDefense_Testing_TestingPawn_h_2393954105(TEXT("/Script/GlobalDefense"),
		Z_CompiledInDeferFile_FID_UE_GlobalDefense_Source_GlobalDefense_Testing_TestingPawn_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UE_GlobalDefense_Source_GlobalDefense_Testing_TestingPawn_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
