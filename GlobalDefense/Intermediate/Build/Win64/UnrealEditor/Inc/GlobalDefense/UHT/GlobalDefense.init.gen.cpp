// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeGlobalDefense_init() {}
	static FPackageRegistrationInfo Z_Registration_Info_UPackage__Script_GlobalDefense;
	FORCENOINLINE UPackage* Z_Construct_UPackage__Script_GlobalDefense()
	{
		if (!Z_Registration_Info_UPackage__Script_GlobalDefense.OuterSingleton)
		{
			static const UECodeGen_Private::FPackageParams PackageParams = {
				"/Script/GlobalDefense",
				nullptr,
				0,
				PKG_CompiledIn | 0x00000000,
				0x0F724F9F,
				0x6BA003FE,
				METADATA_PARAMS(0, nullptr)
			};
			UECodeGen_Private::ConstructUPackage(Z_Registration_Info_UPackage__Script_GlobalDefense.OuterSingleton, PackageParams);
		}
		return Z_Registration_Info_UPackage__Script_GlobalDefense.OuterSingleton;
	}
	static FRegisterCompiledInInfo Z_CompiledInDeferPackage_UPackage__Script_GlobalDefense(Z_Construct_UPackage__Script_GlobalDefense, TEXT("/Script/GlobalDefense"), Z_Registration_Info_UPackage__Script_GlobalDefense, CONSTRUCT_RELOAD_VERSION_INFO(FPackageReloadVersionInfo, 0x0F724F9F, 0x6BA003FE));
PRAGMA_ENABLE_DEPRECATION_WARNINGS
