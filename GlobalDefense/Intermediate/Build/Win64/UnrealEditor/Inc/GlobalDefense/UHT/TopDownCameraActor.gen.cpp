// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "GlobalDefense/Testing/TopDownCameraActor.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeTopDownCameraActor() {}
// Cross Module References
	ENGINE_API UClass* Z_Construct_UClass_ACameraActor();
	ENGINE_API UClass* Z_Construct_UClass_UCameraComponent_NoRegister();
	GLOBALDEFENSE_API UClass* Z_Construct_UClass_ATopDownCameraActor();
	GLOBALDEFENSE_API UClass* Z_Construct_UClass_ATopDownCameraActor_NoRegister();
	UPackage* Z_Construct_UPackage__Script_GlobalDefense();
// End Cross Module References
	void ATopDownCameraActor::StaticRegisterNativesATopDownCameraActor()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ATopDownCameraActor);
	UClass* Z_Construct_UClass_ATopDownCameraActor_NoRegister()
	{
		return ATopDownCameraActor::StaticClass();
	}
	struct Z_Construct_UClass_ATopDownCameraActor_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Camera_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_Camera;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ATopDownCameraActor_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_ACameraActor,
		(UObject* (*)())Z_Construct_UPackage__Script_GlobalDefense,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ATopDownCameraActor_Statics::DependentSingletons) < 16);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ATopDownCameraActor_Statics::Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "HideCategories", "Input Rendering" },
		{ "IncludePath", "Testing/TopDownCameraActor.h" },
		{ "ModuleRelativePath", "Testing/TopDownCameraActor.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ATopDownCameraActor_Statics::NewProp_Camera_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Camera" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Follow camera */" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Testing/TopDownCameraActor.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Follow camera" },
#endif
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ATopDownCameraActor_Statics::NewProp_Camera = { "Camera", nullptr, (EPropertyFlags)0x00400000000a001d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ATopDownCameraActor, Camera), Z_Construct_UClass_UCameraComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ATopDownCameraActor_Statics::NewProp_Camera_MetaData), Z_Construct_UClass_ATopDownCameraActor_Statics::NewProp_Camera_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ATopDownCameraActor_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATopDownCameraActor_Statics::NewProp_Camera,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_ATopDownCameraActor_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ATopDownCameraActor>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_ATopDownCameraActor_Statics::ClassParams = {
		&ATopDownCameraActor::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_ATopDownCameraActor_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_ATopDownCameraActor_Statics::PropPointers),
		0,
		0x009000A4u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ATopDownCameraActor_Statics::Class_MetaDataParams), Z_Construct_UClass_ATopDownCameraActor_Statics::Class_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ATopDownCameraActor_Statics::PropPointers) < 2048);
	UClass* Z_Construct_UClass_ATopDownCameraActor()
	{
		if (!Z_Registration_Info_UClass_ATopDownCameraActor.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ATopDownCameraActor.OuterSingleton, Z_Construct_UClass_ATopDownCameraActor_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_ATopDownCameraActor.OuterSingleton;
	}
	template<> GLOBALDEFENSE_API UClass* StaticClass<ATopDownCameraActor>()
	{
		return ATopDownCameraActor::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(ATopDownCameraActor);
	ATopDownCameraActor::~ATopDownCameraActor() {}
	struct Z_CompiledInDeferFile_FID_UE_GlobalDefense_Source_GlobalDefense_Testing_TopDownCameraActor_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UE_GlobalDefense_Source_GlobalDefense_Testing_TopDownCameraActor_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_ATopDownCameraActor, ATopDownCameraActor::StaticClass, TEXT("ATopDownCameraActor"), &Z_Registration_Info_UClass_ATopDownCameraActor, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ATopDownCameraActor), 4156273072U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UE_GlobalDefense_Source_GlobalDefense_Testing_TopDownCameraActor_h_669165219(TEXT("/Script/GlobalDefense"),
		Z_CompiledInDeferFile_FID_UE_GlobalDefense_Source_GlobalDefense_Testing_TopDownCameraActor_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UE_GlobalDefense_Source_GlobalDefense_Testing_TopDownCameraActor_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
