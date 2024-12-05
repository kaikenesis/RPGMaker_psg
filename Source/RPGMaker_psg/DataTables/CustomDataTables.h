#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "CustomDataTables.generated.h"

UENUM(BlueprintType)
enum class EMessageButton : uint8
{
	None,
	AccpetQuest,
	MAX
};

USTRUCT(BlueprintType)
struct FDialogueList : public FTableRowBase
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadOnly, EditAnywhere)
	FDataTableRowHandle DialogueHandle;

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
	FDataTableRowHandle ResponseHandle;

	UPROPERTY(BlueprintReadOnly, EditAnywhere)
	FText Message;
};

USTRUCT(BlueprintType)
struct FResponseMessageSettings : public FTableRowBase
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadOnly, EditAnywhere)
	FDataTableRowHandle DialogueHandle;

	UPROPERTY(BlueprintReadOnly, EditAnywhere)
	EMessageButton MessageButton;

	UPROPERTY(BlueprintReadOnly, EditAnywhere)
	FText PlayerResponse;

	UPROPERTY(BlueprintReadOnly, EditAnywhere)
	FDataTableRowHandle QuestInfoHandle;
};

USTRUCT(BlueprintType)
struct FQuestInfo : public FTableRowBase
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadOnly, EditAnywhere)
	FText QuestName;

	UPROPERTY(BlueprintReadOnly, EditAnywhere)
	FText QuestInfo;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	bool bComplete;
};