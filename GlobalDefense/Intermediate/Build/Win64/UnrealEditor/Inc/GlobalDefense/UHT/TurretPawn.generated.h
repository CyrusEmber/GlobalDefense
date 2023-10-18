// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "TurretPawn.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class AActor;
class UPrimitiveComponent;
struct FHitResult;
#ifdef GLOBALDEFENSE_TurretPawn_generated_h
#error "TurretPawn.generated.h already included, missing '#pragma once' in TurretPawn.h"
#endif
#define GLOBALDEFENSE_TurretPawn_generated_h

#define FID_UE_UnrealProject_GlobalDefense_Source_GlobalDefense_TurretPawn_h_13_SPARSE_DATA
#define FID_UE_UnrealProject_GlobalDefense_Source_GlobalDefense_TurretPawn_h_13_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_UE_UnrealProject_GlobalDefense_Source_GlobalDefense_TurretPawn_h_13_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_UE_UnrealProject_GlobalDefense_Source_GlobalDefense_TurretPawn_h_13_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execOnOverlapEnd); \
	DECLARE_FUNCTION(execTriggerEnter);


#define FID_UE_UnrealProject_GlobalDefense_Source_GlobalDefense_TurretPawn_h_13_ACCESSORS
#define FID_UE_UnrealProject_GlobalDefense_Source_GlobalDefense_TurretPawn_h_13_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesATurretPawn(); \
	friend struct Z_Construct_UClass_ATurretPawn_Statics; \
public: \
	DECLARE_CLASS(ATurretPawn, APawn, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/GlobalDefense"), NO_API) \
	DECLARE_SERIALIZER(ATurretPawn)


#define FID_UE_UnrealProject_GlobalDefense_Source_GlobalDefense_TurretPawn_h_13_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ATurretPawn(ATurretPawn&&); \
	NO_API ATurretPawn(const ATurretPawn&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ATurretPawn); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ATurretPawn); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(ATurretPawn) \
	NO_API virtual ~ATurretPawn();


#define FID_UE_UnrealProject_GlobalDefense_Source_GlobalDefense_TurretPawn_h_10_PROLOG
#define FID_UE_UnrealProject_GlobalDefense_Source_GlobalDefense_TurretPawn_h_13_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_UE_UnrealProject_GlobalDefense_Source_GlobalDefense_TurretPawn_h_13_SPARSE_DATA \
	FID_UE_UnrealProject_GlobalDefense_Source_GlobalDefense_TurretPawn_h_13_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_UE_UnrealProject_GlobalDefense_Source_GlobalDefense_TurretPawn_h_13_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_UE_UnrealProject_GlobalDefense_Source_GlobalDefense_TurretPawn_h_13_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_UE_UnrealProject_GlobalDefense_Source_GlobalDefense_TurretPawn_h_13_ACCESSORS \
	FID_UE_UnrealProject_GlobalDefense_Source_GlobalDefense_TurretPawn_h_13_INCLASS_NO_PURE_DECLS \
	FID_UE_UnrealProject_GlobalDefense_Source_GlobalDefense_TurretPawn_h_13_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> GLOBALDEFENSE_API UClass* StaticClass<class ATurretPawn>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_UE_UnrealProject_GlobalDefense_Source_GlobalDefense_TurretPawn_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
