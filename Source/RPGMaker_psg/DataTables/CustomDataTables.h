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
};

USTRUCT(BlueprintType)
struct FQuestProgress : public FTableRowBase
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadOnly, EditAnywhere)
	FText QuestName;

	UPROPERTY(BlueprintReadOnly, EditAnywhere)
	bool bAccept;

	UPROPERTY(BlueprintReadOnly, EditAnywhere)
	bool bComplete;

	UPROPERTY(BlueprintReadOnly, EditAnywhere)
	bool bClear;
};

USTRUCT(BlueprintType)
struct FQuestList : public FTableRowBase
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadOnly, EditAnywhere)
	FText NPCName;

	UPROPERTY(BlueprintReadOnly, EditAnywhere)
	FDataTableRowHandle QuestProgressHandle;
};