#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "CustomDataTables.generated.h"

UENUM(BlueprintType)
enum class EMessageButton : uint8
{
	None,
	Message1,
	Message2,
	Message3,
	Message4,
	MAX
};

USTRUCT(BlueprintType)
struct FDialogueList : public FTableRowBase
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadOnly, EditAnywhere)
	FDataTableRowHandle Handle;

	UPROPERTY(BlueprintReadOnly, EditAnywhere)
	FName Name;

	UPROPERTY(BlueprintReadOnly, EditAnywhere)
	FName Description;

	UPROPERTY(BlueprintReadOnly, EditAnywhere)
	TArray<FDataTableRowHandle> Dialogues;
};

USTRUCT(BlueprintType)
struct FDialogueSettings : public FTableRowBase
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadOnly, EditAnywhere)
	FDataTableRowHandle Handle;

	UPROPERTY(BlueprintReadOnly, EditAnywhere)
	FName Name;

	UPROPERTY(BlueprintReadOnly, EditAnywhere)
	FName Description;

	UPROPERTY(BlueprintReadOnly, EditAnywhere)
	FText NPCName;

	UPROPERTY(BlueprintReadOnly, EditAnywhere)
	FText Message;

	UPROPERTY(BlueprintReadOnly, EditAnywhere)
	TArray<FDataTableRowHandle> ResponseMessages;
};

USTRUCT(BlueprintType)
struct FResponseMessageSettings : public FTableRowBase
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadOnly, EditAnywhere)
	FDataTableRowHandle Handle;

	UPROPERTY(BlueprintReadOnly, EditAnywhere)
	EMessageButton MessageButton;

	UPROPERTY(BlueprintReadOnly, EditAnywhere)
	FText PlayerResponse;

	UPROPERTY(BlueprintReadOnly, EditAnywhere)
	TArray<FText> NPCResponseMessage;
};