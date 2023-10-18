// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "GlobalDefense/Testing/FloatingActor.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeFloatingActor() {}
// Cross Module References
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	ENGINE_API UClass* Z_Construct_UClass_UStaticMeshComponent_NoRegister();
	GLOBALDEFENSE_API UClass* Z_Construct_UClass_AFloatingActor();
	GLOBALDEFENSE_API UClass* Z_Construct_UClass_AFloatingActor_NoRegister();
	UPackage* Z_Construct_UPackage__Script_GlobalDefense();
// End Cross Module References
	void AFloatingActor::StaticRegisterNativesAFloatingActor()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AFloatingActor);
	UClass* Z_Construct_UClass_AFloatingActor_NoRegister()
	{
		return AFloatingActor::StaticClass();
	}
	struct Z_Construct_UClass_AFloatingActor_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_VisualMesh_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_VisualMesh;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AFloatingActor_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_GlobalDefense,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AFloatingActor_Statics::DependentSingletons) < 16);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AFloatingActor_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "Testing/FloatingActor.h" },
		{ "ModuleRelativePath", "Testing/FloatingActor.h" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AFloatingActor_Statics::NewProp_VisualMesh_MetaData[] = {
		{ "Category", "FloatingActor" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Testing/FloatingActor.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AFloatingActor_Statics::NewProp_VisualMesh = { "VisualMesh", nullptr, (EPropertyFlags)0x00100000000a0009, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AFloatingActor, VisualMesh), Z_Construct_UClass_UStaticMeshComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AFloatingActor_Statics::NewProp_VisualMesh_MetaData), Z_Construct_UClass_AFloatingActor_Statics::NewProp_VisualMesh_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AFloatingActor_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFloatingActor_Statics::NewProp_VisualMesh,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_AFloatingActor_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AFloatingActor>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_AFloatingActor_Statics::ClassParams = {
		&AFloatingActor::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_AFloatingActor_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_AFloatingActor_Statics::PropPointers),
		0,
		0x009000A4u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AFloatingActor_Statics::Class_MetaDataParams), Z_Construct_UClass_AFloatingActor_Statics::Class_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AFloatingActor_Statics::PropPointers) < 2048);
	UClass* Z_Construct_UClass_AFloatingActor()
	{
		if (!Z_Registration_Info_UClass_AFloatingActor.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AFloatingActor.OuterSingleton, Z_Construct_UClass_AFloatingActor_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_AFloatingActor.OuterSingleton;
	}
	template<> GLOBALDEFENSE_API UClass* StaticClass<AFloatingActor>()
	{
		return AFloatingActor::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(AFloatingActor);
	AFloatingActor::~AFloatingActor() {}
	struct Z_CompiledInDeferFile_FID_UE_UnrealProject_GlobalDefense_Source_GlobalDefense_Testing_FloatingActor_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UE_UnrealProject_GlobalDefense_Source_GlobalDefense_Testing_FloatingActor_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_AFloatingActor, AFloatingActor::StaticClass, TEXT("AFloatingActor"), &Z_Registration_Info_UClass_AFloatingActor, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AFloatingActor), 2773925463U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UE_UnrealProject_GlobalDefense_Source_GlobalDefense_Testing_FloatingActor_h_388770425(TEXT("/Script/GlobalDefense"),
		Z_CompiledInDeferFile_FID_UE_UnrealProject_GlobalDefense_Source_GlobalDefense_Testing_FloatingActor_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UE_UnrealProject_GlobalDefense_Source_GlobalDefense_Testing_FloatingActor_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
