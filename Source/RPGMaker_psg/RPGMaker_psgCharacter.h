// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "InputActionValue.h"
#include "RPGMaker_psgCharacter.generated.h"


UCLASS(config=Game)
class ARPGMaker_psgCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	ARPGMaker_psgCharacter();

protected:
	virtual void BeginPlay();

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

public:
	UFUNCTION()
	void OnBeginOverlap_Interaction(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
	void OnEndOverlap_Interaction(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

public:
	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }
	FORCEINLINE class UCameraComponent* GetFollowCamera() const { return FollowCamera; }
	//FORCEINLINE class APlayerController* GetPlayerController() const { return PlayerController; }

protected:
	void OnMove(const FInputActionValue& Value);
	void OnLook(const FInputActionValue& Value);
	void OnDoAction(const FInputActionValue& Value);
	void OnSprint(const FInputActionValue& Value);
	void OnWalk(const FInputActionValue& Value);
	void OnAvoid(const FInputActionValue& Value);
	void OnInteraction(const FInputActionValue& Value);

private: // Camera & Input
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class USpringArmComponent* CameraBoom;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* FollowCamera;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	class UInputMappingContext* DefaultMappingContext;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	class UInputAction* JumpAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	class UInputAction* MoveAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	class UInputAction* LookAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	class UInputAction* DoAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	class UInputAction* SprintAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	class UInputAction* AvoidAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	class UInputAction* InteractionAction;

private: // SceneComponents
	UPROPERTY(EditDefaultsOnly)
	class UBoxComponent* BoxComp;

private: // ActorComponents

	UPROPERTY(EditDefaultsOnly, Category = Components)
	class UCActionComponent* ActionComp;

	UPROPERTY(EditDefaultsOnly, Category = Components)
	class UCStateComponent* StateComp;

	UPROPERTY(EditDefaultsOnly, Category = Components)
	class UCStatusComponent* StatusComp;

	UPROPERTY(EditDefaultsOnly, Category = Components)
	class UCInteractionComponent* InteractionComp;

private:
	TArray<class AActor*> InteractionActors;
};

