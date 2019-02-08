// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "ObjectMacros.h"
#include "ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef SIMPLEPROJECT_SimpleProjectCharacter_generated_h
#error "SimpleProjectCharacter.generated.h already included, missing '#pragma once' in SimpleProjectCharacter.h"
#endif
#define SIMPLEPROJECT_SimpleProjectCharacter_generated_h

#define SimpleProject_Source_SimpleProject_SimpleProjectCharacter_h_14_RPC_WRAPPERS
#define SimpleProject_Source_SimpleProject_SimpleProjectCharacter_h_14_RPC_WRAPPERS_NO_PURE_DECLS
#define SimpleProject_Source_SimpleProject_SimpleProjectCharacter_h_14_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesASimpleProjectCharacter(); \
	friend SIMPLEPROJECT_API class UClass* Z_Construct_UClass_ASimpleProjectCharacter(); \
public: \
	DECLARE_CLASS(ASimpleProjectCharacter, ACharacter, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/SimpleProject"), NO_API) \
	DECLARE_SERIALIZER(ASimpleProjectCharacter) \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define SimpleProject_Source_SimpleProject_SimpleProjectCharacter_h_14_INCLASS \
private: \
	static void StaticRegisterNativesASimpleProjectCharacter(); \
	friend SIMPLEPROJECT_API class UClass* Z_Construct_UClass_ASimpleProjectCharacter(); \
public: \
	DECLARE_CLASS(ASimpleProjectCharacter, ACharacter, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/SimpleProject"), NO_API) \
	DECLARE_SERIALIZER(ASimpleProjectCharacter) \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define SimpleProject_Source_SimpleProject_SimpleProjectCharacter_h_14_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API ASimpleProjectCharacter(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(ASimpleProjectCharacter) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ASimpleProjectCharacter); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ASimpleProjectCharacter); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ASimpleProjectCharacter(ASimpleProjectCharacter&&); \
	NO_API ASimpleProjectCharacter(const ASimpleProjectCharacter&); \
public:


#define SimpleProject_Source_SimpleProject_SimpleProjectCharacter_h_14_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ASimpleProjectCharacter(ASimpleProjectCharacter&&); \
	NO_API ASimpleProjectCharacter(const ASimpleProjectCharacter&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ASimpleProjectCharacter); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ASimpleProjectCharacter); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(ASimpleProjectCharacter)


#define SimpleProject_Source_SimpleProject_SimpleProjectCharacter_h_14_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__SpringArm() { return STRUCT_OFFSET(ASimpleProjectCharacter, SpringArm); }


#define SimpleProject_Source_SimpleProject_SimpleProjectCharacter_h_11_PROLOG
#define SimpleProject_Source_SimpleProject_SimpleProjectCharacter_h_14_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	SimpleProject_Source_SimpleProject_SimpleProjectCharacter_h_14_PRIVATE_PROPERTY_OFFSET \
	SimpleProject_Source_SimpleProject_SimpleProjectCharacter_h_14_RPC_WRAPPERS \
	SimpleProject_Source_SimpleProject_SimpleProjectCharacter_h_14_INCLASS \
	SimpleProject_Source_SimpleProject_SimpleProjectCharacter_h_14_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define SimpleProject_Source_SimpleProject_SimpleProjectCharacter_h_14_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	SimpleProject_Source_SimpleProject_SimpleProjectCharacter_h_14_PRIVATE_PROPERTY_OFFSET \
	SimpleProject_Source_SimpleProject_SimpleProjectCharacter_h_14_RPC_WRAPPERS_NO_PURE_DECLS \
	SimpleProject_Source_SimpleProject_SimpleProjectCharacter_h_14_INCLASS_NO_PURE_DECLS \
	SimpleProject_Source_SimpleProject_SimpleProjectCharacter_h_14_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID SimpleProject_Source_SimpleProject_SimpleProjectCharacter_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
