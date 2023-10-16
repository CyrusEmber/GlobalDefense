// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "GlobalDefense/Testing/CollidingPawn.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeCollidingPawn() {}
// Cross Module References
	ENGINE_API UClass* Z_Construct_UClass_APawn();
	ENGINE_API UClass* Z_Construct_UClass_UParticleSystemComponent_NoRegister();
	GLOBALDEFENSE_API UClass* Z_Construct_UClass_ACollidingPawn();
	GLOBALDEFENSE_API UClass* Z_Construct_UClass_ACollidingPawn_NoRegister();
	GLOBALDEFENSE_API UClass* Z_Construct_UClass_UCollidingPawnMovementComponent_NoRegister();
	UPackage* Z_Construct_UPackage__Script_GlobalDefense();
// End Cross Module References
	void ACollidingPawn::StaticRegisterNativesACollidingPawn()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ACollidingPawn);
	UClass* Z_Construct_UClass_ACollidingPawn_NoRegister()
	{
		return ACollidingPawn::StaticClass();
	}
	struct Z_Construct_UClass_ACollidingPawn_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_OurParticleSystem_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_OurParticleSystem;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_OurMovementComponent_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_OurMovementComponent;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ACollidingPawn_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_APawn,
		(UObject* (*)())Z_Construct_UPackage__Script_GlobalDefense,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ACollidingPawn_Statics::DependentSingletons) < 16);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ACollidingPawn_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Navigation" },
		{ "IncludePath", "Testing/CollidingPawn.h" },
		{ "ModuleRelativePath", "Testing/CollidingPawn.h" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ACollidingPawn_Statics::NewProp_OurParticleSystem_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Testing/CollidingPawn.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ACollidingPawn_Statics::NewProp_OurParticleSystem = { "OurParticleSystem", nullptr, (EPropertyFlags)0x0010000000080008, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ACollidingPawn, OurParticleSystem), Z_Construct_UClass_UParticleSystemComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ACollidingPawn_Statics::NewProp_OurParticleSystem_MetaData), Z_Construct_UClass_ACollidingPawn_Statics::NewProp_OurParticleSystem_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ACollidingPawn_Statics::NewProp_OurMovementComponent_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Testing/CollidingPawn.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ACollidingPawn_Statics::NewProp_OurMovementComponent = { "OurMovementComponent", nullptr, (EPropertyFlags)0x0010000000080008, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ACollidingPawn, OurMovementComponent), Z_Construct_UClass_UCollidingPawnMovementComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ACollidingPawn_Statics::NewProp_OurMovementComponent_MetaData), Z_Construct_UClass_ACollidingPawn_Statics::NewProp_OurMovementComponent_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ACollidingPawn_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ACollidingPawn_Statics::NewProp_OurParticleSystem,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ACollidingPawn_Statics::NewProp_OurMovementComponent,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_ACollidingPawn_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ACollidingPawn>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_ACollidingPawn_Statics::ClassParams = {
		&ACollidingPawn::StaticClass,
		"Game",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_ACollidingPawn_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_ACollidingPawn_Statics::PropPointers),
		0,
		0x009000A4u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ACollidingPawn_Statics::Class_MetaDataParams), Z_Construct_UClass_ACollidingPawn_Statics::Class_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ACollidingPawn_Statics::PropPointers) < 2048);
	UClass* Z_Construct_UClass_ACollidingPawn()
	{
		if (!Z_Registration_Info_UClass_ACollidingPawn.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ACollidingPawn.OuterSingleton, Z_Construct_UClass_ACollidingPawn_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_ACollidingPawn.OuterSingleton;
	}
	template<> GLOBALDEFENSE_API UClass* StaticClass<ACollidingPawn>()
	{
		return ACollidingPawn::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(ACollidingPawn);
	ACollidingPawn::~ACollidingPawn() {}
	struct Z_CompiledInDeferFile_FID_UE_GlobalDefense_Source_GlobalDefense_Testing_CollidingPawn_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UE_GlobalDefense_Source_GlobalDefense_Testing_CollidingPawn_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_ACollidingPawn, ACollidingPawn::StaticClass, TEXT("ACollidingPawn"), &Z_Registration_Info_UClass_ACollidingPawn, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ACollidingPawn), 2369513099U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UE_GlobalDefense_Source_GlobalDefense_Testing_CollidingPawn_h_383566075(TEXT("/Script/GlobalDefense"),
		Z_CompiledInDeferFile_FID_UE_GlobalDefense_Source_GlobalDefense_Testing_CollidingPawn_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UE_GlobalDefense_Source_GlobalDefense_Testing_CollidingPawn_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
