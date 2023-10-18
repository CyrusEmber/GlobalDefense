// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "SimpleGameMode.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class UUserWidget;
#ifdef GLOBALDEFENSE_SimpleGameMode_generated_h
#error "SimpleGameMode.generated.h already included, missing '#pragma once' in SimpleGameMode.h"
#endif
#define GLOBALDEFENSE_SimpleGameMode_generated_h

#define FID_UE_UnrealProject_GlobalDefense_Source_GlobalDefense_SimpleGameMode_h_15_SPARSE_DATA
#define FID_UE_UnrealProject_GlobalDefense_Source_GlobalDefense_SimpleGameMode_h_15_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_UE_UnrealProject_GlobalDefense_Source_GlobalDefense_SimpleGameMode_h_15_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_UE_UnrealProject_GlobalDefense_Source_GlobalDefense_SimpleGameMode_h_15_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execChangeMenuWidget);


#define FID_UE_UnrealProject_GlobalDefense_Source_GlobalDefense_SimpleGameMode_h_15_ACCESSORS
#define FID_UE_UnrealProject_GlobalDefense_Source_GlobalDefense_SimpleGameMode_h_15_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesASimpleGameMode(); \
	friend struct Z_Construct_UClass_ASimpleGameMode_Statics; \
public: \
	DECLARE_CLASS(ASimpleGameMode, AGameModeBase, COMPILED_IN_FLAGS(0 | CLASS_Transient | CLASS_Config), CASTCLASS_None, TEXT("/Script/GlobalDefense"), NO_API) \
	DECLARE_SERIALIZER(ASimpleGameMode)


#define FID_UE_UnrealProject_GlobalDefense_Source_GlobalDefense_SimpleGameMode_h_15_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API ASimpleGameMode(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ASimpleGameMode(ASimpleGameMode&&); \
	NO_API ASimpleGameMode(const ASimpleGameMode&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ASimpleGameMode); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ASimpleGameMode); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(ASimpleGameMode) \
	NO_API virtual ~ASimpleGameMode();


#define FID_UE_UnrealProject_GlobalDefense_Source_GlobalDefense_SimpleGameMode_h_12_PROLOG
#define FID_UE_UnrealProject_GlobalDefense_Source_GlobalDefense_SimpleGameMode_h_15_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_UE_UnrealProject_GlobalDefense_Source_GlobalDefense_SimpleGameMode_h_15_SPARSE_DATA \
	FID_UE_UnrealProject_GlobalDefense_Source_GlobalDefense_SimpleGameMode_h_15_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_UE_UnrealProject_GlobalDefense_Source_GlobalDefense_SimpleGameMode_h_15_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_UE_UnrealProject_GlobalDefense_Source_GlobalDefense_SimpleGameMode_h_15_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_UE_UnrealProject_GlobalDefense_Source_GlobalDefense_SimpleGameMode_h_15_ACCESSORS \
	FID_UE_UnrealProject_GlobalDefense_Source_GlobalDefense_SimpleGameMode_h_15_INCLASS_NO_PURE_DECLS \
	FID_UE_UnrealProject_GlobalDefense_Source_GlobalDefense_SimpleGameMode_h_15_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> GLOBALDEFENSE_API UClass* StaticClass<class ASimpleGameMode>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_UE_UnrealProject_GlobalDefense_Source_GlobalDefense_SimpleGameMode_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
