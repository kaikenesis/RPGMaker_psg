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
	FDataTableRowHandle DialogueHandles;

	UPROPERTY(BlueprintReadOnly, EditAnywhere)
	FName Name;

	UPROPERTY(BlueprintReadOnly, EditAnywhere)
	FName Description;

};

USTRUCT(BlueprintType)
struct FDialogueSettings : public FTableRowBase
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadOnly, EditAnywhere)
	FDataTableRowHandle ResponseHandles;

	UPROPERTY(BlueprintReadOnly, EditAnywhere)
	FText Message;
};

USTRUCT(BlueprintType)
struct FResponseMessageSettings : public FTableRowBase
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadOnly, EditAnywhere)
	FDataTableRowHandle DialogueHandles;

	UPROPERTY(BlueprintReadOnly, EditAnywhere)
	EMessageButton MessageButton;

	UPROPERTY(BlueprintReadOnly, EditAnywhere)
	FText PlayerResponse;
};