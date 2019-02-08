// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Floor.generated.h"

UCLASS()
class SIMPLEPROJECT_API AFloor : public AActor
{
	GENERATED_BODY()

private:
	// Static mesh for floor.
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Enemy, meta = (AllowPrivateAccess = "true"))
		UStaticMeshComponent* FloorMeshComponent;
	
public:	
	// Sets default values for this actor's properties
	AFloor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};
