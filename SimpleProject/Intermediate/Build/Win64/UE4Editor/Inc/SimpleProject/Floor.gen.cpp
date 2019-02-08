// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "GeneratedCppIncludes.h"
#include "Floor.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeFloor() {}
// Cross Module References
	SIMPLEPROJECT_API UClass* Z_Construct_UClass_AFloor_NoRegister();
	SIMPLEPROJECT_API UClass* Z_Construct_UClass_AFloor();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	UPackage* Z_Construct_UPackage__Script_SimpleProject();
	ENGINE_API UClass* Z_Construct_UClass_UStaticMeshComponent_NoRegister();
// End Cross Module References
	void AFloor::StaticRegisterNativesAFloor()
	{
	}
	UClass* Z_Construct_UClass_AFloor_NoRegister()
	{
		return AFloor::StaticClass();
	}
	UClass* Z_Construct_UClass_AFloor()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			static UObject* (*const DependentSingletons[])() = {
				(UObject* (*)())Z_Construct_UClass_AActor,
				(UObject* (*)())Z_Construct_UPackage__Script_SimpleProject,
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
				{ "IncludePath", "Floor.h" },
				{ "ModuleRelativePath", "Floor.h" },
			};
#endif
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_FloorMeshComponent_MetaData[] = {
				{ "AllowPrivateAccess", "true" },
				{ "Category", "Enemy" },
				{ "EditInline", "true" },
				{ "ModuleRelativePath", "Floor.h" },
				{ "ToolTip", "Static mesh for floor." },
			};
#endif
			static const UE4CodeGen_Private::FObjectPropertyParams NewProp_FloorMeshComponent = { UE4CodeGen_Private::EPropertyClass::Object, "FloorMeshComponent", RF_Public|RF_Transient|RF_MarkAsNative, 0x00400000000a001d, 1, nullptr, STRUCT_OFFSET(AFloor, FloorMeshComponent), Z_Construct_UClass_UStaticMeshComponent_NoRegister, METADATA_PARAMS(NewProp_FloorMeshComponent_MetaData, ARRAY_COUNT(NewProp_FloorMeshComponent_MetaData)) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_FloorMeshComponent,
			};
			static const FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
				TCppClassTypeTraits<AFloor>::IsAbstract,
			};
			static const UE4CodeGen_Private::FClassParams ClassParams = {
				&AFloor::StaticClass,
				DependentSingletons, ARRAY_COUNT(DependentSingletons),
				0x00900080u,
				nullptr, 0,
				PropPointers, ARRAY_COUNT(PropPointers),
				nullptr,
				&StaticCppClassTypeInfo,
				nullptr, 0,
				METADATA_PARAMS(Class_MetaDataParams, ARRAY_COUNT(Class_MetaDataParams))
			};
			UE4CodeGen_Private::ConstructUClass(OuterClass, ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AFloor, 760307842);
	static FCompiledInDefer Z_CompiledInDefer_UClass_AFloor(Z_Construct_UClass_AFloor, &AFloor::StaticClass, TEXT("/Script/SimpleProject"), TEXT("AFloor"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AFloor);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
