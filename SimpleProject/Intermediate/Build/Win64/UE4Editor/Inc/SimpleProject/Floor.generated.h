// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "ObjectMacros.h"
#include "ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef SIMPLEPROJECT_Floor_generated_h
#error "Floor.generated.h already included, missing '#pragma once' in Floor.h"
#endif
#define SIMPLEPROJECT_Floor_generated_h

#define SimpleProject_Source_SimpleProject_Floor_h_12_RPC_WRAPPERS
#define SimpleProject_Source_SimpleProject_Floor_h_12_RPC_WRAPPERS_NO_PURE_DECLS
#define SimpleProject_Source_SimpleProject_Floor_h_12_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAFloor(); \
	friend SIMPLEPROJECT_API class UClass* Z_Construct_UClass_AFloor(); \
public: \
	DECLARE_CLASS(AFloor, AActor, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/SimpleProject"), NO_API) \
	DECLARE_SERIALIZER(AFloor) \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define SimpleProject_Source_SimpleProject_Floor_h_12_INCLASS \
private: \
	static void StaticRegisterNativesAFloor(); \
	friend SIMPLEPROJECT_API class UClass* Z_Construct_UClass_AFloor(); \
public: \
	DECLARE_CLASS(AFloor, AActor, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/SimpleProject"), NO_API) \
	DECLARE_SERIALIZER(AFloor) \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define SimpleProject_Source_SimpleProject_Floor_h_12_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AFloor(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AFloor) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AFloor); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AFloor); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AFloor(AFloor&&); \
	NO_API AFloor(const AFloor&); \
public:


#define SimpleProject_Source_SimpleProject_Floor_h_12_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AFloor(AFloor&&); \
	NO_API AFloor(const AFloor&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AFloor); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AFloor); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AFloor)


#define SimpleProject_Source_SimpleProject_Floor_h_12_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__FloorMeshComponent() { return STRUCT_OFFSET(AFloor, FloorMeshComponent); }


#define SimpleProject_Source_SimpleProject_Floor_h_9_PROLOG
#define SimpleProject_Source_SimpleProject_Floor_h_12_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	SimpleProject_Source_SimpleProject_Floor_h_12_PRIVATE_PROPERTY_OFFSET \
	SimpleProject_Source_SimpleProject_Floor_h_12_RPC_WRAPPERS \
	SimpleProject_Source_SimpleProject_Floor_h_12_INCLASS \
	SimpleProject_Source_SimpleProject_Floor_h_12_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define SimpleProject_Source_SimpleProject_Floor_h_12_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	SimpleProject_Source_SimpleProject_Floor_h_12_PRIVATE_PROPERTY_OFFSET \
	SimpleProject_Source_SimpleProject_Floor_h_12_RPC_WRAPPERS_NO_PURE_DECLS \
	SimpleProject_Source_SimpleProject_Floor_h_12_INCLASS_NO_PURE_DECLS \
	SimpleProject_Source_SimpleProject_Floor_h_12_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID SimpleProject_Source_SimpleProject_Floor_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
