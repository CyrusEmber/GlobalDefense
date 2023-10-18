// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "GlobalDefense/SimpleGameMode.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeSimpleGameMode() {}
// Cross Module References
	COREUOBJECT_API UClass* Z_Construct_UClass_UClass();
	ENGINE_API UClass* Z_Construct_UClass_AGameModeBase();
	GLOBALDEFENSE_API UClass* Z_Construct_UClass_ASimpleGameMode();
	GLOBALDEFENSE_API UClass* Z_Construct_UClass_ASimpleGameMode_NoRegister();
	UMG_API UClass* Z_Construct_UClass_UUserWidget_NoRegister();
	UPackage* Z_Construct_UPackage__Script_GlobalDefense();
// End Cross Module References
	DEFINE_FUNCTION(ASimpleGameMode::execChangeMenuWidget)
	{
		P_GET_OBJECT(UClass,Z_Param_NewWidgetClass);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->ChangeMenuWidget(Z_Param_NewWidgetClass);
		P_NATIVE_END;
	}
	void ASimpleGameMode::StaticRegisterNativesASimpleGameMode()
	{
		UClass* Class = ASimpleGameMode::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "ChangeMenuWidget", &ASimpleGameMode::execChangeMenuWidget },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_ASimpleGameMode_ChangeMenuWidget_Statics
	{
		struct SimpleGameMode_eventChangeMenuWidget_Parms
		{
			TSubclassOf<UUserWidget>  NewWidgetClass;
		};
		static const UECodeGen_Private::FClassPropertyParams NewProp_NewWidgetClass;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FClassPropertyParams Z_Construct_UFunction_ASimpleGameMode_ChangeMenuWidget_Statics::NewProp_NewWidgetClass = { "NewWidgetClass", nullptr, (EPropertyFlags)0x0014000000000080, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(SimpleGameMode_eventChangeMenuWidget_Parms, NewWidgetClass), Z_Construct_UClass_UClass, Z_Construct_UClass_UUserWidget_NoRegister, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASimpleGameMode_ChangeMenuWidget_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASimpleGameMode_ChangeMenuWidget_Statics::NewProp_NewWidgetClass,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASimpleGameMode_ChangeMenuWidget_Statics::Function_MetaDataParams[] = {
		{ "Category", "UMG Game" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Remove the current menu widget and create a new one from the specified class, if provided. */" },
#endif
		{ "ModuleRelativePath", "SimpleGameMode.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Remove the current menu widget and create a new one from the specified class, if provided." },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASimpleGameMode_ChangeMenuWidget_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASimpleGameMode, nullptr, "ChangeMenuWidget", nullptr, nullptr, Z_Construct_UFunction_ASimpleGameMode_ChangeMenuWidget_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ASimpleGameMode_ChangeMenuWidget_Statics::PropPointers), sizeof(Z_Construct_UFunction_ASimpleGameMode_ChangeMenuWidget_Statics::SimpleGameMode_eventChangeMenuWidget_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ASimpleGameMode_ChangeMenuWidget_Statics::Function_MetaDataParams), Z_Construct_UFunction_ASimpleGameMode_ChangeMenuWidget_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ASimpleGameMode_ChangeMenuWidget_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_ASimpleGameMode_ChangeMenuWidget_Statics::SimpleGameMode_eventChangeMenuWidget_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_ASimpleGameMode_ChangeMenuWidget()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASimpleGameMode_ChangeMenuWidget_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ASimpleGameMode);
	UClass* Z_Construct_UClass_ASimpleGameMode_NoRegister()
	{
		return ASimpleGameMode::StaticClass();
	}
	struct Z_Construct_UClass_ASimpleGameMode_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_StartingWidgetClass_MetaData[];
#endif
		static const UECodeGen_Private::FClassPropertyParams NewProp_StartingWidgetClass;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_CurrentWidget_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_CurrentWidget;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ASimpleGameMode_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AGameModeBase,
		(UObject* (*)())Z_Construct_UPackage__Script_GlobalDefense,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ASimpleGameMode_Statics::DependentSingletons) < 16);
	const FClassFunctionLinkInfo Z_Construct_UClass_ASimpleGameMode_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_ASimpleGameMode_ChangeMenuWidget, "ChangeMenuWidget" }, // 1480973760
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ASimpleGameMode_Statics::FuncInfo) < 2048);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASimpleGameMode_Statics::Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "HideCategories", "Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering HLOD WorldPartition DataLayers Transformation" },
		{ "IncludePath", "SimpleGameMode.h" },
		{ "ModuleRelativePath", "SimpleGameMode.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASimpleGameMode_Statics::NewProp_StartingWidgetClass_MetaData[] = {
		{ "Category", "UMG Game" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** The widget class we will use as our menu when the game starts. */" },
#endif
		{ "ModuleRelativePath", "SimpleGameMode.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "The widget class we will use as our menu when the game starts." },
#endif
	};
#endif
	const UECodeGen_Private::FClassPropertyParams Z_Construct_UClass_ASimpleGameMode_Statics::NewProp_StartingWidgetClass = { "StartingWidgetClass", nullptr, (EPropertyFlags)0x0024080000000015, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ASimpleGameMode, StartingWidgetClass), Z_Construct_UClass_UClass, Z_Construct_UClass_UUserWidget_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ASimpleGameMode_Statics::NewProp_StartingWidgetClass_MetaData), Z_Construct_UClass_ASimpleGameMode_Statics::NewProp_StartingWidgetClass_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASimpleGameMode_Statics::NewProp_CurrentWidget_MetaData[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** The widget instance that we are using as our menu. */" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "SimpleGameMode.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "The widget instance that we are using as our menu." },
#endif
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ASimpleGameMode_Statics::NewProp_CurrentWidget = { "CurrentWidget", nullptr, (EPropertyFlags)0x0020080000080008, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ASimpleGameMode, CurrentWidget), Z_Construct_UClass_UUserWidget_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ASimpleGameMode_Statics::NewProp_CurrentWidget_MetaData), Z_Construct_UClass_ASimpleGameMode_Statics::NewProp_CurrentWidget_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ASimpleGameMode_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASimpleGameMode_Statics::NewProp_StartingWidgetClass,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASimpleGameMode_Statics::NewProp_CurrentWidget,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_ASimpleGameMode_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ASimpleGameMode>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_ASimpleGameMode_Statics::ClassParams = {
		&ASimpleGameMode::StaticClass,
		"Game",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_ASimpleGameMode_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_ASimpleGameMode_Statics::PropPointers),
		0,
		0x009002ACu,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ASimpleGameMode_Statics::Class_MetaDataParams), Z_Construct_UClass_ASimpleGameMode_Statics::Class_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ASimpleGameMode_Statics::PropPointers) < 2048);
	UClass* Z_Construct_UClass_ASimpleGameMode()
	{
		if (!Z_Registration_Info_UClass_ASimpleGameMode.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ASimpleGameMode.OuterSingleton, Z_Construct_UClass_ASimpleGameMode_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_ASimpleGameMode.OuterSingleton;
	}
	template<> GLOBALDEFENSE_API UClass* StaticClass<ASimpleGameMode>()
	{
		return ASimpleGameMode::StaticClass();
	}
	ASimpleGameMode::ASimpleGameMode(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
	DEFINE_VTABLE_PTR_HELPER_CTOR(ASimpleGameMode);
	ASimpleGameMode::~ASimpleGameMode() {}
	struct Z_CompiledInDeferFile_FID_UE_UnrealProject_GlobalDefense_Source_GlobalDefense_SimpleGameMode_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UE_UnrealProject_GlobalDefense_Source_GlobalDefense_SimpleGameMode_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_ASimpleGameMode, ASimpleGameMode::StaticClass, TEXT("ASimpleGameMode"), &Z_Registration_Info_UClass_ASimpleGameMode, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ASimpleGameMode), 645790227U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UE_UnrealProject_GlobalDefense_Source_GlobalDefense_SimpleGameMode_h_155191061(TEXT("/Script/GlobalDefense"),
		Z_CompiledInDeferFile_FID_UE_UnrealProject_GlobalDefense_Source_GlobalDefense_SimpleGameMode_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UE_UnrealProject_GlobalDefense_Source_GlobalDefense_SimpleGameMode_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
